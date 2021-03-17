function plot_sim_data_SpeedUp_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,~,~,saveOutputFigures,outputDir,imgFormat,~,~,oFileSuffix,aal)

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

    nC = numel(si1.controlData.global_comm{1});
%     commLabel = cellfun(@(x)['Comm ',num2str(x)],num2cell(1:nC),'UniformOutput',false);
    [~,commLabel] = shrinkStrByCapLetters(aal.labels.AAL09comm,1,false);
    [~,lobeLabelLR] = shrinkStrByCapLetters(regexprep(regexprep(lobeLabelLR,'_L$','_Ip'),'_R$','_Co'),1,true);
    
    [~,dataInd,~] = intersect(si1.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si1.theta);
    end

    txt = {};
    txtloc = {};

    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'global_lobe','globalStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
    txt{1} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(1) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. global sp. up per lobe',{'Controls','Patients'},[],[],0.1);

    if ~isempty(si1.controlData.local_lobe{1})
        [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'local_lobe','localStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
        txtloc{1} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fhloc(1) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per lobe ',{'Controls','Patients'},[],[],0.1);
    end
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'localnet_lobe','localnetStd_lobe'},dataInd,lobeLabel,[],[],[],[],true);
    txt{2} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(2) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per lobe',{'Controls','Patients'},[],[],0.1);

    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'global_lobeLR','globalStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
    txt{3} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(3) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. global sp. up per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);

    if ~isempty(si1.controlData.local_lobeLR{1})
        [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'local_lobeLR','localStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
        txtloc{2} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fhloc(2) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);
    end
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'localnet_lobeLR','localnetStd_lobeLR'},dataInd,lobeLabelLR,[],3,[],[],true);
    txt{4} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(4) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per lobe',{'Controls','Patients'},{'Interpreter','none'},[],0.1);
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'global_comm','globalStd_comm'},dataInd,commLabel,[],[],[],[],true);
    txt{5} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(5) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. global sp. up per Func Comm',{'Controls','Patients'},[],[],0.1);
    
    if ~isempty(si1.controlData.local_comm{1})
        [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'local_comm','localStd_comm'},dataInd,commLabel,[],[],[],[],true);
        txtloc{3} = axLabelStr;
        panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
        fhloc(3) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per Func Comm',{'Controls','Patients'},[],[],0.1);
    end
    
    [P,PStd,axLabel,~,axLabelStr] = prepare_si_spider_data(si1,{'localnet_comm','localnetStd_comm'},dataInd,commLabel,[],[],[],[],true);
    txt{6} = axLabelStr;
    panelLabels = cellfun(@(x)['\theta=',thetaValToTxt(x)],num2cell(si1.theta(dataInd)),'UniformOutput',false);
    fh(6) = plot_si_spider([],[],P,PStd,axLabel,panelLabels,'Avg. local sp. up per Func Comm',{'Controls','Patients'},[],[],0.1);
    
    oFileSuffix = ['_N',num2str(si1.N),oFileSuffix];
    fn = { fullfile(outputDir,['global_lobe',oFileSuffix]),...
           fullfile(outputDir,['localnet_lobe',oFileSuffix]),...
           fullfile(outputDir,['global_lobeLR',oFileSuffix]),...
           fullfile(outputDir,['localnet_lobeLR',oFileSuffix]),...
           fullfile(outputDir,['global_comm',oFileSuffix]),...
           fullfile(outputDir,['localnet_comm',oFileSuffix]) };
	fnloc = { fullfile(outputDir,['local_lobe',oFileSuffix]),...
              fullfile(outputDir,['local_lobeLR',oFileSuffix]),...
              fullfile(outputDir,['local_comm',oFileSuffix]) };
    if saveOutputFigures
        saveFigure(fh,fn,imgFormat);
        if ~isempty(si1.controlData.local_lobe{1})
            saveFigure(fhloc,fnloc,imgFormat);
        end
    end
    writeTextFiles(appendStr(fn,'.txt'),txt,~saveOutputFigures);
    if ~isempty(si1.controlData.local_lobe{1})
        writeTextFiles(appendStr(fnloc,'.txt'),txtloc,~saveOutputFigures);
    end
end