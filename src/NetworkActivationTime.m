function [T,S] = NetworkActivationTime(A, Theta, tTotal, nSeeds, isCompetitive, seedType, seedInd)
    n = GetNodes(A, Theta, 0, nSeeds, isCompetitive);
    nSim = size(seedInd,1);
    p = GetSimulationParam(A, nSeeds, isCompetitive, seedType, seedInd, nSim);
    T = zeros(nSim, 1);
    S = zeros(nSim, 1);
    for i = 1:nSim
        [~,p,T(i),s] = EvolveSINetwork(n, tTotal, p, 0);
        S(i) = max(s(:));
        %T(i) = size(x,1);
    end
end
