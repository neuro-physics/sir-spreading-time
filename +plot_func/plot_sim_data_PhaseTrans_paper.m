function plot_sim_data_PhaseTrans_paper(si1,thetaVal,~,~,~,~,saveOutputFigures,outputDir,imgFormat,oFileSuffix,~)

    if (nargin < 2) || isempty(thetaVal)
        thetaVal = [];
    end
    if (nargin < 10) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    
%     if (nargin < 11) || isempty(isConsensus)
%         isConsensus = false;
%     end

    % part of plot_sim_data.m
    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;
    fp.pColors = [hex2rgb({'#6a3d9a','#33a02c'});fp.pColors];

%     if isempty(si_n90.(cGroup).PhaseTrans) || isempty(si_n90.(p1Group).PhaseTrans) || isempty(si_n90.(p2Group).PhaseTrans) || ...
%             isempty(si_n306.(cGroup).PhaseTrans) || isempty(si_n306.(p1Group).PhaseTrans) || isempty(si_n306.(p2Group).PhaseTrans)
%         return;
%     end

%     if iscell(si1)
%         N = si1{1}.N;
%         cData = si1{1}.controlData;
%     else
    N = si1.N;
%         cData = si1.controlData;
%     end

    %% phase transition: fraction of activated sites
%     fh(1) = figure('Renderer', 'painters', 'Position', [ 400, 400, fp.wFig/2, fp.hFig ]);
    fh(1) = figure('Renderer', 'painters', 'Position', [ fp.x0Fig, fp.y0Fig, fp.wFig/2, fp.hFig ]);
    axh(1) = axes('Position', [3*fp.lMargin,fp.bMargin,fp.wAx,fp.hAx/2]);

    % s = getPlotStruct(x, y, yErr, xLabel, yLabel, xScale, yScale, legendParName, legendParValues, showLegend, plotTitle)
    x1 = { si1.Theta, si1.Theta };
    y1 = { si1.controlData.rho, si1.patientData.rho };
    yErr1 = { si1.controlData.rhoStd, si1.patientData.rhoStd };
    legVal = { 'Controls', 'TLE' };
%     legVal = [cellfun(@(x)[x,'; $N=90$'],legVal,'UniformOutput',false),cellfun(@(x)[x,'; $N=306$'],legVal,'UniformOutput',false)];
%     ps1 = getPlotStruct(x1,y1,yErr1,'Threshold, $\theta$', {'Avg. density of', 'activated sites, $\langle\rho\rangle$'}, 'linear', 'linear', '', legVal, 1, '');
    ps1 = getPlotStruct(x1,y1,yErr1,'Threshold, \theta', '\langle\rho\rangle', 'linear', 'linear', '', legVal, 1, '');
    plotPlotStruct(axh(1), ps1, fp.pLines, [], fp.pSymbols, fp.pColors, ...
        {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineSpec', fp.pErrLineSpec, 'LineWidth', fp.pErrLineWidth, 'Color', fp.pErrLineColor},... % error properties
        {'Box', 'on', 'Layer', 'top', 'XLim', [0,0.18], 'YLim', [-0.02,1.02]},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'tex'},... % legend properties
        {'Interpreter', 'tex', 'FontSize', 11}); % label properties
    plotVerticalLines(axh(1),union([0.01,0.03],thetaVal(:)'),'LineStyle',':','Color','k','LineWidth',0.5,'HandleVisibility','off');

    %% phase transition: distribution of thresholds
%     fh(2) = figure('Renderer', 'painters', 'Position', [ 400, 400, fp.wFig/2, fp.hFig ]);
%     axh(2) = axes('Position', [2*fp.lMargin,fp.bMargin,fp.wAx,fp.hAx/2]);
    axh(2) = axes('Position', [(5.2*fp.lMargin+fp.wAx),fp.bMargin,fp.wAx/2,fp.hAx/2]);

    x2 = { si1.controlData.ThetaTh, si1.patientData.ThetaTh };
    y2 = { si1.controlData.ThetaTh, si1.patientData.ThetaTh };
    ps2 = getPlotStruct(x2,y2,cell(size(x2)),'', '$\theta_{0}$', 'bar', 'linear', '', legVal, 0, '');
    [pps2,xTicks] = getMeanStdPlotStruct(ps2,'','$\theta_{0}$','linear','linear','',legVal,0,'');
    %ps2 = mergePlotStruct(ps2,pps2);
    
    if N == 90
        yLim = [0.0068,0.0659];
    else
%         yMin = min([si1.controlData.ThetaTh(:);si1.patientData.ThetaTh(:)]);
%         yMax = max([si1.controlData.ThetaTh(:);si1.patientData.ThetaTh(:)]);
%         yLim = [ yMin, yMax ];
        yLim = [0.008,0.04];
    end

    fp.pPointSize = 3;
    plotPlotStruct(axh(2), ps2, {'n'}, [], fp.pSymbols, fp.pColors, ...
        {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineWidth', 3, 'Color', fp.pErrLineColor},... % error properties
        {'Box', 'on', 'Layer', 'top', 'XTick', xTicks, 'XTickLabel', legVal, 'XLim', [-0.5,(2*numel(x2)-0.5)], 'YLim', yLim},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12, 'YDisplacement', [0.12,0,0]}); % label properties
    hold(axh(2),'all');
    plotPlotStruct(axh(2), pps2, {'n'}, [], '+', [0,0,0], ...
        {'LineWidth', 14, 'MarkerSize', 2},... % plot properties
        {'ShowErrorBar', 'on', 'LineWidth', 2, 'Color', fp.pErrLineColor}); % label properties
    hold(axh(2),'off');

    %% saving figures

    if saveOutputFigures
        saveFigure(fh(1),fullfile(outputDir,['pt_rho_theta',oFileSuffix]),imgFormat);
%         saveFigure(fh(2),fullfile(outputDir,['pt_actThresh',oFileSuffix]),imgFormat);
    end

end
