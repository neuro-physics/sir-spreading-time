function y = getCurveFromFit(xData,fitObj,nPoints,scale)
% xData -> x-data used to estimate fitObj
% fitObj -> result of function call to matlab function fit
    if (nargin < 3) || isempty(nPoints)
        nPoints = 100;
    end
    if (nargin < 4) || isempty(scale)
        scale = 'linear'; % 'linear' or 'log'
    end
    if strcmpi(scale,'linear')
        scFunc = @linspace;
    elseif strcmpi(scale,'log')
        scFunc = @logspace;
    else
        error('unknown scale parameter');
    end
    mm = minmax(reshape(xData,1,numel(xData)));
    y = fitObj(scFunc(mm(1),mm(2),nPoints));
end
