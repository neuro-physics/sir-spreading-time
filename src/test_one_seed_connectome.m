clearvars
close all

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

%temp = load('D:\Dropbox\p\postdoc\data\AALmatrix_N90\TLE_301_1_FA_AAL_lowres.mat');
temp = load(fullfile(dataDir,'AALmatrix_N306','TLE_301_1_FA_AAL_midres.mat'));
A = temp.matrix;

aal = load(fullfile(dataDir,'AAL_data','aal_cortex_map_olf294_fix.mat'));
pos = aal.pos.AAL306;
%cd ..\func
%pos = getNiiParcelCoord('D:\Dropbox\p\postdoc\data\AAL_data\parcellation\301_1_AAL_lowres_wmmasked_nii.nii');
%cd ..\src

%%
theta = 0.015;
brainShadeAlpha = 1.0;
% viewAngle = [90,10,0];
viewAngle = [0,0,90];
% viewAngle = [0,90,0];
saveFrames = false;
saveGIF = true;
caseName = '301_1';
indStim = find(strcmp(aal.labels.AAL306,'Hippocampus_R'));

N = size(A,1);
L = sqrt(N);
n = GetNodes(A, theta, 0, 1, false);
% p = GetSimulationParam(A, 1, false, 'random', [], 1);
p = GetSimulationParam(A, 1, false, 'fixed', indStim, 1);
[x,~,~,s] = EvolveSINetwork_mex(n, 20, p, 1);
s(:,indStim) = min(s(s>0));

randNum = num2str(randi(10,1,5)-1);
randNum = randNum(randNum~=' ');

%% spreading dynamics paper

fh2 = plotBrain(pos,s,[],[],saveFrames,['sp_',caseName,'_wei_',randNum],brainShadeAlpha,jet,viewAngle);
figNames = cellfun(@(x)['spreading_dynamics_t',num2str(x)],num2cell(1:numel(fh2)),'UniformOutput',false);
saveFigure(fh2,fullfile('D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01',figNames),...
           'tiff', false, {}, 600);

%%
figure;
imagesc(x);
xlabel('Node');
ylabel('Time');
set(gca, 'YDir', 'Reverse');
title('Time evolution')

figure;
imagesc(s);
xlabel('Node');
ylabel('Weighted time');
set(gca, 'YDir', 'Reverse');
title('Time evolution')

[fh1,axh1] = plotBrain(pos,x,[],[strrep(caseName,'_','\_'),'; \theta=',num2str(theta)],saveFrames,['sp_',caseName,'_bin_',randNum],brainShadeAlpha,[0,0,0],viewAngle);
[fh2,axh2] = plotBrain(pos,s,[],[strrep(caseName,'_','\_'),'; \theta=',num2str(theta)],saveFrames,['sp_',caseName,'_wei_',randNum],brainShadeAlpha,jet,viewAngle);

%%

if saveGIF
    frames = makeVideo(axh1, ['sp_',caseName,'_bin_',randNum,'.gif'], 'gif');
    frames = makeVideo(axh2, ['sp_',caseName,'_wei_',randNum,'.gif'], 'gif');
end