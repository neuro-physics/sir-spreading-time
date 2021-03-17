function [fh,axh] = plotAvgVsThetaScatter(fh,axh,thetaVal,cAvg,pAvg,cStd,pStd,cDataAll,pDataAll,passTTest,passTTestCT,passTTestHV,xLabel,yLabel,legValues,stdCorrectionFactor,yLabelHorizDisplacement,xDataHorizDisplace)
    if (nargin < 6)
        cStd = [];
    end
    if (nargin < 7)
        pStd = [];
    end
    if (nargin < 8)
        cDataAll = [];
    end
    if (nargin < 9)
        pDataAll = [];
    end
    if (nargin < 10)
        passTTest = [];
    end
    if (nargin < 11)
        passTTestCT = [];
    end
    if (nargin < 12)
        passTTestHV = [];
    end
    if (nargin < 13)
        xLabel = 'x';
    end
    if (nargin < 14)
        yLabel = 'y';
    end
    if (nargin < 15)
        legValues = {'Controls','Patients','T-test','T-test CT','T-test HV'};
    end
    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;
    fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];
    nPanels = numel(thetaVal);
    nCon = numel(cDataAll{1});
    nPat = numel(pDataAll{1});
    if (nargin < 16) %|| isempty(stdCorrectionFactor)
        stdCorrectionFactor = 1;
        stdCorrectionFactorC = 1/sqrt(nCon);
        stdCorrectionFactorP = 1/sqrt(nPat);
    else
        stdCorrectionFactorC = stdCorrectionFactor;
        stdCorrectionFactorP = stdCorrectionFactor;
    end
    if isempty(stdCorrectionFactor)
        stdCorrectionFactorC = 1;
        stdCorrectionFactorP = 1;
    end
    if (nargin < 17) || isempty(yLabelHorizDisplacement)
        yLabelHorizDisplacement = 0;
    end
    if (nargin < 18) || isempty(xDataHorizDisplace)
        xDataHorizDisplace = 0;
    end
    cErr = cStd.*stdCorrectionFactorC;
    pErr = pStd.*stdCorrectionFactorP;
    yLimMax = ceil(10*max([cAvg,pAvg]+[cErr,pErr]))/10;
    yLimMin = floor(10*min([cAvg,pAvg]-[cErr,pErr]))/10;

    if (nargin < 1) || isempty(fh)
        fh = figure('Renderer', 'painters', 'Position', [ fp.x0Fig, fp.y0Fig, fp.wFig/2, fp.hFig ]);
    end
    if (nargin < 2) || isempty(axh)
        axh = axes('Position', [2.5*fp.lMargin,fp.bMargin,1.9*fp.wAx,1*fp.hAx]);
    end
    if ~isempty(cDataAll)
        thetaCon = thetaVal - xDataHorizDisplace;
        thetaPat = thetaVal + xDataHorizDisplace;
        x1 = [ cellfun(@(x)thetaCon(x).*ones(1,nCon),num2cell(1:nPanels),'UniformOutput',false), cellfun(@(x)thetaPat(x).*ones(1,nPat),num2cell(1:nPanels),'UniformOutput',false) ];
        y1 = [ cellfun(@(x)x,cDataAll,'UniformOutput',false), cellfun(@(x)x,pDataAll,'UniformOutput',false) ];
        pps1 = getPlotStruct(x1,y1,cell(size(x1)),xLabel,yLabel, 'linear', 'linear', '', legValues(1:2), 0, '');
        plotPlotStruct(axh, pps1, {'n'}, [], '.', [repmat(fp.pColors(1,:),nPanels,1);repmat(fp.pColors(2,:),nPanels,1)], ...
                {'LineWidth', 10},... % plot properties
                {'ShowErrorBar', 'off'}); % label properties
    end
    x1 = {thetaVal,thetaVal};
    y1 = {cAvg,pAvg};
    if isempty(cStd)
        err = cell(1,2);
    else
        err = {cErr,pErr};
    end
    if ~isempty(passTTest)
        maxY = ceil(10*max([cAvg,pAvg]))/10;
        maxY = 0.3*maxY + 0.7*yLimMax;
        xx = NaN(size(passTTest));
        yy = NaN(size(xx));
        xx(passTTest) = thetaVal(passTTest);
        yy(passTTest) = maxY;
        if ~all(isnan(xx))
            x1{end+1} = xx;
            y1{end+1} = yy;
            err{end+1} = [];
        end
    end
    if ~isempty(passTTestCT)
        maxY = ceil(10*max([cAvg,pAvg]))/10;
        maxY = 0.5*maxY + 0.5*yLimMax;
        xx = NaN(size(passTTestCT));
        yy = NaN(size(xx));
        xx(passTTestCT) = thetaVal(passTTestCT);
        yy(passTTestCT) = maxY;
        if ~all(isnan(xx))
            x1{end+1} = xx;
            y1{end+1} = yy;
            err{end+1} = [];
        end
    end
    if ~isempty(passTTestHV)
        maxY = ceil(10*max([cAvg,pAvg]))/10;
        maxY = 0.7*maxY + 0.3*yLimMax;
        xx = NaN(size(passTTestHV));
        yy = NaN(size(xx));
        xx(passTTestHV) = thetaVal(passTTestHV);
        yy(passTTestHV) = maxY;
        if ~all(isnan(xx))
            x1{end+1} = xx;
            y1{end+1} = yy;
            err{end+1} = [];
        end
    end
    ps1 = getPlotStruct(x1, y1, err, xLabel, yLabel, 'linear', 'linear', '', legValues, 1, '');
    plotPlotStruct(axh, ps1, {'-','-','n','n','n'}, [], [fp.pSymbols(1:2),'*od'], [fp.pColors(1:2,:);0,0,0;1,0,0;0,0,1], ...
            {'LineWidth', 0.5, 'MarkerSize', 4, 'MarkerFaceColor', 'w'},... % plot properties
            {'ShowErrorBar', 'on', 'LineWidth', 1, 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
            {'FontSize', 8, 'Box', 'on', 'Layer', 'top', 'XLim', [(thetaVal(1)-0.001),(thetaVal(end)+0.001)], 'YLim', [yLimMin,yLimMax]},... % axis properties
            {'Location', 'northoutside', 'FontSize', 8, 'Box', 'off', 'Interpreter', 'tex'},... % legend properties
            {'FontSize', 11, 'YDisplacement', [(0.02+yLabelHorizDisplacement),0,0]},... % label properties
            {'FontWeight','normal','FontSize',11,'Interpreter','tex'}); % title properties
end