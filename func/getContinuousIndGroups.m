function s = getContinuousIndGroups(r)
    s = {};
    ki = 1;
    j = 0;
    for i = 2:numel(r)
        if (abs(r(i) - r(i-1)) > 1)
            j = j + 1;
            s{j} = r(ki:(i-1));
            ki = i;
        end
    end
    s{end+1} = r(ki:end);
    s = sortCellOfVectors(s);
end
