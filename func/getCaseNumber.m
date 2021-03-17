function c = getCaseNumber(cn)
    if iscell(cn)
        c = cell(size(cn));
        for i = 1:numel(cn)
            c{i} = getCaseNumber(cn{i});
        end
    else
        c = regexp(cn,'^\d+(_|$)','match');
        if iscell(c)
            c = c{1};
        end
        if strcmp(c(end),'_')
            c(end) = [];
        end
    end
end