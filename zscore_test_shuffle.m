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

cData = reshape(data(cInd,:),numel(cInd)*N2,1);
pData = reshape(data(pInd,:),numel(pInd)*N2,1);

%%

% z-scoring to controls the raw data
Z = zScoreToSubset(data,cInd);

Z_c = Z(cInd,:);
Z_p = Z(pInd,:);

[~,~,~,~,t] = myttest2(Z_c(:),Z_p(:))

%%

% z-scoring to controls the shuffled shuffled raw data
Zs = zScoreToSubset([reshape(cData(randperm(numel(cData))),numel(cInd),N2);reshape(pData(randperm(numel(pData))),numel(pInd),N2)],cInd);

Zs_c = Zs(cInd,:);
Zs_p = Zs(pInd,:);

[~,~,~,~,t_Zs] = myttest2(Zs_c(:),Zs_p(:))


%%

% z-scoring to controls the individually z-scored shuffled data
Zzs = zScoreToSubset([myzscore(reshape(cData(randperm(numel(cData))),numel(cInd),N2),0,2);myzscore(reshape(pData(randperm(numel(pData))),numel(pInd),N2),0,2)],cInd);

Zzs_c = Zzs(cInd,:);
Zzs_p = Zzs(pInd,:);

[~,~,~,~,t_Zzs] = myttest2(Zzs_c(:),Zzs_p(:))
