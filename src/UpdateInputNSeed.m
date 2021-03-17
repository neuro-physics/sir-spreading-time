function [Isyn,kMax] = UpdateInputNSeed(i, nodes)
    %Isyn = zeros(1,nodes(i).par.nInp);
    IsynM = 0.0;
    kMax = 1;
    IsynAnt = -Inf;
    Isyn = IsynM;
    for k = 1:nodes(i).par.nInp
        % summing up contribution of color k
        IsynM = 0.0;
        for j = 1:nodes(i).par.n
            IsynM = IsynM + nodes(i).w(j) .* (nodes(nodes(i).neigh(j)).x == k);
        end
        
        % selecting color of largest contribution
        if IsynM > IsynAnt
            kMax = k;
            Isyn = IsynM;
        elseif IsynM == IsynAnt
            if rand > 0.5
                kMax = k;
                Isyn = IsynM;
            end
        end
        IsynAnt = IsynM;
    end
end
