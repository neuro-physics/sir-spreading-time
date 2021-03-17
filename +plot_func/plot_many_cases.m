function [lh,ax,fh] = plot_many_cases(ax,X,Y,caseColors,plotArgs)
% plots each line of X vs each line of Y with the corresponding color in caseColors matrix
    n = size(X,1);
    if isempty(ax)
        fh = figure;
        ax = axes;
    else
        fh = gcf;
    end
    if (nargin < 4) || isempty(caseColors)
        caseColors = copper(n);
    end
    if (nargin < 5) || isempty(plotArgs)
        plotArgs = {};
    end
    hold(ax,'on');
    lh = gobjects(1,n);
    for i = 1:n
        lh(i) = plot(ax,X(i,:),Y(i,:),'.','Color',caseColors(i,:),plotArgs{:});
    end
end