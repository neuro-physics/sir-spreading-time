function plot_sim_data_spider_scatter_paper(groupToPlot,spiOutputDir,gcompOutputDir,thetaVal)
    global N aal imgFormat saveOutputFigures plotData si showMTLData volumeVarName useFDR showDataColor effectSizeField

    showEffectSizes = 1;
    if showDataColor == 2
        showEffectSizes = 2;
    end
    if isnumeric(useFDR)
        CohenThreshold = useFDR;
    else
        CohenThreshold = 0.8;
    end
    

%     plot_func.plot_sim_data_PhaseTrans(si_n90,si_n306,'Group1','Group2','Group3',groupLegend,saveOutputFigures,outputDir,imgFormat)
%     plot_func.plot_sim_data_SpMatrix_01(si_n90,si_n306,'Group1','Group2','Group3',groupLegend,saveOutputFigures,outputDir,imgFormat,isActThresh,isConsensus)
%     if N == 90
%         si = si_n90;
%     else
%         si = si_n306;
%     end
    lobeLabel = getLobeLabel(si,groupToPlot,'lobeLabel');
    lobeLabelLR = getLobeLabel(si,groupToPlot,'lobeLabelLR');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if false
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    [si1,~] = getData_internal(si,groupToPlot,'raw','PhaseTrans');
    plot_func.plot_sim_data_PhaseTrans_paper(si1,thetaVal,[],'','',[],saveOutputFigures,gcompOutputDir,imgFormat)
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpMatrix');
    if hasData
        plot_func.plot_sim_data_SpMatrix_01_paper(si1, N, plotData, thetaVal,'',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[],'_bin',showMTLData,volumeVarName)
    end
% end
    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpMatrixW');
    if hasData
        plot_func.plot_sim_data_SpMatrix_01_paper(si1, N, plotData, thetaVal,'',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[],'_wei',showMTLData,volumeVarName)
    end
% return
    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'TwoSeeds');
    if hasData
        plot_func.plot_sim_data_TwoSeeds_theta_paper(si1, N, plotData,'','',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[],'_bin')
    end

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpeedUp');
    if hasData
        plot_func.plot_sim_data_SpeedUp_theta_paper(si1,N, plotData,'','','',saveOutputFigures,gcompOutputDir,imgFormat,[],[],'_bin')
    end
    
    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpeedUpW');
    if hasData
        plot_func.plot_sim_data_SpeedUp_theta_paper(si1,N, plotData,'','','',saveOutputFigures,gcompOutputDir,imgFormat,[],[],'_wei')
    end
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SPIDER PLOTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SPIDER PLOTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% SPIDER PLOTS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpMatrix');
    if hasData
        plot_func.plot_sim_data_SpMatrix_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,'','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'_bin',aal,showMTLData)
    end
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% end % if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpMatrixW');
    if hasData
        plot_func.plot_sim_data_SpMatrix_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,'','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'_wei',aal,showMTLData,showEffectSizes,effectSizeField,CohenThreshold)
    end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% return %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'TwoSeeds');
    if hasData
        plot_func.plot_sim_data_TwoSeeds_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,'','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'_bin',aal)
    end
    
    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpeedUp');
    if hasData
        plot_func.plot_sim_data_SpeedUp_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,'','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'_bin',aal)
    end

    [si1,hasData] = getData_internal(si,groupToPlot,plotData,'SpeedUpW');
    if hasData
        plot_func.plot_sim_data_SpeedUp_spider_paper(si1,lobeLabel,lobeLabelLR,thetaVal,'','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'_wei',aal)
    end
end

function l = getLobeLabel(si,groupToPlot,lobeLabelField)
    if iscell(groupToPlot)
        gt = groupToPlot{1};
    else
        gt = groupToPlot;
    end
    l = si.(gt).(lobeLabelField);
end

function [r,hasData] = getData_internal(s,groupToPlot,plotData,dataField)
    if iscell(groupToPlot)
        r = cell(size(groupToPlot));
        hasData = true;
        for i = 1:numel(groupToPlot)
            [r{i},hasDataTemp] = getData_internal_group(s,groupToPlot{i},plotData,dataField);
            hasData = hasData && hasDataTemp;
            r{i}.groupTitle = groupToPlot{i};
        end
    else
        [r,hasData] = getData_internal_group(s,groupToPlot,plotData,dataField);
        r.groupTitle = groupToPlot;
    end
end

function [s,hasData] = getData_internal_group(s,groupToPlot,plotData,dataField)
    if isfield(s.(groupToPlot),dataField) && ~isempty(s.(groupToPlot).(dataField))
        hasData = true;
        if strcmpi(plotData,'raw')
            s = s.(groupToPlot).(dataField);
        elseif strcmpi(plotData,'flip')
            s = s.(groupToPlot).(dataField).flip;
        elseif strcmpi(plotData,'zScoreToControls')
            s = s.(groupToPlot).(dataField).zToControl;
        end
    else
        warning('%s.%s is empty field',groupToPlot,dataField);
        hasData = false;
        s = [];
    end
end
