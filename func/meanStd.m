function [m,s] = meanStd(A,dim,omitNaN)
    if (nargin < 2) || isempty(dim)
        dim = 0;
    end
    if (nargin < 3) || isempty(omitNaN)
        omitNaN = true;
    end
    if dim == 0
        A = reshape(A,numel(A),1);
        dim = 1;
    else
        if isvector(A)
            [~,dim] = max(size(A));
        end
    end
    nanflag = 'omitnan';
    if ~omitNaN
        nanflag = 'includenan';
    end
    m = mean(A,dim,nanflag);
    s = std(A,[],dim,nanflag);
end
