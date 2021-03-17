function [M,E,nNN,S] = meanMatrix(A)
    if ~iscell(A)
        A = { A };
    end
    nMat = numel(A);
    nNN = zeros(size(A{1}));
    [m,n] = size(A{1});
    M = zeros(size(A{1}));
    E = zeros(size(A{1}));
    for k = 1:nMat
        for i = 1:m
            for j = 1:n
                if ~isnan(A{k}(i,j))
                    M(i,j) = M(i,j) + A{k}(i,j);
                    E(i,j) = E(i,j) + A{k}(i,j) * A{k}(i,j);
                    nNN(i,j) = nNN(i,j) + 1;
                end
            end
        end
    end
    nNN(nNN==0)=1;
    M = M ./ nNN;
    S = sqrt(E ./ nNN - M .* M); % this way of calculating is equivalent to std(x,w=1) -- i.e. it divides the sum of sqr difference to the mean by N instead of N-1
    E = S ./ sqrt(nNN);
end
