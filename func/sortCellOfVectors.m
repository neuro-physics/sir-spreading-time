function s = sortCellOfVectors(c)
    r = zeros(size(c));
    for i = 1:numel(r)
        c{i} = sort(c{i});
        r(i) = c{i}(1);
    end
    [~,k] = sort(r);
    s = c(k);
end
