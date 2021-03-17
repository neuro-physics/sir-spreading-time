function [SS,d] = calcLengthSpTime(S,L,inout,seedNodes)
% S -> Spreading time matrix (or z-scored sp time matrix); N by N nodes
% L -> Fiber Length matrix
% inout -> 'in' or 'out' defines if we want 'in sp time to' or 'out sp time from' seedNodes (or all nodes)
% seedNodes -> consider only spreading time to/from seedNodes
%
% SS,d -> average sp time at average distance d from r0
% nodeInd(i) -> AAL index that correspond to SS(i) and d(i)
    if (nargin < 4) || isempty(inout)
        inout = 'in';
    end
    if (nargin < 5)
        seedNodes = [];
    end
    if ~any(strcmpi(inout,{'in','out'}))
        error('parameter inout can only be in or out')
    end
    N = size(S,1);
    if isempty(seedNodes)
        seedNodes = 1:N;
    end
    
    D = distance_wei(L); % function from brain conn toolbox

    if strcmpi(inout,'out')
        SS = reshape(mean(S(seedNodes,:),1,'omitnan'),[],1); % mean signal coming out from the lesion
        d = reshape(mean(D(seedNodes,:),1,'omitnan'),[],1);
    elseif strcmpi(inout,'in')
        SS = reshape(mean(S(:,seedNodes),2,'omitnan'),[],1); % mean signal going into the lesion
        d = reshape(mean(D(:,seedNodes),2,'omitnan'),[],1);
    end

    [d,nodeInd] = sort(d);
    SS = SS(nodeInd);
end