function [c,sz] = getSurfaceContour(s,x_y_or_z,scaleFactor,showSurf,perpendicular_axis)
% intersects surface s with plane at fixed z
% and returns the curve c defined by such intersection
% s is a struct with fields:
%   .faces (triangles) of size N by 3
%   .vertices (points) of size N by 3
    if (nargin < 3) || isempty(scaleFactor)
        scaleFactor = 5;
    end
    if (nargin < 4) || isempty(showSurf)
        showSurf = false;
    end
    if (nargin < 5) || isempty(perpendicular_axis)
        perpendicular_axis = 'z'; % 'x','y','z'
    end
    if strcmpi(perpendicular_axis,'z')
        p = get_planes_perp_to_z(s,x_y_or_z,scaleFactor);
    elseif strcmpi(perpendicular_axis,'x')
        p = get_planes_perp_to_x(s,x_y_or_z,scaleFactor);
    elseif strcmpi(perpendicular_axis,'y')
        p = get_planes_perp_to_y(s,x_y_or_z,scaleFactor);
    else
        error('this axis is not implemented');
    end
    [c, sz] = SurfaceIntersection(s, p);
    if showSurf
        figure;
        ax = axes;
        trisurf(s.faces,s.vertices(:,1),s.vertices(:,2),s.vertices(:,3),'FaceAlpha', 0.5, 'FaceColor', 'm', 'EdgeColor', 'none')
        hold(ax,'on')
        trisurf(p.faces,p.vertices(:,1),p.vertices(:,2),p.vertices(:,3),'FaceAlpha', 0.5, 'FaceColor', 'b', 'EdgeColor', 'none')
        hold(ax,'off')
    end
end

function p = get_planes_perp_to_x(s,x,scaleFactor)
    mmY = minmax(s.vertices(:,2)').*scaleFactor;
    mmZ = minmax(s.vertices(:,3)').*scaleFactor;
    p = struct('vertices',zeros(0,3),'faces',zeros(0,3));
    for i = 1:numel(x)
        p = addSquare_x(p,x(i),mmY,mmZ);
    end
end

function p = addSquare_x(p,x,y,z)
% y->[y1,y2]
% z->[z1,z2]
% returns the square corresponding to vertices: y1,z1; y2,z1; y2,z2; y1,z2;
    n = size(p.vertices,1);
    p.vertices(n+(1:4),:) = [x,y(1),z(1);   x,y(2),z(1);   x,y(2),z(2);   x,y(1),z(2)];
    p.faces(end+(1:2),:) = [ n+1,n+2,n+3; n+1,n+3,n+4 ];
end

function p = get_planes_perp_to_y(s,y,scaleFactor)
    mmX = minmax(s.vertices(:,1)').*scaleFactor;
    mmZ = minmax(s.vertices(:,3)').*scaleFactor;
    p = struct('vertices',zeros(0,3),'faces',zeros(0,3));
    for i = 1:numel(y)
        p = addSquare_y(p,mmX,y(i),mmZ);
    end
end

function p = addSquare_y(p,x,y,z)
% x->[x1,x2]
% z->[z1,z2]
% returns the square corresponding to vertices: x1,z1; x2,z1; x2,z2; x1,z2;
    n = size(p.vertices,1);
    p.vertices(n+(1:4),:) = [x(1),y,z(1);   x(2),y,z(1);   x(2),y,z(2);   x(1),y,z(2)];
    p.faces(end+(1:2),:) = [ n+1,n+2,n+3; n+1,n+3,n+4 ];
end

function p = get_planes_perp_to_z(s,z,scaleFactor)
    mmX = minmax(s.vertices(:,1)').*scaleFactor;
    mmY = minmax(s.vertices(:,2)').*scaleFactor;
    p = struct('vertices',zeros(0,3),'faces',zeros(0,3));
    for i = 1:numel(z)
        p = addSquare_z(p,mmX,mmY,z(i));
    end
end

function p = addSquare_z(p,x,y,z)
% x->[x1,x2]
% y->[y1,y2]
% returns the square corresponding to vertices: x1,y1; x2,y1; x2,y2; x1,y2;
    n = size(p.vertices,1);
    p.vertices(n+(1:4),:) = [x(1),y(1),z;   x(2),y(1),z;   x(2),y(2),z;   x(1),y(2),z];
    p.faces(end+(1:2),:) = [ n+1,n+2,n+3; n+1,n+3,n+4 ];
end