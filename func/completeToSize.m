function v = completeToSize(v,sz)
    if isempty(v)
        return;
    end
    m = max(numel(size(v)),numel(sz));
    if all([size(v),ones(1,m-numel(size(v)))] == [sz,ones(1,m-numel(sz))])
        return;
    end
    for i=1:numel(sz)
        v = repToComp(v,sz(i),i);
    end
end

function x = repToComp(x,N,dim)
    n = size(x,dim);
    mm = N/n;
    m = ceil(mm);
    x0 = x;
    for i = 2:m
        x = cat(dim,x,x0);
    end
    if floor(mm) ~= mm
        if dim == 1
            x = x(1:N,:,:);
        elseif dim == 2
            x = x(:,1:N,:);
        elseif dim == 3
            x = x(:,:,1:N);
        else
            s = size(x);
            c = cellfun(@(r)1:r,num2cell(s),'UniformOutput',false);
            c{dim} = 1:N;
            [~,~,~,c] = mymeshgrid(c{:});
            p = 1:numel(c); p(1) = 2; p(2) = 1;
            c = cellfun(@(r)permute(r,p),c,'UniformOutput',false);
            k = sub2ind(size(x),c{:});
            x = x(k);
        end 
        return;
    end
%     m = max(numel(sz),numel(size(v)));
%     s = [size(v),ones(1,m-numel(size(v)))];
%     sz = [sz,ones(1,m-numel(sz))];
%     v = repmat(v,sz);
%     %abs(sz - s + 1)
%     %v = repmat(v,abs(sz-s+1));
end
