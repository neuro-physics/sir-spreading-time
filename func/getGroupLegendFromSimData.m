function gn = getGroupLegendFromSimData(s)
    fn = fieldnames(s);
    gn = cell(1,numel(fn));
    for i = 1:numel(fn)
        l = fn{i};
        if iscell(s.(l).Side)
            for j = 1:numel(s.(l).Side)
                gn{i} = [ gn{i}, s.(l).Side{j} ];
            end
        else
            if strcmpi(s.(l).Side,'all')
                gn{i} = 'TLE';
            else
                gn{i} = [ gn{i}, s.(l).Side ];
            end
        end
        if iscell(s.(l).HipPath)
            gn{i} = [ gn{i}, '_' ];
            for j = 1:numel(s.(l).HipPath)
                gn{i} = [ gn{i}, s.(l).HipPath{j} ];
            end
        else
            if ~strcmpi(s.(l).HipPath,'all')
                gn{i} = [ '_', gn{i}, s.(l).HipPath ];
            end
        end
    end
end
