clearvars
close all

addpath func

np = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\net_prop_flip_Z.mat');
%si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');

[~,~,~,aal] = aalsurfview(zeros(90,1));

%spField = 'SpMatrixW';


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

bc_c = mean(matCell2Mat(np.Controls.betweenCenWei),2,'omitnan');
bc_p = mean(matCell2Mat(np.LRTLE.betweenCenWei),2,'omitnan');
tt_bc = ttest.ttest2Struct(bc_c,bc_p,'Alpha',p_thresh,'AlphaFDR',p_thresh);
[fh_bc,ax] = plotAvgVsThetaScatterPanels({{'Betweenness','Centrality'}},bc_c,bc_p,[],[],tt_bc.h,[],[],'Z-Score',{'Controls','TLE'});

cc_c = mean(matCell2Mat(np.Controls.clusterCoeffWei),2,'omitnan');
cc_p = mean(matCell2Mat(np.LRTLE.clusterCoeffWei),2,'omitnan');
tt_cc = ttest.ttest2Struct(cc_c,cc_p,'Alpha',p_thresh,'AlphaFDR',p_thresh);
[fh_cc,ax] = plotAvgVsThetaScatterPanels({{'Clustering','Coefficient'}},cc_c,cc_p,[],[],tt_cc.h,[],[],'Z-Score',{'Controls','TLE'});

[fa_z_c,fa_z_p] = zScoreToControls(np.Controls.A,np.LRTLE.A);
fa_c = mean(fa_z_c,2,'omitnan');
fa_p = mean(fa_z_p,2,'omitnan');
tt_fa = ttest.ttest2Struct(fa_c,fa_p,'Alpha',p_thresh,'AlphaFDR',p_thresh);
[fh_fa,ax] = plotAvgVsThetaScatterPanels({{'FA values'}},fa_c,fa_p,[],[],tt_fa.h,[],[],'Z-Score',{'Controls','TLE'});

if saveOutputFigures
    saveFigure([fh_fa,fh_cc,fh_bc], fullfile('corr_fig',{'group_diff_fa','group_diff_cc','group_diff_bc'}), 'tiff', true, [], 600);
end

%% betweenness centrality - plotting differences on the brain

tt_bc_per_node = ttest.ttest2Struct(matCell2Mat(np.Controls.betweenCenWei),matCell2Mat(np.LRTLE.betweenCenWei),...
                                    'Alpha',p_thresh,'AlphaFDR',p_thresh,'UseSurfStat',false,'Tail','both');
%       'tail'          A string specifying the alternative hypothesis:
%           'both'  "means are not equal" (two-tailed test)
%           'right' "mean of CONTROL is greater than mean of PATIENT" (right-tailed test)
%           'left'  "mean of CONTROL is less than mean of PATIENT" (left-tailed test)


d = tt_bc_per_node.p .* sign(mean(matCell2Mat(np.LRTLE.betweenCenWei),1));

if useFDR
    if any(tt_bc_per_node.hFDR==1)
        d(tt_bc_per_node.hFDR~=1) = 0;
    else
        disp('WARNING: no node passed FDR test for Bet. Central., but showing only those with p < p_thresh');
    end
    d(tt_bc_per_node.h~=1) = 0;
else
    disp('WARNING: not using FDR');
    d(tt_bc_per_node.h~=1) = 0;
end

cLimEffSz_max = max(d);
cLimEffSz_min = min(d);
cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);

c = insertColorForVal(0,d,0.85.*[1,1,1],@(x)flipud(wintermodCMap(x,0.5)),@(x)autumnmodCMap(x,0.6),[],cLimEffSz,numel(d));
%colorLabel = 'Weighted Betweenness Centrality';
if useFDR
    colorLabel = 'p-values, FDR corrected';
else
    colorLabel = 'p-values';
end
[fh1,ax1,cb1] = aalsurfview(d,colorLabel,c,'continuous',[],[],[],[],[],[],[],false);
cb1.Limits=[-1e-3,1e-3];
cb1.Ticks=linspace(cb1.Limits(1),cb1.Limits(2),5);
cb1.TickLabels=abs(cb1.Ticks);
annotation(fh1,'textbox',[cb1.Position(1)-0.18,cb1.Position(2)-0.028,0.18,0.09],'String','Lower in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','right');
annotation(fh1,'textbox',[sum(cb1.Position([1,3])),cb1.Position(2)-0.028,0.18,0.09],'String','Higher in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','left');
% anh=annotation(fh1,'textbox',[0.5 0.893333333333333 0.316 0.0640000000000002],'String','Weighted Betweenness Centrality',...
%     'FitBoxToText','on','EdgeColor','none','VerticalAlignment','top','HorizontalAlignment','center');

if saveOutputFigures
    saveFigure(fh1, fullfile('corr_fig','group_diff_map_bc_pval'), 'tiff', true, [], 600);
end

%% clustering coefficient - plotting differences on the brain

tt_cc_per_node = ttest.ttest2Struct(matCell2Mat(np.Controls.clusterCoeffWei),matCell2Mat(np.LRTLE.clusterCoeffWei),...
                                    'Alpha',p_thresh,'AlphaFDR',p_thresh,'UseSurfStat',false,'Tail','both');
%       'tail'          A string specifying the alternative hypothesis:
%           'both'  "means are not equal" (two-tailed test)
%           'right' "mean of CONTROL is greater than mean of PATIENT" (right-tailed test)
%           'left'  "mean of CONTROL is less than mean of PATIENT" (left-tailed test)


d = tt_cc_per_node.p .* sign(mean(matCell2Mat(np.LRTLE.clusterCoeffWei),1));
% d(abs(d)>p_thresh) = 0;
% d(abs(d)>tt_cc_per_node.pFDR) = 0;

if useFDR
    if any(tt_cc_per_node.hFDR==1)
        d(tt_cc_per_node.hFDR~=1) = 0;
    else
        disp('WARNING: no node passed FDR test for Cluster Coeff., but showing only those with p < p_thresh');
    end
    d(tt_cc_per_node.h~=1) = 0;
else
    disp('WARNING: not using FDR');
    d(tt_cc_per_node.h~=1) = 0;
end

cLimEffSz_max = max(d);
cLimEffSz_min = min(d);
cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);

c = insertColorForVal(0,d,0.85.*[1,1,1],@(x)flipud(winter(x)),@(x)autumn(x),[],cLimEffSz,numel(d));
% colorLabel = 'Weighted Clustering Coefficient';
if useFDR
    colorLabel = 'p-values, FDR corrected';
else
    colorLabel = 'p-values';
end
[fh1,ax1,cb1] = aalsurfview(d,colorLabel,c,'continuous',[],[],[],[],[],[],[],false);
cb1.Limits=[-1e-2,1e-2];
cb1.Ticks=linspace(cb1.Limits(1),cb1.Limits(2),5);
cb1.TickLabels=abs(cb1.Ticks);
annotation(fh1,'textbox',[cb1.Position(1)-0.18,cb1.Position(2)-0.028,0.18,0.09],'String','Lower in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','right');
annotation(fh1,'textbox',[sum(cb1.Position([1,3])),cb1.Position(2)-0.028,0.18,0.09],'String','Higher in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','left');

if saveOutputFigures
    saveFigure(fh1, fullfile('corr_fig','group_diff_map_cc_pval'), 'tiff', true, [], 600);
end

%% FA values - plotting differences on the brain

fa_per_node_c = squeeze(mean(reshapeLines(matCell2Mat(np.Controls.A),size(np.Controls.A{1}),'3darray'),1,'omitnan'))';
fa_per_node_p = squeeze(mean(reshapeLines(matCell2Mat(np.LRTLE.A),size(np.LRTLE.A{1}),'3darray'),1,'omitnan'))';
[fa_z_per_node_c,fa_z_per_node_p] = zScoreToControls(fa_per_node_c,fa_per_node_p,1);

tt_fa_per_node = ttest.ttest2Struct(fa_z_per_node_c,fa_z_per_node_p,'Alpha',p_thresh,'AlphaFDR',p_thresh,'UseSurfStat',false,'Tail','right');
%       'tail'          A string specifying the alternative hypothesis:
%           'both'  "means are not equal" (two-tailed test)
%           'right' "mean of CONTROL is greater than mean of PATIENT" (right-tailed test)
%           'left'  "mean of CONTROL is less than mean of PATIENT" (left-tailed test)

d = tt_fa_per_node.p .* sign(mean(fa_z_per_node_p,1));
% d(abs(d)>p_thresh) = 0;
% d(abs(d)>tt_cc_per_node.pFDR) = 0;

if useFDR
    if any(tt_fa_per_node.hFDR==1)
        d(tt_fa_per_node.hFDR~=1) = 0;
    else
        disp('WARNING: no node passed FDR test for Cluster Coeff., but showing only those with p < p_thresh');
    end
    d(tt_fa_per_node.h~=1) = 0;
else
    disp('WARNING: not using FDR');
    d(tt_fa_per_node.h~=1) = 0;
end

cLimEffSz_max = max(d);
cLimEffSz_min = min(d);
cLimEffSz = getCLim0(cLimEffSz_max,cLimEffSz_min);

c = insertColorForVal(0,d,0.85.*[1,1,1],@(x)flipud(winter(x)),@(x)autumn(x),[],cLimEffSz,numel(d));
% colorLabel = 'FA values';
if useFDR
    colorLabel = 'p-values, FDR corrected';
else
    colorLabel = 'p-values';
end
[fh1,ax1,cb1] = aalsurfview(d,colorLabel,c,'continuous',[],[],[],[],[],[],[],false);
cb1.TickLabels=abs(cb1.Ticks);
annotation(fh1,'textbox',[cb1.Position(1)-0.18,cb1.Position(2)-0.028,0.18,0.09],'String','Lower in TLE', 'FitBoxToText','off','EdgeColor','none','VerticalAlignment','bottom','HorizontalAlignment','right');

if saveOutputFigures
    saveFigure(fh1, fullfile('corr_fig','group_diff_map_fa_pval'), 'tiff', true, [], 600);
end