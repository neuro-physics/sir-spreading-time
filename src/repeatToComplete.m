function y = repeatToComplete(x,N)
% y = [ x(:)', x(:)', ..., x(:)' ]; such that y is [1,N] vector
    y = zeros(1,N);
    x = x(:)';
    n = numel(x);
    m = floor(N/n);
    if m <= 1
        y = x(1:N);
        return
    end
    y(1:(m*n)) = repmat(x, 1, m);
    y((m*n+1):N) = x(1:(N-m*n));
end
