function [x,spTime] = SINElementIter(i,nodes)%(x, par)
    x = nodes(i).x;
    spTime = nodes(i).par.spTime;
    if (x == 0) && ((nodes(i).par.Iext + nodes(i).par.Isyn / nodes(i).par.W) > nodes(i).par.Theta)
        x = nodes(i).par.kInp; % changing to state k (which was set by UpdateInputNSeed function)
        spTime = calcSpTime(i,nodes,x);
    end
end