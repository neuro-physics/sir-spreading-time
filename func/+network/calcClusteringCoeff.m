function C = calcClusteringCoeff(A,isBinaryNet)
    if (nargin < 2) || isempty(isBinaryNet)
        if iscell(A)
            isBinaryNet = isBinary(A{1});
        else
            isBinaryNet = isBinary(A);
        end
    end
    if iscell(A)
        N = size(A{1},1);
        sEq = allSizesEqual(A);
        if sEq
            C = zeros(N,numel(A));
            for i = 1:numel(A)
                C(:,i) = calcClusteringCoeff_internal(A{i},isBinaryNet);
            end
        else
            C = cell(size(A));
            for i = 1:numel(A)
                C{i} = calcClusteringCoeff_internal(A{i},isBinaryNet);
            end
        end
    else
        C = clustering_coef_wd(A);
        C = reshape(C,numel(C),1);
    end
end

function C = calcClusteringCoeff_internal(A,isBinaryNet)
    if isBinaryNet
        C = clustering_coef_bd(A);
    else
        C = clustering_coef_wd(A);
    end
end

function r = isBinary(A)
    r = full(all(all((A == 0) | (A == 1))));
end

function r = allSizesEqual(A)
    r = all(all(cell2mat(cellfun(@(x)size(x),A,'UniformOutput',false)') == size(A{1},1)));
end
