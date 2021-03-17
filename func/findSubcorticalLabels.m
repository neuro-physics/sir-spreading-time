function [k,r,s,k_L,k_R] = findSubcorticalLabels(l)
    subLab = {'Hippocampus','Amygdala','Caudate','Putamen','Pallidum','Thalamus'};
    r = false(size(l));
    for i = 1:numel(subLab)
        r = r | cellfun(@(x)~isempty(x),strfind(l,subLab{i}));
    end
    k = find(r);
    s = l(k);
    k_L = find(r & cellfun(@(x)~isempty(x),regexp(l,'_L[_\d]*$')));
    k_R = find(r & cellfun(@(x)~isempty(x),regexp(l,'_R[_\d]*$')));
end