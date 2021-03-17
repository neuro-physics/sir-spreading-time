addpath('func');

rootDataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    rootDataDir = '/host/scarus/local_raid/mauricio/data';
end

dataDir = [fullfile(rootDataDir,'AALmatrix_N306'),filesep];
nTxt = 'N306';

group = 'controls';
hippath = 'none';
[A_controls,~] = getSubjectsAdjMatrix([dataDir,'TLE*_FA_*.mat'], [], [], true);
matrix = GetConsensusAdjMatrix(A_controls);
save([dataDir,'consensus_controls_',nTxt,'.mat'], 'matrix', 'group', 'hippath', '-v7.3');

group = {'LTLE'};
hippath = {'HS'};
[~,A_patients] = getSubjectsAdjMatrix([dataDir,'TLE*_FA_*.mat'], group, hippath, true);
matrix = GetConsensusAdjMatrix(A_patients);
save([dataDir,'consensus_LTLE-HS_',nTxt,'.mat'], 'matrix', 'group', 'hippath', '-v7.3');

group = {'controls','LTLE'};
hippath = {'none','HS'};
matrix = GetConsensusAdjMatrix([A_controls,A_patients]);
save([dataDir,'consensus_cLTLE-HS_',nTxt,'.mat'], 'matrix', 'group', 'hippath', '-v7.3');

group = {'RTLE'};
hippath = {'HS'};
[~,A_patients] = getSubjectsAdjMatrix([dataDir,'TLE*_FA_*.mat'], group, hippath, true);
matrix = GetConsensusAdjMatrix(A_patients);
save([dataDir,'consensus_RTLE-HS_',nTxt,'.mat'], 'matrix', 'group', 'hippath', '-v7.3');

group = {'controls','RTLE'};
hippath = {'none','HS'};
matrix = GetConsensusAdjMatrix([A_controls,A_patients]);
save([dataDir,'consensus_cRTLE-HS_',nTxt,'.mat'], 'matrix', 'group', 'hippath', '-v7.3');
