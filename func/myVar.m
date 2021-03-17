function S = myVar(A,varargin)
    if iscell(A)
        S = cell(size(A));
        for i = 1:numel(A)
            S{i} = var(A{i},varargin{:});
        end
    else
        S = var(A,varargin{:});
    end
end