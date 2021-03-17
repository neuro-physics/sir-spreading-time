function c = GrowClusterBFS(T,k)
    % creating consensus community
    N = numel(T(:,1));
    visited = false(1,N);
    q = k;
    while ~isempty(q)
        i = q(1);
        q(1) = [];
        n = find(T(i,:)>0);
        q = [n(~visited(n)), q];
        visited(i) = true;
    end
    c = find(visited);
end
