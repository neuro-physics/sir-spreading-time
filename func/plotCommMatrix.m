function [fh,axh,ih,axp0,axp1,cb,pData,pDataCensored] = plotCommMatrix(si,dataInd,ttestLabel,commLabels,tThresh,dataTitle,matrixView,showDataColor,effSizeLabel,useFDR_CohenThreshold,axisPos,showControlsOnly,showEffSizeDots)
    if (nargin < 7) || isempty(matrixView)
        matrixView = 'tril';
    end
    if (nargin < 11) || isempty(axisPos)
        axisPos = [];
    end
    if (nargin < 12) || isempty(showControlsOnly)
        showControlsOnly = false;
    end
    if (nargin < 13) || isempty(showEffSizeDots)
        showEffSizeDots = true;
    end
    if strcmpi(matrixView,'tril')
        getData = @(A)rot90(A,2);
        commLabels = fliplr(commLabels(:)');
    elseif strcmpi(matrixView,'triu')
        getData = @(A)A;
    else
        getData = @(A) (A+A')-eye(size(A,1)).*diag(A);
    end
    elemHighlight = getData(si.ttest.(ttestLabel)(dataInd).h);
    N_elem = size(elemHighlight,1);
    [T,tValues] = getTValuesThreshold(getData(si.ttest.(ttestLabel)(dataInd).t),tThresh,size(elemHighlight));
    if showControlsOnly
        pData = si.controlData.SZ{dataInd};
    else
        pData = si.patientData.SZ{dataInd} - si.controlData.SZ{dataInd};
    end
    if any(isnan(pData(:)))
        pData(isnan(pData)) = 0;
    end
    pData = getData(pData);
    cMap = jet;
    if showControlsOnly
        elemHighlight = ones(size(elemHighlight));
    else
        if isnumeric(showDataColor) && (showDataColor == 2)
            % show effect sizes
            cMap = greenYellowPinkCMap;
            pData = getData(si.ttest.SZ(dataInd).(effSizeLabel));%getData(abs(si.ttest.SZ(dataInd).(effSizeLabel)));
            if all(pData<=0)
                cMap = flipud(cMap);
            end
            elemHighlight((getData(si.ttest.(ttestLabel)(dataInd).hFDR)==1) & (abs(pData) > useFDR_CohenThreshold)) = 2;
            dataTitle = 'Effect size';
            if strcmpi(effSizeLabel,'Cohen_Mahal')
                dataTitle = [dataTitle,' (Cohen''s d)'];
                paramEffSz = 'd';
            else
                dataTitle = [dataTitle,' (SurfStat ef)'];
                paramEffSz = 'ef';
            end
        else
            elemHighlight((getData(si.ttest.(ttestLabel)(dataInd).hFDR)==1) & (tValues > T) & (abs(si.ttest.(ttestLabel)(dataInd).Cohen_Mahal) > 0.8)) = 2;
        end
    end
    highlightProp = {'o','MarkerSize',3,'Color',[0,0,0],'MarkerFaceColor',[0,0,0]};
    if ~showEffSizeDots
        highlightProp = {'skip'};
    end
    if strcmpi(matrixView,'tril')
        pData(triu(ones(N_elem),1)==1)=NaN;
    elseif strcmpi(matrixView,'triu')
        pData(tril(ones(N_elem),-1)==1)=NaN;
    end
    pDataCensored = pData;
    pDataCensored(~elemHighlight) = NaN;
    [fh,axh,ih,axp0,axp1,cb] = ...
        plotMatrix([],[],pData,matrixView,elemHighlight,[],cMap,...
        {'ShowColorBar','on','XTick',1:numel(commLabels),'YTick',1:numel(commLabels),'XTickLabel',commLabels,'YTickLabel',commLabels},[],...
            {{'skip'},highlightProp,'DarkenMatrix',true,'DarkenAlpha',1,'DarkenColor',0.9.*ones(1,3)},...
            {'Type','contour','Alpha',0.4,'LineStyle','-','LineWidth',0.8,'Color',0.01.*ones(1,3)},{'Label',dataTitle,'LabelProperties',{'FontSize',11}});
    if strcmpi(matrixView,'tril')
        cb.Position(1) = sum(axh.Position([1,3]))-cb.Position(3);
    else
        cb.Position(1) = axh.Position(1);
        cb.Position(2) = axh.Position(2);
    end
    if tThresh > 0
        appendCBarLabel(cb,[', |T|>',num2str(T)]);
    end
    if isnumeric(showDataColor) && (showDataColor == 2)
        appendCBarLabel(cb,[', |',paramEffSz,'|>',num2str(useFDR_CohenThreshold)]);
    else
        if ~showControlsOnly
            if numel(cb.Ticks) < 7
                cValues = linspace(cb.Limits(1),cb.Limits(2),7);
                cb.Ticks = cValues;
                cb.TickLabels = strtrim(cellstr(num2str(cValues','%.2g'))');
            end
            %cb.Ticks = [cb.Limits(1),cb.Ticks,cb.Limits(2)];
            cb.TickLabels{1}='same as controls';
            cb.TickLabels{2}='';
            cb.TickLabels{end}='slower in TLE';
            cb.TickLabels{end-1}='';
        end
    end
    drawnow
    if ~isempty(axisPos)
        ax = getChildrenAxes(fh);
        if numel(axisPos) == 1
            p = [ax(1).Position(1:2),axisPos,axisPos];
        elseif numel(axisPos) == 2
            p = [ax(1).Position(1:2),axisPos(:)'];
        else
            p = axisPos;
        end
        set(ax,'Position',p);
        drawnow
    end
end

function c = getChildrenAxes(h)
    c = h.Children;
    c = c(arrayfun(@(x)isa(x, 'matlab.graphics.axis.Axes'),c));
end

function [T,tValues] = getTValuesThreshold(tValues,tThresh,sz)
    if isempty(tValues)
        tValues = ones(sz);
        T = 0;
        return;
    else
        if iscell(tValues)
            T = cell(1,numel(tValues));
            for i = 1:numel(tValues)
                [T{i},tValues{i}] = getTValuesThreshold_internal(tValues{i},tThresh);
            end
        else
            [T,tValues] = getTValuesThreshold_internal(tValues,tThresh);
        end
    end
end

function [T,tValues] = getTValuesThreshold_internal(tValues,tThresh)
    tValues = abs(tValues);
    mmT = minmax(tValues(:)');
    T = mmT(1) + diff(mmT)*tThresh;
end