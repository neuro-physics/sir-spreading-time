function B = calcBetweennessCentrality(A,isBinaryNet)
% Betweenness Centrality of n -> probability that a signal between any two nodes will travel through node n
    if (nargin < 2) || isempty(isBinaryNet)
        if iscell(A)
            isBinaryNet = isBinary(A{1});
        else
            isBinaryNet = isBinary(A);
        end
    end
    if ~iscell(A)
        A = {A};
    end
    nC = numel(A);
    sEq = allSizesEqual(A);
    if sEq
        B = zeros(size(A{1},1),nC);
        for i = 1:nC
            B(:,i) = calcBetweennessCentrality_internal(A{i},isBinaryNet);
        end
    else
        B = cell(size(A));
        for i = 1:nC
            B{i} = calcBetweennessCentrality_internal(A{i},isBinaryNet);
        end
    end
end

function B = calcBetweennessCentrality_internal(A,isBinaryNet)
%     G = digraph(full(A));
%     N = numnodes(G);
%     args = {};
%     if ~isBinary(A)
%        args = {'Cost', G.Edges.Weight};
%     end
%     B = 2 * reshape(centrality(G, 'betweenness', args{:}), N, 1) / ( (N-2)*(N-1) ); % normalized weighted betweenness centrality
    N = size(A,1);
    if isBinaryNet
        B = 2 .* betweenness_bin(A) ./ ( (N-1) * (N-2) ); % function from brain connectivity toolbox
    else
        B = 2 .* betweenness_wei(A) ./ ( (N-1) * (N-2) );
    end
end

function r = isBinary(A)
    r = full(all(all((A == 0) | (A == 1))));
end

function r = allSizesEqual(A)
    r = all(all(cell2mat(cellfun(@(x)size(x),A,'UniformOutput',false)') == size(A{1},1)));
end
