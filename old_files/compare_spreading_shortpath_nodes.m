close all
clearvars

addpath('func');

ggamma = 2.0;
calcShortestPathOnly = false;
% nSigma = 1.1.*ones(1,4); % number of deviations from the mean in order to be considered a stand out

% Group 1
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% sortType = 'comm';
% nSigma = [3,3,2,3]; % number of deviations from the mean in order to be considered a stand out

% Group 2
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% sortType = 'lr';
% nSigma = [3,3,1.5,3]; % number of deviations from the mean in order to be considered a stand out

% Group 3
patientGroup = { 'RTLE' };
patientHipPath = { 'HS' };
nedaSelected = true;
sortType = 'lr';
nSigma = [3,2,1.5,3]; % number of deviations from the mean in order to be considered a stand out
 
spFiles{1} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.00_nSim100_w.mat';
spFiles{2} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w.mat';
spFiles{3} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.03_nSim100_w.mat';
spFiles{4} = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.05_nSim100_w.mat';
shortPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';
load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat'); % inputs variable aal_labels
commFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\comm.mat';

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
p = load(shortPathFile);

sc = sortAALNodes(sortType, commFile, ggamma);

nFiles = numel(spFiles);
N = numel(sp(1).SAvg{1}(:,1));
nCases = numel(sp(1).SAvg);

DMean_case = cell(1, nFiles);
DMean_case = cellfun(@(x)zeros(1,nCases), DMean_case, 'UniformOutput', false);

DMeanControls_theta = zeros(1,nFiles);
DMeanPatients_theta = zeros(1,nFiles);
DMeanControlsErr_theta = zeros(1,nFiles);
DMeanPatientsErr_theta = zeros(1,nFiles);
%DMean_case = zeros(1,nCases);

DMeanNodeControls_theta = cellfun(@(x)zeros(1, nFiles), cell(1,N), 'UniformOutput', false);
DMeanNodePatients_theta = cellfun(@(x)zeros(1, nFiles), cell(1,N), 'UniformOutput', false);

D = cell(1,nFiles);
D = cellfun(@(x)zeros(nCases, N), D, 'UniformOutput', false);
%D = zeros(nCases, N);

dn = cell(1, nFiles);
dn = cellfun(@(x)cell(1, nCases), dn, 'UniformOutput', false);
%dn = cell(1,nCases);

nIsNaN = cell(1, nFiles);
nIsNaN = cellfun(@(x)cell(1, nCases), nIsNaN, 'UniformOutput', false);

slowControlsM = cell(1, nFiles);
slowPatientsM = cell(1, nFiles);
spDiff = cell(1, nFiles);
%spDiff = cellfun(@(x)cell(1, nCases), spDiff, 'UniformOutput', false);

% isPatient = cell(1,nFiles);
patientInd = cell(1,nFiles);
controlInd = cell(1,nFiles);
nControls = zeros(1,nFiles);
nPatients = zeros(1,nFiles);
theta = zeros(1,nFiles);

thetaValStr = cellfun(@(x)'\theta=XXX',cell(1,nFiles),'UniformOutput',false);

for j = 1:nFiles
    rm = regexp(spFiles{j}, 'theta\d+\.\d+','match');
    theta(j) = str2double(rm{1}(6:end));
    thetaValStr{j} = strrep(thetaValStr{j},'XXX',num2str(theta(j)));

    for i = 1:nCases
        k = find(~cellfun(@isempty,strfind(p.caseName, sp(j).caseName{i})),1);
        if calcShortestPathOnly
            D{j}(i,:) = reshape(mean(p.P{i},1),1,N);
        else
            D{j}(i,:) = CalcHammingDist(sp(j).SAvg{i}, p.P{k}) .* N; % calculating hamming distance between spreading and shortest path matrices
        end
        dn{j}{i} = find(D{j}(i,:)); % finding all nodes that differ between spreading and shortest path
        nIsNaN{j}{i} = find(any(isnan(sp(j).SAvg{i}),2))'; %find(isnan(sp(j).SAvg{i}))';
        DMean_case{j}(i) = mean(D{j}(i,:)); % calculating mean hamming distance for case i
    end

%     isPatient{j} = ~cellfun(@isempty,regexp(sp(j).caseName, '^0\d{3}_\d{1}'));
%     if isempty(find(isPatient{j},1))
%         isPatient{j} = false;
%     end
    
    [patientInd{j},controlInd{j}] = getCasesIndices(sp(j).caseName, casesMetaData, patientGroup, patientHipPath, nedaSelected);
    nControls(j) = numel(controlInd{j});
    nPatients(j) = numel(patientInd{j});
    
    DMeanControls_theta(j) = mean(DMean_case{j}(controlInd{j}));
    DMeanPatients_theta(j) = mean(DMean_case{j}(patientInd{j}));
    DMeanControlsErr_theta(j) = std(DMean_case{j}(controlInd{j})) ./ sqrt(nControls(j));
    DMeanPatientsErr_theta(j) = std(DMean_case{j}(patientInd{j})) ./ sqrt(nPatients(j));
    
    spDiff{j} = calcSpreadShortPathSlowDown(sp(j), p, theta(j));
    
    slowControlsM{j} = mean(spDiff{j}.spDiff(controlInd{j},:),1);
    slowControlsM{j} = reshape(slowControlsM{j},N,N);
    %slowControlsM{j} = pairsToMatrix(spDiff{j}.pairs',slowControlsM{j},N);
    slowControlsM{j} = slowControlsM{j}(sc,sc);

    slowPatientsM{j} = mean(spDiff{j}.spDiff(patientInd{j},:),1);
    slowPatientsM{j} = reshape(slowPatientsM{j},N,N);
    %slowPatientsM{j} = pairsToMatrix(spDiff{j}.pairs',slowPatientsM{j},N);
    slowPatientsM{j} = slowPatientsM{j}(sc,sc);
end

%% calculating distributions

%P_full = cell(1, nFiles);
%n_full = cell(1, nFiles);
%PFullMax = cell(1, nFiles);
%nFullMax = cell(1, nFiles);
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
    %[P_full{i},n_full{i}] = histcounts([dn{i}{:}], 1:(N+1));
    %P_full{i} = P_full{i} ./ nCases;
    %n_full{i} = n_full{i}(1:end-1);
    %PFullMax{i} = P_full{i}(P_full{i}>nSigma.*mean(P_full{i}));
    %nFullMax{i} = n_full{i}(P_full{i}>nSigma.*mean(P_full{i}));

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
    DMeanControlsMaxInd_node{i} = find(DMeanControls_node{i}>nSigma(i).*mean(DMeanControls_node{i}));
    DMeanPatientsMaxInd_node{i} = find(DMeanPatients_node{i}>nSigma(i).*mean(DMeanPatients_node{i}));
end

pSymbols = sort('s^ov');

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
    'Case', 'Mean Hamming distance, $\langle H(S,P)\rangle$', 'linear', 'log', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance');
    %'Case', 'Mean Hamming distance, $\langle H(S,P)\rangle$', 'linear', 'log', '\theta', legVal, showLeg, 'Mean Hamming distance');

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
%%
x = { theta, theta };
y = { DMeanControls_theta, DMeanPatients_theta};
yErr = { DMeanControlsErr_theta, DMeanPatientsErr_theta };
psDMean_theta = getPlotStruct(x, y, yErr, ...
    '$\theta$', 'Mean Hamming distance, $\langle H(S,P)\rangle$', 'linear', 'linear', '', {'controls','TLE'}, ones(size(x)), 'Mean Hamming distance');
[fh(2),~,~] = plotPlotStruct([], psDMean_theta, {':'}, 1, pSymbols, lines(2), ...
    {'LineWidth', 1, 'MarkerSize', 4},... % plot properties
    {'ShowErrorBar', 'on', 'Color', 'auto'},... % error properties
    {'Box', 'on', 'XLim', [-0.005,0.055], 'YLim', [-200,6500], 'Layer', 'top'},... % axis properties
    {'Location', 'northwest', 'FontSize', 12, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 14}); % label properties

%% plotting frequency of inequality between nodes
%psPFull = getPlotStruct(n_full, P_full, cell(1,nFiles), ...
%    'Node, $n$', '\% times each node is different, $P(n)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), '');
%[fh(2),~,~]=plotPlotStruct([], psPFull, {':'}, 1, pSymbols, lines(nFiles), ...
%    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
%    {'ShowErrorBar', 'off'},... % error properties
%    {'Box', 'on', 'Layer', 'top'},... % axis properties
%    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
%    {'FontSize', 12}); % label properties

%figure
%bar(n_full,P_full);
%xlabel('Node, $n$', 'Interpreter', 'latex');
%ylabel(, 'Interpreter', 'latex');

%k = find(~cellfun(@isempty,nFullMax));
%if ~isempty(k)
%    for i = 1:numel(nFullMax{k})
%        text(nFullMax{k}(i)-1.5, PFullMax{k}(i), aal_labels{nFullMax{k}(i)}, 'Interpreter', 'none', 'Rotation', 90); 
%    end
%end

%% plotting mean hamming distance per node

x = cell(1,2*nFiles);
y = cell(1,2*nFiles);
legVal = zeros(1,2*nFiles);
% i = 3; %i = 5;
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
   'Node, $n$', 'Mean Hamming distance per node, $\langle H(S_n,P_n)\rangle$', 'linear', 'linear', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance per node');
% psDMean_node = getPlotStruct(x, y, cell(1,2*nFiles), ...
%     'Node, $n$', 'Mean Hamming distance per node, $\langle H(S_n,P_n)\rangle$', 'linear', 'linear', '\theta', legVal, ones(1,2*nFiles), 'Mean Hamming distance per node');
    %'Node, $n$', 'Mean Hamming distance per node, $\langle H(S_n,P_n)\rangle$', 'linear', 'log', '\theta', legVal, zeros(1,2*nFiles), 'Mean Hamming distance per node');
[fh(3),~,~] = plotPlotStruct([], psDMean_node, {':'}, 1, sort([pSymbols,pSymbols]), lines(2), ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

pLineColors = lines(2);
% DMeanControlsMaxInd_node={}
k = find(~cellfun(@isempty,DMeanControlsMaxInd_node));
% k = (i + 1) / 2;
if ~isempty(k)
    m = k;
    for k = m
        for i = 1:numel(DMeanControlsMaxInd_node{k})
            j = DMeanControlsMaxInd_node{k}(i);
            text(j-1.5, DMeanControls_node{k}(j), aal_labels{j}, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(1,:));
        end
    end
end

% DMeanPatientsMaxInd_node={}
k = find(~cellfun(@isempty,DMeanPatientsMaxInd_node));
if ~isempty(k)
    m = k;
    for k = m
        for i = 1:numel(DMeanPatientsMaxInd_node{k})
            j = DMeanPatientsMaxInd_node{k}(i);
            text(j-1.5, DMeanPatients_node{k}(j), aal_labels{j}, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(2,:));
        end
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

%% plotting number of failed seed nodes (all cases)

pLineColors = lines(nFiles);
psPNaNFull = getPlotStruct(nNaN_full, PNaN_full, cell(1,nFiles), ...
    'Node, $n$', '\% cases with failed seed nodes, $q(n)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% cases with failed seed nodes');
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
            ind = find(PNaN_full{k} > nSigma(k).*mean(PNaN_full{k}));
        end
        for i = ind
            text(i-1.5, PNaN_full{k}(i), aal_labels{i}, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% plotting number of failed seed nodes (controls)

pLineColors = lines(nFiles);
psPNaNControls = getPlotStruct(nNaN_controls, PNaN_controls, cell(1,nFiles), ...
    'Node, $n$', '\% controls with failed seed nodes, $q_{controls}(n)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% controls with failed seed nodes');
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
            ind = find(PNaN_controls{k} > nSigma(k).*mean(PNaN_controls{k}));
        end
        for i = ind
            text(i-1.5, PNaN_controls{k}(i), aal_labels{i}, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% plotting failed seed nodes (patients)

pLineColors = lines(nFiles);
psPNaNPatients = getPlotStruct(nNaN_patients, PNaN_patients, cell(1,nFiles), ...
    'Node, $n$', '\% patients with failed seed nodes, $q_{patients}(n)$', 'linear', 'linear', '\theta', theta, ones(1,nFiles), '% patients with failed seed nodes');
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
            ind = find(PNaN_patients{k} > nSigma(k).*mean(PNaN_patients{k}));
        end
        for i = ind
            text(i-1.5, PNaN_patients{k}(i), aal_labels{i}, 'Interpreter', 'none', 'Rotation', 90, 'Color', pLineColors(k,:)); 
        end
    end
end

%% failed nodes versus theta

x = cellfun(@(x)theta,cell(1,2*N),'UniformOutput',false);
y = [mat2cell(reshape(cell2mat(PNaN_controls), [N,nFiles])', nFiles, ones(1,N)),mat2cell(reshape(cell2mat(PNaN_patients), [N,nFiles])', nFiles, ones(1,N))];
psPNaNCases_theta = getPlotStruct(x, y, cell(size(x)), ...
    '$\theta$', '\% cases with failed seed node, $q(\theta;n)$', 'linear', 'linear', 'n', [1:N,1:N], zeros(size(x)), '% cases with failed seed node');

k = nFiles;
if any(PNaN_controls{k})
    indC = find(PNaN_controls{k});
    if numel(indC) > 5
        indC = find(PNaN_controls{k} > nSigma(k).*mean(PNaN_controls{k}));
    end
end
if any(PNaN_patients{k})
    indP = find(PNaN_patients{k});
    if numel(indP) > 5
        indP = find(PNaN_patients{k} > nSigma(k).*mean(PNaN_patients{k}));
    end
end

psPNaNCases_theta.curves(indC(1)).showLegend = 1;
psPNaNCases_theta.curves(indP(1)+N).showLegend = 1;

pLineC = lines(2);
pLineColors = repmat(0.75, [2*N,3]);
pLineColors(indC,:) = repmat(pLineC(1,:), numel(indC), 1);
pLineColors((N+indP),:) = repmat(pLineC(2,:), numel(indP), 1);
pLineSt = [ cellfun(@(x)'-',cell(1,N),'UniformOutput',false),cellfun(@(x)'--',cell(1,N),'UniformOutput',false) ];

[fh(7),~,~]=plotPlotStruct([], psPNaNCases_theta, pLineSt, 2, 'o', pLineColors, ...
    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
    {'ShowErrorBar', 'off'},... % error properties
    {'Box', 'on', 'XLim', [-0.005,0.055], 'YLim', [-0.02,0.5], 'Layer', 'top'},... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

k = nFiles;
indC = find(PNaN_controls{k} > nSigma(k).*mean(PNaN_controls{k}));
for i = indC
    text(theta(k), y{i}(k), aal_labels{i}, 'Interpreter', 'none', 'Color', pLineC(1,:));
end
k = nFiles;
indP = find(PNaN_patients{k} > nSigma(k).*mean(PNaN_patients{k}));
for i = indP
    text(theta(k), y{N+i}(k), aal_labels{i}, 'Interpreter', 'none', 'Color', pLineC(2,:));
end

%% slowing down path distributions (all cases)

%pLineColors = lines(nFiles);
%psPPairsFull = getPlotStruct(nPairs_full, PPairs_full, cell(1,nFiles), ...
%    'Path, $p$', 'slowing down frequency, $F_{cases}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (all cases)');
%[fh(8),~,~]=plotPlotStruct([], psPPairsFull, {':'}, 1, pSymbols, pLineColors, ...
%    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
%    {'ShowErrorBar', 'off'},... % error properties
%    {'Box', 'on', 'Layer', 'top'},... % axis properties
%    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
%    {'FontSize', 12}); % label properties


%% slowing down path distributions (controls)

[fh(8),~,~] = createNPanelsImageFig(slowControlsM, 2, [], thetaValStr, 'Slowing down - Controls', gray, [0,1,1,1]);
%pLineColors = lines(nFiles);
%psPPairsControls = getPlotStruct(nPairs_controls, PPairs_controls, cell(1,nFiles), ...
%    'Path, $p$', 'slowing down frequency, $F_{controls}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (controls)');
%[fh(9),~,~]=plotPlotStruct([], psPPairsControls, {':'}, 1, pSymbols, pLineColors, ...
%    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
%    {'ShowErrorBar', 'off'},... % error properties
%    {'Box', 'on', 'Layer', 'top'},... % axis properties
%    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
%    {'FontSize', 12}); % label properties

%% slowing down path distributions (patients)

[fh(9),~,~] = createNPanelsImageFig(slowPatientsM, 2, [], thetaValStr, 'Slowing down - TLE', gray, [0,1,1,1]);
%pLineColors = lines(nFiles);
%psPPairsPatients = getPlotStruct(nPairs_patients, PPairs_patients, cell(1,nFiles), ...
%    'Path, $p$', 'slowing down frequency, $F_{patients}(p)$', 'linear', 'log', '\theta', theta, ones(1,nFiles), 'slowing down frequency (patients)');
%[fh(10),~,~]=plotPlotStruct([], psPPairsPatients, {':'}, 1, pSymbols, pLineColors, ...
%    {'LineWidth', 1, 'MarkerSize', 3},... % plot properties
%    {'ShowErrorBar', 'off'},... % error properties
%    {'Box', 'on', 'Layer', 'top'},... % axis properties
%    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
%    {'FontSize', 12}); % label properties
