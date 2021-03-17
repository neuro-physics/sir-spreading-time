addpath func

load('D:\Dropbox\p\postdoc\data\sirs\selected\N306\si_data_w.mat');
[~,~,~,aal]=aalsurfview(zeros(90,1));

s=[SpMatrixW.data];

thetaInd = 4;
N = 306;

% preparing data matrices
in_S = matCell2Mat(s(thetaInd).SAvgR);
out_S = matCell2Mat(s(thetaInd).SAvgS);

% getting control indices
[~,cInd] = getPatientControlInd(caseName);

% getting L R indices
[~,lInd,~] = sortAALNodes('lr',[],[],aal.labels.(['AAL',num2str(N)]));
lInd = find(lInd);
rInd = getContraLateralLabel(aal.surf.coord, ['AAL',num2str(N)], lInd, aal);

%%

% calculating t-test between left and right
tt_in=ttest.ttest2Struct(in_S(cInd,lInd),in_S(cInd,rInd));
tt_out=ttest.ttest2Struct(out_S(cInd,lInd),out_S(cInd,rInd));

% plotting differences for in sp time
s = zeros(1,306);
s(lInd(tt_in.hFDR>0)) = 1;
s(rInd(tt_out.hFDR>0)) = 2;
[fh,axh,cb] = aalsurfview(s,'IN (red) and OUT (blue) sp. time significant L/R differences in Controls',[1,1,1;1,0,0;0,0,1]);
cb.Ticks = [0,1,2];
cb.TickLabels = {'No L/R diff','IN L/R diff','OUT L/R diff'};
annotation(fh,'textbox',[0.109867924528302 0.80245283018868 0.318245283018868 0.0935849056603777],'String','IN sp. time L/R difference in Controls','LineStyle','none','FontWeight','bold','FitBoxToText','off');
annotation(fh,'textbox',[0.591047169811321 0.799308176100631 0.341971698113207 0.0935849056603777],'String','OUT sp. time L/R difference in Controls','LineStyle','none','FontWeight','bold','FitBoxToText','off');

%%

saveFigure(fh, 'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2019-08-27_submission\inout_LR_diff_controls', 'tiff', false, {'Renderer','opengl'}, 600)
saveFigure(fh, 'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2019-08-27_submission\inout_LR_diff_controls', 'png', false, {'Renderer','opengl'})
