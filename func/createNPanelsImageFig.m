function [fh,axh,imh] = createNPanelsImageFig(imgs, L, labels, titles, mainTitle, cMap, showCBar)
    if nargin < 2 || isempty(L)
        L = ceil(numel(ps)/2);
    end
    if nargin < 3 || isempty(labels)
        labels = cell(1,2);
    end
    if nargin < 4
        titles = [];
    end
    if nargin < 5
        mainTitle = [];
    end
    if nargin < 6
        cMap = [];
    end
    if nargin < 7 || isempty(showCBar)
        showCBar = false;
    end
    N = numel(imgs);
    R = ceil(N/L);
    panelW = 300; % px
    whRatio = 1.6;
    panelH = panelW / whRatio;
    x0Ax = 45; % px
    y0Ax = x0Ax; % px
    rMargin = x0Ax / 3;
    figTitleH = 0;
    if ~isempty(mainTitle)
        figTitleH = 45;
    end
    figW = L * (panelW + x0Ax) + rMargin;
    figH = R * (panelH + y0Ax) + figTitleH;
    if numel(showCBar) < N
        showCBar = repeatToComplete(showCBar, N);
    end

    fh = figure('Position', [400, 400, figW, figH]);
    for k = 1:N
        [i,j] = ind2sub(L, k);
        x = x0Ax + (i-1) * (panelW + x0Ax);
        y = figH - figTitleH - j * panelH - (j-1)*y0Ax;
        axh(k) = axes('Units', 'pixels', 'Position', [x,y,panelW,panelH]);
        %plotPlotStruct(axh(k), ps(i), psProp(i).lineSet, psProp(i).widthSet, psProp(i).symbolSet, psProp(i).colorSet, psProp(i).plotArgs, psProp(i).errArgs, psProp(i).axisArgs, psProp(i).legendArgs, psProp(i).labelArgs, psProp(i).titleArgs);
        imh(k) = imagesc(axh(k), imgs{k});
        axh(k).Units = 'normalized';
        axis(axh(k), 'square');
        if ~isempty(titles)
            if ~isempty(titles{k})
                title(titles{k});
            end
        end
        if ~isempty(labels)
            if j == R
                xlabel(axh(k), labels{1});
            end
            if i == 1
                ylabel(axh(k), labels{2});
            end
        end
        if ~isempty(cMap)
            colormap(cMap);
        end
        if showCBar(k)
            colorbar
        end
    end
    anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', mainTitle, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold', 'FontSize', 12);
    anh.Position(2) = figH - figTitleH / 5;
    anh.Units = 'normalized';
end
