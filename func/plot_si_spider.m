function [fh,axh] = plot_si_spider(fh,axh,s,sSD,axLabel,panelLabels,plotTitle,legText,axLabelProp,colorsToAdd,errFaceAlpha,plotArgs,hTrend,hFDR,dr,dtheta,trendFDRSymbols)
    if (nargin < 7) || isempty(plotTitle)
        plotTitle = '';
    end
    if (nargin < 9) || isempty(axLabelProp)
        axLabelProp = {};
    end
    if (nargin < 10) || isempty(colorsToAdd)
        colorsToAdd = [];
    end
    if (nargin < 11) || isempty(errFaceAlpha)
        errFaceAlpha = [];
    end
    if (nargin < 12) || isempty(plotArgs)
        plotArgs = {};
    end
    if (nargin < 13) || isempty(hTrend)
        hTrend = [];
    end
    if (nargin < 14) || isempty(hFDR)
        hFDR = [];
    end
    if (nargin < 15) || isempty(dr)
        dr = [];
    end
    if (nargin < 16) || isempty(dtheta)
        dtheta = [];
    end
    if (nargin < 17) || isempty(trendFDRSymbols)
        trendFDRSymbols = '+*';
    end
    if iscell(s)
        if ~iscell(axLabel)
            axLabel = cellfun(@(x)axLabel,cell(size(s)),'UniformOutput',false);
        end
        if ~iscell(panelLabels)
            panelLabels = cellfun(@(x)panelLabels,cell(size(s)),'UniformOutput',false);
        end
        if ~iscell(sSD)
            sSD = cellfun(@(x)sSD,cell(size(s)),'UniformOutput',false);
        end
        legTextTemp = cell(size(s));
        legTextTemp{1} = legText;
        nPanels = numel(s);
        fp = getDefaultFigureProperties();
        %wFig = (1 + 7*fp.lMargin)*fp.wFig * (nPanels/4);
        fp.lMargin = (fp.lMargin/3) * (4/nPanels);
        wFig = fp.wFig * (nPanels/4) + fp.lMargin;% + (nPanels)*fp.lMargin*fp.wFig
        wAx = (1-fp.lMargin) / (nPanels) - fp.lMargin;% - 0.6*fp.lMargin;
        %wAx = (fp.wAx/2.2)*(4/nPanels);
        %x0Ax = (fp.wAx/2 + 0.5*fp.lMargin)*(4/nPanels);
        x0Ax = wAx + 1*fp.lMargin;
        fh = figure('Position',[fp.x0Fig,fp.y0Fig,wFig,fp.hFig]);
        axh = gobjects(1,nPanels);
        for i = 1:nPanels
            axh(i) = axes(fh,'Position',[(1*fp.lMargin + (i-1)*x0Ax),fp.bMargin,wAx,fp.hAx]);
            [~,axh(i)] = plot_si_spider_internal(fh,axh(i),s{i},sSD{i},axLabel{i},panelLabels{i},legTextTemp{i},axLabelProp,colorsToAdd,errFaceAlpha,plotArgs,hTrend{i},hFDR{i},dr,dtheta,trendFDRSymbols);
        end
    else
        if iscell(panelLabels)
            panelLabels = panelLabels{1};
        end
        [fh,axh] = plot_si_spider_internal(fh,axh,s,sSD,axLabel,panelLabels,legText,axLabelProp,colorsToAdd,errFaceAlpha,plotArgs,hTrend,hFDR,dr,dtheta,trendFDRSymbols);
    end
    anh = annotation('textbox',[0.5,1,0.3,1e-3],'String',plotTitle,'FitBoxToText','on','FontSize',11,'Units','normalized','EdgeColor','none');
    %anl = handle.addlistener(anh,'Position','PostSet',@thisCentralizeTitle);
    %anh.FitBoxToText = 'on';
    %waitfor(anh,'Position');
    pp = get(anh,'Position');
    pp(1) = pp(1) - pp(3)/2;
    set(anh,'Position',pp);
end

% function thisCentralizeTitle(src,evnt)
%     pp = get(src,'Position');
%     pp(1) = pp(1) - pp(3)/2;
%     set(src,'Position',pp);
% end

function [fh,axh] = plot_si_spider_internal(fh,axh,D,DSD,axLabel,panelLabels,legText,axLabelProp,colorsToAdd,errFaceAlpha,plotArgs,hTrend,hFDR,dr,dtheta,trendFDRSymbols)
    fp = getDefaultFigureProperties();
    if (nargin < 1) || isempty(fh)
        fh = figure('Position',[fp.x0Fig,fp.y0Fig,fp.wFig/2,fp.hFig]);
    else
        figure(fh);
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    else
        axes(axh);
    end

%     P = [sControl(:),...
%          sPatient(:)];
%     P = P';

    %axLim = repmat(minmax(P(:)'),size(P,1),1);
%     axLim = minmax(D(:)');
%     if all(axLim == zeros(size(axLim)))
%         axLim = [0,1];
%     end
    colorParValPair = {};
    if ~isempty(colorsToAdd)
        colorParValPair = {'AddColorTop', colorsToAdd};
    end
    errParValPair = {};
    if ~isempty(errFaceAlpha)
        errParValPair = {'ErrorFaceAlpha', errFaceAlpha};
    end
            %plotSpider(fh,axh,D,DSD,legText,[],'o',panelLabels,axLabel,{'MarkerFaceColor','auto','MarkerSize',3},['RLim',axLim,'FontSize',9,axLabelProp],{'Position',[0.0142 0.0472 0.1075 0.1217]},{'FontSize',11,'Location','bottom'});
    plotSpider_external(fh,axh,D,DSD,legText,[],'o',panelLabels,axLabel,['MarkerFaceColor','w','MarkerSize',5,'LineWidth',0.5,colorParValPair,errParValPair,plotArgs],['FontSize',9,axLabelProp],{'Position',[0,0.0472,0.1075,0.1217],'Box','off'},{'FontSize',11,'Location','bottom'},hTrend,hFDR,dr,dtheta,trendFDRSymbols);
%     spider_plot_seok(P,plotLabel,axLim,axLabel,{'Controls','TLE'},fh);

%     axes_interval = 2;
% 
%     % Spider plot
%     spider_plot(P, axLabel, axes_interval,...
%     'Marker', 'o',...
%     'LineStyle', '-',...
%     'LineWidth', 2,...
%     'MarkerSize', 5);
% 
%     % Title properties
%     title(plotLabel, 'FontWeight', 'normal', 'FontSize', 12);
% 
%     % Legend properties
%     legend({'Controls', 'TLE'}, 'Location', 'southoutside', 'Box', 'off');
end
