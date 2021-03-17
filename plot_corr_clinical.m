%% loading data

addpath func

clearvars -except si
close all


N = 306;
dataDir = 'D:\Dropbox\p\postdoc\data\sirs\selected';
if exist('si','var') ~= 1
    si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\sim_data_alpha0.01_spTT_w.mat');
else
    warning('*** using the variable si that is already in memory')
end

[~,~,~,aal]=aalsurfview(zeros(90,1));

cdb = load(fullfile(dataDir,'..','..','TLE_NB_BB.mat'));

thetaInd = find(si.LRTLE.SpMatrixW.theta == 0.015);

saveOutputFigures = false;
newOutputDir = 'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\figs_weiSpTime_spTT_fdr';

%% fixing data

[T_con,T_pat] = selectCasesFromPatientStruct(cdb.casesMetaData,si.LRTLE.controlCode,si.LRTLE.patientCode);
T_con = dataToNaN(T_con);
T_pat = dataToNaN(T_pat);

hv = getHipVolStruct(cdb,[si.LRTLE.controlCode,si.LRTLE.patientCode]);%getHippVolumeStruct(cdb, [si.LRTLE.controlCode,si.LRTLE.patientCode], 'HipVol', 'NC');
ct = getCortThickStruct(fullfile(dataDir,'..','..','cortical_thickness_sel.mat'),[si.LRTLE.controlCode,si.LRTLE.patientCode],N);

%%

disp('*** correlations between Sp times and HV')
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd},hv.flip.cData.HV);
fprintf('   * Controls:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd},hv.flip.pData.HV);
fprintf('   * Patients:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));

disp('-')

disp('*** correlations between Sp times and CT')
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd},ct.flip.cData.CT);
fprintf('   * Controls:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd},ct.flip.pData.CT);
fprintf('   * Patients:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));

disp('-')

disp('*** correlations between Sp times and seizure onset')
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd},zscore(T_pat.Onset));
fprintf('   * Patients:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));

disp('-')

disp('*** correlations between Sp times and epilepsy duration')
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd},zscore(T_pat.Duration));
fprintf('   * Patients:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));

disp('-')

disp('*** correlations between Sp times and Age')
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd},zscore(T_con.Age));
fprintf('   * Controls:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));
[R,P] = corrcoef(si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd},zscore(T_pat.Age));
fprintf('   * Patients:    R = %.4g     P = %.4g\n',R(1,2),P(1,2));

%% correlation between HV and CT and Sp times

nControls = numel(hv.flip.cData.HV);
nPatients = numel(hv.flip.pData.HV);

S = [si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd};si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}];
HV1 = [hv.flip.cData.HV(:);hv.flip.pData.HV(:)];
CT1 = [ct.flip.cData.CT(:);ct.flip.pData.CT(:)];
Onset1 = [zeros(nControls,1);zscore(T_pat.Onset(:))];
Group = [ ones(nControls,1); 2.*ones(nPatients,1) ];

mdl = fitlm(Group,S,'linear','CategoricalVars',1,'VarNames',{'Group','S'})
mdl_HV0 = fitlm([Group,HV1],S,'linear','CategoricalVars',1,'VarNames',{'Group','HV','S'})
mdl_CT0 = fitlm([Group,CT1],S,'linear','CategoricalVars',1,'VarNames',{'Group','CT','S'})
mdl_On0 = fitlm([Group,Onset1],S,'linear','CategoricalVars',1,'VarNames',{'Group','Onset','S'})
mdl_HV1 = fitlm([Group,HV1],S,'interactions','CategoricalVars',1,'VarNames',{'Group','HV','S'})
mdl_CT1 = fitlm([Group,CT1],S,'interactions','CategoricalVars',1,'VarNames',{'Group','CT','S'})
mdl_On1 = fitlm([Group,Onset1],S,'interactions','CategoricalVars',1,'VarNames',{'Group','Onset','S'})


%% correlation between seizure onset and duration and spreading times using SurfStat (terrible choice)

nControls = numel(hv.flip.cData.HV);
nPatients = numel(hv.flip.pData.HV);

S = [si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd};si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}];
Onset = termSurfStat([zeros(nControls,1);zscore(T_pat.Onset(:))],'Onset');
Duration = termSurfStat([zeros(nControls,1);zscore(T_pat.Duration(:))],'Duration');
Group = termSurfStat([ repmat({'NC'},nControls,1); repmat({'TLE'},nPatients,1) ]);
ModelOns0 = 1+Group+Onset;
ModelOns1 = 1+Group+Onset+Group*Onset;
ModelDur1 = 1+Group+Duration+Group*Duration;
slm = SurfStatLinMod(S,ModelOns0);
slm = SurfStatT(slm,Group.NC-Group.TLE)
P = SurfStatP(slm)

figure;
[ t, df, pval, slm, slm0 ] = SurfStatPlot(Onset.Onset,S,1,Group);
slm0 = SurfStatT(slm0,Group.NC-Group.TLE);
P = SurfStatP(slm);
P0 = SurfStatP(slm0);

figure;
[ t, df, pval, slm, slm0 ] = SurfStatPlot(Duration.Duration,S,1,Group);
slm0 = SurfStatT(slm0,Group.NC-Group.TLE);

%% correlation between HV and CT and spreading times using SurfStat (terrible choice)

nControls = numel(hv.flip.cData.HV);
nPatients = numel(hv.flip.pData.HV);

S = [si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd};si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}];
HV = termSurfStat([hv.flip.cData.HV(:);hv.flip.pData.HV(:)],'HV');
CT = termSurfStat([ct.flip.cData.CT(:);ct.flip.pData.CT(:)],'CT');
Group = termSurfStat([ repmat({'NC'},nControls,1); repmat({'TLE'},nPatients,1) ]);
Model = 1+Group+HV+Group*HV;
[ t, df, pval, slm, slm0 ] = SurfStatPlot(HV.HV,S,1,Group);
slm0 = SurfStatT(slm0,Group.NC-Group.TLE);
% slm = SurfStatLinMod(S,Model);
% slm = SurfStatT(slm,HV.HV.*Group.NC-HV.HV.*Group.TLE);

%% plotting correlations HV, Onset, CT with Sp times paper

disp('*** Correlation between avg sp times and epilepsy onset (linear)')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.flip.controlData,si.LRTLE.SpMatrixW.flip.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,[],false,false)
[fh1,axh1,th1] = plotScatterCorr([],[],T_pat.Onset(:),si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}(:),...
                                 T_con.Onset(:),si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd}(:),'Epilepsy onset (yr)','Avg. Sp. Time (Z)',[],'',{'Location','best','Box','on'},false,false,'%.2g',8);
axh1.Position = [0.140625 0.15 0.606120283018867 0.591572327044025];
legend(axh1,'Position', [0.50688600375164 0.616201474556873 0.226951358361685 0.105327561053939]);

disp('*** Correlation between avg sp times HV')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.flip.controlData,si.LRTLE.SpMatrixW.flip.patientData,'SAll_theta',...
                                            hv.flip.cData,hv.flip.pData,'HV',false,false,si.LRTLE.SpMatrixW.theta,[],false,false)
[fh2,axh2,th2] = plotScatterCorr([],[],hv.flip.pData.HV(:),si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}(:),...
                                 hv.flip.cData.HV(:),si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd}(:),'Hippocampus volume (Z)','Avg. Sp. Time (Z)',[],'',{'Location','best','Box','on'},false,false,'%.2g',8);
axh2.Position = [0.140625 0.15 0.606120283018867 0.591572327044025];
legend(axh2,'Position', [0.50688600375164 0.616201474556873 0.226951358361685 0.105327561053939]);
th2(2).Position = [-4.76594240383693 -0.198315118397086 0];
th2(4).Position = [-4.7504508833336 -0.379326047358834 0];

disp('*** Correlation between avg sp times CT')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.flip.controlData,si.LRTLE.SpMatrixW.flip.patientData,'SAll_theta',...
                                            ct.flip.cData,ct.flip.pData,'CT',false,false,si.LRTLE.SpMatrixW.theta,[],false,false)
[fh3,axh3,th3] = plotScatterCorr([],[],ct.flip.pData.CT(:),si.LRTLE.SpMatrixW.flip.patientData.SAll_theta{thetaInd}(:),...
                                 ct.flip.cData.CT(:),si.LRTLE.SpMatrixW.flip.controlData.SAll_theta{thetaInd}(:),'Cortical thickness (Z)','Avg. Sp. Time (Z)',[],'',{'Location','best','Box','on'},false,false,'%.2g',8);
axh3.Position = [0.140625 0.15 0.606120283018867 0.591572327044025];
legend(axh3,'Position', [0.50688600375164 0.616201474556873 0.226951358361685 0.105327561053939]);
th3(2).Position = [-1.97694035224889 -0.198315118397086 1.4210854715202e-14];
th3(4).Position = [-1.92861164779286 -0.379818594104308 1.4210854715202e-14];

if saveOutputFigures
    fh1 = cropFigure(fh1,10);
    fh2 = cropFigure(fh2,10);
    fh3 = cropFigure(fh3,10);
    saveFigure([fh1,fh2,fh3],fullfile(newOutputDir,{'corr_sptime_onset','corr_sptime_HV','corr_sptime_CT'}), 'tiff', true, {}, 600);
end

%%

disp('*** Correlation between avg sp times and epilepsy duration (linear) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',false,false,si.LRTLE.SpMatrixW.theta,[],true,true)
[fh1,axh1] = plotScatterCorr([],[],T_pat.Duration(:),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                 T_con.Duration(:),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy duration (yr)','Avg. Sp. Time',[],'',{'Location','best','Box','on'},true,true);
title(axh1,'Avg. Sp Time vs. Epilepsy Duration');

disp('*** Correlation between avg sp times and epilepsy onset (linear) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,[],true,true)
[fh2,axh2] = plotScatterCorr([],[],zscore(T_pat.Onset(:)),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                 T_con.Onset(:),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy onset (yr)','Avg. Sp. Time',[],'',{'Location','best','Box','on'},true,true);
title(axh2,'Avg. Sp Time vs. Epilepsy Onset');

disp('*** Correlation between epilepsy onset and epilepsy duration (linear) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(T_con,T_pat,'Duration',...
    T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,[],true,true)
[fh3,axh3] = plotScatterCorr([],[],T_pat.Onset(:),T_pat.Duration(:),...
    T_con.Onset(:),T_con.Duration(:),'Epilepsy onset (yr)','Epilepsy duration (yr)',[],'',{'Location','best','Box','on'},true,true);
title(axh3,'Epilepsy Duration vs. Epilepsy Onset');

%%

disp('*** Correlation between inverse avg sp times and epilepsy duration (linear) -- no z-scoring')
%                   corrcoef_datastruct_cli(SpMat_con,                                          SpMat_pat,SFieldName,
%                                           B_con,B_pat,BFieldName,useInverseSpTimes,zScoreData,theta,funcForClin)
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',true,false,si.LRTLE.SpMatrixW.theta)
[fh1,axh1] = plotScatterCorr([],[],T_pat.Duration(:),1./si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                 T_con.Duration(:),1./si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy duration (yr)','Avg. Sp. Time',[],'');

%%             
disp('*** Correlation between inverse avg sp times and epilepsy duration (linear) -- no z-scoring')
%                   corrcoef_datastruct_cli(SpMat_con,                                          SpMat_pat,SFieldName,
%                                           B_con,B_pat,BFieldName,useInverseSpTimes,zScoreData,theta,funcForClin)
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',true,false,si.LRTLE.SpMatrixW.theta)
[fh1,axh1] = plotScatterCorr([],[],T_pat.Duration(:),1./si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                 T_con.Duration(:),1./si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy duration (yr)','Avg. Sp. Time',[],'');
%%

disp('*** Correlation between avg sp times and epilepsy duration (sqr root) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',false,false,si.LRTLE.SpMatrixW.theta,@(x)sqrt(x))
[fh2,axh2] = plotScatterCorr([],[],sqrt(T_pat.Duration(:)),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   sqrt(T_con.Duration(:)),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Sqrt of Epilepsy duration','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy duration (log) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',false,false,si.LRTLE.SpMatrixW.theta,@(x)log(x))
[fh3,axh3] = plotScatterCorr([],[],log(T_pat.Duration(:)),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   log(T_con.Duration(:)),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Log of Epilepsy duration','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy duration (sqr) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',false,false,si.LRTLE.SpMatrixW.theta,@(x)x.^2)
[fh4,axh4] = plotScatterCorr([],[],(T_pat.Duration(:)).^2,si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   (T_con.Duration(:)).^2,si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy duration squared','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy duration (cubic) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Duration',false,false,si.LRTLE.SpMatrixW.theta,@(x)x.^3)
[fh5,axh5] = plotScatterCorr([],[],(T_pat.Duration(:)).^3,si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   (T_con.Duration(:)).^3,si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy duration cubed','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy onset (sqr root) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,@(x)sqrt(x))
[fh2,axh2] = plotScatterCorr([],[],sqrt(T_pat.Onset(:)),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   sqrt(T_con.Onset(:)),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Sqrt of onset duration','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy Onset (log) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,@(x)log(x))
[fh3,axh3] = plotScatterCorr([],[],log(T_pat.Onset(:)),si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   log(T_con.Onset(:)),si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Log of onset duration','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy Onset (sqr) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,@(x)x.^2)
[fh4,axh4] = plotScatterCorr([],[],(T_pat.Onset(:)).^2,si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   (T_con.Onset(:)).^2,si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy onset squared','Avg. Sp. Time',[],'');

disp('*** Correlation between avg sp times and epilepsy Onset (cubic) -- no z-scoring')
[r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(si.LRTLE.SpMatrixW.controlData,si.LRTLE.SpMatrixW.patientData,'SAll_theta',...
                                            T_con,T_pat,'Onset',false,false,si.LRTLE.SpMatrixW.theta,@(x)x.^3)
[fh5,axh5] = plotScatterCorr([],[],(T_pat.Onset(:)).^3,si.LRTLE.SpMatrixW.patientData.SAll_theta{thetaInd}(:),...
                                   (T_con.Onset(:)).^3,si.LRTLE.SpMatrixW.controlData.SAll_theta{thetaInd}(:),'Epilepsy onset cubed','Avg. Sp. Time',[],'');