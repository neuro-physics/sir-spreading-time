clearvars
close all

addpath func

[~,~,~,aal] = aalsurfview(zeros(90,1));

[A_FA,caseName_FA] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*_FA_AAL_midres.mat');
[pInd_FA,cInd_FA] = getPatientControlInd(caseName_FA);
rtle_ind = getRTLEIndices(caseName_FA);
A_FA = flipAALMatrix_rowsPerCols(A_FA,aal,rtle_ind);

[A_FL,caseName_FL] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected_dist\TLE_*_dist_AAL_midres.mat');
[pInd_FL,cInd_FL] = getPatientControlInd(caseName_FL);
rtle_ind = getRTLEIndices(caseName_FL);
A_FL = flipAALMatrix_rowsPerCols(A_FL,aal,rtle_ind);

% z-scoring FA and FL
A_FA_z = zScoreToSubset(A_FA, cInd_FA);
A_FL_z = zScoreToSubset(A_FL, cInd_FL);

alphaTTest = 0.01;
alphaFDR = 0.05;

si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');
cdb = load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat');
hv = getHippVolumeStruct(cdb, si.caseName,'HipVol','NC');

is_si_and_FA_same_order = all(cellfun(@(x,y)strcmpi(x,y),si.caseName,caseName_FA));
is_si_and_FL_same_order = all(cellfun(@(x,y)strcmpi(x,y),si.caseName,caseName_FL));
if ~is_si_and_FA_same_order
    disp('FA and si cases are not in the same order! sort the cases before running again... aborting...')
    return
end
if ~is_si_and_FL_same_order
    disp('FL and si cases are not in the same order! sort the cases before running again... aborting...')
    return
end
cInd = cInd_FA;
pInd = pInd_FA;

saveOutputFigures = false;

%%

fa_per_node_c = squeeze(mean(reshapeLines(matCell2Mat(A_FA(cInd_FA)),size(A_FA{1}),'3darray'),1,'omitnan'))';
fa_per_node_p = squeeze(mean(reshapeLines(matCell2Mat(A_FA(pInd_FA)),size(A_FA{1}),'3darray'),1,'omitnan'))';
[fa_z_per_node_c,fa_z_per_node_p] = zScoreToControls(fa_per_node_c,fa_per_node_p,1);

fl_per_node_c = squeeze(mean(reshapeLines(matCell2Mat(A_FL(cInd_FL)),size(A_FL{1}),'3darray'),1,'omitnan'))';
fl_per_node_p = squeeze(mean(reshapeLines(matCell2Mat(A_FL(pInd_FL)),size(A_FL{1}),'3darray'),1,'omitnan'))';
[fl_z_per_node_c,fl_z_per_node_p] = zScoreToControls(fl_per_node_c,fl_per_node_p,1);

%%

tt_in = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
                       
tt_ou = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);

[~,~,~,cLim_effsz] = plot_func.plot_effsz_pat_con(tt_in,tt_ou);
                       
%%

tt_in_hv = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                           'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.Vol(cInd),'C1_y',hv.flip.Vol(pInd));
                       
tt_ou_hv = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                           'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.flip.Vol(cInd),'C1_y',hv.flip.Vol(pInd));

plot_func.plot_effsz_pat_con(tt_in_hv,tt_ou_hv,cLim_effsz)

%%

tt_in_fa = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(cInd)),...
                              matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                              'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',fa_per_node_c,'C1_y',fa_per_node_p);
                       
tt_ou_fa = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                           'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',fa_per_node_c,'C1_y',fa_per_node_p);

plot_func.plot_effsz_pat_con(tt_in_fa,tt_ou_fa,cLim_effsz)

%%

tt_in_fl = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(cInd)),...
                              matCell2Mat(si.SpMatrixW(4).flipData.SAvgR(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                              'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',fl_per_node_c,'C1_y',fl_per_node_p);
                       
tt_ou_fl = ttest.ttest2Struct(matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(cInd)),...
                           matCell2Mat(si.SpMatrixW(4).flipData.SAvgS(pInd)),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,...
                           'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',fl_per_node_c,'C1_y',fl_per_node_p);

fh = plot_func.plot_effsz_pat_con(tt_in_fl,tt_ou_fl,cLim_effsz);

if saveOutputFigures
    saveFigure(fh, fullfile('corr_fig',{'sptime_in_group_diff_Dist','sptime_out_group_diff_Dist'}), 'tiff', true, [], 600);
end