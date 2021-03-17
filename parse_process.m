addpath('func');

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

cdb = load(fullfile(dataDir,'TLE_NB_BB.mat'));
% cdb = load(fullfile(dataDir,'FCD_table.mat'));

%% parse spreading data

% parse simulation files and saves weighted and binary sp times in separate files
% does not perform individual z-score before z-scoring to controls
parseSpreadingData(fullfile(dataDir,'sirs','selected','N90'),fullfile(dataDir,'sirs','selected','N90','si_data.mat'),[],true,false,'',true,true);
parseSpreadingData(fullfile(dataDir,'sirs','selected','N306'),fullfile(dataDir,'sirs','selected','N306','si_data.mat'),[],true,false,'',true,true);

% parse simulation files and saves weighted and binary sp times in separate files
% performs individual z-score before z-scoring to controls
parseSpreadingData(fullfile(dataDir,'sirs','selected','N90'),fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'),[],true,true,'',true,true);
parseSpreadingData(fullfile(dataDir,'sirs','selected','N306'),fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'),[],true,true,'',true,true);

%% calc network properties for all subjects

% tic;
% network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N90','selected'), fullfile(dataDir,'sirs','selected','N90','net_prop.mat'), {{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50);
% network.calcNetworkPropertiesGroups(fullfile(dataDir,'AALmatrix_N306','selected'),fullfile(dataDir,'sirs','selected','N306','net_prop.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},[],100,50);
% toc

%% generate groups with the parsed only (not processed) data

% tic;
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% toc
% 
% tic;
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data_z.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data_z.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data_z.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% toc
% 
% tic;
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data_w.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data_w.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data_w.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% toc
% 
% tic;
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N90', 'si_data_z_w.mat'),fullfile(dataDir,'sirs','selected','N90', 'si_group_data_z_w.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% processSimDataGroups(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'),fullfile(dataDir,'sirs','selected','N306','si_group_data_z_w.mat'),{{'RTLE','LTLE'},'RTLE','LTLE','NC'},'UseForSpSim');
% toc

%% calc comm and short path for std data

% load(fullfile(dataDir,'AAL_data','aal_labels_N90.mat'));
% [~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
% calcCommunities(fullfile(dataDir,'AALmatrix_N90','selected','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','selected','N90','comm.mat'), caseNames);
% calcShortestPath(fullfile(dataDir,'AALmatrix_N90','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N90','shortPath.mat'));
% 
% load(fullfile(dataDir,'AAL_data','aal_labels_N306.mat'));
% [~,caseNames] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1},'AND');
% calcCommunities(fullfile(dataDir,'AALmatrix_N306','selected','TLE*_FA_*.mat'), 1:0.5:3.5, 10, aal_labels, true, fullfile(dataDir,'sirs','selected','N306','comm.mat'), caseNames);
% calcShortestPath(fullfile(dataDir,'AALmatrix_N306','selected','TLE*_FA_*.mat'), true, fullfile(dataDir,'sirs','selected','N306','shortPath.mat'));

%% process std data -- t-tests are performed on the averages of variables

ttestProp = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','off' };
ttestPropSplit = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','on' };

% t-tests are performed on the averages of variables
% does not split t-test over less and greater than zero averages
% std spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01.mat', 0, 0);
% toc

% t-tests are performed on the averages of variables
% splits t-test over less and greater than zero averages
% std spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT.mat', 0, 0);
% toc

% t-tests are performed on the averages of variables
% does not split t-test over less and greater than zero averages
% weighted spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_w.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_w.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_w.mat', 0, 0);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_w.mat', 0, 0);
% toc

% t-tests are performed on the averages of variables
% splits t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_w.mat', 0, 0);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_w.mat', 0, 0);
toc

%% process std data -- t-tests are performed on the samples of variables (does not average before t-test)

% t-tests are performed on the sample (not the averages) of variables
% does not split t-test over less and greater than zero averages
% std spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT.mat', 0, 0, false);
% toc

% t-tests are performed on the sample (not the averages) of variables
% splits t-test over less and greater than zero averages
% std spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT.mat', 0, 0, false);
% toc

% t-tests are performed on the sample (not the averages) of variables
% does not split t-test over less and greater than zero averages
% weighted spreading times
% tic;
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT_w.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT_w.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_alpha0.01_sampTT_w.mat', 0, 0, false);
% processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestProp, 'sim_data_z_alpha0.01_sampTT_w.mat', 0, 0, false);
% toc

% t-tests are performed on the sample (not the averages) of variables
% splits t-test over less and greater than zero averages
% weighted spreading times
tic;
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N90','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
processSpreadingData(fullfile(dataDir,'sirs','selected','N306','si_data_z_w.mat'), '', '', { {'RTLE','LTLE'},{'RTLE'},{'LTLE'} }, { {'HS'},{'HS'},{'HS'} }, ones(1,3), zeros(1,3), [], ttestPropSplit, 'sim_data_z_alpha0.01_spTT_sampTT_w.mat', 0, 0, false);
toc