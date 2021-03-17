clearvars
close all

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end

addpath(fullfile('.','func'));
%addpath(fullfile('.','func','network'));

[A90,cn90] = loadAALMatrix(fullfile(dataDir,'AALmatrix_N90','flipped_cols','TLE*_FA_*.mat'));
[A306,cn306] = loadAALMatrix(fullfile(dataDir,'AALmatrix_N306','flipped_cols','TLE*_FA_*.mat'));

[k90,x90,k306,x306] = generateAALParcelCorresp(1,0.2);

A90 = sortMatrices(A90,k90,0);
A306 = sortMatrices(A306,k306,0);

[pInd,cInd] = getPatientControlInd(cn90);
A90_c = A90(cInd); A90_p = A90(pInd);
nC90 = numel(A90_c); nP90 = numel(A90_p);
[pInd,cInd] = getPatientControlInd(cn306);
A306_c = A306(cInd); A306_p = A306(pInd);
nC306 = numel(A306_c); nP306 = numel(A306_p);

lightBlue = [220, 241, 247]./255;
darkBlue = [56, 129, 158]./255;
lightGreen = [224, 247, 220]./255;
darkGreen = [68, 145, 55]./255;
lightRed = [244, 217, 217]./255;
darkRed = [186, 22, 22]./255;
lightYellow = [252, 238, 186]./255;
darkYellow = [226, 187, 45]./255;

%% calculating density
[rho90_c_mean,rho90_c_std] = meanStd(network.calcNetworkDensity(A90_c,'individual'));
[rho90_p_mean,rho90_p_std] = meanStd(network.calcNetworkDensity(A90_p,'individual'));
[rho306_c_mean,rho306_c_std] = meanStd(network.calcNetworkDensity(A306_c,'individual'));
[rho306_p_mean,rho306_p_std] = meanStd(network.calcNetworkDensity(A306_p,'individual'));

   disp('---');
   disp('* Density');
   disp('  - N = 90');
fprintf('    . Controls = %.5g +/- %.5g\n', rho90_c_mean, rho90_c_std);
fprintf('    . Patients = %.5g +/- %.5g\n', rho90_p_mean, rho90_p_std);
   disp('  - N = 306');
fprintf('    . Controls = %.5g +/- %.5g\n', rho306_c_mean, rho306_c_std);
fprintf('    . Patients = %.5g +/- %.5g\n', rho306_p_mean, rho306_p_std);

%% calculating weight distribution
[P90_c_mean,w90_c_mean] = network.calcWeightDistribution(A90_c,50,'single');
[P90_c,w90_c] = network.calcWeightDistribution(A90_c,50,'individual');
[P90_p_mean,w90_p_mean] = network.calcWeightDistribution(A90_p,50,'single');
[P90_p,w90_p] = network.calcWeightDistribution(A90_p,50,'individual');

[P306_c_mean,w306_c_mean] = network.calcWeightDistribution(A306_c,50,'single');
[P306_c,w306_c] = network.calcWeightDistribution(A306_c,50,'individual');
[P306_p_mean,w306_p_mean] = network.calcWeightDistribution(A306_p,50,'single');
[P306_p,w306_p] = network.calcWeightDistribution(A306_p,50,'individual');

figure;
l1 = plot(w90_c, P90_c, '-^', 'Color', lightBlue, 'MarkerFaceColor', lightBlue, 'MarkerSize', 3); hold on;
l2 = plot(w306_c, P306_c, '-v', 'Color', lightGreen, 'MarkerFaceColor', lightGreen, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(w90_c_mean, P90_c_mean, '-o', 'Color', darkBlue, 'MarkerFaceColor', darkBlue, 'MarkerSize', 3);
plot(w306_c_mean, P306_c_mean, '-s', 'Color', darkGreen, 'MarkerFaceColor', darkGreen, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weight distribution - Controls');
xlabel('FA weight, $w$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(w)$', 'Interpreter', 'latex');

figure;
l1 = plot(w90_p, P90_p, '-^', 'Color', lightRed, 'MarkerFaceColor', lightRed, 'MarkerSize', 3); hold on;
l2 = plot(w306_p, P306_p, '-v', 'Color', lightYellow, 'MarkerFaceColor', lightYellow, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(w90_p_mean, P90_p_mean, '-o', 'Color', darkRed, 'MarkerFaceColor', darkRed, 'MarkerSize', 3);
plot(w306_p_mean, P306_p_mean, '-s', 'Color', darkYellow, 'MarkerFaceColor', darkYellow, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weight distribution - Patients');
xlabel('FA weight, $w$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(w)$', 'Interpreter', 'latex');

%% calculating weighted clustering coefficients
C90_c = network.calcClusteringCoeff(A90_c);
C90_c_mean = mean(C90_c,2,'omitnan');
C90_p = network.calcClusteringCoeff(A90_p);
C90_p_mean = mean(C90_p,2,'omitnan');
C306_c = network.calcClusteringCoeff(A306_c);
C306_c_mean = mean(C306_c,2,'omitnan');
C306_p = network.calcClusteringCoeff(A306_p);
C306_p_mean = mean(C306_p,2,'omitnan');

figure;
l1 = plot(repmat(x90,1,nC90), C90_c, '-^', 'Color', lightBlue, 'MarkerFaceColor', lightBlue, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nC306), C306_c, '-v', 'Color', lightGreen, 'MarkerFaceColor', lightGreen, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, C90_c_mean, '-o', 'Color', darkBlue, 'MarkerFaceColor', darkBlue, 'MarkerSize', 3);
plot(x306, C306_c_mean, '-s', 'Color', darkGreen, 'MarkerFaceColor', darkGreen, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weighted clustering coefficient - Controls');
xlabel('Node', 'Interpreter', 'latex');ylabel('$C(n)$', 'Interpreter', 'latex');

figure;
l1 = plot(repmat(x90,1,nP90), C90_p, '-^', 'Color', lightRed, 'MarkerFaceColor', lightRed, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nP306), C306_p, '-v', 'Color', lightYellow, 'MarkerFaceColor', lightYellow, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, C90_p_mean, '-o', 'Color', darkRed, 'MarkerFaceColor', darkRed, 'MarkerSize', 3);
plot(x306, C306_p_mean, '-s', 'Color', darkYellow, 'MarkerFaceColor', darkYellow, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weighted clustering coefficient - Patients');
xlabel('Node', 'Interpreter', 'latex');ylabel('$C(n)$', 'Interpreter', 'latex');

disp('---');
disp('* Weighted clustering coefficient');
dispMeanStd(C90_c,C90_p,90);
dispMeanStd(C306_c,C306_p,306);

%% node degree (connectivity)

[Pk90_c,k90_c_dist] = network.calcNodeDegree(A90_c,'in','distribution');
[~,k90_c] = network.calcNodeDegree(A90_c,'in','degree');
k90_c_mean = mean(k90_c,2,'omitnan');
[Pk90_p,k90_p_dist] = network.calcNodeDegree(A90_p,'in','distribution');
[~,k90_p] = network.calcNodeDegree(A90_p,'in','degree');
k90_p_mean = mean(k90_p,2,'omitnan');

[Pk306_c,k306_c_dist] = network.calcNodeDegree(A306_c,'in','distribution');
[~,k306_c] = network.calcNodeDegree(A306_c,'in','degree');
k306_c_mean = mean(k306_c,2,'omitnan');
[Pk306_p,k306_p_dist] = network.calcNodeDegree(A306_p,'in','distribution');
[~,k306_p] = network.calcNodeDegree(A306_p,'in','degree');
k306_p_mean = mean(k306_p,2,'omitnan');

figure;
l1 = plot(repmat(x90,1,nC90), k90_c, '-^', 'Color', lightBlue, 'MarkerFaceColor', lightBlue, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nC306), k306_c, '-v', 'Color', lightGreen, 'MarkerFaceColor', lightGreen, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, k90_c_mean, '-o', 'Color', darkBlue, 'MarkerFaceColor', darkBlue, 'MarkerSize', 3);
plot(x306, k306_c_mean, '-s', 'Color', darkGreen, 'MarkerFaceColor', darkGreen, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Node degree - Controls');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Degree, $k(n)$', 'Interpreter', 'latex');

figure;
l1 = plot(repmat(x90,1,nP90), k90_p, '-^', 'Color', lightRed, 'MarkerFaceColor', lightRed, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nP306), k306_p, '-v', 'Color', lightYellow, 'MarkerFaceColor', lightYellow, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, k90_p_mean, '-o', 'Color', darkRed, 'MarkerFaceColor', darkRed, 'MarkerSize', 3);
plot(x306, k306_p_mean, '-s', 'Color', darkYellow, 'MarkerFaceColor', darkYellow, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Node degree - Patients');
xlabel('Node, $n$', 'Interpreter', 'latex');ylabel('Degree, $k(n)$', 'Interpreter', 'latex');

figure;
plot(k90_c_dist, Pk90_c, '-o', 'Color', darkBlue, 'MarkerFaceColor', darkBlue, 'MarkerSize', 3);hold on;
plot(k306_c_dist, Pk306_p, '-s', 'Color', darkGreen, 'MarkerFaceColor', darkGreen, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Node degree distribution - Controls');
xlabel('Degree, $k$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(k)$', 'Interpreter', 'latex');

figure;
plot(k90_p_dist, Pk90_p, '-o', 'Color', darkRed, 'MarkerFaceColor', darkRed, 'MarkerSize', 3);hold on;
plot(k306_p_dist, Pk306_p, '-s', 'Color', darkYellow, 'MarkerFaceColor', darkYellow, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Node degree distribution - Patients');
xlabel('Degree, $k$', 'Interpreter', 'latex');ylabel('$\mathcal{P}(k)$', 'Interpreter', 'latex');

%% betweenness centrality
B90_c = network.calcBetweennessCentrality(A90_c);
B90_c_mean = mean(B90_c,2,'omitnan');
B90_p = network.calcBetweennessCentrality(A90_p);
B90_p_mean = mean(B90_p,2,'omitnan');
B306_c = network.calcBetweennessCentrality(A306_c);
B306_c_mean = mean(B306_c,2,'omitnan');
B306_p = network.calcBetweennessCentrality(A306_p);
B306_p_mean = mean(B306_p,2,'omitnan');

figure;
l1 = plot(repmat(x90,1,nC90), B90_c, '-^', 'Color', lightBlue, 'MarkerFaceColor', lightBlue, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nC306), B306_c, '-v', 'Color', lightGreen, 'MarkerFaceColor', lightGreen, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, B90_c_mean, '-o', 'Color', darkBlue, 'MarkerFaceColor', darkBlue, 'MarkerSize', 3);
plot(x306, B306_c_mean, '-s', 'Color', darkGreen, 'MarkerFaceColor', darkGreen, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weighted betweenness centrality - Controls');
xlabel('Node', 'Interpreter', 'latex');ylabel('$B(n)$', 'Interpreter', 'latex');

figure;
l1 = plot(repmat(x90,1,nP90), B90_p, '-^', 'Color', lightRed, 'MarkerFaceColor', lightRed, 'MarkerSize', 3); hold on;
l2 = plot(repmat(x306,1,nP306), B306_p, '-v', 'Color', lightYellow, 'MarkerFaceColor', lightYellow, 'MarkerSize', 3);
set(l1,'HandleVisibility','off'); set(l2,'HandleVisibility','off');
plot(x90, B90_p_mean, '-o', 'Color', darkRed, 'MarkerFaceColor', darkRed, 'MarkerSize', 3);
plot(x306, B306_p_mean, '-s', 'Color', darkYellow, 'MarkerFaceColor', darkYellow, 'MarkerSize', 3);
legend({'N=90','N=306'}, 'Box', 'off', 'Location', 'best');
title('Weighted betweenness centrality - Patients');
xlabel('Node', 'Interpreter', 'latex');ylabel('$B(n)$', 'Interpreter', 'latex');

disp('---');
disp('* Weighted betweenness centrality');
dispMeanStd(B90_c,B90_p,90);
dispMeanStd(B306_c,B306_p,306);
