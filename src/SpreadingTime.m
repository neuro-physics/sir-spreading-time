function [T,V,S] = SpreadingTime(A, Theta, nSim, tTotal)
    nodes = GetNodes(A, Theta, 0, 1, false);
    N = numel(nodes);
    T = zeros(N,N);
    V = zeros(N,N);
    S = zeros(N,N);
    for i = 1:N
        for j = 1:N
            [T(i,j), V(i,j), S(i,j)] = SpreadNodeToNodeNTimes(i, j, nodes, nSim, tTotal);
        end
    end
end

function [T,V,S] = SpreadNodeToNodeNTimes(i, j, nodes, nSim, tTotal)
    T = 0.0;
    S = 0.0;
    V = 0.0;
    nn = 0;
    for k = 1:nSim
        [TT,SS] = SpreadNodeToNode(i,j,nodes,tTotal);
        if ~isnan(TT)
            T = T + TT;
            V = V + TT .* TT;
            S = S + SS;
            nn = nn + 1;
        end
    end
    if nn == 0
        % all TT were NaN
        T = NaN;
        V = NaN;
        S = NaN;
    else
        T = T ./ nn;
        V = V ./ nn - T .* T;
        S = S ./ nn;
    end
    if V < 0.0
        V = 0.0;
    end
end