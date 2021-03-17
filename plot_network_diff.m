clearvars
close all

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

addpath func

np = load(fullfile(dataDir,'sirs','selected','N306','net_prop_flip_Z.mat'));
cdb = load(fullfile(dataDir,'TLE_NB_BB.mat')); % inputs variable casesMetaData containing a table of patients that Neda gave me
% cdb = load(fullfile(dataDir,'FCD_table.mat'));

caseName = [np.Controls.caseName,np.LRTLE.caseName];
N = size(np.Controls.A{1},1);

ct = getCortThickStruct(fullfile(dataDir,'cortical_thickness_sel.mat'), caseName, N);
hv = getHipVolStruct(cdb, caseName);

[~,~,~,aal] = aalsurfview(zeros(90,1));

%%

hcInd = find(strcmpi(np.nodeLabel,'Hippocampus_L'));
v_hcInd = unique(cell2mat(cellfun(@(x)find(x(:,hcInd)~=0),[np.Controls.A(:);np.LRTLE.A(:)],'UniformOutput',false)));

%%

idC = mean(matCell2Mat(np.Controls.inDegree),1);
idP = mean(matCell2Mat(np.LRTLE.inDegree),1);
r=ttest.ttest2Struct(matCell2Mat(np.Controls.inDegree),matCell2Mat(np.LRTLE.inDegree),'AlphaFDR',0.05,'Alpha',0.05);
idP(r.h==0)=0;
cMap = insertColorForVal(0,idP,[1,1,1]);
aalsurfview(idP, 'in degree TLE Z-score', cMap);


%%

odC = mean(matCell2Mat(np.Controls.outDegree),1);
odP = mean(matCell2Mat(np.LRTLE.outDegree),1);
r=ttest.ttest2Struct(matCell2Mat(np.Controls.outDegree),matCell2Mat(np.LRTLE.outDegree),'AlphaFDR',0.05,'Alpha',0.05);
odP(r.h==0)=0;
cMap = insertColorForVal(0,odP,[1,1,1]);
aalsurfview(odP, 'out degree TLE Z-score', cMap);
% r.h(r.h==0)=NaN;
% figure;
% plot(1:N,odC,'-k',1:N,odP,'-r',1:N,r.h,'*k')

%%

bcC = mean(matCell2Mat(np.Controls.betweenCenWei),1);
bcP = mean(matCell2Mat(np.LRTLE.betweenCenWei),1);
r=ttest.ttest2Struct(matCell2Mat(np.Controls.betweenCenWei),matCell2Mat(np.LRTLE.betweenCenWei),'AlphaFDR',0.05,'Alpha',0.05);
bcP(r.h==0)=0;
cMap = insertColorForVal(0,bcP,[1,1,1]);
aalsurfview(bcP, 'betweenness centrality TLE Z-score', cMap);
% r.h(r.h==0)=NaN;
% figure;
% plot(1:N,odC,'-k',1:N,odP,'-r',1:N,r.h,'*k')

%%

ccC = mean(matCell2Mat(np.Controls.clusterCoeffWei),1);
ccP = mean(matCell2Mat(np.LRTLE.clusterCoeffWei),1);
r=ttest.ttest2Struct(matCell2Mat(np.Controls.clusterCoeffWei),matCell2Mat(np.LRTLE.clusterCoeffWei),'AlphaFDR',0.05,'Alpha',0.05);
ccP(r.h==0)=0;
cMap = insertColorForVal(0,ccP,[1,1,1]);
aalsurfview(ccP, 'clustering coefficient TLE Z-score', cMap);

%%

od_hip_nei_c = cellfun(@(x)mean(x(v_hcInd)),np.Controls.outDegreeWei)';
od_hip_nei_p = cellfun(@(x)mean(x(v_hcInd)),np.LRTLE.outDegreeWei)';
t_od_hip_nei = ttest.ttest2Struct(od_hip_nei_c,od_hip_nei_p,'AlphaFDR',0.05,'Alpha',0.05);
t_od_hip_nei_CT = ttest.ttest2Struct(od_hip_nei_c,od_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_od_hip_nei_HV = ttest.ttest2Struct(od_hip_nei_c,od_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

od_hip_c = cellfun(@(x)mean(x(hcInd)),np.Controls.outDegreeWei)';
od_hip_p = cellfun(@(x)mean(x(hcInd)),np.LRTLE.outDegreeWei)';
t_od_hip = ttest.ttest2Struct(od_hip_c,od_hip_p,'AlphaFDR',0.05,'Alpha',0.05);
t_od_hip_CT = ttest.ttest2Struct(od_hip_c,od_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_od_hip_HV = ttest.ttest2Struct(od_hip_c,od_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

plotAvgVsThetaScatterPanels({'Hip','Hip\_Neighb'}, {od_hip_c,od_hip_nei_c}, {od_hip_p,od_hip_nei_p}, [], ...
                            [t_od_hip.h,t_od_hip_nei.h], [t_od_hip.hFDR,t_od_hip_nei.hFDR], [t_od_hip_CT.hFDR,t_od_hip_nei_CT.hFDR], [t_od_hip_HV.hFDR,t_od_hip_nei_HV.hFDR], ...
                            'Out deg', {'Controls','TLE'});

fprintf('Out degree (Z-Score)\n');
fprintf('--------------------\n');
fprintf('* Hippocampus\n');
dispMeanStd(od_hip_c,od_hip_p,N);
disp(rmfield(t_od_hip,{'confInt','stats','alpha','alphaFDR','pFDR'}));
fprintf('  -\n');
fprintf('* Hippocampus neighbors (avg)\n');
dispMeanStd(od_hip_nei_c,od_hip_nei_p,N);
disp(rmfield(t_od_hip_nei,{'confInt','stats','alpha','alphaFDR','pFDR'}));

%%

id_hip_nei_c = cellfun(@(x)mean(x(v_hcInd)),np.Controls.inDegreeWei)';
id_hip_nei_p = cellfun(@(x)mean(x(v_hcInd)),np.LRTLE.inDegreeWei)';
t_id_hip_nei = ttest.ttest2Struct(id_hip_nei_c,id_hip_nei_p,'AlphaFDR',0.05,'Alpha',0.05);
t_id_hip_nei_CT = ttest.ttest2Struct(id_hip_nei_c,id_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_id_hip_nei_HV = ttest.ttest2Struct(id_hip_nei_c,id_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

id_hip_c = cellfun(@(x)mean(x(hcInd)),np.Controls.inDegreeWei)';
id_hip_p = cellfun(@(x)mean(x(hcInd)),np.LRTLE.inDegreeWei)';
t_id_hip = ttest.ttest2Struct(id_hip_c,id_hip_p,'AlphaFDR',0.05,'Alpha',0.05);
t_id_hip_CT = ttest.ttest2Struct(id_hip_c,id_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_id_hip_HV = ttest.ttest2Struct(id_hip_c,id_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

plotAvgVsThetaScatterPanels({'Hip','Hip\_Neighb'}, {id_hip_c,id_hip_nei_c}, {id_hip_p,id_hip_nei_p}, [], ...
                            [t_id_hip.h,t_id_hip_nei.h], [t_id_hip.hFDR,t_id_hip_nei.hFDR], [t_id_hip_CT.hFDR,t_id_hip_nei_CT.hFDR], [t_id_hip_HV.hFDR,t_id_hip_nei_HV.hFDR], ...
                            'In deg', {'Controls','TLE'});

fprintf('In degree (Z-Score)\n');
fprintf('--------------------\n');
fprintf('* Hippocampus\n');
dispMeanStd(id_hip_c,id_hip_p,N);
disp(rmfield(t_id_hip,{'confInt','stats','alpha','alphaFDR','pFDR'}));
fprintf('  -\n');
fprintf('* Hippocampus neighbors (avg)\n');
dispMeanStd(id_hip_nei_c,id_hip_nei_p,N);
disp(rmfield(t_id_hip_nei,{'confInt','stats','alpha','alphaFDR','pFDR'}));

%%

bc_hip_nei_c = cellfun(@(x)mean(x(v_hcInd)),np.Controls.betweenCenWei)';
bc_hip_nei_p = cellfun(@(x)mean(x(v_hcInd)),np.LRTLE.betweenCenWei)';
t_bc_hip_nei = ttest.ttest2Struct(bc_hip_nei_c,bc_hip_nei_p,'AlphaFDR',0.05,'Alpha',0.05);
t_bc_hip_nei_CT = ttest.ttest2Struct(bc_hip_nei_c,bc_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_bc_hip_nei_HV = ttest.ttest2Struct(bc_hip_nei_c,bc_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

bc_hip_c = cellfun(@(x)mean(x(hcInd)),np.Controls.betweenCenWei)';
bc_hip_p = cellfun(@(x)mean(x(hcInd)),np.LRTLE.betweenCenWei)';
t_bc_hip = ttest.ttest2Struct(bc_hip_c,bc_hip_p,'AlphaFDR',0.05,'Alpha',0.05);
t_bc_hip_CT = ttest.ttest2Struct(bc_hip_c,bc_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_bc_hip_HV = ttest.ttest2Struct(bc_hip_c,bc_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

plotAvgVsThetaScatterPanels({'Hip','Hip\_Neighb'}, {bc_hip_c,bc_hip_nei_c}, {bc_hip_p,bc_hip_nei_p}, [], ...
                            [t_bc_hip.h,t_bc_hip_nei.h], [t_bc_hip.hFDR,t_bc_hip_nei.hFDR], [t_bc_hip_CT.hFDR,t_bc_hip_nei_CT.hFDR], [t_bc_hip_HV.hFDR,t_bc_hip_nei_HV.hFDR], ...
                            'Bet. centr.', {'Controls','TLE'});

fprintf('Betweeness centrality (Z-Score)\n');
fprintf('--------------------\n');
fprintf('* Hippocampus\n');
dispMeanStd(bc_hip_c,bc_hip_p,N);
disp(rmfield(t_bc_hip,{'confInt','stats','alpha','alphaFDR','pFDR'}));
fprintf('  -\n');
fprintf('* Hippocampus neighbors (avg)\n');
dispMeanStd(bc_hip_nei_c,bc_hip_nei_p,N);
disp(rmfield(t_bc_hip_nei,{'confInt','stats','alpha','alphaFDR','pFDR'}));

%%

cc_hip_nei_c = cellfun(@(x)mean(x(v_hcInd)),np.Controls.clusterCoeffWei)';
cc_hip_nei_p = cellfun(@(x)mean(x(v_hcInd)),np.LRTLE.clusterCoeffWei)';
t_cc_hip_nei = ttest.ttest2Struct(cc_hip_nei_c,cc_hip_nei_p,'AlphaFDR',0.05,'Alpha',0.05);
t_cc_hip_nei_CT = ttest.ttest2Struct(cc_hip_nei_c,cc_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_cc_hip_nei_HV = ttest.ttest2Struct(cc_hip_nei_c,cc_hip_nei_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

cc_hip_c = cellfun(@(x)mean(x(hcInd)),np.Controls.clusterCoeffWei)';
cc_hip_p = cellfun(@(x)mean(x(hcInd)),np.LRTLE.clusterCoeffWei)';
t_cc_hip = ttest.ttest2Struct(cc_hip_c,cc_hip_p,'AlphaFDR',0.05,'Alpha',0.05);
t_cc_hip_CT = ttest.ttest2Struct(cc_hip_c,cc_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.flip.cData.CT,'C1_y',ct.flip.pData.CT);
t_cc_hip_HV = ttest.ttest2Struct(cc_hip_c,cc_hip_p,'Alpha',0.05,'AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.cData.HV,'C1_y',hv.flip.pData.HV);

plotAvgVsThetaScatterPanels({'Hip','Hip\_Neighb'}, {cc_hip_c,cc_hip_nei_c}, {cc_hip_p,cc_hip_nei_p}, [], ...
                            [t_cc_hip.h,t_cc_hip_nei.h], [t_cc_hip.hFDR,t_cc_hip_nei.hFDR], [t_cc_hip_CT.hFDR,t_cc_hip_nei_CT.hFDR], [t_cc_hip_HV.hFDR,t_cc_hip_nei_HV.hFDR], ...
                            'Cluster coeff.', {'Controls','TLE'});

fprintf('Clustering coefficient (Z-Score)\n');
fprintf('--------------------\n');
fprintf('* Hippocampus\n');
dispMeanStd(cc_hip_c,cc_hip_p,N);
disp(rmfield(t_cc_hip,{'confInt','stats','alpha','alphaFDR','pFDR'}));
fprintf('  -\n');
fprintf('* Hippocampus neighbors (avg)\n');
dispMeanStd(cc_hip_nei_c,cc_hip_nei_p,N);
disp(rmfield(t_cc_hip_nei,{'confInt','stats','alpha','alphaFDR','pFDR'}));