function [D,P] = CalcHammingDist(A,B)
    coder.extrinsic('pdist');
    A(isnan(A)) = Inf;
    B(isnan(B)) = -Inf;
    if isvector(A) || isvector(B)
        N = numel(A);
        A = A(:);
        B = B(:);
    else
        N = size(A,2);
    end
    nCol = size(A,2);
    D = zeros(1,nCol);
    P = zeros(1,nCol);
    for i = 1:nCol
        P(i) = pdist([A(:,i)';B(:,i)'], 'hamming');
        D(i) = P(i) .* N;
    end
end
