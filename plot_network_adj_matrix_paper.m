clearvars
close all

A = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*FA*.mat',[],{'307_2','0362_1'});
nColors = max(cellfun(@(x)numel(x(x~=0)),A));
Av = reshape(cell2mat(A),1,[]);
cLim = minmax(Av(Av~=0));
cmapFunc = [0.9.*ones(1,3);parula_red(nColors)];

[fh1,~,cbh1]    = plot_stacked_adj_matrices(306,4,0.005,0.32,'func',0.75,    {'307_2','301_1','306_1','304_1'},...
                                            cmapFunc,[],cLim,[]);
[fh2,cMap,cbh2] = plot_stacked_adj_matrices(306,4,0.005,0.32,'func',0.75,{'0362_1','0364_1','0369_1','0370_1'},...
                                            cmapFunc,[],cLim,[]);
cbh1.Position = [0.1225 0.2199 0.0197 0.1933];
cbh2.Position = [0.1225 0.2199 0.0197 0.1933];
cbh1.Label.String = 'FA values';
cbh2.Label.String = 'FA values';

drawnow
%%

% fh1 = cropFigure(fh1,10,true);
% fh2 = cropFigure(fh2,10,true);

saveFigure([fh1,fh2],...
    {'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\adjmat_controls',...
     'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\adjmat_patients'}, 'tiff', false, {}, 600);
saveFigure([fh1,fh2],...
    {'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01\adjmat_controls',...
     'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01\adjmat_patients'}, 'tiff', true, {}, 600);


%%

[A,cn] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*FA*.mat');
[pInd,cInd] = getPatientControlInd(cn);

[P_pat,fa_pat,Perr_pat] = calcMeanFADistribution(A(pInd),30);
[P_con,fa_con,Perr_con] = calcMeanFADistribution(A(cInd),30);

% A_pat = reshape(cell2mat(A(pInd)),1,[]);
% A_con = reshape(cell2mat(A(cInd)),1,[]);
m_pat = sum(P_pat.*fa_pat); %mean(A_pat(A_pat~=0));
m_con = sum(P_con.*fa_con);%mean(A_con(A_con~=0));

fp = getDefaultFigureProperties();
pColor = [fp.pColors(14,:);fp.pColors(13,:)];
fh=figure;
errorbar(fa_con,P_con,Perr_con,'-o','Color',pColor(1,:),'MarkerFaceColor','w','MarkerSize',3)
ax = gca;
hold(ax,'on');
errorbar(fa_pat,P_pat,Perr_pat,'-^','Color',pColor(2,:),'MarkerFaceColor','w','MarkerSize',3);
plotVerticalLines(ax,m_con,'HandleVisibility','off','Color', pColor(1,:),'LineWidth',2,'LineStyle','--');
plotVerticalLines(ax,m_pat,'HandleVisibility','off','Color', pColor(2,:),'LineWidth',2,'LineStyle','--');
% labelpoint([m_con,ax.YLim(2)],'mean of Controls','.',{'VerticalAlignment','top','HorizontalAlignment','left','Color',pColor(1,:)},[],ax);
% labelpoint([m_pat,ax.YLim(2)],'mean of Patients','.',{'VerticalAlignment','top','HorizontalAlignment','right','Color',pColor(2,:)},[],ax);
xlabel('FA values');
ylabel('P(FA)');
legend({'Controls','Patients'},'Position',[0.3999 0.2127 0.1556 0.0711],'Box','off')
ax.Position = [0.1300 0.1100 0.4211 0.1759];
%fh = cropFigure(fh,10,true);
saveFigure(fh,'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01\fa_distribution', 'tiff', true, {}, 600);


%%

[A,cn] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*FA*.mat',[],{'307_2','0362_1'});
[~,~,~,aal]=aalsurfview(zeros(90,1));

Gdb = import_edge_debundle_json('network_debundle\TLE_307_2_edges_xy.debundle-json');
[~,k,~] = intersect(cn,{'307_2'});
AA=A{k};
% n = struct2table(Gdb.nodes);
% r = [n.x,n.y,zeros(size(n.x))];
% cMap = hot(numel(find(cellfun(@isempty,Gdb.edges))))
[fh1, axh1, ~] = plotEdges([],[],aal.pos.AAL306,AA,cMap,'continuous',...
    {'MarkerSize',3,'Color','k','MarkerFaceColor','k'},...
    {'LineWidth',0.1,'EdgeAlpha',0.6},...
    'constant',1,[],[],[],Gdb,0,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)});
%     'constant',[],[],[],[],Gdb,[0,20,40],{'LineWidth',2,'EdgeColor','k'});
view(axh1,2);
daspect(axh1,[1,1,1]);
axis(axh1,'off');

Gdb = import_edge_debundle_json('network_debundle\TLE_0362_1_edges_xy.debundle-json');
[~,k,~] = intersect(cn,{'0362_1'});
AA=A{k};
% n = struct2table(Gdb.nodes);
% r = [n.x,n.y,zeros(size(n.x))];
[fh2, axh2, ~] = plotEdges([],[],aal.pos.AAL306,AA,cMap,'continuous',...
    {'MarkerSize',3,'Color','k','MarkerFaceColor','k'},...
    {'LineWidth',0.1,'EdgeAlpha',0.6},...
    'constant',1,[],[],[],Gdb,0,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)});
%     'constant',[],[],[],[],Gdb,[0,20,40],{'LineWidth',2,'EdgeColor','k'});
view(axh2,2);
daspect(axh2,[1,1,1]);
axis(axh2,'off');

%%
fh1 = cropFigure(fh1,10,true);
fh2 = cropFigure(fh2,10,true);
saveFigure([fh1,fh2],...
    {'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\adjmat_controls_brain',...
    'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\adjmat_patients_brain'}, 'tiff', false, {}, 600);
saveFigure([fh1,fh2],...
    {'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\figs_weiSpTime_spTT_fdr\adjmat_controls_brain',...
     'D:\Dropbox\p\postdoc\data\sirs\selected\figs\N306\figs_weiSpTime_spTT_fdr\adjmat_patients_brain'}, 'tiff', false, {}, 600);
saveFigure([fh1,fh2],...
    {'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01\adjmat_controls_brain',...
     'D:\Dropbox\p\postdoc\artigos\spreading_dynamics\figs_2020-04_submission_2\fig01\adjmat_patients_brain'}, 'tiff', false, {}, 600);
%% generate data for edge debundle

disp('saving network and graph features for edge debundling in fdeb linux cpp program...')

disp('writing ... network_debundle\aal_nodes_xy_position.csv')
dlmwrite(fullfile('network_debundle','aal_nodes_xy_position.csv'), [(1:size(aal.pos.AAL306,1))',aal.pos.AAL306(:,1:2)],' ')
disp('writing ... network_debundle\aal_nodes_yz_position.csv')
dlmwrite(fullfile('network_debundle','aal_nodes_yz_position.csv'), [(1:size(aal.pos.AAL306,1))',aal.pos.AAL306(:,2:3)],' ')
disp('writing ... network_debundle\aal_nodes_xz_position.csv')
dlmwrite(fullfile('network_debundle','aal_nodes_xz_position.csv'), [(1:size(aal.pos.AAL306,1))',aal.pos.AAL306(:,[1,3])],' ')

[~,k,~] = intersect(cn,{'307_2'});
[j,i] = find(triu(A{k},1));
disp('writing ... network_debundle\TLE_307_2_edges.csv')
dlmwrite(fullfile('network_debundle','TLE_307_2_edges.csv'), [i,j], ' ');

[~,k,~] = intersect(cn,{'0362_1'});
[j,i] = find(triu(A{k},1));
disp('writing ... network_debundle\TLE_0362_1_edges.csv')
dlmwrite(fullfile('network_debundle','TLE_0362_1_edges.csv'), [i,j], ' ');