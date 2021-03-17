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
theta = 0.01;
brainShadeAlpha = 0;
caseName = '301_1';

N = size(A,1);
L = sqrt(N);
n = GetNodes(A, theta, 0, 2, true);
% p = GetSimulationParam(A, 2, true, 'random', [], 1);
p = GetSimulationParam(A, 2, true, 'fixed', find(~cellfun(@isempty,strfind(aal.labels.AAL306,'Hippocampus'))), 1);
x = EvolveSINetwork_mex(n, 20, p, 1);

%%
figure;
imagesc(x);
xlabel('Node');
ylabel('Time');
set(gca, 'YDir', 'Reverse');
title('Time evolution')

randNum = num2str(randi(10,1,5)-1);
randNum = randNum(randNum~=' ');

%plotBrain(pos,x,1:size(x,1),[strrep(caseName,'_','\_'),'; \theta=',num2str(theta)],true,['sp_',caseName,'_',randNum]);
% [fh,axh]=plotBrain(pos,x,1:size(x,1),[strrep(caseName,'_','\_'),'; \theta=',num2str(theta)],false,['sp_',caseName,'_',randNum],brainShadeAlpha,[1,1,1;0,0,0;1,0,0]);
[fh,axh]=plotBrain(pos,x,1:size(x,1),'',true,['sp_',caseName,'_',randNum],brainShadeAlpha,[1,1,1;0,0,0;1,0,0]);

%%

% frames = makeVideo(axh, ['sp_',caseName,'_',randNum,'.mp4'], 'mp4');
frames = makeVideo(axh, ['sp_2s_',caseName,'_',randNum,'.gif'], 'gif');
close(fh);
