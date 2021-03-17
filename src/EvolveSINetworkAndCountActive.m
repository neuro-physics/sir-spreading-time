function nn = EvolveSINetworkAndCountActive(nodes, tTotal)
    N = numel(nodes);
    for t = 1:tTotal
        for i = 1:N
            [nodes(i).par.Isyn,nodes(i).par.kInp] = UpdateInput1Seed(i, nodes);
        end
        %isNetActive = nodes(1).x > 0;
        isNetActive = true;
        for i = 1:N
            [nodes(i).x,~] = SIElementIter(i, nodes);%SIElementIter(nodes(i).x, nodes(i).par);
            isNetActive = isNetActive && (nodes(i).x > 0);
        end
        if isNetActive
            break;
        end
    end
    nn = 0;
    for i = 1:N
        if nodes(i).x > 0
            nn = nn + 1;
        end
    end
end
