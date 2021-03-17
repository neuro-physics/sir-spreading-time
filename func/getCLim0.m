function cl = getCLim0(c1,c2)
    cMax = max(c1,c2);
    cMin = min(c1,c2);
    cl = [cMin,cMax];
    if (sign(cMin) == sign(cMax)) && (cMax>0)
        cl(1) = 0;
    end
    if (sign(cMin) == sign(cMax)) && (cMax<0)
        cl(2) = 0;
    end
    if isempty(cl)
        cl = [0,1];
    elseif numel(cl) == 1
        cl = [min(0,cl),max(0,cl)];
    elseif cl(1) == cl(2)
        cl = [min(0,cl(1)),max(0,cl(1))];
    end
end