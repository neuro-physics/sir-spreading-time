close all
clearvars

addpath('func');

nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
nSigmaMinus = 1.4;
ggamma = 2.0;
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
%patientGroup = { 'LTLE' };
%patientHipPath = { 'HS' };

% Group 1
patientGroup = {}; % { 'RTLE', 'LTLE' };
patientHipPath = {}; % { 'HS' }
nedaSelected = false;
sortType = 'comm';
nSigma = [3,3,2,3]; % number of deviations from the mean in order to be considered a stand out

% Group 2
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% sortType = 'lr';
% nSigma = [3,3,1.5,3]; % number of deviations from the mean in order to be considered a stand out

% Group 3
% patientGroup = { 'RTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% sortType = 'lr';
% nSigma = [3,2,1.5,3]; % number of deviations from the mean in order to be considered a stand out

% [ind,c] = getPatientIndex(casesMetaData, { 'Group', 'HipPath' }, { { 'RTLE' }, { 'HS' } }, 'AND');

spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.00_nSim100_w.mat';
spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w.mat';
spFiles{3} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.03_nSim100_w.mat';
spFiles{4} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.05_nSim100_w.mat';
%shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';
commFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\comm.mat';
load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat'); % inputs variable aal_labels

%load('D:\Dropbox\p\postdoc\data\TLE_blade_data_R1FN_Min_add11HS.mat'); % inputs variable casesMetaData
load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat'); % inputs variable casesMetaData

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

for i = 1:numel(sp)
    sp(i).SAvg = calcCommunityAvgSpreadingTime(sp(i).SAvg, cm, ggamma);
end

for i = 1:numel(sp)
    sp(i).SAvg = ZScoreMatrix(sp(i).SAvg);
end

%%

nFiles = numel(spFiles);
N = numel(sp(1).SAvg{1}(:,1));
nCases = numel(sp(1).SAvg);

zScoreAvg = cell(1, nFiles);
zScoreErr = cell(1, nFiles);
zScoreAvgControls = cell(1, nFiles);
zScoreErrControls = cell(1, nFiles);
zScoreAvgPatients = cell(1, nFiles);
zScoreErrPatients = cell(1, nFiles);

%isPatient = cell(1,nFiles);
patientInd = cell(1,nFiles);
controlInd = cell(1,nFiles);
nControls = zeros(1,nFiles);
nPatients = zeros(1,nFiles);

theta = [ sp(:).theta ];

%%
for j = 1:nFiles
    [patientInd{j},controlInd{j}] = getCasesIndices(sp(j).caseName, casesMetaData, patientGroup, patientHipPath, nedaSelected);
    nControls(j) = numel(controlInd{j});
    nPatients(j) = numel(patientInd{j});

    [A,E] = meanMatrix(sp(j).SAvg);
    zScoreAvg{j} = mean(A,1);
    zScoreErr{j} = mean(E,1);
    
    [A,E] = meanMatrix(sp(j).SAvg(controlInd{j}));
    zScoreAvgControls{j} = mean(A,1);
    zScoreErrControls{j} = mean(E,1);
    
    [A,E] = meanMatrix(sp(j).SAvg(patientInd{j}));
    zScoreAvgPatients{j} = mean(A,1);
    zScoreErrPatients{j} = mean(E,1);
end

%% creating plot structs

pLineColors = lines(3);
pSymbols = 'o^s';

psZScore = repmat(getPlotStruct(), 1, nFiles);
psProp = repmat(getPlotStructProperties(), size(psZScore));
xDiff = cell(1,nFiles);
yDiff = cell(1,nFiles);
indSigDiff = cell(1,nFiles);
for i = 1:nFiles
%     x = { 1:N, 1:N, 1:N };
%     y = { zScoreAvgControls{j}, zScoreAvgPatients{j}, zScoreAvg{j} };
    x = { 1:N, 1:N };
    y = { zScoreAvgControls{i}, zScoreAvgPatients{i} };
    yErr = { zScoreErrControls{i}, zScoreErrPatients{i} };
    psZScore(i) = getPlotStruct(x,y,yErr,...
        'Module, $n$', 'Average $z$-score', 'linear', 'linear', ...
        '', {'controls', 'tle', 'total'}, ones(1,3), ['average spreading time z-score; \theta=',num2str(theta(i))]);
    psProp(i) = getPlotStructProperties({':'}, 1, pSymbols, pLineColors, ...
        {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
        {'ShowErrorBar', 'on', 'Color', 'auto'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
    
    xDiff{i} = 1:N;
    yDiff{i} = abs(zScoreAvgControls{i} - zScoreAvgPatients{i});
    indSigDiff{i} = find(yDiff{i} > (zScoreErrControls{i}+zScoreErrPatients{i}));
end

createNPanelsPlotStructFig(psZScore, psProp, 2, ' ');

pSymbolsDiff = 'o^sv';
pLineColorsDiff = lines(4);
psDiff = getPlotStruct(xDiff,yDiff,cell(size(xDiff)),...
    'Module, $n$', '$|z_c-z_p|$', 'linear', 'linear', ...
    '\theta', theta, ones(size(xDiff)), 'average spreading time z-score difference; all \theta');
plotPlotStruct([], psDiff, {':'}, 1, pSymbols, pLineColorsDiff,...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

for i = 1:numel(indSigDiff)
    if ~isempty(indSigDiff{i})
        for j = 1:numel(indSigDiff{i})
            k = indSigDiff{i}(j);
            txt = sprintf('Comm_%d', k);
            text(k, yDiff{i}(k), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColorsDiff(i,:));
        end
    end
end
