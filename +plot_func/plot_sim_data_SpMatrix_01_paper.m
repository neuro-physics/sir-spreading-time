function plot_sim_data_SpMatrix_01_paper(si1,N,~,thetaVal,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix,showMTLData,volumeVarName)

%     if (nargin < 11) || isempty(isConsensus)
%         isConsensus = false;
%     end

%     if (nargin < 3) || isempty(plotData)
%         plotData = 'raw';
%     end

    if (nargin < 12) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    
    if (nargin < 13) || isempty(showMTLData)
        showMTLData = true;
    end
    
    if (nargin < 14) || isempty(volumeVarName)
        volumeVarName = 'Hippocampus';
    end


    % part of plot_sim_data.m

%     fp = getDefaultFigureProperties();
%     fp.pLines = {':'};
%     fp.pPointSize = 3;
%     fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];

%     if isActThresh
%         si1 = resetTheta(si1, 0.03);
%     end
    
%     N = si1.N;

    hasHammDistData = ~isempty(si1.controlData.DAll_theta) && ~isempty(si1.controlData.DAll_theta{1});
    
    %fill_between_lines = @(X1,X2,Y,faceC) patch([X1(:)' fliplr(X2(:)')], [Y(:)' fliplr(Y(:)')], faceC);

    legVal = { 'Controls', 'TLE', 'T-Test (FDR)', 'T-Test CT', 'T-Test HV' };

    %nPanels = numel(si1.theta);

    %% correlation of spreading times and hippocampus volume and cortical thickness
    outputDirCorr = fullfile(outputDir,'corr');
    if exist(outputDirCorr,'dir')~=7
        mkdir(outputDirCorr);
    end

    [~,dataInd,~] = intersect(si1.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si1.theta);
    end
    plotTitle = cellfun(@(x)['\theta=',num2str(si1.theta(x))],num2cell(dataInd),'UniformOutput',false);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if false
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    [fh1,~] = plotSIScatterCorr(si1,'HVAll','SAll_theta',dataInd,[volumeVarName,' volume (Z)'],'Avg. Sp. Time (Z)',legVal(1:2),plotTitle);
    [fh2,~] = plotSIScatterCorr(si1,'CTAll','SAll_theta',dataInd,'Cortical thickness (Z)','Avg. Sp. Time (Z)',legVal(1:2),plotTitle);
    [fh3,~] = plotSIScatterCorr(si1,'SAvgR_node','SAvgS_node',dataInd,'Avg. in-spreading time (Z)','Avg. out-spreading time (Z)',legVal(1:2),plotTitle);
    fn1 = cellfun(@(x)fullfile(outputDirCorr,['sptime_hipvol_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fn2 = cellfun(@(x)fullfile(outputDirCorr,['sptime_cthick_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fn3 = cellfun(@(x)fullfile(outputDirCorr,['sptime_in_out_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    if saveOutputFigures
        saveFigure([fh1,fh2,fh3],[fn1,fn2,fn3],imgFormat);
    end

    if showMTLData
        [~,mtlLabL] = shrinkStrByCapLetters(si1.mtlLabL);
        plot_mtl_corr_fig(si1,N,dataInd,saveOutputFigures,outputDirCorr,imgFormat,oFileSuffix,legVal,plotTitle,mtlLabL,'L',volumeVarName);
        [~,mtlLabR] = shrinkStrByCapLetters(si1.mtlLabR);
        plot_mtl_corr_fig(si1,N,dataInd,saveOutputFigures,outputDirCorr,imgFormat,oFileSuffix,legVal,plotTitle,mtlLabR,'R',volumeVarName);
    end
    
    %% average Spreading Time vs. Theta
    [fh,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.SAvg_theta,si1.patientData.SAvg_theta,si1.controlData.SStd_theta,si1.patientData.SStd_theta,...
        si1.controlData.SAll_theta,si1.patientData.SAll_theta,[si1.ttest.SAvg_theta(:).hFDR],[si1.ttest.SAvg_CT_theta(:).hFDR],[si1.ttest.SAvg_HV_theta(:).hFDR],...
        '$\theta$','$\langle S\rangle$',legVal, [], [], 0.0003);
    %plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
    axh.XTick = si1.theta;
    axh.XTickLabel{4} = [axh.XTickLabel{4},'*'];
    figNames = { fullfile(outputDir,['sptime_avg_theta_N',num2str(N),oFileSuffix]) };

    %% average sp time vs theta (many panels)
    [fh1,~] = plotAvgVsThetaScatterPanels(si1.theta,si1.controlData.SAll_theta,si1.patientData.SAll_theta,[],...
        [si1.ttest.SAvg_theta(:).h],[si1.ttest.SAvg_theta(:).hFDR],[si1.ttest.SAvg_CT_theta(:).hFDR],[si1.ttest.SAvg_HV_theta(:).hFDR],...
        '$\langle S\rangle$',legVal);
    fh(end+1) = fh1;
    figNames{end+1} = fullfile(outputDir,['sptime_theta_N',num2str(N),oFileSuffix]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %% average Hamming distance (S,shortPath) Vs. theta
    if hasHammDistData
        fh = gobjects(0,1);
        figNames={};
        % hamming vs. theta
        [fh1,axh] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.D_theta,si1.patientData.D_theta,si1.controlData.DStd_theta,si1.patientData.DStd_theta,...
            si1.controlData.DAll_theta,si1.patientData.DAll_theta,[],[],[],... % si1.controlData.DAll_theta,si1.patientData.DAll_theta,[si1.ttest.D_theta(:).hFDR],[],[],...
            '$\theta$','$\langle D(T,P)\rangle$',legVal(1:3), [], [],0.0003);
        %plotVerticalLines(axh,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
        axh.XTick = si1.theta;
        axh.XTickLabel{4} = [axh.XTickLabel{4},'*'];
        fh(end+1) = fh1;
        figNames{end+1} = fullfile(outputDir,['hammD_TLE_avg_theta_N',num2str(N),oFileSuffix]);
        
        % Hamming + avg SpTime
        [fh1,axh1] = plotAvgVsThetaScatter([],[],si1.theta,si1.controlData.SAvg_theta,si1.patientData.SAvg_theta,si1.controlData.SStd_theta,si1.patientData.SStd_theta,...
            si1.controlData.SAll_theta,si1.patientData.SAll_theta,[],[],[],... % si1.controlData.SAll_theta,si1.patientData.SAll_theta,[si1.ttest.SAvg_theta(:).hFDR],[si1.ttest.SAvg_CT_theta(:).hFDR],[si1.ttest.SAvg_HV_theta(:).hFDR],...
            '$\theta$','$\langle T\rangle$',legVal,[],0.05,0.0003);
        %plotVerticalLines(axh1,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
        axh1.XTick = si1.theta;
        axh1.XTickLabel{4} = [axh1.XTickLabel{4},'*'];
        axh1.Position = [0.0562 0.1057 0.4331 0.6526];
        [~,axh2] = plotAvgVsThetaScatter(fh1,[],si1.theta,si1.controlData.D_theta,si1.patientData.D_theta,si1.controlData.DStd_theta,si1.patientData.DStd_theta,...
            si1.controlData.DAll_theta,si1.patientData.DAll_theta,[],[],[],... % si1.controlData.DAll_theta,si1.patientData.DAll_theta,[si1.ttest.D_theta(:).hFDR],[],[],...
            '$\theta$','$\langle D(T,P)\rangle$',legVal(1:3),[],0.01,0.0003);
        %plotVerticalLines(axh2,0.0152,'LineStyle','--','Color','k','LineWidth',1,'HandleVisibility','off');
        axh2.XTick = si1.theta;
        axh2.XTickLabel{4} = [axh2.XTickLabel{4},'*'];
        axh2.Position = [0.5629 0.1057 0.4331 0.6526];
        fh(end+1) = fh1;
        figNames{end+1} = fullfile(outputDir,['sptime_hammD_TLE_avg_theta_N',num2str(N),oFileSuffix]);
        
        % hamming 1 panel per theta
        [fh1,axh] = plotAvgVsThetaScatterPanels(si1.theta(2:end),si1.controlData.DAll_theta(2:end),si1.patientData.DAll_theta(2:end),[],...
            [si1.ttest.D_theta(:).h],[si1.ttest.D_theta(2:end).hFDR],[],[],...
            '$\langle D(T,P)\rangle$',legVal);
        fh(end+1) = fh1;
        figNames{end+1} = fullfile(outputDir,['hammD_TLE_theta_N',num2str(N),oFileSuffix]);
    end
    %%
    if saveOutputFigures
        saveFigure(fh,figNames,imgFormat);
    end

end

function plot_mtl_corr_fig(si1,N,dataInd,saveOutputFigures,outputDirCorr,imgFormat,oFileSuffix,legVal,plotTitle,mtlLab,mtlSide,volumeVarName)
    dataLabel = @(r) ['SAll',r,'_mtl',mtlSide,'_theta'];
    
    [fh1,~] = plotSIScatterCorr(si1,'HVAll',dataLabel(''),dataInd,[volumeVarName,' volume (Z)'],'Avg. Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    [fh2,~] = plotSIScatterCorr(si1,'CTAll',dataLabel(''),dataInd,'Cortical thickness (Z)','Avg. Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    fn1 = cellfun(@(x)fullfile(outputDirCorr,['sptime_io_hipvol_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fn2 = cellfun(@(x)fullfile(outputDirCorr,['sptime_io_cthick_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    if saveOutputFigures
        saveFigure([fh1,fh2],[fn1,fn2],imgFormat);
    end
    [fh1,~] = plotSIScatterCorr(si1,'HVAll',dataLabel('R'),dataInd,[volumeVarName,' volume (Z)'],'Avg. In Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    [fh2,~] = plotSIScatterCorr(si1,'CTAll',dataLabel('R'),dataInd,'Cortical thickness (Z)','Avg. In Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    fn1 = cellfun(@(x)fullfile(outputDirCorr,['sptime_in_hipvol_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fn2 = cellfun(@(x)fullfile(outputDirCorr,['sptime_in_cthick_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    if saveOutputFigures
        saveFigure([fh1,fh2],[fn1,fn2],imgFormat);
    end
    [fh1,~] = plotSIScatterCorr(si1,'HVAll',dataLabel('S'),dataInd,[volumeVarName,' volume (Z)'],'Avg. Out Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    [fh2,~] = plotSIScatterCorr(si1,'CTAll',dataLabel('S'),dataInd,'Cortical thickness (Z)','Avg. Out Sp. Time (Z)',legVal(1:2),plotTitle,mtlLab);
    fn1 = cellfun(@(x)fullfile(outputDirCorr,['sptime_out_hipvol_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fn2 = cellfun(@(x)fullfile(outputDirCorr,['sptime_out_cthick_MTL-',mtlSide,'_corr_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    if saveOutputFigures
        saveFigure([fh1,fh2],[fn1,fn2],imgFormat);
    end
    
    if strcmp(mtlSide,'L')
        ppTitle = ['Ipsi ',plotTitle];
    else
        ppTitle = ['Contra ',plotTitle];
    end
    [fh1,~] = plotSIScatterCorr(si1,['SZR_mtl',mtlSide],['SZS_mtl',mtlSide],dataInd,'Avg. in-spreading time (Z)','Avg. out-spreading time (Z)',legVal(1:2),ppTitle,mtlLab,1);
    fn1 = cellfun(@(x)fullfile(outputDirCorr,['sptime_in_out_corr_MTL-',mtlSide,'_N',num2str(N),'_theta',num2str(x),oFileSuffix]),num2cell(si1.theta(dataInd)),'UniformOutput',false);
    if saveOutputFigures
        saveFigure(fh1,fn1,imgFormat);
    end
end