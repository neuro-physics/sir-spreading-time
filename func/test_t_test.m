clearvars
close all

nTests = 100;

alpha = 0.01;
% x = rand(1000,1);
% y = rand(1000,1);
x = random('Normal', 10, 5, [1000,nTests]);
y = random('Normal', 10.1, 5, [1000,nTests]);
y(:,40) = random('Normal', 11, 5, [1000,1]);
%y = zeros(1000,2);
%y(:,1) = random('Normal', 10.1, 5, [1000,1]);
%y(:,2) = random('Normal', 11, 5, [1000,1]);
%y(:,3) = random('Normal', 12, 5, [1000,1]); % error; number of cols in x and y must be the same

[h,p,ci,st,t] = myttest2(x,y,'Alpha',alpha);
[pFDR,~] = FDR(p,alpha);
hC = p <= pFDR;

for i = 1:numel(h)
    if h(i) == 1
        disp(sprintf('x(:,%d) differs from y(:,%d) with significance %f', i,i,alpha));
    else
        disp(sprintf('x(:,%d) equals y(:,%d) with significance %f', i,i,1-alpha));
    end
end

n = 1:nTests;
plot(n(h>0),h(h>0),'*m',n,p,'-k',[1,nTests],[alpha,alpha],'-r',n,t,'-b',n(hC>0),hC(hC>0),'or')

%%

% groups = ones(1,1000);
% G = termSurfStat(groups);
% %G = term(groups);
% %M = 1 + G;
% M = G;
% Y = zeros(1000,2);
% Y(:,1) = x(:)';
% Y(:,2) = y(:)';
% %Y(1,:) = random('Normal', 10, 5, [1,1000]);
% %Y(1,:) = random('Normal', 10.1, 5, [1,1000]);
% slm = SurfStatLinMod(Y,M);
% %slm = SurfStatT(slm, G.A-G.B);
% slm = SurfStatT(slm, G.A-G.B);
% q = SurfStatQ(slm);

% groups = { 'A', 'A', 'A', 'B', 'B', 'B', 'B' };
% G = termSurfStat(groups);
% M = 1 + G;
% Y = rand(7,1000);
% slm = SurfStatLinMod(Y,M);
% slm = SurfStatT(slm, G.A-G.B);
% q = SurfStatQ(slm);
