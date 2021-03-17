function S = myStd(A,varargin)
    if iscell(A)
        S = cell(size(A));
        for i = 1:numel(A)
            S{i} = std(A{i},varargin{:});
        end
    else
        S = std(A,varargin{:});
    end
end