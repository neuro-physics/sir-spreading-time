function C = correctContourBorder(c)
    if numel(c) > 1
        C = c;
        for i = 1:numel(c)
            C(i) = correctContourBorder_internal(c(i));
        end
    else
        C = correctContourBorder_internal(c);
    end
end

function C = correctContourBorder_internal(c)
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
