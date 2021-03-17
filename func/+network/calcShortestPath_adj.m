function P = calcShortestPath_adj(A,isBinaryNet)
    if (nargin < 2) || isempty(isBinaryNet)
        if iscell(A)
            isBinaryNet = isBinary(A{1});
        else
            isBinaryNet = isBinary(A);
        end
    end
    if iscell(A)
        P = cell(size(A));
        for i = 1:numel(A)
            P{i} = calcShortestPath_adj_internal(A{i},isBinaryNet);
        end
    else
        P = calcShortestPath_adj_internal(A,isBinaryNet);
    end
end

function P = calcShortestPath_adj_internal(A,isBinaryNet)
    if isBinaryNet
        P = distance_bin(A);
    else
        P = distance_wei(A);
    end
end

function r = isBinary(A)
    r = full(all(all((A == 0) | (A == 1))));
end
