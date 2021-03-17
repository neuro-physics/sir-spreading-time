function B = sortMatrices(A,s,dim)
% dim = matrix dimension to sort: 1 == lines, 2 == cols, 0 == both (default)
    if (nargin < 3) || isempty(dim)
        dim = 0;
    end
    if iscell(A)
        B = cell(size(A));
        for i = 1:numel(A)
            B{i} = sortMat_internal(A{i},s,dim);
        end
    else
        B = sortMat_internal(A,s,dim);
    end
end

function A = sortMat_internal(A,s,dim)
    if isvector(A)
        A = A(s);
    else
        if dim == 0
            A = A(s,s);
        elseif dim == 1
            A = A(s,:);
        elseif dim == 2
            A = A(:,s);
        else
            error('dim not allowed');
        end
    end
end
