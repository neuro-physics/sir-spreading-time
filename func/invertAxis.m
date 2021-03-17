function ax=invertAxis(ax,onlyCurves)
    if (nargin < 2) || isempty(onlyCurves)
        onlyCurves = false;
    end
    if ~onlyCurves
        xLim = ax.XLim;
        yLim = ax.YLim;
        xLabel = ax.XLabel;
        yLabel = ax.YLabel;
        xTickMode = ax.XTickMode;
        xTick = ax.XTick;
        xTickLabelMode = ax.XTickLabelMode;
        xTickLabel = ax.XTickLabel;
        yTickMode = ax.YTickMode;
        yTick = ax.YTick;
        yTickLabelMode = ax.YTickLabelMode;
        yTickLabel = ax.YTickLabel;
        set(ax,'XLim',yLim,'YLim',xLim,'XLabel',yLabel,'YLabel',xLabel);
        if any(~strcmpi({xTickMode,xTickLabelMode,yTickMode,yTickLabelMode},'auto'))
            set(ax,'XTick',yTick,'YTick',xTick,'XTickLabel',yTickLabel,'YTickLabel',xTickLabel);
        end
        drawnow
    end
    c = allchild(ax);
    for i = 1:numel(c)
        xData = c(i).XData;
        yData = c(i).YData;
        set(c(i),'XData',yData,'YData',xData);
        drawnow
    end
end