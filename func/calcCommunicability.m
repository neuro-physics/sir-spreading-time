function r = calcCommunicability(inputPattern,saveMatFile,outputFileName)
% estrada & hatano 2008 PRE
    if nargin < 2 || isempty(saveMatFile)
        saveMatFile = false;
    end
    if nargin < 3 || isempty(outputFileName)
        outputFileName = 'communic.mat';
    end
    files = getAdjMatrixFiles(inputPattern);
    caseName = cell(1,numel(files));
    Co = cell(1,numel(files));
    for i = 1:numel(files)
        d = load(files{i});
        A = d.matrix;
        A(A~=0) = 1;
        caseName{i} = getCaseName(files{i});
        Co{i} = expm(A);
    end
    [~,cInd] = getPatientControlInd(caseName);
    Co_Z = zScoreToSubset(Co,cInd);
    r.caseName = caseName;
    r.P = Co;
    r.Co_Z = Co_Z;
    if saveMatFile
        save(outputFileName, 'caseName', 'Co', 'Co_Z', '-v7.3');
    end
end
