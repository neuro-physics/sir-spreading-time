function [Cp1,Cp2,H,Cf,T,Tn,S,Sn] = TwoSeedsSpreading(A, Theta, tTotal, isCompetitive)
% Cp -> competitiveness of a node
% H -> entropy of a node
% Cf -> conformity of a node
% T -> network activation time for each pair of seeds
% Tn -> node activation time for each pair of seeds Tn(i,j,k) -> time for seeds (i,j) to activate node k
% S -> network activation time (in inverse weight units) for each pair of seeds
% Sn -> node activation time (in inverse weight units) for each pair of seeds Tn(i,j,k) -> time for seeds (i,j) to activate node k
%
% defined in Misic et al 2015 Neuron; pg 1527-1528 (pdf 11-12).
%
% Cp_i == size of cascades iniated at node i, averaged over all competing nodes j
% H_i == - sum_c P(x_c)*log[P(x_c)]
%      where c runs over all available states (2 seeds, c = 2)
%      P_i(x_c)=n_i(x_c)/k_i is the probability of finding a neighbor of i with state x_c;
%         n_i(x_c) is the amount of neighbors of i with state x_c;
%         k_i is the connectivity of node i
%      the definition of P(x_c) in the paper is ambiguous,
%      it could also be interpreted as the probability of finding all the neighbors of i in state x_c
% Cf_i == the proportion of neighbors in the same state as i
%
% these measures must be averaged over all seeds
%
% Cp1 is the average avalanche size of state 1
% Cp2 is the average avalanche size of state 2
%
% theoretically, Cp1' == Cp2, because of the symmetry of the system
%       (avalanche sizes for state 1 seeds (i,j) are equal to avalanche sizes of state 2 for seeds (j,i);
% however, the function UpdateInputNSeed does not treat all the states equally:
% if the input weights for each state to a given node are equal,
% then the state state 1 is preferred over state 2, 2 over 3, and so on,
% due to the finding of maximum weight algorithm in that function
% I improved the UpdateInputNSeed function to change to a random state when an equal weighted input is found
% now, Cp1' is statistically equal Cp2
    N = size(A,1);
    [ii,jj] = meshgrid(1:N,1:N);
    seedInd = [ ii(:), jj(:) ];
    seedInd(1:(N+1):(N*N),:) = []; % excluding the entries with two seeds in the same node
    nSim = size(seedInd,1); % one simulation for each seed combination
    p = GetSimulationParam(A, 2, isCompetitive, 'fixed', seedInd, nSim);
    n = GetNodes(A, Theta, 0, 2, isCompetitive);
    SS = zeros(nSim,1); % spreading time (in inverse weight units) from each seed combination to the whole network
    TT = zeros(nSim, 1); % spreading time from each seed combination to the whole network
    SSn = zeros(nSim, N); % spreading time (in inverse weight units) from each seed combination to each node in the network
    TTn = zeros(nSim, N); % spreading time from each seed combination to each node in the network
    CCp1 = zeros(nSim, 1);
    CCp2 = zeros(nSim, 1);
    Cf = zeros(N, 1);
    H = zeros(N, 1);
    %CCf = zeros(nSim, 1);
    %HH = zeros(nSim, 1);
%     x = zeros(nSim, N);
    for i = 1:nSim
        [xx,p,TT(i),spTemp] = EvolveSINetwork(n, tTotal, p, 1);
        SS(i) = max(spTemp(end,:));
        x = xx(end,:);
        CCp1(i) = getAvalancheSizeForNode(x(seedInd(i,1)), x); % get size of avalanche starting at seed seedInd(i,1)
        CCp2(i) = getAvalancheSizeForNode(x(seedInd(i,2)), x); % get size of avalanche starting at seed seedInd(i,1)
        Cf = Cf + getConformityForNetwork(n, x);
        H = H + getEntropyForNetwork(n, x, p.x0);
        TTn(i,:) = getNodeActivationTime(xx);
        SSn(i,:) = spTemp(end,:);
        SSn(i,SSn(i,:)==0) = NaN;
%         [x(i,:),p,TT(i)] = EvolveSINetwork(n, tTotal, p, 0);
%         CCp1(i) = getAvalancheSizeForNode(x(i,seedInd(i,1)), x(i,:)); % get size of avalanche starting at seed seedInd(i,1)
%         CCp2(i) = getAvalancheSizeForNode(x(i,seedInd(i,2)), x(i,:)); % get size of avalanche starting at seed seedInd(i,1)
%         Cf = Cf + getConformityForNetwork(n, x(i,:));
%         H = H + getEntropyForNetwork(n, x(i,:), p.x0);
    end
    
    %Cp = averageForOneSeed(CCp, N);
    %T = averageForOneSeed(TT, N);
    Cp1 = vecToMatrix(CCp1,seedInd,N);
    Cp2 = vecToMatrix(CCp2,seedInd,N);
    T = vecToMatrix(TT,seedInd,N);
    Tn = matToTensor(TTn,seedInd,N);
    S = vecToMatrix(SS,seedInd,N);
    Sn = matToTensor(SSn,seedInd,N);
    H = H ./ nSim;
    Cf = Cf ./ nSim;
end

function Tn = getNodeActivationTime(x)
% x(:,i) is the timeseries for each node i
    N = size(x,2);
    Tn = zeros(1,N);
    for i = 1:N
        f = find(x(:,i),1,'first');
        if isempty(f)
            Tn(i) = NaN;
        else
            Tn(i) = f;
        end
    end
end

function T = matToTensor(M,si,N)
    T = zeros(N,N,N);
    n = size(si,1);
    for k = 1:N
        for ii = 1:n
            i = si(ii,1);
            j = si(ii,2);
            T(i,j,k) = M(ii,k);
        end
    end
end

function M = vecToMatrix(v,si,N)
%     M = 1-eye(N);
    M = zeros(N);
    for i = 1:numel(v)
        M(si(i,1),si(i,2)) = v(i);
    end
end

function C = getConformityForNetwork(n, x)
    N = numel(n);
    C = zeros(N,1);
    for i = 1:N % for each node
        % find the number of neighbors with the same state of i
        k = 0;
        for jj = 1:numel(n(i).neigh) % for each neighbor
            j = n(i).neigh(jj);
            if (x(j) == x(i))
                k = k + 1;
            end
        end
        C(i) = k / numel( n(i).neigh );
    end
end

function H = getEntropyForNetwork(n, x, xc)
    N = numel(n);
    H = zeros(N,1);
    nStates = numel(xc);
    for i = 1:N
        P = zeros(1,nStates); % probability of finding a neighbor in each of the available states xc
        for k = 1:nStates % check which neighbors of i are in each state
            for jj = 1:numel(n(i).neigh)
                j = n(i).neigh(jj);
                if (x(j) == xc(k)) % if a given neighbor is in the state k
                    P(k) = P(k) + 1; % sums 1 to probability of finding neighbor in state k
                end
            end
            P(k) = P(k) / numel(n(i).neigh);
            H(i) = H(i) + xlogx(P(k));
        end
        H(i) = -H(i);
        %H(i) = - sum(P.*log(P));
    end
end

function h = xlogx(x)
    if (x == 0)
        h = 0;
        return;
    else
        h = x*log(x);
        return;
    end
end

function s = getAvalancheSizeForNode(xk, x)
    s = numel(find(x(x==xk)));
end

function s = getAvalancheSizeForEachState(x, xc)
    s = zeros(size(xc));
    for k = 1:numel(xc)
        s(k) = numel(find(x==xc(k)));
    end
end

% function r = averageForOneSeed(x, N)
%     r = zeros(N,1);
%     for k = 1:N
%         ind = ((k-1)*N+2-k):(k*N-k); % this indices correspond to all the lines of x that had k as a seed
%         % this is a consequence from lines 20, 21, 22 of this script; i.e. the seed pairs were generated using meshgrid
%         % and the double seeds were removed
%         for i = ind
%             r(k) = r(k) + x(i); % variables corresponding to seed k
%         end
%         r(k) = r(k) / numel(ind);
%     end
% end

% function Cp = meanAvalancheSize(x)
%     %nSim = size(x,1);
%     N = size(x,2);
%     Cp = zeros(N,1);
%     for k = 1:N
%         ind = ((k-1)*N+2-k):(k*N-k); % this indices correspond to all the lines of x that had k as a seed
%         % this is a consequence from lines 20, 21, 22 of this script; i.e. the seed pairs were generated using meshgrid
%         % and the double seeds were removed
%         for i = ind
%             Cp(k) = Cp(k) + getAvalancheSizeForNode(x(i,k),x(i,:)); % gets the amount of nodes that have state equal to node k
%         end
%         Cp(k) = Cp(k) / numel(ind); % average over all the competing seeds
%     end
% end
