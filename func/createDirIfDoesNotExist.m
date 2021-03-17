function createDirIfDoesNotExist(d)
    if ~iscell(d)
        d = {d};
    end
    for i = 1:numel(d)
        if exist(d{i},'dir') ~= 7
            mkdir(d{i});
        end
    end
end