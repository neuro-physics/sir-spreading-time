function plot_sim_data_SpeedUp_theta_paper(si1,N,plotData,~,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix)

%     if (nargin < 11) || isempty(isConsensus)
%         isConsensus = false;
%     end

    if (nargin < 3) || isempty(plotData)
        plotData = 'raw';
    end

    if (nargin < 12) || isempty(oFileSuffix)
        oFileSuffix = '';
    end

    % part of plot_sim_data.m

%     fp = getDefaultFigureProperties();
%     fp.pLines = {':'};
%     fp.pPointSize = 3;
%     fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];

    legVal = { 'Controls', 'TLE' };
    oFileSuffix = ['_N',num2str(N),oFileSuffix];

    %% global speedup vs. Theta
    [fh,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.global_theta,si1.patientData.global_theta,si1.controlData.globalStd_theta,si1.patientData.globalStd_theta,...
        si1.controlData.globalAll_theta,si1.patientData.globalAll_theta,[si1.ttest.global_theta(:).hFDR],[],[],...
        '$\theta$','$\langle U_g\rangle$',[legVal,'T-Test (FDR)']);
    plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    figNames = {fullfile(outputDir,['speedup_global_avg_theta',oFileSuffix])};
    
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.globalAll_theta,si1.patientData.globalAll_theta,[],...
        [si1.ttest.global_theta(:).h],[si1.ttest.global_theta(:).hFDR],[],[],...
        '$\langle U_g\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['speedup_global_theta',oFileSuffix]);
    
    %% average conformity vs theta
    [fh1,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.localnet_theta,si1.patientData.localnet_theta,si1.controlData.localnetStd_theta,si1.patientData.localnetStd_theta,...
        si1.controlData.localnetAll_theta,si1.patientData.localnetAll_theta,[si1.ttest.localnet_theta(:).hFDR],[],[],...
        '$\theta$','$\langle U_l\rangle$',[legVal,'T-Test (FDR)']);
    plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['speedup_localnet_avg_theta',oFileSuffix]);
    
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.localnetAll_theta,si1.patientData.localnetAll_theta,[],...
        [si1.ttest.localnet_theta(:).h],[si1.ttest.localnet_theta(:).hFDR],[],[],...
        '$\langle U_l\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['speedup_localnet_theta',oFileSuffix]);

    %% average competitiveness Vs. theta
    if ~isempty(si1.controlData.localAll_theta{1})
        [fh1,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.local_theta,si1.patientData.local_theta,si1.controlData.localStd_theta,si1.patientData.localStd_theta,...
            si1.controlData.localAll_theta,si1.patientData.localAll_theta,[si1.ttest.local_theta(:).hFDR],[],[],...
            '$\theta$','$\langle U_l\rangle$',[legVal,'T-Test (FDR)']);
        plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
        fh(end+1) = fh1;
        figNames{end+1} = fullfile(outputDir,['speedup_local_avg_theta',oFileSuffix]);

        [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.localAll_theta,si1.patientData.localAll_theta,[],...
            [si1.ttest.local_theta(:).h],[si1.ttest.local_theta(:).hFDR],[],[],...
            '$\langle U_l\rangle$',legVal);
        fh(end+1) = fh1;
        figNames{end+1} = fullfile(outputDir,['speedup_local_theta',oFileSuffix]);
    end



    if saveOutputFigures
        saveFigure(fh, figNames, imgFormat);
    end

end
