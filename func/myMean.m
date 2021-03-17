function M = myMean(A,varargin)
    if iscell(A)
        M = cell(size(A));
        for i = 1:numel(A)
            M{i} = mean(A{i},varargin{:});
        end
    else
        M = mean(A,varargin{:});
    end
end
