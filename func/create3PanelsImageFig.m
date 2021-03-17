function [fh,axh,imh,cbh] = create3PanelsImageFig(imgs, titles, mainTitle)
    panelW = 300; % px
    x0Ax = 45; % px
    y0Ax = x0Ax; % px
    cBarW = 60; % px
    ax1Pos = [x0Ax, y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
    ax2Pos = [(x0Ax + panelW), y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
    ax3Pos = [(x0Ax + 2*panelW), y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
    figW = cBarW + 3 * panelW;

    fh = figure('Position', [400,400, figW,(panelW + x0Ax)]);
    axh(1) = axes('Units', 'pixels', 'Position', ax1Pos);
    axh(2) = axes('Units', 'pixels', 'Position', ax2Pos);
    axh(3) = axes('Units', 'pixels', 'Position', ax3Pos);
    imh(1) = imagesc(axh(1), imgs{1});
    imh(2) = imagesc(axh(2), imgs{2});
    imh(3) = imagesc(axh(3), imgs{3});
    axh(2).Position = ax2Pos;
    axh(3).Position = ax3Pos;
    axis(axh(1),'square')
    axis(axh(2),'square')
    axis(axh(3),'square')
    anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', mainTitle, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
    anh.Position(1) = figW/2 - x0Ax - anh.Position(3)/2;
    anh.Position(2) = panelW + y0Ax;
    anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{1}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
    anh.Position(1) = ax1Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
    anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
    anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{2}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
    anh.Position(1) = ax2Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
    anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
    anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titles{3}, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
    anh.Position(1) = ax3Pos(1) + ax1Pos(3)/2 - anh.Position(3)/2;
    anh.Position(2) = panelW + anh.Position(4) + y0Ax/3;
    axh(1).YLabel.String = 'seed';
    axh(2).XLabel.String = 'target';
end
