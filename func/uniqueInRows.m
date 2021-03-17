function [u,c,k] = uniqueInRows(A)
    n = size(A,1);
    u = [];
    c = [];
    k = false(size(A));
    for i = 1:n
        [uTemp,m] = unique(A(i,:),'stable');
        u((numel(u)+1):(numel(u)+numel(uTemp))) = uTemp;
        c((numel(c)+1):(numel(c)+numel(m))) = m;
        k(i,m) = true(1,numel(m));
    end
    u = u(:);
    c = c(:);
end
