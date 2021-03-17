function [x,y,xStd,yStd] = averageFunctionData(xx, yy, method, nBins)
% this function averages all the power spectra according to method
% and returns a struct with .f and .PS and .std (std dev of PS average for each f)
% cps = array of powerspec structs: .f and .PS fields
% method = 'samex' -> average over the same freq of all PS provided
%        = 'xbinslog' -> makes a distribution of the x-values provided (nBins must be provided) and average y inside these bins (log binning for power-law plots)
%        = 'xbinslin' -> makes a distribution of the x-values provided (nBins must be provided) and average y inside these bins (linear binning for power-law plots)
%        = 'interplog' -> average all PS interpolating to the freq not provided by 3-spline (log binning)
%        = 'interplin' -> average all PS interpolating to the freq not provided by 3-spline (linear binning)
% nBins = amount of bins to make freq distribution if method == 'freqdist'
    if ((nargin < 3) || (isempty(method)))
        method = 'xbinslin';
    end
    if ((strContains(method,'xbins')) && ((nargin < 4) || (isempty(nBins))))
        nBins = 100;
    end

    if ~iscell(xx)
        xx = {xx};
    end
    if ~iscell(yy)
        yy = {yy};
    end
    
    n = numel(xx);
    isSameX = 1;
    isSameSize = 1;
    for i = 1:n-1
        if (size(xx{i}) == size(xx{i+1}))
            isSameX = isSameX && all(xx{i} == xx{i+1});
        else
            isSameSize = 0;
            break;
        end
    end

    if strcmpi(method,'samex') && (isSameSize && isSameX)
        x = xx{1};
        y = zeros(size(x));
        xStd = zeros(size(x));
        yStd = zeros(size(x));
        nVal = numel(x);
        for i = 1:nVal
            ySqSum = 0;
            nNaN = 0;
            for j = 1:n
                if isnan(y(i))
                    nNaN = nNaN + 1;
                    continue;
                end
                y(i) = y(i) + yy{j}(i);
                ySqSum = ySqSum + yy{j}(i) * yy{j}(i);
            end
            nn = n - nNaN;
            if nn == 0
                nn = 1;
            end
            y(i) = y(i) / nn;
            yStd(i) = sqrt(ySqSum / nn - y(i) * y(i));
        end
    elseif strContains(method, 'xbins')
        xLin = [];
        yLin = [];
        for i = 1:n
            xLin = [ xLin, xx{i}(:)' ];
            yLin = [ yLin, yy{i}(:)' ];
        end
        if strContains(method,'log')
            [ x, ~, ~, ~, ~, xEnds ] = lnbin(xLin, nBins);
        else % ~isempty(strfind(method,'lin'))
            [x,xEnds] = linBin(xLin,nBins);
        end
        y = zeros(size(x));
        yStd = zeros(size(x));
        for i = 1:nBins
            yInRange = yLin(xLin >= xEnds(i,1) & xLin < xEnds(i,2));
            y(i) = mean(yInRange,'omitnan');
            yStd(i) = std(yInRange,'omitnan');
        end
        xStd = diff(xEnds,1,2);
    elseif strContains(method, 'interp')
        pp = cell(1,n); % piece-wise polynomial for each PS in cps
        mm = zeros(n,2);
        minx = Inf;
        min2x = Inf;
        maxx = -Inf;
        dX = 0;
        for i = 1:n
            pp{i} = spline(xx{i}, yy{i});
            mm(i,:) = minmax(reshape(xx{i},1,[]));%[ xx{i}(1), xx{i}(end) ];
            m2 = xx{i}(2);
            if (m2 < min2x)
                min2x = m2;
            end
            if (mm(i,1) < minx)
                minx = mm(i,1);
            end
            if (mm(i,2) > maxx)
                maxx = mm(i,2);
            end
            dX = dX + abs(xx{i}(2) - xx{i}(1));
        end
        dX = dX / n;
        nS = ceil((maxx-minx)/dX);
        if (minx == 0)
            minx = min2x;
        end
        if strContains(method,'log')
            xSample = reshape(logspace(log10(minx), log10(maxx), nS),[],1);
        else % ~isempty(strfind(method,'lin'))
            xSample = reshape(linspace(minx, maxx, nS),[],1);
        end
        x = xSample;
        y = zeros(size(xSample));
        yStd = zeros(size(xSample));
        for i = 1:nS % for each of the sampled freq
            k = 0;
            ySum = 0;
            ySqSum = 0;
            nNaN = 0;
            for j = 1:n % for each PS
                if ((xSample(i) < mm(j,1)) || (xSample(i) > mm(j,2)))
                    continue;
                end
                k = k + 1;
                val = ppval(pp{j}, xSample(i));
                if isnan(val)
                    nNaN = nNaN + 1;
                    continue;
                end
                ySum = ySum + val; % spline value at fSample
                ySqSum = ySqSum + val * val;
            end
            nn = k - nNaN;
            if nn == 0
                nn = 1;
            end
            y(i) = ySum / nn;
            yStd(i) = sqrt(ySqSum / nn - y(i) * y(i));
        end
        xStd = [ (x(2)-x(1)); diff(x) ];
    else % method = 'samefreq'
        xLin = [];
        yLin = [];
        for i = 1:n
            xLin = [ xLin, xx{i}(:)' ];
            yLin = [ yLin, yy{i}(:)' ];
        end
        
        xA = [];
        yA = [];
        yStdA = [];
        fNotChecked = ones(size(xLin));
        m = length(xLin);
        for i = 1:m
            if (~fNotChecked(i))
                continue;
            end
            ySum = yLin(i);
            ySqSum = yLin(i) * yLin(i);
            nY = 1;
            nNaN = 0;
            k = i + 1;
            for j = k:m
                if (xLin(i) == xLin(j))
                    if (fNotChecked(j))
                        if isnan(yLin(j))
                            nNaN = nNaN + 1;
                            continue;
                        end
                        ySum = ySum + yLin(j);
                        ySqSum = ySqSum + yLin(j) * yLin(j);
                        fNotChecked(j) = 0;
                        nY = nY + 1;
                    end
                end
            end
            nn = nY - nNaN;
            if nn == 0
                nn = 1;
            end
            xA(end+1) = xLin(i);
            yA(end+1) = ySum ./ nn;
            yStdA(end+1) = sqrt(ySqSum / nn - yA(end) * yA(end));
            fNotChecked(i) = 0;
        end
        [ x, indSrt ] = sort(xA);
        x = reshape(x,[],1);
        y = reshape(yA(indSrt),[],1);
        yStd = reshape(yStdA(indSrt),[],1);
        xStd = zeros(size(x));
    end
end

function [xMid,xEnds] = linBin(x,nBins)
    [~,e] = histcounts(x,nBins);
    e = reshape(e,[],1);
    xEnds = [e(1:(end-1)),e(2:end)];
    xMid = mean(xEnds,2,'omitnan');
end

function r = strContains(str,c)
    r = ~isempty(strfind(str,c));
end