function r = isGraphConnected(A)
% checks if every node of A has at least 1 incoming and/or outgoing connection
    N = size(A,1);
    A(1:(N+1):N) = 0;
    r = isGraphConnected_out(A,N) && isGraphConnected_in(A,N);
end

function r = isGraphConnected_in(A,N)
    isVisited = false(N,1);
    [~,K] = max(sum(A>0,2));
    nodeList = K;
    while ~isempty(nodeList)
        n = nodeList(1);
        nodeList(1) = [];
        isVisited(n) = true;
        nn = find((A(:,n) > 0) & (~isVisited));
        nodeList((1+numel(nodeList)):(numel(nn)+numel(nodeList))) = nn;
    end
    r = all(isVisited);
end

function r = isGraphConnected_out(A,N)
    isVisited = false(1,N);
    [~,K] = max(sum(A>0,1));
    nodeList = K;
    while ~isempty(nodeList)
        n = nodeList(1);
        nodeList(1) = [];
        isVisited(n) = true;
        nn = find((A(n,:) > 0) & (~isVisited));
        nodeList((1+numel(nodeList)):(numel(nn)+numel(nodeList))) = nn;
    end
    r = all(isVisited);
end
