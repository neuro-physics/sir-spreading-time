function [nodes,lMiss,rMiss] = getLRNodeDiff(lab306,lab90)
    if (nargin < 1)
        lab306 = [];
    end
    if (nargin < 2)
        lab90 = [];
    end
    if isempty(lab306) || isempty(lab90)
%         aal = load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
        [~,~,~,aal] = aalsurfview(zeros(90,1));
        if isempty(lab306)
            lab306 = aal.labels.AAL306;
        end
        if isempty(lab90)
            lab90 = aal.labels.AAL90;
        end
    end
    [~,lInd,rInd] = sortAALNodes('lr',[],[],lab306);
    nodeName = regexprep(lab90(1:2:end),'_L$','');
    labChecked = false(size(nodeName));
    ln = {};
    rn = {};
    for i = 1:numel(nodeName)
        if labChecked(i)
            continue;
        else
            labChecked(i) = true;
        end
        kInd = cellfun(@(x)~isempty(x),regexp(lab306,[nodeName{i},'(_R|_L)_*[0-9]*']));
        l = lab306(lInd & kInd);
        r = lab306(rInd & kInd);
        si = numel(ln);
        ei = max(numel(l),numel(r));
        ln((si+1):(ei+si)) = [l(:);cell(numel(r) - numel(l),1)];
        rn((si+1):(ei+si)) = [r(:);cell(numel(l) - numel(r),1)];
    end
    nodes = {};
    nodes(:,1) = ln(:);
    nodes(:,2) = rn(:);
    rMiss = ln(cellfun(@isempty,rn))';
    lMiss = rn(cellfun(@isempty,ln))';
end
