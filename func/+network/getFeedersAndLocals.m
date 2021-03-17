function [fd,lc] = getFeedersAndLocals(A,n)
% graph represented by A adj matrix
% fd -> nodes that connect to n (in or out)
% lc -> all other nodes
    [~,fd1] = find(A(n,:) > 0);
    [fd2,~] = find(A(:,n) > 0);
    fd = union(fd1(:),fd2(:));
    fd(ismember(fd,n(:))) = [];
    lc = setdiff(1:size(A,1),[fd(:)',n(:)']);
    [~,dim] = max(size(n));
    if dim == 1
        fd = reshape(fd,numel(fd),1);
        lc = reshape(lc,numel(lc),1);
    else
        fd = reshape(fd,1,numel(fd));
        lc = reshape(lc,1,numel(lc));
    end
end
