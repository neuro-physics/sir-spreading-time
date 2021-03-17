function [T,S] = SpreadNodeToNode(i, j, nodes, tTotal)
    T = 0.0;
    S = 0.0;
    if i == j
        return;
    end
    nodes(i).x = 1;
    N = numel(nodes);
    for t = 1:tTotal
%         for k = 1:(i-1)
%             [nodes(k).par.Isyn, nodes(k).par.kInp, nodes(k).par.spTime] = UpdateInput1Seed(k, nodes);
%         end
%         for k = (i+1):N
        for k = 1:N
            %nodes(i).par.spTime = 0.0; % forcing seed spTime == 0.0 so that it is not considered to calculate next spTime's
            %[nodes(k).par.Isyn, nodes(k).par.kInp, nodes(k).par.spTime] = UpdateInput1Seed(k, nodes);
            [nodes(k).par.Isyn, nodes(k).par.kInp] = UpdateInput1Seed(k, nodes);
        end
%         for k = 1:(i-1)
%             nodes(k).x = SIElementIter(nodes(k).x, nodes(k).par);
%         end
%         for k = (i+1):N
        for k = 1:N
            %nodes(k).x = SIElementIter(nodes(k).x, nodes(k).par);
            [nodes(k).x,nodes(k).par.spTime] = SIElementIter(k, nodes);
        end
        if nodes(j).x > 0
            T = t;
            S = nodes(j).par.spTime; % effective spreading time
            return;
        end
    end
    T = NaN;
end
