function [fh,axh] = plot5AxesFigure(ps1, ps2, figPos, axPos, axArgs, fp)
    fh(1) = figure('Renderer', 'painters', 'Position', figPos);
    n = numel(axPos);
    legProp = cell(1,n);
    legProp{1} = {'Location', 'northwest', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'};
    ps = cell(1,n);
    ps = cellfun(@(x)ps2, ps, 'UniformOutput', false);
    ps{1} = ps1;
    for i = 1:n
        if ~isempty(axPos{i})
            axh(i) = axes('Position', axPos{i});
            plotPlotStruct(axh(i), ps{i}, fp.pLines, [], fp.pSymbols, fp.pColors, ...
                {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
                {'ShowErrorBar', 'on', 'LineSpec', fp.pErrLineSpec, 'LineWidth', fp.pErrLineWidth, 'Color', fp.pErrLineColor},... % error properties
                ['Box', 'on', 'Layer', 'top', axArgs{i}],... % axis properties
                legProp{i},... % legend properties
                {'FontSize', 12}); % label properties
        end
    end
end
