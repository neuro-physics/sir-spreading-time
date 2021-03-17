function [x,spTime] = SIElementIter(i,nodes)%(x, par)
%     if (par.Iext + par.Isyn / par.W) > par.Theta
%         x = 1;
%         spTime = calcSpTime(i,nodes);
%     end
    x = nodes(i).x;
    spTime = nodes(i).par.spTime;
    if (x == 0) && ((nodes(i).par.Iext + nodes(i).par.Isyn / nodes(i).par.W) > nodes(i).par.Theta)
        x = 1;
        spTime = calcSpTime(i,nodes,x);
    end
end