function files = getAdjMatrixFiles(inputPattern)
    if nargin < 1 || isempty(inputPattern)
        dataDir = 'D:\Dropbox\p\postdoc\data';
        if isunix
            dataDir = '/host/scarus/local_raid/mauricio/data';
        end
        inputPattern = fullfile(dataDir,'AALmatrix_N90','TLE*_FA_*.mat');
    end
    [d,~,~] = fileparts(inputPattern);
    f = dir(inputPattern);
    files = cell(size(f));
    for i = 1:numel(f)
        files{i} = [ d, filesep, f(i).name ];
    end
end
