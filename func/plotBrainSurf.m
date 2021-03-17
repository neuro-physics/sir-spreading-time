function [fh, axh, lh] = plotBrainSurf(fh, axh, brainColor, alphaValue, lightPos, shiftZCoord, contourLevel, contourArgs)
    if isempty(fh) || isempty(fh)
        fh = figure;
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    end
    if (nargin < 3) || isempty(brainColor)
        brainColor = [0.95,0.95,0.95];
    end
    if (nargin < 4) || isempty(alphaValue)
        alphaValue = 0.5;
    end
    if (nargin < 5) || isempty(lightPos)
        lightPos = [ -1,-1,-1;...
                     -1,1,0.5;...
                     1,-1,0.5 ];
    end
    if (nargin < 6) || isempty(shiftZCoord)
        shiftZCoord = false;
    end
    if (nargin < 7) || isempty(contourLevel)
        contourLevel = [];
    end
    if (nargin < 8) || isempty(contourArgs)
        contourArgs = {};
    end
    [~,~,~,aal,~]=aalsurfview(zeros(90,1));
    if isempty(contourLevel)
        [fh,axh,lh] = plotBrainSurf_internal(fh, axh, ones(size(aal.map.AAL90)), aal.surf, brainColor, alphaValue, lightPos, shiftZCoord);
    else
        brain = struct('vertices',aal.surf.coord','faces',aal.surf.tri);
        [~,sz] = getSurfaceContour(brain,contourLevel);
        lh = trisurf(sz.faces,sz.vertices(:,1),sz.vertices(:,2),sz.vertices(:,3),'EdgeAlpha', alphaValue, 'FaceAlpha', alphaValue, 'FaceColor', brainColor, contourArgs{:});
    end
end

function [fh,axh,lh] = plotBrainSurf_internal(fh, axh, data, surf, brainColor, alphaValue, lightPos, shiftZCoord)
%BoSurfStatViewData is a simple viewer for surface data.
% 
% Usage: [a,cb]=BoSurfStatViewData(data, surf [,title [,background]]);
% 
% data        = 1 x v vector of data, v=#vertices
% surf.coord  = 3 x v matrix of coordinates.
% surf.tri    = t x 3 matrix of triangle indices, 1-based, t=#triangles.
%
% a  = vector of handles to the axes, left to right, top to bottom.

    if shiftZCoord
        d = max(minmax(surf.coord(3,:)));
        surf.coord(3,:) = surf.coord(3,:) - (d + 1);
    end

    v = numel(data);
    vl = 1:(v/2);
    vr = vl + v / 2;
    t = size(surf.tri,1);
    tl = 1:(t/2);
    tr = tl + t / 2;
    clim = [ min(data), max(data) ];
    if clim(1)==clim(2)
        clim = clim(1) + [-1 0];
    end
%     colormap(cMap(256));

    % [2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx]
    %a(1)=axes('position',[0.1 0.3 w h]);
    axes(axh);
    hold(axh, 'on');
    hl = trisurf(surf.tri(tl,:),surf.coord(1,vl),surf.coord(2,vl),surf.coord(3,vl),double(data(vl)),'EdgeColor','none');
    hr = trisurf(surf.tri(tr,:)-v/2,surf.coord(1,vr),surf.coord(2,vr),surf.coord(3,vr),double(data(vr)),'EdgeColor','none');
    hold(axh, 'off');
    lighting gouraud; material dull; shading interp;
    axh.CLim = clim;
    nL = size(lightPos,1);
    lh = gobjects(1,nL);
    for i = 1:nL
        lh(i) = light('Position',lightPos(i,:));
    end
    alpha(hl, alphaValue);
    alpha(hr, alphaValue);
    hl.FaceColor = brainColor;
    hr.FaceColor = brainColor;
end
