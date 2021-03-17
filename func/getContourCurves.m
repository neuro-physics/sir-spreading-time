function C = getContourCurves(CMat)
    C = getCurveStruct();
    k = 1;
    nP = size(CMat,2);
    while (k <= nP)
        clevel = CMat(1,k);
        n = CMat(2,k);
        x = CMat(1,(k+1):(k+n));
        y = CMat(2,(k+1):(k+n));
        C(end+1) = getCurveStruct(x,y,clevel);
        k = k + n + 1;
    end
    C(1) = [];
end

function C = getCurveStruct(x,y,clevel)
    C = struct('level',[],'x',[],'y',[]);
    if nargin == 0
        return;
    end
    C.level = clevel;
    C.x = x;
    C.y = y;
end
