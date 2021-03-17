function c = greenYellowPinkCMap(N)

    if nargin < 1
       f = get(groot,'CurrentFigure');
       if isempty(f)
          N = size(get(groot,'DefaultFigureColormap'),1);
       else
          N = size(f.Colormap,1);
       end
    end

    %T = hex2rgb({'#8dd3c7','#ffffb3','#bebada','#fb8072','#80b1d3','#fdb462','#b3de69','#fccde5','#d9d9d9','#bc80bd','#ccebc5','#ffed6f'});
    T = [ 87,227,147;...
         208,223, 38;...
         220,  9,133]./255;
    nBase = size(T,1);
    if N <= nBase
        c = T(1:N,:);
        return;
    end
    x = round(linspace(0,N,nBase));
    c = interp1(x./N,T,linspace(0,1,N));
end
