function A = flip_AAL_matrices(inp,flipSide,outputDir,aal,casesMetaData)
    dataDir = 'D:/Dropbox/p/postdoc/data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end

    if (nargin < 2) || isempty(flipSide)
        flipSide = 'R'; % 'L' or 'R'
    end
    if (nargin < 3) || isempty(outputDir)
        outputDir = '';
    end
    if (nargin < 4) || isempty(aal)
        %aal = load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
        [~,~,~,aal] = aalsurfview(zeros(90,1));
    end
    if (nargin < 5) || isempty(casesMetaData)
        casesMetaData = load(fullfile(dataDir,'TLE_NB_BB.mat'));
        casesMetaData = casesMetaData.casesMetaData;
    end
    if (flipSide ~= 'R') && (flipSide ~= 'L')
        error('flip_AAL_matrices:flipSide','flipSide has to be either R or L');
    end
    f = [];
    inpDir = [];
    [~,fCases] = getPatientIndex(casesMetaData, 'Group', {[flipSide,'TLE']});
    if isstruct(inp)
        f = inp;
        inpDir = '';
    elseif exist(inp, 'dir') == 7
        if inp(end) ~= filesep
            inp(end+1) = filesep;
        end
        inpDir = inp;
        inp = [inp,'*.mat'];
        f = dir(inp);
    elseif exist(inp, 'file') == 2
        A = flipAALMat_internal(inp,aal,outputDir,fCases);
        return;
    elseif ischar(inp)
        f = dir(inp);
        [inpDir,~,~]=fileparts(inp);
        inpDir(end+1) = filesep;
    else
        error('flip_AAL_matrices:inp','unrecognized input type');
    end
    if isempty(outputDir)
        outputDir = inpDir;
    end
%     cn = getCaseName(f);
    n = numel(f);
    A = cell(1,n);
    for i = 1:n
        A{i} = flipAALMat_internal(fullfile(inpDir,f(i).name),aal,outputDir,fCases);
    end
end

function matrix = flipAALMat_internal(fname,aal,outputDir,fCases)
    d = load(fname);
    [inpDir,fname1,fext] = fileparts(fname);
    if isempty(outputDir)
        outputDir = inpDir;
    end
    if exist(outputDir,'dir')~=7
        mkdir(outputDir);
    end
    cn = getCaseName(fname1);
    cc = containsCase(fCases,cn);
    if cc
        matrix = flipAALMatrix_rowsPerCols(d.matrix,aal);
        outFileName = fullfile(outputDir, [fname1,'_flip',fext]);
    else
        matrix = d.matrix;
        outFileName = fullfile(outputDir, [fname1,fext]);
    end
    save(outFileName, 'matrix', '-v7.3');
end
