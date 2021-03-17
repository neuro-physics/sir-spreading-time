function s = calcSpreadShortPathSlowDown(sp, p, theta)
% sp is the result of loading a spreading time MAT file
% p is the result of loading a shortpath.mat file
    nCases = numel(sp.SAvg);
    N = size(sp.SAvg{1},1);
    %[x,y]=meshgrid(1:N,1:N);
    %pairs = [x(:),y(:)];
    %pairs = pairs(pairs(:,2)>pairs(:,1),:);
    %nPairs = size(pairs,1);
    %spDiff = zeros(nCases,nPairs);
    %pairs = zeros(N*N,2);
    spDiff = zeros(nCases,N*N);
    for i = 1:nCases
        k = find(~cellfun(@isempty,strfind(p.caseName, sp.caseName{i})),1);
        if isempty(k)
            k = 1;
            warning('using k = 1 because case was not found');
        end
        A = p.P{k} - sp.SAvg{i};
        spDiff(i,:) = reshape(A,1,N*N);
        %for j = 1:nPairs
        %    spDiff(i,j) = A(pairs(j,1),pairs(j,2));
        %end
    end
    %s.pairs = pairs;
    s.theta = theta;
    s.spDiff = spDiff;
end
