function v = cell2LinVec(s)
    if iscell(s)
        v = cell2LinVec(s{1});
        for i = 2:numel(s)
            v = [v,cell2LinVec(s{i})];
        end
    else
        v = reshape(s,1,[]);
    end
end