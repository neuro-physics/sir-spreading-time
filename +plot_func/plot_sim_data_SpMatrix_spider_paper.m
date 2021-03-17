function plot_sim_data_SpMatrix_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix,aal,showMTLData,showEffectSizes,effectSzField,CohenThreshold)

%     if (nargin < 11) || isempty(isConsensus)
%         isConsensus = false;
%     end

    if (nargin < 4) || isempty(thetaVal)
        thetaVal = [];
    end
    if (nargin < 12) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    if (nargin < 14) || isempty(showMTLData)
        showMTLData = true;
    end
    if (nargin < 15) || isempty(showEffectSizes)
        showEffectSizes = true;
    end
    if (nargin < 16) || isempty(effectSzField)
        effectSzField = 'hFDR';
    end
    if (nargin < 17) || isempty(CohenThreshold)
        CohenThreshold = 0.8;
    end

    % part of plot_sim_data.m

    %fp = getDefaultFigureProperties();
    %fp.pLines = {':'};
    %fp.pPointSize = 3;

%     if isActThresh
%         si1 = resetTheta(si1, 0.03);
%         if ~isempty(si2)
%             si2 = resetTheta(si2, 0.03);
%         end
%     end

    nC = numel(si1.controlData.SZR_comm{2});
%     commLabel = cellfun(@(x)['Comm ',num2str(x)],num2cell(1:nC),'UniformOutput',false);
    [~,commLabel] = shrinkStrByCapLetters(aal.labels.AAL09comm,1,false);
%     [~,lobeLabelLR] = shrinkStrByCapLetters(regexprep(regexprep(lobeLabelLR,'_L$','_Ip'),'_R$','_Co'));
    [~,lobeLabelLR] = shrinkStrByCapLetters(regexprep(regexprep(lobeLabelLR,'_L$','_I'),'_R$','_C'),1,true);

%     [P,axLabel] = prepare_si_spider_data(si1,'SZR_lobe',1:4,lobeLabel,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
                 %prepare_si_spider_data(s                    ,dataLabel ,dataInd,axLabel           ,sRow,shiftData,patientsControlsDiff)

    [~,dataInd,~] = intersect(si1.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si1.theta);
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    txt = {};
    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZR_lobe','SZStdR_lobe','ttest_SZR_lobe_CT','ttest_SZR_lobe_HV'},dataInd,lobeLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{1} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(1) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. In Sp. Time per lobe',colNames,[],[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZS_lobe','SZStdS_lobe','ttest_SZS_lobe_CT','ttest_SZS_lobe_HV'},dataInd,lobeLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{2} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(2) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Out Sp. Time per lobe',colNames,[],[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZB_lobe','SZStdB_lobe','ttest_SZB_lobe_CT','ttest_SZB_lobe_HV'},dataInd,lobeLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{3} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(3) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Sp. Time inside lobe',colNames,[],[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZR_lobeLR','SZStdR_lobeLR','ttest_SZR_lobeLR_CT','ttest_SZR_lobeLR_HV'},dataInd,lobeLabelLR,[],3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{4} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(4) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. In Sp. Time per lobe',colNames,{'Interpreter','none'},[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZS_lobeLR','SZStdS_lobeLR','ttest_SZS_lobeLR_CT','ttest_SZS_lobeLR_HV'},dataInd,lobeLabelLR,[],3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{5} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(5) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Out Sp. Time per lobe',colNames,{'Interpreter','none'},[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZB_lobeLR','SZStdB_lobeLR','ttest_SZB_lobeLR_CT','ttest_SZB_lobeLR_HV'},dataInd,lobeLabelLR,[],3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{6} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(6) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Sp. Time inside lobe',colNames,{'Interpreter','none'},[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZR_comm','SZStdR_comm','ttest_SZR_comm_CT','ttest_SZR_comm_HV'},dataInd,commLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{7} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(7) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. In Sp. Time per Func Comm',colNames,[],[],0.1);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZS_comm','SZStdS_comm','ttest_SZS_comm_CT','ttest_SZS_comm_HV'},dataInd,commLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{8} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(8) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Out Sp. Time per Func Comm',colNames,[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZB_comm','SZStdB_comm','ttest_SZB_comm_CT','ttest_SZB_comm_HV'},dataInd,commLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
    txt{9} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(9) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Sp. Time inside Func Comm',colNames,[],[],0.1);

    lastInd = 9;
    if ~isCellOfEmpty(si1.controlData.D_lobe)
        lastInd = 12;
        [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,'D_lobe',dataInd,lobeLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
        txt{10} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fh(10) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Hamm. dist. per lobe',colNames,[],[],0.1);

        [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,'D_lobeLR',dataInd,lobeLabelLR,[],3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
        txt{11} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fh(11) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Hamm. dist. per lobe',colNames,{'Interpreter','none'},[],0.1);

        [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,'D_comm',dataInd,commLabel,[],[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
        txt{12} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fh(12) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. Hamm. dist per Func Comm ',colNames,[],[],0.1);
    end

    oFileSuffix = ['_N',num2str(si1.N),oFileSuffix];
    
    fn = {  fullfile(outputDir,['sptime_R_lobe',oFileSuffix]),...
            fullfile(outputDir,['sptime_S_lobe',oFileSuffix]),...
            fullfile(outputDir,['sptime_B_lobe',oFileSuffix]),...
            fullfile(outputDir,['sptime_R_lobeLR',oFileSuffix]),...
            fullfile(outputDir,['sptime_S_lobeLR',oFileSuffix]),...
            fullfile(outputDir,['sptime_B_lobeLR',oFileSuffix]),...
            fullfile(outputDir,['sptime_R_comm',oFileSuffix]),...
            fullfile(outputDir,['sptime_S_comm',oFileSuffix]),...
            fullfile(outputDir,['sptime_B_comm',oFileSuffix]),...
            fullfile(outputDir,['hammD_lobe',oFileSuffix]),...
            fullfile(outputDir,['hammD_lobeLR',oFileSuffix]),...
            fullfile(outputDir,['hammD_comm',oFileSuffix]) };
    if saveOutputFigures
        saveFigure(fh,fn,imgFormat);
    end
    writeTextFiles(appendStr(fn(1:lastInd),'.txt'),txt,~saveOutputFigures);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if showMTLData %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        nMTL = numel(si1.mtlLabL);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        fhMtlLLobe = gobjects(1,nMTL);
        fhMtlLLobeLR = gobjects(1,nMTL);
        fhMtlLComm = gobjects(1,nMTL);
        fnMtlLLobe = cell(1,nMTL);
        fnMtlLLobeLR = cell(1,nMTL);
        fnMtlLComm = cell(1,nMTL);
        txtMtlLLobe = cell(1,nMTL);
        txtMtlLLobeLR = cell(1,nMTL);
        txtMtlLComm = cell(1,nMTL);
        fhMtlRLobe = gobjects(1,nMTL);
        fhMtlRLobeLR = gobjects(1,nMTL);
        fhMtlRComm = gobjects(1,nMTL);
        fnMtlRLobe = cell(1,nMTL);
        fnMtlRLobeLR = cell(1,nMTL);
        fnMtlRComm = cell(1,nMTL);
        txtMtlRLobe = cell(1,nMTL);
        txtMtlRLobeLR = cell(1,nMTL);
        txtMtlRComm = cell(1,nMTL);
        for i = 1:nMTL
            nLabelL = shrinkStrByCapLetters(si1.mtlLabL{i});
            nLabelR = shrinkStrByCapLetters(si1.mtlLabR{i});

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_lobe','SZStd_mtlL_lobe','ttest_SZ_mtlL_lobe_CT','ttest_SZ_mtlL_lobe_HV'},dataInd,lobeLabel,i,[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlLLobe{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlLLobe(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelL],colNames,[],[],0.1);

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_lobeLR','SZStd_mtlL_lobeLR','ttest_SZ_mtlL_lobeLR_CT','ttest_SZ_mtlL_lobeLR_HV'},dataInd,lobeLabelLR,i,3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlLLobeLR{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlLLobeLR(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelL],colNames,{'Interpreter','none'},[],0.1);

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_comm','SZStd_mtlL_comm','ttest_SZ_mtlL_comm_CT','ttest_SZ_mtlL_comm_HV'},dataInd,commLabel,i,[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlLComm{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlLComm(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelL],colNames,[],[],0.1);

            fnMtlLLobe{i} = fullfile(outputDir,[nLabelL,'_sptime_lobe',oFileSuffix]);
            fnMtlLLobeLR{i} = fullfile(outputDir,[nLabelL,'_sptime_lobeLR',oFileSuffix]);
            fnMtlLComm{i} = fullfile(outputDir,[nLabelL,'_sptime_comm',oFileSuffix]);

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_lobe','SZStd_mtlR_lobe','ttest_SZ_mtlR_lobe_CT','ttest_SZ_mtlR_lobe_HV'},dataInd,lobeLabel,i,[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlRLobe{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlRLobe(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelR],colNames,[],[],0.1);

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_lobeLR','SZStd_mtlR_lobeLR','ttest_SZ_mtlR_lobeLR_CT','ttest_SZ_mtlR_lobeLR_HV'},dataInd,lobeLabelLR,i,3,[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlRLobeLR{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlRLobeLR(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelR],colNames,{'Interpreter','none'},[],0.1);

            [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_comm','SZStd_mtlR_comm','ttest_SZ_mtlR_comm_CT','ttest_SZ_mtlR_comm_HV'},dataInd,commLabel,i,[],[],[],true,showEffectSizes,effectSzField,CohenThreshold);
            txtMtlRComm{i} = axLabelStr;
            panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
            fhMtlRComm(i) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', nLabelR],colNames,[],[],0.1);

            fnMtlRLobe{i} = fullfile(outputDir,[nLabelR,'_sptime_lobe',oFileSuffix]);
            fnMtlRLobeLR{i} = fullfile(outputDir,[nLabelR,'_sptime_lobeLR',oFileSuffix]);
            fnMtlRComm{i} = fullfile(outputDir,[nLabelR,'_sptime_comm',oFileSuffix]);
        end

        if saveOutputFigures
            saveFigure(fhMtlLLobe,fnMtlLLobe,imgFormat);
            saveFigure(fhMtlLLobeLR,fnMtlLLobeLR,imgFormat);
            saveFigure(fhMtlLComm,fnMtlLComm,imgFormat);
            saveFigure(fhMtlRLobe,fnMtlRLobe,imgFormat);
            saveFigure(fhMtlRLobeLR,fnMtlRLobeLR,imgFormat);
            saveFigure(fhMtlRComm,fnMtlRComm,imgFormat);
        end
        writeTextFiles(appendStr(fnMtlLLobe,'.txt'),txtMtlLLobe,~saveOutputFigures);
        writeTextFiles(appendStr(fnMtlLLobeLR,'.txt'),txtMtlLLobeLR,~saveOutputFigures);
        writeTextFiles(appendStr(fnMtlLComm,'.txt'),txtMtlLComm,~saveOutputFigures);
        writeTextFiles(appendStr(fnMtlRLobe,'.txt'),txtMtlRLobe,~saveOutputFigures);
        writeTextFiles(appendStr(fnMtlRLobeLR,'.txt'),txtMtlRLobeLR,~saveOutputFigures);
        writeTextFiles(appendStr(fnMtlRComm,'.txt'),txtMtlRComm,~saveOutputFigures);

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%     end % if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        plot_individual_MTL_spider(si1,dataInd,lobeLabel,lobeLabelLR,commLabel,outputDir,oFileSuffix,saveOutputFigures,imgFormat,1,effectSzField,CohenThreshold);
        if showEffectSizes == 2
            plot_individual_MTL_spider(si1,dataInd,lobeLabel,lobeLabelLR,commLabel,outputDir,oFileSuffix,saveOutputFigures,imgFormat,2,effectSzField,CohenThreshold);
        end

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end %%%%%%%%%%%%%%%%%%%%%%%%%% if showMTLData
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end

function plot_individual_MTL_spider(si1,dataInd,lobeLabel,lobeLabelLR,commLabel,outputDir,oFileSuffix,saveOutputFigures,imgFormat,showEffectSizes,effectSzField,CohenThreshold)
    nMTL = numel(si1.mtlLabL);

    nLabelL = cellfun(@(x)shrinkStrByCapLetters(x),si1.mtlLabL,'UniformOutput',false);
    nLabelR = cellfun(@(x)shrinkStrByCapLetters(x),si1.mtlLabR,'UniformOutput',false);

    fh = gobjects(1,6);
    fn = cell(1,6);
    txt = cell(1,6);
    
    legendTxtL = ['Controls',nLabelL];
    legendTxtR = ['Controls',nLabelR];
    colorToAdd = [0,0,0];
    if showEffectSizes == 2
        legendTxtL = nLabelL;
        legendTxtR = nLabelR;
        colorToAdd = [];
    end

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_lobe','SZStd_mtlL_lobe','ttest_SZ_mtlL_lobe_CT','ttest_SZ_mtlL_lobe_HV'},dataInd,lobeLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{1} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(1) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabL)],legendTxtL,[],colorToAdd,0.1);
    fn{1} = fullfile(outputDir,['MTL-L_sptime_lobe',oFileSuffix]);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_lobeLR','SZStd_mtlL_lobeLR','ttest_SZ_mtlL_lobeLR_CT','ttest_SZ_mtlL_lobeLR_HV'},dataInd,lobeLabelLR,1:nMTL,3,[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{2} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(2) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabL)],legendTxtL,{'Interpreter','none'},colorToAdd,0.1);
    fn{2} = fullfile(outputDir,['MTL-L_sptime_lobeLR',oFileSuffix]);

    %[P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_comm','SZStd_mtlL_comm','ttest_SZ_mtlL_comm_CT','ttest_SZ_mtlL_comm_HV'},dataInd,commLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlL_comm','ttest_SZ_mtlL_comm_CT','ttest_SZ_mtlL_comm_HV'},dataInd,commLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{3} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(3) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabL)],legendTxtL,[],colorToAdd,0.1);
    fn{3} = fullfile(outputDir,['MTL-L_sptime_comm',oFileSuffix]);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_lobe','SZStd_mtlR_lobe','ttest_SZ_mtlR_lobe_CT','ttest_SZ_mtlR_lobe_HV'},dataInd,lobeLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{4} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(4) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabR)],legendTxtR,[],colorToAdd,0.1);
    fn{4} = fullfile(outputDir,['MTL-R_sptime_lobe',oFileSuffix]);

    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_lobeLR','SZStd_mtlR_lobeLR','ttest_SZ_mtlR_lobeLR_CT','ttest_SZ_mtlR_lobeLR_HV'},dataInd,lobeLabelLR,1:nMTL,3,[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{5} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(5) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabR)],legendTxtR,{'Interpreter','none'},colorToAdd,0.1);
    fn{5} = fullfile(outputDir,['MTL-R_sptime_lobeLR',oFileSuffix]);

    %[P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_comm','SZStd_mtlR_comm','ttest_SZ_mtlR_comm_CT','ttest_SZ_mtlR_comm_HV'},dataInd,commLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    [P,PStd,axLabel,~,axLabelStr,colNames] = prepare_si_spider_data(si1,{'SZ_mtlR_comm','ttest_SZ_mtlR_comm_CT','ttest_SZ_mtlR_comm_HV'},dataInd,commLabel,1:nMTL,[],[],true,true,showEffectSizes,effectSzField,CohenThreshold);
    if showEffectSizes == 2
        P(:,strcmpi(colNames,'Controls')|strcmpi(colNames,'Patients')) = [];
        PStd = [];
    end
    txt{6} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=', thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(6) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,['Sp. Time from ', shrinkStrByCapLetters(si1.mtlLabR)],legendTxtR,[],colorToAdd,0.1);
    fn{6} = fullfile(outputDir,['MTL-R_sptime_comm',oFileSuffix]);

    if saveOutputFigures
        saveFigure(fh,fn,imgFormat);
    end
    writeTextFiles(appendStr(fn,'.txt'),txt,~saveOutputFigures);
end