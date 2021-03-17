clearvars
close all

addpath('.\func');
addpath('.\func\network');

% netType = adjmatrix.NetworkTypes.SqrLatt;
netType = adjmatrix.NetworkTypes.BarabAlbGraph;

L = [10,40,70,100];
N = L.^2;
L_legend = cellfun(@(x)sprintf('N=%d',x),num2cell(L),'UniformOutput',false);
N_legend = cellfun(@(x)sprintf('N=%d',x),num2cell(N),'UniformOutput',false);

A = cell(size(N));
x = cell(size(N));

for i = 1:numel(L)
    if netType == adjmatrix.NetworkTypes.SqrLatt
        A{i} = adjmatrix.GetAdjMatrix(adjmatrix.AdjMatrixParams(netType,[L(i),L(i)],0,2,0,0,2,'','',0),1);
    elseif netType == adjmatrix.NetworkTypes.BarabAlbGraph
        A{i} = adjmatrix.GetAdjMatrix(adjmatrix.AdjMatrixParams(adjmatrix.NetworkTypes.BarabAlbGraph,[L(i),L(i)],0.02,3,1,0,2,'','',0),1);
    end
    x{i} = linspace(1,max(N),N(i));
end

lightBlue = [220, 241, 247]./255;
darkBlue = [56, 129, 158]./255;
lightGreen = [224, 247, 220]./255;
darkGreen = [68, 145, 55]./255;
lightRed = [244, 217, 217]./255;
darkRed = [186, 22, 22]./255;
lightYellow = [252, 238, 186]./255;
darkYellow = [226, 187, 45]./255;

%% calculating density
rho = calcNetworkDensity(A,'individual');

disp('---');
disp('* Density');
for i = 1:numel(rho)
    fprintf('  . N = %d => rho = %.5e\n', N(i), rho(i));
end

%% calculating weight distribution
[P,w] = calcWeightDistribution(A,50,'individual');

figure;
plot(w, P, ':o', 'MarkerSize', 3);
legend(N_legend, 'Box', 'off', 'Location', 'best');
title('Weight distribution');
xlabel('Weight, $w$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(w)$', 'Interpreter', 'latex');

%% calculating weighted clustering coefficients
C = calcClusteringCoeff(A);

figure;axes;hold on;
for i = 1:numel(C)
    plot(x{i}, C{i}, '-o', 'MarkerSize', 3);
end
legend(N_legend, 'Box', 'off', 'Location', 'best');
title('Weighted clustering coefficient');
xlabel('Node', 'Interpreter', 'latex');ylabel('$C(n)$', 'Interpreter', 'latex');

disp('---');
disp('* Weighted clustering coefficient');
dispMeanStd(C,[],N);

%% node degree (connectivity)

[Pk,k_dist] = calcNodeDegree(A,'in','distribution');
[~,k] = calcNodeDegree(A,'in','degree');

figure;axes;hold on;
for i = 1:numel(Pk)
    plot(x{i}, k{i}, '-o', 'MarkerSize', 3);
end
legend(N_legend, 'Box', 'off', 'Location', 'best');
title('Node degree');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Degree, $k(n)$', 'Interpreter', 'latex');

figure;axes;hold on;
for i = 1:numel(Pk)
    plot(k_dist{i}, Pk{i}, '-o', 'MarkerSize', 3);
end
legend(N_legend, 'Box', 'off', 'Location', 'best');
title('Node degree distribution');
xlabel('Degree, $k$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(k)$', 'Interpreter', 'latex');

%% betweenness centrality
B = calcBetweennessCentrality(A);

figure;axes;hold on;
for i = 1:numel(B)
    plot(x{i}, B{i}, '-o', 'MarkerSize', 3);
end
legend(N_legend, 'Box', 'off', 'Location', 'best');
title('Betweenness centrality');
xlabel('Node', 'Interpreter', 'latex');ylabel('$B(n)$', 'Interpreter', 'latex');

disp('---');
disp('* Betweenness centrality');
dispMeanStd(B,[],N);
