function [fh,axh] = plotBrain(r, x, times, mainTitle, saveFigs, fileNamePrefix, brainShadeAlpha, cMap, viewAngles,saveAnimation)
    if (nargin < 3) || isempty(times)
        times = 1:size(x,1);
    end
    if (nargin < 7) || isempty(brainShadeAlpha)
        brainShadeAlpha = 0;
    end
    if (nargin < 8) || isempty(cMap)
        cMap = [];
    end
    if (nargin < 9) || isempty(viewAngles)
        viewAngles = [0,90];
    end
    if (nargin < 10) || isempty(saveAnimation)
        saveAnimation = false;
    end
    if ~isempty(mainTitle)
        mainTitle = [mainTitle,'; '];
    end
    if saveAnimation
        [fh,axh] = plotBrain_animated(r, x, times, mainTitle, saveFigs, fileNamePrefix, brainShadeAlpha, cMap, viewAngles);
    else
        [fh,axh] = plotBrain_static(r, x, times, mainTitle, saveFigs, fileNamePrefix, brainShadeAlpha, cMap, viewAngles);
    end
end

function [fh,axh] = plotBrain_animated(r, x, times, ~, ~, fileNamePrefix, brainShadeAlpha, cMap, viewAngles)
    u = unique(x(end,:));
    numUniq = numel(u);
    if isempty(cMap)
        cMap = flipud(hot(numel(u)));
    end
    cLim = minmax(reshape(x(x~=0), 1, [] ));
    fh = figure;
    fh.Color = 'w';
    axh_bg = axes;
    axh_bg = setAllProperties(axh_bg,getAxAutoProperties(axh_bg),'manual');
    axis(axh_bg,'square');
    axh_bg.Position = [0,0,1,1];
    axh_bg_pos = axh_bg.Position;
    axh_bg.Colormap = cMap;
    axh_bg.CLim = cLim;
    axis(axh_bg,'off');
    xlabel(axh_bg,'x')
    ylabel(axh_bg,'y')
    if brainShadeAlpha
        plotBrainSurf(fh,axh_bg,[0.9,0.9,0.9],brainShadeAlpha,[],[],0,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)});
        %plotBrainSurf(fh(i),axh(i),@(x)[0.95,0.95,0.95],brainShadeAlpha);
    end
    hold(axh_bg,'on');
    plot3(axh_bg,r(:,1),r(:,2),r(:,3),'o','Color','k','MarkerFaceColor',[1,1,1],'MarkerSize',10);
    hold(axh_bg,'off');
    daspect(axh_bg,[1,1,1]);
    view(axh_bg,viewAngles);
    axh_bg = setAllProperties(axh_bg,getAxAutoProperties(axh_bg),'manual');
    axis(axh_bg,'off');
    axh_bg.PickableParts = 'none';
    
    axh = axes;
    axh = setAllProperties(axh,getAxAutoProperties(axh),'manual');
%     axis(axh,'square');
%     daspect(axh,[1,1,1]);
%     view(axh,viewAngles);
%     axh.Position = axh_bg_pos;
%     axh.Colormap = cMap;
%     axh.CLim = cLim;
%     axis(axh,'off');
%     axh.XLim = axh_bg.XLim;
%     axh.YLim = axh_bg.YLim;
%     axh.PickableParts = 'none';

    txt = annotation(fh,'textbox',[0.0156428571428571 0.932857142857143 0.284714285714286 0.0571428571428604],'String','t = 0000','LineStyle','none','FontSize',12,'FitBoxToText','off');

    mmX = minmax(x(:)');
    i = 0;
    
    % Initialize video
    vw = VideoWriter([fileNamePrefix,'_anim.mp4'], 'MPEG-4'); %open video file
    vw.Quality = 100;
    vw.FrameRate = 16;
    vw.open();
    
    for t = times
        i = 1 + i;
%         axh.NextPlot = 'add';
        ind = x(t,:) == 0;
        k = find(ind);
%         plot3(axh,r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',[1,1,1],'MarkerSize',10);
        gt0 = find(~ind); % ind of x > 0
        if numUniq < (numel(gt0)/5)
            for j = 1:numel(u)
                k = find(x(t,:) == u(j));
                plot3(axh,r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',getColor(u(j),cMap,mmX),'MarkerSize',10);
            end
        else
            for j = 1:numel(gt0)
                k = gt0(j);
                plot3(axh,r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',getColor(x(t,k),cMap,mmX),'MarkerSize',10);
            end
        end
%         axh.NextPlot = 'replace';
        axis(axh,'square');
        daspect(axh,[1,1,1]);
        view(axh,viewAngles);
        axh.Position = axh_bg_pos;
        axh.Colormap = cMap;
        axh.CLim = cLim;
        axis(axh,'off');
        axh.XLim = axh_bg.XLim;
        axh.YLim = axh_bg.YLim;
        axh.PickableParts = 'none';
        txt.String = sprintf('t = %d',t);

        pause(0.01);
        vframe = getframe(fh);
        vw.writeVideo(vframe);
    end
    
    vw.close();
end

function [fh,axh] = plotBrain_static(r, x, times, mainTitle, saveFigs, fileNamePrefix, brainShadeAlpha, cMap, viewAngles)
    u = unique(x(end,:));
    numUniq = numel(u);
    if isempty(cMap)
        cMap = flipud(hot(numel(u)));
    end
    cLim = minmax(reshape(x(x~=0), 1, [] ));
    fh = gobjects(1,numel(times));
    axh = gobjects(1,numel(times));
    mmX = minmax(x(:)');
    i = 0;
    for t = times
        i = 1 + i;
        fh(i) = figure;
        fh(i).Color = 'w';
        axh(i) = axes;
        if brainShadeAlpha
            plotBrainSurf(fh(i),axh(i),[0.9,0.9,0.9],brainShadeAlpha,[],[],0,{'LineWidth',2,'EdgeColor',0.8.*ones(1,3)});
            %plotBrainSurf(fh(i),axh(i),@(x)[0.95,0.95,0.95],brainShadeAlpha);
        end
        hold(axh(i),'on');
        ind = x(t,:) == 0;
        k = find(ind);
        plot3(r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',[1,1,1],'MarkerSize',10);
        gt0 = find(~ind); % ind of x > 0
        if numUniq < (numel(gt0)/5)
            for j = 1:numel(u)
                k = find(x(t,:) == u(j));
                plot3(r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',getColor(u(j),cMap,mmX),'MarkerSize',10);
            end
        else
            for j = 1:numel(gt0)
                k = gt0(j);
                plot3(r(k,1),r(k,2),r(k,3),'o','Color','k','MarkerFaceColor',getColor(x(t,k),cMap,mmX),'MarkerSize',10);
            end
        end
        axh(i).Colormap = cMap;
        axh(i).CLim = cLim;
        hold(axh(i),'off');
        axis(axh(i),'square');
        axis(axh(i),'off');
        daspect(axh(i),[1,1,1]);
        %view(axh(i),2);
        % view(axh(i),[90,0]);
        view(axh(i),viewAngles);
        xlabel('x')
        ylabel('y')
        title([mainTitle, 't=',num2str(t)]);
        if saveFigs
            saveas(fh(i), [fileNamePrefix,'_t',num2str(t)], 'png');
        end
    end
end

function s = getColor(xx, colorSet, mm)
    dy = size(colorSet,1)-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    k = floor(a.*xx+b)+1;
    if k < 1
        k = 1;
    end
    if k > size(colorSet,1)
        k = size(colorSet,1);
    end
    s = colorSet(k,:);
end

function p = getAxAutoProperties(ax)
    p = fieldnames(ax);
    p(cellfun(@(x)ischar(ax.(x)) && strcmpi(ax.(x),'auto'),fieldnames(ax)) ~= 1) = [];
end

function obj = setAllProperties(obj,p,value)
    c = cell(1,numel(p)*2);
    c(1:2:end)=p;
    c(2:2:end)={value};
    set(obj,c{:});
end