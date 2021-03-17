clearvars
close all

addpath func

%% test 1 with covariate and multivariate versions
% test whether the overlap of x(:,i) and y(:,i) is considered equal by t-test

% generating random data
x = random('normal',10,1,[1000,1]);
x_co = 15.*x + 10.*randn(size(x));
y = random('normal',10,1,[1000,1]);
y_co = 160-15.*y + 10.*randn(size(y));

[   tt.h,   tt.p,   tt.ci,   tt.stats,   tt.t,   tt.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both');
[tt_co.h,tt_co.p,tt_co.ci,tt_co.stats,tt_co.t,tt_co.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both','Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',x_co,'C1_y',y_co);
[ tt_m.h, tt_m.p, tt_m.ci, tt_m.stats, tt_m.t, tt_m.slm] = ttest.tTestSurfStat(cat(3,x,x_co),cat(3,y,y_co),'Alpha',0.05,'Tail','both');

ax1=subplot(1,2,1);
plot(ax1,ones(size(x)),x,'.b',1.2.*ones(size(y)),y,'.r');set(ax1,'XLim',[0.8,1.4],'XTick',[1,1.2],'XTickLabel',{'x','y'})
ylabel(ax1,'x,y')
ax2=subplot(1,2,2);
plot(ax2,x_co,x,'.b',y_co,y,'.r')
legend(ax2,{'x','y'},'location','northoutside')
xlabel(ax2,'x,y covariate')
ylabel(ax2,'x,y');
text(ax2,-90,15.5,sprintf('simple t-test: x and y are %s',get_txt_if(tt.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom');
text(ax2,-90,14.8,sprintf('t-test w/ cov: x and y are %s',get_txt_if(tt_co.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
text(ax2,-90,14.1,sprintf('mltvar t-test: x and y are %s',get_txt_if(tt_m.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
set([ax1,ax2],'YLim',[6,16])
ax2.XLim = [-100,250];
ax2.Position(3) = 1.1.*ax2.Position(3);
ax1.Position(3:4) = ax2.Position(3:4);

%% test 2 with covariate and multivariate versions
% test whether the overlap of x(:,i) and y(:,i) is considered equal by t-test

% generating random data
x = random('normal',10,1,[1000,1]);
x_co = 15.*x + 10.*randn(size(x));
y = random('normal',10,1,[1000,1]);
y_co = 20.*y + 10.*randn(size(y));

[   tt.h,   tt.p,   tt.ci,   tt.stats,   tt.t,   tt.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both');
[tt_co.h,tt_co.p,tt_co.ci,tt_co.stats,tt_co.t,tt_co.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both','Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',x_co,'C1_y',y_co);
[ tt_m.h, tt_m.p, tt_m.ci, tt_m.stats, tt_m.t, tt_m.slm] = ttest.tTestSurfStat(cat(3,x,x_co),cat(3,y,y_co),'Alpha',0.05,'Tail','both');

ax1=subplot(1,2,1);
plot(ax1,ones(size(x)),x,'.b',1.2.*ones(size(y)),y,'.r');
set(ax1,'XLim',[0.8,1.4],'XTick',[1,1.2],'XTickLabel',{'x','y'})
ylabel(ax1,'x,y')
ax2=subplot(1,2,2);
plot(ax2,x_co,x,'.b',y_co,y,'.r')
legend(ax2,{'x','y'},'location','northoutside')
xlabel(ax2,'x,y covariate')
ylabel(ax2,'x,y');
text(ax2,90,15.5,sprintf('simple t-test: x and y are %s',get_txt_if(tt.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom');
text(ax2,90,14.8,sprintf('t-test w/ cov: x and y are %s',get_txt_if(tt_co.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
text(ax2,90,14.1,sprintf('mltvar t-test: x and y are %s',get_txt_if(tt_m.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
set([ax1,ax2],'YLim',[6,16])
ax2.XLim = [80,280];
ax2.Position(3) = 1.1.*ax2.Position(3);
ax1.Position(3:4) = ax2.Position(3:4);

%% test 3 with covariate and multivariate versions
% test whether the overlap of x(:,i) and y(:,i) is considered equal by t-test
close all
% generating random data
x = random('normal',10,2,[1000,1]);
x_co = -100+ 10.*x + 5.*randn(size(x));
corrcoef(x,x_co)
y = random('normal',10,2,[1000,1]);
y_co = -100+10.*y+5.*randn(size(y));

[   tt.h,   tt.p,   tt.ci,   tt.stats,   tt.t,   tt.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both');
[tt_co.h,tt_co.p,tt_co.ci,tt_co.stats,tt_co.t,tt_co.slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both','Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',x_co,'C1_y',y_co);
[ tt_m.h, tt_m.p, tt_m.ci, tt_m.stats, tt_m.t, tt_m.slm] = ttest.tTestSurfStat(cat(3,x,x_co),cat(3,y,y_co),'Alpha',0.05,'Tail','both');

ax1=subplot(1,2,1);
plot(ax1,ones(size(x)),x,'.b',1.2.*ones(size(y)),y,'.r');
set(ax1,'XLim',[0.8,1.4],'XTick',[1,1.2],'XTickLabel',{'x','y'})
ylabel(ax1,'x,y')
ax2=subplot(1,2,2);
plot(ax2,x_co,x,'.b',y_co,y,'.r')
legend(ax2,{'x','y'},'location','northoutside')
xlabel(ax2,'x,y covariate')
ylabel(ax2,'x,y');
text(ax2,-40,15.5,sprintf('simple t-test: x and y are %s',get_txt_if(tt.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom');
text(ax2,-40,14.8,sprintf('t-test w/ cov: x and y are %s',get_txt_if(tt_co.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
text(ax2,-40,14.1,sprintf('mltvar t-test: x and y are %s',get_txt_if(tt_m.h>0,'diff','equal')  ),'HorizontalAlignment','left','VerticalAlignment','bottom')
% set([ax1,ax2],'YLim',[6,16])
% ax2.XLim = [80,280];
ax2.Position(3) = 1.1.*ax2.Position(3);
ax1.Position(3:4) = ax2.Position(3:4);

%% test 1
% test whether the overlap of x(:,i) and y(:,i) is considered equal by t-test

% generating random data
x = random('normal',10,1,[1000,1]);
x_co = 10.*x + 10.*randn(size(x));
x = repmat(x(:,1),1,20);
x_co = repmat(x_co(:,1),1,20);
y = random('normal',15,1,[1000,1]);
y_co = 10.*y + 10.*randn(size(y));
x_plot = ones(size(x));
for i = 2:20
    y(:,end+1)=y(:,1) - (i-1).*0.5;
    y_co(:,end+1)=y_co(:,1) - (i-1).*0.5;
    x_plot(:,i) = i;
end

[a.h,a.p,a.ci,a.stats,a.t,slm] = ttest.tTestSurfStat(x,y,'Alpha',0.05,'Tail','both','AlphaFDR',0.05,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',x_co,'C1_y',y_co);
%r.SAvgRS_CT_node(i) = ttest.ttest2Struct(cat(3,SnRc,SnSc),cat(3,SnRp,SnSp),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true);
%r.SAvgRS_HV_node(i) = ttest.ttest2Struct(cat(3,ScHV_in,ScHV_out),cat(3,SpHV_in,SpHV_out),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);

% a and b are equal structs

k_a = find(a.h); % finding the t-test differences between x and y within p < alpha range (alpha*100% of false positives)

plot(x_plot,x,'.b',x_plot+0.3,y,'.r',k_a,20.*ones(size(k_a)),'*k');
xlabel('comparison #')
ylabel('x and y values')
set(gca,'XLim',[0.7,(x_plot(1,end)+0.6)]);

figure('Position',[0,0,1000,780]);
for i = 1:size(x,2)
    subplot(4,5,i)
    t_res = {};
    if a.h
        t_res = {mean(x(:,i)),mean(x_co(:,i)),'*k'};
    end
    plot(x(:,i),x_co(:,i),'.b',y(:,i),y_co(:,i),'.r',t_res{:})
end

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
