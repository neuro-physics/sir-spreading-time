clearvars
close all

% addpath func

si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data.mat');
spField = 'SpMatrix';
% si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');
% spField = 'SpMatrixW';
p = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\shortPath.mat');

%%

p_thresh = 0.001;

weightedTxt = '';
if strcmp(spField,'SpMatrixW')
    weightedTxt = 'weighted ';
end

[r_c_specific,p_c_specific,...
    r_c,p_c,...
    r_p_specific,p_p_specific,...
    r_p,p_p,theta,scplot] = ...
    corrcoef_datastruct(si.(spField),p,'data','SAvg','P',false,false,si.caseName,'shortPath');

[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (shortest path and ',weightedTxt,'sp times)'],[0,1.1],p_thresh,...
    r_c_specific,p_c_specific,r_c,p_c,r_p_specific,p_p_specific,r_p,p_p,theta);

%%%% the z-scored data breaks down any correlation
% figure;
% errorbar(theta,mean(r_c_specific_z,1,'omitnan'),std(r_c_specific_z,[],1,'omitnan'),':o', 'Color', lc(1,:), 'MarkerFaceColor', lc(1,:)); hold all
% errorbar(theta,mean(r_p_specific_z,1,'omitnan'),std(r_p_specific_z,[],1,'omitnan'),':o', 'Color', lc(2,:), 'MarkerFaceColor', lc(2,:));
% plot(theta,r_c_z,':s','Color',lc(1,:))
% plot(theta,r_p_z,':s','Color',lc(2,:))
% xlabel('\theta');ylabel(['R (Z shortest path and Z ',weightedTxt,'sp times)']);
% legend({'Controls','TLE'});