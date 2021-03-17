% function plot_sim_data_func(plot_config_file)

%% global config
clearvars
close all

% variables shared with the functions:
%   plot_sim_data_for
%   plot_sim_data_spider_scatter
global N aal displayData groupLabels groupLegend groupOutputDir ...
       highlightPtrn_n306 highlightPtrn_n90 imgFormat isActThresh ...
       isConsensus nodeLabels outputDir saveOutputFigures sortNodesBy ...
       sort_n306 sort_n90 useFDR groupOutputDirComm plotData si showDataColor ....
       showMTLData volumeVarName showZScoreEdges tThresh effectSizeField

siFileNameSuffix = '';
showMTLData = true;
volumeVarName = 'Hippocampus';
showZScoreEdges = true;

plotSpider = true;
% plotSpider = false;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% UNCOMMENT THIS LINE BELOW WHEN THE FUNCTION LINE (FIRST LINE) IS UNCOMMENTED:
%
% plot_config_file() % loads config variables for this plot if the current file is a function
% plot_func.plot_config_file_N90_debug() % debugging purposes
                                                   %%%%%%%%
                                                   %%%%%%%%
plot_func.plot_config_file_N306_flip_avgTT_paper() %%% for TLE paper
                                                   %%%%%%%%
                                                   %%%%%%%%
                                                   %%%%%%%%
% plot_func.plot_config_file_N306_FCD_all_groups() %%% for FCD paper
                                                   %%%%%%%%
                                                   %%%%%%%%
% outputDir = 'D:\Dropbox\p\postdoc\programs\matlab\sirs\spreading_figs\test\';

%% loading selected cases (not flipped)

%[outputDir,outputMainDir,outputMainDirN,si_n90,si_n306] = plot_func.loadPlotData(dataDir,odirSuffix,N,useBinarySpTime,splitTTest,zScoreIndividually,ttestOnAvg);
[outputDir,outputMainDir,outputMainDirN,si,siFileName] = plot_func.loadPlotData(dataDir,odirSuffix,N,useBinarySpTime,splitTTest,zScoreIndividually,ttestOnAvg,siFileNameSuffix);
isActThresh = false;
isConsensus = false;

%% exporting workspace to output directory
if saveOutputFigures
    vars = whos;
    vars(([vars(:).bytes]==0) | strcmp({vars(:).name},'si')) = []; % excluding empty variables and 'si' variable
    varsNameToSave = {vars(:).name};
end

%% creating directories

%aal = load(fullfile(dataDir,'AAL_data','aal_cortex_map_olf294_fix.mat'));
[~,~,~,aal] = aalsurfview(zeros(90,1));

groupLegend = getGroupLegendFromSimData(si);

[~,sort_n90,lobeLim_n90] = groupAALNodes(90,sortNodesBy,aal);
[~,sort_n306,lobeLim_n306] = groupAALNodes(306,sortNodesBy,aal);

highlightPtrn_n90 = createCommPattern(90,lobeLim_n90);
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

    save(fullfile(outputDir,'output_config.mat'),varsNameToSave{:},'-v7.3');
end

%%

if plotSpider
    warning('off','MATLAB:circshift:ScalarShift');
    for i = 1:numel(groupLabels)
        % plot_func.plot_sim_data_spider_scatter(groupLabels{i},spiOutputDir{i},gcompOutputDir{i});
        plot_func.plot_sim_data_spider_scatter_paper(groupLabels{i},spiOutputDir{i},gcompOutputDir{i},thetaVal);
    end
end
if useBinarySpTime
    return
end

%%

% plot_func.plot_sim_data_for('SpMatrix',thetaVal,'');
plot_func.plot_sim_data_for('SpMatrixW',thetaVal,'');
% plot_func.plot_sim_data_for('SpeedUp',thetaVal,'global');
% plot_func.plot_sim_data_for('SpeedUp',thetaVal,'localnet');
% plot_func.plot_sim_data_for('SpeedUpW',thetaVal,'global');
% plot_func.plot_sim_data_for('SpeedUpW',thetaVal,'localnet');
if useBinarySpTime
    plot_func.plot_sim_data_for('TwoSeeds',thetaVal,'');
end
% plot_func.plot_sim_data_for('SpeedUp',thetaVal,'local');

% end