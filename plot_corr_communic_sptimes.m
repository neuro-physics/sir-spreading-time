clearvars
close all

% addpath func

% si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data.mat');
% spField = 'SpMatrix';
si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');
spField = 'SpMatrixW';
co = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\communic.mat');
co = sortFieldsContents(co,si.caseName);
%%
p_thresh = 0.001;
thetaInd = 4;

weightedTxt = '';
if strcmp(spField,'SpMatrixW')
    weightedTxt = 'weighted ';
end

[pInd,cInd] = getPatientControlInd(si.caseName);
Sinv = cellfun(@(x)1./x,si.(spField)(thetaInd).data.SAvg,'UniformOutput',false);
Sinv_Z = zScoreToSubset(Sinv,cInd);

[r_c_specific,p_c_specific,...
    r_c,p_c,...
    r_p_specific,p_p_specific,...
    r_p,p_p,theta] = ...
    corrcoef_datastruct(si.(spField),co,'data','SAvg','Co',true,true,si.caseName);

[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (communic. and inverse ',weightedTxt,'sp times)'],[0,0.42],p_thresh,...
    r_c_specific,p_c_specific,r_c,p_c,r_p_specific,p_p_specific,r_p,p_p,theta);

[fh,axh] = plotScatterCorr([],[],co.Co_Z{end}(:),Sinv{end}(:),co.Co_Z{1}(:),Sinv{1}(:),'Communic','Sp Time',[],'');
[fh,axh] = plotScatterCorr([],[],co.Co_Z{end}(:),Sinv_Z{end}(:),co.Co_Z{1}(:),Sinv_Z{1}(:),'Communic','Sp Time',[],'');

%%%% the z-scored to controls data breaks down any correlation
% figure;
% errorbar(theta,mean(r_c_specific_z,1,'omitnan'),std(r_c_specific_z,[],1,'omitnan'),':o', 'Color', lc(1,:), 'MarkerFaceColor', lc(1,:)); hold all
% errorbar(theta,mean(r_p_specific_z,1,'omitnan'),std(r_p_specific_z,[],1,'omitnan'),':o', 'Color', lc(2,:), 'MarkerFaceColor', lc(2,:));
% plot(theta,r_c_z,':s','Color',lc(1,:))
% plot(theta,r_p_z,':s','Color',lc(2,:))
% xlabel('\theta');ylabel(['R (Z communic. and inverse Z ',weightedTxt,'sp times)']);
% legend({'Controls specific','TLE specific', 'Controls avg', 'TLE avg'});