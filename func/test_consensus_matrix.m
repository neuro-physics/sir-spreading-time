clearvars
close all

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

%% getting controls adjacency matrix
% [A_controls,~] = getSubjectsAdjMatrix(fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat'), {}, {}, false);
[A_controls,~] = getSubjectsAdjMatrix(fullfile(dataDir,'AALmatrix_N306','TLE*_FA_*.mat'), {}, {}, false);

nC = numel(A_controls);
N = size(A_controls{1},1);
nodes = 1:N;

%% calculating consensus
A = GetConsensusAdjMatrix(A_controls);
B = GetConsensusMatrixEdgeLength(A_controls); % results are more consistent without adjusting the number of bins
% A = GetConsensusMatrixEdgeLength(A_controls);
% B = GetConsensusMatrixEdgeLength(A_controls, [], [], [1000,1900]); % nBins = [1621,3826] for N=306
M = reshape(cell2mat(A_controls),[size(A),nC]);

%% calculating density
rhoA = numel(A(A>0))/numel(A);
rhoB = numel(B(B>0))/numel(B);
rhoM = numel(M(M>0))/numel(M);

disp('---');
disp('* Density');
disp(['  - matrix A (no edge length sampling) = ', num2str(rhoA)]);
disp(['  - matrix B    (edge length sampling) = ', num2str(rhoB)]);
disp(['  - all matrices average               = ', num2str(rhoM)]);

%% calculating weight distribution
wM = M(M~=0);
wA = A(A~=0);
wB = B(B~=0);
[PM,weM]=histcounts(wM,50,'Normalization','probability');weM=weM(1:end-1);
[PA,weA]=histcounts(wA,50,'Normalization','probability');weA=weA(1:end-1);
[PB,weB]=histcounts(wB,50,'Normalization','probability');weB=weB(1:end-1);
figure;plot(weA, PA, '-ob', weB, PB, '-sk', weM, PM, '-+r', 'MarkerFaceColor', 'auto', 'MarkerSize', 3);
legend({'A (no edge length)','B (edge length)','all matrices'}, 'Box', 'off', 'Location', 'best');
xlabel('FA weight, $w$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(w)$', 'Interpreter', 'latex');

%% calculating weighted clustering coefficients
CA = clustering_coef_wd(A)';
CB = clustering_coef_wd(B)';
CM = zeros(nC,N);
for i = 1:nC
    CM(i,:) = clustering_coef_wd(A_controls{i})';
end
CMm = mean(CM,1);
figure;l=plot(nodes,CM,'-','Color',[0.9,0.9,0.9]);hold on
plot(nodes, CA, '-b', nodes, CB, '-k', nodes, CMm, ':r', 'LineWidth', 2);
hold off
set(l, 'HandleVisibility', 'off');
legend({'A (no edge length)','B (edge length)','all matrices'}, 'Box', 'off', 'Location', 'best');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Clustering coeff. $\mathcal{C}(n)$', 'Interpreter', 'latex');

disp('---');
dispAvgError(CA,CB,CMm,N,'Weighted clustering coefficient');

%% node degree (connectivity)

kA = sum(A~=0,1);
kB = sum(B~=0,1);
kM = zeros(nC,N);
for i = 1:nC
    kM(i,:) = sum(M(:,:,i)~=0,1);
end
[PkM,keM]=histcounts(kM(:),[nodes,(N+1)],'Normalization','probability');keM=keM(1:end-1);
[PkA,keA]=histcounts(kA,[nodes,(N+1)],'Normalization','probability');keA=keA(1:end-1);
[PkB,keB]=histcounts(kB,[nodes,(N+1)],'Normalization','probability');keB=keB(1:end-1);

kMm = mean(kM,1);
figure;l=plot(nodes,kM,'-','Color',[0.9,0.9,0.9]);hold on
plot(nodes, kA, '-b', nodes, kB, '-k', nodes, kMm, ':r', 'LineWidth', 2);
hold off
set(l, 'HandleVisibility', 'off');
legend({'A (no edge length)','B (edge length)','all matrices'}, 'Box', 'off', 'Location', 'best');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Connectivity $k(n)$', 'Interpreter', 'latex');

figure;plot(keA, PkA, ':ob', keB, PkB, ':sk', keM, PkM, ':+r', 'MarkerFaceColor', 'auto', 'MarkerSize', 3);
legend({'A (no edge length)','B (edge length)','all matrices'}, 'Box', 'off', 'Location', 'best');
xlabel('Degree, $k$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(k)$', 'Interpreter', 'latex');

disp('---');
dispAvgError(kA,kB,kMm,N,'Node connectivity');
disp('---');
dispAvgError(PkA,PkB,PkM,N,'Connectivity distribution');

%% betweenness centrality
GA = digraph(A);
GB = digraph(B);
bA = centrality(GA, 'betweenness')';
bB = centrality(GB, 'betweenness')';
bM = zeros(nC,N);
for i = 1:nC
    GM = digraph(M(:,:,i));
    bM(i,:) = centrality(GM, 'betweenness');
end

bMm = mean(bM,1);
figure;l=plot(nodes,bM,'-','Color',[0.9,0.9,0.9]);hold on
plot(nodes, bA, '-b', nodes, bB, '-k', nodes, bMm, ':r', 'LineWidth', 2);
hold off
set(l, 'HandleVisibility', 'off');
legend({'A (no edge length)','B (edge length)','all matrices'}, 'Box', 'off', 'Location', 'best');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Betweenness centrality $\mathcal{B}(n)$', 'Interpreter', 'latex');

disp('---');
dispAvgError(bA,bB,bMm,N,'Betweenness centrality');
