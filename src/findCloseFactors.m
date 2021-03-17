function f = findCloseFactors(N)
    L = sqrt(N);
    if floor(L) == L
        f = [ L, L ];
        return;
    end
    Nf = factor(N);
    if numel(Nf) == 1
        f = [N,1];
        return;
    end
    if numel(Nf) == 2
        f = Nf;
        return;
    end
    if numel(Nf) == 3
        Nf = [ 1, Nf ];
    end
    eF = 1;
    if numel(Nf)>4
        eF = prod(Nf(1:(end-4)));
        Nf = Nf((end-3):end);
    end
    fPerms = perms(Nf);
    pr = [ prod(fPerms(:,1:2),2), prod(fPerms(:,3:4),2) ];
    pr = [ eF.*pr(:,1), pr(:,2);...
           pr(:,1), eF.*pr(:,2) ];
    [~,k] = min(abs( diff(pr,1,2) ));
    f = sort(pr(k,:),'descend');
end
