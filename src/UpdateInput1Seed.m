function [Isyn,kMax] = UpdateInput1Seed(i, nodes)
    Isyn = 0.0; kMax = 1; %spTime = 0.0; nAct = 0; spTimePrev = 0.0;
    for j = 1:nodes(i).par.n
        Isyn = Isyn + nodes(i).w(j) .* nodes(nodes(i).neigh(j)).x;
    end
end
