function plot_sim_data_for(dataField,thetaVal,speedUpSpecification)
    if (nargin < 2) || isempty(thetaVal)
        thetaVal = [];
    end
    if (nargin < 3) || isempty(speedUpSpecification)
        speedUpSpecification = '';
    end

    global N displayData groupLabels highlightPtrn_n306 highlightPtrn_n90 sort_n306 sort_n90 si tThresh %si_n306 si_n90

    commDataField = ['Comm',dataField];
    
    % part of plot_sim_data.m

    if N == 90
%         si = si_n90;
        hlPtrn = highlightPtrn_n90;
        sc = sort_n90;
    else
%         si = si_n306;
        hlPtrn = highlightPtrn_n306;
        sc = sort_n306;
    end

    if strcmp(dataField,'SpeedUp') && strcmp(speedUpSpecification,'local')
        if all(cellfun(@isempty,si.(groupLabels{1}).SpeedUp.controlData.local))
            disp(sprintf('N=%d has no local speed-up data',N))
            return;
        end
    end

    % data
    if any(strcmp(displayData,'raw'))
        for i = 1:numel(groupLabels)
            for t = tThresh
                fn_suffix = ['_TvalThresh',num2str(t,'%.2g')];
                call_plot_group_function(i,dataField,si,hlPtrn,sc,speedUpSpecification,thetaVal,false,t,fn_suffix);
            end
        end
    end

    % comm data
    if any(strcmp(displayData,'comm')) && strcmpi(dataField,'SpMatrixW')
        for i = 1:numel(groupLabels)
            for t = tThresh
                fn_suffix = ['_TvalThresh',num2str(t,'%.2g')];
                call_plot_group_function(i,commDataField,si,hlPtrn,sc,speedUpSpecification,thetaVal,true,t,fn_suffix);
            end
        end
    end
end

function call_plot_group_function(i,dataField,si,hlPtrn,sc,speedUpSpecification,thetaVal,isCommData,tThresh,fileNameSuffix)
    global groupLabels plotData nodeLabels
    if (nargin < 9) || isempty(tThresh)
        tThresh = 0;
    end
    if (nargin < 10) || isempty(fileNameSuffix)
        fileNameSuffix = '';
    end
    g = groupLabels{i};
    %sd = si.(g).Side;
    if isCommData
        myNodeLabels = {'Limbic','Limbic','Subcortical','Subcortical'};
    else
        myNodeLabels = nodeLabels;
    end

    if isfield(si.(g),dataField) && ~isempty(si.(g).(dataField))
        if strcmp(plotData,'raw') % 'raw' means no z-scoring at all
            pData = si.(g).(dataField);
        elseif strcmp(plotData,'flip') % 'flip' means the simulation data has been z-scored to controls and then flipped
            pData = si.(g).(dataField).flip;
        elseif strcmp(plotData,'zScoreToControls') % 'zScoreToControls' means no flipping occured
            pData = si.(g).(dataField).zToControl;
        else
            error('Unrecognized plotData value');
        end
        call_plot_group_function_internal(dataField,pData,i,g,hlPtrn,sc,speedUpSpecification,thetaVal,myNodeLabels,tThresh,fileNameSuffix);
    else
        warning('%s.%s is empty field',g,dataField);
    end
end

function call_plot_group_function_internal(dataField,pData,gi,gTitle,hlPtrn,sc,speedUpSpecification,thetaVal,myNodeLabels,tThresh,fileNameSuffix)
    global N aal groupOutputDir imgFormat saveOutputFigures sortNodesBy useFDR groupOutputDirComm showDataColor showMTLData showZScoreEdges effectSizeField
    
    if ~ischar(dataField)
        error('data field must be a standard character array with only one field');
    end
    if ~ischar(speedUpSpecification)
        error('speedUpSpecification must be a standard char array: global, local or localnet');
    end

    if strcmp(dataField,'SpMatrix')
        plot_func.plot_sim_data_SpMatrix_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor,showMTLData,showZScoreEdges);
    elseif strcmp(dataField,'SpMatrixW')
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor,'',showMTLData,showZScoreEdges,tThresh,effectSizeField);
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor,'CT',showMTLData,showZScoreEdges,tThresh,effectSizeField);
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor,'HV',showMTLData,showZScoreEdges,tThresh,effectSizeField);
    elseif strcmp(dataField,'CommSpMatrix')
        fileNameSuffix = [fileNameSuffix,'_comm'];
        plot_func.plot_sim_data_SpMatrix_02_Group(aal,pData,thetaVal,gTitle,[],[],saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,[],true,sortNodesBy,showDataColor,showMTLData,showZScoreEdges);
    elseif strcmp(dataField,'CommSpMatrixW')
        fileNameSuffix = [fileNameSuffix,'_comm'];
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,true,sortNodesBy,showDataColor,'',showMTLData,showZScoreEdges,tThresh,effectSizeField);
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,true,sortNodesBy,showDataColor,'CT',showMTLData,showZScoreEdges,tThresh,effectSizeField);
        plot_func.plot_sim_data_SpMatrixW_02_Group(aal,pData,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,true,sortNodesBy,showDataColor,'HV',showMTLData,showZScoreEdges,tThresh,effectSizeField);
    elseif strcmp(dataField,'SpeedUp')
        plot_func.plot_sim_data_SpeedUp_Group(aal,pData,speedUpSpecification,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor);
    elseif strcmp(dataField,'SpeedUpW')
        plot_func.plot_sim_data_SpeedUpW_Group(aal,pData,speedUpSpecification,thetaVal,gTitle,sc,hlPtrn,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,myNodeLabels,false,sortNodesBy,showDataColor);
    elseif strcmp(dataField,'CommSpeedUp')
        fileNameSuffix = [fileNameSuffix,'_comm'];
        plot_func.plot_sim_data_SpeedUp_Group(aal,pData,speedUpSpecification,thetaVal,gTitle,[],[],saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,[],true,sortNodesBy,showDataColor);
    elseif strcmp(dataField,'TwoSeeds')
        plot_func.plot_sim_data_TwoSeeds_Group(pData,thetaVal,gTitle,saveOutputFigures,groupOutputDir{gi},imgFormat,fileNameSuffix,useFDR,N,false,sortNodesBy,showDataColor);
    elseif strcmp(dataField,'CommTwoSeeds')
        fileNameSuffix = [fileNameSuffix,'_comm'];
        plot_func.plot_sim_data_TwoSeeds_Group(pData,thetaVal,gTitle,saveOutputFigures,groupOutputDirComm{gi},imgFormat,fileNameSuffix,useFDR,N,true,sortNodesBy,showDataColor);
    else
        error('Unrecognized data field');
    end
end
