function r = getNiiParcelCoord(niiFile,p)
% load nii file
% find indices i,j,k corresponding to each non-zero element in .img of loaded file
% calculate centroid (mean) of i,j,k
% displace this coord by summing up it with .hdr.hist.originator
    coder.extrinsic('load_nii');
    if ischar(niiFile)
%         hkStruct = struct('sizeof_hdr',0, 'data_type','', 'db_name','', 'extents',0, 'session_error',0, 'regular','', 'dim_info',0);
%         coder.varsize('hkStruct(:).data_type', 'hkStruct(:).db_name', 'hkStruct(:).regular', [1,1], [1,1]);
%         dimeStruct = struct('dim',zeros(1,0),...
%                             'intent_p1',0, 'intent_p2',0, 'intent_p3',0, 'intent_code',0,...
%                             'datatype',0,'bitpix',0,'slice_start',0,...
%                             'pixdim',zeros(1,0),'vox_offset',0,'scl_slope',0,'scl_inter',0,'slice_end',0,...
%                             'slice_code',0,'xyzt_units',0,'cal_max',0,'cal_min',0,'slice_duration',0,...
%                             'toffset',0,'glmax',0,'glmin',0);
%         coder.varsize('dimeStruct(:).dim', 'dimeStruct(:).pixdim', [1,1], [1,1]);
%         histStruct = struct('descrip','', 'aux_file','', 'qform_code',0, 'sform_code',0, 'quatern_b',0, 'quatern_c',0, ...
%                             'quatern_d',0, 'qoffset_x',0, 'qoffset_y',0, 'qoffset_z',0,...
%                             'srow_x', zeros(1,0), 'srow_y', zeros(1,0), 'srow_z', zeros(1,0),...
%                             'intent_name','', 'magic','', ...
%                             'originator', zeros(1,0), 'rot_orient', zeros(1,0), 'flip_orient', zeros(1,0));
%         coder.varsize('histStruct(:).descrip', 'histStruct(:).aux_file', 'histStruct(:).intent_name', 'histStruct(:).magic', [1,1], [1,1]);
%         coder.varsize('histStruct(:).srow_x', 'histStruct(:).srow_y', 'histStruct(:).srow_z', 'histStruct(:).originator', 'histStruct(:).rot_orient', 'histStruct(:).flip_orient',[1,1],[1,1]);
%         data = struct('hdr', struct('hk', hkStruct, 'dime', dimeStruct,'hist', histStruct),...
%                       'filetype', 0,...
%                       'fileprefix', 'a',...
%                       'machine', 'a',...
%                       'img',zeros(0,0,0),...
%                       'original', struct('hdr', struct('hk', hkStruct, 'dime', dimeStruct,'hist', histStruct)));
%         coder.varsize('data.img');
        data = load_nii(niiFile);
    elseif isstruct(niiFile)
        data = niiFile;
    else
        error('getNiiParcelCoord:niiFile','incorrect input format');
    end
    if nargin < 2 || isempty(p)
        mm = myMinMax(data.img(:)');
        if floor(mm(2)) ~= mm(2)
            u = unique(data.img(:)');
            nn = min(u(u~=0));
            data.img = round(data.img ./ nn);
            mm = double(round(mm ./ nn));
        end
        p = 1:mm(2);
    end
    o = data.hdr.hist.originator(1:3);
    sc = data.hdr.dime.pixdim(2:4);
%     o = zeros(1,3);
%     sc = ones(1,3);
    indRangeX = [1,data.hdr.dime.dim(2)];
    indRangeY = [1,data.hdr.dime.dim(3)];
    indRangeZ = [1,data.hdr.dime.dim(4)];
    brainRangeX = [0,abs(data.hdr.hist.qoffset_x)];
    brainRangeY = [0,abs(data.hdr.hist.qoffset_y)];
    brainRangeZ = [0,abs(data.hdr.hist.qoffset_z)];
    r = zeros(numel(p),3);
    for i = 1:numel(p)
        [ii,jj,kk] = ind2sub(size(data.img),find(data.img == p(i)));
        r(i,:) = (mean(stretchVector(ii,jj,kk,[indRangeX;brainRangeX],[indRangeY;brainRangeY],[indRangeZ;brainRangeZ])) - o) .* sc;
        %r(i,:) = (mean([ii,jj,kk]) - o) .* sc;
    end
end

function r = stretchVector(x,y,z,xR,yR,zR)
    r = [ stretchInterval(x,xR(1,:),xR(2,:)), stretchInterval(y,yR(1,:),yR(2,:)), stretchInterval(z,zR(1,:),zR(2,:)) ];
end

function y = stretchInterval(x, xRange, yRange)
    a = (yRange(2) - yRange(1)) / (xRange(2) - xRange(1));
    y = a .* x + (yRange(1) - a * xRange(1));
end

function mm = myMinMax(x)
    mm = [Inf,-Inf];
    for i = 1:numel(x)
        if x(i) < mm(1)
            mm(1) = x(i);
        end
        if x(i) > mm(2)
            mm(2) = x(i);
        end
    end
end
