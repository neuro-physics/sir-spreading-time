%function groups = GroupVerticesKMeans(r, centers)
function clusterNumbers = GroupVerticesKMeans(r, centers, splitInHalf)
% returns groups of arbitrary number of elements from the position, r, of N elements in the network
% utilizes kmeans to produce the groups, so the number of elements in each group is random, but is around n
% each row of r is a position (3D or 2D)
    if (nargin < 3) || isempty(splitInHalf)
        splitInHalf = true;
    end
    if splitInHalf
        pPool = parpool(2);
    end
    coder.extrinsic('perms');
    sr = size(r);
    sc = size(centers);
    pm = zeros(numel(sr));
    pm = perms(sr);
    k = find(pm == repmat(sc,[size(pm,1),1]));k=k(1);
    n = find(sr~=pm(k));n=n(1);
    sr1 = sr(n);
    n = find(sc~=pm(k));n=n(1);
    sc1 = sc(n);
    r = reshape(r,[sr1,pm(k)]); % reshaping such that size(r) = [N,d] (d is the dimensionality of the space)
    centers = reshape(centers,[sc1,pm(k)]); % reshaping such that size(centers) = [Nc,d]
    if splitInHalf
        n = cell(1,2);
        rr = { r(1:(sr1/2),:), r((1+sr1/2):end,:) };
        cc = { centers(1:(sc1/2),:), centers((1+(sc1/2)):end,:) };
        parfor i = 1:2
            n{i} = runKMeans(rr{i},cc{i});
        end
        clusterNumbers = [ n{1}(:); (n{2}(:)+(sc1/2)) ];
        delete(pPool);
    else
        clusterNumbers = runKMeans(r,centers);
    end
    
%     groups = cell(1,nGroups);
%     for i = 1:nGroups
%         groups{i} = find(clusterNumbers == i);
%     end
end

function n = runKMeans(r, centers)
    nGroups = size(centers,1);
    n = kmeans(r, nGroups, 'start', centers, 'onlinephase', 'on', 'distance', 'sqEuclidean', 'emptyaction', 'singleton', 'Options', statset('MaxIter', 1000, 'Display', 'off'));
end
