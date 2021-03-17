function [ps,xTicks] = getMeanStdPlotStruct(ps1,varargin)
    xx = cell(size(ps1.curves));
    yy = cell(size(ps1.curves));
    yyErr = cell(size(ps1.curves));
    xTicks = zeros(size(ps1.curves));
    for i = 1:numel(ps1.curves)
        xTicks(i)=mean(ps1.curves(i).x);
        xx{i} = mean(ps1.curves(i).x);
        yy{i} = mean(ps1.curves(i).y);
        yyErr{i} = std(ps1.curves(i).y);
    end
    ps = getPlotStruct(xx,yy,yyErr,varargin{:});
end
