function r = moveManyFiles(src,dest)
    if isempty(src)
        r = [];
        return;
    end
    if iscell(src)
        r = cell(size(src));
        for i = 1:numel(src)
            if isempty(src{i})
                continue;
            end
            if exist(src{i},'file')
                r{i} = movefile(src{i},dest);
            end
        end
    else
        if exist(src,'file')
            r = movefile(src,dest);
        end
    end
end
