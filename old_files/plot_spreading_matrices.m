clearvars
close all

addpath .\func

% if calc new data
%parseSpreadingTimeMatrixFiles('D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w', 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w.mat');
%load('D:\Dropbox\p\postdoc\data\AAL_data\aal_labels_N90.mat')
%calcCommunities('D:\Dropbox\p\postdoc\data\AALmatrix_N90\TLE*_FA_*.mat', 1:0.5:3.5, 10, aal_labels, true, 'D:\Dropbox\p\postdoc\data\sirs\N90\comm.mat')

ggamma = 2.5;
saveFig = true;
indPlot = []; % if empty, plots all the fig
plotShortPathDiff = true;

% inputFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.00_nSim100_w.mat';
% inputFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.01_nSim100_w.mat';
% inputFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.03_nSim100_w.mat';
inputFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\sp_N90_theta0.05_nSim100_w.mat';
commFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\comm.mat';
sPathFile = 'D:\Dropbox\p\postdoc\data\sirs\N90\shortPath.mat';

%%
sp = load(inputFile);
cm = load(commFile);
p = load(sPathFile);
gIndex = find(cm.ggamma == ggamma, 1);
if isempty(gIndex)
    error('required ggamma not found in file %s',commFile);
end
nComm = max(cm.C{gIndex});
C_labels = cell(1,nComm);
for i = 1:nComm
    C_labels{i} = cm.aal_labels(cm.C{gIndex} == i);
end

%%

if plotShortPathDiff
    mainFigOutDir = 'sp_spath_fig';
else
    mainFigOutDir = 'sp_fig';
end

[figOutputDir,fn,~] = fileparts(inputFile);
fn = strrep(strrep(fn, '_N90', ''), '_N306', '');
figOutputDir = [ figOutputDir, filesep, mainFigOutDir ];
if saveFig && (exist(figOutputDir, 'dir') ~= 7)
    mkdir(figOutputDir);
end
figOutputDir = [ figOutputDir, filesep, fn, '_gamma', num2str(ggamma) ];
if saveFig && (exist(figOutputDir, 'dir') ~= 7)
    mkdir(figOutputDir);
end

rm = regexp(fn, 'theta\d+\.\d+','match');
theta = str2double(rm{1}(6:end));

[~,s] = sort(cm.C{gIndex});

%%
panelW = 300; % px
x0Ax = 45; % px
y0Ax = x0Ax; % px
cBarW = 60; % px
ax1Pos = [x0Ax, y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
ax2Pos = [(x0Ax + panelW), y0Ax,(panelW-x0Ax), (panelW-y0Ax)];
figW = cBarW + 2 * panelW;

[nColors,foundNaN] = getNumOfColors(sp.SAvg);
if plotShortPathDiff
    nColors = 4; % -1, 0, 1, 2==NaN
end

% i = 12;
if isempty(indPlot)
    indPlot = 1:numel(sp.SAvg);
end
%%
for i = indPlot
    if plotShortPathDiff
        fh = figure('Position', [400,400,(cBarW+panelW),(panelW + x0Ax)]);
        axh = axes('Units', 'pixels', 'Position', ax1Pos);
        S = p.P{i} - sp.SAvg{i};
        S(S<0) = -1;
        S(S>0) = 1;
        S(isnan(S)) = 2;
        ih = imagesc(S(s,s), [-1,2]);
        ih.CDataMapping = 'scaled';
        xlabel('target');
        ylabel('seed');
        colormap(flipud(parula(nColors)));
        cb = colorbar;
        cb.LimitsMode = 'manual';
        cb.Limits = [-1,2];
        cb.Units = 'pixels';
        cb.Ticks = -1:2;
        cb.TickLabels = { 'slower', 'equal', 'faster', 'NaN' };%cellstr(num2str((-1:2)'))';
        cb.Position = [306 42 10 256];
        cb.Label.Rotation = 90;
        %cb.Label.String = 'Time steps';
        %cb.TickLabels{end} = 'NaN';
        axis(axh,'square')
        titleText = [ strrep(sp.caseName{i},'_','\_'), '; $\gamma=',num2str(ggamma),'$; $\theta=',num2str(theta),'$' ];
        anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titleText, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold');
        anh.Position(1) = panelW/2 - anh.Position(3)/2 - x0Ax;
        anh.Position(2) = panelW + anh.Position(4) + y0Ax/2;
    else
        fh = figure('Position', [400,400,figW,(panelW + x0Ax)]);
        axh(1) = axes('Units', 'pixels', 'Position', ax1Pos);
        S = sp.SAvg{i};
        S(isnan(S)) = nColors - 1;
        ih(1) = imagesc(S, [0,(nColors-1)]);
        ih(1).CDataMapping = 'scaled';
        xlabel('target');
        ylabel('seed');
        axh(2) = axes('Units', 'pixels', 'Position', ax2Pos);
        ih(2) = imagesc(S(s,s), [0,(nColors-1)]);
        ih(2).CDataMapping = 'scaled';
        xlabel('target');
        ylabel('seed');
        %nColors = ceil(max(r.SAvg{i}(:))) + 1; % +1 for counting t = 0
        colormap(flipud(parula(nColors)));
        cb = colorbar;
        cb.LimitsMode = 'manual';
        cb.Limits = [0,(nColors-1)];
        cb.Units = 'pixels';
        cb.Ticks = 0:nColors;
        cb.Position = [610 39 13 255];
        cb.Label.String = 'Time steps';
        if foundNaN
            cb.TickLabels{end} = 'NaN';
        end
        axh(2).Position = ax2Pos;
        axis(axh(1),'square')
        axis(axh(2),'square')
        titleText = [ strrep(sp.caseName{i},'_','\_'), '; $\gamma=',num2str(ggamma),'$; $\theta=',num2str(theta),'$' ];
        anh = annotation(fh,'textbox',[0.5,0.5,0.01,0.01], 'String', titleText, 'EdgeColor', 'none', 'Interpreter', 'latex', 'FitBoxToText', 'on', 'Units', 'pixels', 'FontWeight', 'bold');
        anh.Position(1) = panelW - anh.Position(3)/2 - x0Ax;
        anh.Position(2) = panelW + anh.Position(4) + y0Ax/2;
    end
    if (saveFig)
        saveas(fh, [ figOutputDir, filesep, 'sp_', sp.caseName{i} ], 'png');
        close(fh);
    end
end
