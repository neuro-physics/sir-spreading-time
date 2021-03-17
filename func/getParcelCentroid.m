function r = getParcelCentroid(vertexInd, coord, side)
% Usage: [a,cb]=BoSurfStatViewData(data, surf [,title [,background]]);
% 
% vertexInd  = 1 x v vector of data, v=#vertices
% coord      = 3 x v matrix of coordinates.
% side       = L, R, LR (default)
%
% the centroid is the average of the coordinates of all the vertices with same index
%#codegen
    if nargin < 3 || isempty(side)
        side = 'LR';
    end
    nv = numel(vertexInd);
    if strcmp(side, 'L')
        vInt = 1:(nv/2);
    elseif strcmp(side, 'R')
        vInt = (1:(nv/2)) + nv/2;
    else
        vInt = 1:nv;
    end
    mm = myMinMax(vertexInd);
    if mm(1) ~= 1
        mm(1) = 1;
    end
    r = zeros(3,mm(2));
    for i = mm(1):mm(2)
        ind = find(vertexInd(vInt) == i);
        if isempty(ind)
            r(:,i) = NaN(3,1);
        else
            r(:,i) = mean(coord(:,ind),2);
        end
    end
end

function mm = myMinMax(x)
    mm = [Inf,-Inf];
    for i = 1:numel(x)
        if x(i) < mm(1)
            mm(1) = x(i);
        end
        if x(i) > mm(2)
            mm(2) = x(i);
        end
    end
end
