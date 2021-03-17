function spTime = calcSpTime(i,nodes,x)
    spTime = 0.0; nAct = 0; spTimePrev = 0.0;
    for j = 1:nodes(i).par.n
        spTime = spTime + double(nodes(nodes(i).neigh(j)).x == x) / nodes(i).w(j); % summing up the inverse weights (sp times) of active neighbors to reach i
        spTimePrev = spTimePrev + double(nodes(nodes(i).neigh(j)).x==x) * nodes(nodes(i).neigh(j)).par.spTime; % summing up the sp time to reach each of the active neighbors
        nAct = nAct + double(nodes(nodes(i).neigh(j)).x==x); % x is either 0 or 1, so nAct is the total amount of active neighbors of i
    end
    if (nAct == 0)
        nAct = 1;
    end
    spTime = (spTime + spTimePrev) / nAct;
end
