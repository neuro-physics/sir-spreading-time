close all
clearvars

addpath('func');

thetaVal = 0.01;
alphaTTest = 0.05;
fdrRate = 0.1;
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };

% Group 1
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% sortType = 'comm';

% Group 2
patientGroup = { 'LTLE' };
patientHipPath = { 'HS' };
nedaSelected = true;
sortType = 'lr';

% Group 3
% patientGroup = { 'RTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% sortType = 'lr';

data = load('D:\Dropbox\p\postdoc\data\sirs\N90\si_data.mat');
caseName = data.caseName;
data = data.TwoSeeds(strcmp({data.TwoSeeds(:).seedMode},'competitive'));
load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat'); % inputs variable aal_labels

casesMetaData=load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat'); % inputs variable casesMetaData
casesMetaData=casesMetaData.casesMetaData;

%%

[pInd,cInd] = getCasesIndices(caseName, casesMetaData, patientGroup, patientHipPath, nedaSelected);

nFiles = numel(data);
N = data(1).N;
nCases = numel(caseName);
nC = numel(cInd);
nP = numel(pInd);

theta = [data(:).theta];
tInd = find(theta == thetaVal);

%% entropy calculation

HZ_Avg_control = meanMatrix(data(tInd).data.H_Z(cInd));
HZ_Avg_patient = meanMatrix(data(tInd).data.H_Z(pInd));

HZ_control = [ data(tInd).data.H_Z{cInd} ]'; % each row is a observation of a given node state; each col is a different node of the network
HZ_patient = [ data(tInd).data.H_Z{pInd} ]'; % each row is a observation of a given node state; each col is a different node of the network

[h,p,ci,st] = ttest2(HZ_control,HZ_patient,'Alpha',alphaTTest);
aalsurfview(h,'H',hot);
disp('Entropy differs between controls and patients in')
aal_labels(find(h))
%[~,p,~,~] = ttest2(HZ_control,HZ_patient,'Alpha',alphaTTest,'Vartype','unequal');
% alphaFDR = FDR(p,fdrRate);
% [h,p,ci,st] = ttest2(HZ_control,HZ_patient,'Alpha',alphaFDR,'Vartype','unequal');

%% conformity calculation

CfZ_Avg_control = meanMatrix(data(tInd).data.Cf_Z(cInd));
CfZ_Avg_patient = meanMatrix(data(tInd).data.Cf_Z(pInd));

CfZ_control = [ data(tInd).data.Cf_Z{cInd} ]'; % each row is a observation of a given node state; each col is a different node of the network
CfZ_patient = [ data(tInd).data.Cf_Z{pInd} ]'; % each row is a observation of a given node state; each col is a different node of the network

[h,p,ci,st] = ttest2(CfZ_control,CfZ_patient,'Alpha',alphaTTest);
aalsurfview(h,'H',hot);
disp('Conformity differs between controls and patients in:')
aal_labels(find(h))

%% avalanche size calculation

CpZ_Avg_control = meanMatrix(data(tInd).data.Cp1_Z(cInd));
CpZ_Avg_patient = meanMatrix(data(tInd).data.Cp1_Z(pInd));
CpZ_Avg_control = mean(CpZ_Avg_control,2);
CpZ_Avg_patient = mean(CpZ_Avg_patient,2);

CpTemp = meanCells(data(tInd).data.Cp1_Z(cInd),2,'omitnan');
CpZ_control = [ CpTemp{:} ]'; % each row is a observation of a given node state; each col is a different node of the network
CpTemp = meanCells(data(tInd).data.Cp1_Z(pInd),2,'omitnan');
CpZ_patient = [ CpTemp{:} ]'; % each row is a observation of a given node state; each col is a different node of the network

[h,p,ci,st] = ttest2(CpZ_control,CpZ_patient,'Alpha',alphaTTest);
aalsurfview(h,'H',hot);
disp('Mean avalanche size differs between controls and patients in:')
aal_labels(find(h))
