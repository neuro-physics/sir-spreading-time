function c = greenPinkCMap(N)
    T = [ 137   214   170;
          217    0    127 ]./255;
    nBase = size(T,1);
    if N <= nBase
        c = T(1:N,:);
        return;
    end
    x = round(linspace(0,N,nBase));
    c = interp1(x./N,T,linspace(0,1,N));
end