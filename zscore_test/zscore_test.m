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

nCases = numel(group);

data(data==0)=NaN;

%%
disp('raw data');
m = mean(data,2,'omitnan');
s = std(data,[],2,'omitnan');
[t.h,~,~,t.st] = ttest2(m(cInd),m(pInd),'Alpha',0.05);

   disp('   mean(mean) +- mean(SD)');
fprintf('   Controls: %.5g +/- %.5g\n',mean(m(cInd)),mean(s(cInd)));
fprintf('        TLE: %.5g +/- %.5g\n',mean(m(pInd)),mean(s(pInd)));
fprintf('    T-value: %.5g\n',t.st.tstat);

figure;
plot(1:numel(cInd),m(cInd),'-o',1:numel(cInd),s(cInd),'-s',numel(cInd)+(1:numel(pInd)),m(pInd),'-o',numel(cInd)+(1:numel(pInd)),s(pInd),'-s');
hold on;
line([0,nCases],[0,0],'LineStyle', '--', 'Color','k','HandleVisibility','off');line([0,nCases],[1,1],'LineStyle', '--', 'Color','k','HandleVisibility','off');
xlabel('case #'); ylabel('mean and SD of avg. sp time');
legend({'mean Controls','SD Controls','mean TLE','SD TLE'},'location','best');
title('Raw data');

%%
disp('---');
disp('z-scoring individually');
z = myzscore(data,0,2); % matrix of z-scored individuals
m_z = mean(z,2,'omitnan');
s_z = std(z,[],2,'omitnan');
[t_z.h,~,~,t_z.st] = ttest2(m_z(cInd),m_z(pInd),'Alpha',0.05);

   disp('   mean(mean) +- mean(SD)');
fprintf('   Controls: %.5g +/- %.5g\n',mean(m_z(cInd)),mean(s_z(cInd)));
fprintf('        TLE: %.5g +/- %.5g\n',mean(m_z(pInd)),mean(s_z(pInd)));
fprintf('    T-value: %.5g\n',t_z.st.tstat);

figure;
plot(1:numel(cInd),m_z(cInd),'-o',1:numel(cInd),s_z(cInd),'-s',numel(cInd)+(1:numel(pInd)),m_z(pInd),'-o',numel(cInd)+(1:numel(pInd)),s_z(pInd),'-s');
hold on;
line([0,nCases],[0,0],'LineStyle', '--', 'Color','k','HandleVisibility','off');line([0,nCases],[1,1],'LineStyle', '--', 'Color','k','HandleVisibility','off');
xlabel('case #'); ylabel('mean and SD of avg. sp time');
legend({'mean Controls','SD Controls','mean TLE','SD TLE'},'location','best');
title('Individually z-scored data');

%%
disp('---');
disp('z-scoring to controls the individually z-scored data');
zz = zScoreToSubset(z,cInd); % z-scoring to controls the individually z-scored data
m_zz = mean(zz,2,'omitnan');
s_zz = std(zz,[],2,'omitnan');
[t_zz.h,~,~,t_zz.st] = ttest2(m_zz(cInd),m_zz(pInd),'Alpha',0.05);

   disp('   mean(mean) +- mean(SD)');
fprintf('   Controls: %.5g +/- %.5g\n',mean(m_zz(cInd)),mean(s_zz(cInd)));
fprintf('        TLE: %.5g +/- %.5g\n',mean(m_zz(pInd)),mean(s_zz(pInd)));
fprintf('    T-value: %.5g\n',t_zz.st.tstat);

figure;
plot(1:numel(cInd),m_zz(cInd),'-o',1:numel(cInd),s_zz(cInd),'-s',numel(cInd)+(1:numel(pInd)),m_zz(pInd),'-o',numel(cInd)+(1:numel(pInd)),s_zz(pInd),'-s');
hold on;
line([0,nCases],[0,0],'LineStyle', '--', 'Color','k','HandleVisibility','off');line([0,nCases],[1,1],'LineStyle', '--', 'Color','k','HandleVisibility','off');
xlabel('case #'); ylabel('mean and SD of avg. sp time');
legend({'mean Controls','SD Controls','mean TLE','SD TLE'},'location','best');
title('z-score to controls of the individually z-scored data');

%%
disp('---');
disp('z-scoring to controls the raw data');
zc = zScoreToSubset(data,cInd); % z-scoring to controls the individually z-scored data
m_zc = mean(zc,2,'omitnan');
s_zc = std(zc,[],2,'omitnan');
[t_zc.h,~,~,t_zc.st] = ttest2(m_zc(cInd),m_zc(pInd),'Alpha',0.05);

   disp('   mean(mean) +- mean(SD)');
fprintf('   Controls: %.5g +/- %.5g\n',mean(m_zc(cInd)),mean(s_zc(cInd)));
fprintf('        TLE: %.5g +/- %.5g\n',mean(m_zc(pInd)),mean(s_zc(pInd)));
fprintf('    T-value: %.5g\n',t_zc.st.tstat);

figure;
plot(1:numel(cInd),m_zc(cInd),'-o',1:numel(cInd),s_zc(cInd),'-s',numel(cInd)+(1:numel(pInd)),m_zc(pInd),'-o',numel(cInd)+(1:numel(pInd)),s_zc(pInd),'-s');
hold on;
line([0,nCases],[0,0],'LineStyle', '--', 'Color','k','HandleVisibility','off');line([0,nCases],[1,1],'LineStyle', '--', 'Color','k','HandleVisibility','off');
xlabel('case #'); ylabel('mean and SD of avg. sp time');
legend({'mean Controls','SD Controls','mean TLE','SD TLE'},'location','best');
title('z-score to controls of the raw data');
