function [ScAvg,nComm] = calcCommunityAvgSpreadingTime(sp, cm, ggamma,reshapeBeforeAvg)
    if (nargin < 4) || isempty(reshapeBeforeAvg)
        reshapeBeforeAvg = true;
    end
    c = find(cm.ggamma == ggamma, 1);
    if isempty(c)
        error('ggamma not found in cm');
    end
    
    if isstruct(sp)
        if ~isfield(sp, 'SAvg')
            error('struct sp does not have field SAvg');
        end
        SAvg = sp.SAvg;
    elseif iscell(sp)
        SAvg = sp;
    else
        SAvg = { sp };
    end
    
    if reshapeBeforeAvg
        meanFunc = @(X) mean(reshape(X,1,[]));
    else
        meanFunc = @(X) mean(mean(X,1),2);
    end
    
    nCases = numel(SAvg);
    ScAvg = cell(1,nCases);
    %SAvg = cell(1,nCases);
    nComm = max(cm.C{c});
    %[~,s] = sort(cm.C{c});
    for k = 1:nCases
        %SAvg{k} = sp.SAvg{k}(s,s);
        ScAvg{k} = zeros(nComm);
        % for each community pair
        for i = 1:nComm
            ii = find(cm.C{c} == i);
            for j = 1:nComm %for j = i:nComm
                jj = find(cm.C{c} == j); 
                ScAvg{k}(i,j) = meanFunc(SAvg{k}(ii,jj));
                %ScAvg{k}(j,i) = ScAvg{k}(i,j);
            end
        end
    end
end
