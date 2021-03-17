function cbh = changeCBarToTxtLabel(cbh,lab)
    n = numel(cbh);
    for i = 1:n
        if ~isempty(fieldnames(cbh(i)))
            if iscell(lab)
                cbh(i).Ticks = cbh(i).Limits ./ 2 + sign(cbh(i).Limits) .* 0.175;
                cbh(i).TickLabels = lab;
            else
                cbh(i).Ticks = sum(cbh(i).Limits)/2;
                cbh(i).TickLabels = {lab};
            end
        end
    end
end
