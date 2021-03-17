function [pInd,cInd,pCases,cCases] = getCasesIndices(caseNames, casesMetaData, patientGroup, patientHipPath, nedaSelected, useFieldName, matchNumberOfControls, matchAge, matchSex)
    if nargin < 3
        patientGroup = [];
    end
    if nargin < 4
        patientHipPath = [];
    end
    if nargin < 5 || isempty(nedaSelected)
        nedaSelected = true;
    end
    if nargin < 6 || isempty(useFieldName)
        useFieldName = 'Use'; %'Use' or 'UseForSpSim'
    end
    if nargin < 7 || isempty(matchNumberOfControls)
        matchNumberOfControls = false;
    end
    if nargin < 8 || isempty(matchAge)
        matchAge = false;
    end
    if nargin < 9 || isempty(matchSex)
        matchSex = false;
    end
    
    % get first attempt of patient and control indices
    [pInd,cInd] = getIndices_internal(caseNames,casesMetaData);
    [~,k,~] = intersect(pInd,cInd);
    if ~isempty(k)
        pInd(k) = [];
    end

    % 'Use' or 'UseForSpSim' may be fields in the cdb struct...
    % if we must select cases that are not 'Use' cases, then we go inside this if
    if ~strcmpi(useFieldName,'Use')
        [~,cCases] = getPatientIndex(casesMetaData, {'Group',useFieldName}, {{'NC'},{1}},'AND');
        [~,cInd,~] = intersect(caseNames,cCases);
    end
    
    % getting the case numbers for patients
    if ~isempty(pInd)
        pCases = caseNames(pInd);
    end
    
    % getting the case numbers for controls
    if ~isempty(cInd)
        cCases = caseNames(cInd);
    end
    
    % if no optional selection parameters were passed we go inside the if
    if isempty(patientGroup) && isempty(patientHipPath) && ~nedaSelected
        if (numel(pInd) < numel(cInd)) && matchNumberOfControls % if we have to match the number of controls to the number of patients
            cInd = getRandomSample(cInd,numel(pInd));
            cCases = caseNames(cInd);
        end
        if matchSex || matchAge % if we have to match sex or age to patients
            [cInd,cCases] = getAgeAndSexMatchControls(numel(cInd), pCases, caseNames, casesMetaData, 10000, matchSex, matchAge);
        end
        return
    end
    
    selFields = {};
    selValues = {};
    if ~isempty(patientGroup)
        selFields{end+1} = 'Group';
        selValues{end+1} = patientGroup;
    end
    if ~isempty(patientHipPath)
        selFields{end+1} = 'HipPath';
        selValues{end+1} = patientHipPath;
    end
    if nedaSelected
        selFields{end+1} = useFieldName;
        selValues{end+1} = { 1 };
    end
    [~,selectedPatientCases] = getPatientIndex(casesMetaData, selFields, selValues, 'AND');

    if ~isempty(selectedPatientCases)
        pCases = selectedPatientCases;
        [~,selPatientInd,~] = intersect(caseNames, selectedPatientCases);
        pInd = intersect(selPatientInd, pInd);
        if (numel(pInd) < numel(cInd)) && matchNumberOfControls
            cInd = getRandomSample(cInd,numel(pInd));
            cCases = caseNames(cInd);
        end
        if matchSex || matchAge
            [cInd,cCases] = getAgeAndSexMatchControls(numel(cInd), pCases, caseNames, casesMetaData, 10000, matchSex, matchAge);
        end
        %cInd = cInd(randperm(numel(cInd)));
        %cInd = cInd(1:numel(pInd));
    end
end

function w = getRandomSample(v,nsample)
    k = randperm(numel(v));
    w = v(k(1:nsample));
end

function [pInd,cInd] = getIndices_internal(cn,casesMetaData)
    isControl = strcmpi(casesMetaData.Group,'NC');
    [~,pInd] = intersect(cn,casesMetaData.Code(~isControl),'stable');
    [~,cInd] = intersect(cn,casesMetaData.Code(isControl),'stable');
end

% function [pInd,cInd] = getIndices_internal(caseNames)
%     isPatient = ~cellfun(@isempty,regexp(caseNames, '^0\d{3}_\d{1}'));
%     pInd = find(isPatient);
%     cInd = find(~isPatient);
% end