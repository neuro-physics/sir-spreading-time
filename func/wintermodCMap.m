function c = wintermodCMap(N,p)
    % p : fraction of lighter colors to ignore
    cc = winter(2);
    c = interp1([0,1],cc,linspace(0,1-p,N));
end