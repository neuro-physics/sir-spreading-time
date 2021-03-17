function [fh,axh] = plotSIScatterCorr(si,controlVarLabel,dataLabel,dataInd,xLabel,yLabel,legValues,plotTitle,colNames,transposeData)
    if ~iscell(si.controlData.(dataLabel))
        si.controlData.(dataLabel) = { si.controlData.(dataLabel) };
    end
    if (nargin < 4) || isempty(dataInd)
        dataInd = 1:numel(si.controlData.(dataLabel));
    end
    if (nargin < 8) || isempty(plotTitle)
        if numel(dataInd) == 1
            plotTitle = ['\theta=',num2str(si.theta(dataInd(1)))];
        else
            plotTitle = cellfun(@(x)['\theta=',num2str(si.theta(x))],num2cell(dataInd),'UniformOutput',false);
        end
    end
    if (nargin < 10) || isempty(transposeData)
        transposeData = false;
    end
    if transposeData
        si.controlData.(dataLabel) = transposeCells(si.controlData.(dataLabel));
        si.patientData.(dataLabel) = transposeCells(si.patientData.(dataLabel));
        si.controlData.(controlVarLabel) = transposeCells(si.controlData.(controlVarLabel));
        si.patientData.(controlVarLabel) = transposeCells(si.patientData.(controlVarLabel));
    end
    nCols = size(si.controlData.(dataLabel){dataInd(1)},2);
    if (nargin < 9) || isempty(colNames)
        colNames = cellfun(@(x)['Col-',num2str(x)],num2cell(1:nCols),'UniformOutput',false);
    end
    if nCols > 1 % 1 or many theta values and many nodes, each node named by each entry in colNames
        % plots 1 figure for each theta value, with nCols panels each
        fh = gobjects(1,numel(dataInd));
        axh = gobjects(1,numel(dataInd)*nCols);
        for i = 1:numel(dataInd)
            k = dataInd(i);
            yp = mat2cell(si.patientData.(dataLabel){k},size(si.patientData.(dataLabel){k},1),ones(1,nCols));
            yc = mat2cell(si.controlData.(dataLabel){k},size(si.controlData.(dataLabel){k},1),ones(1,nCols));
            if iscell(si.patientData.(controlVarLabel))
                xp = mat2cell(si.patientData.(controlVarLabel){k},size(si.patientData.(controlVarLabel){k},1),ones(1,nCols));
            else
                xp = si.patientData.(controlVarLabel);
            end
            if iscell(si.controlData.(controlVarLabel))
                xc = mat2cell(si.controlData.(controlVarLabel){k},size(si.controlData.(controlVarLabel){k},1),ones(1,nCols));
            else
                xc = si.controlData.(controlVarLabel);
            end
            [fh(i),axhTemp] = plotScatterCorr([],[],xp,yp,...
                xc,yc,...
                xLabel,yLabel,legValues,colNames);
            axh((1:nCols) + (i-1)*nCols) = axhTemp;
            annotation('textbox',[0.5,0.95,1e-5,1e-5],'String',['\theta=',num2str(si.theta(k))],'FitBoxToText','on','FontSize',12,'EdgeColor','none');
        end
    else
        if numel(dataInd) == 1 % 1 node and 1 theta
            if iscell(plotTitle)
                plotTitle = plotTitle{1};
            end
            % plots 1 figure with 1 panel
            if iscell(si.patientData.(controlVarLabel))
                xp = si.patientData.(controlVarLabel){dataInd(1)};
            else
                xp = si.patientData.(controlVarLabel);
            end
            if iscell(si.controlData.(controlVarLabel))
                xc = si.controlData.(controlVarLabel){dataInd(1)};
            else
                xc = si.controlData.(controlVarLabel);
            end
            yc = si.controlData.(dataLabel){dataInd(1)};
            [fh,axh] = plotScatterCorr([],[],xp,si.patientData.(dataLabel){dataInd(1)},...
                xc,yc,...
                xLabel,yLabel,legValues,plotTitle);
        else % 1 node and many theta values
            % plots 1 figure with many panels
            [fh,axh] = plotScatterCorr([],[],si.patientData.(controlVarLabel),si.patientData.(dataLabel),...
                si.controlData.(controlVarLabel),si.controlData.(dataLabel),...
                xLabel,yLabel,legValues,plotTitle);
        end
    end
end

function x = transposeCells(x)
    if iscell(x)
        x = cellfun(@(y)y',x,'UniformOutput',false);
    else
        x = x';
    end
end