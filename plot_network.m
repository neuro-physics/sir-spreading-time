function fh = plot_network(A,aal,Gdb)
    if nargin < 3
        Gdb = [];
    end
    matlabPath = path;
    if isunix
        path(genpath('/host/scarus/local_raid/mauricio/matlab_toolbox/tools_edgebundle'),matlabPath); % matlab path has to come later because of the conflict with minmax function in debundle
    else
        path(genpath('D:\matlab_toolbox\tools_edgebundle'),matlabPath); % matlab path has to come later because of the conflict with minmax function in debundle
    end
    if (nargin < 2) || isempty(aal)
        %aal=load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
        [~,~,~,aal]=aalsurfview(zeros(90,1));
    end
    N = size(A,1);
    l = getAALLabel(N);
    %     plotBrainSurf([],[],@(x)[0.95,0.95,0.95],0.3,[],true);colormap(hot);
    if isempty(Gdb)
%         G = digraph(A);
%         x = aal.pos.(l)(:,1);
%         y = aal.pos.(l)(:,2);
%         z = aal.pos.(l)(:,3);
%         Name = cellfun(@num2str,num2cell(1:N)','UniformOutput',false); % cellstr(num2str((1:90)'))
%         G.Nodes = table(Name,x,y,z,'RowNames',Name);
%         Gdb = debundle(G);
       %plotEdges(fh,axh,r,A,colorArr,colorMode,posArgs,edgeArgs,widthMode,brainShade,brainColor,onlyAddEdgesToAxes,lightPos)
        [fh,ax,~] = plotEdges([],[],aal.pos.(l),A,hot,'continuous',{'Color','w','MarkerFaceColor','w','MarkerSize',3},{'LineWidthLim',[0.1,0.1]},'constant', [], [0.95,0.95,0.95]); % plots brain surface
        daspect([1,1,1]);
        axis(ax,'off');
    else
        plotBrainSurf([],[],[0.95,0.95,0.95],0.3,[],true);colormap(hot);
        daspect([1,1,1]);
        ax = gca;
        fh = gcf;
        ax2 = copyobj(ax,fh);
        cla(ax2);
        plotdeb(Gdb, 'w', 5, 'rloop', 1, 'ax', ax2);
        ax2.Position = ax.Position;
        ax2.XLim = ax.XLim;
        ax2.YLim = ax.YLim;
        axis(ax,'off');
        axis(ax2,'off');
    end
%     uistack(ax,'top');
    path(matlabPath);
end

function l = getAALLabel(N)
    l = ['AAL',num2str(N)];
    if N == 78
        l = [l,'remap'];
    end
end
