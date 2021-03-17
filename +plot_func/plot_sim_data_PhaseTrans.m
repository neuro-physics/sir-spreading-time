function plot_sim_data_PhaseTrans(si_n90,si_n306,cGroup,p1Group,p2Group,groupLegend,saveOutputFigures,outputDir,imgFormat,oFileSuffix,isConsensus)

    if (nargin < 10) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    
    if (nargin < 11) || isempty(isConsensus)
        isConsensus = false;
    end

    % part of plot_sim_data.m
    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;

    if isempty(si_n90.(cGroup).PhaseTrans) || isempty(si_n90.(p1Group).PhaseTrans) || isempty(si_n90.(p2Group).PhaseTrans) || ...
            isempty(si_n306.(cGroup).PhaseTrans) || isempty(si_n306.(p1Group).PhaseTrans) || isempty(si_n306.(p2Group).PhaseTrans)
        return;
    end

    %% phase transition: fraction of activated sites
    fh(1) = figure('Renderer', 'painters', 'Position', [ 400, 400, fp.wFig/2, fp.hFig ]);
    axh(1) = axes('Position', [2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx]);

    % s = getPlotStruct(x, y, yErr, xLabel, yLabel, xScale, yScale, legendParName, legendParValues, showLegend, plotTitle)
    x1 = { si_n90.(cGroup).PhaseTrans.Theta, si_n90.(p1Group).PhaseTrans.Theta, si_n90.(p2Group).PhaseTrans.Theta,...
           si_n306.(cGroup).PhaseTrans.Theta, si_n306.(p1Group).PhaseTrans.Theta, si_n306.(p2Group).PhaseTrans.Theta };
    y1 = { si_n90.(cGroup).PhaseTrans.controlData.rho, si_n90.(p1Group).PhaseTrans.patientData.rho, si_n90.(p2Group).PhaseTrans.patientData.rho,...
           si_n306.(cGroup).PhaseTrans.controlData.rho, si_n306.(p1Group).PhaseTrans.patientData.rho, si_n306.(p2Group).PhaseTrans.patientData.rho };
    yErr1 = { si_n90.(cGroup).PhaseTrans.controlData.rhoStd, si_n90.(p1Group).PhaseTrans.patientData.rhoStd, si_n90.(p2Group).PhaseTrans.patientData.rhoStd,...
              si_n306.(cGroup).PhaseTrans.controlData.rhoStd, si_n306.(p1Group).PhaseTrans.patientData.rhoStd, si_n306.(p2Group).PhaseTrans.patientData.rhoStd };
    legVal = [ 'Controls', strrep(groupLegend(2:end),'_','-') ];
    legVal = [cellfun(@(x)[x,'; $N=90$'],legVal,'UniformOutput',false),cellfun(@(x)[x,'; $N=306$'],legVal,'UniformOutput',false)];
    ps1 = getPlotStruct(x1,y1,yErr1,'Threshold, $\theta$', 'Avg. density of activated sites, $\langle\rho\rangle$', 'linear', 'linear', '', legVal, 1, '');

    plotPlotStruct(axh(1), ps1, fp.pLines, [], fp.pSymbols, fp.pColors, ...
        {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineSpec', fp.pErrLineSpec, 'LineWidth', fp.pErrLineWidth, 'Color', fp.pErrLineColor},... % error properties
        {'Box', 'on', 'Layer', 'top', 'XLim', [0,0.23]},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties

    %% phase transition: distribution of thresholds
    axh(2) = axes('Position', [0.6275 0.3300 0.3450 0.2200]);

    x2 = { si_n90.(cGroup).PhaseTrans.controlData.ThetaTh, si_n90.(p1Group).PhaseTrans.patientData.ThetaTh, si_n90.(p2Group).PhaseTrans.patientData.ThetaTh,...
           si_n306.(cGroup).PhaseTrans.controlData.ThetaTh, si_n306.(p1Group).PhaseTrans.patientData.ThetaTh, si_n306.(p2Group).PhaseTrans.patientData.ThetaTh };
    y2 = { si_n90.(cGroup).PhaseTrans.controlData.ThetaTh, si_n90.(p1Group).PhaseTrans.patientData.ThetaTh, si_n90.(p2Group).PhaseTrans.patientData.ThetaTh,...
           si_n306.(cGroup).PhaseTrans.controlData.ThetaTh, si_n306.(p1Group).PhaseTrans.patientData.ThetaTh, si_n306.(p2Group).PhaseTrans.patientData.ThetaTh };
    ps2 = getPlotStruct(x2,y2,cell(size(x2)),'Case', '$\theta_{0}$', 'bar', 'linear', '', legVal, 0, '');

    fp.pPointSize = 3;
    plotPlotStruct(axh(2), ps2, {'n'}, [], fp.pSymbols, fp.pColors, ...
        {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
        {'ShowErrorBar', 'off'},... % error properties
        {'Box', 'off', 'Layer', 'top', 'XTickLabel', [], 'XTick', [], 'XLim', [-1,2*numel(x2)], 'YLim', [0.0068,0.0659]},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12, 'YDisplacement', [0.04,0,0]}); % label properties

    %% saving figures

    if saveOutputFigures
        saveFigure(fh,fullfile(outputDir,['pt_rho_theta',oFileSuffix]),imgFormat);
    end

end
