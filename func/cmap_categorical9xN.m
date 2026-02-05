function colors = cmap_categorical9xN(comm_labels, style)
% CATEGORICAL9XN  Group-aware categorical colors (9 groups, N items)
%
%   colors = categorical9xN(comm_labels)
%   colors = categorical9xN(comm_labels, style)
%
%   Inputs:
%       comm_labels : Nx1 or 1xN vector with integer labels in 1..9
%       style       : (optional) palette style
%                     'hsv'        - original vivid HSV palette
%                     'muted'      - Nature / Tableau-inspired (recommended)
%                     'colorblind' - Okabe–Ito inspired
%                     'subtle'     - low-contrast / grayscale-friendly
%
%   Output:
%       colors      : Nx3 RGB array
%
%   Notes:
%       - Same group ? same hue
%       - Different shades within group
%       - Order-preserving and deterministic

    if nargin < 2 || isempty(style)
        style = 'muted';
    end

    % Ensure column vector
    comm_labels = comm_labels(:);
    N = numel(comm_labels);

    if any(comm_labels < 1 | comm_labels > 9 | mod(comm_labels,1) ~= 0)
        error('categorical9xN:InvalidLabels', ...
              'comm_labels must contain integers in the range 1..9');
    end

    colors = zeros(N,3);

    switch lower(style)

        % -------------------------------------------------------------
        case 'hsv'   % Original vivid palette
        % -------------------------------------------------------------
            groupHues = [
                0.00  % red
                0.08  % orange
                0.16  % yellow
                0.33  % green
                0.50  % cyan
                0.58  % blue
                0.67  % indigo
                0.75  % purple
                0.90  % magenta
            ];

            for g = 1:9
                idx = find(comm_labels == g);
                ng  = numel(idx);
                if ng == 0, continue, end

                v = linspace(0.45, 0.90, ng);
                s = linspace(0.55, 0.90, ng);

                for k = 1:ng
                    colors(idx(k),:) = hsv2rgb([groupHues(g), s(k), v(k)]);
                end
            end

        % -------------------------------------------------------------
        case 'muted'   % Nature / Tableau-inspired (recommended)
        % -------------------------------------------------------------
            groupRGB = [
                0.80 0.23 0.23
                0.90 0.55 0.20
                0.90 0.80 0.30
                0.35 0.70 0.35
                0.30 0.75 0.70
                0.30 0.45 0.80
                0.45 0.35 0.75
                0.65 0.40 0.75
                0.85 0.35 0.55
            ];

            for g = 1:9
                idx = find(comm_labels == g);
                ng  = numel(idx);
                if ng == 0, continue, end

                t = linspace(0.0, 0.6, ng); % mix with white

                base = groupRGB(g,:);
                for k = 1:ng
                    colors(idx(k),:) = (1 - t(k)) * base + t(k) * [1 1 1];
                end
            end

        % -------------------------------------------------------------
        case 'colorblind'   % Okabe–Ito inspired
        % -------------------------------------------------------------
            groupRGB = [
                0.90 0.62 0.00
                0.35 0.70 0.90
                0.00 0.60 0.50
                0.95 0.90 0.25
                0.00 0.45 0.70
                0.80 0.40 0.00
                0.80 0.60 0.70
                0.40 0.40 0.40
                0.20 0.20 0.20
            ];

            for g = 1:9
                idx = find(comm_labels == g);
                ng  = numel(idx);
                if ng == 0, continue, end

                t = linspace(0.0, 0.6, ng);
                base = groupRGB(g,:);
                for k = 1:ng
                    colors(idx(k),:) = (1 - t(k)) * base + t(k) * [1 1 1];
                end
            end

        % -------------------------------------------------------------
        case 'subtle'   % Low-contrast / grayscale-friendly
        % -------------------------------------------------------------
            groupRGB = [
                0.30 0.30 0.30
                0.45 0.45 0.45
                0.60 0.60 0.60
                0.35 0.45 0.55
                0.45 0.55 0.45
                0.55 0.45 0.35
                0.55 0.35 0.45
                0.40 0.40 0.55
                0.55 0.55 0.40
            ];

            for g = 1:9
                idx = find(comm_labels == g);
                ng  = numel(idx);
                if ng == 0, continue, end

                t = linspace(0.0, 0.5, ng);
                base = groupRGB(g,:);
                for k = 1:ng
                    colors(idx(k),:) = (1 - t(k)) * base + t(k) * [1 1 1];
                end
            end

        % -------------------------------------------------------------
        otherwise
            error('categorical9xN:UnknownStyle', ...
                  'Unknown style "%s"', style);
    end
end
