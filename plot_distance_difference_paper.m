clearvars
close all

addpath func

[~,~,~,aal] = aalsurfview(zeros(90,1));

[A_FA,caseName_FA] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*_FA_AAL_midres.mat');
[pInd_FA,cInd_FA] = getPatientControlInd(caseName_FA);
rtle_ind = getRTLEIndices(caseName_FA);
A_FA = flipAALMatrix_rowsPerCols(A_FA,aal,rtle_ind);

[A_FL,caseName_FL] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected_dist\TLE_*_dist_AAL_midres.mat');
[pInd_FL,cInd_FL] = getPatientControlInd(caseName_FL);
rtle_ind = getRTLEIndices(caseName_FL);
A_FL = flipAALMatrix_rowsPerCols(A_FL,aal,rtle_ind);

% z-scoring FA and FL
A_FA_z = zScoreToSubset(A_FA, cInd_FA);
A_FL_z = zScoreToSubset(A_FL, cInd_FL);

si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');

use_z_score_for_corr = true;
% use_z_score_for_corr = false;

% a fake si data structure to fool the correlation function
si_fake_for_FA.caseName = caseName_FA;
si_fake_for_FA.Data = struct('theta',0,'flipData',[]);
if use_z_score_for_corr
    si_fake_for_FA.Data.flipData.FA = A_FA_z;
else
    si_fake_for_FA.Data.flipData.FA = A_FA;
end
spField_fake = 'Data';

% a fake network properties data structure to fool the correlation function
npm_fake_for_FL = struct('caseName',[],'FL',[],'FL_node_in',[],'FL_node_out',[]);
npm_fake_for_FL.caseName = caseName_FL;
if use_z_score_for_corr
    npm_fake_for_FL.FL = A_FL_z;
else
    npm_fake_for_FL.FL = A_FL;
end
npm_fake_for_FL.ignore_zero_for_mean = true;

spField = 'SpMatrixW';

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

p_thresh = 0.05;
useFDR = true;

%% plotting average group differences

[fl_z_c,fl_z_p] = zScoreToControls(A_FL(cInd_FL),A_FL(pInd_FL));
fl_c = meandiff0(fl_z_c,2);
fl_p = meandiff0(fl_z_p,2);
tt_fl = ttest.ttest2Struct(fl_c,fl_p,'Alpha',p_thresh,'AlphaFDR',p_thresh);
[fh_fl,ax] = plotAvgVsThetaScatterPanels({{'Distance'}},fl_c,fl_p,[],[],tt_fl.h,[],[],'Z-Score',{'Controls','TLE'});

if saveOutputFigures
    saveFigure(fh_fl, fullfile('corr_fig','group_diff_dist'), 'tiff', true, [], 600);
end

%% FL-FA correlation

[r_c_specific_fl_fa,p_c_specific_fl_fa,...
    r_c_fl_fa,p_c_fl_fa,...
    r_p_specific_fl_fa,p_p_specific_fl_fa,...
    r_p_fl_fa,p_p_fl_fa,theta,in_scplot] = ...
    corrcoef_datastruct(si_fake_for_FA.(spField_fake),npm_fake_for_FL,'flipData','FA','FL',false,false,si_fake_for_FA.caseName,'FA values');

[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta','FA-Dist. corr',[0,1.1],p_thresh,...
    r_c_specific_fl_fa,p_c_specific_fl_fa,r_c_fl_fa,p_c_fl_fa,r_p_specific_fl_fa,p_p_specific_fl_fa,r_p_fl_fa,p_p_fl_fa,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Spreading Times (Z-score)','Patients: In-Spreading Times (Z-score)'},0.1,[],[-0.1,-0.4,0.01]);


thetaInd = 1;

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(thetaInd).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(thetaInd).var_patient,1),1,0.1);
[lhp,ax_p,fh_p] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_patient,in_scplot(thetaInd).sptime_patient,flipud(patient_colors),{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
[lhc,ax_c,fh_c] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_control,in_scplot(thetaInd).sptime_control,flipud(control_colors),{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
set(ax_p,'YLim',[-18.9435846075104 28.428305624128],'XLim',[-41.6861826697892 131.147540983607]);
ylabel(ax_p,'FA values (Z-score)');
xlabel(ax_p,'Distance (Z-score)');
ylabel(ax_c,'FA values (Z-score)');
xlabel(ax_c,'Distance (Z-score)');
title(ax_p,sprintf('Patients, R=%.2f, p=%g',mean(r_p_specific_fl_fa(:,thetaInd)),max(p_p_specific_fl_fa(:,thetaInd))),'FontWeight','normal');
title(ax_c,sprintf('Controls, R=%.2f, p=%g',mean(r_c_specific_fl_fa(:,thetaInd)),max(p_c_specific_fl_fa(:,thetaInd))),'FontWeight','normal');

set([ax_p,ax_c],'FontSize',14);

if saveOutputFigures
    saveFigure([fhR,fh_p,fh_c], fullfile('corr_fig',{'corr_group_diff_dist_fa','corr_dist_fa_z_tle','corr_dist_fa_z_control'}), 'tiff', true, [], 600);
end


%% calculating FL per node for plotting differences on the brain

fl_per_node_c_in = squeeze(mean(reshapeLines(matCell2Mat(A_FL(cInd_FL)),size(A_FL{1}),'3darray'),1,'omitnan'))';
fl_per_node_p_in = squeeze(mean(reshapeLines(matCell2Mat(A_FL(pInd_FL)),size(A_FL{1}),'3darray'),1,'omitnan'))';
[fl_z_per_node_c_in,fl_z_per_node_p_in] = zScoreToControls(fl_per_node_c_in,fl_per_node_p_in,1);

fl_per_node_c_out = squeeze(mean(reshapeLines(matCell2Mat(A_FL(cInd_FL)),size(A_FL{1}),'3darray'),2,'omitnan'))';
fl_per_node_p_out = squeeze(mean(reshapeLines(matCell2Mat(A_FL(pInd_FL)),size(A_FL{1}),'3darray'),2,'omitnan'))';
[fl_z_per_node_c_out,fl_z_per_node_p_out] = zScoreToControls(fl_per_node_c_out,fl_per_node_p_out,1);

npm_fake_for_FL.FL_node_in = reshapeLines([fl_per_node_p_in;fl_per_node_c_in],[1,size(fl_per_node_p_in,2)],'cell');
npm_fake_for_FL.FL_node_out = reshapeLines([fl_per_node_p_out;fl_per_node_c_out],[1,size(fl_per_node_p_out,2)],'cell');

%% FL values - plotting differences on the brain

tt_fl_per_node_in = ttest.ttest2Struct(fl_z_per_node_c_in,fl_z_per_node_p_in,'Alpha',p_thresh,'AlphaFDR',p_thresh,'UseSurfStat',false,'Tail','both');
%       'tail'          A string specifying the alternative hypothesis:
%           'both'  "means are not equal" (two-tailed test)
%           'right' "mean of CONTROL is greater than mean of PATIENT" (right-tailed test)
%           'left'  "mean of CONTROL is less than mean of PATIENT" (left-tailed test)

d = tt_fl_per_node_in.p .* sign(mean(fl_z_per_node_p_in,1));
% d(abs(d)>p_thresh) = 0;
% d(abs(d)>tt_cc_per_node.pFDR) = 0;

passedFDR = false;
if useFDR
    if any(tt_fl_per_node_in.hFDR==1)
        d(tt_fl_per_node_in.hFDR~=1) = 0;
        passedFDR = true;
    else
        fprintf('WARNING: no node passed FDR test for Distance, but showing only those with p < %g\n',p_thresh);
    end
    d(tt_fl_per_node_in.h~=1) = 0;
else
    disp('WARNING: not using FDR');
    d(tt_fl_per_node_in.h~=1) = 0;
end

cLimEffSz_max = max(d);
cLimEffSz_min = min(d);
cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);

c = insertColorForVal(0,d,0.85.*[1,1,1],@(x)flipud(winter(x)),@(x)autumn(x),[],cLimEffSz,numel(d));
% colorLabel = 'FA values';
if useFDR
    if passedFDR
        colorLabel = 'p-values, FDR corrected';
    else
        colorLabel = 'p-values (no nodes passed FDR correction, showing trends)';
    end
else
    colorLabel = 'p-values';
end
[fh1,ax1,cb1] = aalsurfview(d,colorLabel,c,'continuous',[],[],[],[],[],[],[],false);
cb1.TickLabels=abs(cb1.Ticks);
annotation(fh1,'textbox',[cb1.Position(1)-0.18,cb1.Position(2)-0.028,0.18,0.09],'String','Shorter in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','right');
annotation(fh1,'textbox',[sum(cb1.Position([1,3])),cb1.Position(2)-0.028,0.18,0.09],'String','Longer in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','left');

if saveOutputFigures
    saveFigure(fh1, fullfile('corr_fig','group_diff_map_dist_in_pval'), 'tiff', true, [], 600);
end

%%

tt_fl_per_node_out = ttest.ttest2Struct(fl_z_per_node_c_out,fl_z_per_node_p_out,'Alpha',p_thresh,'AlphaFDR',p_thresh,'UseSurfStat',false,'Tail','both');
%       'tail'          A string specifying the alternative hypothesis:
%           'both'  "means are not equal" (two-tailed test)
%           'right' "mean of CONTROL is greater than mean of PATIENT" (right-tailed test)
%           'left'  "mean of CONTROL is less than mean of PATIENT" (left-tailed test)

d = tt_fl_per_node_out.p .* sign(mean(fl_z_per_node_p_in,1));
% d(abs(d)>p_thresh) = 0;
% d(abs(d)>tt_cc_per_node.pFDR) = 0;

passedFDR = false;
if useFDR
    if any(tt_fl_per_node_out.hFDR==1)
        d(tt_fl_per_node_out.hFDR~=1) = 0;
        passedFDR = true;
    else
        fprintf('WARNING: no node passed FDR test for Fiber Length, but showing only those with p < %g\n',p_thresh);
    end
    d(tt_fl_per_node_out.h~=1) = 0;
else
    disp('WARNING: not using FDR');
    d(tt_fl_per_node_out.h~=1) = 0;
end

cLimEffSz_max = max(d);
cLimEffSz_min = min(d);
cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);

c = insertColorForVal(0,d,0.85.*[1,1,1],@(x)flipud(winter(x)),@(x)autumn(x),[],cLimEffSz,numel(d));
% colorLabel = 'FA values';
if useFDR
    if passedFDR
        colorLabel = 'p-values, FDR corrected';
    else
        colorLabel = 'p-values (no nodes passed FDR correction, showing trends)';
    end
else
    colorLabel = 'p-values';
end
[fh1,ax1,cb1] = aalsurfview(d,colorLabel,c,'continuous',[],[],[],[],[],[],[],false);
cb1.TickLabels=abs(cb1.Ticks);
annotation(fh1,'textbox',[cb1.Position(1)-0.18,cb1.Position(2)-0.028,0.18,0.09],'String','Smaller in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','right');
annotation(fh1,'textbox',[sum(cb1.Position([1,3])),cb1.Position(2)-0.028,0.18,0.09],'String','Larger in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','left');

if saveOutputFigures
    saveFigure(fh1, fullfile('corr_fig','group_diff_map_fl_out_pval'), 'tiff', true, [], 600);
end


%% spreading time with FL values

[r_c_specific_fl_sr,p_c_specific_fl_sr,...
    r_c_fl_sr,p_c_fl_sr,...
    r_p_specific_fl_sr,p_p_specific_fl_sr,...
    r_p_fl_sr,p_p_fl_sr,theta,in_scplot] = ...
    corrcoef_datastruct(si.(spField),npm_fake_for_FL,'flipData','SAvgR','FL_node_in',false,true,si.caseName,'FL values');
[r_c_specific_fl_ss,p_c_specific_fl_ss,...
    r_c_fl_ss,p_c_fl_ss,...
    r_p_specific_fl_ss,p_p_specific_fl_ss,...
    r_p_fl_ss,p_p_fl_ss,~,out_scplot] = ...
    corrcoef_datastruct(si.(spField),npm_fake_for_FL,'flipData','SAvgS','FL_node_out',false,true,si.caseName,'FL values');

[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (Distance and ',weightedTxt,'in sp times)'],[0,1.1],p_thresh,...
    r_c_specific_fl_sr,p_c_specific_fl_sr,r_c_fl_sr,p_c_fl_sr,r_p_specific_fl_sr,p_p_specific_fl_sr,r_p_fl_sr,p_p_fl_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: In-Spreading Times (Z-score)','Patients: In-Spreading Times (Z-score)'},0.1,[],[-0.1,-0.4,0.01]);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (Distance and ',weightedTxt,'out sp times)'],[-0.6,0.2],p_thresh,...
    r_c_specific_fl_ss,p_c_specific_fl_ss,r_c_fl_ss,p_c_fl_ss,r_p_specific_fl_ss,p_p_specific_fl_ss,r_p_fl_ss,p_p_fl_ss,theta,...
    '^',line_colors_Rtheta(3:4,:),{'MarkerSize',7},{'Controls: Out-Spreading Times (Z-score)','Patients: Out-Spreading Times (Z-score)'},0.1,axh,[-0.1,-0.35,0.01]);
legend(axh);
title(axh,'Distance (Z-score)','FontWeight','normal');
ylabel('Correlation coefficient (R)');
axh.XLim = [-0.0005,0.0255];
% axh.YTick = -0.5:0.1:0;

thetaInd = 4;

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(thetaInd).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(thetaInd).var_patient,1),1,0.1);
[lhp,axin_p,fhin_p] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_patient,in_scplot(thetaInd).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
[lhc,axin_c,fhin_c] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_control,in_scplot(thetaInd).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
% set(axin,'YLim',[-16.5163934426229 11.5983606557377],'XLim',[-13.0498987336211 25.3146602567903]);
xlabel(axin_p,'Distance (Z-score)');
ylabel(axin_p,'In-Spreading Times (Z-score)');
xlabel(axin_c,'Distance (Z-score)');
ylabel(axin_c,'In-Spreading Times (Z-score)');
% set([lhp(1),lhc(1)],'HandleVisibility','on');
% lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_sr(:,thetaInd)),max(p_p_specific_fl_sr(:,thetaInd)));
% lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_sr(:,thetaInd)),max(p_c_specific_fl_sr(:,thetaInd)));
% legh=legend(axin_p);
title(axin_p,sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_sr(:,thetaInd)),max(p_p_specific_fl_sr(:,thetaInd))),'FontWeight','normal','Interpreter','latex');
title(axin_c,sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_sr(:,thetaInd)),max(p_c_specific_fl_sr(:,thetaInd))),'FontWeight','normal','Interpreter','latex');

[lhp,axout_p,fhout_p] = plot_func.plot_many_cases([],out_scplot(thetaInd).var_patient,out_scplot(thetaInd).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
[lhc,axout_c,fhout_c] = plot_func.plot_many_cases([],out_scplot(thetaInd).var_control,out_scplot(thetaInd).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
% set(axout,'YLim',[-16.0245901639344 11.4344262295082],'XLim',[-13.0498987336211 25.3146602567903]);
xlabel(axout_p,'Distance (Z-score)');
ylabel(axout_p,'Out-Spreading Times (Z-score)');
xlabel(axout_c,'Distance (Z-score)');
ylabel(axout_c,'Out-Spreading Times (Z-score)');
% set([lhp(1),lhc(1)],'HandleVisibility','on');
% lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_ss(:,thetaInd)),max(p_p_specific_fl_ss(:,thetaInd)));
% lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_ss(:,thetaInd)),max(p_c_specific_fl_ss(:,thetaInd)));
% legh=legend(axout_p);
title(axout_p,sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_ss(:,thetaInd)),max(p_p_specific_fl_ss(:,thetaInd))),'FontWeight','normal','Interpreter','latex');
title(axout_c,sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_ss(:,thetaInd)),max(p_c_specific_fl_ss(:,thetaInd))),'FontWeight','normal','Interpreter','latex');

set([axh,axin_p,axin_c,axout_p,axout_c],'FontSize',14);
axh.XLabel.FontSize = 18;

if saveOutputFigures
    saveFigure([fhR,fhin_p,fhout_p,fhin_c,fhout_c], fullfile('corr_fig',{'corr_sp_dist_z','corr_sptime_in_dist_z_tle','corr_sptime_out_dist_z_tle','corr_sptime_in_dist_z_con','corr_sptime_out_dist_z_con'}), 'tiff', true, [], 600);
end

%% spreading time matrix with FL values

[r_c_specific_fl_sr,p_c_specific_fl_sr,...
    r_c_fl_sr,p_c_fl_sr,...
    r_p_specific_fl_sr,p_p_specific_fl_sr,...
    r_p_fl_sr,p_p_fl_sr,theta,in_scplot] = ...
    corrcoef_datastruct(si.(spField),npm_fake_for_FL,'flipData','SAvg','FL',false,true,si.caseName,'Distance');

[fhR,axh] = plot_func.plot_corrcoef_datastruct('\theta',['R (Distance and ',weightedTxt,'sp times)'],[0,1.1],p_thresh,...
    r_c_specific_fl_sr,p_c_specific_fl_sr,r_c_fl_sr,p_c_fl_sr,r_p_specific_fl_sr,p_p_specific_fl_sr,r_p_fl_sr,p_p_fl_sr,theta,...
    'v',line_colors_Rtheta(1:2,:),{'MarkerSize',7},{'Controls: Spreading Times (Z-score)','Patients: Spreading Times (Z-score)'},0.1,[],[-0.1,-0.4,0.01]);
    %{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Controls'},{'Marker','v','MarkerFaceColor','w','DisplayName','In Sp. Time, Patients'});
legend(axh);
title(axh,'Distance (Z-score)','FontWeight','normal');
ylabel('Correlation coefficient (R)');
axh.XLim = [-0.0005,0.0255];
% axh.YTick = -0.5:0.1:0;

thetaInd = 4;

control_colors = brightnessCMap(dot_color_base(1,:),size(in_scplot(thetaInd).var_control,1),1,0.1);
patient_colors = brightnessCMap(dot_color_base(2,:),size(in_scplot(thetaInd).var_patient,1),1,0.1);
[lhp,axin_p,fhin_p] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_patient,in_scplot(thetaInd).sptime_patient,patient_colors,{'Marker','^','MarkerSize',3,'HandleVisibility','off'});
[lhc,axin_c,fhin_c] = plot_func.plot_many_cases([],in_scplot(thetaInd).var_control,in_scplot(thetaInd).sptime_control,control_colors,{'Marker','o','MarkerSize',3,'HandleVisibility','off'});
% set(axin,'YLim',[-16.5163934426229 11.5983606557377],'XLim',[-13.0498987336211 25.3146602567903]);
xlabel(axin_p,'Distance (Z-score)');
ylabel(axin_p,'Spreading Times (Z-score)');
xlabel(axin_c,'Distance (Z-score)');
ylabel(axin_c,'Spreading Times (Z-score)');
% set([lhp(1),lhc(1)],'HandleVisibility','on');
% lhp(1).DisplayName = sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_sr(:,thetaInd)),max(p_p_specific_fl_sr(:,thetaInd)));
% lhc(1).DisplayName = sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_sr(:,thetaInd)),max(p_c_specific_fl_sr(:,thetaInd)));
% legh=legend(axin_p);
title(axin_p,sprintf('Patients, R=%.2f, p=%.3f',mean(r_p_specific_fl_sr(:,thetaInd)),max(p_p_specific_fl_sr(:,thetaInd))),'FontWeight','normal','Interpreter','latex');
title(axin_c,sprintf('Controls, R=%.2f, p=%.2f',mean(r_c_specific_fl_sr(:,thetaInd)),max(p_c_specific_fl_sr(:,thetaInd))),'FontWeight','normal','Interpreter','latex');

set([axh,axin_p,axin_c],'FontSize',14);
axh.XLabel.FontSize = 18;

if saveOutputFigures
    saveFigure([fhR,fhin_p,fhin_c], fullfile('corr_fig',{'corr_sptime_dist_z','corr_sptime_dist_z_tle','corr_sptime_dist_z_con'}), 'tiff', true, [], 600);
end