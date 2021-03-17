close all
clearvars

addpath('func');

nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
nSigmaMinus = 1.4;
ggamma = 2.0;
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };
% [ind,c] = getPatientIndex(casesMetaData, { 'Group', 'HipPath' }, { { 'RTLE' }, { 'HS' } }, 'AND');

% Group 1
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% sortType = 'comm';
% nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
% nSigmaMinus = 1.4;

% Group 2
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% sortType = 'lr';
% nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
% nSigmaMinus = 1.39;

% Group 3
patientGroup = { 'RTLE' };
patientHipPath = { 'HS' };
nedaSelected = true;
sortType = 'lr';
nSigmaPlus = 3; % number of deviations from the mean in order to be considered a stand out
nSigmaMinus = 1.39;

spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.00_nSim100_w.mat';
spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.01_nSim100_w.mat';
spFiles{3} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.03_nSim100_w.mat';
spFiles{4} = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\sp_N90_theta0.05_nSim100_w.mat';
%shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';
commFile = 'D:\Dropbox\p\postdoc\data\sirs\old_2016-11-06\N90\comm.mat';
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

%[~,sc] = sort(cm.C{gIndex});
sc = sortAALNodes(sortType, commFile, ggamma);

for i = 1:numel(sp)
    sp(i).SAvg = ZScoreMatrix(sp(i).SAvg);
end

%%

nFiles = numel(spFiles);
N = numel(sp(1).SAvg{1}(:,1));
nCases = numel(sp(1).SAvg);

zScores_plus = cell(1, nFiles);
zScoresControls_plus = cell(1, nFiles);
zScoresPatients_plus = cell(1, nFiles);

zScores_minus = cell(1, nFiles);
zScoresControls_minus = cell(1, nFiles);
zScoresPatients_minus = cell(1, nFiles);

%isPatient = cell(1,nFiles);
patientInd = cell(1,nFiles);
controlInd = cell(1,nFiles);
nControls = zeros(1,nFiles);
nPatients = zeros(1,nFiles);

theta = [ sp(:).theta ];

%%
for j = 1:nFiles
    zScores_plus{j} = selectZScores(sp(j).SAvg, nSigmaPlus, @(a,b)a>=b, false, true);
    zScores_minus{j} = selectZScores(sp(j).SAvg, -nSigmaMinus, @(a,b)a<=b, false, true);
    zScores_minus{j}.z(zScores_minus{j}.z(:,1:(N+1):end)~=0,1:(N+1):end)=0; % some cases have the main diagonal values obeying the condition above

    [patientInd{j},controlInd{j}] = getCasesIndices(sp(j).caseName, casesMetaData, patientGroup, patientHipPath, nedaSelected);
    nControls(j) = numel(controlInd{j});
    nPatients(j) = numel(patientInd{j});
    
    zScoresControls_plus{j} = zScores_plus{j}.z(controlInd{j},:);
    zScoresPatients_plus{j} = zScores_plus{j}.z(patientInd{j},:);
    
    zScoresControls_minus{j} = zScores_minus{j}.z(controlInd{j},:);
    zScoresPatients_minus{j} = zScores_minus{j}.z(patientInd{j},:);
end

%% creating plot structs

psZScorePlus = repmat(getPlotStruct(), 1, nFiles);
psZScoreMinus = repmat(getPlotStruct(), 1, nFiles);
for i = 1:nFiles
    x = { 1:(N*N), 1:(N*N), 1:(N*N) };
    y = { sum(zScoresControls_plus{i},1)./nControls(i), sum(zScoresPatients_plus{i},1)./nPatients(i), sum(zScores_plus{i}.z,1)./nCases };
    psZScorePlus(i) = getPlotStruct(x,y,cell(1,3),...
        'Pairs, $p$', ['Frequency of pairs with $z_p\geq',num2str(nSigmaPlus),'$'], 'linear', 'linear', ...
        '', {'controls', 'tle', 'total'}, ones(1,3), ['z stand outs (slower than avg); \theta=',num2str(theta(i))]);
    
    x = { 1:(N*N), 1:(N*N), 1:(N*N) };
    y = { sum(zScoresControls_minus{i},1)./nControls(i), sum(zScoresPatients_minus{i},1)./nPatients(i), sum(zScores_minus{i}.z,1)./nCases };
    psZScoreMinus(i) = getPlotStruct(x,y,cell(1,3),...
        'Pairs, $p$', ['Frequency of pairs with $z_p\leq',num2str(-nSigmaMinus),'$'], 'linear', 'linear', ...
        '', {'controls', 'tle', 'total'}, ones(1,3), ['z stand outs (faster than avg); \theta=',num2str(theta(i))]);
end

%%
pLineColors = lines(3);
pSymbols = 'o^s';

psProp = repmat(getPlotStructProperties(), size(psZScorePlus));
% for i = 1:nFiles
i = 1;
    A1 = reshape(sum(zScores_plus{i}.z,1),[N,N]);
    A2 = reshape(sum(zScoresControls_plus{i},1),[N,N]);
    A3 = reshape(sum(zScoresPatients_plus{i},1),[N,N]);
    titleText = [ 'z stand outs (slower than avg); $\gamma=',num2str(ggamma),'$; $\theta=',num2str(theta(i)),'$; $z_p\geq',num2str(nSigmaPlus),'$'];
    create3PanelsImageFig({ A1(sc,sc), A2(sc,sc), A3(sc,sc) }, { 'Total', 'Controls', 'TLE' }, titleText);
    
    psProp(i) = getPlotStructProperties({':'}, 1, pSymbols, pLineColors, ...
        {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
        {'ShowErrorBar', 'off'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
% end
% createNPanelsPlotStructFig(psZScorePlus, psProp, 2, ' ');

%%

psProp = repmat(getPlotStructProperties(), size(psZScoreMinus));
% for i = 1:nFiles
i = 1;
    A1 = reshape(sum(zScores_minus{i}.z,1),[N,N]);
    A2 = reshape(sum(zScoresControls_minus{i},1),[N,N]);
    A3 = reshape(sum(zScoresPatients_minus{i},1),[N,N]);
    titleText = [ 'z stand outs (faster than avg); $\gamma=',num2str(ggamma),'$; $\theta=',num2str(theta(i)),'$; $z_p\leq',num2str(-nSigmaMinus),'$'];
    create3PanelsImageFig({ A1(sc,sc), A2(sc,sc), A3(sc,sc) }, { 'Total', 'Controls', 'TLE' }, titleText);

    psProp(i) = getPlotStructProperties({':'}, 1, pSymbols, pLineColors, ...
        {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
        {'ShowErrorBar', 'off'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
% end
% createNPanelsPlotStructFig(psZScoreMinus, psProp, 2, ' ');
