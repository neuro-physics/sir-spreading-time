function Z = ZScoreMatrixElem(A,M,S,keepNonzeroOnly)
% Z-score elements of A
% A is a set (cell) of matrices
% M,S is the average/stddev used to Z-Score A (if empty, [M,~,~,S] = meanMatrix(A) )
% keepNonzeroOnly -> calculates z-score only for the non-zero elements of each matrix in A
%
% Z -> cell of size(A) containing the Z-score relative to M of each matrix in A
    if (nargin < 2) || isempty(M) || (nargin < 3) || isempty(S)
        [M,~,~,S] = meanMatrix(A);
        S(S==0)=1;
    end
    if (nargin < 4) || isempty(keepNonzeroOnly)
        keepNonzeroOnly = true;
    end
    if ~iscell(A)
        A = {A};
    end
    n = numel(A);
    N = size(A{1},1);
    Z = cell(size(A));
    for k = 1:n
        for i = 1:N
            for j = 1:N
                Z{k}(i,j) = (A{k}(i,j) - M(i,j)) ./ S(i,j);
                if keepNonzeroOnly && (A{k}(i,j) == 0)
                    Z{k}(i,j) = 0;
                end
            end
        end
    end
end
