function [ScAvg,nComm] = calcCommunityDataForNodes(sp, cm, ggamma)
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
    
    nCases = numel(SAvg);
    ScAvg = cell(1,nCases);
    %SAvg = cell(1,nCases);
    nComm = max(cm.C{c});
    %[~,s] = sort(cm.C{c});
    for k = 1:nCases
        %SAvg{k} = sp.SAvg{k}(s,s);
        ScAvg{k} = zeros(nComm,1);
        % for each community pair
        for i = 1:nComm
            ScAvg{k}(i) = nanmean(SAvg{k}(cm.C{c} == i));
        end
    end
end
