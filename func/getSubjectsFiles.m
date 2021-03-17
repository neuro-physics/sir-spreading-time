function [c,p] = getSubjectsFiles(inputPattern, patientGroup, patientHipPath, nedaSelected, patientTableFile)
    if (nargin < 5) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    [caseName,fName] = getCaseName(inputPattern);
    cmd = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData
    [pInd,cInd] = getCasesIndices(caseName, cmd.casesMetaData, patientGroup, patientHipPath, nedaSelected);
    c = fName(cInd);
    p = fName(pInd);
end
