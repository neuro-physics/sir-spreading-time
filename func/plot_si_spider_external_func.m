function [fh,axh] = plot_si_spider_external_func(fh,axh,s,dataLabel,dataInd,axLabel,plotLabel)
    if (nargin < 1) || isempty(fh)
        fh = figure;
    else
        figure(fh);
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    else
        axes(axh);
    end
    
    if isstruct(s)
        sControl = s.controlData.(dataLabel){dataInd}(:)';
        sPatient = s.patientData.(dataLabel){dataInd}(:)';
        sTTestH = s.ttest.(dataLabel)(dataInd).h == 1;
        sTTestHFDR = s.ttest.(dataLabel)(dataInd).hFDR == 1;
    elseif iscell(s)
        sControl = s{1}(:)';
        sPatient = s{2}(:)';
        sTTestH = [];
        sTTestHFDR = [];
    else
        error('unsupported data type');
    end

    P = [sControl;...
         sPatient];
    P = P';

    axLabel(sTTestH) = appendStr(axLabel(sTTestH),'','*');
    axLabel(sTTestHFDR) = appendStr(axLabel(sTTestHFDR),'','*');
    %axLim = repmat(minmax(P(:)'),size(P,1),1);
    axLim = minmax(P(:)');
    spider_plot_seok(P,plotLabel,axLim,axLabel,{'Controls','TLE'},fh);

%     axes_interval = 2;
% 
%     % Spider plot
%     spider_plot(P, axLabel, axes_interval,...
%     'Marker', 'o',...
%     'LineStyle', '-',...
%     'LineWidth', 2,...
%     'MarkerSize', 5);
% 
%     % Title properties
%     title(plotLabel, 'FontWeight', 'normal', 'FontSize', 12);
% 
%     % Legend properties
%     legend({'Controls', 'TLE'}, 'Location', 'southoutside', 'Box', 'off');
end
