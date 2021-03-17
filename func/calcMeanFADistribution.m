function [P,fa,Perr] = calcMeanFADistribution(A,nbins,errType)
    if (nargin < 3) || isempty(errType)
        errType = 'std'; % errType = 'std' or 'error'
    end
    if iscell(A)
        N = numel(A);
        P = zeros(N,nbins);
        for i = 1:N
            [P(i,:), fa] = calcMeanFADistribution_internal(A{i},nbins);
        end
        P = mean(P,1);
        Perr = std(P,[],1);
        if strcmpi(errType,'error')
            Perr = Perr ./ sqrt(N);
        end
    else
        [P,fa] = calcMeanFADistribution_internal(A,nbins);
        Perr = zeros(size(P));
    end
end

function [P,fa] = calcMeanFADistribution_internal(A,nbins)
    [P,fa] = histcounts(A(A~=0),nbins,'Normalization','probability');
    fa(end)=[];
end