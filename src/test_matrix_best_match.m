clearvars
close all

cd ..
param = adjmatrix.AdjMatrixParams(adjmatrix.NetworkTypes.SqrLatt, 100, 0, 0, 0, 0, 2, '', '', 0);
A = full(adjmatrix.GetAdjMatrix(param));
cd src

% A = load('D:\Dropbox\p\postdoc\data\AALmatrix_N90\TLE_301_1_FA_AAL_lowres.mat');
% A = A.matrix;

% A = load('D:\Dropbox\p\postdoc\data\AALmatrix_N306\TLE_301_1_FA_AAL_midres.mat');
% A = A.matrix;

[Fh,Rh,Ph]=FindBestFunctionalMatch_mex(A, A, 0.01, 2:80, 100, 1000, 'hamming');
[Fc,Rc,Pc]=FindBestFunctionalMatch_mex(A, A, 0.01, 2:80, 100, 1000, 'corr');

subplot(1,3,1);imagesc(A);title('original');axis('square')
subplot(1,3,2);imagesc(Fc);title('corr max');axis('square')
subplot(1,3,3);imagesc(Fh);title('hamming min');axis('square')

figure;plot(Rc);
xlabel('n seeds');
ylabel('Correlation coefficient, $R$', 'Interpreter', 'latex');

figure;plot(Rh);
xlabel('n seeds');
ylabel('Hamming distance, $H$', 'Interpreter', 'latex');