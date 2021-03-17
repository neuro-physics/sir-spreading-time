function rho = netDensity(A)
    rho = numel(A(A~=0))/numel(A);
end
