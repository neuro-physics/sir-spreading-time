clearvars
close all

x = rand(50,100);
y1 = rand(50,100);

alpha = 0.05;
%%

[h1,p1] = ttest2(x, y1, 'Alpha', alpha);
[a1,b1] = FDR(p1,alpha);
h1C = zeros(size(h1));
h1C = p1 <= a1;

figure;plot(1:100,h1,'*',1:100,h1C,'or',1:100,p1,'-k',1:100,repmat(0.05,1,100),'-r')

%%

k = 40;
y2 = y1;
y2(:,k) = y1(:,k) + 0.2;

%%

[h2,p2] = ttest2(x, y2, 'Alpha', alpha);
[a2,b2] = FDR(p2,alpha);

h2C = zeros(size(h2));
h2C = p2<=a2;

figure;plot(1:100,h2,'*',1:100,h2C,'or',1:100,p2,'-k',1:100,repmat(0.05,1,100),'-r')
