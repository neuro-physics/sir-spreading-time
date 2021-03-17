function psp = getPlotStructProperties(lineSet, widthSet, symbolSet, colorSet, plotArgs, errArgs, axisArgs, legendArgs, labelArgs, titleArgs)
    if nargin < 1
        lineSet = [];
    end
    if nargin < 2
        widthSet = [];
    end
    if nargin < 3
        symbolSet = [];
    end
    if nargin < 4
        colorSet = [];
    end
    if nargin < 5
        plotArgs = [];
    end
    if nargin < 6
        errArgs = [];
    end
    if nargin < 7
        axisArgs = [];
    end
    if nargin < 8
        legendArgs = [];
    end
    if nargin < 9
        labelArgs = [];
    end
    if nargin < 10
        titleArgs = [];
    end
    psp.lineSet = lineSet;
    psp.widthSet = widthSet;
    psp.symbolSet = symbolSet;
    psp.colorSet = colorSet;
    psp.plotArgs = plotArgs;
    psp.errArgs = errArgs;
    psp.axisArgs = axisArgs;
    psp.legendArgs = legendArgs;
    psp.labelArgs = labelArgs;
    psp.titleArgs = titleArgs;
end
