function r = calcShortestPath(inputPattern,saveMatFile,outputFileName)
    if nargin < 2 || isempty(saveMatFile)
        saveMatFile = false;
    end
    if nargin < 3 || isempty(outputFileName)
        outputFileName = 'shortestPath.mat';
    end
    files = getAdjMatrixFiles(inputPattern);
    caseName = cell(1,numel(files));
    P = cell(1,numel(files));
    for i = 1:numel(files)
        d = load(files{i});
        A = d.matrix;
        A(A~=0) = 1;
        caseName{i} = getCaseName(files{i});
        P{i} = distance_bin(A);
    end
    r.caseName = caseName;
    r.P = P;
    if saveMatFile
        save(outputFileName, 'caseName', 'P', '-v7.3');
    end
end
