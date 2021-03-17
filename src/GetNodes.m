function nodes = GetNodes(A,Theta,x0,nSeeds,isCompetitive)
% A       -> [N,N] adjacency matrix (either weighted or binary)
% Theta   -> [1,1] to [1,N] vector activation threshold; if a vector is provided, each element has Theta(i) activation Threshold
% x0      -> [1,1] to [1,N] initial condition; if a vector is provided, each element has ic x0(i)
    if nargin < 4 || isempty(nSeeds)
        nSeeds = 1;
    end
    if nargin < 5 || isempty(isCompetitive)
        isCompetitive = false;
    end
    if ~isCompetitive
        nSeeds = 1;
    end
    N = numel(A(1,:));
    x_init = repeatToComplete(x0, N);
    Theta_el = repeatToComplete(Theta, N);
    nodes = repmat(struct('x', 0.0, 'neigh', zeros(0,1), 'w', zeros(0,1), 'par', getParStruct(0.0, 0.0, 0, 0.0, 0, 0, 0, 0.0)), 1, N);
    coder.varsize('nodes(:).neigh', 'nodes(:).w');
    for j = 1:N
        ind = find(A(:,j));
        [~,s] = sort(A(ind,j),'descend'); % sorting connections from the heaviest to the lightest
        nodes(j).x = x_init(j);
        nodes(j).neigh = ind(s);
        nodes(j).w = A(ind(s),j);
        nodes(j).par = getParStruct(0.0, 0.0, 0, Theta_el(j), sum(A(ind,j)), numel(ind), nSeeds, 0.0);
    end
end

function p = getParStruct(Iext, Isyn, kInp, Theta, W, n, nInp, s)
% Iext -> external current used to initially excite a given node
% Isyn -> sum of weighted inputs over node i; i.e. sum of w_ij * s_j
% kInp -> (only for multiple seeds) the state towards which node i must be updated (can be from 1 to nInp)
% Theta -> the element threshold for firing
% W -> total input weight over node i
% n -> number of inputs over node i
% nInp -> total number of possible states
% s -> cumulative time it took for node i to get activated during spreading time simulation (summing up all times from the initial seed stimulation)
    p = struct('Iext', Iext, 'Isyn', Isyn, 'kInp', kInp, 'Theta', Theta, 'W', W, 'n', n, 'nInp', nInp, 'spTime', s);
end
