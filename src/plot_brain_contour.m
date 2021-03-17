clearvars
close all

addpath ..\func
dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
aal = load(fullfile(dataDir,'AAL_data','aal_cortex_map_olf294_fix.mat'));

[fh, axh, lh] = plotBrainSurf([], [], 0.95.*[1,1,1], 1, [], [], [0,30,60], [], 'z');
[fh, axh, lh] = plotBrainSurf([], [], 0.95.*[1,1,1], 1, [], [], [0,30,60], [], 'y');
[fh, axh, lh] = plotBrainSurf([], [], 0.95.*[1,1,1], 1, [], [], [10,40,60], [], 'x');