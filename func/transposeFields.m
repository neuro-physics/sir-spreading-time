function S = transposeFields(S)
    fn = fieldnames(S);
    for i = 1:numel(fn)
        f = fn{i};
        S.(f) = S.(f)';
    end
end