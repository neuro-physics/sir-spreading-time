function [sc,lInd,rInd] = sortAALNodes(sortType, commFile, ggamma, aalLabels)
% if sortType == 'comm'
%   commFile is a mat-file containing a struct:
%     Ac         -> consensus matrix
%     C          -> communities for each node for each ggamma
%   ggamma     -> each ggamma corresponds to a cell of C
% elseif sortType == 'lr'
%   aalLabels -> AAL labels that need to be sorted
    if strcmpi(sortType, 'comm')
        cm = load(commFile);
        gIndex = find(cm.ggamma == ggamma, 1); % checking if ggamma exists in comm file
        if isempty(gIndex)
            error('required ggamma not found in file %s',commFile);
        end
        [~,sc] = sort(cm.C{gIndex});
        lInd = [];
        rInd = [];
    elseif strcmpi(sortType, 'lr')
        rInd = cellfun(@(x)~isempty(x),regexp(aalLabels, '(_R$|_R_)', 'start'));
        lInd = ~rInd;
        ll = find(lInd);
        rr = find(rInd);
        sc = [ ll(:)', rr(:)' ];
    else
        error('sortAALNodes:sortType','unrecognized sortType');
    end
end
