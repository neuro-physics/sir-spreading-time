function [fh,axh,cb,sh]=BoSurfStatViewData(data,surf,fp,titleTxt,cMap,fhp,axR0,alphaData,colorMode)

%BoSurfStatViewData is a simple viewer for surface data.
% 
% Usage: [a,cb]=BoSurfStatViewData(data, surf [,title [,background]]);
% 
% data        = 1 x v vector of data, v=#vertices
% surf.coord  = 3 x v matrix of coordinates.
% surf.tri    = t x 3 matrix of triangle indices, 1-based, t=#triangles.
% titleTxt    = any string, data name by default.
% fp -> figure properties struct from fp = getDefaultFigureProperties();
%
% a  = vector of handles to the axes, left to right, top to bottom. 
% cb = handle to the colorbar.

if nargin < 4
    titleTxt=inputname(1);
end
if nargin < 3 || isempty(fp)
    fp = getDefaultFigureProperties();
end
if nargin < 5 || isempty(cMap)
    cMap = @hsv;
end
if (nargin < 6)
    fhp = [];
end
if (nargin < 7) || isempty(axR0)
    axR0 = [0,fp.bMargin];
end
if (nargin < 8) || isempty(alphaData)
    alphaData = ones(size(data));
end
if (nargin < 9) || isempty(colorMode)
    colorMode = 'discrete'; % discrete or continuous; discrete -> direct; continuous -> scaled
end

figResize = 0;
if isempty(fhp)
    fh = figure('Position', [fp.x0Fig, fp.y0Fig, fp.wFig, fp.hFig]);
else
    fh = fhp;
    if (fp.hAx + axR0(2)) > 1
        fh = resizeFig(fh, [fh.Position(3),fh.Position(4)*1.5]);
        axR0(2) = axR0(2) / 2 - fp.bMargin*0.7;
        figResize = 1;
    end
end

nVertex=length(data);
vl=1:(nVertex/2);
vr=vl+nVertex/2;
t=size(surf.tri,1);
tl=1:(t/2);
tr=tl+t/2;
clim=[min(data),max(data)];
if clim(1)==clim(2)
    clim=clim(1)+[-1 0];
end

alphaPropL = {};
alphaPropR = {};
if ~all(alphaData==1)
    alphaPropL = { 'AlphaDataMapping', 'scaled', 'FaceAlpha', 'flat', 'FaceVertexAlphaData', alphaData(vl) };
    alphaPropR = { 'AlphaDataMapping', 'scaled', 'FaceAlpha', 'flat', 'FaceVertexAlphaData', alphaData(vr) };
    alphamap(fh,unique(alphaData));
end

%clf;
colormap(cMap(256));

sh = gobjects(1,4);

h=0.25;
w=0.20;

% [2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx]
%a(1)=axes('position',[0.1 0.3 w h]);
axPos = [axR0(1),axR0(2),2*(fp.wAx+fp.lMargin)/4,fp.hAx];
axh(1)=axes('position', axPos);
sh(1) = trisurf(surf.tri(tl,:),surf.coord(1,vl),surf.coord(2,vl),surf.coord(3,vl),...
    double(data(vl)),'EdgeColor','none', alphaPropL{:});
view(-90,0); 
daspect([1 1 1]); axis tight; camlight; axis vis3d off;
lighting phong; material dull; shading interp;
%xlabel('x');ylabel('y');zlabel('z');

%a(2)=axes('position',[0.1+w 0.3 w h]);
axh(2)=axes('position',[axPos(1)+axPos(3),axPos(2),axPos(3),axPos(4)]);
sh(2) = trisurf(surf.tri(tl,:),surf.coord(1,vl),surf.coord(2,vl),surf.coord(3,vl),...
    double(data(vl)),'EdgeColor','none', alphaPropL{:});
view(90,0); 
daspect([1 1 1]); axis tight; camlight; axis vis3d off;
lighting phong; material dull; shading interp;
%xlabel('x');ylabel('y');zlabel('z');

%a(3)=axes('position',[0.1+2*w 0.3 w h]);
axh(3)=axes('position',[axPos(1)+2*axPos(3),axPos(2),axPos(3),axPos(4)]);
sh(3) = trisurf(surf.tri(tr,:)-nVertex/2,surf.coord(1,vr),surf.coord(2,vr),surf.coord(3,vr),...
    double(data(vr)),'EdgeColor','none', alphaPropR{:});
view(-90,0); 
daspect([1 1 1]); axis tight; camlight; axis vis3d off;
lighting phong; material dull; shading interp;
%xlabel('x');ylabel('y');zlabel('z');

%a(4)=axes('position',[0.1+3*w 0.3 w h]);
axh(4)=axes('position',[axPos(1)+3*axPos(3),axPos(2),axPos(3),axPos(4)]);
sh(4) = trisurf(surf.tri(tr,:)-nVertex/2,surf.coord(1,vr),surf.coord(2,vr),surf.coord(3,vr),...
    double(data(vr)),'EdgeColor','none', alphaPropR{:});
view(90,0); 
daspect([1 1 1]); axis tight; camlight; axis vis3d off;
lighting phong; material dull; shading interp;
%xlabel('x');ylabel('y');zlabel('z');

if strcmpi(colorMode,'discrete')
    cMode = 'direct';
else
    cMode = 'scaled';
end

for i=1:length(axh)
    set(axh(i),'CLim',clim);
    set(axh(i),'Tag',['SurfStatView ' num2str(i) ]);
    set(sh,'CDataMapping',cMode);
end


cb=colorbar('location','South');
set(cb,'TickDirection','out','Position',[0.35,(axR0(2)+1.25*fp.bMargin*figResize), 0.3, (0.03*fp.hFig/fh.Position(4))],'AxisLocation','out');
cb.Title.String = titleTxt;
% set(h,'String',titleTxt,'Interpreter', 'latex');

% cb=[];

%whitebg(gcf,background);
%set(gcf,'Color',background,'InvertHardcopy','off');

%dcm_obj=datacursormode(gcf);
%set(dcm_obj,'UpdateFcn',@SurfStatDataCursor,'DisplayStyle','window');
end


function s = getDefaultFigureProperties()
    s.pLines = {'--'};
    s.pSymbols = [ 'o', '^', 'v', 's', '>', '<', 'p', 'h', 'x', '+', '*' ];
    s.pColors = [ [112,179,250;... % azul
                   210,45,45;... % vermelho
                   229,173,68;... % laranja
                   26,92,186;... % azul escuro
                   186,26,26;... % vermelho escuro
                   186,87,26;... % laranja escuro (marrom)
                   99,199,113;... % verde
                   194,129,201;... % roxo
                   210,217,78]./255;... % amarelo
                   lines(7) ];

    s.pPointSize = 4;
    s.pPointFaceColor = 'w';
    s.pLineColor = 'k';
    s.pLineWidth = 1;

    s.pErrSymbol = '';
    s.pErrLineSpec = '-';
    s.pErrLineWidth = 0.5;
    s.pErrLineColor = 'auto';

    s.wFig = 800;
    s.hFig = 300;
    ss = get(0, 'ScreenSize');
    mp = get(0, 'MonitorPositions');
    if size(mp,1) == 2
        ss = mp(2,:);
    end
    s.x0Fig = ss(1)+randi(floor([100,(ss(3)-s.wFig-100)]), 1, 1);
    s.y0Fig = ss(2)+randi(floor([100,(ss(4)-s.hFig-100)]), 1, 1);
    s.margin = 0.15;
    s.rtMarginPer = 0.2;
    s.hwRatio = s.hFig/s.wFig;
    s.lMargin = s.margin*s.hwRatio;
    s.bMargin = s.margin;
    s.hAx = 1 - s.bMargin - s.rtMarginPer*s.bMargin;
    s.wAx = (1 - 2*s.lMargin) / 2 - s.rtMarginPer*s.lMargin*s.hwRatio;
end
