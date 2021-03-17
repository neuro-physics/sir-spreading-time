function c = calcVolumeCenter(r,w)
% calculates the center of the positions given by r and weighted by w
% r -> Nx3 list of 3d positions
% w -> Nx1 list of weights for each r
    if (nargin < 2) || isempty(w)
        w = ones(size(r,1),1);
    end
    if size(w,1) ~= size(r,1)
        error('if you provide weights, you must provide one weight for each r');
    end
    if size(r,1) == 1
        c = r(1,:);
    else
        c = sum(r.*repmat(w,1,size(r,2))) ./ sum(w);
        c(isnan(c))=0;
    end
end