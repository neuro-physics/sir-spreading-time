function m = myMin(A,dim)
    if iscell(A)
        m = cell(size(A));
        for i = 1:numel(A)
            m{i} = min(A{i},[],dim);
        end
    else
        m = min(A,[],dim);
    end
end
