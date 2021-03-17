clearvars
close all

addpath('func');

[~,~,~,aal] = aalsurfview(zeros(90,1));

cMap = brewerCMap(10,2);

%%

aalsurfview(aal.comm.AAL09comm,'Yeo correspondance to our parcellation',cMap(1:9,:));
aalsurfview(aal.comm.AAL90,'AAL',cMap);
aalsurfview(aal.comm.AAL306,'AAL',cMap);

disp('--');
disp('Community indices:');
disp(cellfun(@(x)[num2str(x),' -> ',aal.labels.AAL09comm{x}],num2cell(1:numel(aal.labels.AAL09comm)),'UniformOutput',false)');
disp('--');
