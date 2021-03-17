function [fh,axh,cb1,cb2,labFile] = plotSpreadingTimeZScore(fh,axh,nodesPosOrDarkenMatrix,ZControl,ZPatient,ZTTest,colorArrPlus,colorArrMinus,...
                                            showColorBar,cBarLabel,axLabel,...
                                            plotType,sortInd,ptrnHighlightOrView,labelEdges,nodeLabels,labFile,ZTTest2,discretizeZScore)
    if (nargin < 7) || isempty(colorArrPlus)
        colorArrPlus = autumn;
    end
    if (nargin < 8) || isempty(colorArrMinus)
        colorArrMinus = winter;
    end
    if (nargin < 9) || isempty(showColorBar)
        showColorBar = true;
    end
    if (nargin < 10)
        cBarLabel = '';
    end
    if (nargin < 11)
        axLabel = '';
    end
    if (nargin < 12) || isempty(plotType)
        plotType = 'brain'; % or 'matrix'
    end
    if (nargin < 13)
        sortInd = []; % only used for plotType == 'matrix'
    end
    if (nargin < 14)
        ptrnHighlightOrView = [];
    end
    if (nargin < 15)
        labelEdges = []; % it can be empty, 'print', or 'file'
    end
    if (nargin < 16)
        nodeLabels = [];
    end
    if (nargin < 17)
        labFile = [];
    else
        labFile = CheckAndGetFileName(labFile);
    end
    if (nargin < 18)
        ZTTest2 = cell(size(ZTTest));
    end
    if (nargin < 19) || isempty(discretizeZScore)
        discretizeZScore = false;
    end
    isMatrix = 0;
    if strcmpi(plotType, 'brain')
        plotFunc = @plotBrainEdges;
    elseif strcmpi(plotType, 'matrix')
        plotFunc = @plotMatrixEdges;
        isMatrix = 1;
    else
        error('plotSpreadingTimeZScore:plotType','Unrecognized plotType parameter');
    end
    if iscell(ZControl) && (numel(ZControl)==1)
        ZControl = ZControl{1};
        if iscell(cBarLabel)
            cBarLabel = cBarLabel{1};
        end
        if iscell(axLabel)
            axLabel = axLabel{1};
        end
    end
    if iscell(ZPatient) && (numel(ZPatient)==1)
        ZPatient = ZPatient{1};
    end
    if iscell(ZTTest) && (numel(ZTTest)==1)
        ZTTest = ZTTest{1};
    end
    if iscell(ZTTest2) && (numel(ZTTest2)==1)
        ZTTest2 = ZTTest2{1};
    end
    if iscell(ZControl) && iscell(ZPatient) && iscell(ZTTest)
        if ~iscell(cBarLabel)
            cBarLabel = cellfun(@(x)cBarLabel,cell(size(ZControl)),'UniformOutput',false);
        end
        if iscell(axLabel)
            if any(size(ZControl) ~= size(axLabel))
                axLabel = cellfun(@(x)axLabel,cell(size(ZControl)),'UniformOutput',false);
            end
        else
            axLabel = cellfun(@(x)axLabel,cell(size(ZControl)),'UniformOutput',false);
        end
        fp = getDefaultFigureProperties();
        nAx = numel(ZControl);
        fp.wFig = fp.wFig * (nAx / 4);
        wFig = fp.wFig;
        fp.lMargin = fp.lMargin * (4 / nAx);
        lMargin = fp.lMargin;
        wAx = (1-lMargin)/nAx;%fp.wAx * (4 / nAx);
        isSagitalView = ischar(ptrnHighlightOrView) && strcmpi(ptrnHighlightOrView,'sagital');
        if isSagitalView
            wFig = 1.5.*fp.wFig;
            [isInsSc,~,scSize]=isInsideScreen([fp.x0Fig,fp.y0Fig,wFig,fp.hFig]);
            if ~isInsSc
                fp.x0Fig = -wFig + scSize(3);
            end
            lMargin = fp.lMargin / 2;
            wAx = (1-lMargin)/nAx;%fp.wAx * (4 / nAx);
        end
        fh = figure('Position', [fp.x0Fig,fp.y0Fig,wFig,fp.hFig]);
        axh = gobjects(size(ZControl));
        %axPos0 = [0,fp.bMargin,2*(fp.wAx+fp.lMargin)/4,fp.hAx];
        if isMatrix
            axPos0 = [(4/nAx)*lMargin/4,1.3*fp.bMargin,(wAx-lMargin/20),fp.hAx];
        else
            axPos0 = [lMargin/2,1.3*fp.bMargin,wAx,fp.hAx];
        end
        axPos = axPos0;
        n = numel(ZControl);
        cb1 = gobjects(1,n);
        cb2 = gobjects(1,n);
        for i = 1:n
%             axPos(1) = axPos0(1) + (i-1) * (axPos0(3)*(1-isSagital/2) + isMatrix .* lMargin/4);
            axPos(1) = axPos0(1) + (i-1) * (axPos0(3) + isMatrix .* (4/nAx) .* lMargin/4);
            axh(i) = axes('Position', axPos);
            [~,~,cb1(i),cb2(i),cMatrix] = plotFunc(fh,axh(i),nodesPosOrDarkenMatrix,ZControl{i},ZPatient{i},ZTTest{i},colorArrPlus,colorArrMinus,showColorBar,cBarLabel{i},axLabel{i},sortInd,ptrnHighlightOrView,ZTTest2{i},discretizeZScore);
            if ~isempty(labelEdges)
                writeEdgeLabels(labFile, labelEdges, getEdgeLabels(nodeLabels,ZTTest{i},cMatrix), [axLabel{i},'; ',cBarLabel{i}]);
            end
        end
        drawnow
    else
        if isempty(fh)
            fh = figure;
        else
            figure(fh);
        end
        if (nargin < 2) || isempty(axh)
            fp = getDefaultFigureProperties();
            axPos = [fp.lMargin,1.3*fp.bMargin,fp.wAx,fp.hAx];
            axh = axes('Position', axPos);
        end
        [fh,axh,cb1,cb2,cMatrix] = plotFunc(fh,axh,nodesPosOrDarkenMatrix,ZControl,ZPatient,ZTTest,colorArrPlus,colorArrMinus,showColorBar,...
                                            cBarLabel,axLabel,sortInd,ptrnHighlightOrView,ZTTest2,discretizeZScore);
        if ~isempty(labelEdges)
            writeEdgeLabels(labFile, labelEdges, getEdgeLabels(nodeLabels,ZTTest,cMatrix), [axLabel,'; ',cBarLabel]);
        end
        drawnow
    end
end

function p = getEdgeLabels(l, z, colorMatrix)%zMat)
%     zUpper = triu(zMat);
%     zLower = tril(zMat);
%     z = zUpper;
%     z((zUpper')~=zLower)
    zUpper = removeLowerEntries(z);
    [ii,jj] = find(zUpper);
    [ii,ind] = sort(ii);
    jj = jj(ind);
    n = numel(ii);
    p = ['    (n_edges = ', num2str(n),')\n'];
    for k = 1:n
        i = ii(k);
        j = jj(k);
        cyclicTxt = '';
        if (i < j)
            if z(j,i) ~= 0
                cyclicTxt = '; cyclic';
            end
        end
        p = [p, '    ', num2str(k),': ', l{i},' -> ',l{j}, '    (color: ',rgb2hex(reshape(colorMatrix(i,j,:),1,3)),cyclicTxt,')', '\n'];
    end
    p = p(1:(end-2));
end

function labFile = writeEdgeLabels(labFile, labelEdges, edgeLabels, edgeTitle)
    str = '---\n';
    str = [str, '* ', strrep(edgeTitle,'\',''), '\n'];
    str = [str, edgeLabels, '\n'];
    str = [str, '---\n'];
    if strcmpi(labelEdges, 'print')
        disp(sprintf(str));
    elseif strcmpi(labelEdges, 'file')
        fid = fopen(labFile, 'a');
        fprintf(fid, '%s', sprintf(str));
        fclose(fid);
    else
        error('plotSpreadingTimeZScore:writeEdgeLabels','unrecognized writing method');
    end
end

function y = linearTransf(x, X, Y)
    dy = Y(2) - Y(1);
    dx = X(2) - X(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = Y(1) - a.*X(1);
    y = round(a .* x + b);
end

function [fh,axh,cb1,cb2,colorMatrix] = plotMatrixEdges(fh,axh,darkenMatrix,ZControl,ZPatient,ZTTest,colorArrPlus,colorArrMinus,showColorBar,...
                                            cBarLabel,axLabel,sortInd,patternHighlight,ZTTest2,discretizeZScore)
    if isempty(sortInd)
        sortInd = 1:size(ZPatient,1);
    end
    if ~isempty(ZTTest2)
        ZTTest2(ZTTest ~= 0) = 0;
%         ZTTest2 = ZTTest2(sortInd,sortInd);
    end
    Zdiff = ZPatient - ZControl;
    
    ZTTest(1:(size(ZTTest,1)+1):end) = 0;
    ZTTest2(1:(size(ZTTest2,1)+1):end) = 0;
    Zdiff(1:(size(Zdiff,1)+1):end) = 0;
%     Zdiff = Zdiff(sortInd,sortInd);
%     ZTTest = ZTTest(sortInd,sortInd);
    if ~darkenMatrix
        Zdiff(ZTTest==0) = 0;
    end
    Zp = Zdiff;
    Zm = Zdiff;
    Zp(Zp<0) = 0;
    Zm(Zm>0) = 0;
    indP = Zp>0;
    zTemp = Zp(indP);
    mmP = minmax(zTemp(:)');
    indM = Zm < 0;
    zTemp = Zm(indM);
    mmM = minmax(zTemp(:)');
    cArr = [colorArrMinus;1,1,1;colorArrPlus];
    getMinusColor = @(x) linearTransf(x, mmM, [1,size(colorArrMinus,1)]);
    getPlusColor = @(x) linearTransf(x, mmP, [1,size(colorArrPlus,1)]) + (size(colorArrMinus,1) + 1);

    Z = ones(size(Zdiff)) .* (size(colorArrMinus,1) + 1);
    if discretizeZScore
%         cArr1=cArr;
        if any(indP(:))
            if ~isempty(ZTTest2)
                Z((ZTTest2~=0) & indP) = getPlusColor(mmP(1));
            end
            Z((ZTTest~=0) & indP) = getPlusColor(mmP(2));
%         else
%             cArr1 = cArr(1:(size(colorArrMinus,1)+1),:);
        end
        if any(indM(:))
            if ~isempty(ZTTest2)
                Z((ZTTest2~=0) & indM) = getMinusColor(mmM(2));
            end
            Z((ZTTest~=0) & indM) = getMinusColor(mmM(1));
%         else
%             cArr1 = cArr((size(colorArrMinus,1)+1):end,:);
        end
        cArr1=cArr(unique(Z(:)),:);
    else
        cArr1=cArr;
        if any(indP(:))
            Z(indP) = getPlusColor(Zp(indP));
        else
            cArr1 = cArr(1:(size(colorArrMinus,1)+1),:);
        end
        if any(indM(:))
            Z(indM) = getMinusColor(Zm(indM));
        else
            cArr1 = cArr((size(colorArrMinus,1)+1):end,:);
        end
    end
%     Z = Z(sortInd,sortInd);
%     ih = imagesc(axh, Z(sortInd,sortInd));
%     colormap(axh, cArr1);
%     axis(axh,'square');
    colorMatrix = getColorMatrix(ZTTest,Z,cArr);
    
    Z = Z(sortInd,sortInd);
    ZTTest = ZTTest(sortInd,sortInd);
    if ~isempty(ZTTest2)
        ZTTest2 = ZTTest2(sortInd,sortInd);
    end

%     elemHighlight = (ZTTest ~= 0) | (ZTTest2 ~= 0);
    elemHighlight = zeros(size(ZTTest));
    elemHighlight(ZTTest2 ~= 0) = 1;
    elemHighlight(ZTTest ~= 0) = 2;
%     if (elemHighlight(1) ~= 0) && all(elemHighlight(:) == elemHighlight(1))
    if all(elemHighlight(:) ~= 0)
        elemHighlight = zeros(size(ZTTest));
    end
    if ~any(any(elemHighlight))
        elemHighlight = zeros(size(ZTTest));
    end
    if all(all(Z==Z'))
        matrixView = 'triu';
    else
        matrixView = 'full';
    end
    
    % plotting matrix!
%     [~,~,~,axp0,axp1] = plotMatrix(fh,axh,Z,matrixView,elemHighlight,patternHighlight,cArr1,[],[],{{'s','MarkerSize',3,'MarkerFaceColor','none','Color','k'},{'s','MarkerSize',3,'MarkerFaceColor','none','Color','w'},'DarkenMatrix',true,'DarkenAlpha',0.8});
%     [~,~,~,axp0,axp1] = plotMatrix(fh,axh,Z,matrixView,elemHighlight,patternHighlight,cArr1,[],[],{{'skip'},{'s','MarkerSize',3,'MarkerFaceColor','none','Color',0.99.*ones(1,3)},'DarkenMatrix',darkenMatrix,'DarkenAlpha',1,'DarkenColor',0.9.*ones(1,3)});
    [~,~,~,axp0,axp1] = plotMatrix(fh,axh,Z,matrixView,elemHighlight,patternHighlight,cArr1,[],[],...
                        {{'skip'},{'s','MarkerSize',4,'MarkerFaceColor','none','Color',[0.4,0.6,0.2]},'DarkenMatrix',darkenMatrix,'DarkenAlpha',1,'DarkenColor',0.9.*ones(1,3)},...%{{'skip'},{'skip'},'DarkenMatrix',darkenMatrix,'DarkenAlpha',1,'DarkenColor',0.9.*ones(1,3)},...%
                        {'Type','contour','Alpha',0.4,'LineStyle','-','LineWidth',0.8,'Color',0.01.*ones(1,3)});

    if showColorBar
        ZpTemp = Zp(Zp>0);
        ZmTemp = Zm(Zm<0);
        if isempty(ZpTemp)
            mmP = [0,1];
        else
            mmP = minmax(ZpTemp(:)');
        end
        if isempty(ZmTemp)
            mmM = [-1,0];
        else
            mmM = minmax(ZmTemp(:)');
        end
        cb2 = createColorBar(fh, axh, colorArrPlus, mmP, cBarLabel);
        cb1 = createColorBar(fh, axh, colorArrMinus, mmM, '');
        cb2.Position(1) = cb1.Position(1) + cb1.Position(3);
        axes(axh);
        if darkenMatrix
            axes(axp0);
%             delete(axp0);
        end
        if ~isempty(patternHighlight)
            axes(axp1);
        end
    else
        cb2 = createColorBar(fh, axh);
        cb1 = createColorBar(fh, axh);
        cb2.Position(1) = cb1.Position(1) + cb1.Position(3);
    end
    if ~isempty(axLabel)
        hasDollar = strfind(axLabel,'$');
        if iscell(hasDollar)
            isLatex = any(cellfun(@(x)~isempty(x),hasDollar));
        else
            isLatex = ~isempty(hasDollar);
        end
        if isLatex
            txtInterpreter = 'latex';
        else
            txtInterpreter = 'tex';
        end
        txtW = cb1.Position(3) + cb2.Position(3);
        txtH = 2.2*cb1.Position(4);
        r = [cb1.Position(1),cb1.Position(2)+txtH,txtW,txtH];
        anh = annotation(fh, 'textbox', r, 'String', axLabel, 'Interpreter', txtInterpreter, 'FontSize', 10, 'EdgeColor', 'none', 'HorizontalAlignment', 'center');
%         cb1.Position(2) = cb1.Position(2) - anh.Position(4)*0.8;
%         cb2.Position(2) = cb2.Position(2) - anh.Position(4)*0.8;
    end
    axis(axh, 'off');
end

function [fh,axh,cb1,cb2,colorMatrix] = plotBrainEdges(fh,axh,nodesPos,ZControl,ZPatient,ZTTest,colorArrPlus,colorArrMinus,showColorBar,...
                                            cBarLabel,axLabel,sortInd,brainView,ZTTest2,discretizeZScore)
    hasZTTest2 = false;
    if ~isempty(ZTTest2)
        ZTTest2(ZTTest ~= 0) = 0;
        hasZTTest2 = ~isempty(ZTTest2) && any(any(ZTTest2));
    end
    Zdiff = ZPatient - ZControl;
    Zdiff(ZTTest==0) = 0;
    if discretizeZScore
        Ztemp = Zdiff(Zdiff>0);
        mmP = minmax(Ztemp(:)');
        Ztemp = Zdiff(Zdiff<0);
        mmM = minmax(Ztemp(:)');
        Zp = zeros(size(Zdiff));
        Zm = zeros(size(Zdiff));
        Zp(Zdiff>0) = mmP(2);
        Zm(Zdiff<0) = mmM(1);
        colorArrPlus = flipud(colorArrPlus);
    else
        Zp = Zdiff;
        Zm = Zdiff;
        Zp(Zp<0) = 0;
        Zm(Zm>0) = 0;
    end
    markerSize = 3;
    lightPos = [];
    if strcmpi(brainView,'sagital')
        lightPos = [1,1,1;-2,1,-0.5;1,-2,-0.5];
        markerSize = 4;
    end
    [fh, axh, cm1] = plotEdges(fh,axh,nodesPos,Zp, colorArrPlus,'continuous',{'Color','k','MarkerFaceColor','k','MarkerSize',markerSize},{'LineWidthLim',[2,2]},'constant', [], [0.95,0.95,0.95], false, lightPos); % plots brain surface
    [fh, axh, cm2] = plotEdges(fh,axh,nodesPos,Zm,colorArrMinus,'continuous',{'Color','k','MarkerFaceColor','k','MarkerSize',markerSize},{'LineWidthLim',[2,2]},'constant', false, [], true); % does not plot brain surface
    colorMatrix = cm2;
    colorMatrix(cm1~=0)=cm1(cm1~=0);
%     for k = 1:size(cm2,3)
%         [ii,jj] = find(cm2(:,:,k)~=0);
%         colorMatrix(ii,jj,k) = cm2(ii,jj,k);
%     end
    if hasZTTest2
        Zdiff2 = ZPatient - ZControl;
        Zdiff2(ZTTest2 == 0) = 0;
        if discretizeZScore
            Ztemp = Zdiff2(Zdiff2>0);
            mmP2 = minmax(Ztemp(:)');
            Ztemp = Zdiff2(Zdiff2<0);
            mmM2 = minmax(Ztemp(:)');
            Zp2 = zeros(size(Zdiff2));
            Zm2 = zeros(size(Zdiff2));
            Zp2(Zdiff2>0) = mmP2(1);
            Zm2(Zdiff2<0) = mmM2(2);
            colorArrPlus = flipud(colorArrPlus);
        else
            Zp2 = Zdiff2;
            Zm2 = Zdiff2;
            Zp2(Zp2<0) = 0;
            Zm2(Zm2>0) = 0;
        end
        colorArrPlus2 = rgb2hsv(colorArrPlus);colorArrPlus2(:,3) = colorArrPlus2(:,3) .* 0.8;colorArrPlus2 = hsv2rgb(colorArrPlus2);
        colorArrMinus2 = rgb2hsv(colorArrMinus);colorArrMinus2(:,3) = colorArrMinus2(:,3) .* 0.8;colorArrMinus2 = hsv2rgb(colorArrMinus2);
        [fh, axh] = plotEdges(fh,axh,nodesPos,Zp2,colorArrPlus2,'continuous',{'Color','k','MarkerFaceColor','k','MarkerSize',markerSize},{'LineWidthLim',[2,2],'EdgeAlpha',0.2},'constant', false, [], true); % does not plot brain surface
        [fh, axh] = plotEdges(fh,axh,nodesPos,Zm2,colorArrMinus2,'continuous',{'Color','k','MarkerFaceColor','k','MarkerSize',markerSize},{'LineWidthLim',[2,2],'EdgeAlpha',0.2},'constant', false, [], true); % does not plot brain surface
    end
    daspect(axh,[1,1,1]); fh.Color = 'w'; axis(axh,'tight');
    if strcmpi(brainView,'sagital')
        view(axh,[-90,0]);
    else
        view(axh,2);
    end
    if showColorBar
        ZpTemp = Zp(Zp>0);
        ZmTemp = Zm(Zm<0);
        if isempty(ZpTemp)
            mmP = [0,1];
        else
            mmP = minmax(ZpTemp(:)');
        end
        if isempty(ZmTemp)
            mmM = [-1,0];
        else
            mmM = minmax(ZmTemp(:)');
        end
        cb2 = createColorBar(fh, axh, colorArrPlus, mmP, cBarLabel);
        cb1 = createColorBar(fh, axh, colorArrMinus, mmM, '');
        cb2.Position(1) = cb1.Position(1) + cb1.Position(3);
        axes(axh);
    else
        cb2 = createColorBar(fh, axh);
        cb1 = createColorBar(fh, axh);
        cb2.Position(1) = cb1.Position(1) + cb1.Position(3);
    end
    if ~isempty(axLabel)
        hasDollar = strfind(axLabel,'$');
        if iscell(hasDollar)
            isLatex = any(cellfun(@(x)~isempty(x),hasDollar));
        else
            isLatex = ~isempty(hasDollar);
        end
        if isLatex
            txtInterpreter = 'latex';
        else
            txtInterpreter = 'tex';
        end
        txtW = cb1.Position(3) + cb2.Position(3);
        txtH = 2.2*cb1.Position(4);
        r = [cb1.Position(1),cb1.Position(2),txtW,txtH];
        anh = annotation(fh, 'textbox', r, 'String', axLabel, 'Interpreter', txtInterpreter, 'FontSize', 10, 'EdgeColor', 'none', 'HorizontalAlignment', 'center');
        cb1.Position(2) = cb1.Position(2) - anh.Position(4)*0.8;
        cb2.Position(2) = cb2.Position(2) - anh.Position(4)*0.8;
    end
    axis(axh, 'off');
end

function cb = createColorBar(fh, axh, cMap, cLim, barLabel, sameAxis)
    deleteObj = false;
    cLim = checkCLim(cLim);
    if (nargin < 3) % user just wants the position of colorbar
        deleteObj = true;
        cMap = [0,0,0;1,1,1];
        cLim = [0,1];
    end
    if (nargin < 5)
        barLabel = '';
    end
    if (nargin < 6) || isempty(sameAxis)
        sameAxis = false;
    end
    if sameAxis
        cb = createColorBar_internal(axh, cMap, cLim, barLabel);
    else
        axcb = copyobj(axh, fh);
        cla(axcb);
        cb = createColorBar_internal(axcb, cMap, cLim, barLabel);
        axis(axcb,'off');
        if deleteObj
            p = cb.Position;
            delete(cb);
            delete(axcb);
            cb = struct('Position',p);
        end
    end
end

function C = getColorMatrix(K,V,cArr)
    C = zeros(size(K,1),size(K,2),size(cArr,2));
    [rows,cols] = find(K);
    for k = 1:numel(rows)
        i = rows(k);
        j = cols(k);
        c = cArr(V(i,j),:);
        C(i,j,:) = reshape(c,1,1,numel(c));
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

function cb = createColorBar_internal(axh, cMap, cLim, barLabel)
    axh.CLim = cLim;
    colormap(axh, cMap);
    cb = colorbar(axh);
    cb.Limits = cLim;
    cb.Location = 'southoutside';
    cb.Units = 'pixels';
    cb.Position(3) = 75;
    cb.Position(4) = 7.5;
    cb.Units = 'normalized';
    cb.Position(1) = axh.Position(1) + axh.Position(3)*0.05;
    cb.Position(2) = cb.Position(2) - 4*cb.Position(4);
    if ~isempty(barLabel)
        cb.Label.String = barLabel;
        cb.Label.Interpreter = 'latex';
        cb.Label.FontSize = 11;
        cb.Label.Units = 'normalized';
        cb.Label.Position(1) = 0;
    end
end
