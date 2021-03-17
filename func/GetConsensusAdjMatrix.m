function [A,P,km] = GetConsensusAdjMatrix(input, kmShift, caseName)
% for each node i, generates a probability distribution for the number of edges k_i (considering all matrices in inputPattern files)
% then select the <k_i> most probable nodes for i
%
% input may be:
%    - directory pattern for mat files, each file containing an adjacency matrix
%    - a cell of adjacency matrices
    if (nargin < 3)
        caseName = [];
    end
    if ischar(input)
        A = loadFiles(input, caseName);
    else
        A = input;
    end
    if (nargin < 2)
        kmShift = [];
    end
    [K, P, W] = calcParameters(A);
    N = numel(K(:,1));
    if isempty(kmShift)
        kmShift = zeros(N,1);
    end
    A = zeros(N,N);
    km = zeros(N,1);
    for i = 1:N % for each node
        km(i) = round(mean(K(i,:))); % mean connectivity for each node taken case-wise
        if km(i) < 1
            km(i) = 1;
        end
        if km(i) > N
            km(i) = N;
        end
        [~,ind] = sort(P(i,:), 'descend'); % sorting from the most probable connection of node i to the least probable
        a = W(i,ind(1:(km(i) + kmShift(i))));
        A(i,ind(1:km(i))) = a; % selecting the km most probable connections
    end
end

function A = loadFiles(input, cn)
    [inputDir,~,~] = fileparts(input);
    if ~isempty(inputDir)
        inputDir = [ inputDir, filesep ];
    end
    f = dir(input);
    A = cell(1,numel(f));
    for i = 1:numel(f)
        if isempty(cn)
            A{i} = loadMatrix([inputDir,f(i).name]);
        else
            c = getCaseName(f(i).name);
            [cc,~] = containsCase(cn,c);
            if cc
                A{i} = loadMatrix([inputDir,f(i).name]);
            end
        end
    end
    A=A(cellfun(@(x)~isempty(x),A));
end

function A = loadMatrix(fname)
    a = load(fname);
    if isfield(a, 'matrix')
        A = a.matrix;
    else
        A = a;
    end
end

function [K, P, W] = calcParameters(A)
    if iscell(A)
        n = numel(A);
        m = size(A{1},1);
        A = reshape(cell2mat(A),[m,m,n]);
    end
    [n,~,nsub] = size(A);
    C = sum(A~=0,3); % number of links between nodes
    P = C ./ nsub; % probability of having i,j connection
    K = reshape(sum(A~=0,2),[n,nsub]);
    %km = round(mean(sum(A~=0,2),3));km(km<1)=1;km(km>n)=n; % mean connectivity per node
    C(C==0)=1;
    W = sum(A,3)./C;
end

function [K, P, W] = calcParameters_old(A)
% returns a matrix N x NP (nodes x num_of_cases)
% each element is the connectivity of that node for a given patient
% P (N x N) is the matrix containing the probability of finding a node i connected to a node j
% W (N x N) is the average weight (across selected edges) of a given edge
    np = numel(A);
    %a = load([inpDir,f(1).name]); %
    %N = numel(a.matrix(:,1));
    N = size(A{1},1);
    K = [];
    P = zeros(N,N);
    W = zeros(N,N);
    edges = cell(1,N);
    %weights = cell(1,N);
    for i = 1:np
        a = A{i};%load([inpDir,f(i).name]); %
        K = [ K, sum(a>0,2) ];
        for n = 1:N
            jj = find(a(n,:)>0);
            edges{n} = [ edges{n}, jj(:)' ];
            %weights{n} = [ weights{n}, a.matrix(n,jj) ];
            W(n,jj) = W(n,jj) + a(n,jj);
        end
    end
    for i = 1:N
        P(i,:) = histcounts(edges{i}, N, 'Normalization', 'probability');
        for j = 1:N
            % nEdges = P(i,j) * numel(edges{i});
            nEdges = numel(find(edges{i} == j));
            if nEdges == 0
                nEdges = 1;
            end
            W(i,j) = W(i,j) / nEdges;
        end
    end
end
