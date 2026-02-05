function plot_network_debundle


clearvars
close all


[A,cn] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*FA*.mat',[],{'307_2'});
[~,~,~,aal]=aalsurfview(zeros(90,1));


nColors = max(cellfun(@(x)numel(x(x~=0)),A));
Av = reshape(cell2mat(A),1,[]);
cLim = minmax(Av(Av~=0));


[~,k,~] = intersect(cn,{'307_2'});
AA=A{k};

%%

brain_surf = struct('vertices',aal.surf.coord','faces',aal.surf.tri);
x_minmax = minmax(brain_surf.vertices(:,1)');
y_minmax = minmax(brain_surf.vertices(:,2)');
z_minmax = minmax(brain_surf.vertices(:,3)');

cMap = [0.9.*ones(1,3);parula(nColors)];


% plot_plane = 'xy';
% plot_plane = 'xz';
plot_plane = 'yz';


save_fig   = true;
fig_format = 'png';


[Gdb, contour_levels,perp_contour_axis,axis_view_args]=load_debundle_plot_data(plot_plane);

node_alpha = 0.2;
edge_alpha = 0.5;
contour_alpha = 0.5;
%contour_levels = [];%[] 17.1258 34.2515  51.3773  68.5030


%plotEdges(fh,axh,r,A,colorArr,colorMode,posArgs,edgeArgs,widthMode,brainShade,brainColor,onlyAddEdgesToAxes,lightPos,Gdb,contourLevel,contourArgs,perpendicular_axis_contour)
[fh1, axh1, ~] = plotEdges([],[],aal.pos.AAL306,AA,cMap,'continuous',...
    {'MarkerSize',3,'Color',[0,0,0,node_alpha],'MarkerFaceColor',[1,1,1],'LineWidth',0.1},...
    {'LineWidth',0.1,'EdgeAlpha',edge_alpha},...
    'constant',contour_alpha,[],[],[],Gdb,contour_levels,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)},perp_contour_axis);
view(axh1,axis_view_args{:});
daspect(axh1,[1,1,1]);
axis(axh1,'off');

if save_fig
    saveFigure(fh1,sprintf('network_debundle/%s_307_2_netdeb',plot_plane),fig_format,false,[],300)
end

%%

cMap = [0.9.*ones(1,3);parula(nColors)];


plot_plane = 'xy';
% plot_plane = 'xz';
% plot_plane = 'yz';


save_fig   = true;
fig_format = 'png';


[Gdb, contour_levels,perp_contour_axis,axis_view_args]=load_debundle_plot_data(plot_plane);

node_alpha = 0.2;
edge_alpha = 0.0;
contour_alpha = 1;
contour_levels = [];


%plotEdges(fh,axh,r,A,colorArr,colorMode,posArgs,edgeArgs,widthMode,brainShade,brainColor,onlyAddEdgesToAxes,lightPos,Gdb,contourLevel,contourArgs,perpendicular_axis_contour)
[fh1, axh1, ~] = plotEdges([],[],aal.pos.AAL306,AA,cMap,'continuous',...
    {'Marker','none','MarkerSize',3,'Color',[0,0,0,node_alpha],'MarkerFaceColor',[1,1,1],'LineWidth',0.1},...
    {'LineWidth',0.1,'EdgeAlpha',edge_alpha},...
    'constant',contour_alpha,[],[],[],Gdb,contour_levels,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)},perp_contour_axis);
view(axh1,axis_view_args{:});
daspect(axh1,[1,1,1]);
axis(axh1,'off');

if save_fig
    saveFigure(fh1,sprintf('network_debundle/brain_%s',plot_plane),fig_format,false,{'Color','m','InvertHardCopy','off'},300)
end



end

function [Gdb, contour_levels,perp_contour_axis,axis_view_args]=load_debundle_plot_data(plot_plane)
    if strcmpi(plot_plane,'xy')
        Gdb               = import_edge_debundle_json('network_debundle\TLE_307_2_edges_xy.debundle-json');
        contour_levels    = 0;
        perp_contour_axis = 'z';
        axis_view_args    = {0,90};
    elseif strcmpi(plot_plane,'yz')
        Gdb               = import_edge_debundle_json('network_debundle\TLE_307_2_edges_yz.debundle-json');
        contour_levels    = 10; % [ 20, 40 ]
        perp_contour_axis = 'x';
        axis_view_args    = {90,0};
    elseif strcmpi(plot_plane,'xz')
        Gdb               = import_edge_debundle_json('network_debundle\TLE_307_2_edges_xz.debundle-json');
        contour_levels    = 0;
        perp_contour_axis = 'y';
        axis_view_args    = {180,0};
    end
end