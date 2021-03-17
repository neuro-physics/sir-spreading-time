function plot_sim_data_SpeedUp_Group(aal,si,speedUpLabel,thetaVal,legTitle,sort_n90,highlightPtrn_n90,saveOutputFigures,outputDir,imgFormat,oFileSuffix,useFDR,N,nodeLabels,showCommData,sortNodesBy,showDataColor)

    if (nargin < 11) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    if (nargin < 12) || isempty(useFDR)
        useFDR = false;
    end
    if (nargin < 13) || isempty(N)
        N = 90;
    end
    if (nargin < 14) || isempty(nodeLabels)
        nodeLabels = [];
    end
    if (nargin < 15) || isempty(showCommData)
        showCommData = false;
    end
    if (nargin < 17) || isempty(showDataColor)
        showDataColor = true;
    end
    
    if useFDR
        hField = 'hFDR';
    else
        hField = 'h';
    end
    
    if N == 90
        aLab = 'AAL90';
    else
        aLab = 'AAL306';
    end
    
    [~,dataInd,~] = intersect(si.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si.theta);
    end
    
%     tTestColorArr = [165,6,6;... % dark red
%                      255,73,73;... % light red
%                      255,255,255;... % white
%                      0,200,255;... % light blue
%                      6,70,165]./255; % dark blue
    
    if showDataColor
        cMap_plus = flipud(autumn(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_c) - Z(S_p)
        cMap_minus = winter(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_c) - Z(S_p)
%         tTestColorProp = { 'ColorArr', [1,1,1;jet(N)], 'ShowDataColor', 'on' };
    else
        tTestColorArr = [132,17,17;... % dark red
                         255,107,107;... % light red
                         255,255,255;... % white
                         98,195,255;... % light blue
                         21,46,135]./255; % dark blue
        tTestColorArr = flipud(tTestColorArr);
        cMap_plus = tTestColorArr(4:5,:);
        cMap_minus = tTestColorArr(1:2,:);
%         tTestColorProp = { 'ColorArr', tTestColorArr, 'ColorLim1', [-2,2] };
    end

    suStructLab = speedUpLabel;
%     suStructLab_Z = [speedUpLabel,'_Z'];

%     colorLabel_Z = ['$Z(U_p^{(',speedUpLabel(1),')})-Z(U_c^{(',speedUpLabel(1),')})$'];
%     colorLabel = ['$U_p^{(',speedUpLabel(1),')}-U_c^{(',speedUpLabel(1),')}$'];

    %%% z-score of the speed ups visualized with matrix and edges
    %%% RTLE and LTLE
%     axLabel = cellfun(@(x)[legTitle,'; $\theta=',num2str(x),'$'],num2cell(si.theta),'UniformOutput',false);
    [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],true,...
        si.controlData.(suStructLab)(dataInd),...
        si.patientData.(suStructLab)(dataInd),...
        {si.ttest.(suStructLab)(dataInd).(hField)},...
        cMap_plus,cMap_minus,true,'','Greater in','matrix',sort_n90,highlightPtrn_n90,...%%cMap_autumn,cMap_winter,true,'','Greater in','matrix',sort_n90,highlightPtrn_n90,...
        'file',aal.labels.(aLab),['speedup_zscore_',speedUpLabel,oFileSuffix,'_edge_labels.txt'],...
        {si.ttest.(suStructLab)(dataInd).h},true);%false
    if ~showDataColor
        changeCBarToTxtLabel(cb1,'Controls');changeCBarToTxtLabel(cb2,'Patients');
    end
    if saveOutputFigures
        saveFigure(fh,fullfile(outputDir,['speedup_zscore_',speedUpLabel,oFileSuffix,'_matrix']),imgFormat);
        movefile(labFile,outputDir);
    end

    if ~showCommData
%         axLabel = cellfun(@(x)[legTitle,'; $\theta=',num2str(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            si.controlData.(suStructLab)(dataInd),...
            si.patientData.(suStructLab)(dataInd),...
            {si.ttest.(suStructLab)(dataInd).(hField)},...
            cMap_plus,cMap_minus,true,'','Greater in','brain',...%cMap_autumn,cMap_winter,true,'','Greater in','brain',...
            [],'',[],[],[],...
            {si.ttest.(suStructLab)(dataInd).h},true);%false
        if ~showDataColor
            changeCBarToTxtLabel(cb1,'Controls');changeCBarToTxtLabel(cb2,'Patients');
        end
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['speedup_zscore_',speedUpLabel,oFileSuffix,'_brain']),imgFormat);
        end
%         axLabel = cellfun(@(x)[legTitle,'; $\theta=',num2str(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            si.controlData.(suStructLab)(dataInd),...
            si.patientData.(suStructLab)(dataInd),...
            {si.ttest.(suStructLab)(dataInd).(hField)},...
            cMap_plus,cMap_minus,true,'','Greater in','brain',[],'sagital',...%cMap_autumn,cMap_winter,true,'','Greater in','brain',[],'sagital',...
            [],[],[],...
            {si.ttest.(suStructLab)(dataInd).h},true);%false
        if ~showDataColor
            changeCBarToTxtLabel(cb1,'Controls');changeCBarToTxtLabel(cb2,'Patients');
        end
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['speedup_zscore_',speedUpLabel,oFileSuffix,'_brain_sagital']),imgFormat);
        end
    end
    
end