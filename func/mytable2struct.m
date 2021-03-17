function S = mytable2struct(T)
    f = T.Properties.VariableNames;
    ff = cell(1,2*numel(f));
    ff(1:2:end) = f;
    S = struct(ff{:});
    for i = 1:numel(f)
        l = f{i};
        S.(l) = T.(l);
    end
end