function [SS,d,nodeInd] = calcRadialSpTime(S,r0,r,inout,seedNodes)
% S -> Spreading time matrix (or z-scored sp time matrix); N by N nodes
% r0 -> center of reference to calculate radii
% r -> r(i,:) -> node i position; i = 1:N
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
    if size(r,2) == N
        r = r';
    end
    if size(r,1) ~= N
        error('you have to provide one position for each node')
    end

    d = sqrt(sum((r-repmat(r0,N,1)).^2,2));
    if strcmpi(inout,'out')
        SS = reshape(mean(S(seedNodes,:),1,'omitnan'),[],1); % mean signal coming out from the lesion
    elseif strcmpi(inout,'in')
        SS = reshape(mean(S(:,seedNodes),2,'omitnan'),[],1); % mean signal going into the lesion
    end

    [d,nodeInd] = sort(d);
    SS = SS(nodeInd);
end