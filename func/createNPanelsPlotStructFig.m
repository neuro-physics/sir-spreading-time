function [fh,axh] = createNPanelsPlotStructFig(ps, psProp, L, mainTitle)
    if nargin < 2 || isempty(psProp)
        psProp = repmat(getPlotStructProperties(), size(ps));
    end
    if nargin < 3 || isempty(L)
        L = ceil(numel(ps)/2);
    end
    if nargin < 4
        mainTitle = [];
    end
    fp = getDefaultFigureProperties();
    N = numel(ps);
    R = ceil(N/L);
    panelW = 300; % px
    whRatio = 1.6;
    panelH = panelW / whRatio;
    x0Ax = 45; % px
    y0Ax = x0Ax; % px
    rMargin = x0Ax / 3;
    figTitleH = 0;
    if ~isempty(mainTitle)
        figTitleH = 45;
    end
    figW = L * (panelW + x0Ax) + rMargin;
    figH = R * (panelH + y0Ax) + figTitleH;
    
    if numel(psProp)~=N
        psProp = repmat(psProp(1), size(ps));
    end

    fh = figure('Position', [fp.x0Fig, fp.y0Fig, figW, figH]);
    for k = 1:N
        [i,j] = ind2sub(L, k);
        x = x0Ax + (i-1) * (panelW + x0Ax);
        y = figH - figTitleH - j * panelH - (j-1)*y0Ax;
        axh(k) = axes('Units', 'pixels', 'Position', [x,y,panelW,panelH]);
        plotPlotStruct(axh(k), ps(k), psProp(k).lineSet, psProp(k).widthSet, psProp(k).symbolSet, psProp(k).colorSet, psProp(k).plotArgs, psProp(k).errArgs, psProp(k).axisArgs, psProp(k).legendArgs, psProp(k).labelArgs, psProp(k).titleArgs);
        axh(k).Units = 'normalized';
    end
    %ax1Pos = [x0Ax, y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
    %ax2Pos = [(x0Ax + panelW), y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
    %ax3Pos = [(x0Ax + 2*panelW), y0Ax,(panelW-x0Ax), (panelW-y0Ax)];

    
    %axh(2) = axes('Units', 'pixels', 'Position', ax2Pos);
    %axh(3) = axes('Units', 'pixels', 'Position', ax3Pos);
    
%     axh(2).Position = ax2Pos;
%     axh(3).Position = ax3Pos;
%     axis(axh(1),'square')
%     axis(axh(2),'square')
%     axis(axh(3),'square')
%     anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', mainTitle, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
%     anh.Position(1) = figW/2 - x0Ax - anh.Position(3)/2;
%     anh.Position(2) = panelW + y0Ax;
%     anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{1}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
%     anh.Position(1) = ax1Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
%     anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
%     anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{2}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
%     anh.Position(1) = ax2Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
%     anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
%     anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{3}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
%     anh.Position(1) = ax3Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
%     anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
%     axh(1).YLabel.String = 'seed';
%     axh(2).XLabel.String = 'target';
end
