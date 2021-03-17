function A = pairsToMatrix(pairs, values, N)
    A = zeros(N);
    A(sub2ind(size(A),pairs(1,:),pairs(2,:))) = values;
    A(sub2ind(size(A),pairs(2,:),pairs(1,:))) = values;
end
