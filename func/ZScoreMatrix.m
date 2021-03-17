function Z = ZScoreMatrix(A,dim)
    if (nargin < 2)
        dim = 0;
    end
    if iscell(A)
        Z = cell(1,numel(A));
        for i = 1:numel(A)
            Z{i} = calcZScore(A{i},dim);
        end
    else
        Z = calcZScore(A,dim);
    end
end

function Z = calcZScore(A,dim)
    if dim == 0
        m = mean(A(:),'omitnan');
        s = std(A(:),'omitnan');
        Z = (A - m) ./ s;
    else
        m = mean(A,dim,'omitnan');
        s = std(A,0,dim,'omitnan');
        if dim == 1
            m = repmat(m,[size(A,dim),1]);
            s = repmat(s,[size(A,dim),1]);
        elseif dim == 2
            m = repmat(m,[1,size(A,dim)]);
            s = repmat(s,[1,size(A,dim)]);
        elseif dim == 3
            m = repmat(m,1,1,size(A,dim));
            s = repmat(s,1,1,size(A,dim));
        else
            error('Cannot have dim > 3');
        end
        Z = (A - m) ./ s;
    end
    Z(isnan(Z)) = 0;
end
