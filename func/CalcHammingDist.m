function D = CalcHammingDist(A,B,dim)
% dim == 1: compare lines of A with lines of B
% dim == 2: compare columns of A with columns of B
    if (nargin < 3) || isempty(dim)
        dim = 1;
    end
    isvec = false;
    A(isnan(A)) = Inf;
    B(isnan(B)) = -Inf;
    if isvector(A) || isvector(B)
        N = numel(A);
        A = A(:);
        B = B(:);
        isvec = true;
        dim = 1;
    end
    if dim == 1
        if ~isvec
            N = size(A,2);
        end
        nCol = size(A,2);
        D = zeros(1,nCol);
        for i = 1:nCol
            D(i) = pdist([A(:,i)';B(:,i)'], 'hamming') .* N;
        end
    elseif dim == 2
        N = size(A,1);
        nRow = size(A,1);
        D = zeros(nRow,1);
        for i = 1:nRow
            D(i) = pdist([A(i,:);B(i,:)], 'hamming') .* N;
        end
    end
end
