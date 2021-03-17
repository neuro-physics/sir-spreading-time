function [pInd,cInd] = getPatientControlInd(caseNames,cdb,controlGroup)
    if nargin < 2
        cdb = [];
    end
    if (nargin < 3) || isempty(controlGroup)
        controlGroup = 'NC';
    end

    if isempty(cdb)
        isPatient = ~cellfun(@isempty,regexp(caseNames, '^0\d{3}_\d{1}'));
        pInd = find(isPatient);
        cInd = find(~isPatient);
    else
        [pInd,cInd] = getCasesIndices(caseNames, cdb.casesMetaData, '', [], false, '');
        if ~strcmp(controlGroup,'NC')
            [cInd,~] = getCasesIndices(caseNames, cdb.casesMetaData, controlGroup, [], false, '');
        end
    end
end