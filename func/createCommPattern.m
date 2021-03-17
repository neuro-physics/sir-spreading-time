% function [P,commSort] = createCommPattern(N,ll)
function P = createCommPattern(N,ll)
    if (nargin < 2) || isempty(ll)
        ll = [ floor(N/2); N ];
    end
%     commSort = [];
    if numel(ll) == N
%         commSort = sort(ll,'ascend');
        [~,ll,~] = unique(sort(ll,'ascend'),'last');
    end
    if ll(1) ~= 1
        ll = [ 1; ll(:) ];
    end
    P = zeros(N);
    for k = 2:numel(ll)
        for i = ll(k-1):ll(k)
            for j = ll(k-1):ll(k)
                P(i,j) = 1;
            end
        end
    end
end
