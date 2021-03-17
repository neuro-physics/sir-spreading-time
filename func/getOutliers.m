function [xOut,ind] = getOutliers(X)
% uses the quantile rule to get the ouliers of X
% calculates the 4 quantiles bounded by min(X), Q1, Q2, Q3, max(X)
% and returns points of X such that
% X < Q1-1.5*(Q3-Q1) or X > Q3+1.5(Q3-Q1)
    Q = quantile(X,3);
    ind = (X < (Q(1)-1.5.*(Q(3)-Q(1)))) | (X > (Q(3)+1.5.*(Q(3)-Q(1))));
    xOut = X(ind);
end