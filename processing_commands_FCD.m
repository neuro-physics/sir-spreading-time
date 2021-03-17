addpath('func');

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
if ~(exist(dataDir,'dir') == 7)
    dataDir = fullfile('.','aux_files');
end

%%

% cdb = load(fullfile(dataDir,'TLE_NB_BB.mat'));
cdb = load(fullfile(dataDir,'FCD_table.mat'));

[~,~,~,aal]=aalsurfview(zeros(90,1));

%%

currDir = pwd;
cd(fullfile(dataDir,'fcd'))
casesMetaData = generate_patient_table('FCD_table.mat');
copyfile(fullfile(dataDir,'fcd','FCD_table.mat'),dataDir,'f');
cd(currDir);
[~,~,ptf] = calc_cortical_thickness(true,fullfile(dataDir,'fcd','thickness'),fullfile(dataDir,'fcd','thickness'),'FCD_table.mat');
copyfile(ptf,fullfile(dataDir,'fcd'),'f');

%% filtering adjacency matrices

%backboneFilterAdjMatrix(                                       input,   method,                                          outputDir, groups, hipPath, nedaSelected, patientTableFile)
backboneFilterAdjMatrix(fullfile(dataDir,'fcd','selected','*FA*.mat'),    'raw',    fullfile(dataDir,'fcd','selected','filter_raw'), [], [], [], 'FCD_table.mat');
backboneFilterAdjMatrix(fullfile(dataDir,'fcd','selected','*FA*.mat'), 'length', fullfile(dataDir,'fcd','selected','filter_length'), [], [], [], 'FCD_table.mat');

%% parse spreading data

% parse simulation files and saves weighted and binary sp times in separate files
% does not perform individual z-score before z-scoring to controls
parseSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306'),fullfile(dataDir,'sirs','fcd_selected','N306','si_data.mat'),false,false,false,'',true,true,'NC');
clear all
dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
parseSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306'),fullfile(dataDir,'sirs','fcd_selected','N306','si_data_pre.mat'),false,false,false,'',true,true,'FCD_PREOP');
clear all
dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
parseSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306'),fullfile(dataDir,'sirs','fcd_selected','N306','si_data_post.mat'),false,false,false,'',true,true,'FCD_POSTOP');

% parse simulation files and saves weighted and binary sp times in separate files
% performs individual z-score before z-scoring to controls
%parseSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306'),fullfile(dataDir,'sirs','fcd_selected','N306','si_data.mat'),false,false,true,'',true,true);

%% calc network properties for all subjects

patient_groups = unique(regexprep(cdb.casesMetaData.Group,'_\d+',''))';
tic;
network.calcNetworkPropertiesGroups(fullfile(dataDir,'fcd','selected'),fullfile(dataDir,'sirs','fcd_selected','N306','net_prop.mat'),patient_groups,[],100,50,aal.labels.AAL306,0,0,'FCD_table.mat','');
network.calcNetworkPropertiesGroups(fullfile(dataDir,'fcd','selected'),fullfile(dataDir,'sirs','fcd_selected','N306','net_prop_Z.mat'),patient_groups,[],100,50,aal.labels.AAL306,0,1,'FCD_table.mat','');
toc

%% calc comm and short path for std data

%load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat')); % inputs variable aal_labels
[~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1}, 'AND');
calcCommunities(fullfile(dataDir,'fcd','selected','*FA*.mat'), 1:0.5:3.5, 10, aal.labels.AAL306, true, fullfile(dataDir,'sirs','fcd_selected','N306','comm.mat'), caseNames);
calcShortestPath(fullfile(dataDir,'fcd','selected','*FA*.mat'), true, fullfile(dataDir,'sirs','fcd_selected','N306','shortPath.mat'));

%% process std data for paper

si = load(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_w.mat'));
p = calcPostopImprovement(si.SpMatrixW,si.caseName,cdb,'FCD_PREOP','','','D:\Dropbox\p\postdoc\data\fcd\fiber_length');
save(fullfile(dataDir,'sirs','fcd_selected','N306','postop_imp.mat'),'p','-v7.3')

%%

ttestPropSplit = { 'AlphaTTest',0.01,'AlphaFDR',0.00001,'SplitNegPos','on' };
patient_groups = unique(regexprep(cdb.casesMetaData.Group,'_\d+',''))';
patient_groups(strcmp(patient_groups,'NC')) = [];
patient_hp = cell(size(patient_groups));

% paper data
processSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_w.mat'), '', '', patient_groups, patient_hp, 1, 0, [], ttestPropSplit, ['sim_data_alpha0.01_spTT_w_alphaFDR',num2str(ttestPropSplit{4}),'.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol');
processSpreadingData(  fullfile(dataDir,'sirs','fcd_selected','N306','si_data.mat'), '', '', patient_groups, patient_hp, 1, 0, [], ttestPropSplit, [  'sim_data_alpha0.01_spTT_alphaFDR',num2str(ttestPropSplit{4}),'.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol');

%% comparting postop with postopsim

processSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_post_w.mat'), '', '', { 'FCD_POSTOPSIM' }, {}, 1, 0, [], ttestPropSplit, ['sim_data_alpha0.01_spTT_w_alphaFDR',num2str(ttestPropSplit{4}),'_postpost.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_POSTOP');
processSpreadingData(  fullfile(dataDir,'sirs','fcd_selected','N306','si_data_post.mat'), '', '', { 'FCD_POSTOPSIM' }, {}, 1, 0, [], ttestPropSplit, [  'sim_data_alpha0.01_spTT_alphaFDR',num2str(ttestPropSplit{4}),'_postpost.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_POSTOP');

%% comparting preop with postop

processSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_pre_w.mat'), '', '', { 'FCD_POSTOP' }, {}, 1, 0, [], ttestPropSplit, ['sim_data_alpha0.01_spTT_w_alphaFDR',num2str(ttestPropSplit{4}),'_prepost.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_PREOP');
processSpreadingData(  fullfile(dataDir,'sirs','fcd_selected','N306','si_data_pre.mat'), '', '', { 'FCD_POSTOP' }, {}, 1, 0, [], ttestPropSplit, [  'sim_data_alpha0.01_spTT_alphaFDR',num2str(ttestPropSplit{4}),'_prepost.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_PREOP');

%% comparting preop with postopsim

processSpreadingData(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_pre_w.mat'), '', '', { 'FCD_POSTOPSIM' }, {}, 1, 0, [], ttestPropSplit, ['sim_data_alpha0.01_spTT_w_alphaFDR',num2str(ttestPropSplit{4}),'_prepostsim.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_PREOP');
processSpreadingData(  fullfile(dataDir,'sirs','fcd_selected','N306','si_data_pre.mat'), '', '', { 'FCD_POSTOPSIM' }, {}, 1, 0, [], ttestPropSplit, [  'sim_data_alpha0.01_spTT_alphaFDR',num2str(ttestPropSplit{4}),'_prepostsim.mat'], 0, 0, 1, 'FCD_table.mat', 'CavVol', 'FCD_PREOP');