function [fh,axh,ih,axhdarken,axhpattern,cbh] = plotMatrix(fh,axh,A,matrixView,elemHighlight,patternHighlight,cMap,axProp,imgProp,elHighlightProp,ptrnHighlightProp,cbarProp)
    if (nargin < 1) || isempty(fh)
        fh = figure;
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    end
    if (nargin < 4) || isempty(matrixView)
        matrixView = 'full'; % 'triu' -> upper triangular; 'tril' -> lower triangular; 'full' -> complete matrix
    end
    if (nargin < 5)
        elemHighlight = [];
    end
    if (nargin < 6)
        patternHighlight = [];
    end
    if (nargin < 7)
        cMap = [];
    end
    if (nargin < 8)
        axProp = {};
        % contains property 'ShowColorBar' 'on' or 'off'
    end
    if (nargin < 9)
        imgProp = {};
    end
    if (nargin < 10) || isempty(elHighlightProp)
        elHighlightProp = {'s','MarkerSize',3,'MarkerFaceColor','none','Color','w','DarkenMatrix',true,'DarkenAlpha',0.8,'DarkenColor',[1,1,1]};
        % elHighlightProp can be
        %    - a cell with properties to 'plot' function
        %    - a cell of cells with properties to plot function, corresponding to each unique integer in elemHighlight matrix
        %      * this cell may contain 'DarkenMatrix', 'DarkenAlpha' and 'DarkenColor' properties besides each cell corresponding to the indices
        %      * empty inner cells correspond to default plot properties for highlighting
        %      * a cell containing 'skip' makes that unique integer of elemHighlight matrix not to be highlighted by symbols
    end
    if (nargin < 11) || isempty(ptrnHighlightProp)
        ptrnHighlightProp = {'Type','contour','Alpha',0.4,'LineStyle','-','LineWidth',0.8,'Color',0.99.*ones(1,3)}; % 'Type' == 'contour' or 'solid'
    end
    if (nargin < 12) || isempty(cbarProp)
        cbarProp = {'Label','data','LabelProperties',{}};
    end

    [showCBar,axProp] = getParamValue('ShowColorBar',axProp,true);
    if isempty(showCBar) || strcmpi(showCBar,'off') || strcmpi(showCBar,'none')
        showCBar = false;
    end

    axhdarken = gobjects(1,1);
    axhpattern = gobjects(1,1);
    % getting default values for variables
    elHighlightPropDefault = {'s','MarkerSize',3,'MarkerFaceColor','none','Color','w'};
    hasElemHighlight = ~isempty(elemHighlight) && any(elemHighlight(:));
    hasPatternHighlight = ~isempty(patternHighlight) && any(patternHighlight(:));
    if hasElemHighlight
        elemHighlight = elemHighlight'; % imagesc generates 'YDir' == 'reverse' in the axis
    end
    [darkenMatrix,elHighlightProp] = getParamValue('DarkenMatrix',elHighlightProp,true);
    if isempty(darkenMatrix)
        darkenMatrix = false;
    end
    [darkenAlpha,elHighlightProp] = getParamValue('DarkenAlpha',elHighlightProp,true);
    if isempty(darkenAlpha)
        darkenAlpha = false;
    end
    [darkenColor,elHighlightProp] = getParamValue('DarkenColor',elHighlightProp,true);
    if isempty(darkenColor)
        darkenColor = [0,0,0];
    else
        if ~(isvector(darkenColor) && isnumeric(darkenColor) && (numel(darkenColor) == 3))
            darkenColor = [0,0,0];
        end
    end
    [ptrnHighlightType,ptrnHighlightProp] = getParamValue('Type',ptrnHighlightProp,true);
    if isempty(ptrnHighlightType)
        ptrnHighlightType = 'contour';
    end
    [ptrnHighlightAlpha,ptrnHighlightProp] = getParamValue('Alpha',ptrnHighlightProp,true);
    if isempty(ptrnHighlightAlpha)
        ptrnHighlightAlpha = 0.4;
    end
    [ptrnHighlightLineStyle,ptrnHighlightProp] = getParamValue('LineStyle',ptrnHighlightProp,true);
    if isempty(ptrnHighlightLineStyle)
        ptrnHighlightLineStyle = '-w';
    end
    
    % defining plotting variables
    if strcmpi(matrixView,'triu')
        alphaMat = triu(ones(size(A)));
        matViewAxProp = { 'XAxisLocation', 'top', 'YAxisLocation', 'right', 'Box', 'off', 'Layer', 'top' };
        if hasElemHighlight
            elemHighlight = tril(elemHighlight);
        end
        getPtrnHighlight = @(x)triu(x);
    elseif strcmpi(matrixView,'tril')
        alphaMat = tril(ones(size(A)));
        matViewAxProp = { 'XAxisLocation', 'bottom', 'YAxisLocation', 'left', 'Box', 'off', 'Layer', 'top' };
        if hasElemHighlight
            elemHighlight = triu(elemHighlight);
        end
        getPtrnHighlight = @(x)tril(x);
    else
        alphaMat = ones(size(A));
        matViewAxProp = {'Layer', 'top'};
        getPtrnHighlight = @(x)x;
    end
%     sA = size(A);
%     [x,y] = meshgrid(1:sA(1),1:sA(2));
%     x = linearTransf_scal(x,[1,sA(2)],[0.5,sA(1)+0.5]);
%     y = linearTransf_scal(y,[1,sA(1)],[0.5,sA(2)+0.5]);
%     ih=pcolor(x,y,A);
%     set(ih,'FaceColor','texturemap','FaceAlpha','texturemap','AlphaDataMapping','none','AlphaData',alphaMat,'EdgeColor','none');

    % plotting matrix
    axes(axh);
    ih = imagesc(A,'AlphaData',alphaMat);
    
    % adjusting top layers
    %if hasElemHighlight && darkenMatrix
    if darkenMatrix
        axhdarken = createPatternHighlight_imagesc(fh,axh,getPtrnHighlight(~(elemHighlight')),darkenAlpha,[1,1,1;darkenColor(:)']); % transpose because elemHighlight has been transposed already
    end
    if hasPatternHighlight
        if strcmpi(ptrnHighlightType,'contour')
            axhpattern = createPatternHighlight_contour(fh,axh,getPtrnHighlight(patternHighlight),ptrnHighlightLineStyle,ptrnHighlightProp{:});
        elseif strcmpi(ptrnHighlightType,'solid')
            axhpattern = createPatternHighlight_imagesc(fh,axh,getPtrnHighlight(patternHighlight),ptrnHighlightAlpha,[0,0,0;1,1,1]);
        else
            error('unrecognized pattern highlight type: either solid or contour');
        end
    end
    if hasElemHighlight
        v = unique(elemHighlight(:));
        v(v==0) = [];
%         if numel(v) >= 2  % there's more than 0 and 1
        if (numel(elHighlightProp) ~= max(v))
            if all(cellfun(@iscell,elHighlightProp))
                elHighlightProp = cellfun(@(x)elHighlightProp{1},cell(1,numel(v)),'UniformOutput',false);
            else
                elHighlightProp = cellfun(@(x)elHighlightProp,cell(1,numel(v)),'UniformOutput',false);
            end
        end
        if darkenMatrix
            pAxh = axhdarken;
        elseif hasPatternHighlight
            pAxh = axhpattern;
        else
            pAxh = axh;
        end
%         end
        hold(pAxh,'on');
        for j = 1:numel(v)
            k = v(j);
            if isempty(elHighlightProp{k})
                ehp = elHighlightPropDefault;
            else
                if (numel(elHighlightProp{k}) == 1) && strcmpi(elHighlightProp{k}{1},'skip')
                    continue;
                else
                    ehp = elHighlightProp{k};
                end
            end
            [x,y] = find(elemHighlight == k);
            plot(pAxh,x,y,ehp{:});
        end
        hold(pAxh,'off');
    end
    if ~isempty(axProp)
        set(axh,axProp{:});
    end
    cbh = gobjects;
    if showCBar
        cbarLoc = 'southoutside';
        if strcmpi(matrixView,'tril')
            cbarLoc = 'northoutside';
        end
        cbpos = createColorBar(fh,axh);
        [cbarLabel,cbarProp] = getParamValue('Label',cbarProp,true);
        if isempty(cbarLabel)
            cbarLabel = 'data';
        end
        [cbarLabelProp,cbarProp] = getParamValue('LabelProperties',cbarProp,true);
        if isempty(cbarLabelProp)
            cbarLabelProp = {};
        end
        [cLim,cbarProp] = getParamValue('ColorLim',cbarProp,true);
        if isempty(cLim)
            cLim = minmax(A(:)');
        end
        cbh = createColorBar(fh, axh, cMap, cLim, cbarLabel, true, ['Position',cbpos.Position,'Location',cbarLoc,cbarProp],cbarLabelProp);
    end
    if ~isempty(imgProp)
        set(ih,imgProp{:});
    end
    set(axh,matViewAxProp{:});
    axis(axh,'square');
    if ~isempty(cMap)
        colormap(axh,cMap);
    end
    if hasElemHighlight && darkenMatrix
        axes(axhdarken);
    end
    if hasPatternHighlight
        axes(axhpattern);
    end
end

function a = createPatternHighlight_imagesc(fh,axh,p,alpha,cMap)
    a = copyobj(axh,fh);
    cla(a);
    axes(a);
    imagesc(p, 'AlphaData', alpha.*p);
%     h.AlphaData = 0.2.*p;
    colormap(a,cMap);
    axis(a, 'square');
    axis(a, 'off');
end

function a = createPatternHighlight_contour(fh,axh,p,lineStyle,varargin)
    a = copyobj(axh,fh);
    cla(a);
    plotPatternContour(fh,a,p,lineStyle,varargin{:});
    a.YDir = 'reverse';
    a.XLim = axh.XLim;
    a.YLim = axh.YLim;
%     imagesc(a, p, 'AlphaData', alpha.*p);
%     h.AlphaData = 0.2.*p;
%     colormap(a,cMap);
    axis(a, 'square');
    axis(a, 'off');
end

function Y = linearTransf_scal(X,xLim,yLim)
    if (nargin < 2) || isempty(xLim)
        xLim = minmax(X(:)');
    end
    b = diff(yLim) / diff(xLim);
    a = yLim(1) - b * xLim(1);
    Y = a + b.*X;
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

function cb = createColorBar(fh, axh, cMap, cLim, barLabel, sameAxis, cbarProp, labelProp)
    deleteObj = false;
    if (nargin < 3) % user just wants the position of colorbar
        deleteObj = true;
        cMap = [0,0,0;1,1,1];
        cLim = [0,1];
    end
    if (nargin < 4) || isempty(cLim)
        cLim = [0,1];
    end
    cLim = checkCLim(cLim);
    if (nargin < 5)
        barLabel = '';
    end
    if (nargin < 6) || isempty(sameAxis)
        sameAxis = false;
    end
    if (nargin < 7)
        cbarProp = [];
    end
    if (nargin < 8)
        labelProp = [];
    end
    if sameAxis
        cb = createColorBar_internal(axh, cMap, cLim, barLabel, cbarProp, labelProp);
    else
        axcb = copyobj(axh, fh);
        cla(axcb);
        cb = createColorBar_internal(axcb, cMap, cLim, barLabel, cbarProp, labelProp);
        axis(axcb,'off');
        if deleteObj
            p = cb.Position;
            delete(cb);
            delete(axcb);
            cb = struct('Position',p);
        end
    end
end

function cb = createColorBar_internal(axh, cMap, cLim, barLabel, cbarProp, labelProp)
    axh.CLim = cLim;
    if ~isempty(cMap)
        colormap(axh, cMap);
    end
    if isempty(cbarProp)
        cb = colorbar(axh);
        cb.Limits = cLim;
        cb.Location = 'northoutside';
        cb.Units = 'pixels';
        cb.Position(3) = 225;
        cb.Position(4) = 7.5;
        cb.Units = 'normalized';
        cb.Position(1) = axh.Position(1) + axh.Position(3)/2 - cb.Position(3)/2;
%         cb.Position(2) = cb.Position(2) - 5*cb.Position(4);
    else
        cb = colorbar(axh,cbarProp{:});
    end
    if ~isempty(barLabel)
        cb.Label.String = barLabel;
        cb.Label.Interpreter = 'tex';
        cb.Label.FontSize = 11;
        cb.Label.Units = 'normalized';
        if ~isempty(labelProp)
            set(cb.Label,labelProp{:});
        end
    end
end

function cLim = checkCLim(cLim)
    cLim(isinf(cLim)) = 0;
    if cLim(1) == cLim(2)
        if cLim(1) == 0
            cLim = [0,1];
        else
            cLim = sort([0,cLim(1)]);
        end
    end
end