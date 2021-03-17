function [P,k] = calcNodeDegree(A,direction,resultType,degType)
    if (nargin < 2) || isempty(direction)
        direction = 'in'; % 'in' or 'out'
    end
    if (nargin < 3) || isempty(resultType)
        resultType = 'degree'; % 'degree' -> returns node degree for each matrix in cell A
                               % 'distribution' -> returns total degree distribution (considering samples from every case in cell A)
    end
    if (nargin < 4) || isempty(degType)
        degType = 'binary'; % 'binary' -> binarize A
                            % 'weighted' -> sums the weights of A
    end
    isBinary = strcmpi(degType,'binary');

    if ~iscell(A)
        A = {A};
    end
    if strcmpi(resultType,'distribution')
        sEq = allSizesEqual(A);
        if sEq
            [P,k] = calcDegreeDistribution_internal(A,direction,isBinary);
        else
            P = cell(size(A));
            k = cell(size(A));
            for i = 1:numel(A)
                [P{i},k{i}] = calcDegreeDistribution_internal(A{i},direction,isBinary);
            end
        end
    elseif strcmpi(resultType,'degree')
        P = [];
        nC = numel(A);
        sEq = allSizesEqual(A);
        if sEq
            k = zeros(size(A{1},1),nC);
            for i = 1:nC
                k(:,i) = calcNodeDegree_internal(A{i},direction,isBinary);
            end
        else
            k = cell(size(A));
            for i = 1:nC
                k{i} = calcNodeDegree_internal(A{i},direction,isBinary);
            end
        end
    else
        error('Unrecognized resultType');
    end
end

function k = calcNodeDegree_internal(A,direction,isBinary)
    if strcmpi(direction,'in')
        dim = 1;
    else
        dim = 2;
    end
    if isBinary
        k = sum(A~=0,dim);
    else
        k = sum(A,dim);
    end
    k = reshape(k,numel(k),1);
end

function [P,k] = calcDegreeDistribution_internal(A,direction,isBinary)
    if iscell(A)
        if strcmpi(direction,'in')
            A = cell2mat(reshape(A,1,numel(A)));
        else
            A = cell2mat(reshape(A,numel(A),1));
        end
    end
    kA = calcNodeDegree_internal(A,direction,isBinary);
    if isBinary
        [P,k] = histcounts(kA,1:(size(A,1)+1),'Normalization','probability');
    else
        [P,k] = histcounts(kA,ceil(sqrt(numel(kA))),'Normalization','probability');
    end
    P = reshape(P,numel(P),1);
    k = reshape(k(1:end-1),numel(P),1);
end

function r = allSizesEqual(A)
    r = all(all(cell2mat(cellfun(@(x)size(x),A,'UniformOutput',false)') == size(A{1},1)));
end
