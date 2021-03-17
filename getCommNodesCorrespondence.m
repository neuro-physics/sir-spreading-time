function [nodeComm,nodesCommInd] = getCommNodesCorrespondence(commLabel)
    if (nargin < 1) || isempty(commLabel)
        commLabel = '';
    end
    addpath func
    [~,~,~,aal] = aalsurfview(zeros(90,1));
    if isempty(commLabel)
        r = aal.labels.AAL09comm(aal.comm.AAL306);
        [r,ind] = sort(r);
        s = aal.labels.AAL306(ind);
        nodeComm = [s',r'];
        nodesCommInd = cell(size(aal.labels.AAL09comm));
        for i = 1:numel(nodesCommInd)
            nodesCommInd{i} = aal.labels.AAL306(aal.comm.AAL306==i);
        end
    else
        nodesCommInd = [];
        k = find(strcmpi(aal.labels.AAL09comm,commLabel),1,'first');
        nodeComm = aal.labels.AAL306(aal.comm.AAL306==k);
    end
end