function clusterNumbers = GroupVerticesEucDist(r, centers, splitInHalf)
% returns groups of arbitrary number of elements from the position, r, of N elements in the network
% utilizes kmeans to produce the groups, so the number of elements in each group is random, but is around n
% each row of r is a position (3D or 2D)
    if (nargin < 3) || isempty(splitInHalf)
        splitInHalf = true;
    end
    if splitInHalf
%         pPool = parpool(2);
    end
    coder.extrinsic('perms');
    sr = size(r);
    sc = size(centers);
    pm = zeros(numel(sr));
    pm = perms(sr);
    k = find(pm == repmat(sc,[size(pm,1),1]));k=k(1);
    n = find(sr~=pm(k));n=n(1);
    sr2 = sr(n);
    n = find(sc~=pm(k));n=n(1);
    sc2 = sc(n);
    r = reshape(r,[pm(k),sr2]); % reshaping such that size(r) = [N,d] (d is the dimensionality of the space)
    centers = reshape(centers,[pm(k),sc2]); % reshaping such that size(centers) = [Nc,d]

%     clusterNumbers = groupVertices(r,centers);
    if splitInHalf
        n = cell(1,2);
        rr = { r(:,1:(sr2/2)), r(:,(1+sr2/2):end) };
        cc = { centers(:,1:(sc2/2)), centers(:,(1+(sc2/2)):end) };
%         parfor i = 1:2
        for i = 1:2
            n{i} = groupVertices(rr{i},cc{i});
        end
        clusterNumbers = [ n{1}(:); (n{2}(:)+(sc2/2)) ];
%         delete(pPool);
    else
        clusterNumbers = groupVertices(r,centers);
    end
    
%     groups = cell(1,nGroups);
%     for i = 1:nGroups
%         groups{i} = find(clusterNumbers == i);
%     end
end

function n = groupVertices(r,centers)
    sr2 = size(r,2);
    sc2 = size(centers,2);
    n = zeros(sr2,1);
    for i = 1:sr2
        [~,j] = min(sqrt(sum( (repmat(r(:,i),1,sc2) - centers).^2) ));
        n(i) = j;
    end
end
