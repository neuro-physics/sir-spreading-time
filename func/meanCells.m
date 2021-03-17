function m = meanCells(A,dim,omitnan)
    if nargin < 2 || isempty(dim)
        dim = 1;
    end
    if nargin < 3 || isempty(omitnan)
        omitnan = true;
    end
    if omitnan
        omitnan = 'omitnan';
    else
        omitnan = 'includenan';
    end
    if ~iscell(A)
        m = mean(A,dim,omitnan);
    else
        m = cell(size(A));
        for i = 1:numel(A)
            m{i} = mean(A{i},dim,omitnan);
        end
    end
end
