function [fh,axh] = plotAvgVsThetaScatterPanels(thetaVal_title,cDataAll,pDataAll,yLim,passTTest,passFDR,passTTestCT,passTTestHV,yLabel,legValues)
    if ~iscell(cDataAll)
        cDataAll = { cDataAll };
    end
    if ~iscell(pDataAll)
        pDataAll = { pDataAll };
    end
    if (nargin < 4) || isempty(yLim)
        minY = min(min(min(cell2mat(cDataAll))),min(min(cell2mat(pDataAll))));
        maxY = max(max(max(cell2mat(cDataAll))),max(max(cell2mat(pDataAll))));
        yLim = [minY,maxY];
    end
    if (nargin < 5) || isempty(passTTest)
        passTTest = [];
    end
    if (nargin < 6) || isempty(passFDR)
        passFDR = [];
    end
    if (nargin < 7) || isempty(passTTestCT)
        passTTestCT = [];
    end
    if (nargin < 8) || isempty(passTTestHV)
        passTTestHV = [];
    end
    if (nargin < 9)
        yLabel = 'y';
    end
    if (nargin < 10)
        legValues = {'Controls','Patients'};
    end
    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;
    fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];
    nPanels = numel(thetaVal_title);
    
    if isempty(passTTest)
        passTTest = false(1,nPanels);
    end
    if isempty(passTTestCT)
        passTTestCT = false(1,nPanels);
    end
    if isempty(passTTestHV)
        passTTestHV = false(1,nPanels);
    end
    if isempty(passFDR)
        passFDR = false(1,nPanels);
    end
    
    if iscell(thetaVal_title)
        thetaValCell = thetaVal_title;
    else
        thetaValCell = cellfun(@(x)['\theta=',num2str(x)],num2cell(thetaVal_title),'UniformOutput',false);
    end

    ps1 = repmat(getPlotStruct(),nPanels,1);
    pps1 = repmat(getPlotStruct(),nPanels,1);
    for i = 1:nPanels
        x1 = { cDataAll{i}, pDataAll{i} };
        y1 = { cDataAll{i}, pDataAll{i} };
        %dataLegend = legValues;
        strTitle = '';
        if passFDR(i)
            %dataLegend = appendStr(dataLegend,'','*');
            strTitle = [strTitle,'*'];
        elseif passTTest(i)
            %dataLegend = appendStr(dataLegend,'','+');
            strTitle = [strTitle,'+'];
        end
        if passTTestCT(i)
            %dataLegend = appendStr(dataLegend,'*CT','');
            if ~isempty(strTitle)
                strTitle(end+1) = ',';
            end
            strTitle = [strTitle,'*CT'];
        end
        if passTTestHV(i)
            %dataLegend = appendStr(dataLegend,'*HV','');
            if ~isempty(strTitle)
                strTitle(end+1) = ',';
            end
            strTitle = [strTitle,'*HV'];
        end
        stitle = [thetaValCell{i},strTitle];
        if isnumeric(thetaVal_title) && isnan(thetaVal_title(i))
            stitle = '';
        end
        ps1(i) = getPlotStruct(x1,y1,cell(size(x1)),'',yLabel, 'bar', 'linear', '', legValues, 0, stitle);
        [pps1(i),xTicks] = getMeanStdPlotStruct(ps1(i),'',yLabel,'linear','linear','',legValues,0,stitle);
        if i > 1
            ps1(i).yLabel = '';
            pps1(i).yLabel = '';
        end
    end

    fh = figure('Renderer', 'painters', 'Position', [ fp.x0Fig, fp.y0Fig, (fp.wFig/2)*(nPanels/3), fp.hFig ]);
    axh = gobjects(1,nPanels);
    ax0 = [(1.8*fp.lMargin).*(3/nPanels),fp.bMargin,(fp.wAx/2).*(3/nPanels),fp.hAx/2];
    for i = 1:nPanels
        axh(i) = axes('Position', ax0 + (i-1).*[(1.4*fp.lMargin+fp.wAx/2).*(3/nPanels),0,0,0]);
        plotPlotStruct(axh(i), ps1(i), {'n'}, [], fp.pSymbols, fp.pColors, ...
            {'LineWidth', fp.pLineWidth, 'MarkerSize', fp.pPointSize},... % plot properties
            {'ShowErrorBar', 'on', 'LineWidth', 3, 'Color', fp.pErrLineColor},... % error properties
            {'Box', 'on', 'Layer', 'top', 'XTick', xTicks, 'XTickLabel', legValues, 'XLim', [-0.5,(2*numel(x1)-0.5)], 'YLim', yLim},... % axis properties
            {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
            {'FontSize', 11, 'YDisplacement', [0.12,0,0]},... % label properties
            {'FontWeight','normal','FontSize',11,'Interpreter','tex'}); % title properties
        plotPlotStruct(axh(i), pps1(i), {'n'}, [], '+', [0,0,0], ...
            {'LineWidth', 14, 'MarkerSize', 2},... % plot properties
            {'ShowErrorBar', 'on', 'LineWidth', 2, 'Color', fp.pErrLineColor}); % label properties
    end

end