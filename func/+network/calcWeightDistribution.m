function [P,w] = calcWeightDistribution(A,nBins,resultType)
    if (nargin < 2) || isempty(nBins)
        nBins = 50;
    end
    if (nargin < 3) || isempty(resultType)
        resultType = 'single'; % 'single' -> all matrices in the cell array A{:} are considered as a single unit for the many samples of w
                               % 'individual' -> P(:,k) and w(:,k) are the weight distribution of A{k}
    end
    if ~iscell(A)
        A = {A};
    end
    if strcmpi(resultType,'single')
        [P,w] = calcWeightDistribution_internal( reshape(cell2mat(A),numel(A{1})*numel(A),1)   ,   nBins);
    elseif strcmpi(resultType,'individual')
        nC = numel(A);
        P = zeros(nBins,nC);
        w = zeros(nBins,nC);
        for i = 1:nC
            [P(:,i),w(:,i)] = calcWeightDistribution_internal(A{i},nBins);
        end
    else
        error('Unrecognized resultType');
    end
end

function [P,w] = calcWeightDistribution_internal(A,nBins)
    wA = A(A~=0);
    [P,w] = histcounts(wA,nBins,'Normalization','probability');
    P = reshape(P,numel(P),1);
    w = reshape(w(1:end-1),numel(P),1);
end
