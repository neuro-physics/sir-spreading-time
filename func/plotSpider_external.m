function [fh,axh,lh] = plotSpider_external(fh,axh,D,DSD,DLegend,lineSet,symbolSet,panelLabels,axLabel,plotArgs,axArgs,legArgs,panelLabelArgs,hTrend,hFDR,dr,dtheta,trendFDRSymbols)
% creates spider plot
%
% D(:,curves) -> data matrix; each column is a different curve
% DLegend{curves} -> legend for each curve
% plotTitle -> title of the plot
% axLabel -> label for each axes of the spider plot
% plotArgs -> additional plot arguments polarplot(...,plotArgs{:})
% axArgs -> additional axes arguments set(axh,axArgs{:})
% legArgs -> additional legend arguments legend(...,legArgs{:})
%
    if (nargin < 1) || isempty(fh)
        fh = figure;
    else
        figure(fh);
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    else
        axes(axh);
    end
    if (nargin < 3) || isempty(D)
        error('Data matrix cannot be empty');
    end
    if (nargin < 4)
        DSD = [];
    end
    [nTheta,nC] = size(D);
    if (nargin < 5) || isempty(DLegend)
        DLegend = {};
    end
    if (nargin < 6) || isempty(lineSet)
        lineSet = {'-'};
    end
    if (nargin < 7) || isempty(symbolSet)
        symbolSet = 'n';
    end
    if (nargin < 8) || isempty(panelLabels)
        panelLabels = '';
    end
    if (nargin < 9) || isempty(axLabel)
        axLabel = cellfun(@(x)['Label ',num2str(x)],num2cell(1:nTheta),'UniformOutput',false);
    end
    if (nargin < 10) || isempty(plotArgs)
        plotArgs = {};
    end
    if (nargin < 11) || isempty(axArgs)
        axArgs = {};
    end
    if (nargin < 12) || isempty(legArgs)
        legArgs = {};
    end
    if (nargin < 13) || isempty(panelLabelArgs)
        panelLabelArgs = {};
    end
    if (nargin < 14) || isempty(hTrend)
        hTrend = [];
    end
    if (nargin < 15) || isempty(hFDR)
        hFDR = [];
    end
    if (nargin < 16) || isempty(dr)
        dr = diff(minmax(D(:)')).*0.05;
    end
    if (nargin < 17) || isempty(dtheta)
        dtheta = 5*pi/180;
    end
    if (nargin < 18) || isempty(trendFDRSymbols)
        trendFDRSymbols = '+*';
    end
    
    % setting default param values
    if numel(DLegend) > nC
        DLegend = DLegend(1:nC);
    end
    if numel(axLabel) > nTheta
        axLabel = axLabel(1:nTheta);
    end

    hasSD = ~isempty(DSD) && any(DSD(:)~=0);
    getLineSt = @(ii)getPLine(ii,lineSet);
    getSymbol = @(ii)getPSymbol(ii,symbolSet);
    %fill_between_lines = @(X,Y1,Y2,C) fill( [X(:)' fliplr(X(:)')],  [Y1(:)' fliplr(Y2(:)')], C, 'EdgeColor', 'none');

    [newCMapTop,plotArgs] = getParamValue('AddColorTop',plotArgs,true);
    [newCMapBottom,plotArgs] = getParamValue('AddColorBottom',plotArgs,true);
    [errFaceAlpha,plotArgs] = getParamValue('ErrorFaceAlpha',plotArgs,true);
    [lineWidth,plotArgs] = getParamValue('LineWidth',plotArgs,true);
    if isempty(lineWidth)
        lineWidth = 1.5;
    end

    [markerFaceColor,plotArgs] = getParamValue('MarkerFaceColor',plotArgs,true);
    if isempty(markerFaceColor)
        markerFaceColor = 'none';
    end
    isAutoMarkerFaceColor = strcmpi(markerFaceColor,'auto');
    %theta = linspace(0,2*pi,nTheta+1)' + pi/nTheta;
    %thetaCurves = repmat(theta,1,nC);
    %rhoCurves = [D;D(1,:)];
    %lh = polarplot(axh,thetaCurves,rhoCurves,'LineWidth',1.5,plotArgs{:});
    %set(axh,'ThetaTick',theta(1:(end-1)).*180/pi,'ThetaTickLabel',axLabel,'ThetaGrid','off',...
    %        'RAxisLocation',0,...
    %        'GridColor',0.1.*ones(1,3),'GridLineStyle',':','GridAlpha',0.6,...
    %        'FontSize',11,'Box','off',axArgs{:});
    %[lh,sdh,sdlh1,sdlh2] = spider_plot(P, PSD, P_labels, axes_interval, plotArgs, sdPlotArgs, radLabArgs, axLabelArgs)
    [lh,sdh,~,~,ltrend,lfdr] = spider_plot(D,DSD,axLabel,[],plotArgs,{},axArgs,axArgs, hTrend, hFDR, trendFDRSymbols, dr, dtheta);
    cMap = [newCMapTop;myColorMap(nC);newCMapBottom];
    for i = 1:nC
        if isAutoMarkerFaceColor
            mfc = cMap(i,:);
        else
            mfc = markerFaceColor;
        end
        set(lh(i), 'LineStyle', getLineSt(i), 'Color', cMap(i,:), 'Marker', getSymbol(i), 'MarkerFaceColor', mfc, 'LineWidth', lineWidth);
        if isa(ltrend,'matlab.graphics.chart.primitive.Line')
            set(ltrend(i),'Color',cMap(i,:),'MarkerSize',5);
        end
        if isa(lfdr,'matlab.graphics.chart.primitive.Line')
            set(lfdr(i),'Color',cMap(i,:),'MarkerSize',5);
        end
        if hasSD
            sdh(i).FaceColor = cMap(i,:);
            if ~isempty(errFaceAlpha)
                sdh(i).FaceAlpha = errFaceAlpha;
            end
        end
    end
    %lhr = createRadialLines(axh,theta(1:(end-1)),axh.RLim,'-',[axh.GridColor,axh.GridAlpha]);
    if ~isempty(DLegend)
        legend(axh,DLegend,'FontSize',9,'Box','on','Location','northwestoutside',legArgs{:});
    end
    if ~isempty(panelLabels)
        [titleLocation,panelLabelArgs] = getParamValue('Location',panelLabelArgs,true);
        th=title(panelLabels,'FontSize',14,'FontWeight','normal',panelLabelArgs{:});
        if strcmpi(titleLocation,'bottom')
            th.Position(2) = -th.Position(2);
            th.Units = 'points';
            th.Position(2) = th.Position(2) - 2*th.FontSize;
            th.Units = 'data';
        end
    end
    %uistack(lhr,'bottom');
end

function lh = createRadialLines(axh,theta,rlim,ls,lc)
    lh = gobjects(1,numel(theta));
    for i = 1:numel(theta)
        lh(i) = line(axh,[theta(i),theta(i)],rlim,'LineStyle',ls,'Color',lc,'HandleVisibility','off');
    end
end

function c = myColorMap(N)
    T = hex2rgb({'#33a02c','#6a3d9a','#e31a1c','#1f78b4','#ff7f00','#b15928','#b2df8a','#a6cee3','#fb9a99','#fdbf6f','#cab2d6','#ffff99'});
    nBase = size(T,1);
    if N <= nBase
        c = T(1:N,:);
        return;
    end
    x = round(linspace(0,N,nBase));
    c = interp1(x./N,T,linspace(0,1,N));
end

function s = getPLine(ii, lineSet)
    s = lineSet{int32(mod(int32(ii)-1,numel(lineSet)))+1};
    if ((strcmp(s,'n')) || (strcmp(s,'none')))
        s = '';
    end
end

function s = getPSymbol(ii, symbolSet)
    s = symbolSet(int32(mod(int32(ii)-1,numel(symbolSet)))+1);
    if ((strcmp(s,'n')) || (strcmp(s,'none')))
        s = 'none';
    end
end

function [v,parList] = getParamValue(parName,parList,delParFromList)
    if (nargin < 3) || isempty(delParFromList)
        delParFromList = false;
    end
    k = find(strcmpi(parList,parName));
    if isempty(k)
        v = [];
        return;
    end
    if k == numel(parList)
        error(['missing parameter value for ', parName]);
    end
    v = parList{k+1};
    if delParFromList
        parList(k:(k+1)) = [];
    end
end