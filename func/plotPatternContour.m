function lh = plotPatternContour(fh,axh,p,lineStyle,varargin)
    if isempty(fh)
        fh = figure;
    end
    if isempty(axh)
        axh = axes;
    end
    if (nargin < 4) || isempty(lineStyle)
        lineStyle = '-k';
    end
    C = contourc(p,1);
    CC = correctContourBorder_internal(getContourCurves_internal(C));
    lh = gobjects(1,numel(CC));
    hold(axh,'on');
    for i = 1:numel(CC)
        lh(i) = plot(axh,CC(i).x,CC(i).y,lineStyle,varargin{:});
    end
    hold(axh,'off');
end

function C = getContourCurves_internal(CMat)
    C = getCurveStruct_internal();
    k = 1;
    nP = size(CMat,2);
    while (k <= nP)
        clevel = CMat(1,k);
        n = CMat(2,k);
        x = CMat(1,(k+1):(k+n));
        y = CMat(2,(k+1):(k+n));
        C(end+1) = getCurveStruct_internal(x,y,clevel);
        k = k + n + 1;
    end
    C(1) = [];
end

function C = getCurveStruct_internal(x,y,clevel)
    C = struct('level',[],'x',[],'y',[]);
    if nargin == 0
        return;
    end
    C.level = clevel;
    C.x = x;
    C.y = y;
end

function C = correctContourBorder_internal(c)
    if numel(c) > 1
        C = c;
        for i = 1:numel(c)
            C(i) = correctContourBorder_internal_2(c(i));
        end
    else
        C = correctContourBorder_internal_2(c);
    end
end

function C = correctContourBorder_internal_2(c)
% c is contour curve struct with properties
%   .level
%   .x
%   .y
%
% this function sharps the edges of the contour according to a very specific rule
    N = numel(c.x);
    dx = abs([NaN,diff(c.x(:)')]);
    dy = abs([NaN,diff(c.y(:)')]);
    C = c;
    C.x = [];
    C.y = [];
    nStart = 1;
    for i = 2:N
        if all(dx(i) ~= [0,1]) && all(dy(i) ~= [0,1])
            ind = nStart:(i-1);
            C.x((end+1):(end+numel(ind))) = c.x(ind);
            C.y((end+1):(end+numel(ind))) = c.y(ind);
            if dx(i-1) == 0
                C.x(i) = c.x(i-1);
                C.y(i) = c.y(i);
            else
                C.x(i) = c.x(i);
                C.y(i) = c.y(i-1);
            end
            nStart = i;
        end
    end
    ind = nStart:N;
    C.x((numel(C.x)+1):(numel(C.x)+numel(ind))) = c.x(ind);
    C.y((numel(C.y)+1):(numel(C.y)+numel(ind))) = c.y(ind);
end