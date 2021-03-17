function T = findLinearTransformation(u,v)
% finds a matrix T (3x3) such that T * u(:,i) = v(:,i)
% u(:,i) and v(:,i) are 3d col vectors; the amount of col vectors in u and v must match
%
% explanation of algorithm in:
% http://stackoverflow.com/questions/26635266/matlab-calculate-3d-similarity-transformation-fitgeotrans-for-3d
    if any(size(u) ~= size(v))
        error('findLinearTransform:u','u and v must be the same shape and size 3d vectors');
    end
    [n,nP] = size(u);
    if nP > n
        I = eye(nP);
        u = [u;I((n+1):nP,1:nP)];
        v = [v;I((n+1):nP,1:nP)];
        [n,nP] = size(u);
    end
    if (nP*n*n*n > intmax())
        if n == nP
            T = v/u;
        else
            error('findLinearTransform:u','matrix too big to resolve');
        end
    else
        A = zeros(nP*n,n*n);
        for k = 1:nP
            for i = ((k-1)*n+1):(k*n)
                A(i,mod((((i-1)*n+1):(i*n))-1,n*n) + 1) = u(:,k)';
            end
        end
        v = v(:);
        T = reshape(A\v, n, n).';
    end
end
