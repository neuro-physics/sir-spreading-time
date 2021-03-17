function p = GetSimulationParam(A, nSeeds, isCompetitive, seedType, seedInd, nSim)
% A -> adj matrix
% nSeeds -> amount of initial seeds for activity (must be equal to the GetNodes nSeeds
% isCompetitive -> determines whether the seeds are competitive (diff states) or cooperative (eq states)
% seedType -> 'random': randomly select seeds
%             'fixed': select fixed seedInd for every trial + a quantity of (nSeeds-numel(seedInd)) seeds in 1:size(A,1);
%             'mostconn': selects the nSeeds most connected nodes as seeds
% seedInd -> double(1:nSim,1:nSeeds) index of 'fixed' seeds
%            if there is less rows than nSim, the remaining rows are a periodic repetition of seedInd(:,:)
%            if there is less columns than nSeeds, the remaining cols are going to be filled up with random seeds
% nSim -> number seed trials
%
% return:
% p struct with fields:
% .N -> network total number of elements
% .nSeeds -> same as input
% .isCompetitive -> same as input
% .seeds -> double(1:nSim,1:nSeeds); each line is a seed trial
% .seedTrial -> a counter for sim functions to determine which seed trial (out of .seeds) to take
% .nSim -> number of seed trials
% .seedType -> same as input
% .x0 -> double(1,1:nSeeds); initial condition for each of the seed nodes
%
    if nargin == 0
        p.N = 0;
        p.nSeeds = 0;
        p.isCompetitive = false;
        p.seeds = 0;
        p.seedTrial = 0;
        p.nSim = 0;
        p.seedType = '';
        p.x0 = 0;
        return;
    end
    N = size(A,1);
    p.N = N;
    p.nSeeds = nSeeds;
    p.isCompetitive = isCompetitive;
    p.seeds = zeros(nSim, nSeeds);
    p.nSim = nSim;
    p.seedType = seedType;
    if strcmpi(seedType, 'random')
        % generate random permutations...
        % need to take care with the total amount of unique combinations of N, take nSeeds;
        % s = N!/( (nSeeds)! * (N-nSeeds)!) is total number of unique combinations
        % if s < nSim, then we can only take s maximum seed combinations, instead of nSim
        %    otherwise we will sample with replacement
        for i = 1:nSim
            p.seeds(i,:) = randperm(N, nSeeds);
        end
    elseif strcmpi(seedType, 'fixed')
        p.seeds = fillUpMatrix(seedInd,nSim,nSeeds,N);
    elseif strcmpi(seedType, 'mostconn')
        s = sort(sum(A~=0), 'descend');
        s = s(1:nSeeds); % gets nSeeds most connected elements for every simulation
        p.seeds = repmat(s(:)', nSim, 1);
    else
        error('GetSimulationParam:seedType', 'Unrecognized seed type');
    end
    p.seedTrial = 1;
    if isCompetitive
        p.x0 = 1:nSeeds;
    else
        p.x0 = ones(1,nSeeds);
    end
end
