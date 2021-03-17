function plot_sim_data_TwoSeeds_Group(si,thetaVal,legTitle,saveOutputFigures,outputDir,imgFormat,oFileSuffix,useFDR,N,showCommData,sortNodesBy,showDataColor)

    if (nargin < 8) || isempty(oFileSuffix)
        oFileSuffix = '';
    end
    if (nargin < 9) || isempty(useFDR)
        useFDR = false;
    end
    if (nargin < 10) || isempty(N)
        N = 90;
    end
    if (nargin < 11) || isempty(showCommData)
        showCommData = false;
    end
    if (nargin < 13) || isempty(showDataColor)
        showDataColor = true;
    end
    
    [~,dataInd,~] = intersect(si.theta,thetaVal,'stable');
    if isempty(dataInd)
        dataInd = 1:numel(si.theta);
    end

    %tTestColorProp = [255,73,73;0,0,0;0,200,255]./255; % red, black, blue
    if showDataColor
        tTestColorProp = { 'ColorArr', jet(N), 'ShowDataColor', 'on' };
    else
        tTestColorArr = [132,17,17;... % dark red
                         255,107,107;... % light red
                         255,255,255;... % white
                         98,195,255;... % light blue
                         21,46,135]./255; % dark blue
        tTestColorArr = flipud(tTestColorArr);
        tTestColorProp = { 'ColorArr', tTestColorArr, 'ColorLim1', [-2,2] };
    end

%     [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'H_Z_Std','H_Z'}, dataInd, legTitle, 'Avg. Entropy $\langle Z(H_p)\rangle-\langle Z(H_c)\rangle$', tTestColorProp, 'file', ['entropy_zscore',oFileSuffix,'_label.txt'], useFDR);
    [fh,~,labFile,theta,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'H_Std','H'}, dataInd, legTitle, 'Avg. Entropy', tTestColorProp, 'file', ['entropy_zscore',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Controls','Patients'});setColorBarTitle(cb1,'Greater in');
    end
    %[fh,~,~,theta,fhFDR] = plotSpMatrixSurface(si, 'H_Z', legTitle, 'Avg. Entropy $\langle Z(H_p)\rangle-\langle Z(H_c)\rangle$', tTestColorProp, [], [], useFDR);
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['entropy_zscore',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end
%     [fh,~,labFile,~,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'Cp_Z_Std','Cp_Z'}, dataInd, legTitle, 'Avg. Competitiveness $\langle Z(A_p)\rangle-\langle Z(A_c)\rangle$', tTestColorProp, 'file', ['nodecomp_zscore',oFileSuffix,'_label.txt'], useFDR);
    [fh,~,labFile,~,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'Cp_Std','Cp'}, dataInd, legTitle, 'Avg. Competitiveness', tTestColorProp, 'file', ['nodecomp_zscore',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Controls','Patients'});setColorBarTitle(cb1,'Greater in');
    end
    %[fh,~,~,~,fhFDR] = plotSpMatrixSurface(si, 'Cp_Z', legTitle, 'Avg. Competitiveness $\langle Z(A_p)\rangle-\langle Z(A_c)\rangle$', tTestColorProp, [], [], useFDR);
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['nodecomp_zscore',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end
%     [fh,~,labFile,~,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'Cf_Z_Std','Cf_Z'}, dataInd, legTitle, 'Avg. Conformity $\langle Z(C_p)\rangle-\langle Z(C_c)\rangle$', tTestColorProp, 'file', ['nodeconf_zscore',oFileSuffix,'_label.txt'], useFDR);
    [fh,~,labFile,~,fhFDR,cb1,~] = plotSpMatrixSurface(si, {'Cf_Std','Cf'}, dataInd, legTitle, 'Avg. Conformity', tTestColorProp, 'file', ['nodeconf_zscore',oFileSuffix,'_label.txt'], useFDR,[],[],[],sortNodesBy);
    if ~showDataColor
        changeCBarToTxtLabel(cb1,{'Controls','Patients'});setColorBarTitle(cb1,'Greater in');
    end
    %[fh,~,~,~,fhFDR] = plotSpMatrixSurface(si, 'Cf_Z', legTitle, 'Avg. Conformity $\langle Z(C_p)\rangle-\langle Z(C_c)\rangle$', tTestColorProp, [], [], useFDR);
    if saveOutputFigures
        fn = getFigureFileNames(outputDir, ['nodeconf_zscore',oFileSuffix,'_theta'], theta);
        saveFigure(fh, fn, imgFormat);
        saveFigure(fhFDR, appendStr(fn,'_tTest'), imgFormat);
        moveManyFiles(labFile, outputDir);
    end
end