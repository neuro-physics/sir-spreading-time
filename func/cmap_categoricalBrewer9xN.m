function colors = cmap_categoricalBrewer9xN(comm_labels, colorScheme, randColors)
% CATEGORICALBREWER9XN
% Assigns ColorBrewer-style colors to N points in 9 groups
%
% Each group gets its own interpolated Brewer ramp.
%
% Inputs:
%   comm_labels  : Nx1 vector with values 1..9
%   colorScheme  : passed to brewerCMap (default = 2)
%   randColors   : shuffle colors within each group (default = false)
%
% Output:
%   colors       : Nx3 RGB array

    if nargin < 2 || isempty(colorScheme)
        colorScheme = 2;
    end
    if nargin < 3 || isempty(randColors)
        randColors = false;
    end

    comm_labels = comm_labels(:);
    N = numel(comm_labels);

    if any(comm_labels < 1 | comm_labels > 9 | mod(comm_labels,1) ~= 0)
        error('categoricalBrewer9xN:InvalidLabels', ...
              'comm_labels must be integers in the range 1..9');
    end

    colors = zeros(N,3);

    % Use different offsets into the same Brewer ramp
    % to avoid identical colors across groups
    baseOffsets = linspace(0, 0.6, 9);

    for g = 1:9
        idx = find(comm_labels == g);
        ng  = numel(idx);
        if ng == 0
            continue
        end

        % Oversample Brewer ramp and select a window
        cmap = brewerCMap(ng + 10, colorScheme, false);

        offset = round(baseOffsets(g) * size(cmap,1));
        sel = (1:ng) + offset;
        sel(sel > size(cmap,1)) = size(cmap,1);

        cg = cmap(sel,:);

        if randColors
            cg = cg(randperm(ng),:);
        end

        colors(idx,:) = cg;
    end
end
