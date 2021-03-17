function C = backboneFilterAdjMatrix(input, method, outputDir, groups, hipPath, nedaSelected, patientTableFile)
    fn = [];
    if nargin < 3
        outputDir = '';
    end
    if nargin < 4
        groups = [];
    end
    if nargin < 5
        hipPath = [];
    end
    if nargin < 6
        nedaSelected = 0;
    end
    if (nargin < 7) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    if ischar(input)
        [A,fn] = loadFiles(input, groups, hipPath, nedaSelected, patientTableFile);
    else
        A = input;
    end
    if ~iscell(A)
        error('incorrect format for input parameter');
    end
    if strcmpi(method, 'raw')
        conFun = @GetConsensusAdjMatrix;
    elseif strcmpi(method, 'length')
        conFun = @GetConsensusMatrixEdgeLength;
    else
        error('incorrect method parameter');
    end
    B = conFun(A);
    N = size(B,1);
    [C,estat,erows] = filterMatrix(A,B);
    m = 0;
    while estat
        m = m + 1;
        disp(m)
        kmShift = zeros(N,1); kmShift(erows) = m;
        [B,persist] = callConsensusFun(method, conFun, A, kmShift);
        if (~persist) || (m > N)
            break;
        end
        [C,estat,erows] = filterMatrix(A,B);
    end
    % saving matrices
    if ~isempty(outputDir)
        if exist(outputDir, 'dir') ~= 7
            mkdir(outputDir);
        end
        if isempty(fn)
            fn = appendStr(getFigureFileNames('','fam_',1:numel(A)),'.mat');
        end
        for i = 1:numel(C)
            matrix = C{i};
            save(fullfile(outputDir, fn{i}), 'matrix', '-v7.3');
        end
    end
end

function [B,persist] = callConsensusFun(method, conFun, A, kmShift)
    if strcmpi(method, 'raw')
        B = conFun(A,kmShift);
        persist = true;
    elseif strcmpi(method, 'length')
        B = conFun(A,[],[],[],kmShift);
        persist = false;
    end
end

function [C,errstat,erows] = filterMatrix(A,B)
    errstat = 0; % ok
    k = B==0;
    C = cell(size(A));
    erows = [];
    for i = 1:numel(A)
        C{i} = A{i};
        C{i}(k) = 0; % removing elements which are not present in consensus
        erows = [erows;find(all(C{i}==0,2))];
    end
    if ~isempty(erows)
        errstat = 1;
        erows = unique(erows);
    end
end

function [A,fn] = loadFiles(input, groups, hipPath, nedaSelected, patientTableFile)
    [inputDir,~,~] = fileparts(input);
%     if ~isempty(inputDir)
%         inputDir = [ inputDir, filesep ];
%     end
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    cdb = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData
    f = dir(input);
    cn = getCaseName(f);
    [~,~,pCases,cCases] = getCasesIndices(cn, cdb.casesMetaData, groups, hipPath, nedaSelected);
    caseCodes = [ pCases, cCases ];
    [~,k,~] = intersect(cn, caseCodes);
    fn = cell(1,numel(k));
    A = cell(1,numel(k));
%     for i = 1:numel(f)
    for j = 1:numel(k)
        i = k(j);
        fn{j} = f(i).name;
        a = load(fullfile(inputDir,f(i).name));
        if isfield(a, 'matrix')
            A{j} = a.matrix;
        else
            A{j} = a;
        end
    end
end
