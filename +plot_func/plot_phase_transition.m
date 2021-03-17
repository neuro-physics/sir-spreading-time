clearvars
close all

addpath('func');

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

inputFile = fullfile(dataDir,'sirs','fcd_selected','si_data_w.mat');

si = load(inputFile);
seedType = si.PhaseTrans.icType;
matrixType = si.PhaseTrans.weightSamp;

% load(fullfile(dataDir,'TLE_NB_BB.mat')); % inputs variable casesMetaData
load(fullfile(dataDir,'FCD_table.mat')); % inputs variable casesMetaData

%%

% Group 1
% patientGroup = {}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% legendText = 'TLE';

% Group 2
% patientGroup = { 'LTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% legendText = 'LTLE+HS';

% Group 3
% patientGroup = { 'RTLE' };
% patientHipPath = { 'HS' };
% nedaSelected = true;
% legendText = 'RTLE+HS';

% FCD group (all together: preop, postop and postopsim)
patientGroup = {}; % { 'RTLE', 'LTLE' };
patientHipPath = {}; % { 'HS' }
nedaSelected = false;
legendText = 'FCD';

% FCD group
% patientGroup = {'FCD_PREOP'}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% legendText = 'FCDpre';

% FCD group
% patientGroup = {'FCD_POSTOP'}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% legendText = 'FCDpost';

% FCD group
% patientGroup = {'FCD_POSTOPSIM'}; % { 'RTLE', 'LTLE' };
% patientHipPath = {}; % { 'HS' }
% nedaSelected = false;
% legendText = 'FCDsim';

%%

[patientInd,controlInd] = getCasesIndices(si.caseName, casesMetaData, patientGroup, patientHipPath, nedaSelected);

%isPatient = ~cellfun(@isempty,regexp(si.caseName, '^0\d{3}_\d{1}'));
Th = calcActivationThreshold(si.PhaseTrans.data);
nControls = numel(controlInd);
nPatients = numel(patientInd);
nTheta = numel(si.PhaseTrans.data.Theta{1});

rhoMeanControls = mean(reshape([si.PhaseTrans.data.rho{controlInd}],nTheta,nControls),2);
rhoErrControls = std(reshape([si.PhaseTrans.data.rho{controlInd}],nTheta,nControls),0,2)./sqrt(nControls);
NVarRhoMeanControls = mean(reshape([si.PhaseTrans.data.NVarRho{controlInd}],nTheta,nControls),2);
NVarRhoErrControls = std(reshape([si.PhaseTrans.data.NVarRho{controlInd}],nTheta,nControls),0,2)./sqrt(nControls);

rhoMeanPatients = mean(reshape([si.PhaseTrans.data.rho{patientInd}],nTheta,nPatients),2);
rhoErrPatients = std(reshape([si.PhaseTrans.data.rho{patientInd}],nTheta,nPatients),0,2)./sqrt(nPatients);
NVarRhoMeanPatients = mean(reshape([si.PhaseTrans.data.NVarRho{patientInd}],nTheta,nPatients),2);
NVarRhoErrPatients = std(reshape([si.PhaseTrans.data.NVarRho{patientInd}],nTheta,nPatients),0,2)./sqrt(nPatients);

ThControls = [mean(Th(controlInd),'omitnan'),std(Th(controlInd),'omitnan')/sqrt(nControls)];
ThPatients = [mean(Th(patientInd),'omitnan'),std(Th(patientInd),'omitnan')/sqrt(nControls)];

%%

plotVar.pLines = {':'};
plotVar.pSymbols = [ 'o', '^', 's', 'v', 'p', 'h', '>', '<', 'x', '+', '*' ];
plotVar.pColors = [112,179,250;... % azul
           210,45,45;... % vermelho
           99,199,113;... % verde
           194,129,201;... % roxo
           230,191,108;... % laranja
           210,217,78]./255; % amarelo
plotVar.redMatrix = [ 249,42,42;...
              194,29,29;...
              146,18,18;...
              89,5,5 ]./255;
plotVar.blueMatrix = plotVar.redMatrix(:,3:1);
plotVar.pPointSize = 3;
plotVar.pPointFaceColor = 'w';
plotVar.pLineColor = 'k';
plotVar.pLineWidth = 1;
plotVar.pErrSymbol = '';
plotVar.pErrLineSpec = '-';
plotVar.pErrLineWidth = 0.5;
plotVar.pErrLineColor = 'auto';%[0.6,0.6,0.6];

%%

% getPlotStruct(x, y, yErr, xLabel, yLabel, xScale, yScale, legendParName, legendParValues, showLegend, plotTitle)
%ps = getPlotStruct(si.PhaseTrans.data.Theta, si.PhaseTrans.data.rho, cellfun(@sqrt,si.PhaseTrans.data.varRho, 'UniformOutput', false), ...
psRho = getPlotStruct(si.PhaseTrans.data.Theta, si.PhaseTrans.data.rho, cell(size(si.PhaseTrans.data.Theta)), ...
    '$\theta$', '$\rho$', 'linear', 'linear', '', si.caseName, zeros(size(si.PhaseTrans.data.Theta)), sprintf('seed = %s; matrix = %s;', seedType, matrixType));
plotPlotStruct([], psRho, plotVar.pLines, [], plotVar.pSymbols, plotVar.pColors, ...
    {'LineWidth', plotVar.pLineWidth, 'MarkerSize', plotVar.pPointSize},... % plot properties
    {'ShowErrorBar', 'on', 'LineSpec', plotVar.pErrLineSpec, 'LineWidth', plotVar.pErrLineWidth, 'Color', plotVar.pErrLineColor},... % error properties
    {'Box', 'off', 'Layer', 'top', 'XLim', [0,0.23] },... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

%%

psVarRho = getPlotStruct(si.PhaseTrans.data.Theta, si.PhaseTrans.data.NVarRho, cell(size(si.PhaseTrans.data.Theta)), ...
    '$\theta$', '$N\textnormal{Var}(\rho)$', 'linear', 'linear', '', si.caseName, zeros(size(si.PhaseTrans.data.Theta)), sprintf('seed = %s; matrix = %s;', seedType, matrixType));
plotPlotStruct([], psVarRho, plotVar.pLines, [], plotVar.pSymbols, plotVar.pColors, ...
    {'LineWidth', plotVar.pLineWidth, 'MarkerSize', plotVar.pPointSize},... % plot properties
    {'ShowErrorBar', 'on', 'LineSpec', plotVar.pErrLineSpec, 'LineWidth', plotVar.pErrLineWidth, 'Color', plotVar.pErrLineColor},... % error properties
    {'Box', 'off', 'Layer', 'top', 'XLim', [0,0.23] },... % axis properties
    {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
    {'FontSize', 12}); % label properties

%%
if numel(patientInd) > 1
    x = { 1:nControls, (nControls + (1:numel(find(patientInd)))) };
    y = { Th(controlInd), Th(patientInd) };
    psThresh = getPlotStruct(x,y,cell(1,2),...
        'Case', '$\theta_T$', 'linear', 'linear', '', {'Controls',legendText}, ones(1,2), '');
    plotPlotStruct([], psThresh, plotVar.pLines, [], plotVar.pSymbols, plotVar.pColors, ...
        {'LineWidth', plotVar.pLineWidth, 'MarkerSize', plotVar.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineSpec', plotVar.pErrLineSpec, 'LineWidth', plotVar.pErrLineWidth, 'Color', plotVar.pErrLineColor},... % error properties
        {'Box', 'off', 'Layer', 'top' },... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
end

%%

if numel(patientInd) > 1
    x = { si.PhaseTrans.data.Theta{1}, si.PhaseTrans.data.Theta{1} };
    y = { rhoMeanControls, rhoMeanPatients };
    yErr = { rhoErrControls, rhoErrPatients };
    psRhoMean = getPlotStruct(x,y,yErr,...
        '$\theta$', '$\bar{\rho}$', 'linear', 'linear', '', {'Controls',legendText}, ones(1,2), '');
    plotPlotStruct([], psRhoMean, plotVar.pLines, [], plotVar.pSymbols, plotVar.pColors, ...
        {'LineWidth', plotVar.pLineWidth, 'MarkerSize', plotVar.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineSpec', plotVar.pErrLineSpec, 'LineWidth', plotVar.pErrLineWidth, 'Color', plotVar.pErrLineColor},... % error properties
        {'Box', 'off', 'Layer', 'top', 'XLim', [0.02,0.18] },... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
    
    x = { si.PhaseTrans.data.Theta{1}, si.PhaseTrans.data.Theta{1} };
    y = { NVarRhoMeanControls, NVarRhoMeanPatients };
    yErr = { NVarRhoErrControls, NVarRhoErrPatients };
    psNVarRhoMean = getPlotStruct(x,y,yErr,...
        '$\theta$', '$\bar{N\textnormal{Var}(\rho)}$', 'linear', 'linear', '', {'Controls',legendText}, ones(1,2), '');
    plotPlotStruct([], psNVarRhoMean, plotVar.pLines, [], plotVar.pSymbols, plotVar.pColors, ...
        {'LineWidth', plotVar.pLineWidth, 'MarkerSize', plotVar.pPointSize},... % plot properties
        {'ShowErrorBar', 'on', 'LineSpec', plotVar.pErrLineSpec, 'LineWidth', plotVar.pErrLineWidth, 'Color', plotVar.pErrLineColor},... % error properties
        {'Box', 'off', 'Layer', 'top', 'XLim', [0.02,0.18] },... % axis properties
        {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties
end

