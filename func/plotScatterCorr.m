function [fh,axh,th] = plotScatterCorr(fh,axh,xp,yp,xc,yc,xLabel,yLabel,legValues,plotTitle,legendProperties,ignoreOutliersX,ignoreOutliersY,txtParPrecision,txtParFontSize)
    if (nargin < 7) || isempty(xLabel)
        xLabel = 'x';
    end
    if (nargin < 8) || isempty(yLabel)
        yLabel = 'y';
    end
    if (nargin < 9) || isempty(legValues)
        legValues = {'Controls','Patients','Controls Fit','Patients Fit'};
    else
        if numel(legValues) ~= 4
            legValues = [ legValues(1:2),'Controls Fit','Patients Fit' ];
        end
    end
    if (nargin < 10) || isempty(plotTitle)
        plotTitle = '';
    end
    if (nargin < 11) || isempty(legendProperties)
        legendProperties = {'Box','on'};
    end
    if (nargin < 12) || isempty(ignoreOutliersX)
        ignoreOutliersX = false;
    end
    if (nargin < 13) || isempty(ignoreOutliersY)
        ignoreOutliersY = false;
    end
    if (nargin < 14) || isempty(txtParPrecision)
        txtParPrecision = '%.3g';
    end
    if (nargin < 15) || isempty(txtParFontSize)
        txtParFontSize = 11;
    end
    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;
    fp.pColors = [hex2rgb({'#33a02c','#6a3d9a'});fp.pColors];
    
    if iscell(yp) || iscell(yc) || iscell(xp) || iscell(xc)
        if iscell(yp)
            nPanels = numel(yp);
        elseif iscell(yc)
            nPanels = numel(yc);
        elseif iscell(xp)
            nPanels = numel(xp);
        elseif iscell(xc)
            nPanels = numel(xc);
        end
        if ~iscell(xLabel)
            xLabel = repeatToComplete({xLabel},nPanels);
        end
        if ~iscell(xp)
            xp = repeatToComplete({xp},nPanels);
        end
        if ~iscell(xc)
            xc = repeatToComplete({xc},nPanels);
        end
        if ~iscell(yp)
            yp = repeatToComplete({yp},nPanels);
        end
        if ~iscell(yc)
            yc = repeatToComplete({yc},nPanels);
        end
        if ~iscell(plotTitle)
            plotTitle = cellfun(@(x)plotTitle,cell(1,nPanels),'UniformOutput',false);
        end
        if (nargin < 1) || isempty(fh)
            fh = figure('Renderer', 'painters', 'Position', [ fp.x0Fig, fp.y0Fig, nPanels*(fp.wFig/2.7), fp.hFig ]);
        end
        showLegend = zeros(1,nPanels);
        showLegend(1) = 1;
        fp.lMargin = 1.5*fp.lMargin*(2/nPanels);
        fp.bMargin = 2.7*fp.bMargin*(2/nPanels);
        wAx = 1/nPanels - fp.lMargin - 0.05*fp.lMargin;
        axh = gobjects(1,nPanels);
        ax0 = [fp.lMargin,fp.bMargin,wAx,fp.hAx/1.35];
        for i = 1:nPanels
            axh(i) = axes('Position', ax0 + (i-1).*[(0.9*fp.lMargin+wAx),0,0,0]);
            if i>1
                yyLab = '';
            else
                yyLab = yLabel;
            end
            th = plotScatterCorr_internal(axh(i),xp{i},yp{i},xc{i},yc{i},xLabel{i},yyLab,legValues,plotTitle{i},fp,showLegend(i),['Units','pixels','Position', [14.3855 259.3889 90.8491 31.6459],legendProperties],ignoreOutliersX,ignoreOutliersY,txtParPrecision,txtParFontSize); % {'Position', [0.0036,0.7969,0.0896,0.1996]}
        end
    else
        if (nargin < 1) || isempty(fh)
            fh = figure('Renderer', 'painters', 'Position', [ fp.x0Fig, fp.y0Fig, fp.wFig/2, fp.hFig ]);
        end
        if (nargin < 2) || isempty(axh)
            axh = axes('Position', [2.5*fp.lMargin,fp.bMargin,1.9*fp.wAx,0.9*fp.hAx]);
        end
        th = plotScatterCorr_internal(axh,xp,yp,xc,yc,xLabel,yLabel,legValues,plotTitle,fp,1,['Location','northeast',legendProperties],ignoreOutliersX,ignoreOutliersY,txtParPrecision,txtParFontSize);
    end
end

function th = plotScatterCorr_internal(axh,xp,yp,xc,yc,xLabel,yLabel,legValues,plotTitle,fp,showLegend,legProp,ignoreOutliersX,ignoreOutliersY,txtParPrecision,txtParFontSize)
    if all(yc==yc(1)) || all(xc==xc(1))
        xc = [];
        yc = [];
    end
    txtc = '';
    txtc_pval = '';
    if ~isempty(xc)
        ind = isnan(xc(:)) | isnan(yc(:));
        xc(ind) = [];
        yc(ind) = [];
        if ~(isempty(xc) || isempty(yc))
            fitc = fit(xc(:),yc(:),'poly1');
            [ccc,pval_c] = corrcoef(xc(:),yc(:));
            txtc = ['R_c=',sprintf(txtParPrecision,ccc(1,2))];
            legValues{3} = [legValues{3},'; ',txtc,' (p=',num2str(pval_c(1,2),txtParPrecision),')'];
            txtc_pval = ['P_c=',sprintf(txtParPrecision,pval_c(1,2))];
        end
    end
    ind = isnan(xp(:)) | isnan(yp(:));
    xp(ind) = [];
    yp(ind) = [];
    
    xp_out = [];
    xc_out = [];
    yp_out = [];
    yc_out = [];

    if ignoreOutliersX
        [~,ind_xp] = getOutliers(xp);
        [~,ind_xc] = getOutliers(xc);
    else
        ind_xp = false(size(xp));
        ind_xc = false(size(xc));
    end
    if ignoreOutliersY
        [~,ind_yp] = getOutliers(yp);
        [~,ind_yc] = getOutliers(yc);
        xp_out = xp(ind_yp | ind_xp);
        yp_out = yp(ind_yp | ind_xp);
        xp(ind_yp | ind_xp) = [];
        yp(ind_yp | ind_xp) = [];
        if ~isempty(xc)
            xc_out = xc(ind_yc | ind_xc);
            yc_out = yc(ind_yc | ind_xc);
            xc(ind_yc | ind_xc) = [];
            yc(ind_yc | ind_xc) = [];
        end
    end
    
    fitp = fit(xp(:),yp(:),'poly1');
    [ccp,pval_p] = corrcoef(xp(:),yp(:));
    txtp = ['R_p=',sprintf(txtParPrecision,ccp(1,2))];
    legValues{4} = [legValues{4},'; ',txtp,' (p=',num2str(pval_p(1,2),txtParPrecision),')'];
    txtp_pval = ['P_p=',sprintf(txtParPrecision,pval_p(1,2))];
    
    xLim = minmax([xc(:)',xp(:)']);
    xLimFit = xLim;
    xLimFit(1) = xLim(1)-0.2*diff(xLim);
    xLimFit(2) = xLim(2)+0.2*diff(xLim);
    xLim(1) = xLim(1)-0.05*diff(xLim);
    xLim(2) = xLim(2)+0.05*diff(xLim);
    if xLim(1) == xLim(2)
        xLim = xLim + [-0.5,0.5];
    end
    
    if isempty(xc)
        legValues = legValues([2,4]);
        x1 = { xp, xLimFit };
        y1 = { yp, fitp(xLimFit) };
        showLegend = [1,0];
        lineSt = {'n','-'};
        symbSt = [fp.pSymbols(2),'n'];
        lineCol = [fp.pColors(2,:);fp.pColors(10,:)];
        if ~isempty(xp_out)
            legValues = [legValues,'Outliers'];
            x1 = [ x1, xp_out ];
            y1 = [ y1, yp_out ];
            showLegend = [showLegend,0];
            lineSt = [lineSt,'n'];
            symbSt = [symbSt,'+'];%[symbSt,symbSt(1)];
            lineCol = [lineCol;lineCol(1,:)];
        end
    else
        x1 = { xc, xp, xLimFit, xLimFit };
        y1 = { yc, yp, fitc(xLimFit), fitp(xLimFit) };
        showLegend = [repeatToComplete(showLegend,2),0,0];
        lineSt = {'n','n','-','-'};
        symbSt = [fp.pSymbols(1:2),'nn'];
        lineCol = [fp.pColors(1:2,:);fp.pColors(9:10,:)];
        if ~isempty(xc_out)
            x1 = [x1,xc_out];
            y1 = [y1,yc_out];
            showLegend = [showLegend,0];
            lineSt = [lineSt,'n'];
            symbSt = [symbSt,'+'];
            lineCol = [lineCol;lineCol(1,:)];
            legValues = [legValues,'Outliers'];
        end
        if ~isempty(xp_out)
            x1 = [x1,xp_out];
            y1 = [y1,yp_out];
            showLegend = [showLegend,0];
            lineSt = [lineSt,'n'];
            symbSt = [symbSt,'+'];
            lineCol = [lineCol;lineCol(2,:)];
            legValues = [legValues,'Outliers'];
        end
    end
    nn = numel(x1);
    ps1 = getPlotStruct(x1, y1, cell(1,nn), xLabel, yLabel, 'linear', 'linear', '', legValues, showLegend, plotTitle);
    plotPlotStruct(axh, ps1, lineSt, [], symbSt, lineCol, ...
            {'LineWidth', 0.5, 'MarkerSize', 4},... % plot properties
            {'ShowErrorBar', 'on', 'LineWidth', 1, 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
            {'FontSize', 8, 'Box', 'on', 'Layer', 'top', 'XLim', xLim},... % axis properties
            ['FontSize', 8, 'Box', 'off', legProp],... % legend properties
            {'FontSize', 11},... % label properties
            {'FontWeight','normal','FontSize',11}); % title properties
%     axUn = axh.Units;
%     axh.Units = 'points';
    if isempty(txtc)
        th = gobjects(1,2);
        th(1)=text(axh.XLim(1),axh.YLim(1),txtp,'FontSize',txtParFontSize,'Color',fp.pColors(2,:));
        th(1).Units = 'points';
        th(1).Position(1:2) = [4,25];
        drawnow
        th(1).Units = 'data';
        th(2)=text(axh.XLim(1),axh.YLim(1),txtp_pval,'FontSize',txtParFontSize,'Color',fp.pColors(2,:));
        th(2).Units = 'points';
        th(2).Position(1:2) = [4,10];
        drawnow
        th(2).Units = 'data';
    else
        th = gobjects(1,2);
        th(1)=text(axh.XLim(1),axh.YLim(1),[txtc,'; '],'FontSize',txtParFontSize,'Color',fp.pColors(1,:));
        th(1).Units = 'points';
        th(1).Position(1:2) = [4,25];
        drawnow
        th(1).Units = 'data';
        th(2)=text(th(1).Extent(1)+th(1).Extent(3),th(1).Extent(2)+th(1).Extent(4)/2,txtp,'FontSize',txtParFontSize,'Color',fp.pColors(2,:));
        th(3)=text(axh.XLim(1),axh.YLim(1),[txtc_pval,'; '],'FontSize',txtParFontSize,'Color',fp.pColors(1,:));
        th(3).Units = 'points';
        th(3).Position(1:2) = [4,10];
        drawnow
        th(3).Units = 'data';
        th(4)=text(th(3).Extent(1)+th(3).Extent(3),th(3).Extent(2)+th(3).Extent(4)/2,txtp_pval,'FontSize',txtParFontSize,'Color',fp.pColors(2,:));
    end
%     axh.Units = axUn;
end