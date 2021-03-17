function D = hammingDistance(S,P,N,dim)
    if ~iscell(S)
        S = {S};
    end
    if ~iscell(P)
        P = {P};
    end
    if (nargin < 3) || isempty(N)
        N = size(S{1},1);
    end
    if (nargin < 4)
        dim = [];
    end
    D = zeros(numel(S),N);
    for i = 1:numel(S)
        D(i,:) = CalcHammingDist(S{i}, P{i}, dim); % calculating hamming distance between spreading and shortest path matrices
    end
end
