clearvars -except si co
close all

addpath func

communicFile = 'D:\Dropbox\p\postdoc\data\sirs\selected\N306\communic.mat';
% spTimeFile = 'D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data.mat';
spTimeFile = 'D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat';
thetaInd = 4;

if ~(exist('co','var') == 1)
    co = load(communicFile);
end
if ~(exist('si','var') == 1)
    si = load(spTimeFile);
end

co = sortFieldsContents(co,si.caseName);

[pInd_c,cInd_c] = getPatientControlInd(co.caseName);
[pInd_s,cInd_s] = getPatientControlInd(si.caseName);

N = size(co.Co{1},1);
co_z = matCell2Mat(co.Co);
co_z(:,1:(N+1):end) = repmat(max(co_z,[],2) + 1,1,N); % setting the communicability of a node to itself (main diagonal of Co matrices) to be the max + 1
co_z = zScoreToSubset(co_z,cInd_c);
Cc = co_z(cInd_c,:);
Cp = co_z(pInd_c,:);

% Sc = matCell2Mat(si.SpMatrix(thetaInd).zControlData.SAvg(cInd_s));
% Sp = matCell2Mat(si.SpMatrix(thetaInd).zControlData.SAvg(pInd_s));
% Sc = matCell2Mat(si.SpMatrix(thetaInd).data.SAvg(cInd_s));
% Sp = matCell2Mat(si.SpMatrix(thetaInd).data.SAvg(pInd_s));

Sc = matCell2Mat(si.SpMatrixW(thetaInd).zControlData.SAvg(cInd_s));
Sp = matCell2Mat(si.SpMatrixW(thetaInd).zControlData.SAvg(pInd_s));
% Sc = matCell2Mat(si.SpMatrixW(thetaInd).data.SAvg(cInd_s));
% Sp = matCell2Mat(si.SpMatrixW(thetaInd).data.SAvg(pInd_s));
Sc(isnan(Sc)) = 0;
Sp(isnan(Sp)) = 0;


%[fh,axh] = plotScatterCorr([],[],Sp(1,:),Cp(1,:),Sc(1,:),Cc(1,:),'Sp. times','Communicability');
[fh,axh] = plotScatterCorr([],[],Cp(1,:),Sp(1,:),Cc(1,:),Sc(1,:),'Communicability','Sp. times');