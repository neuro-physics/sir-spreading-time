clearvars
close all

if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data/';
else
    dataDir = 'D:\Dropbox\p\postdoc\data\';
end
%%
aal = load(fullfile(dataDir,'AAL_data','aal_cortex_map_olf294_fix.mat'));
%r = getParcelCentroid_mex(B.Atlas.Cortex.AAL_HighRes, B.Templates.Cortex.coord, 'LR');
%%
yeo.surf = SurfStatAvSurf({ fullfile(dataDir,'yeo_comm_parcel','surf_reg_model_left_20480.obj'), fullfile(dataDir,'yeo_comm_parcel','surf_reg_model_right_20480.obj') });
yeo.data = SurfStatReadData(fullfile(dataDir,'yeo_comm_parcel','Yeo_parcellation.txt'));

%%
%r = getParcelCentroid_mex(yeo.data, yeo.surf.coord, 'LR');

disp('Grouping vertices...')

% vertexGroups = GroupVerticesKMeans(aal.surf.coord, yeo.surf.coord);
vertexGroups = GroupVerticesEucDist(aal.surf.coord, yeo.surf.coord);

aalVertexCommData = yeo.data(vertexGroups);

save('yeo_aal_corresp.mat', 'vertexGroups', 'aalVertexCommData', '-v7.3');

SurfStatView(aalVertexCommData', aal.surf)
% figure;SurfStatView(yeo.data, yeo.surf)

% k1 = find(aalVertexCommData==2);
% n1 = find(yeo.data==2);
% plot3(aal.surf.coord(1,k1), aal.surf.coord(2,k1), aal.surf.coord(3,k1),'.k')
% hold on
% plot3(yeo.surf.coord(1,n1), yeo.surf.coord(2,n1), yeo.surf.coord(3,n1),'.r')
% daspect([1,1,1])
