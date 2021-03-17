function lh = plotVerticalLines(axh,x,varargin)
    if isempty(axh)
        axh = axes;
    end
%     [lineStyle,args] = getParamValue('LineStyle',varargin,true);
%     [lineColor,args] = getParamValue('Color',args,true);
%     [lineWidth,args] = getParamValue('LineWidth',args,true);
%     if ~isempty(lineStyle)
%         if ~iscell(lineStyle)
%             lineStyle = 
%         end
%     end
%     if ~isempty(lineColor)
%         if ~iscell(lineColor)
%         end
%     end
%     if ~isempty(lineWidth)
%         if ~iscell(lineWidth)
%         end
%     end
    lh = gobjects(numel(x),1);
    hold(axh,'on')
    for i = 1:numel(x)
        if isnan(x(i))
            continue;
        end
%         line(axh, [x(i),x(i)], axh.YLim, 'LineStyle', lineStyle{i}, 'Color', lineColor{i}, 'LineWidth', lineWidth{i}, args{:});
        lh(i) = line(axh,[x(i),x(i)], axh.YLim, varargin{:});
    end
    hold(axh,'off')
end

% function [v,c] = getParamValue(par,c,del)
%     if (nargin < 3) || isempty(del)
%         del = false;
%     end
%     k = find(strcmpi(c,par));
%     if isempty(k)
%         v = [];
%         return;
%     end
%     if k == numel(c)
%         error(['missing parameter value for ', par]);
%     end
%     v = c{k+1};
%     if del
%         c(k:(k+1)) = [];
%     end
% end
