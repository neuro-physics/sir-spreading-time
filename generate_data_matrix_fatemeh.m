addpath func

load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');
[~,~,~,aal]=aalsurfview(zeros(90,1));
cdb = load('D:\Dropbox\p\postdoc\data\TLE_NB_BB.mat');

dataToUse = 'flip';
% dataToUse = 'raw';

%%

% getting control indices
[pInd,cInd] = getPatientControlInd(caseName);

if strcmpi(dataToUse,'raw')
    s=[SpMatrixW.data];
    fileName = 'D:\Dropbox\p\postdoc\data\sirs\selected\N306\sptime_data_fatemeh.mat';
elseif strcmpi(dataToUse,'flip')
    s=[SpMatrixW.flipData];
    fileName = 'D:\Dropbox\p\postdoc\data\sirs\selected\N306\sptime_flipdata_fatemeh.mat';
end
s=s(4);
sm=SpMatrixW(4).flipData.SAvg;

N = 306;

comm_labels = aal.labels.AAL09comm;

hv_s = getHippVolumeStruct(cdb, caseName, 'HipVol', 'NC', 'ipsi');
hv_s_contra = getHippVolumeStruct(cdb, caseName, 'HipVol', 'NC', 'contra');

HV_ipsi_controls = hv_s.flip.Vol(cInd);
HV_ipsi_patients = hv_s.flip.Vol(pInd);
HV_contra_controls = hv_s_contra.flip.Vol(cInd);
HV_contra_patients = hv_s_contra.flip.Vol(pInd);

%%
% preparing data matrices
in_S = matCell2Mat(s.SAvgR);
out_S = matCell2Mat(s.SAvgS);
s.SAvgR = cellfun(@(x)x',s.SAvgR,'UniformOutput',false)';
s.SAvgS = cellfun(@(x)x',s.SAvgS,'UniformOutput',false)';

S_controls = mean(matCell2Mat(sm(cInd)),2,'omitnan');
S_patients = mean(matCell2Mat(sm(pInd)),2,'omitnan');
Sm_controls = sm(cInd);
Sm_patients = sm(pInd);
in_S_controls = s.SAvgR(cInd);
in_S_patients = s.SAvgR(pInd);
out_S_controls = s.SAvgS(cInd);
out_S_patients = s.SAvgS(pInd);

in_S_controls_matrix = in_S(cInd,:);
in_S_patients_matrix = in_S(pInd,:);
out_S_controls_matrix = out_S(cInd,:);
out_S_patients_matrix = out_S(pInd,:);

in_S_controls_comm = averageSector(in_S_controls_matrix,aal.comm.AAL306,'line');
in_S_patients_comm = averageSector(in_S_patients_matrix,aal.comm.AAL306,'line');
out_S_controls_comm = averageSector(out_S_controls_matrix,aal.comm.AAL306,'line');
out_S_patients_comm = averageSector(out_S_patients_matrix,aal.comm.AAL306,'line');

code_patients = caseName(pInd)';
code_controls = caseName(cInd)';

%%

% in_S_patients_table = struct2table(struct('code',code_patients,'in_sp_time',in_S_patients));
% in_S_controls_table = struct2table(struct('code',code_controls,'in_sp_time',in_S_controls));
% out_S_patients_table = struct2table(struct('code',code_patients,'out_sp_time',out_S_patients));
% out_S_controls_table = struct2table(struct('code',code_controls,'out_sp_time',out_S_controls));

%%

save(fileName,'in_S_controls_matrix','in_S_patients_matrix','out_S_controls_matrix','out_S_patients_matrix',...
              'in_S_controls_comm','in_S_patients_comm','out_S_controls_comm','out_S_patients_comm',...
              'HV_ipsi_patients','HV_ipsi_controls','HV_contra_patients','HV_contra_controls',...
              'S_controls','S_patients','code_patients','code_controls','comm_labels','Sm_controls','Sm_patients','-v7.3');