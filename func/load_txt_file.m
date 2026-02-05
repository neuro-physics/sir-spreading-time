function X = load_txt_file(fname)
% LOAD_TXT_FILE  Load space-separated numeric data with 3 '#' header lines
%
%   Columns -> variables
%   Rows    -> time samples

    opts = detectImportOptions(fname, ...
        'FileType', 'text', ...
        'Delimiter', ' ', ...
        'CommentStyle', '#');

    % Skip the first 3 header lines
    opts.DataLines = [4 Inf];

    X = readmatrix(fname, opts);
end
