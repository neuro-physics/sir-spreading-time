function [fh,axh,h] = plot3DPosition(fh,axh,r,values,plotArgs,colorArr,colorMode,colorLim,symbolSet,symbolMode)
    if isempty(fh)
        fh = figure;
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    end
    if (nargin < 5) || isempty(plotArgs)
        plotArgs = { };
    end
    if (nargin < 6) || isempty(colorArr)
        colorArr = hsv(numel(unique(values)));
    end
    if (nargin < 7) || isempty(colorMode)
        colorMode = 'discrete'; % or 'continuous'
    end
    if (nargin < 8) || isempty(colorLim)
        colorLim = axh.CLim;
    end
    if (nargin < 9) || isempty(symbolSet)
        symbolSet = 'o^svd<>ph+*.x';%repeatToComplete_local('o^svd<>ph+*.x', numel(unique(values)));
    end
    if (nargin < 10) || isempty(symbolMode)
        symbolMode = 'unique'; % or 'value'
    end
    if strcmpi(colorMode, 'discrete')
        getColor = @(xx)getPColor_discrete(xx,colorArr);
    elseif strcmpi(colorMode, 'continuous')
        %mm = minmax(values(:)');
        getColor = @(xx)getPColor_continuous(xx,colorArr,colorLim);
    else
        error('plotParcelPosition:colorMode','unrecognized colorMode parameter');
    end
    %if strcmpi(symbolMode, 'value')
    useUniqueSymbol = strcmpi(symbolMode,'unique');
    getSymbol = @(ii)getPSymbol(ii,symbolSet);
    %elseif strcmpi(symbolMode, 'unique')
    %    getSymbol = @(ii)getPSymbol(ii,symbolSet);
    %else
    %    error('plotParcelPosition:symbolMode','unrecognized symbolMode parameter');
    %end

    [plotLineSpec,plotArgs,containsLineSpec] = getArgValue(plotArgs, 'linespec');
    if ~containsLineSpec
        plotLineSpec = '';
    end
    
    [hideNodeList,plotArgs,containsHideNodeList] = getArgValue(plotArgs, 'hidenodelist');
    if containsHideNodeList
        hideNodeList(hideNodeList <= 0) = [];
    else
        hideNodeList = [];
    end
    
    if ~(isvector(hideNodeList) && isnumeric(hideNodeList))
        if isempty(hideNodeList)
            hideNodeList = [];
        else
            error('param HideNodeList in plotArgs must be a numeric vector of indices of r')
        end
    end
    if ~isempty(hideNodeList)
        if size(values,1) == size(r,1)
            values(hideNodeList,:) = [];
        end
        r(hideNodeList,:) = [];
    end

    hold(axh,'on');
    h = plotParcelPosition_internal(axh, r, values, plotArgs, plotLineSpec, getColor, getSymbol, useUniqueSymbol);
    hold(axh,'off');
end

function h = plotParcelPosition_internal(axh, r, values, plotArgs, plotLineSpec, getColor, getSymbol, useUniqueSymbol)
    is2d = size(r,2)==2;
    [uv,~,iv] = unique(values);
    hold(axh, 'on');
    for i = 1:numel(uv)
        pArgs = [ 'Color', getColor(uv(i)), 'MarkerFaceColor', getColor(uv(i)), plotArgs ];
        k = find(iv==i);
        pData = { axh };
        if useUniqueSymbol && isempty(plotLineSpec)
            for j = 1:numel(k)
                pSpec = getSymbol(k(j));
                if is2d
                    pData = [ pData, r(k(j),1), r(k(j),2), pSpec ];
                else
                    pData = [ pData, r(k(j),1), r(k(j),2), r(k(j),3), pSpec ];
                end
            end
        else
            if isempty(plotLineSpec)
                pSpec = getSymbol(i);
            else
                pSpec = plotLineSpec;
            end
            if is2d
                pData = [ pData, r(k,1), r(k,2), pSpec ];
            else
                pData = [ pData, r(k,1), r(k,2), r(k,3), pSpec ];
            end
        end
        if is2d
            h = plot(pData{:});
        else
            h = plot3(pData{:});
        end
        for j = 1:numel(h)
            set(h, pArgs{:});
        end
    end
    hold(axh, 'off');
end

function s = getPColor_discrete(ii, colorSet)
    s = colorSet(int32(mod(int32(ii)-1,int32(round(numel(colorSet)/3))))+1,:);
end

function s = getPColor_continuous(xx, colorSet, mm)
    dy = size(colorSet,1)-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    k = round(a.*xx+b)+1;
    if k < 1
        k = 1;
    end
    if k > size(colorSet,1)
        k = size(colorSet,1);
    end
    s = colorSet(k,:);
end

function s = getPSymbol(ii, symbolSet)
    s = symbolSet(int32(mod(int32(ii)-1,numel(symbolSet)))+1);
    if ((strcmp(s,'n')) || (strcmp(s,'none')))
        s = '';
    end
end

function [val,argsOut,c] = getArgValue(args, arg)
    argsOut = args;
    ind = find(strcmp(strCellToLower(args),arg));
    if (~isempty(ind))
        val = argsOut{ind+1};
        argsOut(ind+1) = [];
        argsOut(ind) = [];
        c = true;
    else
        val = [];
        c = false;
    end
end

function cc = strCellToLower(c)
    n = numel(c);
    cc = cell(size(c));
    for i = 1:n
        if (ischar(c{i}))
            cc{i} = lower(c{i});
        else
            cc{i} = c{i};
        end
    end
end

% function h = copyAxes(axh)
%     for i = 1:numel(axh)
%         h(i) = copyobj(axh(i),axh(i).Parent);
%     end
% end

function y = repeatToComplete_local(x,N)
% y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector
    y = zeros(1,N);
    x = x(:)';
    n = numel(x);
    m = floor(N/n);
    if m <= 1
        y = x(1:N);
        return
    end
    y(1:(m*n)) = repmat(x, 1, m);
    y((m*n+1):N) = x(1:(N-m*n));
    if ischar(x)
        y = char(y);
    end
end
