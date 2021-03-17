function plot_sim_data_SpMatrix_02_Group(aal,si,thetaVal,legTitle,sortInd,highlightPtrn,saveOutputFigures,outputDir,imgFormat,oFileSuffix,useFDR,N,nodeLabels,showCommData,sortNodesBy,showDataColor,showMTLData,showZScoreEdges)
    if (nargin < 10) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    if (nargin < 11) || isempty(useFDR)
        useFDR = false;
    end
    if (nargin < 12) || isempty(N)
        N = 90;
    end
    if (nargin < 13) || isempty(nodeLabels)
        nodeLabels = [];
    end
    if (nargin < 14) || isempty(showCommData)
        showCommData = false;
    end
    if (nargin < 16) || isempty(showDataColor)
        showDataColor = true;
    end
    if (nargin < 17) || isempty(showMTLData)
        showMTLData = true; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end
    if (nargin < 18) || isempty(showZScoreEdges)
        showZScoreEdges = true; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end

%     tTestColorArr = [165,6,6;... % dark red
%                      255,73,73;... % light red
%                      255,255,255;... % white
%                      0,200,255;... % light blue
%                      6,70,165]./255; % dark blue
    if showDataColor
%         cMap_autumn = flipud(autumn(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_c) - Z(S_p)
%         cMap_winter = winter(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_c) - Z(S_p)
        cMap_minus = autumn(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_p) - Z(S_c)
        cMap_plus = flipud(winter(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_p) - Z(S_c)
        tTestColorProp = { 'ColorArr', [1,1,1;jet(N)], 'ShowDataColor', 'on' };
    else
        tTestColorArr = [132,17,17;... % dark red
                         255,107,107;... % light red
                         255,255,255;... % white
                         98,195,255;... % light blue
                         21,46,135]./255; % dark blue
        cMap_plus = tTestColorArr(4:5,:);
        cMap_minus = tTestColorArr(1:2,:);
        tTestColorProp = { 'ColorArr', tTestColorArr, 'ColorLim1', [-2,2] };
    end
%     tTestColorArr = flipud(tTestColorArr); % dark blue, blue, white, red, dark red

    [~,dataInd,~] = intersect(si.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si.theta);
    end

%     cMap_autumn = flipud(autumn(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_c) - Z(S_p)
%     cMap_winter = winter(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_c) - Z(S_p)
%     cMap_autumn = autumn(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_p) - Z(S_c)
%     cMap_winter = flipud(winter(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_p) - Z(S_c)
    cMap_jetDesat = rgb2hsv(jet);cMap_jetDesat(:,2) = cMap_jetDesat(:,2) .* linspace(0.4,0.9,size(cMap_jetDesat,1))';cMap_jetDesat = hsv2rgb(cMap_jetDesat);

    close all

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

    NN = si.N;
    nTheta = numel(si.theta);
    zeroCell = cellfun(@(x)zeros(NN),cell(1,nTheta),'UniformOutput',false);
    hMatAllOnes = cellfun(@(x)ones(NN),cell(1,nTheta),'UniformOutput',false);

% if false
    panelTitle = 'Avg. In Sp. Time $\langle S_n^{(in)}\rangle_p-\langle S_n^{(in)}\rangle_c$';
    [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'SStdR_node','SAvgR_node'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', ['sptime_receive_node',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
    end
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['sptime_receive_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end

    panelTitle = 'Avg. Out Sp. Time $\langle S_n^{(out)}\rangle_p-\langle S_n^{(out)}\rangle_c$';
    [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'SStdS_node','SAvgS_node'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', ['sptime_send_node',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
    end
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['sptime_send_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end

    panelTitle = 'Avg. Sp. Time $\langle S_n\rangle_p-\langle S_n\rangle_c$';
    [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'SStdRS_node','SAvgRS_node'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', ['sptime_io_node',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
    end
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['sptime_io_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end

    panelTitle = 'Hamm. Dist. $\langle D(S_n,P_n)\rangle_p-\langle D(S_n,P_n)\rangle_c$';
    [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'DStd_node','D_node'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', ['hammD_node',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
    end
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['hammD_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end

    if ~showCommData
        panelTitle = 'Isolation, $I$';
        [fh,~,labFile,theta,~,~,~] = plotSpMatrixSurface(si, 'I', legTitle, panelTitle, hot, 'file', 'isolation_node_labels.txt', useFDR,[],[],[],sortNodesBy);
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, ['isolation_node',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end
    end

    panelTitle = 'Prob. sp. time diff. $\mathcal{P}(n)$';
    [fh,~,labFile,theta,~,~,~] = plotSpMatrixSurface(si, 'Pdiff_node', legTitle, panelTitle, hot, 'file', 'pdiff_node_labels.txt', useFDR,[],[],[],sortNodesBy);
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['pdiff_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        moveManyFiles(labFile, outputDir);
    end


    if ~showCommData
        if ~isempty(nodeLabels)
            if ~iscell(nodeLabels)
                nodeLabels = { nodeLabels };
            end
            for i = 1:numel(nodeLabels)
                panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
                [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStd','SZ'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [nodeLabels{i},'_sptZ_ttest',oFileSuffix,'_label.txt'], useFDR, nodeLabels{i}, 'ttest',[],sortNodesBy);
                if ~showDataColor
                    changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
                end
                if saveOutputFigures
                    fn = getFigureFileNames(outputDir, [nodeLabels{i},'_sptZ_ttest',oFileSuffix,'_theta'], theta);
                    saveFigure(fh, fn, imgFormat);
                    moveManyFiles(labFile, outputDir);
                end
            end
        end
    end
% end %if false

% if false
    if showMTLData && (~showCommData)
        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStdRS_mtlL','SZRS_mtlL'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR, si.mtlLabL, 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabL),'_spt_io_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end

        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStdRS_mtlR','SZRS_mtlR'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR, si.mtlLabR, 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabR),'_spt_io_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end

        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStd_mtlL','SZ_mtlL'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR, si.mtlLabL, 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end

        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStd_mtlR','SZ_mtlR'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR, si.mtlLabR, 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end

        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStd_mtlL_all','SZ_mtlL_all'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_MTL-L_all_spt_ttest',oFileSuffix,'_label.txt'], useFDR, '', 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabL),'_MTL-L_all_spt_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end

        panelTitle = 'Sp. Time $Z(S_p)-Z(S_c)$';
        [fh,~,labFile,theta,~,cb1,~] = plotSpMatrixSurface(si, {'SZStd_mtlR_all','SZ_mtlR_all'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_MTL-R_all_spt_ttest',oFileSuffix,'_label.txt'], useFDR, '', 'ttest', true, sortNodesBy);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        end
        if saveOutputFigures
            fn = getFigureFileNames(outputDir, [shrinkStrByCapLetters(si.mtlLabR),'_MTL-R_all_spt_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, outputDir);
        end
    end

    if showZScoreEdges
        %%% z-score of the spreading times visualized with matrix and edges
        %%% R + L TLE
        colorLabel = '$Z(S_p)-Z(S_c)$';
        axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],true,...
            si.controlData.SZ(dataInd),...
            si.patientData.SZ(dataInd),...
            {si.ttest.SZ(dataInd).(hField)},...
            cMap_plus,cMap_minus,true,'','Faster in','matrix',sortInd,highlightPtrn,...%cMap_winter,cMap_autumn,true,'','Faster in','matrix',sortInd,highlightPtrn,...
            'file',aal.labels.(aLab),['sptime_zscore_edge_labels',oFileSuffix,'.txt'],...
            {si.ttest.SZ(dataInd).h},true);
        if ~showDataColor
            changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
        end
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['sptime_zscore_matrix',oFileSuffix]),imgFormat);
            moveManyFiles(labFile,outputDir);
        end

        if ~showCommData
            axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
            [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
                si.controlData.SZ(dataInd),...
                si.patientData.SZ(dataInd),...
                {si.ttest.SZ(dataInd).(hField)},...
                cMap_plus,cMap_minus,true,'','Faster in','brain',...%cMap_winter,cMap_autumn,true,'','Faster in','brain',...
                [],'',[],[],[],...
                {si.ttest.SZ(dataInd).h},true);%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
            if ~showDataColor
                changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
            end
    %         return;
            if saveOutputFigures
                saveFigure(fh,fullfile(outputDir,['sptime_zscore_brain',oFileSuffix]),imgFormat);
            end
            [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
                si.controlData.SZ(dataInd),...
                si.patientData.SZ(dataInd),...
                {si.ttest.SZ(dataInd).(hField)},...
                cMap_plus,cMap_minus,true,'','Faster in','brain',[],'sagital',...%cMap_winter,cMap_autumn,true,'','Faster in','brain',[],'sagital',...
                [],[],[],...
                {si.ttest.SZ(dataInd).h},true);%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
            if ~showDataColor
                changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
            end
            if saveOutputFigures
                saveFigure(fh,fullfile(outputDir,['sptime_zscore_brain_sagital',oFileSuffix]),imgFormat);
            end
        end

    end
    
    
    return; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


    colorLabel = '$\Delta S_p(k)-\Delta S_c(k)$';
    hMatAllOnesDeltaS = cellfun(@(x,y)(x~=0)|(y~=0),si.controlData.SPdiff_edge,si.patientData.SPdiff_edge,'UniformOutput',false);
    axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
    [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],true,...
        si.controlData.SPdiff_edge(dataInd),...
        si.patientData.SPdiff_edge(dataInd),...
        hMatAllOnes(dataInd),...
        cMap_winter,cMap_autumn,true,'','Faster in','matrix',sortInd,highlightPtrn,...%%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'matrix',sortInd,highlightPtrn,...
        'file',aal.labels.(aLab),['spdiff_zscore_edge_labels',oFileSuffix,'.txt']);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
    end
    if saveOutputFigures
        saveFigure(fh,fullfile(outputDir,['spdiff_matrix',oFileSuffix]),imgFormat);
        moveManyFiles(labFile,outputDir);
    end
    
% if false
    if ~showCommData
        axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            si.controlData.SPdiff_edge(dataInd),...
            si.patientData.SPdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_winter,cMap_autumn,true,'','Faster in','brain');%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
        if ~showDataColor
            changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
        end
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['spdiff_brain',oFileSuffix]),imgFormat);
        end
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            si.controlData.SPdiff_edge(dataInd),...
            si.patientData.SPdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_winter,cMap_autumn,true,'','Faster in','brain',[],'sagital');%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
        if ~showDataColor
            changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
        end
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['spdiff_brain_sagital',oFileSuffix]),imgFormat);
        end
    end
% end % if false
    % desaturate blue tones from jet colormap

    colorLabel = '$\mathcal{P}(k_c)$';
    axLabel = cellfun(@(x)[legTitle,'; Controls $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
    [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],false,...
        zeroCell(dataInd),...
        si.controlData.Pdiff_edge(dataInd),...
        hMatAllOnes(dataInd),...
        cMap_jetDesat,[],true,'',colorLabel,'matrix',sortInd,highlightPtrn,...
        'file',aal.labels.(aLab),['pdiff_control_edge_labels',oFileSuffix,'.txt']);
    delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
    if saveOutputFigures
        saveFigure(fh,fullfile(outputDir,['pdiff_control_matrix',oFileSuffix]),imgFormat);
        moveManyFiles(labFile,outputDir);
    end

% if false
    if ~showCommData
        axLabel = cellfun(@(x)[legTitle,'; Controls $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            zeroCell(dataInd),...
            si.controlData.Pdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_jetDesat,[],true,'',colorLabel,'brain');
        delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['pdiff_control_brain',oFileSuffix]),imgFormat);
        end
        axLabel = cellfun(@(x)[legTitle,'; Controls $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            zeroCell(dataInd),...
            si.controlData.Pdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_jetDesat,[],true,'',colorLabel,'brain',[],'sagital');
        delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['pdiff_control_brain_sagital',oFileSuffix]),imgFormat);
        end
    end
% end % if false
    colorLabel = '$\mathcal{P}(k_p)$';
    axLabel = cellfun(@(x)[legTitle,'; Patients $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
    [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],false,...
        zeroCell(dataInd),...
        si.patientData.Pdiff_edge(dataInd),...
        hMatAllOnes(dataInd),...
        cMap_jetDesat,[],true,'',colorLabel,'matrix',sortInd,highlightPtrn,...
        'file',aal.labels.(aLab),['pdiff_patient_edge_labels',oFileSuffix,'.txt']);
    delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
    if saveOutputFigures
        saveFigure(fh,fullfile(outputDir,['pdiff_patient_matrix',oFileSuffix]),imgFormat);
        moveManyFiles(labFile,outputDir);
    end
% if false
    if ~showCommData
        axLabel = cellfun(@(x)[legTitle,'; Patients $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            zeroCell(dataInd),...
            si.patientData.Pdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_jetDesat,[],true,'',colorLabel,'brain');
        delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['pdiff_patient_brain',oFileSuffix]),imgFormat);
        end
        [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
            zeroCell(dataInd),...
            si.patientData.Pdiff_edge(dataInd),...
            hMatAllOnes(dataInd),...
            cMap_jetDesat,[],true,'',colorLabel,'brain',[],'sagital');
        delete(cb1);stretchAndDisplaceObj(cb2,[-cb2(1).Position(3),0,cb2(1).Position(3),0]);
        if saveOutputFigures
            saveFigure(fh,fullfile(outputDir,['pdiff_patient_brain_sagital',oFileSuffix]),imgFormat);
        end
    end
% end % if false
end