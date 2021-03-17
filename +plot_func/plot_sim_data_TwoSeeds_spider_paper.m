function plot_sim_data_TwoSeeds_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix,aal)

%     if (nargin < 11) || isempty(isConsensus)
%         isConsensus = false;
%     end

    if (nargin < 4) || isempty(thetaVal)
        thetaVal = [];
    end
    if (nargin < 12) || isempty(oFileSuffix)
        oFileSuffix = '';
    end

    % part of plot_sim_data.m

    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;

%     if isActThresh
%         si1 = resetTheta(si1, 0.03);
%         if ~isempty(si2)
%             si2 = resetTheta(si2, 0.03);
%         end
%     end

    nC = numel(si1.controlData.H_comm{1});
%     commLabel = cellfun(@(x)['Comm ',num2str(x)],num2cell(1:nC),'UniformOutput',false);
    [~,commLabel] = shrinkStrByCapLetters(aal.labels.AAL09comm,1,false);
    [~,lobeLabelLR] = shrinkStrByCapLetters(regexprep(regexprep(lobeLabelLR,'_L$','_Ip'),'_R$','_Co'),1,true);
    
    [~,dataInd,~] = intersect(si1.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si1.theta);
    end

    txt = {};

    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'H_lobe','HStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
    txt{1} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(1) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. entropy per lobe',{'Controls','Patients'},[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cp_lobe','CpStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
    txt{2} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(2) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. competitiveness per lobe ',{'Controls','Patients'},[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cf_lobe','CfStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
    txt{3} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(3) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. conformity per lobe',{'Controls','Patients'},[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'H_lobeLR','HStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
    txt{4} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(4) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. entropy per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cp_lobeLR','CpStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
    txt{5} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(5) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. competitiveness per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cf_lobeLR','CfStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
    txt{6} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(6) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. conformity per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'H_comm','HStd_comm'},dataInd,commLabel,[],[],[],[],true);
    txt{7} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(7) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. entropy per Func Comm',{'Controls','Patients'},[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cp_comm','CpStd_comm'},dataInd,commLabel,[],[],[],[],true);
    txt{8} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(8) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. competitiveness per Func Comm',{'Controls','Patients'},[],[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'Cf_comm','CfStd_comm'},dataInd,commLabel,[],[],[],[],true);
    txt{9} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(9) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. conformity per Func Comm',{'Controls','Patients'},[],[],0.1);
    
    oFileSuffix = ['_N',num2str(si1.N),oFileSuffix];
    fn = { fullfile(outputDir,['entropy_lobe',oFileSuffix]),...
           fullfile(outputDir,['nodecomp_lobe',oFileSuffix]),...
           fullfile(outputDir,['nodeconf_lobe',oFileSuffix]),...
           fullfile(outputDir,['entropy_lobeLR',oFileSuffix]),...
           fullfile(outputDir,['nodecomp_lobeLR',oFileSuffix]),...
           fullfile(outputDir,['nodeconf_lobeLR',oFileSuffix]),...
           fullfile(outputDir,['entropy_comm',oFileSuffix]),...
           fullfile(outputDir,['nodecomp_comm',oFileSuffix]),...
           fullfile(outputDir,['nodeconf_comm',oFileSuffix]) };
    if saveOutputFigures
        saveFigure(fh,fn,imgFormat);
    end
    writeTextFiles(appendStr(fn,'.txt'),txt,~saveOutputFigures);
end