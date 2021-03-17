function [a,k] = replaceLinesByFunc(v,ind,dim,func)
% replaces v(ind) by func(v(ind)), where func(v(ind)) is a scalar
% if v is a matrix, then dim==1 selects ind from lines; dim==2 selects ind from columns
% k is the vector index representing the positions of v in a; NaN is put for the line or column of a where func(v(ind)) was added
    if isempty(ind)
        a = v;
        k = [];
        return
    end
    if (nargin < 3) || isempty(dim)
        dim = find(size(v)~=1,1,'first');
    end
    if (nargin < 4) || isempty(func)
        func = @(x)mean(x,dim,'omitnan');
    end
    fixedInd = setdiff(1:size(v,dim),ind);
    a = zeros(size(v)-(numel(ind)-1).*(dim == 1:(numel(size(v)))));
    n = size(v,dim) - numel(ind);
    a = assignVal(a,getVal(v,fixedInd,dim),1:n,dim);
    a = assignVal(a,func(getVal(v,ind,dim)),size(a,dim),dim);
    k = [fixedInd,NaN];
end

function a = getVal(v,k,dim)
    if dim == 1
        a = v(k,:);
    elseif dim == 2
        a = v(:,k);
    else
        error('dim not supported')
    end
end

function a = assignVal(a,v,k,dim)
    if dim == 1
        a(k,:) = v;
    elseif dim == 2
        a(:,k) = v;
    else
        error('dim not supported')
    end
end