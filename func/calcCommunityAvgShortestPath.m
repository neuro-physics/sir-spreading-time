function PcAvg = calcCommunityAvgShortestPath(p, cm, ggamma)
    c = find(cm.ggamma == ggamma, 1);
    if isempty(c)
        error('ggamma not found in cm');
    end
    
    if isstruct(p)
        if ~isfield(p, 'P')
            error('struct p does not have field P');
        end
        P = p.P;
    elseif iscell(p)
        P = p;
    else
        P = { p };
    end
    
    nCases = numel(P);
    PcAvg = cell(1,nCases);
    %SAvg = cell(1,nCases);
    nComm = max(cm.C{c});
    %[~,s] = sort(cm.C{c});
    for k = 1:nCases
        %SAvg{k} = sp.SAvg{k}(s,s);
        PcAvg{k} = zeros(nComm);
        % for each community pair
        for i = 1:nComm
            ii = find(cm.C{c} == i);
            for j = i:nComm
                jj = find(cm.C{c} == j); 
                PcAvg{k}(i,j) = mean(mean(P{k}(ii,jj),1),2);
                PcAvg{k}(j,i) = PcAvg{k}(i,j);
            end
        end
    end
end
