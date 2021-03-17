clearvars
close all

addpath func

% load('zscore_test_data_N90.mat');
load('zscore_test_data_N306.mat');
% load('zscore_test_data_N306_theta0.mat');
% load('zscore_test_data_N306_binary_short_path.mat');
% load('zscore_test_data_N306_shuffle.mat');
% load('zscore_normal_test_data_N306.mat');
% load('zscore_normal_test_data_N306_same_mean.mat');
% load('zscore_uniform_test_data_same_mean_N306.mat');


% loads variables data (size == num_cases Vs. sp_time_matrix_elements)
%                 group (size num_cases Vs. 1)
%   each group{i} corresponds to data(i,:)

cInd = find(strcmpi(group,'NC')); % indices of controls
pInd = find(strcmpi(group,'TLE')); % indices of patients

[nCases,N2] = size(data);

data(data==0)=NaN;

Z = zscore(data,0,2); % individually z-scoring the raw data
Zc = zScoreToSubset(data,cInd); % z-scoring to controls the raw data
Zz = zScoreToSubset(Z,cInd); % z-scoring to controls the individually z-scored data

% raw data vectors
data_c = reshape(data(cInd,:),numel(cInd)*N2,1);
data_p = reshape(data(pInd,:),numel(pInd)*N2,1);

% z-scored data vectors
Z_c = reshape(Z(cInd,:),numel(cInd)*N2,1);
Z_p = reshape(Z(pInd,:),numel(pInd)*N2,1);

% z-scored to controls raw data vectors
Zc_c = reshape(Zc(cInd,:),numel(cInd)*N2,1);
Zc_p = reshape(Zc(pInd,:),numel(pInd)*N2,1);

% z-scored to controls ind z-scored data vectors
Zz_c = reshape(Zz(cInd,:),numel(cInd)*N2,1);
Zz_p = reshape(Zz(pInd,:),numel(pInd)*N2,1);

%%

bins = minmax(data(:)');
bins = bins(1):(bins(2)+1);
[P_c,x_c] = histcounts(data_c,bins,'Normalization','probability');
[P_p,x_p] = histcounts(data_p,bins,'Normalization','probability');
x_c(end) = [];
x_p(end) = [];
figure;
plot(x_c,P_c,'-o',x_p,P_p,'-s')
xlabel('raw spreading times, s'); ylabel('P(s)');
legend({'Controls','TLE'});
title('raw data distribution');

%%

nBins = 30;
[P_Z_c,x_Z_c] = histcounts(Z_c,nBins,'Normalization','probability');
[P_Z_p,x_Z_p] = histcounts(Z_p,nBins,'Normalization','probability');
x_Z_c(end) = [];
x_Z_p(end) = [];
figure;
plot(x_Z_c,P_Z_c,'-o',x_Z_p,P_Z_p,'-s')
xlabel('individually z-scored sp time, z'); ylabel('P(z)');
legend({'Controls','TLE'});
title('individually z-scored data distribution');

%%

nBins = 30;
[P_Zc_c,x_Zc_c] = histcounts(Zc_c,nBins,'Normalization','probability');
[P_Zc_p,x_Zc_p] = histcounts(Zc_p,nBins,'Normalization','probability');
x_Zc_c(end) = [];
x_Zc_p(end) = [];
figure;
plot(x_Zc_c,P_Zc_c,'-o',x_Zc_p,P_Zc_p,'-s')
xlabel('z-scored to controls raw sp time, zc'); ylabel('P(zc)');
legend({'Controls','TLE'});
title('z-scored to controls raw data distribution');

%%

nBins = 30;
[P_Zz_c,x_Zz_c] = histcounts(Zz_c,nBins,'Normalization','probability');
[P_Zz_p,x_Zz_p] = histcounts(Zz_p,nBins,'Normalization','probability');
x_Zz_c(end) = [];
x_Zz_p(end) = [];
figure;
plot(x_Zz_c,P_Zz_c,'-o',x_Zz_p,P_Zz_p,'-s')
xlabel('z-scored to controls ind z-scored sp time, zz'); ylabel('P(zz)');
legend({'Controls','TLE'});
title('z-scored to controls ind z-scored data distribution');
