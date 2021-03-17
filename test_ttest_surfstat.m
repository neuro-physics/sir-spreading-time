clearvars
close all

addpath func

%% test 1
% test whether the overlap of x(:,i) and y(:,i) is considered equal by t-test

% generating random data
x = random('normal',10,1,[1000,1]);
x = repmat(x(:,1),1,20);
y = random('normal',15,1,[1000,1]);
x_plot = ones(size(x));
for i = 2:20
    y(:,end+1)=y(:,1) - (i-1).*0.5;
    x_plot(:,i) = i;
end

[a.h,a.p,a.ci,a.stats,a.t,slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both');
[b.h,b.p,b.ci,b.stats,b.t] = ttest.myttest2(x,y,'Alpha',0.05,'Tail','both');

% a and b are equal structs

k_a = find(a.h); % finding the t-test differences between x and y within p < alpha range (alpha*100% of false positives)
k_b = find(b.h); % finding the t-test differences between x and y within p < alpha range (alpha*100% of false positives)

plot(x_plot,x,'.b',x_plot+0.3,y,'.r',k_a,20.*ones(size(k_a)),'*k',k_b,19.*ones(size(k_b)),'+k');
xlabel('comparison #')
ylabel('x and y values')
set(gca,'XLim',[0.7,(x_plot(1,end)+0.6)]);

%% test 2
% test whether there is significant overlap of the clouds [x(:,i,1),x(:,i,2)] and [y(:,i,1),y(:,i,2)]

X(:,:,1) = x;
Y(:,:,1) = y;

% generating data
xx = random('normal', 10, 1, [1000,1]);
X(:,:,2) = repmat(xx,1,20);
yy = random('normal', 15, 1, [1000,1]);
for i = 1:20
    Y(:,i,2) = yy - (i-1).*0.5;
end

X_x_plot = 10 .* (x_plot-1) + X(:,:,1); % displacing data for visualizing
X_y_plot = X(:,:,2);

Y_x_plot = 10 .* (x_plot-1) + Y(:,:,1); % displacing data for visualizing
Y_y_plot = Y(:,:,2);

[A.h,A.p,A.ci,A.stats,A.t,SLM] = ttest.tTestSurfStat(X,Y,'Alpha',0.05,'Tail','both');
K = find(A.h); % finding the t-test differences between x and y within p < alpha range (alpha*100% of false positives)

figure;
plot(X_x_plot,X_y_plot,'.b',Y_x_plot,Y_y_plot,'.r',10.*x_plot(1,K),20.*ones(size(K)),'*k');
xlabel('displaced x_1 and y_1')
ylabel('x_2 and y_2')
set(gca,'XLim',minmax(X_x_plot(:)')+[-10,10]);

%% test 3
% test whether there is significant overlap of the 3d clouds [x(:,i,1),x(:,i,2),x(:,i,3)] and [y(:,i,1),y(:,i,2),y(:,i,3)]

X3 = X;
Y3 = Y;

% generating data
xx = random('normal', 10, 1, [1000,1]);
X3(:,:,3) = repmat(xx,1,20);
yy = random('normal', 15, 1, [1000,1]);
for i = 1:20
    Y3(:,i,3) = yy - (i-1).*0.5;
end

X3_x_plot = 10 .* (x_plot-1) + X3(:,:,1); % displacing data for visualizing
X3_y_plot = X3(:,:,2);
X3_z_plot = X3(:,:,3);

Y3_x_plot = 10 .* (x_plot-1) + Y3(:,:,1); % displacing data for visualizing
Y3_y_plot = Y3(:,:,2);
Y3_z_plot = Y3(:,:,3);

[A3.h,A3.p,A3.ci,A3.stats,A3.t,SLM3] = ttest.tTestSurfStat(X,Y,'Alpha',0.05,'Tail','both');
K3 = find(A3.h); % finding the t-test differences between x and y within p < alpha range (alpha*100% of false positives)

fh = figure;
fh.Position(1) = fh.Position(1) - 1.5*fh.Position(3);
if (fh.Position(1) <= 0)
    fh.Position(1) = 20;
end
fh.Position(3) = fh.Position(3) * 2.5;
subplot(1,3,1);
plot3(X3_x_plot,X3_y_plot,X3_z_plot,'.b',Y3_x_plot,Y3_y_plot,Y3_z_plot,'.r',10.*x_plot(1,K3),20.*ones(size(K3)),20.*ones(size(K3)),'*k')
xlabel('displaced x_1 and x_2');ylabel('y_1 and y_2');zlabel('z_1 and z_2');
set(gca,'XLim',minmax(X_x_plot(:)')+[-10,10]);
view([1,0,0]);
axis square
subplot(1,3,2);
plot3(X3_x_plot,X3_y_plot,X3_z_plot,'.b',Y3_x_plot,Y3_y_plot,Y3_z_plot,'.r',10.*x_plot(1,K3),20.*ones(size(K3)),20.*ones(size(K3)),'*k')
xlabel('displaced x_1 and x_2');ylabel('y_1 and y_2');zlabel('z_1 and z_2');
set(gca,'XLim',minmax(X_x_plot(:)')+[-10,10]);
view([0,1,0]);
axis square
subplot(1,3,3);
plot3(X3_x_plot,X3_y_plot,X3_z_plot,'.b',Y3_x_plot,Y3_y_plot,Y3_z_plot,'.r',10.*x_plot(1,K3),20.*ones(size(K3)),20.*ones(size(K3)),'*k')
xlabel('displaced x_1 and x_2');ylabel('y_1 and y_2');zlabel('z_1 and z_2');
set(gca,'XLim',minmax(X_x_plot(:)')+[-10,10]);
view([0,0,1]);
axis square
