function k = getIpsiHippocampusIndex(cn,N,cdb)
    if (nargin < 2) || isempty(N)
        N = 306;
    end
    if (nargin < 3) || isempty(cdb)
        cdb = load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat');
    end
    T = struct2table(cdb.casesMetaData);
    T = T(T.UseForSpSim==1,:);
    [~,~,it] = intersect(cn,T.Code,'stable');
    T = T(it,:);

    [~,~,~,aal] = aalsurfview(zeros(90,1));
    l = getAALLabel(N);
    k_L = find(strcmpi(aal.labels.(l),'Hippocampus_L'));
    k_R = find(strcmpi(aal.labels.(l),'Hippocampus_R'));
    
    k = (strcmpi(T.Group,'NC') | strcmpi(T.Group,'LTLE')) .* k_L + strcmpi(T.Group,'RTLE') .* k_R;
end