function [z_c,z_p] = zScoreToControls(x_c,x_p,dim)
    if (nargin < 3)||isempty(dim)
        dim = 1; % dimension along which the control average for each variable should be taken
                 % dim==1 means that each row in x_c is an observation for the variable x_c(:,j)
    end
    if iscell(x_c)
        x_c = matCell2Mat(x_c);
    end
    if iscell(x_p)
        x_p = matCell2Mat(x_p);
    end
    if isvector(x_c) && isvector(x_p)
        m = mean(x_c(:),'omitnan');
        s = std(x_c(:),'omitnan');
        s(s==0)=1;
        z_c = (x_c - m) ./ s;
        z_p = (x_p - m) ./ s;
    elseif ismatrix(x_c) && ismatrix(x_p)
        if dim == 1
            sz_c = [size(x_c,dim),1];
            sz_p = [size(x_p,dim),1];
        elseif dim == 2
            sz_c = [1,size(x_c,dim)];
            sz_p = [1,size(x_p,dim)];
        else
            error('only defined for bidimensional matrices')
        end
        m = mean(x_c,dim,'omitnan');
        s = std(x_c,[],dim,'omitnan');
        s(s==0)=1;
        z_c = (x_c - repmat(m,sz_c)) ./ repmat(s,sz_c);
        z_p = (x_p - repmat(m,sz_p)) ./ repmat(s,sz_p);
    else
        error('both x_c and x_p must be either vectors or matrices, or cell arrays')
    end
    z_c(isnan(z_c)) = 0;
    z_p(isnan(z_p)) = 0;
end