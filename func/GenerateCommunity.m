function [C, Q, Zrand, gammaMaxInd] = GenerateCommunity(A, ggamma, nTrials)
% this method is only working for scalar ggamma
    N = numel(A(:,1));
    nGamma = numel(ggamma);
    q = zeros(nGamma, nTrials);
    Q = zeros(1, nGamma);
    CC = zeros(N,nTrials,nGamma);
    ri = zeros(1, nTrials*(nTrials - 1));
    Zrand = zeros(1,nGamma);
    gMax = 0;
    %ZMax = -Inf;
    for i = 1:nGamma % for each gamma
        for j = 1:nTrials % generate nTrials communities
            [CC(:,j,i),q(i,j)] = community_louvain(A, ggamma(i));
            %[CC(:,j,i),q(i,j)] = modularity_und(A, ggamma(i));
        end
        Q(i) = mean(q(i,:));

        % generates the rand index between every pair of generated communities
        %riMean = 0;
        %riStd = 0;
        m = 0;
        for j = 1:nTrials
            for k = (j+1):nTrials
                m = m + 1;
                ri(m) = rand_index(CC(:,j,i), CC(:,k,i));
                %riMean = riMean + ri(m);
                %riStd = riStd + ri(m) * ri(m);
            end
        end
        %riMean = riMean / numel(ri);
        %riStd = riStd / numel(ri) - riMean * riMean;
        % mean(ri - riMean) = mean(ri) - mean(riMean) = riMean - riMean = 0 always!
        %Zrand(i) = mean(ri - riMean); % calculate average Z-score of the rand index between all pairs of communities
        Zrand(i) = mean(abs(zscore(ri))); % I am having a problem with selecting the gamma...
                                     % I am probably misinterpreting the Misic paper methods (pg 11)
                                     % and Traud et al (2011) paper in which the z-score of rand-index is described
        %if (Zrand(i) > ZMax)
        %    gMax = i; % getting the index of the gamma that maximize the Z-score of the rand index
        %end
    end
    [ ~, gMax ] = max(Zrand);
    
    % selecting the best structural scale parameter
    gammaMaxInd = gMax;
    CC = CC(:,:,gMax);
    
    % applying consensus to the community trials in order to determine a single community
    % D. Bassett et al (2013): Robust detection of dynamic community structure in networks. CHAOS 23, 013142.
    % section: Dealing with degeneracy: Constructing representative partitions
    T = zeros(size(A));
    Tr = zeros(size(A));
    ip = zeros(1,N);
    for trial = 1:nTrials
        mm = minmax(CC(:,trial)');
        cp = randperm(N);
        %p = CC(cp,trial);
        ip(cp) = 1:N;
        for k = mm(1):mm(2)
            n = find(CC(:,trial) == k);
            nr = ip(n);
            for i = 1:numel(n)
                for j = (i+1):numel(n)
                    T(n(i),n(j)) = T(n(i),n(j)) + 1;
                    Tr(nr(i),nr(j)) = Tr(nr(i),nr(j)) + 1;
                end
            end
        end
    end
    T(T<Tr) = 0; % eliminating grouping by chance
    
    C = ClusterConnectedElements(T);
end
