function k = getColorIndex(values, nColors, mm)
    if (nargin < 3) || isempty(mm)
        mm = minmax(values(:)');
    end
    dy = nColors-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    k = round(a.*values+b)+1;
    k(k<1) = 1;
    k(k>nColors) = nColors;
end