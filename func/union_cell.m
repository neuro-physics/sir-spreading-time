function u = union_cell(c,varargin)
    u = c{1};
    for i = 2:numel(c)
        u = union(u,c{i},varargin{:});
    end
end