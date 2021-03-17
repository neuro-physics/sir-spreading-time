close all
clearvars

addpath('func');

nSigma = 3; % number of deviations from the mean in order to be considered a stand out
ggamma = 2;

% Group 1
patientGroup = {}; % { 'RTLE', 'LTLE' };
patientHipPath = {}; % { 'HS' }
nedaSelected = false;
sortType = 'comm';
% nSigma = [3,3,2,3]; % number of deviations from the mean in order to be considered a stand out

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
 
spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.00_nSim100_w.mat';
spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w.mat';
spFiles{3} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.03_nSim100_w.mat';
spFiles{4} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.05_nSim100_w.mat';
shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';
commFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\comm.mat';
load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat'); % inputs variable aal_labels

%load('D:\Dropbox\p\postdoc\data\TLE_blade_data_R1FN_Min_add11HS.mat'); % inputs variable casesMetaData
load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat'); % inputs variable casesMetaData

sp = repmat(struct('SAvg', [], 'SVar', [], 'caseName', [], 'theta', []), size(spFiles));
for i = 1:numel(spFiles)
    sp(i) = load(spFiles{i});
end

p = load(shortPathFile);
cm = load(commFile);

gIndex = find(cm.ggamma == ggamma, 1); % checking if ggamma exists in comm file
if isempty(gIndex)
    error('required ggamma not found in file %s',commFile);
end

%% calculating average for each community

for i = 1:numel(sp)
    sp(i).SAvg = calcCommunityAvgSpreadingTime(sp(i).SAvg, cm, ggamma);
end
p.P = calcCommunityAvgShortestPath(p.P, cm, ggamma);

%%

nFiles = numel(spFiles);
N = numel(sp(1).SAvg{1}(:,1));
nCases = numel(sp(1).SAvg);

DMean_case = cell(1, nFiles);
DMean_case = cellfun(@(x)zeros(1,nCases), DMean_case, 'UniformOutput', false);
%DMean_case = zeros(1,nCases);

D = cell(1,nFiles);
D = cellfun(@(x)zeros(nCases, N), D, 'UniformOutput', false);
%D = zeros(nCases, N);

dn = cell(1, nFiles);
dn = cellfun(@(x)cell(1, nCases), dn, 'UniformOutput', false);
%dn = cell(1,nCases);

nIsNaN = cell(1, nFiles);
nIsNaN = cellfun(@(x)cell(1, nCases), nIsNaN, 'UniformOutput', false);

spDiff = cell(1, nFiles);
%spDiff = cellfun(@(x)cell(1, nCases), spDiff, 'UniformOutput', false);

% isPatient = cell(1,nFiles);
patientInd = cell(1,nFiles);
controlInd = cell(1,nFiles);
nControls = zeros(1,nFiles);
nPatients = zeros(1,nFiles);
theta = zeros(1,nFiles);

for j = 1:nFiles
    theta(j) = sp(j).theta;

    for i = 1:nCases
        k = find(~cellfun(@isempty,strfind(p.caseName, sp(j).caseName{i})),1);
        D{j}(i,:) = CalcHammingDist(sp(j).SAvg{i}, p.P{k}) .* N; % calculating hamming distance between spreading and shortest path matrices
        dn{j}{i} = find(D{j}(i,:)); % finding all nodes that differ between spreading and shortest path
        nIsNaN{j}{i} = find(any(isnan(sp(j).SAvg{i}),2))'; %find(isnan(sp(j).SAvg{i}))';
        DMean_case{j}(i) = mean(D{j}(i,:)); % calculating mean hamming distance for case i
    end
    
    spDiff{j} = calcSpreadShortPathSlowDown(sp(j), p, theta(j));

    [patientInd{j},controlInd{j}] = getCasesIndices(sp(j).caseName, casesMetaData, patientGroup, patientHipPath);
    nControls(j) = numel(controlInd{j});
    nPatients(j) = numel(patientInd{j});
end

%% calculating distributions

P_full = cell(1, nFiles);
n_full = cell(1, nFiles);
PFullMax = cell(1, nFiles);
nFullMax = cell(1, nFiles);
DMeanControls_node = cell(1, nFiles);
DMeanPatients_node = cell(1, nFiles);
DMeanControlsMaxInd_node = cell(1, nFiles);
DMeanPatientsMaxInd_node = cell(1, nFiles);
PNaN_full = cell(1, nFiles);
nNaN_full = cell(1, nFiles);
PNaN_controls = cell(1, nFiles);
nNaN_controls = cell(1, nFiles);
PNaN_patients = cell(1, nFiles);
nNaN_patients = cell(1, nFiles);
PPairs_full = cell(1, nFiles);
nPairs_full = cell(1, nFiles);
PPairs_controls = cell(1, nFiles);
nPairs_controls = cell(1, nFiles);
PPairs_patients = cell(1, nFiles);
nPairs_patients = cell(1, nFiles);

for i = 1:nFiles
    % finding the nodes that differed the most between shortest path and spreading time
    [P_full{i},n_full{i}] = histcounts([dn{i}{:}], 1:(N+1));
    P_full{i} = P_full{i} ./ nCases;
    n_full{i} = n_full{i}(1:end-1);
    PFullMax{i} = P_full{i}(P_full{i}>nSigma.*mean(P_full{i}));
    nFullMax{i} = n_full{i}(P_full{i}>nSigma.*mean(P_full{i}));
    
    [PNaN_full{i}, nNaN_full{i}] = histcounts([nIsNaN{i}{:}], 1:(N+1));
    PNaN_full{i} = PNaN_full{i} ./ nCases;
    nNaN_full{i} = nNaN_full{i}(1:end-1);
    
    [PNaN_controls{i}, nNaN_controls{i}] = histcounts([nIsNaN{i}{controlInd{i}}], 1:(N+1));
    PNaN_controls{i} = PNaN_controls{i} ./ nControls(i);
    nNaN_controls{i} = nNaN_controls{i}(1:end-1);
    
    [PNaN_patients{i}, nNaN_patients{i}] = histcounts([nIsNaN{i}{patientInd{i}}], 1:(N+1));
    PNaN_patients{i} = PNaN_patients{i} ./ nPatients(i);
    nNaN_patients{i} = nNaN_patients{i}(1:end-1);
    
    PPairs_full{i} = sum(spDiff{i}.spDiff~=0,1) ./ nCases;
    nPairs_full{i} = 1:size(spDiff{i}.spDiff,2);
    
    PPairs_controls{i} = sum(spDiff{i}.spDiff(controlInd{i},:)~=0,1) ./ nControls(i);
    nPairs_controls{i} = 1:size(spDiff{i}.spDiff,2);
    
    PPairs_patients{i} = sum(spDiff{i}.spDiff(patientInd{i},:)~=0,1) ./ nPatients(i);
    nPairs_patients{i} = 1:size(spDiff{i}.spDiff,2);
    
    % finding mean Hamming distance per node for controls
    DMeanControls_node{i} = mean(D{i}(controlInd{i},:),1);
    DMeanPatients_node{i} = mean(D{i}(patientInd{i},:),1);
    DMeanControlsMaxInd_node{i} = find(DMeanControls_node{i}>nSigma.*mean(DMeanControls_node{i}));
    DMeanPatientsMaxInd_node{i} = find(DMeanPatients_node{i}>nSigma.*mean(DMeanPatients_node{i}));
end

%% plotting mean Hamming distance for each case and 4 thresholds

x = cell(1,2*nFiles);
y = cell(1,2*nFiles);
legVal = zeros(1,2*nFiles);
showLeg = zeros(1,2*nFiles);
for i = 1:2:(2*nFiles)
    k = (i + 1)/2;
    x{i} = 1:numel(DMean_case{k}(controlInd{k}));
    x{i+1} = nControls(k) + (1:numel(DMean_case{k}(patientInd{k})));
    y{i} = DMean_case{k}(controlInd{k});
    y{i+1} = DMean_case{k}(patientInd{k});
    legVal(i) = theta(k);
    legVal(i+1) = theta(k);
    showLeg(i) = 1;
end
psDMean_case = getPlotStruct(x, y, cell(1,2*nFiles), ...
    'Case', 'Mean Hamming distance, $\langle H(S,P)\rangle$', 'linear', 'linear', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance');
    %'Case', 'Mean Hamming distance, $\langle H(S,P)\rangle$', 'linear', 'log', '\theta', legVal, showLeg, 'Mean Hamming distance');

pSymbols = sort('s^ov');

[fh(1),~,~] = plotPlotStruct([], psDMean_case, {':'}, 1, sort([pSymbols,pSymbols]), lines(2), ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties
% createLegend(fh, legText, legSymbol, legLine, legColor, boxArgs, textArgs, lineArgs, lineColWidth)

pLineColors = lines(2);
axh = createLegend(fh(1),...
    psDMean_case.legend(1:2:end),...
    { '^,^', 'o,o', 's,s', 'v,v' },...
    { ':,:', ':,:', ':,:', ':,:' },...
    { pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:)
    }',...
    {'Position', [0.2004 0.4615 0.3050 0.1500], 'Box', 'off'},... % box args
    {'Interpreter', 'latex', 'Displacement', [0,0]},... % text args
    {'MarkerSize', 3}); % line args

%% plotting frequency of inequality between nodes
psPFull = getPlotStruct(n_full, P_full, cell(1,nFiles), ...
    'Community, $c$', '\% times each comm is different, $P(c)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '');
    %'Community, $c$', '\% times each comm is different, $P(c)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), '');
[fh(2),~,~]=plotPlotStruct([], psPFull, {':'}, 1, pSymbols, lines(nFiles), ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

%figure
%bar(n_full,P_full);
%xlabel('Node, $n$', 'Interpreter', 'latex');
%ylabel(, 'Interpreter', 'latex');

k = find(~cellfun(@isempty,nFullMax));
if ~isempty(k)
    for i = 1:numel(nFullMax{k})
        txt = sprintf('Comm_%d', nFullMax{k}(i));
        text(nFullMax{k}(i), PFullMax{k}(i), txt, 'Interpreter', 'none', 'Rotation', 90); 
    end
end

%% plotting mean hamming distance per node

x = cell(1,2*nFiles);
y = cell(1,2*nFiles);
legVal = zeros(1,2*nFiles);
for i = 1:2:(2*nFiles)
    k = (i + 1)/2;
    x{i} = 1:N;
    x{i+1} = 1:N;
    y{i} = DMeanControls_node{k};
    y{i+1} = DMeanPatients_node{k};
    legVal(i) = theta(k);
    legVal(i+1) = theta(k);
end

psDMean_node = getPlotStruct(x, y, cell(1,2*nFiles), ...
    'Community, $c$', 'Mean Hamming distance per comm, $\langle H(S_c,P_c)\rangle$', 'linear', 'linear', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance per comm');
    %'Community, $c$', 'Mean Hamming distance per comm, $\langle H(S_c,P_c)\rangle$', 'linear', 'log', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance per comm');
[fh(3),~,~] = plotPlotStruct([], psDMean_node, {':'}, 1, sort([pSymbols,pSymbols]), lines(2), ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

pLineColors = lines(2);

k = find(~cellfun(@isempty,DMeanControlsMaxInd_node));
if ~isempty(k)
    for i = 1:numel(DMeanControlsMaxInd_node{k})
        j = DMeanControlsMaxInd_node{k}(i);
        txt = sprintf('Comm_%d', j);
        text(j, DMeanControls_node{k}(j), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(1,:));
    end
end

k = find(~cellfun(@isempty,DMeanPatientsMaxInd_node));
if ~isempty(k)
    for i = 1:numel(DMeanPatientsMaxInd_node{k})
        j = DMeanPatientsMaxInd_node{k}(i);
        txt = sprintf('Comm_%d', j);
        text(j, DMeanPatients_node{k}(j), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(2,:));
    end
end

axh = createLegend(fh(3),...
    psDMean_node.legend(1:2:end),...
    { '^,^', 'o,o', 's,s', 'v,v' },...
    { ':,:', ':,:', ':,:', ':,:' },...
    { pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:);...
      pLineColors(1,:), pLineColors(2,:)
    }',...
    {'Position', [0.2004 0.4615 0.3050 0.1500], 'Box', 'on'},... % box args
    {'Interpreter', 'latex', 'Displacement', [0,0]},... % text args
    {'MarkerSize', 3}); % line args
axh.Position = [0.1486 0.4996 0.2389 0.1500];
axh.Box = 'off';
% bcolors = lines(2);
% figure
% bh = bar(1:N,[DMeanPatients_node;DMeanControls_node]');
% bh(1).FaceColor = bcolors(1,:);
% bh(2).FaceColor = bcolors(2,:);
% bh(1).EdgeColor = 'none';
% bh(2).EdgeColor = 'none';
% bh(1).BarWidth = 1;
% bh(2).BarWidth = 1;
% %bar(1:N,DMeanPatients_node-DMeanControls_node)

%% plotting number of unreachable nodes (all cases)

pLineColors = lines(nFiles);
psPNaNFull = getPlotStruct(nNaN_full, PNaN_full, cell(1,nFiles), ...
    'Community, $c$', '\% cases with unreachable comm, $N_{cases}(c)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% cases with unreachable comm');
[fh(4),~,~]=plotPlotStruct([], psPNaNFull, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties


for k = 1:nFiles
    if any(PNaN_full{k})
        ind = find(PNaN_full{k});
        if numel(ind) > 5
            ind = find(PNaN_full{k} > nSigma.*mean(PNaN_full{k}));
        end
        for i = ind
            txt = sprintf('Comm_%d', i);
            text(i, PNaN_full{k}(i), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% plotting number of unreachable nodes (controls)

pLineColors = lines(nFiles);
psPNaNControls = getPlotStruct(nNaN_controls, PNaN_controls, cell(1,nFiles), ...
    'Community, $c$', '\% controls with unreachable comm, $N_{controls}(c)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% controls with unreachable comm');
[fh(5),~,~]=plotPlotStruct([], psPNaNControls, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties


for k = 1:nFiles
    if any(PNaN_controls{k})
        ind = find(PNaN_controls{k});
        if numel(ind) > 5
            ind = find(PNaN_controls{k} > nSigma.*mean(PNaN_controls{k}));
        end
        for i = ind
            txt = sprintf('Comm_%d', i);
            text(i, PNaN_controls{k}(i), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% plotting unreachable nodes (patients)

pLineColors = lines(nFiles);
psPNaNPatients = getPlotStruct(nNaN_patients, PNaN_patients, cell(1,nFiles), ...
    'Community, $c$', '\% patients with unreachable comm, $N_{patients}(c)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% patients with unreachable comm');
[fh(6),~,~]=plotPlotStruct([], psPNaNPatients, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties


for k = 1:nFiles
    if any(PNaN_patients{k})
        ind = find(PNaN_patients{k});
        if numel(ind) > 5
            ind = find(PNaN_patients{k} > nSigma.*mean(PNaN_patients{k}));
        end
        for i = ind
            txt = sprintf('Comm_%d', i);
            text(i, PNaN_patients{k}(i), txt, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% slowing down path distributions (all cases)

pLineColors = lines(nFiles);
psPPairsFull = getPlotStruct(nPairs_full, PPairs_full, cell(1,nFiles), ...
    'Path, $p$', 'slowing down frequency, $F_{cases}(p)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), 'slowing down frequency (all cases)');
    %'Path, $p$', 'slowing down frequency, $F_{cases}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (all cases)');
[fh(7),~,~]=plotPlotStruct([], psPPairsFull, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

%% slowing down path distributions (controls)

pLineColors = lines(nFiles);
psPPairsControls = getPlotStruct(nPairs_controls, PPairs_controls, cell(1,nFiles), ...
    'Path, $p$', 'slowing down frequency, $F_{controls}(p)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), 'slowing down frequency (controls)');
    %'Path, $p$', 'slowing down frequency, $F_{controls}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (controls)');
[fh(8),~,~]=plotPlotStruct([], psPPairsControls, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

%% slowing down path distributions (patients)

pLineColors = lines(nFiles);
psPPairsPatients = getPlotStruct(nPairs_patients, PPairs_patients, cell(1,nFiles), ...
    'Path, $p$', 'slowing down frequency, $F_{patients}(p)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), 'slowing down frequency (patients)');
    %'Path, $p$', 'slowing down frequency, $F_{patients}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (patients)');
[fh(9),~,~]=plotPlotStruct([], psPPairsPatients, {':'}, 1, pSymbols, pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties
