function T = dataToNaN(T)
    isT = istable(T);
    if isT
        T = table2struct(T,'ToScalar',true);
    end
    fn = fieldnames(T);
    for j = 1:numel(fn)
        if isnumeric(T.(fn{j}))
            T.(fn{j})(T.(fn{j}) == -666) = NaN;
        elseif iscell(T.(fn{j}))
            T.(fn{j})(strcmpi(T.(fn{j}),'-666')) = {'NaN'};
        end
    end
    if isT
        T = struct2table(T);
    end
end