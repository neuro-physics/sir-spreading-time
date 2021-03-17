function plot_sim_data_TwoSeeds_theta_paper(si1,N,plotData,~,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix)

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

%     if isActThresh
%         si1 = resetTheta(si1, 0.03);
%         if ~isempty(si2)
%             si2 = resetTheta(si2, 0.03);
%         end
%     end

    legVal = { 'Controls', 'TLE' };
    
%     N = si1.N;

    %% average entropy vs. Theta
    [fh,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.H_theta,si1.patientData.H_theta,si1.controlData.HStd_theta,si1.patientData.HStd_theta,...
        si1.controlData.HAll_theta,si1.patientData.HAll_theta,[si1.ttest.H_theta(:).hFDR],[],[],...
        '$\theta$','$\langle H\rangle$',[legVal,'T-Test (FDR)']);
    plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    figNames = { fullfile(outputDir,['entropy_avg_theta_N',num2str(N),oFileSuffix]) };
    
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.HAll_theta,si1.patientData.HAll_theta,[],...
        [si1.ttest.H_theta(:).h],[si1.ttest.H_theta(:).hFDR],[],[],...
        '$\langle H\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['entropy_theta_N',num2str(N),oFileSuffix]);

    %% average conformity vs theta
    [fh1,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.Cf_theta,si1.patientData.Cf_theta,si1.controlData.CfStd_theta,si1.patientData.CfStd_theta,...
        si1.controlData.CfAll_theta,si1.patientData.CfAll_theta,[si1.ttest.Cf_theta(:).hFDR],[],[],...
        '$\theta$','$\langle C\rangle$',[legVal,'T-Test (FDR)']);
    plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['nodeconf_avg_theta_N',num2str(N),oFileSuffix]);
    
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.CfAll_theta,si1.patientData.CfAll_theta,[],...
        [si1.ttest.Cf_theta(:).h],[si1.ttest.Cf_theta(:).hFDR],[],[],...
        '$\langle C\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['nodeconf_theta_N',num2str(N),oFileSuffix]);

    %% average competitiveness Vs. theta
    [fh1,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.Cp_theta,si1.patientData.Cp_theta,si1.controlData.CpStd_theta,si1.patientData.CpStd_theta,...
        si1.controlData.CpAll_theta,si1.patientData.CpAll_theta,[si1.ttest.Cp_theta(:).hFDR],[],[],...
        '$\theta$','$\langle A\rangle$',[legVal,'T-Test (FDR)']);
    plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['nodecomp_avg_theta_N',num2str(N),oFileSuffix]);
    
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.CpAll_theta,si1.patientData.CpAll_theta,[],...
        [si1.ttest.Cp_theta(:).h],[si1.ttest.Cp_theta(:).hFDR],[],[],...
        '$\langle A\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['nodecomp_theta_N',num2str(N),oFileSuffix]);



    %%
    if saveOutputFigures
        saveFigure(fh, figNames, imgFormat);
    end

end
