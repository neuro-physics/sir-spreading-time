function A = get_random_matrix(N,conn_dens)
    A              = rand(N,N);
    A(A>conn_dens) = 0;
end