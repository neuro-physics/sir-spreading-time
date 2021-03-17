function plot_sim_data_spider_scatter(groupToPlot,spiOutputDir,gcompOutputDir)
    global N aal imgFormat saveOutputFigures plotData si %si_n306 si_n90 


%     plot_func.plot_sim_data_PhaseTrans(si_n90,si_n306,'Group1','Group2','Group3',groupLegend,saveOutputFigures,outputDir,imgFormat)
%     plot_func.plot_sim_data_SpMatrix_01(si_n90,si_n306,'Group1','Group2','Group3',groupLegend,saveOutputFigures,outputDir,imgFormat,isActThresh,isConsensus)
%     if N == 90
%         si = si_n90;
%     else
%         si = si_n306;
%     end
    lobeLabel = getLobeLabel(si,groupToPlot,'lobeLabel');
    lobeLabelLR = getLobeLabel(si,groupToPlot,'lobeLabelLR');

    %if false % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    si1 = getData_internal(si,groupToPlot,'raw','PhaseTrans');
    plot_func.plot_sim_data_PhaseTrans_paper(si1,[],[],'','',[],saveOutputFigures,gcompOutputDir,imgFormat)

    si1 = getData_internal(si,groupToPlot,plotData,'SpMatrix');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpMatrix_01_paper(si1, N, plotData,'','',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[])
    end
    
    si1 = getData_internal(si,groupToPlot,plotData,'SpMatrixW');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpMatrix_01_paper(si1, N, plotData,'','',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[])
    end

    si1 = getData_internal(si,groupToPlot,plotData,'TwoSeeds');
    if ~isempty(si1)
        plot_func.plot_sim_data_TwoSeeds_theta_paper(si1, N, plotData,'','',[],saveOutputFigures,gcompOutputDir,imgFormat,[],[])
    end

    si1 = getData_internal(si,groupToPlot,plotData,'SpeedUp');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpeedUp_theta_paper(si1,N, plotData,'','','',saveOutputFigures,gcompOutputDir,imgFormat,[],[],'')
    end

    si1 = getData_internal(si,groupToPlot,plotData,'SpeedUpW');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpeedUp_theta_paper(si1,N, plotData,'','','',saveOutputFigures,gcompOutputDir,imgFormat,[],[],'')
    end

    %end % if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%     if verLessThan('matlab','R2016a')
%         warning('Spider plots are not going to be displayed because MATLAB version is older than R2016a');
%     else
        %if false %  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    si1 = getData_internal(si,groupToPlot,plotData,'SpMatrix');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpMatrix_spider_paper(si1,lobeLabel,lobeLabelLR,'','','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'',aal)
    end

    %end % if false %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    si1 = getData_internal(si,groupToPlot,plotData,'SpMatrixW');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpMatrix_spider_paper(si1,lobeLabel,lobeLabelLR,'','','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'',aal)
    end

    si1 = getData_internal(si,groupToPlot,plotData,'TwoSeeds');
    if ~isempty(si1)
        plot_func.plot_sim_data_TwoSeeds_spider_paper(si1,lobeLabel,lobeLabelLR,'','','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'',aal)
    end

    si1 = getData_internal(si,groupToPlot,plotData,'SpeedUp');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpeedUp_spider_paper(si1,lobeLabel,lobeLabelLR,'','','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'',aal)
    end

    si1 = getData_internal(si,groupToPlot,plotData,'SpeedUpW');
    if ~isempty(si1)
        plot_func.plot_sim_data_SpeedUp_spider_paper(si1,lobeLabel,lobeLabelLR,'','','',saveOutputFigures,spiOutputDir,imgFormat,[],[],'',aal)
    end
%     end
end

function l = getLobeLabel(si,groupToPlot,lobeLabelField)
    if iscell(groupToPlot)
        gt = groupToPlot{1};
    else
        gt = groupToPlot;
    end
    l = si.(gt).(lobeLabelField);
end

function r = getData_internal(s,groupToPlot,plotData,dataField)
    if iscell(groupToPlot)
        r = cell(size(groupToPlot));
        for i = 1:numel(groupToPlot)
            r{i} = getData_internal_group(s,groupToPlot{i},plotData,dataField);
            r{i}.groupTitle = groupToPlot{i};
        end
    else
        r = getData_internal_group(s,groupToPlot,plotData,dataField);
        r.groupTitle = groupToPlot;
    end
end

function s = getData_internal_group(s,groupToPlot,plotData,dataField)
    if isfield(s.(groupToPlot),dataField) && ~isempty(s.(groupToPlot).(dataField))
        if strcmpi(plotData,'raw')
            s = s.(groupToPlot).(dataField);
        elseif strcmpi(plotData,'flip')
            s = s.(groupToPlot).(dataField).flip;
        elseif strcmpi(plotData,'zScoreToControls')
            s = s.(groupToPlot).(dataField).zToControl;
        end
    else
        warning('%s.%s is empty field',groupToPlot,dataField);
        s = [];
    end
end
