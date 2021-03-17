close all
clearvars

addpath('func');

nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
nSigmaMinus = 1.4;
ggamma = 2.0;
 
spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.00_nSim100_w.mat';
spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.01_nSim100_w.mat';
spFiles{3} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.03_nSim100_w.mat';
spFiles{4} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.05_nSim100_w.mat';
%shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';
commFile = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\comm.mat';
load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat'); % inputs variable aal_labels

% spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\CoCoMac\sp_CCM_theta0.01_nSim1_w.mat';
% spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\CoCoMac\sp_CCM_theta0.015_nSim1_w.mat';
% shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\CoCoMac\shortPath.mat';
% load('D:\Dropbox\p\postdoc\data\rhesus_data\rhesus_labels.mat'); % inputs variable aal_labels

sp = repmat(struct('SAvg', [], 'SVar', [], 'caseName', [], 'theta', []), size(spFiles));
for i = 1:numel(spFiles)
    sp(i) = load(spFiles{i});
end
cm = load(commFile);
%p = load(shortPathFile);

gIndex = find(cm.ggamma == ggamma, 1); % checking if ggamma exists in comm file
if isempty(gIndex)
    error('required ggamma not found in file %s',commFile);
end

[~,sc] = sort(cm.C{gIndex});

nFiles = numel(spFiles);
N = numel(sp(1).SAvg{1}(:,1));
nCases = numel(sp(1).SAvg);

isPatient = cell(1,nFiles);
nControls = zeros(1,nFiles);
nPatients = zeros(1,nFiles);

for k = 1:nFiles
    isPatient{k} = ~cellfun(@isempty,regexp(sp(k).caseName, '^0\d{3}_\d{1}'));
    if isempty(find(isPatient{k},1))
        isPatient{k} = false;
    end
    nControls(k) = numel(find(~isPatient{k}));
    nPatients(k) = numel(find(isPatient{k}));
end

%%

meanSpTime_edge = cell(1,nFiles);
meanSpTime_node = cell(1,nFiles);

meanSpTimeControls_edge = cell(1,nFiles);
meanSpTimeControls_node = cell(1,nFiles);

meanSpTimePatients_edge = cell(1,nFiles);
meanSpTimePatients_node = cell(1,nFiles);

panelTitles = cell(1,nFiles);

psSpTime_node = repmat(getPlotStruct(), 1, nFiles);
psProp = repmat(getPlotStructProperties(), 1, nFiles);
pLineColors = lines(3);
pSymbols = 'o^s';

for k = 1:nFiles
    meanSpTime_edge{k} = meanMatrix(sp(k).SAvg);
    meanSpTime_edge{k} = meanSpTime_edge{k}(sc,sc);
    meanSpTime_node{k} = mean(meanSpTime_edge{k},1);
    
    meanSpTimeControls_edge{k} = meanMatrix(sp(k).SAvg(~isPatient{k}));
    meanSpTimeControls_edge{k} = meanSpTimeControls_edge{k}(sc,sc);
    meanSpTimeControls_node{k} = mean(meanSpTimeControls_edge{k},1);
    
    meanSpTimePatients_edge{k} = meanMatrix(sp(k).SAvg(isPatient{k}));
    meanSpTimePatients_edge{k} = meanSpTimePatients_edge{k}(sc,sc);
    meanSpTimePatients_node{k} = mean(meanSpTimePatients_edge{k},1);
    
    panelTitles{k} = [ '\theta=',num2str(sp(k).theta) ];
    
    % getPlotStruct(x, y, yErr, xLabel, yLabel, xScale, yScale, legendParName, legendParValues, showLegend, plotTitle)
    psSpTime_node(k) = getPlotStruct( {1:N, 1:N, 1:N}, {meanSpTimeControls_node{k},meanSpTimePatients_node{k},meanSpTime_node{k}},cell(1,3),...
        'Node, $n$', 'Avg reaching time, $S(n)$', 'linear', 'linear', '', {'Controls','TLE','Total'},ones(1,3),'');
    psProp(k) = getPlotStructProperties({':'}, 1, pSymbols, pLineColors, ...
        {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
        {'ShowErrorBar', 'off'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
end

%%

createNPanelsImageFig(meanSpTime_edge, 2, {'targets', 'seeds'}, panelTitles, 'Total',1-parula);
createNPanelsImageFig(meanSpTimeControls_edge, 2, {'targets', 'seeds'}, panelTitles, 'Controls',1-parula);
createNPanelsImageFig(meanSpTimePatients_edge, 2, {'targets', 'seeds'}, panelTitles, 'TLE',1-parula);
createNPanelsPlotStructFig(psSpTime_node, psProp, 2, ' ');
