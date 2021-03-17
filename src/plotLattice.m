function axh = plotLattice(L,x,seeds,mainTitle)

    [ii,jj]=ind2sub(L,seeds);
    [xx,yy]=meshgrid(1:(L+1),1:(L+1));
    %P = reshape(x(end,:),L,L);
    P = zeros(size(xx));
    P(1:L,1:L) = reshape(x,L,L);
    figure;
    sh = pcolor(xx,yy,P);set(gca,'YDir','Reverse');
    sh.EdgeColor = 'w';
    sh.EdgeAlpha = 0.5;
    hold on
    plot(jj+0.5,ii+0.5,'ok','MarkerFaceColor','w','MarkerSize',15);
    title(mainTitle)
    %figure;imagesc(P(1:L,1:L));
    %hold on
    %plot(jj,ii,'ok','MarkerFaceColor','w','MarkerSize',15)

end
