function g = getIndexGroups(c)
    u = unique(c);
    g = cell(size(u));
    for i = 1:numel(u)
        g{i} = find(c == u(i));
    end
end
