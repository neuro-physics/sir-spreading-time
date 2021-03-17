function r = calcNiiParcelPosition(img)
    u = unique(img(:));
    if u(1) == 0
        u(1) = [];
    end
    r = zeros(numel(u),3);
    for i = 1:numel(u)
        target = img == u(i);
        [voxel_x,voxel_y,voxel_z] = ind2sub(size(target),find(target));
        r(i,:) = mean([voxel_x,voxel_y,voxel_z],1);
    end
end