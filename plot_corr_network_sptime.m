clearvars
close all

addpath func

np = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\net_prop_flip_Z.mat');
si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');

[~,~,~,aal] = aalsurfview(zeros(90,1));

spField = 'SpMatrixW';

% merging structs
npm = mergeStruct({'A','caseName','density','shortestPathBin','shortestPathWei',...
                   'Pw','wEdges','clusterCoeffBin','clusterCoeffWei','inDegree',...
                   'outDegree','inDegreeWei','outDegreeWei','betweenCenBin','betweenCenWei'},...
                   np.Controls, np.LTLE, np.RTLE);
npm = sortFieldsContents(npm,si.caseName);
thetaInd = 4; % theta index
[pInd,~] = getPatientControlInd(si.caseName);
p_thresh = 0.001;

weightedTxt = '';
if strcmp(spField,'SpMatrixW')
    weightedTxt = 'weighted ';
end

line_colors_Rtheta = [79,146,190; % lighter blue
                      2,32,99; % darker blue
                      96,181,47; % lighter green
                      4,71,3]./255; % darker green
c_temp = lines(5);
dot_color_base = c_temp(5:-1:4,:);

saveOutputFigures = false;

% bc = matCell2Mat(np.Controls.betweenCenWei);
% id = matCell2Mat(np.Controls.inDegree);
% od = matCell2Mat(np.Controls.outDegree);

%% betweenness centrality
[r_c_specific_bc_sr,p_c_specific_bc_sr,...
    r_c_bc_sr,p_c_bc_sr,...
    r_p_specific_bc_sr,p_p_specific_bc_sr,...
    r_p_bc_sr,p_p_bc_sr,theta,in_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvgR','betweenCenWei',false,false,si.caseName,'Betweenness Centrality');
[r_c_specific_bc_ss,p_c_specific_bc_ss,...
    r_c_bc_ss,p_c_bc_ss,...
    r_p_specific_bc_ss,p_p_specific_bc_ss,...
    r_p_bc_ss,p_p_bc_ss,~,out_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvgS','betweenCenWei',false,false,si.caseName,'Betweenness Centrality');

[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (between cen and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_bc_sr,p_c_specific_bc_sr,r_c_bc_sr,p_c_bc_sr,r_p_specific_bc_sr,p_p_specific_bc_sr,r_p_bc_sr,p_p_bc_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Spreading Times (Z-score)','Patients: In-Spreading Times (Z-score)'},0.1);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (between cen and ',weightedTxt,'in sp times)'],[-0.2,0.2],p_thresh,...
    r_c_specific_bc_ss,p_c_specific_bc_ss,r_c_bc_ss,p_c_bc_ss,r_p_specific_bc_ss,p_p_specific_bc_ss,r_p_bc_ss,p_p_bc_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Spreading Times (Z-score)','Patients: Out-Spreading Times (Z-score)'},0.1,axh);
legend(axh);
ylabel('Correlation coefficient (R)');
title(axh,'Weighted Betweenness Centrality (Z-score)','FontWeight','normal');
axh.XLim = [-0.0005,0.0255];

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(4).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(4).var_patient,1),1,0.1);
[lhp,axin,fhin] = plot_func.plot_many_cases([],in_scplot(4).var_patient,in_scplot(4).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axin,in_scplot(4).var_control,in_scplot(4).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axin,'YLim',[-3.8197 9.4590],'XLim',[-2.0902 9.4015]);
xlabel(axin,'Weighted Betweeness Centrality (Z-score)');
ylabel(axin,'In-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.2f',mean(r_p_specific_bc_sr(:,4)),max(p_p_specific_bc_sr(:,4)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_bc_sr(:,4)),max(p_c_specific_bc_sr(:,4)));
legh=legend(axin);
title(axin,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

[lhp,axout,fhout] = plot_func.plot_many_cases([],out_scplot(4).var_patient,out_scplot(4).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axout,out_scplot(4).var_control,out_scplot(4).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axout,'YLim',[-3.5644 7.3958],'XLim',[-2.4346 11.0401]);
xlabel(axout,'Weighted Betweeness Centrality (Z-score)');
ylabel(axout,'Out-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.2f',mean(r_p_specific_bc_ss(:,4)),max(p_p_specific_bc_ss(:,4)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_bc_ss(:,4)),max(p_c_specific_bc_ss(:,4)));
legh=legend(axout);
title(axout,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

set([axh,axin,axout],'FontSize',14);
axh.XLabel.FontSize = 18;

if saveOutputFigures
    saveFigure([fhR,fhin,fhout], fullfile('corr_fig',{'corr_sp_bc_z','corr_spin_bc_z','corr_spout_bc_z'}), 'tiff', true, [], 600);
end

%% clustering coefficient
[r_c_specific_cc_sr,p_c_specific_cc_sr,...
    r_c_cc_sr,p_c_cc_sr,...
    r_p_specific_cc_sr,p_p_specific_cc_sr,...
    r_p_cc_sr,p_p_cc_sr,~,in_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvgR','clusterCoeffWei',false,false,si.caseName,'Clustering Coefficient');
[r_c_specific_cc_ss,p_c_specific_cc_ss,...
    r_c_cc_ss,p_c_cc_ss,...
    r_p_specific_cc_ss,p_p_specific_cc_ss,...
    r_p_cc_ss,p_p_cc_ss,~,out_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvgS','clusterCoeffWei',false,false,si.caseName,'Clustering Coefficient');

[fhR,axh,~,ttR_in] = plot_func.plot_corrcoef_datastruct('\theta',['R (cluster coeff and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_cc_sr,p_c_specific_cc_sr,r_c_cc_sr,p_c_cc_sr,r_p_specific_cc_sr,p_p_specific_cc_sr,r_p_cc_sr,p_p_cc_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Spreading Times (Z-score)','Patients: In-Spreading Times (Z-score)'},0.1);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fhR,axh,~,ttR_out] = plot_func.plot_corrcoef_datastruct('\theta',['R (cluster coeff and ',weightedTxt,'out sp times)'],[-0.1,0.5],p_thresh,...
    r_c_specific_cc_ss,p_c_specific_cc_ss,r_c_cc_ss,p_c_cc_ss,r_p_specific_cc_ss,p_p_specific_cc_ss,r_p_cc_ss,p_p_cc_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Spreading Times (Z-score)','Patients: Out-Spreading Times (Z-score)'},0.1,axh);
legend(axh);
title(axh,'Weighted Clustering Coefficient (Z-score)','FontWeight','normal');
ylabel('Correlation coefficient (R)');
axh.XLim = [-0.0005,0.0255];

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(4).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(4).var_patient,1),1,0.1);
[lhp,axin,fhin] = plot_func.plot_many_cases([],in_scplot(4).var_patient,in_scplot(4).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axin,in_scplot(4).var_control,in_scplot(4).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axin,'YLim',[-3.6230 8.1475],'XLim',[-3.5673 5.6868]);
xlabel(axin,'Weighted Clustering Coefficient (Z-score)');
ylabel(axin,'In-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.2f',mean(r_p_specific_cc_sr(:,4)),max(p_p_specific_cc_sr(:,4)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_cc_sr(:,4)),max(p_c_specific_cc_sr(:,4)));
legh=legend(axin);
title(axin,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

[lhp,axout,fhout] = plot_func.plot_many_cases([],out_scplot(4).var_patient,out_scplot(4).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axout,out_scplot(4).var_control,out_scplot(4).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axout,'YLim',[-3.5644 7.2272],'XLim',[-3.5221 6.0359]);
xlabel(axout,'Weighted Clustering Coefficient (Z-score)');
ylabel(axout,'Out-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.2f',mean(r_p_specific_cc_ss(:,4)),max(p_p_specific_cc_ss(:,4)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_cc_ss(:,4)),max(p_c_specific_cc_ss(:,4)));
legh=legend(axout);
title(axout,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

set([axh,axin,axout],'FontSize',14);
axh.XLabel.FontSize = 18;

if saveOutputFigures
    saveFigure([fhR,fhin,fhout], fullfile('corr_fig',{'corr_sp_cc_z','corr_spin_cc_z','corr_spout_cc_z'}), 'tiff', true, [], 600);
end

%% FA values
[r_c_specific_fa_sr,p_c_specific_fa_sr,...
    r_c_fa_sr,p_c_fa_sr,...
    r_p_specific_fa_sr,p_p_specific_fa_sr,...
    r_p_fa_sr,p_p_fa_sr,theta,in_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvg','A',false,true,si.caseName,'FA values');
[r_c_specific_fa_ss,p_c_specific_fa_ss,...
    r_c_fa_ss,p_c_fa_ss,...
    r_p_specific_fa_ss,p_p_specific_fa_ss,...
    r_p_fa_ss,p_p_fa_ss,~,out_scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'flipData','SAvg','A',false,true,si.caseName,'FA values');

[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (FA and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_fa_sr,p_c_specific_fa_sr,r_c_fa_sr,p_c_fa_sr,r_p_specific_fa_sr,p_p_specific_fa_sr,r_p_fa_sr,p_p_fa_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Spreading Times (Z-score)','Patients: In-Spreading Times (Z-score)'},0.1,[],[-0.1,-0.4,0.01]);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (FA and ',weightedTxt,'out sp times)'],[-0.6,0.2],p_thresh,...
    r_c_specific_fa_ss,p_c_specific_fa_ss,r_c_fa_ss,p_c_fa_ss,r_p_specific_fa_ss,p_p_specific_fa_ss,r_p_fa_ss,p_p_fa_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Spreading Times (Z-score)','Patients: Out-Spreading Times (Z-score)'},0.1,axh,[-0.1,-0.35,0.01]);
legend(axh);
title(axh,'FA Values (Z-score)','FontWeight','normal');
ylabel('Correlation coefficient (R)');
axh.XLim = [-0.0005,0.0255];
% axh.YTick = -0.5:0.1:0;

thetaInd = 4;

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(thetaInd).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(thetaInd).var_patient,1),1,0.1);
[lhp,axin,fhin] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_patient,in_scplot(thetaInd).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axin,in_scplot(thetaInd).var_control,in_scplot(thetaInd).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axin,'YLim',[-16.5163934426229 11.5983606557377],'XLim',[-13.0498987336211 25.3146602567903]);
xlabel(axin,'FA values (Z-score)');
ylabel(axin,'In-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fa_sr(:,thetaInd)),max(p_p_specific_fa_sr(:,thetaInd)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fa_sr(:,thetaInd)),max(p_c_specific_fa_sr(:,thetaInd)));
legh=legend(axin);
title(axin,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

[lhp,axout,fhout] = plot_func.plot_many_cases([],out_scplot(thetaInd).var_patient,out_scplot(thetaInd).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
lhc = plot_func.plot_many_cases(axout,out_scplot(thetaInd).var_control,out_scplot(thetaInd).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(axout,'YLim',[-16.0245901639344 11.4344262295082],'XLim',[-13.0498987336211 25.3146602567903]);
xlabel(axout,'FA values (Z-score)');
ylabel(axout,'Out-Spreading Times (Z-score)');
set([lhp(1),lhc(1)],'HandleVisibility','on');
lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fa_ss(:,thetaInd)),max(p_p_specific_fa_ss(:,thetaInd)));
lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fa_ss(:,thetaInd)),max(p_c_specific_fa_ss(:,thetaInd)));
legh=legend(axout);
title(axout,sprintf('$\\theta=%g$',theta(4)),'FontWeight','normal','Interpreter','latex');

set([axh,axin,axout],'FontSize',14);
axh.XLabel.FontSize = 18;

if saveOutputFigures
    saveFigure([fhR,fhin,fhout], fullfile('corr_fig',{'corr_sp_fa_z','corr_spin_fa_z','corr_spout_fa_z'}), 'tiff', true, [], 600);
end

%% in degree
[r_c_specific_id_sr,p_c_specific_id_sr,...
    r_c_id_sr,p_c_id_sr,...
    r_p_specific_id_sr,p_p_specific_id_sr,...
    r_p_id_sr,p_p_id_sr,~,scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'data','SAvgR','inDegree',false,false,si.caseName,'In Degree');
[r_c_specific_id_ss,p_c_specific_id_ss,...
    r_c_id_ss,p_c_id_ss,...
    r_p_specific_id_ss,p_p_specific_id_ss,...
    r_p_id_ss,p_p_id_ss,~,scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'data','SAvgS','inDegree',false,false,si.caseName,'In Degree');

[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (in degree and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_id_sr,p_c_specific_id_sr,r_c_id_sr,p_c_id_sr,r_p_specific_id_sr,p_p_specific_id_sr,r_p_id_sr,p_p_id_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Sp. Times','Patients: In-Sp. Times'},0.1);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (in degree and ',weightedTxt,'out sp times)'],[-0.2,0.2],p_thresh,...
    r_c_specific_id_ss,p_c_specific_id_ss,r_c_id_ss,p_c_id_ss,r_p_specific_id_ss,p_p_specific_id_ss,r_p_id_ss,p_p_id_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Sp. Times','Patients: Out-Sp. Times'},0.1,axh);

%% out degree
[r_c_specific_od_sr,p_c_specific_od_sr,...
    r_c_od_sr,p_c_od_sr,...
    r_p_specific_od_sr,p_p_specific_od_sr,...
    r_p_od_sr,p_p_od_sr,~,scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'data','SAvgR','outDegree',false,true,si.caseName,'Out Degree');
[r_c_specific_od_ss,p_c_specific_od_ss,...
    r_c_od_ss,p_c_od_ss,...
    r_p_specific_od_ss,p_p_specific_od_ss,...
    r_p_od_ss,p_p_od_ss,~,scplot] = ...
    corrcoef_datastruct(si.(spField),npm,'data','SAvgS','outDegree',false,true,si.caseName,'Out Degree');

[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (out degree and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_od_sr,p_c_specific_od_sr,r_c_od_sr,p_c_od_sr,r_p_specific_od_sr,p_p_specific_od_sr,r_p_od_sr,p_p_od_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Sp. Times','Patients: In-Sp. Times'},0.1);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fh,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (out degree and ',weightedTxt,'out sp times)'],[-0.2,0.2],p_thresh,...
    r_c_specific_od_ss,p_c_specific_od_ss,r_c_od_ss,p_c_od_ss,r_p_specific_od_ss,p_p_specific_od_ss,r_p_od_ss,p_p_od_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Sp. Times','Patients: Out-Sp. Times'},0.1,axh);