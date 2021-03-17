function d = calcNodesDistance(A,r)
% A (NxN): adjacency matrix
% r (Nx3): position of each node in A
%
% return:
% d (NxN): distance between each connected node in A
    N = size(A,1);
    d = zeros(size(A));
    for i = 1:N
        for j = 1:N
            if A(i,j) ~= 0
                d(i,j) = norm(r(i,:) - r(j,:));
            end
        end
    end
end
