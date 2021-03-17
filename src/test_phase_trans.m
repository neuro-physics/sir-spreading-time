clearvars
close all

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

% inpFile = fullfile(dataDir,'AALmatrix_N306','filter_raw','TLE_301_1_FA_AAL_midres.mat');
% inpFile = fullfile(dataDir,'AALmatrix_N306','filter_length','TLE_301_1_FA_AAL_midres.mat');
% inpFile = fullfile(dataDir,'AALmatrix_N90','filter_length','TLE_0361_1_FA_AAL_lowres.mat');
% inpFile = fullfile(dataDir,'AALmatrix_N90','filter_raw','TLE_301_1_FA_AAL_lowres.mat');
inpFile = fullfile(dataDir,'AALmatrix_N90','TLE_301_1_FA_AAL_lowres.mat');
% inpFile = fullfile(dataDir,'AALmatrix_N90','TLE_0361_1_FA_AAL_lowres.mat');
tTotal = 100;
%Theta = 0.0101010101010101;
% Theta = 0.11;
Theta = linspace(0,0.2,11);
x0 = 0;
useBinary = false;
%useBinary = false;

rho = zeros(size(Theta));
NVarRho = zeros(size(Theta));

tmp = load(inpFile);
A = tmp.matrix;
if useBinary
    A(A~=0)=1;
end

nodes = GetNodes(A, Theta(1), x0);
N = numel(nodes);

seedInd = 1:N;

x0 = repmat(x0, 1, N);
nAct = zeros(numel(Theta),numel(seedInd));
for k = 1:numel(Theta)
    T = Theta(k);
%     nAct = zeros(size(seedInd));
    for i = 1:numel(seedInd)
        s = seedInd(i);
        x0i = x0;
        x0i(s) = 1;
        nodes = ResetNodes(nodes, T, x0i);
        nAct(k,i) = EvolveSINetworkAndCountActive_mex(nodes,tTotal);
    end
    rho(k) = mean(nAct(k,:)) / N;
    NVarRho(k) = var(nAct(k,:));
%     nAct((nAct ~= N) & (nAct ~= 1))
end

[~,indTheta] = meshgrid(1:numel(seedInd),1:numel(Theta));
[~,indThetaS] = sort(indTheta(:));
theta_nAct = Theta(indTheta(indThetaS));
nAct_p = nAct(indThetaS)./N;

%%

labelProperties = { 'Interpreter', 'latex', 'FontSize', 16 };
figure;plot(Theta,rho,'-o',theta_nAct,nAct_p,'s');xlabel('$\theta$', labelProperties{:});ylabel('$\rho$', labelProperties{:});legend({ '$\rho=\langle s\rangle/N$', '$s_k/N$' }, 'Box', 'off', labelProperties{:});
figure;plot(Theta,rho.*N,'-o',theta_nAct,nAct_p.*N,'s');xlabel('$\theta$', labelProperties{:});ylabel('Size, $s$', labelProperties{:});legend({ '$\langle s\rangle$', '$s_k$' }, 'Box', 'off', labelProperties{:});
figure;plot(Theta,NVarRho,'-o');xlabel('$\theta$', labelProperties{:});ylabel('$\chi=N\textnormal{Var}(\rho)$', labelProperties{:});
