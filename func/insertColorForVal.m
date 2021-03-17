function c = insertColorForVal(x0,x,c0,cMapMinus,cMapPlus,func,cLim,nC)
    if (nargin < 4) || isempty(cMapMinus)
        cMapMinus = @winter;
    end
    if (nargin < 5) || isempty(cMapPlus)
        cMapPlus = @(x)flipud(autumn(x));
    end
    if (nargin < 6) || isempty(func)
        func = @ceil;
    end
    if (nargin < 7) || isempty(cLim)
        cLim = minmax(x(:)');
    end
    if (nargin < 8) || isempty(nC)
        nC = numel(unique(x(:)));
    end
    if mod(nC,2) ~= 1
        nC = nC + 1;
    end
    k = getColorIndex(x0, nC, cLim, func);
    c = [getColors(cMapMinus,k-1);c0;getColors(cMapPlus,nC-k-1)];
end

function c = getColors(arr,n)
    if isa(arr,'function_handle')
        c = arr(n);
    else
        c = arr(1:n,:);
    end
end

function k = getColorIndex(xx, nColors, mm, func)
    dy = nColors-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    k = func(a.*xx+b);
    if k < 1
        k = 1;
    end
    if k > nColors
        k = nColors;
    end
end