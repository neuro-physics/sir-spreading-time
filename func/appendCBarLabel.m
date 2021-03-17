function cbh = appendCBarLabel(cbh,lab)
    n = numel(cbh);
    for i = 1:n
        if ~isempty(fieldnames(cbh(i)))
            if iscell(lab)
                cbh(i).Label.String = [cbh(i).Label.String,lab{i}];
            else
                cbh(i).Label.String = [cbh(i).Label.String,lab];
            end
        end
    end
end