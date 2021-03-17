function [Tcomm,nComm] = calcCommunityAvgTwoSeedToNode(T, cm, ggamma)
    c = find(cm.ggamma == ggamma, 1);
    if isempty(c)
        error('ggamma not found in cm');
    end
    
    if ~iscell(T)
        T = { T };
    end
    
    nCases = numel(T);
    Tcomm = cell(1,nCases);
    %SAvg = cell(1,nCases);
    nComm = max(cm.C{c});
    %[~,s] = sort(cm.C{c});
    for k = 1:nCases
        Tcomm{k} = calcCommSp_internal(T{k},cm.C{c},nComm);
    end
end

function Tc = calcCommSp_internal(T,C,nC)
    Tc = zeros(nC,nC,nC);
    % for each community pair
    for i = 1:nC
        ii = find(C == i);
        for j = i:nC
            jj = find(C == j); 
            for k = 1:nC
                kk = find(C == k);
                Tc(i,j,k) = mean(mean(mean(T(ii,jj,kk),1),2),3);
            end
        end
    end
end
