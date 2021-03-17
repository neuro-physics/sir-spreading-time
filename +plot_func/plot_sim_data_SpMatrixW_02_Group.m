function plot_sim_data_SpMatrixW_02_Group(aal,si,thetaVal,legTitle,sortInd,highlightPtrn,saveOutputFigures,outputDir,imgFormat,oFileSuffix,useFDR_CohenThreshold,N,nodeLabels,showCommData,sortNodesBy,showDataColor,tTestBiasControl,showMTLData,showZScoreEdges,tThresh,effSizeLabel)
    if (nargin < 10) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    if (nargin < 11) || isempty(useFDR_CohenThreshold)
        useFDR_CohenThreshold = false;
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
    if (nargin < 17) || isempty(tTestBiasControl)
        tTestBiasControl = 'none'; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end
    if (nargin < 18) || isempty(showMTLData)
        showMTLData = true; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end
    if (nargin < 19) || isempty(showZScoreEdges)
        showZScoreEdges = true; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end
    if (nargin < 20) || isempty(tThresh)
        tThresh = 0; % 'none' -> std t-test; 'CT' -> t-test controlling for CT; 'HV' -> t-test controlling for HV
    end
    if (nargin < 21) || isempty(effSizeLabel)
        effSizeLabel = 'effsz'; % or 'Cohen_Mahal'
    end

    tbc = tTestBiasControl;

%     tTestColorArr = [165,6,6;... % dark red
%                      255,73,73;... % light red
%                      255,255,255;... % white
%                      0,200,255;... % light blue
%                      6,70,165]./255; % dark blue

% 	tTestColorArr = flipud(tTestColorArr);

    if showDataColor
%         cMap_autumn = flipud(autumn(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_c) - Z(S_p)
%         cMap_winter = winter(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_c) - Z(S_p)
        cMap_minus = autumn(size(get(groot,'DefaultFigureColormap'),1)); % good for Z(S_p) - Z(S_c)
        cMap_plus = flipud(winter(size(get(groot,'DefaultFigureColormap'),1))); % good for Z(S_p) - Z(S_c)
        if tThresh > 0
            tTestColorProp = { 'ColorArr', [0.3,0.3,0.3;1,1,1;jet(N)], 'ShowDataColor', showDataColor, 'ColorMode', 'discrete' };
        else
            tTestColorProp = { 'ColorArr', [1,1,1;jet(N)], 'ShowDataColor', showDataColor, 'ColorMode', 'continuous' };
        end
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
    
    [~,commLabels] = shrinkStrByCapLetters(aal.labels.AAL09comm,1);

%     aalLabel = ['AAL',num2str(N)];
%     cMap_jetDesat = rgb2hsv(jet);cMap_jetDesat(:,2) = cMap_jetDesat(:,2) .* linspace(0.4,0.9,size(cMap_jetDesat,1))';cMap_jetDesat = hsv2rgb(cMap_jetDesat);

    close all

    if useFDR_CohenThreshold
        hField = 'hFDR';
    else
        hField = 'h';
    end
    
    if N == 90
        aLab = 'AAL90';
    else
        aLab = 'AAL306';
    end
    
    newOutputDir = outputDir;
    if strcmpi(tbc,'CT') || strcmpi(tbc,'HV')
        newOutputDir = [fullfile(outputDir,tbc),filesep];
        if exist(newOutputDir,'dir') ~= 7
            mkdir(newOutputDir);
        end
        legTitle = [legTitle,' - ',tbc];
    end

    tTestColorProp1 = tTestColorProp;
    if showDataColor
        cLim = minmax([cell2LinVec(getFieldsContents(si.controlData,{'SAvgR_node','SAvgS_node','SAvgRS_node'},dataInd)),cell2LinVec(getFieldsContents(si.patientData,{'SAvgR_node','SAvgS_node','SAvgRS_node'},dataInd))]);
        cLimTrends_max = max(abs(cell2LinVec(getFieldsContents(si.ttest,...
                                 {'SAvgR_node','SAvgR_CT_node','SAvgR_HV_node','SAvgS_node','SAvgS_CT_node','SAvgS_HV_node'},...
                                 dataInd,'t',{'hFDR','h'},'($h$>0) & ($hFDR$==0)'))));
        cLimTrends_min = min(abs(cell2LinVec(getFieldsContents(si.ttest,...
                                 {'SAvgR_node','SAvgR_CT_node','SAvgR_HV_node','SAvgS_node','SAvgS_CT_node','SAvgS_HV_node'},...
                                 dataInd,'t',{'hFDR','h'},'($h$>0) & ($hFDR$==0)'))));
        cLimTrends = getCLim0(cLimTrends_max,cLimTrends_min);
        cLimEffSz_max = max(cell2LinVec(getFieldsContents(si.ttest,...
                                 {'SAvgR_node','SAvgR_CT_node','SAvgR_HV_node','SAvgS_node','SAvgS_CT_node','SAvgS_HV_node'},...
                                 dataInd,effSizeLabel,{'hFDR','h'},'($h$>0) & ($hFDR$>0)')));
        cLimEffSz_min = min(cell2LinVec(getFieldsContents(si.ttest,...
                                 {'SAvgR_node','SAvgR_CT_node','SAvgR_HV_node','SAvgS_node','SAvgS_CT_node','SAvgS_HV_node'},...
                                 dataInd,effSizeLabel,{'hFDR','h'},'($h$>0) & ($hFDR$>0)')));
        cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);
        tTestColorProp1 = [tTestColorProp,'ColorLim1',cLim,'ColorLimT',cLimTrends,'ColorLimEf',cLimEffSz];
    end
    
    nodeLabelsXAxis = {};
    if showCommData
        nodeLabelsXAxis = commLabels;
    end

    panelTitle = 'Spreading Time (Z-Score W.r.t. Controls)';
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %panelTitle = 'Avg. In Sp. Time $\langle S_n^{(in)}\rangle_p-\langle S_n^{(in)}\rangle_c$';

    %panelTitle = 'Avg. In Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
    [fh,~,labFile,theta,fhFDR,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SStdR_node','SAvgR_node'},getTTestLabel(tbc,'SAvgR_node')], dataInd, legTitle, panelTitle, tTestColorProp1, 'file', ['sptime_receive_node',oFileSuffix,'_label.txt'], useFDR_CohenThreshold,[],[],[],sortNodesBy,nodeLabelsXAxis,tThresh);
    if ~showTrends
        if numel(cb1.Ticks) < 7
            cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
            cb1.Ticks = cValues;
            cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
        end
%         if showDataColor && islogical(showDataColor)
        cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
        cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%         end
        drawnow
    end
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        drawnow
    end
    if saveOutputFigures
        fn = getFigureFileNames(newOutputDir, ['sptime_receive_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, newOutputDir);
    end

%     panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
    [fh,~,labFile,theta,fhFDR,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SStdS_node','SAvgS_node'},getTTestLabel(tbc,'SAvgS_node')], dataInd, legTitle, panelTitle, tTestColorProp1, 'file', ['sptime_send_node',oFileSuffix,'_label.txt'], useFDR_CohenThreshold,[],[],[],sortNodesBy,nodeLabelsXAxis,tThresh);
    if ~showTrends
        if numel(cb1.Ticks) < 7
            cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
            cb1.Ticks = cValues;
            cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
        end
%         if showDataColor && islogical(showDataColor)
        cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
        cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%         end
        drawnow
    end
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        drawnow
    end
    if saveOutputFigures
        fn = getFigureFileNames(newOutputDir, ['sptime_send_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, newOutputDir);
    end

%     panelTitle = 'Avg. Sp. In/Out Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
    [fh,~,labFile,theta,fhFDR,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SStdRS_node','SAvgRS_node'},getTTestLabel(tbc,'SAvgRS_node')], dataInd, legTitle, panelTitle, tTestColorProp1, 'file', ['sptime_io_node',oFileSuffix,'_label.txt'], useFDR_CohenThreshold,[],[],[],sortNodesBy,nodeLabelsXAxis,tThresh);
    if ~showTrends
        if numel(cb1.Ticks) < 7
            cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
            cb1.Ticks = cValues;
            cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
        end
%         if showDataColor && islogical(showDataColor)
        cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
        cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%         end
        drawnow
    end
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
        drawnow
    end
    if saveOutputFigures
        fn = getFigureFileNames(newOutputDir, ['sptime_io_node',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, newOutputDir);
    end

    if false % dont need individual MTL nodes
    if strcmpi(tbc,'none')
        if ~showCommData
            if ~isempty(nodeLabels)
                if ~iscell(nodeLabels)
                    nodeLabels = { nodeLabels };
                end
                for i = 1:numel(nodeLabels)
%                     panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
                    [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, {'SZStd','SZ'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [nodeLabels{i},'_sptZ_ttest',oFileSuffix,'_label.txt'], useFDR, nodeLabels{i}, 'ttest',[],sortNodesBy,nodeLabelsXAxis,tThresh);
                    if ~showTrends
                        if numel(cb1.Ticks) < 7
                            cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                            cb1.Ticks = cValues;
                            cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
                        end
                        if showDataColor && islogical(showDataColor)
                            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
                            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
                        end
                        drawnow
                    end
                    if ~showDataColor
                        changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
                        drawnow
                    end
                    if saveOutputFigures
                        fn = getFigureFileNames(newOutputDir, [nodeLabels{i},'_sptZ_ttest',oFileSuffix,'_theta'], theta);
                        saveFigure(fh, fn, imgFormat);
                        moveManyFiles(labFile, newOutputDir);
                    end
                end
            end
        end
    end
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if showMTLData %&& (~showCommData)
        tTestColorPropL = tTestColorProp1;
        tTestColorPropR = tTestColorProp1;
%         tTestColorPropL = tTestColorProp;
%         tTestColorPropR = tTestColorProp;
%         if showDataColor
%             cLim = minmax([cell2LinVec(getFieldsContents(si.controlData,{'SZR_mtlL','SZS_mtlL','SZRS_mtlL'},dataInd)),cell2LinVec(getFieldsContents(si.patientData,{'SZR_mtlL','SZS_mtlL','SZRS_mtlL'},dataInd))]);
%             tTestColorPropL = [tTestColorProp,'ColorLim1',cLim];
%             cLim = minmax([cell2LinVec(getFieldsContents(si.controlData,{'SZR_mtlR','SZS_mtlR','SZRS_mtlR'},dataInd)),cell2LinVec(getFieldsContents(si.patientData,{'SZR_mtlR','SZS_mtlR','SZRS_mtlR'},dataInd))]);
%             tTestColorPropR = [tTestColorProp,'ColorLim1',cLim];
%         end

%         panelTitle = 'Avg. In/Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdRS_mtlL','SZRS_mtlL'},getTTestLabel(tbc,'SZRS_mtlL')], dataInd, legTitle, panelTitle, tTestColorPropL, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabL, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabL),'_spt_io_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end

%         panelTitle = 'Avg. In/Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdRS_mtlR','SZRS_mtlR'},getTTestLabel(tbc,'SZRS_mtlR')], dataInd, legTitle, panelTitle, tTestColorPropR, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabR, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabR),'_spt_io_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
%         panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdS_mtlL','SZS_mtlL'},getTTestLabel(tbc,'SZS_mtlL')], dataInd, legTitle, panelTitle, tTestColorPropL, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabL, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabL),'_spt_out_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end

%         panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdS_mtlR','SZS_mtlR'},getTTestLabel(tbc,'SZS_mtlR')], dataInd, legTitle, panelTitle, tTestColorPropR, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabR, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabR),'_spt_out_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end
        
%         panelTitle = 'Avg. In Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdR_mtlL','SZR_mtlL'},getTTestLabel(tbc,'SZR_mtlL')], dataInd, legTitle, panelTitle, tTestColorPropL, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabL, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabL),'_spt_in_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end

%         panelTitle = 'Avg. In Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
        [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, [{'SZStdR_mtlR','SZR_mtlR'},getTTestLabel(tbc,'SZR_mtlR')], dataInd, legTitle, panelTitle, tTestColorPropR, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, si.mtlLabR, 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
        if ~showTrends
            if numel(cb1.Ticks) < 7
                cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                cb1.Ticks = cValues;
                cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
%             if showDataColor && islogical(showDataColor)
            cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
            cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%             end
            drawnow
        end
        if ~showDataColor
            changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
            drawnow
        end
        if saveOutputFigures
            fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabR),'_spt_in_ttest',oFileSuffix,'_theta'], theta);
            saveFigure(fh, fn, imgFormat);
            moveManyFiles(labFile, newOutputDir);
        end

        if strcmpi(tbc,'none')
%             panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
            [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, {'SZStd_mtlL_all','SZ_mtlL_all'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabL),'_MTL-L_all_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, '', 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
            if ~showTrends
                if numel(cb1.Ticks) < 7
                    cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                    cb1.Ticks = cValues;
                    cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
                end
%                 if showDataColor && islogical(showDataColor)
                cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
                cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%                 end
                drawnow
            end
            if ~showDataColor
                changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
                drawnow
            end
            if saveOutputFigures
                fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabL),'_MTL-L_all_spt_ttest',oFileSuffix,'_theta'], theta);
                saveFigure(fh, fn, imgFormat);
                moveManyFiles(labFile, newOutputDir);
            end

%             panelTitle = 'Avg. Out Sp. Time'; if showDataColor, panelTitle = [ panelTitle, '(Z-scores; FDR corrected)' ]; end
            [fh,~,labFile,theta,~,cb1,~,showTrends] = plotSpMatrixSurface(si, {'SZStd_mtlR_all','SZ_mtlR_all'}, dataInd, legTitle, panelTitle, tTestColorProp, 'file', [shrinkStrByCapLetters(si.mtlLabR),'_MTL-R_all_spt_ttest',oFileSuffix,'_label.txt'], useFDR_CohenThreshold, '', 'ttest', true, sortNodesBy,nodeLabelsXAxis,tThresh);
            if ~showTrends
                if numel(cb1.Ticks) < 7
                    cValues = linspace(cb1.Limits(1),cb1.Limits(2),7);
                    cb1.Ticks = cValues;
                    cb1.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
                end
%                 if showDataColor && islogical(showDataColor)
                cb1.TickLabels{1} = 'same as controls'; cb1.TickLabels{2} = '';
                cb1.TickLabels{end} = 'slower in TLE'; cb1.TickLabels{end-1} = '';
%                 end
                drawnow
            end
            if ~showDataColor
                changeCBarToTxtLabel(cb1,{'Patients','Controls'});setColorBarTitle(cb1,'Faster in');
                drawnow
            end
            if saveOutputFigures
                fn = getFigureFileNames(newOutputDir, [shrinkStrByCapLetters(si.mtlLabR),'_MTL-R_all_spt_ttest',oFileSuffix,'_theta'], theta);
                saveFigure(fh, fn, imgFormat);
                moveManyFiles(labFile, newOutputDir);
            end
        end
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% return %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if showZScoreEdges

% end % if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%% z-score of the spreading times visualized with matrix and edges
    %%% R + L TLE
%     colorLabel = '$Z(S_p)-Z(S_c)$';
%     axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
        if showDataColor
            colorBarLabel = 'Avg. Local Sp Time';
        else
            colorBarLabel = 'Faster in';
        end
        ttestLabel = 'SZ';
        if ~strcmpi(tbc,'none')
            ttestLabel = [ttestLabel,'_',tbc];
        end
        if showCommData
            matrixView = 'tril';
            fh = gobjects(1,numel(dataInd));
            cb = gobjects(1,numel(dataInd));
            for i = 1:numel(dataInd)
                [fh(i),~,~,~,~,cb(i)] = plotCommMatrix_internal(si,dataInd(i),ttestLabel,commLabels,tThresh,panelTitle,matrixView,showDataColor,effSizeLabel,useFDR_CohenThreshold);
            end
            appendCBarLabel(cb,appendStr(strtrim(cellstr(num2str(si.theta(dataInd)'))'),[],', \theta='));
            drawnow
            if saveOutputFigures
                fn = getFigureFileNames(newOutputDir, ['sptime_zscore_matrix',oFileSuffix,'_theta'], si.theta(dataInd));
                saveFigure(fh,fn,imgFormat);
                %moveManyFiles(labFile,newOutputDir);
            end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% return %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %     end % if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %     return;
    % end % if false

        else % for the condition of if showCommData

            [hMat,T] = applyTThresholdToFDR(useFDR_CohenThreshold,tThresh,{si.ttest.(ttestLabel)(dataInd).t},{si.ttest.(ttestLabel)(dataInd).(hField)});
            [fh,~,cb1,cb2,labFile] = plotSpreadingTimeZScore([],[],true,...
                si.controlData.SZ(dataInd),...
                si.patientData.SZ(dataInd),...
                hMat,...
                cMap_plus,cMap_minus,true,'',colorBarLabel,'matrix',sortInd,highlightPtrn,...%cMap_winter,cMap_autumn,true,'','Faster in','matrix',sortInd,highlightPtrn,...
                'file',aal.labels.(aLab),['sptime_zscore_edge_labels',oFileSuffix,'.txt'],...
                {si.ttest.(ttestLabel)(dataInd).h},true);
            if ~showDataColor
                changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
            end
            appendCBarLabel(cb1,appendStr(strtrim(cellstr(num2str(T'))'),[],', |T|>'));
            if saveOutputFigures
                saveFigure(fh,fullfile(newOutputDir,['sptime_zscore_matrix',oFileSuffix]),imgFormat);
                moveManyFiles(labFile,newOutputDir);
            end

    %         axLabel = cellfun(@(x)[legTitle,'; $\theta=',thetaValToTxt(x),'$'],num2cell(si.theta),'UniformOutput',false);
            [hMat,T] = applyTThresholdToFDR(useFDR_CohenThreshold,tThresh,{si.ttest.(ttestLabel)(dataInd).t},{si.ttest.(ttestLabel)(dataInd).(hField)});
            [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
                si.controlData.SZ(dataInd),...
                si.patientData.SZ(dataInd),...
                hMat,...
                cMap_plus,cMap_minus,true,'',colorBarLabel,'brain',...%cMap_winter,cMap_autumn,true,'','Faster in','brain',...
                [],'',[],[],[],...
                {si.ttest.(ttestLabel)(dataInd).h},true);%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
            if ~showDataColor
                changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
            end
            appendCBarLabel(cb1,appendStr(strtrim(cellstr(num2str(T'))'),[],', |T|>'));
            if saveOutputFigures
                saveFigure(fh,fullfile(newOutputDir,['sptime_zscore_brain',oFileSuffix]),imgFormat);
            end

            [hMat,T] = applyTThresholdToFDR(useFDR_CohenThreshold,tThresh,{si.ttest.(ttestLabel)(dataInd).t},{si.ttest.(ttestLabel)(dataInd).(hField)});
            [fh,~,cb1,cb2,~] = plotSpreadingTimeZScore([],[],aal.pos.(aLab),...
                si.controlData.SZ(dataInd),...
                si.patientData.SZ(dataInd),...
                hMat,...
                cMap_plus,cMap_minus,true,'',colorBarLabel,'brain',[],'sagital',...%cMap_winter,cMap_autumn,true,'','Faster in','brain',[],'sagital',...
                [],[],[],...
                {si.ttest.(ttestLabel)(dataInd).h},true);%cMap_winter,cMap_autumn,true,colorLabel,axLabel,'brain');
            if ~showDataColor
                changeCBarToTxtLabel(cb1,'Patients');changeCBarToTxtLabel(cb2,'Controls');
            end
            appendCBarLabel(cb1,appendStr(strtrim(cellstr(num2str(T'))'),[],', |T|>'));
            if saveOutputFigures
                saveFigure(fh,fullfile(newOutputDir,['sptime_zscore_brain_sagital',oFileSuffix]),imgFormat);
            end
        end
    end
end

function [R,Tmat] = applyTThresholdToFDR(useFDR,tThresh,tCell,hCell)
    if useFDR
        sz = size(hCell{1});
        [T,tValues] = getTValuesThreshold(tCell,tThresh,sz);
        R = cellfun(@(h,t,tt)(h>0)&(t>tt),hCell,tValues,T,'UniformOutput',false);
        Tmat = cell2mat(T);
    else
        R = hCell;
    end
end

function [T,tValues] = getTValuesThreshold(tValues,tThresh,sz)
    if isempty(tValues)
        tValues = ones(sz);
        T = 0;
        return;
    else
        if iscell(tValues)
            T = cell(1,numel(tValues));
            for i = 1:numel(tValues)
                [T{i},tValues{i}] = getTValuesThreshold_internal(tValues{i},tThresh);
            end
        else
            [T,tValues] = getTValuesThreshold_internal(tValues,tThresh);
        end
    end
end

function [T,tValues] = getTValuesThreshold_internal(tValues,tThresh)
    tValues = abs(tValues);
    mmT = minmax(tValues(:)');
    T = mmT(1) + diff(mmT)*tThresh;
end

function [fh,axh,ih,axp0,axp1,cb] = plotCommMatrix_internal(si,dataInd,ttestLabel,commLabels,tThresh,dataTitle,matrixView,showDataColor,effSizeLabel,useFDR_CohenThreshold)
    if (nargin < 7) || isempty(matrixView)
        matrixView = 'tril';
    end
    if strcmpi(matrixView,'tril')
        getData = @(A)rot90(A,2);
        commLabels = fliplr(commLabels(:)');
    else
        getData = @(A)A;
    end
    elemHighlight = getData(si.ttest.(ttestLabel)(dataInd).h);
    N_elem = size(elemHighlight,1);
    [T,tValues] = getTValuesThreshold(getData(si.ttest.(ttestLabel)(dataInd).t),tThresh,size(elemHighlight));
    pData = getData(si.patientData.SZ{dataInd} - si.controlData.SZ{dataInd});
    cMap = jet;
    if isnumeric(showDataColor) && (showDataColor == 2)
        % show effect sizes
        cMap = greenYellowPinkCMap;
        pData = getData(abs(si.ttest.SZ(dataInd).(effSizeLabel)));
        elemHighlight((getData(si.ttest.(ttestLabel)(dataInd).hFDR)==1) & (pData > useFDR_CohenThreshold)) = 2;
        dataTitle = 'Effect size';
        if strcmpi(effSizeLabel,'Cohen_Mahal')
            dataTitle = [dataTitle,' (Cohen''s d)'];
            paramEffSz = 'd';
        else
            dataTitle = [dataTitle,' (SurfStat ef)'];
            paramEffSz = 'ef';
        end
    else
        elemHighlight((getData(si.ttest.(ttestLabel)(dataInd).hFDR)==1) & (tValues > T)) = 2;
    end
    if strcmpi(matrixView,'tril')
        pData(triu(ones(N_elem),1)==1)=NaN;
    else
        pData(tril(ones(N_elem),-1)==1)=NaN;
    end
    [fh,axh,ih,axp0,axp1,cb] = ...
        plotMatrix([],[],pData,matrixView,elemHighlight,[],cMap,...
        {'ShowColorBar','on','XTick',1:numel(commLabels),'YTick',1:numel(commLabels),'XTickLabel',commLabels,'YTickLabel',commLabels},[],...
            {{'skip'},{'o','MarkerSize',3,'Color',[0,0,0],'MarkerFaceColor',[0,0,0]},'DarkenMatrix',true,'DarkenAlpha',1,'DarkenColor',0.9.*ones(1,3)},...
            {'Type','contour','Alpha',0.4,'LineStyle','-','LineWidth',0.8,'Color',0.01.*ones(1,3)},{'Label',dataTitle,'LabelProperties',{'FontSize',11}});
    if strcmpi(matrixView,'tril')
        cb.Position(1) = sum(axh.Position([1,3]))-cb.Position(3);
    else
        cb.Position(1) = axh.Position(1);
        cb.Position(2) = axh.Position(2);
    end
    if tThresh > 0
        appendCBarLabel(cb,[', |T|>',num2str(T)]);
    end
    if isnumeric(showDataColor) && (showDataColor == 2)
        appendCBarLabel(cb,[', |',paramEffSz,'|>',num2str(useFDR_CohenThreshold)]);
    else
        if numel(cb.Ticks) < 7
            cValues = linspace(cb.Limits(1),cb.Limits(2),7);
            cb.Ticks = cValues;
            cb.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
        end
        %cb.Ticks = [cb.Limits(1),cb.Ticks,cb.Limits(2)];
        cb.TickLabels{1}='same as controls';
        cb.TickLabels{2}='';
        cb.TickLabels{end}='slower in TLE';
        cb.TickLabels{end-1}='';
    end
    drawnow
end

function l = getTTestLabel(tbc,lab)
    if strcmpi(tbc,'none')
        l=[];
        return;
    end
    if ~(strcmpi(tbc,'CT') || strcmpi(tbc,'HV'))
        error('Unrecognized tTestBiasControl argument');
    end
    avgTxt = regexp(lab,'Avg(RS|R|S)?','match');
    if isempty(avgTxt)
        l = ['ttest_',lab,'_',tbc];
    else
        avgTxt = avgTxt{1};
        l = ['ttest_',strrep(lab,avgTxt,[avgTxt,'_',tbc])];
    end
end