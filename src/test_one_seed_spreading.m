clearvars
close all

cd ..
param = adjmatrix.AdjMatrixParams(adjmatrix.NetworkTypes.SqrLatt, 100, 0, 0, 0, 0, 2, '', '', 0);
A = full(adjmatrix.GetAdjMatrix(param));
cd src

N = size(A,1);
L = sqrt(N);
n = GetNodes(A, 0.01, 0, 1, false);
p = GetSimulationParam(A, 1, false, 'fixed', 45, 1);
x = EvolveSINetwork_mex(n, 20, p, 1);

figure;
imagesc(x);
xlabel('Node');
ylabel('Time');
set(gca, 'YDir', 'Reverse');
title('Time evolution')

plotLattice(L,x(end,:),p.seeds,'t=11');
