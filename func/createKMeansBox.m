function groups = createKMeansBox(r, n)
% returns groups of arbitrary number of elements from the position, r, of N elements in the network
% utilizes kmeans to produce the groups, so the number of elements in each group is random, but is around n
% each row of r is a position (3D or 2D)
    ss = size(r);
    r = reshape(r,sort(ss,'descend'));
    N = length(r(:,1)); % number of the elements in the network
    a = mod(N, n);
    nGroups = floor(N / n);
    if (a ~= 0)
        NN = N - a;
    else
        NN = N;
    end
    startInd = 1:n:NN;
    startPos = zeros(nGroups, numel(r(1,:)));
    for i = 1:nGroups
        startPos(i,:) = r(startInd(i),:);
    end
    clusterNumbers = kmeans(r, nGroups, 'start', startPos, 'onlinephase', 'on', 'distance', 'sqEuclidean', 'emptyaction', 'singleton', 'Options', statset('MaxIter', 1000, 'Display', 'off'));
    groups = cell(1,nGroups);
    for i = 1:nGroups
        groups{i} = find(clusterNumbers == i);
    end
end
