clearvars
close all

cd ..
param = adjmatrix.AdjMatrixParams(adjmatrix.NetworkTypes.SqrLatt, 100, 0, 0, 0, 0, 2, '', '', 0);
A = full(adjmatrix.GetAdjMatrix(param));
cd src

% load('D:\Dropbox\p\postdoc\data\AALmatrix_N90\TLE_301_1_FA_AAL_lowres.mat')
% A = matrix;

%%
N = size(A,1);
L = findCloseFactors(N);
n = GetNodes(A, 0.01, 0, 10, true);
p = GetSimulationParam(A, 10, true, 'fixed', [5,86], 1);
[x,~,tt] = EvolveSINetwork(n, 20, p, true);

figure;
imagesc(x);
xlabel('Node');
ylabel('Time');
set(gca, 'YDir', 'Reverse');
title('Time evolution')

L1 = L(1);
L2 = L(2);

%%
[ii,jj]=ind2sub(L1,p.seeds);
[xx,yy]=meshgrid(1:(L1+1),1:(L2+1));
%P = reshape(x(end,:),L1,L2);
%%
P = zeros(size(xx));
P(1:L2,1:L1) = reshape(x(end,:),L2,L1);
%%
figure;
sh = pcolor(xx,yy,P);set(gca,'YDir','Reverse');
sh.EdgeColor = 'w';
sh.EdgeAlpha = 0.5;
hold on
plot(jj+0.5,ii+0.5,'ok','MarkerFaceColor','w','MarkerSize',15);
title('Lattice')
% figure;imagesc(P(1:L,1:L));
% hold on
% plot(jj,ii,'ok','MarkerFaceColor','w','MarkerSize',15)
