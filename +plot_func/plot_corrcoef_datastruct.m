function [fh,axh,lh,tt] = plot_corrcoef_datastruct(xLabel,yLabel,yLim,p_thresh,r_c_specific,p_c_specific,r_c,p_c,r_p_specific,p_p_specific,r_p,p_p,theta,controlPatientSymbols,lineColorSet,plotArgs,controlPatientLegend,errFaceAlpha,axh,yValueForSignificantDiff)
%     if (nargin < 14) || isempty(controlArgs)
%         controlArgs = {};
%     end
%     if (nargin < 15) || isempty(patientArgs)
%         patientArgs = {};
%     end
    if (nargin < 14) || isempty(controlPatientSymbols)
        controlPatientSymbols = 'o';
    end
    if (nargin < 15) || isempty(lineColorSet)
        all_lc = lines(5);
        lineColorSet = all_lc(5:-1:4,:);
    end
    if (nargin < 16) || isempty(plotArgs)
        plotArgs = {};
    end
    if (nargin < 17) || isempty(controlPatientLegend)
        controlPatientLegend = {'Controls','Patients'};
    end
    if (nargin < 18) || isempty(errFaceAlpha)
        errFaceAlpha = 0.1;
    end
    
    % number of points
    n_points = numel(theta);
    
    if (nargin < 19) || isempty(axh)
        if n_points > 1
            fh = figure;
            axh = axes;
        end
    else
        if n_points > 1
            fh = gcf;
        end
    end
    if (nargin < 20) || isempty(yValueForSignificantDiff)
        yValueForSignificantDiff = 0.38;
    end
    p_c_specific = max(p_c_specific,[],1);
    p_p_specific = max(p_p_specific,[],1);
    if isscalar(yValueForSignificantDiff)
        yValueForSignificantDiff_c = yValueForSignificantDiff;
        yValueForSignificantDiff_p = yValueForSignificantDiff-0.05;
        yValueForSignificantDiff_R = yValueForSignificantDiff-0.02;
    else
        yValueForSignificantDiff = repeatToComplete(yValueForSignificantDiff,3);
        yValueForSignificantDiff_c = yValueForSignificantDiff(1);
        yValueForSignificantDiff_p = yValueForSignificantDiff(2);
        yValueForSignificantDiff_R = yValueForSignificantDiff(3);
    end

    tt = ttest.ttest2Struct(r_c_specific,r_p_specific,'Alpha',p_thresh,'AlphaFDR',p_thresh);

    if n_points > 1
        hold(axh,'on');
        %lh = gobjects(1,2);
    
        ps = getPlotStruct({theta,theta},...
            {mean(r_c_specific,1,'omitnan'),mean(r_p_specific,1,'omitnan')},...
            {std(r_c_specific,[],1,'omitnan'),std(r_p_specific,[],1,'omitnan')},...
            xLabel, yLabel, 'linear', 'linear', '', controlPatientLegend, 1, '');

        %plotArgs = ['MarkerSize',4,plotArgs];
        [fh,axh,lh]=plotPlotStruct(axh, ps, {'--','-.'}, 1, controlPatientSymbols, lineColorSet, ...
            plotArgs,... % plot properties
            {'ShowErrorBar', 'on', 'Fill','on','LineStyle','none','LineSpec', '-', 'LineWidth', 0.1, 'Color', 'auto', 'FaceAlpha', errFaceAlpha},... % error properties
            {},... % axis properties
            {'Location', 'best', 'FontSize', 9, 'Box', 'off', 'Interpreter', 'tex'},... % legend properties
            {'Interpreter', 'tex', 'FontSize', 14}); % label properties
    
        %lh(1) = errorbar(theta,mean(r_c_specific,1,'omitnan'),std(r_c_specific,[],1,'omitnan'),'--o', 'LineWidth', 1, 'Color', lc(1,:), 'MarkerFaceColor', lc(1,:),controlArgs{:});
        %lh(2) = errorbar(theta,mean(r_p_specific,1,'omitnan'),std(r_p_specific,[],1,'omitnan'),'--o', 'LineWidth', 1, 'Color', lc(2,:), 'MarkerFaceColor', lc(2,:),patientArgs{:});
        
        %%% the average data is for correlations between averages of groups, not between the specific matrix sp time data per se
        % plot(theta,r_c,':s','Color',lc(1,:))
        % plot(theta,r_p,':s','Color',lc(2,:))
        xlabel(xLabel);ylabel(yLabel);
        %legend({'Controls','TLE'});%legend({'Controls specific','TLE specific', 'Controls avg', 'TLE avg'});
        if any(p_c_specific<p_thresh)
            yy = yValueForSignificantDiff_c.*ones(size(theta));
            text(theta(p_c_specific<p_thresh),yy(p_c_specific<p_thresh),'$\dagger$C','Interpreter','latex','FontSize',12,'VerticalAlignment','middle','HorizontalAlignment','center','Color',lineColorSet(1,:))
        end
        if any(p_p_specific<p_thresh)
            yy = yValueForSignificantDiff_p.*ones(size(theta));
            text(theta(p_p_specific<p_thresh),yy(p_p_specific<p_thresh),'$\dagger$P','Interpreter','latex','FontSize',12,'VerticalAlignment','middle','HorizontalAlignment','center','Color',lineColorSet(1,:))
        end
        if any(tt.h>0)
            yy = yValueForSignificantDiff_R.*ones(size(theta));
            text(theta(tt.h>0),yy(tt.h>0),'*','FontSize',16,'VerticalAlignment','middle','HorizontalAlignment','center')
        else
            disp(['no signficant difference between R in Controls and TLE [',yLabel,']'])
        end
        set(gca,'YLim',yLim);
    else
        lh = gobjects;
        [fh,axh] = plotAvgVsThetaScatterPanels({{yLabel}},r_c_specific,r_p_specific,[],[],tt.h,[],[],'R values',{'Controls','TLE'});
    end
end