addpath('func');

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
if ~(exist(dataDir,'dir') == 7)
    dataDir = fullfile('.','aux_files');
end

cdb = load(fullfile(dataDir,'TLE_NB_BB.mat'));
% cdb = load(fullfile(dataDir,'FCD_table.mat'));

%% filtering adjacency matrices

backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 'raw', fullfile(dataDir,'AALmatrix_N90','filter_raw'));
backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 'length', fullfile(dataDir,'AALmatrix_N90','filter_length'));
backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 'raw', fullfile(dataDir,'AALmatrix_N306','filter_raw'));
backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 'length', fullfile(dataDir,'AALmatrix_N306','filter_length'));

backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 'raw', fullfile(dataDir,'AALmatrix_N90','filter_HS'), {'RTLE','LTLE'}, {'HS'}, 1);
backboneFilterAdjMatrix(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 'raw', fullfile(dataDir,'AALmatrix_N306','filter_HS'), {'RTLE','LTLE'}, {'HS'}, 1);

%% parse spreading data

% parse simulation files and saves weighted and binary sp times in separate files
% does not perform individual z-score before z-scoring to controls
parseSpreadingData(fullfile(dataDir,'sirs','selected','N90'),fullfile(dataDir,'sirs','selected','N90','si_data.mat'),[],true,false,'',true,true);
parseSpreadingData(fullfile(dataDir,'sirs','selected','N306'),fullfile(dataDir,'sirs','selected','N306','si_data.mat'),[],true,false,'',true,true);

% parse simulation files and saves weighted and binary sp times in separate files
% performs individual z-score before z-scoring to controls
parseSpreadingData(fullfile(dataDir,'sirs','selected','N90'),fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'),[],true,true,'',true,true);
parseSpreadingData(fullfile(dataDir,'sirs','selected','N306'),fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'),[],true,true,'',true,true);

parseSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N90'),fullfile(dataDir,'sirs','flipped_cols','N90','si_data.mat'),[],false);
parseSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N306'),fullfile(dataDir,'sirs','flipped_cols','N306','si_data.mat'),[],false);

parseSpreadingData(fullfile(dataDir,'sirs','N90'),fullfile(dataDir,'sirs','N90','si_data.mat'));
parseSpreadingData(fullfile(dataDir,'sirs','N306'),fullfile(dataDir,'sirs','N306','si_data.mat'));
parseSpreadingData(fullfile(dataDir,'sirs','CoCoMac'),fullfile(dataDir,'sirs','CoCoMac','si_data.mat'));

parseSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N90'),fullfile(dataDir,'sirs','cons_filter_HS','N90','si_data.mat'));
parseSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N306'),fullfile(dataDir,'sirs','cons_filter_HS','N306','si_data.mat'));

parseSpreadingData(fullfile(dataDir,'sirs','cons_filter','N90'),fullfile(dataDir,'sirs','cons_filter','N90','si_data.mat'));
parseSpreadingData(fullfile(dataDir,'sirs','cons_filter','N306'),fullfile(dataDir,'sirs','cons_filter','N306','si_data.mat'));

parseSpreadingData(fullfile(dataDir,'sirs','consensus','N90'),fullfile(dataDir,'sirs','consensus','N90','si_data.mat'));
parseSpreadingData(fullfile(dataDir,'sirs','consensus','N306'),fullfile(dataDir,'sirs','consensus','N306','si_data.mat'));

parseSpreadingData(fullfile(dataDir,'sirs','actthresh','N90'),fullfile(dataDir,'sirs','actthresh','N90','si_data.mat'), true);
parseSpreadingData(fullfile(dataDir,'sirs','actthresh','N306'),fullfile(dataDir,'sirs','actthresh','N306','si_data.mat'), true);

%% calc network properties for all subjects

[~,~,~,aal] = aalsurfview(zeros(90,1));

network.calcNetworkProperties(fullfile(dataDir,'rhesus_data','rhesus_adj_matrix.mat'),fullfile(dataDir,'sirs','CoCoMac','net_prop.mat'),[],[],[],lab_ccm.aal_labels);

tic;
network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N90','selected'), fullfile(dataDir,'sirs','selected','N90','net_prop.mat'), {{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50,aal.labels.AAL90);
network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N306','selected'),fullfile(dataDir,'sirs','selected','N306','net_prop.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50,aal.labels.AAL306);
network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N90','selected'), fullfile(dataDir,'sirs','selected','N90','net_prop_flip_Z.mat'), {{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50,aal.labels.AAL90,1,1);
network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N306','selected'),fullfile(dataDir,'sirs','selected','N306','net_prop_flip_Z.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50,aal.labels.AAL306,1,1);
toc

tic;
processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
toc

tic;
processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data_z.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data_z.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data_z.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
toc

%% calc comm and short path for std data

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'));
[~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
calcCommunities(fullfile(dataDir,'AALmatrix_N90','selected','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','selected','N90','comm.mat'), caseNames);
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N90','shortPath.mat'));
calcCommunicability(fullfile(dataDir,'AALmatrix_N90','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N90','communic.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'));
[~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
calcCommunities(fullfile(dataDir,'AALmatrix_N306','selected','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','selected','N306','comm.mat'), caseNames);
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N306','shortPath.mat'));
calcCommunicability(fullfile(dataDir,'AALmatrix_N306','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N306','communic.mat'));

load(fullfile(dataDir,'rhesus_data','rhesus_labels.mat'))
calcCommunities(fullfile(dataDir,'rhesus_data','rhesus_adj_matrix.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','CoCoMac','comm.mat'))
calcShortestPath(fullfile(dataDir,'rhesus_adj_matrix.mat'), true, fullfile(dataDir,'sirs','CoCoMac','shortPath.mat'));
calcCommunicability(fullfile(dataDir,'rhesus_adj_matrix.mat'), true, fullfile(dataDir,'sirs','CoCoMac','communic.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','N90','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','N90','shortPath.mat'));
calcCommunicability(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','N90','communic.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','N306','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','N306','shortPath.mat'));
calcCommunicability(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','N306','communic.mat'));

%% calc comm short path flipped data

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'));
[~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
calcCommunities(fullfile(dataDir,'AALmatrix_N90','flipped_cols','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','flipped_cols','N90','comm.mat'), caseNames);
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','flipped_cols','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','flipped_cols','N90','shortPath.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'));
[~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
calcCommunities(fullfile(dataDir,'AALmatrix_N306','flipped_cols','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','flipped_cols','N306','comm.mat'), caseNames);
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','flipped_cols','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','flipped_cols','N306','shortPath.mat'));

%% calc comm short path for consensus filtered data

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N90','filter_raw','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','cons_filter','N90','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','filter_raw','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','cons_filter','N90','shortPath.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N306','filter_raw','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','cons_filter','N306','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','filter_raw','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','cons_filter','N306','shortPath.mat'));

%% calc comm short path for consensus filtered data (only HS)

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N90','filter_HS','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','cons_filter_HS','N90','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','filter_HS','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','cons_filter_HS','N90','shortPath.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N306','filter_HS','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','cons_filter_HS','N306','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','filter_HS','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','cons_filter_HS','N306','shortPath.mat'));

%% calc comm and short path for consensus data

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','consensus','N90','comm.mat'));
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','consensus*.mat'), true, fullfile(dataDir,'sirs','consensus','N90','shortPath.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','consensus','N306','comm.mat'));
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','consensus*.mat'), true, fullfile(dataDir,'sirs','consensus','N306','shortPath.mat'));

%% calc comm and short path for activation threshold data

load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','actthresh','N90','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','actthresh','N90','shortPath.mat'));

load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'))
calcCommunities(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','actthresh','N306','comm.mat'))
calcShortestPath(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','actthresh','N306','shortPath.mat'));

%% process std data for paper

ttestProp = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','off', 'UseSurfStat', 'on' };
ttestPropSplit = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','on', 'UseSurfStat', 'on' };

% paper data
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w_comm_fix.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);

%%

% t-tests are performed on the averages of variables
% does not split t-test over less and greater than zero averages
% std spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01.mat', 0, 0);
toc

% t-tests are performed on the averages of variables
% splits t-test over less and greater than zero averages
% std spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT.mat', 0, 0);
toc

% t-tests are performed on the averages of variables
% does not split t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_w.mat', 0, 0);
toc

% t-tests are performed on the averages of variables
% splits t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
toc

%%

ttestProp = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','off' };
ttestPropSplit = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','on' };

% t-tests are performed on the sample (not the averages) of variables
% does not split t-test over less and greater than zero averages
% std spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT.mat', 0, 0, false);
toc

% t-tests are performed on the sample (not the averages) of variables
% splits t-test over less and greater than zero averages
% std spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT.mat', 0, 0, false);
toc

% t-tests are performed on the sample (not the averages) of variables
% does not split t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT_w.mat', 0, 0, false);
toc

% t-tests are performed on the sample (not the averages) of variables
% splits t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
toc

%%

tic;
processSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N90','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N90','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N306','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','flipped_cols','N306','si_data.mat'), '', '', { {'RTLE','LTLE'} }, { {'HS'} }, 1, 0, [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
toc

tic;
processSpreadingData(fullfile(dataDir,'sirs','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','CoCoMac','si_data.mat'), '', '', [], [], [], [], [], ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','CoCoMac','si_data.mat'), '', '', [], [], [], [], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','CoCoMac','si_data.mat'), '', '', [], [], [], [], [], 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','CoCoMac','si_data.mat'), '', '', [], [], [], [], [], 0.05, 0.05, 'sim_data_alpha0.05.mat');
toc

tic;
processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat');
toc

tic;
processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','cons_filter_HS','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], [], 0.05, 0.05, 'sim_data_alpha0.05.mat');
toc

%% process data consensus and activation threshold

tic;
processSpreadingData(fullfile(dataDir,'sirs','consensus','N90','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, ttestProp, 'sim_data_alpha0.01.mat', 1);
processSpreadingData(fullfile(dataDir,'sirs','consensus','N90','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 1);
% processSpreadingData(fullfile(dataDir,'sirs','consensus','N90','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, 0.03, 0.05, 'sim_data_alpha0.03.mat', 1);
% processSpreadingData(fullfile(dataDir,'sirs','consensus','N90','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, 0.05, 0.05, 'sim_data_alpha0.05.mat', 1);

processSpreadingData(fullfile(dataDir,'sirs','consensus','N306','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, ttestProp, 'sim_data_alpha0.01.mat', 1);
processSpreadingData(fullfile(dataDir,'sirs','consensus','N306','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 1);
% processSpreadingData(fullfile(dataDir,'sirs','consensus','N306','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, 0.03, 0.05, 'sim_data_alpha0.03.mat', 1);
% processSpreadingData(fullfile(dataDir,'sirs','consensus','N306','si_data.mat'), '', '', {{}}, {{}}, 0, 0, 2, 0.05, 0.05, 'sim_data_alpha0.05.mat', 1);

processSpreadingData(fullfile(dataDir,'sirs','actthresh','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','actthresh','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','actthresh','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','actthresh','N90','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, 0.05, 0.05, 'sim_data_alpha0.05.mat');

processSpreadingData(fullfile(dataDir,'sirs','actthresh','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, ttestProp, 'sim_data_alpha0.01.mat');
processSpreadingData(fullfile(dataDir,'sirs','actthresh','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, ttestPropSplit, 'sim_data_alpha0.01_spTT.mat');
% processSpreadingData(fullfile(dataDir,'sirs','actthresh','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, 0.03, 0.05, 'sim_data_alpha0.03.mat');
% processSpreadingData(fullfile(dataDir,'sirs','actthresh','N306','si_data.mat'), '', '', { {'RTLE','LTLE'}, {'RTLE'}, {'LTLE'} }, { {'HS'}, {'HS'}, {'HS'} }, [1,1,1], [0,0,0], 2, 0.05, 0.05, 'sim_data_alpha0.05.mat');
toc
