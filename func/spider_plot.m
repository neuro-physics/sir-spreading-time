function [lh,sdh,sdlh1,sdlh2,ltrend,lfdr] = spider_plot(P, PSD, P_labels, axes_interval, plotArgs, sdPlotArgs, radLabArgs, axLabelArgs, hTrend, hFDR, trendFDRSymbols,dr,dTheta)
% Create a spider web or radar plot
%
% spider_plot(P, P_labels, axes_interval) creates a spider web plot using
% the points specified in the array P. The column of P contains the data 
% points and the rows of P contain the multiple sets of data points.
% Each point must be accompanied by a label specified in the cell
% P_labels. The number of intervals that separate the axes is specified
% by axes_interval.
% 
% P - [vector | matrix]
% P_labels - [cell of strings]
% axes_interval - [integer]
%
% spider_plot(P, P_labels, axes_interval, line_spec) works the same as
% the function above. Additional line properties can be added in the 
% same format as the default plot function in MATLAB.
%
% line_spec - [character vector]
%
%
% %%%%%%%%%%%%%%%%%%% Example of a Generic Spider Plot %%%%%%%%%%%%%%%%%%%
% % Clear workspace
% close all;
% clearvars;
% clc;
% 
% % Point properties
% num_of_points = 6;
% row_of_points = 4;
% P = rand(row_of_points, num_of_rows);
% 
% % Create generic labels
% P_labels = cell(num_of_points, 1);
% 
% for ii = 1:num_of_points
%     P_labels{ii} = sprintf('Label %i', ii);
% end
% 
% % Figure properties
% figure('units', 'normalized', 'outerposition', [0 0.05 1 0.95]);
% 
% % Axes interval
% axes_interval = 4;
% 
% % Spider plot
% spider_plot(P, P_labels, axes_interval,...
%     'Marker', 'o',...
%     'LineStyle', '-',...
%     'LineWidth', 2,...
%     'MarkerSize', 5);
% 
% % Title properties
% title('Sample Spider Plot',...
%     'Fontweight', 'bold',...
%     'FontSize', 12);
% 
% % Legend properties
% legend('show', 'Location', 'southoutside');
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%% Point Properties %%%
    % Number of points
    [num_points,num_of_rows] = size(P);

    if (nargin < 2) || isempty(PSD)
        PSD = [];
    end
    if (nargin < 3) || isempty(P_labels)
        P_labels = cellfun(@(x)num2str(x),num2cell(1:num_points),'UniformOutput',false);
    end
    if (nargin < 4) || isempty(axes_interval)
        axes_interval = 4;
    end
    if (nargin < 5) || isempty(plotArgs)
        plotArgs = {};
    end
    if (nargin < 6) || isempty(sdPlotArgs)
        sdPlotArgs = {};
    end
    if (nargin < 7) || isempty(radLabArgs)
        radLabArgs = {};
    end
    if (nargin < 8) || isempty(axLabelArgs)
        axLabelArgs = {};
    end
    if (nargin < 9) || isempty(hTrend)
        hTrend = [];
    end
    if (nargin < 10) || isempty(hFDR)
        hFDR = [];
    end
    if (nargin < 11) || isempty(trendFDRSymbols)
        trendFDRSymbols = '+*';
    end
    if (nargin < 12) || isempty(dr)
        dr = 0.1;
    end
    if (nargin < 13) || isempty(dTheta)
        dTheta = 5 * pi / 180;
    end

    %%% Polar Axes %%%
    % Polar increments
    % polar_increments = 2*pi/num_points;
    if isempty(PSD)
        hasSD = false;
        PSD = zeros(size(P));
    else
        hasSD = true;
        PSD = abs(PSD);
    end
    if isempty(hTrend)
        hasTrend = false;
        hTrend = NaN(size(P));
    else
        hasTrend = true;
        hTrend = hTrend.*P;
        hTrend(hTrend == 0) = NaN;
    end
    if isempty(hFDR)
        hasFDR = false;
        hFDR = NaN(size(P));
    else
        hasFDR = true;
        hFDR = hFDR.*P;
        hFDR(hFDR == 0) = NaN;
        if hasTrend
            dTheta = dTheta / 2;
        end
    end
    
    % Calculate max limit of axes
    max_value = max(max(P+PSD));
    min_value = min(min(P-PSD));
    axes_limit = [floor(min_value*10)/10,(ceil(max_value*10)/10)];

    % Polar points
    % radius = [0; axes_limit];
    % theta = 0:polar_increments:2*pi;
    % theta = theta + pi/numel(theta);
    theta = linspace(0,2*pi,num_points+1) + pi/num_points;

    % Iterate through all the line handles
    % for ii = 1:length(h)
        % Remove polar axes from legend
        %h(ii).Annotation.LegendInformation.IconDisplayStyle = 'off';
    % end

    %%% Polar Isocurves %%%
    % Incremental radius
    %radius = (axes_limit(1):diff(axes_limit)/axes_interval:axes_limit(2))';
    radius = linspace(0,1,axes_interval+1)';

    % Convert polar to cartesian coordinates
    [x_isocurves, y_isocurves] = getCircles([0,0], radius);

    % Plot polar isocurves
    axh = gca;
    hold(axh,'on');
    % h = plot(x_isocurves', y_isocurves','--',...
    bgh = fill(axh,x_isocurves(:,end),y_isocurves(:,end),[1,1,1],'EdgeColor',0.7.*ones(1,3),'HandleVisibility','off');
    % hold(gca,'on');

    h = plot(axh,x_isocurves(:,1:(end-1)), y_isocurves(:,1:(end-1)),':',...
        'LineWidth', 1,...
        'Color', 0.7.*ones(1,3),...
        'HandleVisibility','off');

    % Convert polar to cartesian coordinates
    [x_axes, y_axes] = pol2cartvect(theta, radius);

    % Plot polar axes
    % grey = [1, 1, 1] * 0.5;
    h = line(axh,x_axes, y_axes,...
        'LineWidth', 1,...
        'Color', 0.7.*ones(1,3),...
        'HandleVisibility','off');

    % Iterate through all the plot handles
    % for ii = 1:length(h)
        % Remove polar isocurves from legend
        %h(ii).Annotation.LegendInformation.IconDisplayStyle = 'off';
    % end

    axFontSize = 12;
    if ~isempty(axLabelArgs)
        [axFontSize,axLabelArgs] = getParamValue('FontSize',axLabelArgs,true);
        if isempty(axFontSize)
            axFontSize = 12;
        end
    end
    tickFontSize = 12;
    if ~isempty(radLabArgs)
        [tickFontSize,radLabArgs] = getParamValue('FontSize',radLabArgs,true);
        if isempty(tickFontSize)
            tickFontSize = 12;
        end
    end
    sdLineSt = [];
    if ~isempty(sdPlotArgs)
        [sdLineSt,sdPlotArgs] = getParamValue('LineStyle',sdPlotArgs,true);
        if strcmpi(sdLineSt,'none')
            sdLineSt = [];
        end
        [sdLineCol,sdPlotArgs] = getParamValue('LineColor',sdPlotArgs,true);
        if isempty(sdLineCol)
            sdLineCol = 'auto';
        end
        [sdLineWd,sdPlotArgs] = getParamValue('LineWidth',sdPlotArgs,true);
        if isempty(sdLineWd)
            sdLineWd = 1;
        end
    end

    %%% Data Points %%%
    % Iterate through all the rows
    lh = gobjects(num_of_rows,1);
    sdh = gobjects(num_of_rows,1);
    ltrend = gobjects(num_of_rows,1);
    lfdr = gobjects(num_of_rows,1);
%     if (nargout > 2) && ~isempty(sdLineSt)
    sdlh1 = gobjects(num_of_rows,1);
    sdlh2 = gobjects(num_of_rows,1);
%     end
%     axh = gca;
    axh.ColorOrderIndex = 1;
    axh.LineStyleOrderIndex = 1;
    for ii = 1:num_of_rows
        % Convert polar to cartesian coordinates
        PP = P(:,ii)';
        [x_points, y_points] = pol2cartvect(theta(1:(end-1)), linearTransf(PP,axes_limit,[0,1]));
        % Make points circular
        x_points(end+1) = x_points(1);
        y_points(end+1) = y_points(1);
        % Plot data points
        lh(ii) = plot(axh,x_points, y_points, plotArgs{:});
        colorOrderIndex = axh.ColorOrderIndex;
        lsOrderIndex = axh.LineStyleOrderIndex;
        
        if hasTrend
            rt = linearTransf(hTrend(:,ii)'+dr,axes_limit,[0,1]);
            [xt, yt] = pol2cartvect(theta(1:(end-1))+dTheta./rt, rt);
            xt(end+1) = xt(1); yt(end+1) = yt(1);
            ltrend(ii) = plot(axh,xt,yt,'LineStyle','none','MarkerSize',4,'MarkerFaceColor',lh(ii).Color,'HandleVisibility','off','Marker',trendFDRSymbols(1));
            axh.ColorOrderIndex = colorOrderIndex;
            axh.LineStyleOrderIndex = lsOrderIndex;
        end
        if hasFDR
            rt = linearTransf(hFDR(:,ii)'+dr,axes_limit,[0,1]);
            [xt, yt] = pol2cartvect(theta(1:(end-1))-dTheta./rt, rt);
            xt(end+1) = xt(1); yt(end+1) = yt(1);
            lfdr(ii) = plot(axh,xt,yt,'LineStyle','none','MarkerSize',4,'MarkerFaceColor',lh(ii).Color,'HandleVisibility','off','Marker',trendFDRSymbols(2));
            axh.ColorOrderIndex = colorOrderIndex;
            axh.LineStyleOrderIndex = lsOrderIndex;
        end

        if hasSD
            SS = PSD(:,ii)';
            [xsd1, ysd1] = pol2cartvect(theta(1:(end-1)), linearTransf(PP+SS,axes_limit,[0,1]));
            [xsd0, ysd0] = pol2cartvect(theta(1:(end-1)), linearTransf(PP-SS,axes_limit,[0,1]));
            xsd1(end+1) = xsd1(1);
            ysd1(end+1) = ysd1(1);
            xsd0(end+1) = xsd0(1);
            ysd0(end+1) = ysd0(1);
            xsd = [xsd1(:);xsd0(:)];
            ysd = [ysd1(:);ysd0(:)];
            sdh(ii) = fill(axh, xsd, ysd, lh(ii).Color, 'LineStyle', 'none', 'FaceAlpha', 0.2, 'HandleVisibility', 'off', sdPlotArgs{:});
            if ~isempty(sdLineSt)
                if strcmpi(sdLineCol,'auto')
                    slc = lh(ii).Color;
                else
                    slc = sdLineCol;
                end
                lhtemp1 = line(axh,xsd0,ysd0,'LineStyle',sdLineSt,'Color',slc,'LineWidth',sdLineWd,'HandleVisibility','off');
                lhtemp2 = line(axh,xsd1,ysd1,'LineStyle',sdLineSt,'Color',slc,'LineWidth',sdLineWd,'HandleVisibility','off');
                if nargout > 2
                    sdlh1(ii) = lhtemp1;
                    sdlh2(ii) = lhtemp2;
                end
            end
            axh.ColorOrderIndex = colorOrderIndex;
            axh.LineStyleOrderIndex = lsOrderIndex;
        end
    end

    %%% Axis Properties %%%
    % Figure background
    % fig = gcf;
    % fig.Color = 'white';

    % Iterate through the isocurve radius
    radLabel = linearTransf(radius,[0,1],axes_limit);
    c45 = cos(pi/4);
    s45 = sin(pi/4);
    for ii = 1:length(radius)
        % Display axis text for each isocurve
        %text(x_isocurves(ii, 1), 0, sprintf('%3.1f', radius(ii)),...
        %text(x_isocurves(1,ii), 0, sprintf('%3.2g', radLabel(ii)),... % writing axis labels on theta=0 (horizontally)
        text(axh,c45*radius(ii), s45*radius(ii), sprintf('%3.2g', radLabel(ii)),... % writing axis labels on theta=pi/4; (45 deg)
            'Units', 'Data',...
            'Color', 'black',...
            'FontSize', tickFontSize,...
            'HorizontalAlignment', 'center',...
            'VerticalAlignment', 'middle', radLabArgs{:});
    end

    % Label points
    [x_c, y_c] = pol2cartvect(theta, radius);
    x_label = x_c(end, :);
    y_label = y_c(end, :);
    % x_label = x_isocurves(:,end)';
    % y_label = y_isocurves(:,end)';

    % Check if labels equals the number of points
    if length(P_labels) == num_points
        % Iterate through each label
        for ii = 1:num_points
            % Angle of point in radians
            theta_point = theta(ii);

            % Find out which quadrant the point is in
            if theta_point == 0
                quadrant = 0;
            elseif theta_point == pi/2
                quadrant = 1.5;
            elseif theta_point == pi
                quadrant = 2.5;
            elseif theta_point == 3*pi/2
                quadrant = 3.5;
            elseif theta_point == 2*pi
                quadrant = 0;
            elseif theta_point > 0 && theta_point < pi/2
                quadrant = 1;
            elseif theta_point > pi/2 && theta_point < pi
                quadrant = 2;
            elseif theta_point > pi && theta_point < 3*pi/2
                quadrant = 3;
            elseif theta_point > 3*pi/2 && theta_point < 2*pi
                quadrant = 4;
            end

            % Adjust text alignment information depending on quadrant
            switch quadrant
                case 0
                    horz_align = 'left';
                    vert_align = 'middle';
                case 1
                    horz_align = 'left';
                    vert_align = 'bottom';
                case 1.5
                    horz_align = 'center';
                    vert_align = 'bottom';
                case 2
                    horz_align = 'right';
                    vert_align = 'bottom';
                case 2.5
                    horz_align = 'right';
                    vert_align = 'middle';
                case 3
                    horz_align = 'right';
                    vert_align = 'top';
                case 3.5
                    horz_align = 'center';
                    vert_align = 'top';
                case 4
                    horz_align = 'left';
                    vert_align = 'top';
            end

            % Display text label
            text(axh, x_label(ii), y_label(ii), P_labels{ii},...
                'Units', 'Data',...
                'HorizontalAlignment', horz_align,...
                'VerticalAlignment', vert_align,...
                'EdgeColor', 'none',...
                'FontSize', axFontSize,...
                'BackgroundColor', 'none', axLabelArgs{:});
        end
    else
        % Error message
        error('Error: Please make sure the number of labels is the same as the number of points.');
    end

    % Axis limits
    axis(axh,'square');
    axis(axh,'tight');
    %axis([-axes_limit(2), axes_limit(2), -axes_limit(2), axes_limit(2)]);
    axis(axh,[-1, 1, -1, 1]);
    axis(axh,'off');
    if hasSD
        uistack(flipud(sdh),'top');
        uistack(flipud(lh),'top');
    end
end

function [x,y] = getCircles(c,r)
    n = ceil(10 * max(r(:)) * 2 * pi); % 10 points per unit arch
    x = zeros(n,numel(r));
    y = zeros(size(x));
    theta = linspace(0,2*pi,n);
    ct = cos(theta(:));
    st = sin(theta(:));
    for i = 1:numel(r)
        x(:,i) = r(i) .* ct + c(1);
        y(:,i) = r(i) .* st + c(2);
    end
end

function [x,y,z] = pol2cartvect(th,r,z) 
    if size(th,1) == size(r,1) && size(th,2) == size(r,2) 
        x = r.*cos(th); y = r.*sin(th); 
    else
        x = r*cos(th); y = r*sin(th); 
    end
end

function [v,parList] = getParamValue(parName,parList,delParFromList)
    if (nargin < 3) || isempty(delParFromList)
        delParFromList = false;
    end
    k = find(strcmpi(parList,parName));
    if isempty(k)
        v = [];
        return;
    end
    if k == numel(parList)
        error(['missing parameter value for ', parName]);
    end
    v = parList{k+1};
    if delParFromList
        parList(k:(k+1)) = [];
    end
end

function Y = linearTransf(X,xLim,yLim)
    if (nargin < 2) || isempty(xLim)
        xLim = minmax(X(:)');
    end
    b = diff(yLim) / diff(xLim);
    a = yLim(1) - b * xLim(1);
    Y = a + b.*X;
end