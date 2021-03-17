% function plot_sim_data(useFDR)
clearvars
%close all

% variables shared with the functions:
%   plot_sim_data_for
%   plot_sim_data_spider_scatter
global N aal displayData groupLabels groupLegend groupOutputDir highlightPtrn_n306 highlightPtrn_n90 imgFormat isActThresh isConsensus nodeLabels outputDir saveOutputFigures si_n306 si_n90 sortNodesBy sort_n306 sort_n90 useFDR groupOutputDirComm plotData

imgFormat = 'png';

saveOutputFigures = true;
% saveOutputFigures = false;

% useFDR = 2; % false, true, or 2; if useFDR == 2, show t-test figures
useFDR = 1; % false, true, or 2; if useFDR == 2, show t-test figures

zScoreIndividually = true;
% zScoreIndividually = false;

% N = 90; % size of the parcellation of the main results
% sortNodesBy = 'lobe'; % 'lobe' or 'func' or 'funclr'

N = 306; % size of the parcellation of the main results
sortNodesBy = 'func';

% plotData = 'flip'; % 'raw', 'flip', 'zScoreToControls'
% groupLabels = { 'LRTLE' }; % list of group labels that are going to be plotted

plotData = 'zScoreToControls'; % 'raw', 'flip', 'zScoreToControls'
groupLabels = { 'RTLE', 'LTLE' }; % list of group labels that are going to be plotted

% plotData = 'raw'; % 'raw' -> plot data without preprocessing; 'flip' -> plot data with RTLE flipped and grouped with LTLE; 'zScoreToControls' -> plot data that has been z-scored to controls (no flipping)

addpath('func');

odirSuffix = '';
if useFDR, odirSuffix = '_fdr'; end

nodeLabels = {'Hippocampus_R','Hippocampus_L','Thalamus_R','Thalamus_L','Amygdala_R','Amygdala_L','ParaHippocampal_R','ParaHippocampal_L'};

displayData = { 'raw' }; % 'raw' -> full matrices; and/or 'comm' -> community data

programDir = 'D:\Dropbox\p\postdoc\programs\matlab\sirs';
dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    programDir = '/host/scarus/local_raid/mauricio/programs/matlab';
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

if zScoreIndividually
    outputMainDir = fullfile(programDir,'spreading_figs_z');
else
    outputMainDir = fullfile(programDir,'spreading_figs');
end
outputMainDirN = fullfile(outputMainDir, sprintf('N%d',N));

% outputDir = 'D:\Dropbox\p\postdoc\programs\matlab\sirs\spreading_figs\test\';

%% flipped cases (correctly)

% outputDir = fullfile(outputMainDirN,['full_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','flipped_cols','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','flipped_cols','N306','sim_data_alpha0.01.mat'));

% outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','flipped_cols','N90','sim_data_alpha0.01_spTT.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','flipped_cols','N306','sim_data_alpha0.01_spTT.mat'));
% 
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1' }; % list of group labels that are going to be plotted

%% selected cases (not flipped)

% outputDir = fullfile(outputMainDirN,['full_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','selected','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','selected','N306','sim_data_alpha0.01.mat'));

outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT',odirSuffix,filesep]);
if zScoreIndividually
    si_n90 = load(fullfile(dataDir,'sirs','selected','N90','sim_data_z_alpha0.01_spTT.mat'));
    si_n306 = load(fullfile(dataDir,'sirs','selected','N306','sim_data_z_alpha0.01_spTT.mat'));
else
    si_n90 = load(fullfile(dataDir,'sirs','selected','N90','sim_data_alpha0.01_spTT.mat'));
    si_n306 = load(fullfile(dataDir,'sirs','selected','N306','sim_data_alpha0.01_spTT.mat'));
end

isActThresh = false;
isConsensus = false;

%% raw data

% outputDir = fullfile(outputMainDirN,['full_alpha0.01',odirSuffix,filesep]);
% outputDir = fullfile(outputMainDirN,['full_comm_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','N306','sim_data_alpha0.01.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['full_alpha0.03',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','N90','sim_data_alpha0.03.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','N306','sim_data_alpha0.03.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['full_alpha0.05',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','N90','sim_data_alpha0.05.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','N306','sim_data_alpha0.05.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

%% consensus filtered data

% outputDir = fullfile(outputMainDirN,['cons_filter_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter','N306','sim_data_alpha0.01.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['cons_filter_alpha0.03',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter','N90','sim_data_alpha0.03.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter','N306','sim_data_alpha0.03.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted
% 
% outputDir = fullfile(outputMainDirN,['cons_filter_alpha0.05',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter','N90','sim_data_alpha0.05.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter','N306','sim_data_alpha0.05.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

%% consensus filtered data (HS only)

% outputDir = fullfile(outputMainDirN,['cons_filter_HS_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter_HS','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter_HS','N306','sim_data_alpha0.01.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['cons_filter_alpha0.03',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter','N90','sim_data_alpha0.03.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter','N306','sim_data_alpha0.03.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['cons_filter_alpha0.05',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','cons_filter','N90','sim_data_alpha0.05.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','cons_filter','N306','sim_data_alpha0.05.mat'));
% isActThresh = false;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

%% activation threshold normalized data

% outputDir = fullfile(outputMainDirN,['actthresh_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','actthresh','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','actthresh','N306','sim_data_alpha0.01.mat'));
% isActThresh = true;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['actthresh_alpha0.03',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','actthresh','N90','sim_data_alpha0.03.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','actthresh','N306','sim_data_alpha0.03.mat'));
% isActThresh = true;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['actthresh_alpha0.05',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','actthresh','N90','sim_data_alpha0.05.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','actthresh','N306','sim_data_alpha0.05.mat'));
% isActThresh = true;
% isConsensus = false;
% groupLabels = { 'Group1', 'Group2', 'Group3' }; % list of group labels that are going to be plotted

%% consensus data

% outputDir = fullfile(outputMainDirN,['consensus_alpha0.01',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','consensus','N90','sim_data_alpha0.01.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','consensus','N306','sim_data_alpha0.01.mat'));
% isActThresh = false;
% isConsensus = true;
% groupLabels = { 'Group1', 'Group2', 'Group3', 'Group4' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['consensus_alpha0.03',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','consensus','N90','sim_data_alpha0.03.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','consensus','N306','sim_data_alpha0.03.mat'));
% isActThresh = false;
% isConsensus = true;
% groupLabels = { 'Group1', 'Group2', 'Group3', 'Group4' }; % list of group labels that are going to be plotted

% outputDir = fullfile(outputMainDirN,['consensus_alpha0.05',odirSuffix,filesep]);
% si_n90 = load(fullfile(dataDir,'sirs','consensus','N90','sim_data_alpha0.05.mat'));
% si_n306 = load(fullfile(dataDir,'sirs','consensus','N306','sim_data_alpha0.05.mat'));
% isActThresh = false;
% isConsensus = true;
% groupLabels = { 'Group1', 'Group2', 'Group3', 'Group4' }; % list of group labels that are going to be plotted

%%
aal = load(fullfile(dataDir,'AAL_data','aal_cortex_map_olf294_fix.mat'));

groupLegend = getGroupLegendFromSimData(si_n90);

% ggamma = 2.0;

% commFile = fullfile(dataDir,'sirs','N90','comm.mat';
% sort_n90 = sortAALNodes('lr', commFile, ggamma, aal.labels.AAL90);
% [~,sort_n90,lobeLim_n90] = groupAALNodes(aal.labels.AAL90);
[~,sort_n90,lobeLim_n90] = groupAALNodes(90,sortNodesBy,aal);

% commFile = fullfile(dataDir,'sirs','N306','comm.mat';
% sort_n306 = sortAALNodes('lr', commFile, ggamma, aal.labels.AAL90);
% [~,sort_n306,lobeLim_n306] = groupAALNodes(aal.labels.AAL306);
[~,sort_n306,lobeLim_n306] = groupAALNodes(306,sortNodesBy,aal);

% highlightPtrn_n90 = zeros(90,90);
% highlightPtrn_n90(1:45,1:45) = 1;
% highlightPtrn_n90(46:end,46:end) = 1;
highlightPtrn_n90 = createCommPattern(90,lobeLim_n90);

% highlightPtrn_n306 = zeros(306,306);
% highlightPtrn_n306(1:153,1:153) = 1;
% highlightPtrn_n306(154:end,154:end) = 1;
highlightPtrn_n306 = createCommPattern(306,lobeLim_n306);


groupOutputDir = cellfun(@(x)fullfile(outputDir, x),groupLabels,'UniformOutput',false);
spiOutputDir = cellfun(@(x)fullfile(x,'spider_plots'),groupOutputDir,'UniformOutput',false);
gcompOutputDir = cellfun(@(x)fullfile(x,'group_comparison'),groupOutputDir,'UniformOutput',false);

if any(strcmp(displayData,'comm'))
    groupOutputDirComm = appendStr(groupOutputDir,'_comm');
end

if saveOutputFigures
    if exist(outputMainDir, 'dir') ~= 7
        mkdir(outputMainDir);
    end
    if exist(outputMainDirN, 'dir') ~= 7
        mkdir(outputMainDirN);
    end
    if exist(outputDir, 'dir') ~= 7
        mkdir(outputDir);
    end
    if any(strcmp(displayData,'raw'))
        for i = 1:numel(groupOutputDir)
            if exist(groupOutputDir{i}, 'dir') ~= 7
                mkdir(groupOutputDir{i});
            end
            if exist(spiOutputDir{i}, 'dir') ~= 7
                mkdir(spiOutputDir{i});
            end
            if exist(gcompOutputDir{i}, 'dir') ~= 7
                mkdir(gcompOutputDir{i});
            end
        end
    end
    
    if any(strcmp(displayData,'comm'))
        for i = 1:numel(groupOutputDirComm)
            if exist(groupOutputDirComm{i}, 'dir') ~= 7
                mkdir(groupOutputDirComm{i});
            end
        end
    end
end

%%

% for i = 1:numel(groupLabels)
%     plot_func.plot_sim_data_spider_scatter(groupLabels{i},spiOutputDir{i},gcompOutputDir{i});
% end

%%

plot_func.plot_sim_data_for('SpMatrix','')
% plot_func.plot_sim_data_for('SpeedUp','global')
% plot_func.plot_sim_data_for('SpeedUp','local')
% plot_func.plot_sim_data_for('SpeedUp','localnet')
% plot_func.plot_sim_data_for('TwoSeeds','')
