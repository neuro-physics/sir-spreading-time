function [B,Bdens] = filterWeakestElements(A,d)
% filter out weakest elements from A
% to the desired density d
% this function does not ensure that B is a connected graph
    s = size(A);
    N = numel(A);
    A = reshape(A,N,1);
    [~,k] = sort(A,'descend');
    n = round(N * d);
    B = zeros(N,1);
    B(k(1:n)) = A(k(1:n));
    B = reshape(B,s);
    Bdens = numel(B(B~=0)) / N;
end
