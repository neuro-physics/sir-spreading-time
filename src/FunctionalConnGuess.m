function F = FunctionalConnGuess(A, Theta, nSeeds, nSim, tTotal)
    N = size(A,1);
    p = GetSimulationParam(A, nSeeds, true, 'random', [], nSim);
    x0i = zeros(1, N);
    n = GetNodes(A, Theta, x0i, nSeeds, true);
    F = zeros(N);
    for k = 1:nSim
        p.seedTrial = k; % needs to be set because EvolveSINetwork uses the seeds for sim index given in p.seedTrial
        x = EvolveSINetwork(n, tTotal, p, false);
        
        for i = 1:N
            for j = (i+1):N
                if x(end,i) == x(end,j)
                    F(i,j) = F(i,j) + 1; % couting how many times the pair (i,j) ended in the same state
                    F(j,i) = F(j,i) + 1; % couting how many times the pair (i,j) ended in the same state
                end
            end
        end
    end
    F = F ./ nSim;
end