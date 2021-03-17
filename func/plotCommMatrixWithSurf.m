function [fh,axh,cb] = plotCommMatrixWithSurf(siDataStruct,thetaInd,ttestLabel,commLabels,tThresh,panelTitle,matrixView,showDataColor,effSizeLabel,useFDR,showCommSurf,showControlsOnly,showEffSizeDots)
    if (nargin < 11) || isempty(showCommSurf)
        showCommSurf = false;
    end
    if (nargin < 12) || isempty(showControlsOnly)
        showControlsOnly = false;
    end
    if (nargin < 13) || isempty(showEffSizeDots)
        showEffSizeDots = true;
    end
    fp = getDefaultFigureProperties();
    [fh,axh,~,~,~,cb,Eff,EffCensor] = plotCommMatrix(siDataStruct,thetaInd,ttestLabel,commLabels,tThresh,panelTitle,matrixView,showDataColor,effSizeLabel,useFDR,[0.25,0.27,0.5,0.5],showControlsOnly,showEffSizeDots);
    appendCBarLabel(cb,appendStr(strtrim(cellstr(num2str(siDataStruct.theta(thetaInd)'))'),[],', \theta='));
    fh.Children(end).XTickLabelRotation = -90;
    cb.Title.String = cb.Label.String;
    cb.Label.String = '';
    yTickLimParam = {};
%     xTickLimParam = {};
    if isnumeric(showDataColor) && (showDataColor == 2)
        set(cb,'Position', [0.2917 0.1234 0.4014 0.0178]);%, 'Limits', [-1.6,-0.4], 'Ticks', -1.6:0.4:0.4);
            cb.TickLabels{1} = 'slower in TLE';
        yTickLimParam = {'YLim',cb.Limits};%,'YTick',[-1.4,-0.8]};
%         xTickLimParam = {'XLim',cb.Limits,'XTick',[-1.4,-0.8]};
    end
    drawnow
    ax1 = axes('Position',[0.3117 0.7668 0.3752 0.0927],'Box','on','XLim',fh.Children(1).XLim,'XTick',1:(numel(commLabels)));
    ax1.XTickLabel = [];
    % Eff_u = triu(Eff);
    % Eff_u(tril(ones(size(Eff)),-1)==1)=NaN;
    if showControlsOnly
        ps1 = getPlotStruct({1:(numel(commLabels))}, {mean(Eff,1,'omitnan')}, {std(Eff,[],1,'omitnan')}, '', '$\bar{S}$', 'linear', 'linear', '', 0, false, '');
        ps2 = getPlotStruct({1:(numel(commLabels))}, {reshape(mean(Eff,2,'omitnan'),1,[])}, {reshape(std(Eff,[],2,'omitnan'),1,[])}, '$\bar{S}$', '', 'linear', 'linear', '', 0, true, '');
    else
        ps1 = getPlotStruct({1:(numel(commLabels))}, {mean(EffCensor,1,'omitnan')}, {std(EffCensor,[],1,'omitnan')}, '', '$\bar{d}$', 'linear', 'linear', '', 0, false, '');
        ps2 = getPlotStruct({1:(numel(commLabels))}, {reshape(mean(EffCensor,2,'omitnan'),1,[])}, {reshape(std(EffCensor,[],2,'omitnan'),1,[])}, '$\bar{d}$', '', 'linear', 'linear', '', 0, true, '');
    end
    plotPlotStruct(ax1, ps1, {':'}, 1, fp.pSymbols, fp.pColors(2,:), ...
        {'MarkerSize', 4, 'MarkerFaceColor', 'auto'},... % plot properties
        {'ShowErrorBar', 'on', 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties   % , 'XLim', minmax(VV), 'XTick', 0:3, 'YLim', [-0.05,1.05], 'YTick', [0,1]
        {'Location', 'best', 'FontSize', 8, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties    % , 'YDisplacement',[0.03,0,0],'XDisplacement',[0,0.03,0]
    set(ax1,'Position', [0.3130 0.7692 0.3730 0.0735], 'XColor','none','Box','off',yTickLimParam{:});
    plotHorizontalLines(ax1,-0.8,'LineStyle',':','Color','k','HandleVisibility','off','LineWidth',0.1);
    ax2 = axes('Position',[0.3117 0.7668 0.3752 0.0927],'Box','on','XLim',fh.Children(1).XLim,'XTick',1:(numel(commLabels)));
    plotPlotStruct(ax2, ps2, {':'}, 1, fp.pSymbols, fp.pColors(2,:), ...
        {'MarkerSize', 4, 'MarkerFaceColor', 'auto'},... % plot properties
        {'ShowErrorBar', 'on', 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
        {'Box', 'on', 'Layer', 'top'},... % axis properties   % , 'XLim', minmax(VV), 'XTick', 0:3, 'YLim', [-0.05,1.05], 'YTick', [0,1]
        {'Location', 'best', 'FontSize', 8, 'Box', 'off', 'Interpreter', 'latex'},... % legend properties
        {'FontSize', 12}); % label properties    % , 'YDisplacement',[0.03,0,0],'XDisplacement',[0,0.03,0]
    delete(legend(ax2));
    plotHorizontalLines(ax2,-0.8,'LineStyle',':','Color','k','HandleVisibility','off','LineWidth',0.1);
    ax2 = invertAxis(ax2,true);
    set(ax2, 'Position',[0.6887 0.2687 0.0582 0.5007],'Box','on','YLim',ax1.XLim,'YTick',ax1.XTick, 'YDir', 'reverse', ...
        'YTickLabel',[],'YColor','none','Box','off','XTickLabelRotation',-90,'XLim',ax1.YLim,'XTick',ax1.YTick);
    ax2.XLabel.Position = [0.3466 -0.1003 0];
    if showCommSurf
        x0 = 0.232;
        y0 = 0.67;
        axr = 0.3;
        aax1 = plot_community(commLabels{1},[1,0,0],fh,[x0,y0],axr);
        axh = [axh,aax1];
        drawnow
        dy = 0.08;
        for i = 2:numel(commLabels)
            y = y0 - (i-1).*dy;
            aax = plot_community(commLabels{i},[1,0,0],fh,[x0,y],0.3);
            axh = [axh,aax];
            drawnow
        end
        x0l = [0.252,0.268,0.252,0.268,0.268,0.268,0.286,0.286,0.286];
        y0l = 0.75;
        dyl = 0.058;
        y0 = 0.758;
        for i = 1:numel(commLabels)
            annotation(fh,'line',[(x0-0.1), x0],[(y0-(i-1).*dy), (y0-(i-1).*dy)]);
            annotation(fh,'line',[x0, x0l(i)],[(y0-(i-1).*dy), (y0l-(i-1).*dyl)]);
        end
        disp('*** done plotting matrix with surfaces');
    end
end