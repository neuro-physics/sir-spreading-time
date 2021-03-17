function select_case_matrices(inpDir,matFilePtrn,casesMetaDataFile,cpCmd,outputDir)
    if (nargin < 2) || isempty(matFilePtrn)
        matFilePtrn = 'TLE_*_FA_*.mat';
    end
    if (nargin < 3) || isempty(casesMetaDataFile)
        casesMetaDataFile = 'TLE_NB_BB.mat';
    end
    if (nargin < 4) || isempty(cpCmd)
        cpCmd = @copyfile;
    end
    if (nargin < 5) || isempty(outputDir)
        outputDir = 'selected';
    end
    addpath('func')
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end

    % inpDir = 'D:\Dropbox\p\postdoc\data\AALmatrix_N90';

    cdb=load(fullfile(dataDir,casesMetaDataFile));

    [~,selectedCases] = getPatientIndex(cdb.casesMetaData, 'UseForSpSim', {1}, 'AND');

    ffn = dir(fullfile(inpDir,matFilePtrn));

    if exist(fullfile(inpDir,outputDir),'dir')~=7
        mkdir(fullfile(inpDir,outputDir));
    end

    for i = 1:numel(ffn)
        c = getCaseName(ffn(i).name);
        disp(c);
        if containsCase(selectedCases,c)
            cpCmd(fullfile(inpDir,ffn(i).name),fullfile(inpDir,outputDir,ffn(i).name));
        end
    end

    codes = getCaseName({ffn(:).name});
    missingCases = setdiff(selectedCases,codes);
    disp('missing cases:');
    disp(missingCases);
end
