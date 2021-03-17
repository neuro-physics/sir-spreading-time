function r = processSpreadingData(spDataMatFile, commMatFile, shortPathMatFile, groups, hipPath, nedaSelected, flipMatrices, ggamma, ttestProp, outputFile, isConsensus, ageSexMatch, tTestAvgNotSample, patientTableFile, volumeField, controlGroup, nPermut)
    if nargin < 2
        commMatFile = '';
    end
    if (nargin < 3)
        shortPathMatFile = '';
    end
    if (nargin < 4) || isempty(groups)
        groups = { {}, {'RTLE'}, {'LTLE'} }; % fTLE -> flips RTLE matrices
    end
    if (nargin < 5) || isempty(hipPath)
        hipPath = { {}, {'HS'}, {'HS'} };
    end
    if (nargin < 6) || isempty(nedaSelected)
        nedaSelected = [ 0, 1, 1 ];
    end
    if (nargin < 7) || isempty(flipMatrices)
        flipMatrices = [ 0, 0, 0 ];
    end
    if (nargin < 8) || isempty(ggamma)
        ggamma = 2.0;
    end
    if (nargin < 9) || isempty(ttestProp)
        ttestProp = { 'AlphaTTest',0.01,'AlphaFDR',0.05,'SplitNegPos','off' };
    end
    if (nargin < 10)
        outputFile = [];
    end
    if (nargin < 11) || isempty(isConsensus)
        isConsensus = false;
    end
    if (nargin < 12) || isempty(ageSexMatch)
        ageSexMatch = false; % tries to match age and sex of controls with first group of patients
    end
    if (nargin < 13) || isempty(tTestAvgNotSample)
        tTestAvgNotSample = true;
    end
    if (nargin < 14) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    if (nargin < 15) || isempty(volumeField)
        volumeField = 'HipVol';
    end
    if (nargin < 16) || isempty(controlGroup)
        controlGroup = 'NC';
    end
    if (nargin < 17)
        nPermut = []; % amount of controls and patients to randomly select from each group (data will be processed only for nPermut cases, if this variable is set)
    end

    global aal;

    % the Mahalanobis distance function (built-in)
    % uses a matrix inverse to calculate its value
    % causing this warning for some data
    % it is used inside the t-test functions
    warning('off','MATLAB:nearlySingularMatrix')
    warning('off','MATLAB:singularMatrix')

    HashValue = DataHash({spDataMatFile, commMatFile, shortPathMatFile, groups, hipPath, nedaSelected, flipMatrices, ggamma, ttestProp, outputFile, isConsensus, ageSexMatch, tTestAvgNotSample, patientTableFile, volumeField, controlGroup, nPermut},struct('Method','SHA-256','Format','base64'));

    [alphaTTest,~] = getParamValue('AlphaTTest',ttestProp,false);
    [alphaFDR,~] = getParamValue('AlphaFDR',ttestProp,false);

    if exist(spDataMatFile, 'dir') == 7 % is directory
        if spDataMatFile(end) ~= filesep
            spDataMatFile(end+1) = filesep;
        end
        fDir = spDataMatFile;
        spDataMatFile = [fDir,'si_data.mat'];
    elseif exist(spDataMatFile, 'file') == 2 % is file
        [fDir,~,~] = fileparts(spDataMatFile);
        fDir(end+1) = filesep;
    else
        fDir = '';
    end

    if ~(exist(spDataMatFile, 'file') == 2)
        error('processSpreadingData:spDataMatFile', 'File not found: %s', spDataMatFile);
    end
    if isempty(commMatFile)
        commMatFile = [fDir,'comm.mat'];
    end
    if isempty(shortPathMatFile)
        shortPathMatFile = [fDir,'shortPath.mat'];
    end
    if isempty(shortPathMatFile)
        shortPathMatFile = [fDir,'shortPath.mat'];
    end

    disp('* Loading files ...');

    % organize shortest path matrices in sp.p
    % according to case names in d
    cm = [];
    cmY = [];
    sp = [];
    d = load(spDataMatFile);
    if exist(commMatFile, 'file') == 2
        cm = load(commMatFile);
    end
    if exist(shortPathMatFile, 'file') == 2
        sp = load(shortPathMatFile);
        sp = sortFieldsContents(sp, d.caseName);
    end
    if isfield(d,'SpMatrix')
        N = d.SpMatrix(1).N;
    elseif isfield(d,'SpMatrixW')
        N = d.SpMatrixW(1).N;
    else
        error('cannot define N through fields SpMatrixW or SpMatrix');
    end

%     aal = load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
    [~,~,~,aal] = aalsurfview(zeros(90,1));
    if isfield(aal, 'comm')
        cmY = getCommStruct(aal.comm, ggamma, N);
    end
    [~,sortInd,~,lobeLabel,lobeIndLR,lobeInd] = groupAALNodes(aal.labels.(getAALLabel(N)));

    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    cdb = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData containing a table of patients that Neda gave me
    
    %%%% creating hippocampus volume struct
    hv = getHippVolumeStruct(cdb, d.caseName, volumeField, controlGroup);

    %%%% creating cortical thickness struct
    ct = [];
    if isfield(cdb,'ctdata')
        ct = getCortThickStruct(cdb.ctdata, d.caseName, N, controlGroup, cdb);
    else
        if exist(fullfile(dataDir,'cortical_thickness_sel.mat'),'file') == 2
            ct = getCortThickStruct(fullfile(dataDir,'cortical_thickness_sel.mat'), d.caseName, N, controlGroup, cdb);
        elseif exist(fullfile(dataDir,'cortical_thickness.mat'),'file') == 2
            ct = getCortThickStruct(fullfile(dataDir,'cortical_thickness.mat'), d.caseName, N, controlGroup, cdb);
        end
    end

    if isConsensus
        groups = { {'cLTLE'}, {'LTLE'}, {'cRTLE'}, {'RTLE'} };
        hipPath = cellfun(@(x){'HS'},cell(size(groups)),'UniformOutput',false);
        flipMatrices = flipMatrices(1).*ones(1,4);
        nedaSelected = nedaSelected(1).*ones(1,4);
    end

    patientInd = [];
    controlInd = [];
    if strcmp(controlGroup,'NC')
        if ageSexMatch
            % tries to select from d.caseName doing age and sex match automatically
            [~,controlInd] = getCasesIndices(d.caseNamhhe, cdb.casesMetaData, controlGroup, hipPath{1}, nedaSelected(1), 'Use', true, true, true);
        else
            % use from d.caseName only the ones that Neda selected for my study
            [~,controlInd] = getCasesIndices(d.caseName, cdb.casesMetaData, controlGroup, hipPath{1}, nedaSelected(1), 'UseForSpSim');
        end
    else
        [controlInd,~] = getCasesIndices(d.caseName, cdb.casesMetaData, controlGroup, hipPath{1}, nedaSelected(1), 'UseForSpSim');
    end
    if ~isempty(nPermut)
        controlInd = controlInd(sort(randperm(numel(controlInd),nPermut)));
    end

    if ~isempty(outputFile)
        if ~hasDirectory(outputFile)
            outputFile = [fDir,outputFile];
        end
        outputFile = CheckAndGetFileName(outputFile);
    end
    
    if numel(nedaSelected) ~= numel(groups)
        nedaSelected = repeatToComplete(nedaSelected,numel(groups));
    end
    
    if numel(flipMatrices) ~= numel(groups)
        flipMatrices = repeatToComplete(flipMatrices,numel(groups));
    end

    pAnt = [];
    cAnt = [];
    for i = 1:numel(groups)
        if isConsensus
            [patientInd,controlInd] = getConsensusGroupCaseInd(d.caseName, groups{i}{1});
            if ~isempty(nPermut)
                controlInd = controlInd(sort(randperm(numel(controlInd),nPermut)));
            end
        else
            [patientInd,~] = getCasesIndices(d.caseName, cdb.casesMetaData, groups{i}, hipPath{i}, nedaSelected(i), 'UseForSpSim');
        end
        if equalVectors(pAnt,patientInd) && equalVectors(cAnt,controlInd)
            continue;
        end
        if ~isempty(nPermut)
            patientInd = patientInd(sort(randperm(numel(patientInd),nPermut)));
        end

        pAnt = patientInd;
        cAnt = controlInd;

        %l = [ 'Group', num2str(i) ];
        l = getGroupName(groups{i});

        disp(['* Processing ... ',l]);
        r = struct(l,[]);
        r.(l) = d;
        %spTemp = sp;
%         if flipMatrices(i)
%             disp('  - Flipping result matrices... ');
%             [kFlip,~] = getCasesIndices(d.caseName(patientInd), cdb.casesMetaData, {'RTLE'}, {'HS'}, 1, 'UseForSpSim');
%             if ~isempty(kFlip)
%                 r.(l) = flipDataMatrices(d.caseName, d.caseName(patientInd(kFlip)), d, aal);
%             end
%             [pIndFlip,~] = getCasesIndices(sp.caseName, cdb.casesMetaData, groups{i}, hipPath{i}, nedaSelected(i), 'UseForSpSim');
%             [kFlip,~] = getCasesIndices(sp.caseName(pIndFlip), cdb.casesMetaData, {'RTLE'}, {'HS'}, 1, 'UseForSpSim');
%             if ~isempty(kFlip)
%                 spTemp = flipDataMatrices(sp.caseName, sp.caseName(pIndFlip(kFlip)), sp, aal);
%             end
%         end
        if isempty(groups{i}), groups{i} = 'all'; end
        if isempty(hipPath{i}), hipPath{i} = 'all'; end
        r.(l).ControlGroup = controlGroup;
        r.(l).Side = groups{i};
        r.(l).RTLEFlip = flipMatrices(i);
        r.(l).HipPath = hipPath{i};
        r.(l).controlCode = d.caseName(controlInd);
        r.(l).patientCode = d.caseName(patientInd);
        r.(l) = rmfield(r.(l), 'caseName');
        r.(l).IsPermutation = ~isempty(nPermut);

        %spMat = r.(l).SpMatrix;
        if ~isempty(r.(l).PhaseTrans)
            r.(l).PhaseTrans = processPhaseTrans(r.(l).PhaseTrans, controlInd, patientInd, alphaTTest, alphaFDR, flipMatrices(i));
        else
            r.(l).PhaseTrans = [];
        end
        if isempty(cmY)
            if isfield(r.(l),'SpMatrix')
                [r.(l).SpMatrix,r.(l).ModSpMatrix] = processSpreadingMatrix(r.(l).SpMatrix, controlInd, patientInd, sp, cm, ggamma, ct, hv, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpMatrix = [];
                r.(l).ModSpMatrix = [];
            end
            if isfield(r.(l),'SpMatrixW')
                [r.(l).SpMatrixW,r.(l).ModSpMatrixW] = processSpreadingMatrix(r.(l).SpMatrixW, controlInd, patientInd, sp, cm, ggamma, ct, hv, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpMatrixW = [];
                r.(l).ModSpMatrixW = [];
            end
        else
            if isfield(r.(l),'SpMatrix')
                [~, r.(l).ModSpMatrix]               = processSpreadingMatrix(r.(l).SpMatrix, controlInd, patientInd, sp, cm, ggamma, ct, hv, ttestProp, true, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
                [r.(l).SpMatrix, r.(l).CommSpMatrix] = processSpreadingMatrix(r.(l).SpMatrix, controlInd, patientInd, sp, cmY, ggamma, ct, hv, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpMatrix = [];
                r.(l).ModSpMatrix = [];
                r.(l).CommSpMatrix = [];
            end
            if isfield(r.(l),'SpMatrixW')
                [~, r.(l).ModSpMatrixW]                = processSpreadingMatrix(r.(l).SpMatrixW, controlInd, patientInd, sp, cm, ggamma, ct, hv, ttestProp, true, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
                [r.(l).SpMatrixW, r.(l).CommSpMatrixW] = processSpreadingMatrix(r.(l).SpMatrixW, controlInd, patientInd, sp, cmY, ggamma, ct, hv, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpMatrixW = [];
                r.(l).ModSpMatrixW = [];
                r.(l).CommSpMatrixW = [];
            end
        end

        %tsComp = r.(l).TwoSeeds;
        %suTemp = r.(l).SpeedUp;
        if isempty(cmY)
            if isfield(r.(l),'SpeedUp')
                [r.(l).SpeedUp, r.(l).ModSpeedUp]    = processSpeedUp(r.(l).SpeedUp, controlInd, patientInd, cm, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpeedUp = [];
                r.(l).ModSpeedUp = [];
            end
            if isfield(r.(l),'SpeedUpW')
                [r.(l).SpeedUpW, r.(l).ModSpeedUpW]  = processSpeedUp(r.(l).SpeedUpW, controlInd, patientInd, cm, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpeedUpW = [];
                r.(l).ModSpeedUpW = [];
            end
            if isfield(r.(l),'TwoSeeds')
                [r.(l).TwoSeeds,r.(l).ModTwoSeeds]   = processTwoSeedsCompetitive(r.(l).TwoSeeds, controlInd, patientInd, cm, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).TwoSeeds = [];
                r.(l).ModTwoSeeds = [];
            end
        else
            if isfield(r.(l),'SpeedUp')
                [~, r.(l).ModSpeedUp]                 = processSpeedUp(r.(l).SpeedUp, controlInd, patientInd, cm, ggamma, ttestProp, true, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
                [r.(l).SpeedUp, r.(l).CommSpeedUp]    = processSpeedUp(r.(l).SpeedUp, controlInd, patientInd, cmY, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpeedUp = [];
                r.(l).ModSpeedUp = [];
                r.(l).CommSpeedUp = [];
            end
            if isfield(r.(l),'SpeedUpW')
                [~, r.(l).ModSpeedUpW]                = processSpeedUp(r.(l).SpeedUpW, controlInd, patientInd, cm, ggamma, ttestProp, true, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
                [r.(l).SpeedUpW, r.(l).CommSpeedUpW]  = processSpeedUp(r.(l).SpeedUpW, controlInd, patientInd, cmY, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).SpeedUpW = [];
                r.(l).ModSpeedUpW = [];
                r.(l).CommSpeedUpW = [];
            end
            if isfield(r.(l),'TwoSeeds')
                [~, r.(l).ModTwoSeeds]                = processTwoSeedsCompetitive(r.(l).TwoSeeds, controlInd, patientInd, cm, ggamma, ttestProp, true, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
                [r.(l).TwoSeeds, r.(l).CommTwoSeeds]  = processTwoSeedsCompetitive(r.(l).TwoSeeds, controlInd, patientInd, cmY, ggamma, ttestProp, [], lobeIndLR, lobeInd, sortInd, tTestAvgNotSample);
            else
                r.(l).TwoSeeds = [];
                r.(l).ModTwoSeeds = [];
                r.(l).CommTwoSeeds = [];
            end
        end

        r.(l).alphaTTest = alphaTTest;
        r.(l).comm = cm;
        r.(l).commYeo = cmY;
        r.(l).ggamma = ggamma;
        r.(l).shortPath = sp;
        [~,cCInd,~]=intersect(cdb.casesMetaData.Code,d.caseName(controlInd));
        [~,pCInd,~]=intersect(cdb.casesMetaData.Code,d.caseName(patientInd));
        r.(l).controlAge = [round(mean(cdb.casesMetaData.Age(cCInd))),ceil(std(cdb.casesMetaData.Age(cCInd)))];
        r.(l).patientAge = [round(mean(cdb.casesMetaData.Age(pCInd))),ceil(std(cdb.casesMetaData.Age(pCInd)))];
        r.(l).controlNumFem = numel(getFemaleCases(cdb,cCInd));
        r.(l).patientNumFem = numel(getFemaleCases(cdb,pCInd));
        r.(l).lobeLabelLR = lobeLabel;
        r.(l).lobeLabel = regexprep(lobeLabel(1:(numel(lobeLabel)/2)),'_(R|L)$','');
        r.(l).commLabel_Yeo = aal.labels.AAL09comm;
        r.(l) = orderfields(r.(l));
        if ~isempty(outputFile)
            outArgs = '-v7.3';
            if exist(outputFile,'file') == 2
                outArgs = '-append';
            end
            disp(['* Saving (appending) ... ', outputFile]);
            save(outputFile, '-struct', 'r', outArgs);
        end
    end
    r.HashValue = HashValue;

    if ~isempty(outputFile)
        outArgs = '-v7.3';
        if exist(outputFile,'file') == 2
            outArgs = '-append';
        end
        disp(['* Finishing file ... ', outputFile]);
        save(outputFile, 'HashValue', outArgs);
    end
    warning('on','MATLAB:nearlySingularMatrix')
end

function c = getFemaleCases(cdb,ind)
    if (nargin < 2) || isempty(ind)
        ind = 1:numel(cdb.casesMetaData.Code);
    end
    c = cdb.casesMetaData.Code(strcmp(cdb.casesMetaData.Sex(ind),'Female') | strcmp(cdb.casesMetaData.Sex(ind),'F'));
end

function [pInd,cInd] = getConsensusGroupCaseInd(cn, g)
    cInd = find(strcmp(cn, '000_0'));
    if strcmp(g, 'cLTLE')
        pInd = find(strcmp(cn, '0991_0'));
    elseif strcmp(g, 'LTLE')
        pInd = find(strcmp(cn, '0991_9'));
    elseif strcmp(g, 'cRTLE')
        pInd = find(strcmp(cn, '0992_0'));
    elseif strcmp(g, 'RTLE')
        pInd = find(strcmp(cn, '0992_9'));
    else
        error('processSpreadingData:getConsensusGroupCaseInd','unrecognized group for consensus data');
    end
end

function [r,rCm] = processTwoSeedsCompetitive(ts, cInd, pInd, cm, ggamma, ttestProp, calcCommOnly, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample)
    if (nargin < 7) || isempty(calcCommOnly)
        calcCommOnly = false;
    end
    commInd = getCommGroups(cm,ggamma);
    if calcCommOnly
        r = [];
    else
        r = processTwoSeedsCompetitive_internal(ts, cInd, pInd, ttestProp, lobeIndLR, lobeInd, commInd, sortInd, tTestAvgNotSample);
    end
    rCm = processTwoSeedsCompetitive_internal(getCommunityData(ts, cm, ggamma), cInd, pInd, ttestProp,...
                                              num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), 1:numel(commInd), tTestAvgNotSample);
end

function r = processTwoSeedsCompetitive_internal(ts, cInd, pInd, tTestProp, lobeIndLR, lobeInd, commInd, sortInd, tTestAvgNotSample)
    [alphaTTest,tTestProp] = getParamValue('AlphaTTest',tTestProp,true);
    [alphaFDR,tTestProp] = getParamValue('AlphaFDR',tTestProp,true);
    [splitTTest,tTestProp] = getParamValue('SplitNegPos',tTestProp,true);
    theta = [ts(:).theta];
    nT = numel(theta);
    N = ts(1).N;
    r = struct('header', [], 'N', [], 'theta', [], 'controlData', [], 'patientData', [], 'ttest', []);
    r.N = N;
    r.theta = theta;
    r.header = [cellCellToCell(ts(1).header);...
                {'Cp',       'Cp1 averaged over each state 2 seed';...
                 'Cp_lobe',  'Competitiveness (avalanche size for a given seed) averaged for each lobe';...
                 'Cp_lobeLR','Competitiveness (avalanche size for a given seed) averaged for each L and R lobe';...
                 'Cp_comm',  'Competitiveness (avalanche size for a given seed) averaged for each Yeo community';...
                 'Cf_lobe',  'Conformity (similarity to neighbors) averaged for each lobe';...
                 'Cf_lobeLR','Conformity (similarity to neighbors) averaged for each L and R lobe';...
                 'Cf_comm',  'Conformity (similarity to neighbors) averaged for each Yeo community';...
                 'H_lobe',   'Entropy (dissimilarity to neighbors) averaged for each lobe';...
                 'H_lobeLR', 'Entropy (dissimilarity to neighbors) averaged for each L and R lobe';...
                 'H_comm',   'Entropy (dissimilarity to neighbors) averaged for each Yeo community'}];

    dataFields      =         {     'Cf_Std',      'Cp_Std',      'H_Std',    'T_Std', ...
                                        'Cf',          'Cp',          'H',        'T',      'Cp1',       'Cp2',   'Cf_lobe', 'Cf_lobeLR',  'Cf_comm',  'Cp_lobe', ...
                                 'Cp_lobeLR',     'Cp_comm',     'H_lobe', 'H_lobeLR',   'H_comm',  'Cp_theta',  'Cf_theta',   'H_theta', ...
                               'CpAll_theta', 'CfAll_theta', 'HAll_theta',...
                               'CpStd_theta', 'CfStd_theta', 'HStd_theta',...
                                'CfStd_lobe','CfStd_lobeLR', 'CfStd_comm','CpStd_lobe','CpStd_lobeLR','CpStd_comm','HStd_lobe','HStd_lobeLR','HStd_comm'};
    defaultFieldVal =         {   cell(1,nT),    cell(1,nT),   cell(1,nT), cell(1,nT), ...
                                  cell(1,nT),    cell(1,nT),   cell(1,nT), cell(1,nT), cell(1,nT),  cell(1,nT),  cell(1,nT),  cell(1,nT), cell(1,nT), cell(1,nT), ...
                                  cell(1,nT),    cell(1,nT),   cell(1,nT), cell(1,nT), cell(1,nT), zeros(1,nT), zeros(1,nT), zeros(1,nT), ...
                                  cell(1,nT),    cell(1,nT),   cell(1,nT), ...
                                  zeros(1,nT), zeros(1,nT), zeros(1,nT),...
                                  cell(1,nT),    cell(1,nT),   cell(1,nT), cell(1,nT), cell(1,nT),  cell(1,nT),  cell(1,nT),  cell(1,nT), cell(1,nT) };
    fieldHasTTest   = logical([            0,             0,            0,          0, ...
                                           1,             1,            1,          1,          1,           1,           1,           1,          1,          1, ...
                                           1,             1,            1,          1,          1,           1,           1,           1, ...
                                           0,             0,            0,...
                                           0,             0,            0,...
                                           0,             0,            0,          0,          0,           0,           0,           0,          0 ]);

    r.controlData = cell2struct(defaultFieldVal, dataFields, 2);
    r.patientData = cell2struct(defaultFieldVal, dataFields, 2);
    r.ttest = cell2struct(cellfun(@(x)ttest.ttest2Struct(),cell(1,numel(find(fieldHasTTest))),'UniformOutput',false),dataFields(fieldHasTTest),2);
    r.flip = rmfield(r,'header');
    r.zToControl = r.flip;
    
    for i = 1:nT
        r = CalcTwoSeedsOutput_theta(r,i,ts(i).data,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        r.flip = CalcTwoSeedsOutput_theta(r.flip,i,ts(i).flipData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        r.zToControl = CalcTwoSeedsOutput_theta(r.zToControl,i,ts(i).zControlData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
    end
    r.flip.controlData = correctNumericPrecision_cell(r.flip.controlData,1e-8);
    r.zToControl.controlData = correctNumericPrecision_cell(r.zToControl.controlData,1e-8);
end

function r = CalcTwoSeedsOutput_theta(r,i,ts,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp)
    if isempty(ts)
        return;
    end
    [r.controlData,Cf_c,Cf_comm_c,Cf_lobeLR_c,Cf_lobe_c,Cp1_c,Cp2_c,Cp_c,...
      Cp_comm_c,Cp_lobeLR_c,Cp_lobe_c,H_c,H_comm_c,H_lobeLR_c,H_lobe_c,...
      T_c] = CalcTwoSeedsOutput(r.controlData,i,ts,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample);

    if numel(pInd) > 0
        [r.patientData,Cf_p,Cf_comm_p,Cf_lobeLR_p,Cf_lobe_p,Cp1_p,Cp2_p,Cp_p,...
          Cp_comm_p,Cp_lobeLR_p,Cp_lobe_p,H_p,H_comm_p,H_lobeLR_p,H_lobe_p,...
          T_p] = CalcTwoSeedsOutput(r.patientData,i,ts,N,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample);

        r.ttest = CalcTwoSeedsTTest(r.ttest,i,alphaTTest,alphaFDR,splitTTest,N,lobeInd,lobeIndLR,commInd,Cf_c,Cf_p,Cf_comm_c,Cf_comm_p,...
                           Cf_lobeLR_c,Cf_lobeLR_p,Cf_lobe_c,Cf_lobe_p,Cp1_c,Cp1_p,Cp2_c,Cp2_p,Cp_c,Cp_p,...
                           Cp_comm_c,Cp_comm_p,Cp_lobeLR_c,Cp_lobeLR_p,Cp_lobe_c,Cp_lobe_p,H_c,H_p,H_comm_c,H_comm_p,...
                           H_lobeLR_c,H_lobeLR_p,H_lobe_c,H_lobe_p,T_c,T_p,tTestProp);
    end
end

function [r,Cf_c,Cf_comm_c,Cf_lobeLR_c,Cf_lobe_c,Cp1_c,Cp2_c,Cp_c,...
          Cp_comm_c,Cp_lobeLR_c,Cp_lobe_c,H_c,H_comm_c,H_lobeLR_c,H_lobe_c,...
          T_c] = CalcTwoSeedsOutput(r,i,ts,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample)
    Cp1_c = matCell2Mat(ts.Cp1(cInd));
    Cp2_c = matCell2Mat(ts.Cp2(cInd));
    Cp_c = matCell2Mat(myMean(ts.Cp1(cInd),2,'omitnan'));
    Cf_c = matCell2Mat(ts.Cf(cInd));
    H_c = matCell2Mat(ts.H(cInd));
    T_c = matCell2Mat(ts.T(cInd));
    Cf_c_Z_sort = sortMatrices(Cf_c,sortInd,2);
    Cp_c_Z_sort = sortMatrices(Cp_c,sortInd,2);
    H_c_Z_sort = sortMatrices(H_c,sortInd,2);
    if tTestAvgNotSample
        Cf_lobe_c = averageSector(Cf_c_Z_sort,lobeInd,'line');
        Cf_lobeLR_c = averageSector(Cf_c_Z_sort,lobeIndLR,'line');
        Cf_comm_c = averageSector(Cf_c,commInd,'line');
        Cp_lobe_c = averageSector(Cp_c_Z_sort,lobeInd,'line');
        Cp_lobeLR_c = averageSector(Cp_c_Z_sort,lobeIndLR,'line');
        Cp_comm_c = averageSector(Cp_c,commInd,'line');
        H_lobe_c = averageSector(H_c_Z_sort,lobeInd,'line');
        H_lobeLR_c = averageSector(H_c_Z_sort,lobeIndLR,'line');
        H_comm_c = averageSector(H_c,commInd,'line');

        Cf_lobe_c_var = varianceSector(Cf_c_Z_sort,lobeInd,'line');
        Cf_lobeLR_c_var = varianceSector(Cf_c_Z_sort,lobeIndLR,'line');
        Cf_comm_c_var = varianceSector(Cf_c,commInd,'line');
        Cp_lobe_c_var = varianceSector(Cp_c_Z_sort,lobeInd,'line');
        Cp_lobeLR_c_var = varianceSector(Cp_c_Z_sort,lobeIndLR,'line');
        Cp_comm_c_var = varianceSector(Cp_c,commInd,'line');
        H_lobe_c_var = varianceSector(H_c_Z_sort,lobeInd,'line');
        H_lobeLR_c_var = varianceSector(H_c_Z_sort,lobeIndLR,'line');
        H_comm_c_var = varianceSector(H_c,commInd,'line');
    else
        Cf_lobe_c = groupSector(Cf_c_Z_sort,lobeInd,'line');
        Cf_lobeLR_c = groupSector(Cf_c_Z_sort,lobeIndLR,'line');
        Cf_comm_c = groupSector(Cf_c,commInd,'line');
        Cp_lobe_c = groupSector(Cp_c_Z_sort,lobeInd,'line');
        Cp_lobeLR_c = groupSector(Cp_c_Z_sort,lobeIndLR,'line');
        Cp_comm_c = groupSector(Cp_c,commInd,'line');
        H_lobe_c = groupSector(H_c_Z_sort,lobeInd,'line');
        H_lobeLR_c = groupSector(H_c_Z_sort,lobeIndLR,'line');
        H_comm_c = groupSector(H_c,commInd,'line');
    end

    r.Cp_Std{i} = reshape(std(Cp_c,[],1,'omitnan'),N,1);
    r.Cf_Std{i} = reshape(std(Cf_c,[],1,'omitnan'),N,1);
    r.H_Std{i} = reshape(std(H_c,[],1,'omitnan'),N,1);
    r.T_Std{i} = reshape(std(T_c,[],1,'omitnan'),N,N);
    r.Cp1{i} = reshape(mean(Cp1_c,1,'omitnan'),N,N);
    r.Cp2{i} = reshape(mean(Cp2_c,1,'omitnan'),N,N);
    r.Cp{i} = reshape(mean(Cp_c,1,'omitnan'),N,1);
    r.Cf{i} = reshape(mean(Cf_c,1,'omitnan'),N,1);
    r.H{i} = reshape(mean(H_c,1,'omitnan'),N,1);
    r.T{i} = reshape(mean(T_c,1,'omitnan'),N,N);
    r.Cf_lobe{i} = reshape(mean(Cf_lobe_c,1,'omitnan'),numel(lobeInd),1);
    r.Cf_lobeLR{i} = reshape(mean(Cf_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
    r.Cf_comm{i} = reshape(mean(Cf_comm_c,1,'omitnan'),numel(commInd),1);
    r.Cp_lobe{i} = reshape(mean(Cp_lobe_c,1,'omitnan'),numel(lobeInd),1);
    r.Cp_lobeLR{i} = reshape(mean(Cp_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
    r.Cp_comm{i} = reshape(mean(Cp_comm_c,1,'omitnan'),numel(commInd),1);
    r.H_lobe{i} = reshape(mean(H_lobe_c,1,'omitnan'),numel(lobeInd),1);
    r.H_lobeLR{i} = reshape(mean(H_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
    r.H_comm{i} = reshape(mean(H_comm_c,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.CfStd_lobe{i} = reshape(sqrt(mean(Cf_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
        r.CfStd_lobeLR{i} = reshape(sqrt(mean(Cf_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
        r.CfStd_comm{i} = reshape(sqrt(mean(Cf_comm_c_var,1,'omitnan')),numel(commInd),1);
        r.CpStd_lobe{i} = reshape(sqrt(mean(Cp_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
        r.CpStd_lobeLR{i} = reshape(sqrt(mean(Cp_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
        r.CpStd_comm{i} = reshape(sqrt(mean(Cp_comm_c_var,1,'omitnan')),numel(commInd),1);
        r.HStd_lobe{i} = reshape(sqrt(mean(H_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
        r.HStd_lobeLR{i} = reshape(sqrt(mean(H_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
        r.HStd_comm{i} = reshape(sqrt(mean(H_comm_c_var,1,'omitnan')),numel(commInd),1);
    else
        r.CfStd_lobe{i} = reshape(std(Cf_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
        r.CfStd_lobeLR{i} = reshape(std(Cf_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
        r.CfStd_comm{i} = reshape(std(Cf_comm_c,[],1,'omitnan'),numel(commInd),1);
        r.CpStd_lobe{i} = reshape(std(Cp_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
        r.CpStd_lobeLR{i} = reshape(std(Cp_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
        r.CpStd_comm{i} = reshape(std(Cp_comm_c,[],1,'omitnan'),numel(commInd),1);
        r.HStd_lobe{i} = reshape(std(H_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
        r.HStd_lobeLR{i} = reshape(std(H_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
        r.HStd_comm{i} = reshape(std(H_comm_c,[],1,'omitnan'),numel(commInd),1);
    end
    r.Cp_theta(i) = nanmean(Cp_c(:));
    r.Cf_theta(i) = nanmean(Cf_c(:));
    r.H_theta(i) = nanmean(H_c(:));
    r.CpStd_theta(i) = nanstd(Cp_c(:));
    r.CfStd_theta(i) = nanstd(Cf_c(:));
    r.HStd_theta(i) = nanstd(H_c(:));
    r.CpAll_theta{i} = mean(Cp_c,2,'omitnan');
    r.CfAll_theta{i} = mean(Cf_c,2,'omitnan');
    r.HAll_theta{i} = mean(H_c,2,'omitnan');
end

function r = CalcTwoSeedsTTest(r,i,alphaTTest,alphaFDR,splitTTest,N,lobeInd,lobeIndLR,commInd,Cf_c,Cf_p,Cf_comm_c,Cf_comm_p,...
                               Cf_lobeLR_c,Cf_lobeLR_p,Cf_lobe_c,Cf_lobe_p,Cp1_c,Cp1_p,Cp2_c,Cp2_p,Cp_c,Cp_p,...
                               Cp_comm_c,Cp_comm_p,Cp_lobeLR_c,Cp_lobeLR_p,Cp_lobe_c,Cp_lobe_p,H_c,H_p,H_comm_c,H_comm_p,...
                               H_lobeLR_c,H_lobeLR_p,H_lobe_c,H_lobe_p,T_c,T_p,tTestProp)
    r.Cf(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cf_c,Cf_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[N,1]);
    r.Cp(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp_c,Cp_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[N,1]);
    r.H(i) = ttest.reshapeTTest(ttest.ttest2Struct(H_c,H_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[N,1]);
    r.T(i) = ttest.reshapeTTest(ttest.ttest2Struct(T_c,T_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.Cp1(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp1_c,Cp1_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.Cp2(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp2_c,Cp2_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.Cf_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cf_lobe_c,Cf_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeInd),1]);
    r.Cf_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cf_lobeLR_c,Cf_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeIndLR),1]);
    r.Cf_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cf_comm_c,Cf_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(commInd),1]);
    r.Cp_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp_lobe_c,Cp_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeInd),1]);
    r.Cp_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp_lobeLR_c,Cp_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeIndLR),1]);
    r.Cp_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(Cp_comm_c,Cp_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(commInd),1]);
    r.H_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(H_lobe_c,H_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeInd),1]);
    r.H_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(H_lobeLR_c,H_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(lobeIndLR),1]);
    r.H_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(H_comm_c,H_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR),[numel(commInd),1]);
    r.Cp_theta(i) = ttest.ttest2Struct(Cp_c(:),Cp_p(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
    r.Cf_theta(i) = ttest.ttest2Struct(Cf_c(:),Cf_p(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
    r.H_theta(i) = ttest.ttest2Struct(H_c(:),H_p(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
end

function m = cellCellToCell(c)
    n = numel(c);
    m=cellfun(@(x)[x{1},';',x{2},';'],c,'UniformOutput',false);
    m=strsplit([m{:}],';');
    m=m(1:end-1);
    m=reshape(m,2,n)';
end

function [r,rCm] = processSpeedUp(su, cInd, pInd, cm, ggamma, ttestProp, calcCommOnly, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample)
    if (nargin < 8) || isempty(calcCommOnly)
        calcCommOnly = false;
    end
    commInd = getCommGroups(cm,ggamma);
    if calcCommOnly
        r = [];
    else
        r = processSpeedUp_internal(su,cInd,pInd,ttestProp,lobeIndLR,lobeInd,commInd,sortInd,tTestAvgNotSample);
    end
    rCm = processSpeedUp_internal(getCommunityData(su, cm, ggamma), cInd, pInd, ttestProp,...
                                  num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), 1:numel(commInd), tTestAvgNotSample);
end

function r = processSpeedUp_internal(su, cInd, pInd, tTestProp, lobeIndLR, lobeInd, commInd, sortInd, tTestAvgNotSample)
    [alphaTTest,tTestProp] = getParamValue('AlphaTTest',tTestProp,true);
    [alphaFDR,tTestProp] = getParamValue('AlphaFDR',tTestProp,true);
    [splitTTest,tTestProp] = getParamValue('SplitNegPos',tTestProp,true);
    thetaSel = [su(:).theta];
    
    N = su(1).N;
    nT = numel(thetaSel);

    r = struct('header', [], 'N', [], 'theta', [], 'controlData', [], 'patientData', [], 'ttest', []);

    r.N = N;

    r.header = { 'global',   'speedup of the seed pair (i,j) network activation in relation to the minimum total network activation time by starting only at seed i or seed j';...
                 'local',    'speedup of the seed pair (i,j) to k in relation to the minimum total network activation time by starting only at seed i or seed j to k';...
                 'localnet', 'speedup of the seed pair (i,j) in relation to the minimum of the activation time of seed-target pairs (i,j) or (j,i)'};

    r.theta = thetaSel;
    
    dataFields      =         {       'global',           'local',       'localnet', ...
                                'global_theta',     'local_theta', 'localnet_theta', 'globalAll_theta', 'localAll_theta', 'localnetAll_theta', ...
                                'globalStd_theta',     'localStd_theta', 'localnetStd_theta', ...
                                 'global_lobe',   'global_lobeLR',    'global_comm',      'local_lobe',   'local_lobeLR',        'local_comm', ...
                               'localnet_lobe', 'localnet_lobeLR',  'localnet_comm', ...
                              'globalStd_lobe','globalStd_lobeLR', 'globalStd_comm',   'localStd_lobe','localStd_lobeLR',     'localStd_comm', ...
                            'localnetStd_lobe','localnetStd_lobeLR','localnetStd_comm'};
    defaultFieldVal =         {     cell(1,nT),        cell(1,nT),       cell(1,nT), ...
                                   zeros(1,nT),       zeros(1,nT),      zeros(1,nT),        cell(1,nT),       cell(1,nT),          cell(1,nT), ...
                                   zeros(1,nT),       zeros(1,nT),      zeros(1,nT), ...
                                    cell(1,nT),        cell(1,nT),       cell(1,nT),        cell(1,nT),       cell(1,nT),          cell(1,nT), ...
                                    cell(1,nT),        cell(1,nT),       cell(1,nT), ...
                                    cell(1,nT),        cell(1,nT),       cell(1,nT),        cell(1,nT),       cell(1,nT),          cell(1,nT), ...
                                    cell(1,nT),        cell(1,nT),       cell(1,nT) };
    fieldHasTTest   = logical([              1,                 1,                1, ...
                                             1,                 1,                1,                 0,                0,                   0, ...
                                             0,                 0,                0, ...
                                             1,                 1,                1,                 1,                1,                   1, ...
                                             1,                 1,                1, ...
                                             0,                 0,                0,                 0,                0,                   0, ...
                                             0,                 0,                0 ]);

    r.controlData = cell2struct(defaultFieldVal, dataFields, 2);
    r.patientData = cell2struct(defaultFieldVal, dataFields, 2);
    r.ttest = cell2struct(cellfun(@(x)ttest.ttest2Struct(),cell(1,numel(find(fieldHasTTest))),'UniformOutput',false),dataFields(fieldHasTTest),2);
    r.flip = rmfield(r,'header');
    r.zToControl = r.flip;
    
%     Sc = S(cInd);
%     ScZ = ZScoreMatrix(Sc);
%     ScZm = meanMatrix(ScZ);
%     ScZ_linear = matCell2Mat(ScZ);
%     tt=myttest2(ScZ_linear,SpZ_linear,'Alpha',0.01);

    for i = 1:nT
        %r = CalcSpeedUpOutput_theta(r,i,s(i).data,ts(i).data,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest);
        r = CalcSpeedUpOutput_theta(r,i,su(i).data,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        if (~isempty(su(i).flipData))
            %r.flip = CalcSpeedUpOutput_theta(r.flip,i,s(i).flipData,ts(i).flipData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest);
            r.flip = CalcSpeedUpOutput_theta(r.flip,i,su(i).flipData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        end
        if (~isempty(su(i).zControlData))
            %r.zToControl = CalcSpeedUpOutput_theta(r.zToControl,i,s(i).zControlData,ts(i).zControlData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest);
            r.zToControl = CalcSpeedUpOutput_theta(r.zToControl,i,su(i).zControlData,N,cInd,pInd,[],[],lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        end
    end
    r.flip.controlData = correctNumericPrecision_cell(r.flip.controlData,1e-8);
    r.zToControl.controlData = correctNumericPrecision_cell(r.zToControl.controlData,1e-8);
end

function r = CalcSpeedUpOutput_theta(r,i,su,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp)
    [r.controlData,SZg_comm_c,SZg_lobeLR_c,SZg_lobe_c,SZl_comm_c,SZl_lobeLR_c,...
      SZl_lobe_c,SZln_comm_c,SZln_lobeLR_c,SZln_lobe_c,...
      Sgc,Slc,Slnc] = CalcSpeedUpOutput(r.controlData,i,su,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample);

    if numel(pInd) > 0
        [r.patientData,SZg_comm_p,SZg_lobeLR_p,SZg_lobe_p,SZl_comm_p,SZl_lobeLR_p,...
          SZl_lobe_p,SZln_comm_p,SZln_lobeLR_p,SZln_lobe_p,...
          Sgp,Slp,Slnp] = CalcSpeedUpOutput(r.patientData,i,su,N,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample);

        r.ttest = CalcSpeedUpTTest(r.ttest,i,~isempty(su.Ulocal),alphaTTest,alphaFDR,splitTTest,N,lobeInd,lobeIndLR,commInd,SZg_comm_c,SZg_comm_p,SZg_lobeLR_c,...
                          SZg_lobeLR_p,SZg_lobe_c,SZg_lobe_p,SZl_comm_c,SZl_comm_p,SZl_lobeLR_c,SZl_lobeLR_p,SZl_lobe_c,SZl_lobe_p,...
                          SZln_comm_c,SZln_comm_p,SZln_lobeLR_c,SZln_lobeLR_p,SZln_lobe_c,SZln_lobe_p,Sgc,Sgp,Slc,Slp,Slnc,Slnp,tTestProp);
    end
end

function [r,SZg_comm_c,SZg_lobeLR_c,SZg_lobe_c,SZl_comm_c,SZl_lobeLR_c,...
          SZl_lobe_c,SZln_comm_c,SZln_lobeLR_c,SZln_lobe_c,...
          Sgc,Slc,Slnc] = CalcSpeedUpOutput(r,i,su,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample)
%           Slc,SlcZ,Slnc,SlncZ] = CalcSpeedUpOutput(r,i,s,ts,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd)
    S = su.Uglobal(cInd);
    %SZ = ZScoreMatrix(su.Uglobal(cInd));
    SZ_sort = sortMatrices(S,sortInd);
    if tTestAvgNotSample
        SZg_lobe_c = matCell2Mat(averageSector(SZ_sort, lobeInd, 'vert'));
        SZg_lobeLR_c = matCell2Mat(averageSector(SZ_sort, lobeIndLR, 'vert'));
        SZg_comm_c = matCell2Mat(averageSector(S, commInd, 'vert'));

        SZg_lobe_c_var = matCell2Mat(varianceSector(SZ_sort, lobeInd, 'vert'));
        SZg_lobeLR_c_var = matCell2Mat(varianceSector(SZ_sort, lobeIndLR, 'vert'));
        SZg_comm_c_var = matCell2Mat(varianceSector(S, commInd, 'vert'));
    else
        SZg_lobe_c = cell2mat(groupSector(SZ_sort, lobeInd, 'vert'));
        SZg_lobeLR_c = cell2mat(groupSector(SZ_sort, lobeIndLR, 'vert'));
        SZg_comm_c = cell2mat(groupSector(S, commInd, 'vert'));
    end
    Sgc = matCell2Mat(S);
    r.global{i} = reshape(mean(Sgc,1,'omitnan'),N,N);
    r.global{i}(1:(N+1):end) = 0;
    r.global_theta(i) = mean(Sgc(:),'omitnan');
    r.globalStd_theta(i) = std(Sgc(:),'omitnan');
    r.globalAll_theta{i} = mean(Sgc,2,'omitnan');
    r.global_lobe{i} = reshape(mean(SZg_lobe_c,1,'omitnan'),numel(lobeInd),1);
    r.global_lobeLR{i} = reshape(mean(SZg_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
    r.global_comm{i} = reshape(mean(SZg_comm_c,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.globalStd_lobe{i} = reshape(sqrt(mean(SZg_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
        r.globalStd_lobeLR{i} = reshape(sqrt(mean(SZg_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
        r.globalStd_comm{i} = reshape(sqrt(mean(SZg_comm_c_var,1,'omitnan')),numel(commInd),1);
    else
        r.globalStd_lobe{i} = reshape(std(SZg_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
        r.globalStd_lobeLR{i} = reshape(std(SZg_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
        r.globalStd_comm{i} = reshape(std(SZg_comm_c,[],1,'omitnan'),numel(commInd),1);
    end
    %if ~isempty(ts.Tn{1})
    if ~isempty(su.Ulocal)
        S = su.Ulocal(cInd);
        SZ_sort = sortMatrices(S,sortInd);
        if tTestAvgNotSample
            SZl_lobe_c = matCell2Mat(averageSector(SZ_sort, lobeInd, 'vert'));
            SZl_lobeLR_c = matCell2Mat(averageSector(SZ_sort, lobeIndLR, 'vert'));
            SZl_comm_c = matCell2Mat(averageSector(S, commInd, 'vert'));
            
            SZl_lobe_c_var = matCell2Mat(varianceSector(SZ_sort, lobeInd, 'vert'));
            SZl_lobeLR_c_var = matCell2Mat(varianceSector(SZ_sort, lobeIndLR, 'vert'));
            SZl_comm_c_var = matCell2Mat(varianceSector(S, commInd, 'vert'));
        else
            SZl_lobe_c = cell2mat(groupSector(SZ_sort, lobeInd, 'vert'));
            SZl_lobeLR_c = cell2mat(groupSector(SZ_sort, lobeIndLR, 'vert'));
            SZl_comm_c = cell2mat(groupSector(S, commInd, 'vert'));
        end
        Slc = matCell2Mat(S);
        r.local{i} = reshape(mean(Slc,1,'omitnan'),N,N);
        r.local_Z{i} = reshape(mean(Slc,1,'omitnan'),N,N);
        r.local{i}(1:(N+1):end) = 0;
        r.local_Z{i}(1:(N+1):end) = 0;
        r.local_theta(i) = mean(Slc(:),'omitnan');
        r.localStd_theta(i) = std(Slc(:),'omitnan');
        r.localAll_theta{i} = mean(Slc,2,'omitnan');
        r.local_lobe{i} = reshape(mean(SZl_lobe_c,1,'omitnan'),numel(lobeInd),1);
        r.local_lobeLR{i} = reshape(mean(SZl_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
        r.local_comm{i} = reshape(mean(SZl_comm_c,1,'omitnan'),numel(commInd),1);
        if tTestAvgNotSample
            r.localStd_lobe{i} = reshape(sqrt(mean(SZl_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
            r.localStd_lobeLR{i} = reshape(sqrt(mean(SZl_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
            r.localStd_comm{i} = reshape(sqrt(mean(SZl_comm_c_var,1,'omitnan')),numel(commInd),1);
        else
            r.localStd_lobe{i} = reshape(std(SZl_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
            r.localStd_lobeLR{i} = reshape(std(SZl_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
            r.localStd_comm{i} = reshape(std(SZl_comm_c,[],1,'omitnan'),numel(commInd),1);
        end
    else
        SZl_lobe_c = []; SZl_lobeLR_c = []; SZl_comm_c = []; Slc = [];
    end
    S = su.Ulocalnet(cInd);
    SZ_sort = sortMatrices(S,sortInd);
    if tTestAvgNotSample
        SZln_lobe_c = matCell2Mat(averageSector(SZ_sort, lobeInd, 'vert'));
        SZln_lobeLR_c = matCell2Mat(averageSector(SZ_sort, lobeIndLR, 'vert'));
        SZln_comm_c = matCell2Mat(averageSector(S, commInd, 'vert'));

        SZln_lobe_c_var = matCell2Mat(varianceSector(SZ_sort, lobeInd, 'vert'));
        SZln_lobeLR_c_var = matCell2Mat(varianceSector(SZ_sort, lobeIndLR, 'vert'));
        SZln_comm_c_var = matCell2Mat(varianceSector(S, commInd, 'vert'));
    else
        SZln_lobe_c = cell2mat(groupSector(SZ_sort, lobeInd, 'vert'));
        SZln_lobeLR_c = cell2mat(groupSector(SZ_sort, lobeIndLR, 'vert'));
        SZln_comm_c = cell2mat(groupSector(S, commInd, 'vert'));
    end
    Slnc = matCell2Mat(S);
    r.localnet{i} = reshape(mean(Slnc,1,'omitnan'),N,N);
    r.localnet_Z{i} = reshape(mean(Slnc,1,'omitnan'),N,N);
    r.localnet{i}(1:(N+1):end) = 0;
    r.localnet_Z{i}(1:(N+1):end) = 0;
    r.localnet_theta(i) = mean(Slnc(:),'omitnan');
    r.localnetStd_theta(i) = std(Slnc(:),'omitnan');
    r.localnetAll_theta{i} = mean(Slnc,2,'omitnan');
    r.localnet_lobe{i} = reshape(mean(SZln_lobe_c,1,'omitnan'),numel(lobeInd),1);
    r.localnet_lobeLR{i} = reshape(mean(SZln_lobeLR_c,1,'omitnan'),numel(lobeIndLR),1);
    r.localnet_comm{i} = reshape(mean(SZln_comm_c,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.localnetStd_lobe{i} = reshape(sqrt(mean(SZln_lobe_c_var,1,'omitnan')),numel(lobeInd),1);
        r.localnetStd_lobeLR{i} = reshape(sqrt(mean(SZln_lobeLR_c_var,1,'omitnan')),numel(lobeIndLR),1);
        r.localnetStd_comm{i} = reshape(sqrt(mean(SZln_comm_c_var,1,'omitnan')),numel(commInd),1);
    else
        r.localnetStd_lobe{i} = reshape(std(SZln_lobe_c,[],1,'omitnan'),numel(lobeInd),1);
        r.localnetStd_lobeLR{i} = reshape(std(SZln_lobeLR_c,[],1,'omitnan'),numel(lobeIndLR),1);
        r.localnetStd_comm{i} = reshape(std(SZln_comm_c,[],1,'omitnan'),numel(commInd),1);
    end
end

function r = CalcSpeedUpTTest(r,i,hasLocalSpeedUp,alphaTTest,alphaFDR,splitTTest,N,lobeInd,lobeIndLR,commInd,SZg_comm_c,SZg_comm_p,SZg_lobeLR_c,...
                              SZg_lobeLR_p,SZg_lobe_c,SZg_lobe_p,SZl_comm_c,SZl_comm_p,SZl_lobeLR_c,SZl_lobeLR_p,SZl_lobe_c,SZl_lobe_p,...
                              SZln_comm_c,SZln_comm_p,SZln_lobeLR_c,SZln_lobeLR_p,SZln_lobe_c,SZln_lobe_p,Sgc,Sgp,Slc,Slp,Slnc,Slnp,tTestProp)
    r.global(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sgc,Sgp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.global_theta(i) = ttest.ttest2Struct(Sgc(:),Sgp(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
    r.global_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZg_lobe_c,SZg_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeInd),1]);
    r.global_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZg_lobeLR_c,SZg_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeIndLR),1]);
    r.global_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZg_comm_c,SZg_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(commInd),1]);
    r.localnet(i) = ttest.reshapeTTest(ttest.ttest2Struct(Slnc,Slnp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.localnet_theta(i) = ttest.ttest2Struct(Slnc(:),Slnp(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
    r.localnet_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZln_lobe_c,SZln_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeInd),1]);
    r.localnet_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZln_lobeLR_c,SZln_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeIndLR),1]);
    r.localnet_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZln_comm_c,SZln_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(commInd),1]);
    if hasLocalSpeedUp%~isempty(ts.Tn{1})
        r.local(i) = ttest.reshapeTTest(ttest.ttest2Struct(Slc,Slp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
        r.local_theta(i) = ttest.ttest2Struct(Slnc(:),Slnp(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
        r.local_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZl_lobe_c,SZl_lobe_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeInd),1]);
        r.local_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZl_lobeLR_c,SZl_lobeLR_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(lobeIndLR),1]);
        r.local_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(SZl_comm_c,SZl_comm_p,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[numel(commInd),1]);
    end
end

function [r,rCm] = processSpreadingMatrix(s, cInd, pInd, sp, cm, ggamma, ct, hv, ttestProp, calcCommOnly, lobeIndLR, lobeInd, sortInd, tTestAvgNotSample)
    if (nargin < 8) || isempty(calcCommOnly)
        calcCommOnly = false;
    end
    commInd = getCommGroups(cm,ggamma);
    if calcCommOnly
        r = [];
    else
        r = processSpreadingMatrix_internal(s, cInd, pInd, sp, ct, hv, ttestProp, lobeIndLR, lobeInd, commInd, sortInd, tTestAvgNotSample);
    end
    rCm = processSpreadingMatrix_internal(getCommunityData(s, cm, ggamma), cInd, pInd, ShortPathToShortPathMod(sp, cm, ggamma), getCortThickComm(ct, cm, ggamma, s(1).N), hv, ttestProp,...
                                          num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), num2cell(1:numel(commInd)), 1:numel(commInd), tTestAvgNotSample);
    %rCm = processSpreadingMatrix_internal(SpMatrixToSpMatrixMod(s, cm, ggamma), cInd, pInd, ShortPathToShortPathMod(sp, cm, ggamma), alphaTTest);
end

% function r = SpMatrixToSpMatrixMod(s, cm, ggamma)
%     r = s;
%     for i = 1:numel(s)
%         [r(i).data.SAvg,nComm] = calcCommunityAvgSpreadingTime(s(i).data.SAvg, cm, ggamma);
%         r(i).data.SAvg_Z = ZScoreMatrix(r(i).data.SAvg);
%         r(i).N = nComm;
%     end
% end

function r = processSpreadingMatrix_internal(s, cInd, pInd, sp, ct, hv, tTestProp, lobeIndLR, lobeInd, commInd, sortInd, tTestAvgNotSample)
    [alphaTTest,tTestProp] = getParamValue('AlphaTTest',tTestProp,true);
    [alphaFDR,tTestProp] = getParamValue('AlphaFDR',tTestProp,true);
    [splitTTest,tTestProp] = getParamValue('SplitNegPos',tTestProp,true);
    N = s(1).N;
    if (N == 9) || (N >= 78) % Yeo Comm or std AAL
        [mtlIndL,mtlIndR,mtlLabL,mtlLabR] = getMTLNodeIndex(s(1).N);
    else
        mtlIndL = []; mtlIndR = []; mtlLabL = []; mtlLabR = [];
    end
    r.N = N;
    r.header = {'',s(1).header;...
                'SAvgRS_node', 'same as SAvg_node, but t-tested using send and receive spreading times in a multivariate fashion';...
                'SZRS_mtlL', 'same as SZ_mtlL, but t-tedted using send and receive spreading times in a multivariate fashion';...
                'SZRS_mtlR', 'same as SZ_mtlR, but t-tedted using send and receive spreading times in a multivariate fashion';...
                'SZ'         ,'sp time matrix (averaged over each subject)';...
                'SZ_HV'      ,'sp time matrix (averaged over each subject) controlling for HV';...
                'SZ_CT'      ,'sp time matrix (averaged over each subject) controlling for CT';...
                'SZ_node'    ,'sp time matrix (averaged over each subject, t-test node per node instead of whole matrix)';...
                'SZS_mtlL'    ,'sp time matrix lines (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes';...
                'SZS_mtlR'    ,'sp time matrix lines (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes';...
                'SZStdS_mtlL' ,'Std dev of the Z-score matrix lines (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes';...
                'SZStdS_mtlR' ,'Std dev of the Z-score matrix lines (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes';...
                'SZR_mtlL'    ,'sp time matrix cols (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes';...
                'SZR_mtlR'    ,'sp time matrix cols (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes';...
                'SZStdR_mtlL' ,'Std dev of the Z-score matrix cols (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes';...
                'SZStdR_mtlR' ,'Std dev of the Z-score matrix cols (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes';...
                'SZ_mtlL_all','Z-score matrix lines (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes (seeding from all the MTL-L)';...
                'SZ_mtlR_all','Z-score matrix lines (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes (seeding from all the MTL-R)';...
                'SZStd_mtlL_all' ,'Std dev of the Z-score matrix lines (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes (seeding from all the MTL-L)';...
                'SZStd_mtlR_all' ,'Std dev of the Z-score matrix lines (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes (seeding from all the MTL-L)';...
                'SZ_mtlL_lobe','Z-score matrix (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes per target lobe';...
                'SZ_mtlR_lobe','Z-score matrix (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes per target lobe';...
                'SZ_mtlL_lobeLR','Z-score matrix (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes per target lobe';...
                'SZ_mtlR_lobeLR','Z-score matrix (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes per target lobe';...
                'SZ_mtlL_comm','Z-score matrix (averaged over each subject) for the L (Ipsi) Mesio-Temporal Lobe nodes per target functional community';...
                'SZ_mtlR_comm','Z-score matrix (averaged over each subject) for the R (Contra) Mesio-Temporal Lobe nodes per target functional community';...
                'SPdiff_edge','SpTime - ShortestPath matrix difference averaged over subjects';...
                'SPdiff_node','SpTime - ShortestPath matrix difference averaged over subjects and seeds';...
                'Pdiff_edge' ,'Prob of finding a pair (seed-target) that has different SpTime and ShortPath';...
                'Pdiff_node' ,'Prob of finding a node that has different SpTime and ShortPath considering all seeds';...
                'SAll_theta','average spreading time for each theta for all cases';...
                'SAvg_theta','Spreading times averaged over seeds, targets and subjects';...
                'SAvgR_node' ,'Spreading times averaged over seeds (receiving times)';...
                'SAvgS_node' ,'Spreading times averaged over seeds (receiving times)';...
                'SStd_theta','Total variance over seeds, targets and subjects';...
                'SStd_node' ,'Variance of the averaged (subject-wise) spreading times for a given target (receiving times)';...
                'SErr_theta','Total variance over seeds, targets and subjects';...
                'SErr_node' ,'Variance of the averaged (subject-wise) spreading times for a given target (receiving times)';...
                'SZS_lobe' ,'Average out spreading time over nodes of same AAL lobe for each theta';...
                'SZS_lobeLR','Average out spreading time over nodes of same AAL lobe for each theta';...
                'SZS_comm' ,'Average out spreading time over nodes of same Yeo communities for each theta';...
                'SZR_lobe' ,'Average in spreading time over nodes of same AAL lobe for each theta';...
                'SZR_lobeLR','Average in spreading time over nodes of same AAL lobe for each theta';...
                'SZR_comm' ,'Average in spreading time over nodes of same Yeo communities for each theta';...
                'SZB_lobe' ,'Average block spreading time over only nodes of same AAL lobe for each theta';...
                'SZB_lobeLR','Average block spreading time over only nodes of same AAL lobe for each theta';...
                'SZB_comm' ,'Average block spreading time over only nodes of same Yeo communities for each theta';...
                'SZStdS_lobe' ,'std dev out spreading time over nodes of same AAL lobe for each theta';...
                'SZStdS_lobeLR','std dev out spreading time over nodes of same AAL lobe for each theta';...
                'SZStdS_comm' ,'std dev out spreading time over nodes of same Yeo communities for each theta';...
                'SZStdR_lobe' ,'std dev in spreading time over nodes of same AAL lobe for each theta';...
                'SZStdR_lobeLR','std dev in spreading time over nodes of same AAL lobe for each theta';...
                'SZStdR_comm' ,'std dev in spreading time over nodes of same Yeo communities for each theta';...
                'SZStdB_lobe' ,'std dev block spreading time over only nodes of same AAL lobe for each theta';...
                'SZStdB_lobeLR','std dev block spreading time over only nodes of same AAL lobe for each theta';...
                'SZStdB_comm' ,'std dev block spreading time over only nodes of same Yeo communities for each theta';...
                'D_theta'   ,'Hamming distance D(S,P) between receiving times and shortest path averaged over nodes and subjects';...
                'DErr_theta','Hamming distance stddev err D(S,P) between receiving times and shortest path averaged over nodes and subjects';...
                'DStd_theta','Hamming distance stddev D(S,P) between receiving times and shortest path averaged over nodes and subjects';...
                'DAll_theta','Hamming distance D(S,P) between receiving times and shortest path averaged over nodes for all cases';...
                'D_node'    ,'Hamming distance D(S,P) averaged over subjects for each node';...
                'DErr_node' ,'Hamming distance D(S,P) averaged over subjects for each node';...
                'DStd_node' ,'Hamming distance D(S,P) averaged over subjects for each node';...
                'D_lobe'    ,'Average Hamming distance over nodes of same lobe for each theta';...
                'D_lobeLR'  ,'Average Hamming distance over nodes of same lobe for each theta';...
                'D_comm'    ,'Average Hamming distance over nodes of same Yeo communities for each theta';...
                'I'         ,'Isolation of each node (fraction of subjects that got a given node disconnected for each theta)';...
                'CTAll'         ,'Avg cortical thickness for all subjects' ;...
                'CT_node'       ,'Avg cortical thickness for each AAL parcel (it is not normalized by parcel size) for all subjects' ;...
                'SAvg_CT_theta' ,'t-test between group avg sp times controlling for cort thickness' ;...
                'SAvg_CT_node'  ,'t-test between nodal group avg in/out sp times controlling for cort thickness' ;...
                'HVAll'         ,'hip volume for all subjects' ;...
                'SAvg_HV_theta' ,'t-test between group avg sp times controlling for hip vol' ;...
                'SAvg_HV_node'  ,'t-test between nodal group in/out sp times controlling for hip vol' ;...
                'SZS_mtlL_CT', '';...
                'SZS_mtlR_CT', '';...
                'SZR_mtlL_CT', '';...
                'SZR_mtlR_CT', '';...
                'SZRS_mtlL_CT', '';...
                'SZRS_mtlR_CT', '';...
                'SZ_mtlL_lobe_CT', '';...
                'SZ_mtlR_lobe_CT', '';...
                'SZ_mtlL_lobeLR_CT', '';...
                'SZ_mtlR_lobeLR_CT', '';...
                'SZ_mtlL_comm_CT', '';...
                'SZ_mtlR_comm_CT', '';...
                'SZS_mtlL_HV', '';...
                'SZS_mtlR_HV', '';...
                'SZR_mtlL_HV', '';...
                'SZR_mtlR_HV', '';...
                'SZRS_mtlL_HV', '';...
                'SZRS_mtlR_HV', '';...
                'SZ_mtlL_lobe_HV', '';...
                'SZ_mtlR_lobe_HV', '';...
                'SZ_mtlL_lobeLR_HV', '';...
                'SZ_mtlR_lobeLR_HV', '';...
                'SZ_mtlL_comm_HV', '';...
                'SZ_mtlR_comm_HV', '';...
                'ttest'     ,'if h=1, then controls and patients are statistically independent; h=0 means they are statistically equal'};

    if (N == 9) || (N >= 78)
        r.mtlLabL = mtlLabL;
        r.mtlLabR = mtlLabR;
    else
        r.mtlLabL = '';
        r.mtlLabR = '';
    end
    r.theta = [ s(:).theta ];
    nT = numel(r.theta);
    r.nSim = s(1).nSim;

    dataFields      =         {            'SZ',          'SZ_HV',            'SZ_CT',           'SZStd',          'SZ_node',      'SZStd_node',      'SZS_mtlL',      'SZS_mtlR',  'SZStdS_mtlL',   'SZStdS_mtlR', ...
                              'SAll_mtlL_theta','SAll_mtlR_theta', 'SAllR_mtlL_theta','SAllR_mtlR_theta', 'SAllS_mtlL_theta','SAllS_mtlR_theta', ...
                                     'SZR_mtlL',       'SZR_mtlR',    'SZStdR_mtlL',    'SZStdR_mtlR', ...
                                  'SAvgRS_node',    'SStdRS_node',      'SZRS_mtlL',      'SZRS_mtlR',  'SZStdRS_mtlL',  'SZStdRS_mtlR', ...
                                  'SZ_mtlL_all',    'SZ_mtlR_all', 'SZStd_mtlL_all', 'SZStd_mtlR_all',  'SZ_mtlL_lobe',  'SZ_mtlR_lobe', ...
                               'SZ_mtlL_lobeLR', 'SZ_mtlR_lobeLR',   'SZ_mtlL_comm',   'SZ_mtlR_comm',   'SPdiff_edge',   'SPdiff_node', ...
                                   'Pdiff_edge',     'Pdiff_node',     'SAvg_theta',     'SStd_theta',    'SErr_theta',    'SAvgR_node', ...
                                   'SAvgS_node',     'SErrR_node',     'SErrS_node',     'SStdR_node',    'SStdS_node',    'SAll_theta',     'SZS_lobe',    'SZS_lobeLR', ...
                                     'SZS_comm',       'SZR_lobe',     'SZR_lobeLR',       'SZR_comm',      'SZB_lobe',    'SZB_lobeLR',     'SZB_comm', ...
                                  'SZStdS_lobe',  'SZStdS_lobeLR',    'SZStdS_comm',    'SZStdR_lobe', 'SZStdR_lobeLR',   'SZStdR_comm',  'SZStdB_lobe', 'SZStdB_lobeLR',   'SZStdB_comm', ...
                                   'DAll_theta',        'D_theta',     'DErr_theta',     'DStd_theta',        'D_node',     'DErr_node',    'DStd_node',        'D_lobe',      'D_lobeLR',      'D_comm',         'I', ...
                                        'CTAll',        'CT_node',  'SAvg_CT_theta', 'SAvgRS_CT_node',         'HVAll','SAvgRS_HV_theta', 'SAvg_HV_node', ...
                                'SAvgR_CT_node', 'SAvgR_HV_theta',  'SAvgS_CT_node', 'SAvgS_HV_theta', ...
                                  'SZS_mtlL_CT',    'SZS_mtlR_CT',    'SZR_mtlL_CT',    'SZR_mtlR_CT',  'SZRS_mtlL_CT',  'SZRS_mtlR_CT', 'SZ_mtlL_lobe_CT', 'SZ_mtlR_lobe_CT', 'SZ_mtlL_lobeLR_CT', 'SZ_mtlR_lobeLR_CT', 'SZ_mtlL_comm_CT', 'SZ_mtlR_comm_CT', ...
                                  'SZS_mtlL_HV',    'SZS_mtlR_HV',    'SZR_mtlL_HV',    'SZR_mtlR_HV',  'SZRS_mtlL_HV',  'SZRS_mtlR_HV', 'SZ_mtlL_lobe_HV', 'SZ_mtlR_lobe_HV', 'SZ_mtlL_lobeLR_HV', 'SZ_mtlR_lobeLR_HV', 'SZ_mtlL_comm_HV', 'SZ_mtlR_comm_HV', ...
                            'SZStd_mtlL_lobe','SZStd_mtlR_lobe','SZStd_mtlL_lobeLR','SZStd_mtlR_lobeLR',   'SZStd_mtlL_comm',   'SZStd_mtlR_comm',...
                                  'SZR_lobe_CT',  'SZR_lobeLR_CT',    'SZR_comm_CT',    'SZS_lobe_CT', 'SZS_lobeLR_CT',   'SZS_comm_CT',     'SZB_lobe_CT',   'SZB_lobeLR_CT',       'SZB_comm_CT',...
                                  'SZR_lobe_HV',  'SZR_lobeLR_HV',    'SZR_comm_HV',    'SZS_lobe_HV', 'SZS_lobeLR_HV',   'SZS_comm_HV',     'SZB_lobe_HV',   'SZB_lobeLR_HV',       'SZB_comm_HV' };
    defaultFieldVal =         {      cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),     cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT),     cell(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),     cell(1,nT),       cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),      zeros(1,nT),      zeros(1,nT),     zeros(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT),     cell(1,nT),      cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT),     cell(1,nT), ...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT),     cell(1,nT),      cell(1,nT),    cell(1,nT), ...
                                     cell(1,nT),      zeros(1,nT),      zeros(1,nT),      zeros(1,nT),      cell(1,nT),      cell(1,nT),     cell(1,nT),      cell(1,nT),    cell(1,nT), cell(1,nT),  cell(1,nT), ...
                                     zeros(0,1),        cell(1,0),               [],               [],      zeros(0,1),              [],             [], ...
                                             [],               [],               [],               [], ...
                                             [],               [],               [],               [],              [],              [],             [],              [],            [],         [],          [],         [],...
                                             [],               [],               [],               [],              [],              [],             [],              [],            [],         [],          [],         [],...
                                     cell(1,nT),       cell(1,nT),       cell(1,nT),       cell(1,nT),      cell(1,nT),      cell(1,nT),...
                                             [],               [],               [],               [],              [],              [],             [],              [],            [],...
                                             [],               [],               [],               [],              [],              [],             [],              [],            [] };
    fieldHasTTest   = logical([               1,                1,                1,                0,               1,               0,              1,               1,              0,             0, ...
                                              0,                0,                0,                0,               0,               0, ...
                                              1,                1,                0,                0, ...
                                              1,                0,                1,                1,               0,               0, ...
                                              1,                1,                0,                0,               1,               1, ...
                                              1,                1,                1,                1,               1,               1, ...
                                              0,                0,                1,                0,               0,               1, ...
                                              1,                0,                0,                0,               0,               0,              1,               1, ...
                                              1,                1,                1,                1,               1,               1,              1, ...
                                              0,                0,                0,                0,               0,               0,              0,               0,             0, ...
                                              0,                1,                0,                0,               1,               0,              0,               1,             1,         1,           0, ...
                                              1,                1,                1,                1,               1,               1,              1, ...
                                              1,                1,                1,                1, ...
                                              1,                1,                1,                1,               1,               1,              1,   1, 1, 1, 1, 1,...
                                              1,                1,                1,                1,               1,               1,              1,   1, 1, 1, 1, 1,...
                                              0,                0,                0,                0,               0,               0,...
                                              1,                1,                1,                1,               1,               1,              1,               1,             1,...
                                              1,                1,                1,                1,               1,               1,              1,               1,             1 ]);

    r.controlData = cell2struct(defaultFieldVal, dataFields, 2);
    r.patientData = cell2struct(defaultFieldVal, dataFields, 2);
    r.ttest = cell2struct(cellfun(@(x)ttest.ttest2Struct(),cell(1,numel(find(fieldHasTTest))),'UniformOutput',false),dataFields(fieldHasTTest),2);
    r.flip = rmfield(r,'header');
    r.zToControl = r.flip;
    
    Pz = zScoreToSubset(sp.P,cInd);
    if (N == 90) || (N == 306)
        if isempty(s(1).flipData)
            P = sp.P;
        else
            P = zScoreAndFlipShortestPath(sp.P,cInd,s(1).flipData.SAvg);
        end
    else
        P = Pz;
    end
    
    ct = groupCortThick(ct,cInd,pInd);
    hv = groupHippVolume(hv,cInd,pInd);

    for i = 1:nT
        r = CalcSpMatrixOutput_theta(r,i,s(i).data,sp.P,ct.raw,hv.raw,hv.excludedInd,0,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp); % calculates controlData, patientData and ttest fields of r
        r.flip = CalcSpMatrixOutput_theta(r.flip,i,s(i).flipData,P,ct.flip,hv.flip,hv.excludedInd,1e-4,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp);
        r.zToControl = CalcSpMatrixOutput_theta(r.zToControl,i,s(i).zControlData,Pz,ct.zToControls,hv.zToControls,hv.excludedInd,0,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp); % calculates controlData, patientData and ttest fields of r
    end

    r.controlData.CTAll = ct.raw.cData.CT; r.controlData.CT_node = ct.raw.cData.CT_node;
    r.patientData.CTAll = ct.raw.pData.CT; r.patientData.CT_node = ct.raw.pData.CT_node;
    r.flip.controlData.CTAll = ct.flip.cData.CT; r.flip.controlData.CT_node = ct.flip.cData.CT_node;
    r.flip.patientData.CTAll = ct.flip.pData.CT; r.flip.patientData.CT_node = ct.flip.pData.CT_node;
    r.zToControl.controlData.CTAll = ct.zToControls.cData.CT; r.zToControl.controlData.CT_node = ct.zToControls.cData.CT_node;
    r.zToControl.patientData.CTAll = ct.zToControls.pData.CT; r.zToControl.patientData.CT_node = ct.zToControls.pData.CT_node;

    r.controlData.HVAll = hv.raw.cData.HV; r.patientData.HVAll = hv.raw.pData.HV;
    r.flip.controlData.HVAll = hv.flip.cData.HV; r.flip.patientData.HVAll = hv.flip.pData.HV;
    r.zToControl.controlData.HVAll = hv.zToControls.cData.HV; r.zToControl.patientData.HVAll = hv.zToControls.pData.HV;

    r.flip.controlData = correctNumericPrecision_cell(r.flip.controlData,1e-8);
    r.zToControl.controlData = correctNumericPrecision_cell(r.zToControl.controlData,1e-8);
    r.flip.patientData = correctNumericPrecision_cell(r.flip.patientData,1e-8);
    r.zToControl.patientData = correctNumericPrecision_cell(r.zToControl.patientData,1e-8);
end

function r = CalcSpMatrixOutput_theta(r,i,s,shortPath,ct,hv,hvAbsent,hammDistPrecision,N,cInd,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,alphaTTest,alphaFDR,splitTTest,tTestAvgNotSample,tTestProp)
    if isempty(s)
        return;
    end
    [r.controlData,Dc,DcM,Dcc,DlLRc,Dlc,SPc_diff,SPc_diff_edge,Sc,ScBc,...
      ScRc,ScSc,ScZ_mtlL,ScZ_mtlL_all,...
      ScZ_mtlL_comm,ScZ_mtlL_lobe,ScZ_mtlL_lobeLR,ScZ_mtlR,...
      ScZ_mtlR_all,ScZ_mtlR_comm,ScZ_mtlR_lobe,...
      ScZ_mtlR_lobeLR,SlBc,SlLRBc,SlLRRc,SlLRSc,SlRc,SlSc,...
      SnRc,SnSc,ScHV] = CalcSpMatrixOutput(r.controlData,i,s,shortPath,hammDistPrecision,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample,hvAbsent);

    if numel(pInd) > 0
        [r.patientData,Dp,DpM,Dcp,DlLRp,Dlp,SPp_diff,SPp_diff_edge,Sp,ScBp,...
          ScRp,ScSp,SpZ_mtlL,SpZ_mtlL_all,...
          SpZ_mtlL_comm,SpZ_mtlL_lobe,SpZ_mtlL_lobeLR,SpZ_mtlR,...
          SpZ_mtlR_all,SpZ_mtlR_comm,SpZ_mtlR_lobe,...
          SpZ_mtlR_lobeLR,SlBp,SlLRBp,SlLRRp,SlLRSp,SlRp,SlSp,...
          SnRp,SnSp,SpHV] = CalcSpMatrixOutput(r.patientData,i,s,shortPath,hammDistPrecision,N,pInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample,hvAbsent);

        r.ttest = CalcSpMatrixTTest(r.ttest,i,alphaTTest,alphaFDR,splitTTest,N,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,...
                               Dc,Dp,DcM,DpM,Dcc,Dcp,DlLRc,DlLRp,Dlc,Dlp,SPc_diff,SPp_diff,SPc_diff_edge,SPp_diff_edge,...
                               Sc,Sp,ScBc,ScBp,ScRc,ScRp,ScSc,ScSp,ScZ_mtlL,SpZ_mtlL,...
                               ScZ_mtlL_all,SpZ_mtlL_all,ScZ_mtlL_comm,SpZ_mtlL_comm,ScZ_mtlL_lobe,SpZ_mtlL_lobe,ScZ_mtlL_lobeLR,...
                               SpZ_mtlL_lobeLR,ScZ_mtlR,SpZ_mtlR,ScZ_mtlR_all,SpZ_mtlR_all,ScZ_mtlR_comm,SpZ_mtlR_comm,...
                               ScZ_mtlR_lobe,SpZ_mtlR_lobe,ScZ_mtlR_lobeLR,SpZ_mtlR_lobeLR,SlBc,SlBp,SlLRBc,SlLRBp,SlLRRc,...
                               SlLRRp,SlLRSc,SlLRSp,SlRc,SlRp,SlSc,SlSp,SnRc,SnRp,SnSc,SnSp,ct,hv,ScHV,SpHV,hvAbsent,cInd,pInd,tTestProp);
    end
end

% apaguei da saída
%    ScZ,
function [r,Dc,DcM,Dcc,DlLRc,Dlc,SPc_diff,SPc_diff_edge,Sc,ScBc,...
          ScRc,ScSc,ScZS_mtlL,ScZ_mtlL_all,...
          ScZ_mtlL_comm,ScZ_mtlL_lobe,ScZ_mtlL_lobeLR,ScZS_mtlR,...
          ScZ_mtlR_all,ScZ_mtlR_comm,ScZ_mtlR_lobe,...
          ScZ_mtlR_lobeLR,SlBc,SlLRBc,SlLRRc,SlLRSc,SlRc,SlSc,...
          SnRc,SnSc,ScHV] = CalcSpMatrixOutput(r,i,s,shortPath,hammDistPrecision,N,cInd,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,sortInd,tTestAvgNotSample,hvAbsent)
% i -> index of the theta value

    cIndHV = setdiff(cInd,hvAbsent);
    S = s.SAvg(cInd); % spreading time matrices (could be z-scored to controls if s comes from s(i).zControlData in the external function that calls this one)
    Sc = matCell2Mat(S); % table of the spreading time matrices (each row is a linearized matrix of a given subject)
    ScHV = matCell2Mat(s.SAvg(cIndHV));
    ScZ_sort = sortMatrices(S, sortInd); % sorting each subject's Sp Time matrix according to sortInd

    if isfield(s,'D_node')
        % highlighting nodes and edges that have spreading times which are different from the binary shortest path matrix
        PmC = matCell2Mat(shortPath(cInd)); % short path table
        SPc_diff = Sc - PmC;
        SPc_diff_edge = reshape(mean(SPc_diff,1,'omitnan'),N,N); % mean (over subjects) difference between sp time and short path for each pair of nodes
        PcDiff_edge = reshape(sum(SPc_diff~=0,1),N,N)./numel(cInd); % normalized number of times that a given edge differed between sp time and short path in the considered group cInd
        PcDiff_node = sum(PcDiff_edge,1)./N; % normalized number of times a given node differed between in sp time and short path inside the considered group cInd
    else
        SPc_diff = [];
        SPc_diff_edge = [];
    end

    if (N == 9) || (N >= 78) % Yeo Comm or std AAL
        ScZS_mtlL = matCell2Mat(selectLinesOrCols(S, mtlIndL, 'line')); % table with MTL-L sp times (out) for every subject (lines)
        ScZS_mtlR = matCell2Mat(selectLinesOrCols(S, mtlIndR, 'line')); % same as above for MTL-R
        ScZ_mtlL_all = matCell2Mat(myMin(selectLinesOrCols(S, mtlIndL, 'line'),1)); % table with MTL-L sp times (out) seed simultaneously from all MTL-L nodes
        ScZ_mtlR_all = matCell2Mat(myMin(selectLinesOrCols(S, mtlIndR, 'line'),1)); % same as above for MTL-R
        if tTestAvgNotSample
            ScZ_mtlL_lobe = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeInd, 'line')); % out sp times from MTL-L to all the network averaged over lobe -- organized as tables (line == subject)
            ScZ_mtlR_lobe = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeInd, 'line')); % same as above for MTL-R
            ScZ_mtlL_lobeLR = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeIndLR, 'line')); % out sp times from MTL-L to all the network averaged over L and R lobes (line == subject)
            ScZ_mtlR_lobeLR = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeIndLR, 'line')); % same as above for MTL-R
            ScZ_mtlL_comm = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndL, 'line'), commInd, 'line')); % out sp times from MTL-L to all the network averaged over functional communities (line == subject)
            ScZ_mtlR_comm = matCell2Mat(averageSector(selectLinesOrCols(S, mtlIndR, 'line'), commInd, 'line')); % same as above for MTL-R
            
            ScZ_mtlL_lobe_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeInd, 'line')); % out sp times from MTL-L to all the network averaged over lobe -- organized as tables (line == subject)
            ScZ_mtlR_lobe_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeInd, 'line')); % same as above for MTL-R
            ScZ_mtlL_lobeLR_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeIndLR, 'line')); % out sp times from MTL-L to all the network averaged over L and R lobes (line == subject)
            ScZ_mtlR_lobeLR_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeIndLR, 'line')); % same as above for MTL-R
            ScZ_mtlL_comm_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndL, 'line'), commInd, 'line')); % out sp times from MTL-L to all the network averaged over functional communities (line == subject)
            ScZ_mtlR_comm_var = matCell2Mat(varianceSector(selectLinesOrCols(S, mtlIndR, 'line'), commInd, 'line')); % same as above for MTL-R
        else
            ScZ_mtlL_lobe = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeInd, 'line')), lobeInd, numel(mtlIndL)); % out sp times from MTL-L to all the network averaged over lobe -- organized as tables (line == subject)
            ScZ_mtlR_lobe = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeInd, 'line')), lobeInd, numel(mtlIndR)); % same as above for MTL-R
            ScZ_mtlL_lobeLR = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndL, 'line'), lobeIndLR, 'line')), lobeIndLR, numel(mtlIndL)); % out sp times from MTL-L to all the network averaged over L and R lobes (line == subject)
            ScZ_mtlR_lobeLR = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndR, 'line'), lobeIndLR, 'line')), lobeIndLR, numel(mtlIndR)); % same as above for MTL-R
            ScZ_mtlL_comm = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndL, 'line'), commInd, 'line')), commInd, numel(mtlIndL)); % out sp times from MTL-L to all the network averaged over functional communities (line == subject)
            ScZ_mtlR_comm = reorgMatrixSectorLineGroup(matCell2Mat(groupSector(selectLinesOrCols(S, mtlIndR, 'line'), commInd, 'line')), commInd, numel(mtlIndR)); % same as above for MTL-R
        end
    else
        ScZS_mtlL = []; ScZS_mtlR = []; ScZ_mtlL_all = []; ScZ_mtlR_all = []; ScZ_mtlL_lobe = [];
        ScZ_mtlR_lobe = []; ScZ_mtlL_lobeLR = []; ScZ_mtlR_lobeLR = []; ScZ_mtlL_comm = []; ScZ_mtlR_comm = [];
    end

    % the variables below are tables in which each line is a subject,
    % and each column corresponds to either a node of the network or a lobe, or a community
    % i.e. all the spreading times corresponding to that particular node (or lobe or comm) of a given subject is averaged in a single
    % cell of the matrices below
    % instead of computing these averages at this stage, I will generate tables in which columns are still nodes (or lobes or comm),
    % but lines correspond to spreading times (instead of subjects)
    % having the actual spreading times as lines helps increasing the t-test sensibility
    %
    if tTestAvgNotSample
        SnRc = matCell2Mat(myMean(S,1,'omitnan')); % average in sp time (table, subj == line)
        SnSc = matCell2Mat(myMean(S,2,'omitnan')); % average out sp time (table, subj == line)
        SlRc = matCell2Mat(averageSector(ScZ_sort,lobeInd,'horiz')); % in sp time averaged in lobes 
        SlSc = matCell2Mat(averageSector(ScZ_sort,lobeInd,'vert')); % out sp time averaged in lobes
        SlBc = matCell2Mat(averageSector(ScZ_sort,lobeInd,'block')); % in-out averaged sp time for each lobes
        SlLRRc = matCell2Mat(averageSector(ScZ_sort,lobeIndLR,'horiz')); % in sp time averaged in L and R lobes
        SlLRSc = matCell2Mat(averageSector(ScZ_sort,lobeIndLR,'vert')); % out sp time averaged in L and R lobes
        SlLRBc = matCell2Mat(averageSector(ScZ_sort,lobeIndLR,'block')); % in-out averaged sp time for each L and R lobes
        ScRc = matCell2Mat(averageSector(S,commInd,'horiz')); % in sp time averaged in func comm
        ScSc = matCell2Mat(averageSector(S,commInd,'vert')); % out sp time averaged in func comm
        ScBc = matCell2Mat(averageSector(S,commInd,'block')); % in-out sp time averaged for each func comm
        
        SnRc_var = matCell2Mat(myVar(S,0,1,'omitnan')); % average in sp time (table, subj == line)
        SnSc_var = matCell2Mat(myVar(S,0,2,'omitnan')); % average out sp time (table, subj == line)
        SlRc_var = matCell2Mat(varianceSector(ScZ_sort,lobeInd,'horiz')); % in sp time averaged in lobes 
        SlSc_var = matCell2Mat(varianceSector(ScZ_sort,lobeInd,'vert')); % out sp time averaged in lobes
        SlBc_var = matCell2Mat(varianceSector(ScZ_sort,lobeInd,'block')); % in-out averaged sp time for each lobes
        SlLRRc_var = matCell2Mat(varianceSector(ScZ_sort,lobeIndLR,'horiz')); % in sp time averaged in L and R lobes
        SlLRSc_var = matCell2Mat(varianceSector(ScZ_sort,lobeIndLR,'vert')); % out sp time averaged in L and R lobes
        SlLRBc_var = matCell2Mat(varianceSector(ScZ_sort,lobeIndLR,'block')); % in-out averaged sp time for each L and R lobes
        ScRc_var = matCell2Mat(varianceSector(S,commInd,'horiz')); % in sp time averaged in func comm
        ScSc_var = matCell2Mat(varianceSector(S,commInd,'vert')); % out sp time averaged in func comm
        ScBc_var = matCell2Mat(varianceSector(S,commInd,'block')); % in-out sp time averaged for each func comm
    else
        SnRc = cell2mat(S(:)); % average in sp time (table, lines == in sp times, subjects are stacked)
        SnSc = cell2mat(S(:)')'; % average out sp time (table, lines == out sp times, subjects are stacked)
        SlRc = cell2mat(groupSector(ScZ_sort,lobeInd,'horiz')); % in sp time averaged in lobes 
        SlSc = cell2mat(groupSector(ScZ_sort,lobeInd,'vert')); % out sp time averaged in lobes
        SlBc = cell2mat(groupSector(ScZ_sort,lobeInd,'block')); % in-out averaged sp time for each lobes
        SlLRRc = cell2mat(groupSector(ScZ_sort,lobeIndLR,'horiz')); % in sp time averaged in L and R lobes
        SlLRSc = cell2mat(groupSector(ScZ_sort,lobeIndLR,'vert')); % out sp time averaged in L and R lobes
        SlLRBc = cell2mat(groupSector(ScZ_sort,lobeIndLR,'block')); % in-out averaged sp time for each L and R lobes
        ScRc = cell2mat(groupSector(S,commInd,'horiz')); % in sp time averaged in func comm
        ScSc = cell2mat(groupSector(S,commInd,'vert')); % out sp time averaged in func comm
        ScBc = cell2mat(groupSector(S,commInd,'block')); % in-out sp time averaged for each func comm
    end

    [mm,ss] = meanStd(Sc,1,true);
    r.SZ{i} = reshape(mm,N,N);
    r.SZStd{i} = reshape(ss,N,N);

    r.SZ_node{i} = r.SZ{i};
    r.SZStd_node{i} = r.SZStd{i};

    if (N == 9) || (N >= 78) % Yeo Comm or std AAL
        r.SZS_mtlL{i} = r.SZ{i}(mtlIndL,:); % average (over subjects) MTL-L out sp times
        r.SZS_mtlR{i} = r.SZ{i}(mtlIndR,:); % same for MTL-R
        r.SZStdS_mtlL{i} = r.SZStd{i}(mtlIndL,:); % stddev (over subjects) MTL-L out sp times
        r.SZStdS_mtlR{i} = r.SZStd{i}(mtlIndR,:); % same for MTL-R
        
        r.SZR_mtlL{i} = r.SZ{i}(:,mtlIndL)'; % average (over subjects) MTL-L out sp times
        r.SZR_mtlR{i} = r.SZ{i}(:,mtlIndR)'; % same for MTL-R
        r.SZStdR_mtlL{i} = r.SZStd{i}(:,mtlIndL)'; % stddev (over subjects) MTL-L out sp times
        r.SZStdR_mtlR{i} = r.SZStd{i}(:,mtlIndR)'; % same for MTL-R
        
        ScZR_mtlL = matCell2Mat(myMean(selectLinesOrCols(S, mtlIndL, 'cols'),1,'omitnan')); % table with MTL-L sp times (out) for every subject (lines)
        ScZR_mtlR = matCell2Mat(myMean(selectLinesOrCols(S, mtlIndR, 'cols'),1,'omitnan')); % same as above for MTL-R
        ScZS_mtlL_avg = matCell2Mat(mean(reshapeLines(ScZS_mtlL,[numel(mtlIndL),N]),2,'omitnan'));
        ScZS_mtlR_avg = matCell2Mat(mean(reshapeLines(ScZS_mtlR,[numel(mtlIndR),N]),2,'omitnan'));
        r.SAllS_mtlL_theta{i} =  ScZS_mtlL_avg;
        r.SAllS_mtlR_theta{i} =  ScZS_mtlR_avg;
        r.SAllR_mtlL_theta{i} =  ScZR_mtlL;
        r.SAllR_mtlR_theta{i} =  ScZR_mtlR;
        r.SAll_mtlL_theta{i} =  mean(cat(3,ScZS_mtlL_avg,ScZR_mtlL),3,'omitnan');
        r.SAll_mtlR_theta{i} =  mean(cat(3,ScZS_mtlR_avg,ScZR_mtlR),3,'omitnan');

        r.SZRS_mtlL{i} = mean(cat(3,r.SZ{i}(mtlIndL,:),r.SZ{i}(:,mtlIndL)'),3,'omitnan'); % mean of in out sp times for MTL L
        r.SZRS_mtlR{i} = mean(cat(3,r.SZ{i}(mtlIndR,:),r.SZ{i}(:,mtlIndR)'),3,'omitnan'); % mean of in out sp times for MTL R
        r.SZStdRS_mtlL{i} = sqrt(mean(cat(3,r.SZStd{i}(mtlIndL,:).^2,(r.SZStd{i}(:,mtlIndL)').^2),3,'omitnan')); % std dev of the mean of in out sp times for MTL L (sqrt of the mean variance)
        r.SZStdRS_mtlR{i} = sqrt(mean(cat(3,r.SZStd{i}(mtlIndR,:).^2,(r.SZStd{i}(:,mtlIndR)').^2),3,'omitnan')); % std dev of the mean of in out sp times for MTL R (sqrt of the mean variance)

        r.SZ_mtlL_all{i} = mean(ScZ_mtlL_all,1,'omitnan'); % average (over subjects) MTL-L out sp time (simultaneously seed from all MTL-L)
        r.SZ_mtlR_all{i} = mean(ScZ_mtlR_all,1,'omitnan'); % same for MTL-R
        r.SZStd_mtlL_all{i} = std(ScZ_mtlL_all,[],1,'omitnan'); % stddev of the above measurement
        r.SZStd_mtlR_all{i} = std(ScZ_mtlR_all,[],1,'omitnan'); % same as above
        r.SZ_mtlL_lobe{i} = reshape(mean(ScZ_mtlL_lobe,1,'omitnan'),numel(mtlIndL),numel(lobeInd)); % avg (over subj) sp time from MTL-L to lobes
        r.SZ_mtlR_lobe{i} = reshape(mean(ScZ_mtlR_lobe,1,'omitnan'),numel(mtlIndR),numel(lobeInd)); % same for MTL-R
        r.SZ_mtlL_lobeLR{i} = reshape(mean(ScZ_mtlL_lobeLR,1,'omitnan'),numel(mtlIndL),numel(lobeIndLR)); % same as above to lobes L R
        r.SZ_mtlR_lobeLR{i} = reshape(mean(ScZ_mtlR_lobeLR,1,'omitnan'),numel(mtlIndR),numel(lobeIndLR)); % same as above for MTL-R
        r.SZ_mtlL_comm{i} = reshape(mean(ScZ_mtlL_comm,1,'omitnan'),numel(mtlIndL),numel(commInd)); % same as above to func comm
        r.SZ_mtlR_comm{i} = reshape(mean(ScZ_mtlR_comm,1,'omitnan'),numel(mtlIndR),numel(commInd)); % same as above for MTL-R
        if tTestAvgNotSample
            r.SZStd_mtlL_lobe{i} = reshape(sqrt(mean(ScZ_mtlL_lobe_var,1,'omitnan')),numel(mtlIndL),numel(lobeInd)); % avg (over subj) sp time from MTL-L to lobes
            r.SZStd_mtlR_lobe{i} = reshape(sqrt(mean(ScZ_mtlR_lobe_var,1,'omitnan')),numel(mtlIndR),numel(lobeInd)); % same for MTL-R
            r.SZStd_mtlL_lobeLR{i} = reshape(sqrt(mean(ScZ_mtlL_lobeLR_var,1,'omitnan')),numel(mtlIndL),numel(lobeIndLR)); % same as above to lobes L R
            r.SZStd_mtlR_lobeLR{i} = reshape(sqrt(mean(ScZ_mtlR_lobeLR_var,1,'omitnan')),numel(mtlIndR),numel(lobeIndLR)); % same as above for MTL-R
            r.SZStd_mtlL_comm{i} = reshape(sqrt(mean(ScZ_mtlL_comm_var,1,'omitnan')),numel(mtlIndL),numel(commInd)); % same as above to func comm
            r.SZStd_mtlR_comm{i} = reshape(sqrt(mean(ScZ_mtlR_comm_var,1,'omitnan')),numel(mtlIndR),numel(commInd)); % same as above for MTL-R
        else
            r.SZStd_mtlL_lobe{i} = reshape(std(ScZ_mtlL_lobe,[],1,'omitnan'),numel(mtlIndL),numel(lobeInd)); % avg (over subj) sp time from MTL-L to lobes
            r.SZStd_mtlR_lobe{i} = reshape(std(ScZ_mtlR_lobe,[],1,'omitnan'),numel(mtlIndR),numel(lobeInd)); % same for MTL-R
            r.SZStd_mtlL_lobeLR{i} = reshape(std(ScZ_mtlL_lobeLR,[],1,'omitnan'),numel(mtlIndL),numel(lobeIndLR)); % same as above to lobes L R
            r.SZStd_mtlR_lobeLR{i} = reshape(std(ScZ_mtlR_lobeLR,[],1,'omitnan'),numel(mtlIndR),numel(lobeIndLR)); % same as above for MTL-R
            r.SZStd_mtlL_comm{i} = reshape(std(ScZ_mtlL_comm,[],1,'omitnan'),numel(mtlIndL),numel(commInd)); % same as above to func comm
            r.SZStd_mtlR_comm{i} = reshape(std(ScZ_mtlR_comm,[],1,'omitnan'),numel(mtlIndR),numel(commInd)); % same as above for MTL-R
        end
        
%         r.SZS_mtlL_CT{i} = r.SZS_mtlL{i}; r.SZS_mtlR_CT{i} = r.SZS_mtlR{i}; r.SZR_mtlL_CT{i} = r.SZR_mtlL{i}; r.SZR_mtlR_CT{i} = r.SZR_mtlR{i};
%         r.SZRS_mtlL_CT{i} = r.SZRS_mtlL{i}; r.SZRS_mtlR_CT{i} = r.SZRS_mtlR{i}; r.SZ_mtlL_lobe_CT{i} = r.SZ_mtlL_lobe{i}; r.SZ_mtlR_lobe_CT{i} = r.SZ_mtlR_lobe{i};
%         r.SZ_mtlL_lobeLR_CT{i} = r.SZ_mtlL_lobeLR{i}; r.SZ_mtlR_lobeLR_CT{i} = r.SZ_mtlR_lobeLR{i}; r.SZ_mtlL_comm_CT{i} = r.SZ_mtlL_comm{i}; r.SZ_mtlR_comm_CT{i} = r.SZ_mtlR_comm{i};
% 
%         r.SZS_mtlL_HV{i} = r.SZS_mtlL{i}; r.SZS_mtlR_HV{i} = r.SZS_mtlR{i}; r.SZR_mtlL_HV{i} = r.SZR_mtlL{i}; r.SZR_mtlR_HV{i} = r.SZR_mtlR{i};
%         r.SZRS_mtlL_HV{i} = r.SZRS_mtlL{i}; r.SZRS_mtlR_HV{i} = r.SZRS_mtlR{i}; r.SZ_mtlL_lobe_HV{i} = r.SZ_mtlL_lobe{i}; r.SZ_mtlR_lobe_HV{i} = r.SZ_mtlR_lobe{i};
%         r.SZ_mtlL_lobeLR_HV{i} = r.SZ_mtlL_lobeLR{i}; r.SZ_mtlR_lobeLR_HV{i} = r.SZ_mtlR_lobeLR{i}; r.SZ_mtlL_comm_HV{i} = r.SZ_mtlL_comm{i}; r.SZ_mtlR_comm_HV{i} = r.SZ_mtlR_comm{i};
    end

    if isfield(s,'D_node')
        r.SPdiff_edge{i} = SPc_diff_edge;
        r.SPdiff_node{i} = reshape(mean(SPc_diff_edge,1,'omitnan'),N,1);
        r.Pdiff_edge{i} = PcDiff_edge;
        r.Pdiff_node{i} = PcDiff_node(:);
    end

    SAll = mean(Sc,2,'omitnan');
    r.SAll_theta{i} = reshape(SAll,numel(cInd),1); % average sp time for each subject in this group
    r.SAvg_theta(i) = mean(SAll,'omitnan'); % average sp time for this group
    r.SErr_theta(i) = std(SAll,'omitnan') ./ sqrt(numel(SAll)); % error of sp time for this group
    r.SStd_theta(i) = std(SAll,'omitnan'); % stddev sp time for this group

    r.SAvgR_node{i} = reshape(mean(SnRc,1,'omitnan'),N,1); % avg (per subject) in sp time per node
    r.SAvgS_node{i} = reshape(mean(SnSc,1,'omitnan'),N,1); % avg (per subject) out sp time per node
    if tTestAvgNotSample
        r.SStdR_node{i} = reshape(sqrt(mean(SnRc_var,1,'omitnan')),N,1); % stddev of above measure
        r.SStdS_node{i} = reshape(sqrt(mean(SnSc_var,1,'omitnan')),N,1); % stddev of above measure
    else
        r.SStdR_node{i} = reshape(sqrt(mean(SnRc_var,1,'omitnan')),N,1); % stddev of above measure
        r.SStdS_node{i} = reshape(sqrt(mean(SnSc_var,1,'omitnan')),N,1); % stddev of above measure
    end
    r.SErrR_node{i} = r.SStdR_node{i} ./ sqrt(numel(cInd)); % statistical err of above measure
    r.SErrS_node{i} = r.SStdS_node{i} ./ sqrt(numel(cInd)); % statistical err of above measure

    r.SAvgRS_node{i} = mean(cat(3,r.SAvgR_node{i}(:),r.SAvgS_node{i}(:)),3,'omitnan'); % mean of in out sp times per node
    r.SStdRS_node{i} = sqrt(mean(cat(3,r.SStdR_node{i}(:).^2,r.SStdS_node{i}(:).^2),3,'omitnan')); % std dev of the mean of in out sp times per node (sqrt of the mean variance)
    
%     r.SAvg_CT_theta(i) = r.SAvg_theta(i);
%     r.SAvg_CT_node{i} = r.SAvgRS_node{i};
%     r.SAvg_HV_theta(i) = r.SAvg_theta(i);
%     r.SAvg_HV_node{i} = r.SAvgRS_node{i};

    r.SZR_lobe{i} = reshape(mean(SlRc,1,'omitnan'),numel(lobeInd),1);
    r.SZR_lobeLR{i} = reshape(mean(SlLRRc,1,'omitnan'),numel(lobeIndLR),1);
    r.SZR_comm{i} = reshape(mean(ScRc,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.SZStdR_lobe{i} = reshape(sqrt(mean(SlRc_var,1,'omitnan')),numel(lobeInd),1);
        r.SZStdR_lobeLR{i} = reshape(sqrt(mean(SlLRRc_var,1,'omitnan')),numel(lobeIndLR),1);
        r.SZStdR_comm{i} = reshape(sqrt(mean(ScRc_var,1,'omitnan')),numel(commInd),1);
    else
        r.SZStdR_lobe{i} = reshape(std(SlRc,[],1,'omitnan'),numel(lobeInd),1);
        r.SZStdR_lobeLR{i} = reshape(std(SlLRRc,[],1,'omitnan'),numel(lobeIndLR),1);
        r.SZStdR_comm{i} = reshape(std(ScRc,[],1,'omitnan'),numel(commInd),1);
    end

    r.SZS_lobe{i} = reshape(mean(SlSc,1,'omitnan'),numel(lobeInd),1);
    r.SZS_lobeLR{i} = reshape(mean(SlLRSc,1,'omitnan'),numel(lobeIndLR),1);
    r.SZS_comm{i} = reshape(mean(ScSc,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.SZStdS_lobe{i} = reshape(sqrt(mean(SlSc_var,1,'omitnan')),numel(lobeInd),1);
        r.SZStdS_lobeLR{i} = reshape(sqrt(mean(SlLRSc_var,1,'omitnan')),numel(lobeIndLR),1);
        r.SZStdS_comm{i} = reshape(sqrt(mean(ScSc_var,1,'omitnan')),numel(commInd),1);
    else
        r.SZStdS_lobe{i} = reshape(std(SlSc,[],1,'omitnan'),numel(lobeInd),1);
        r.SZStdS_lobeLR{i} = reshape(std(SlLRSc,[],1,'omitnan'),numel(lobeIndLR),1);
        r.SZStdS_comm{i} = reshape(std(ScSc,[],1,'omitnan'),numel(commInd),1);
    end

    r.SZB_lobe{i} = reshape(mean(SlBc,1,'omitnan'),numel(lobeInd),1);
    r.SZB_lobeLR{i} = reshape(mean(SlLRBc,1,'omitnan'),numel(lobeIndLR),1);
    r.SZB_comm{i} = reshape(mean(ScBc,1,'omitnan'),numel(commInd),1);
    if tTestAvgNotSample
        r.SZStdB_lobe{i} = reshape(sqrt(mean(SlBc_var,1,'omitnan')),numel(lobeInd),1);
        r.SZStdB_lobeLR{i} = reshape(sqrt(mean(SlLRBc_var,1,'omitnan')),numel(lobeIndLR),1);
        r.SZStdB_comm{i} = reshape(sqrt(mean(ScBc_var,1,'omitnan')),numel(commInd),1);
    else
        r.SZStdB_lobe{i} = reshape(std(SlBc,[],1,'omitnan'),numel(lobeInd),1);
        r.SZStdB_lobeLR{i} = reshape(std(SlLRBc,[],1,'omitnan'),numel(lobeIndLR),1);
        r.SZStdB_comm{i} = reshape(std(ScBc,[],1,'omitnan'),numel(commInd),1);
    end

    if isfield(s,'D_node')
        if isNotEmptyField(s,'D_node')
            Dc = matCell2Mat(s.D_node(cInd)); % hamming distance table (lines are subjects), columns are Hamming distance between individual nodes
        else
            if hammDistPrecision > 0
                [Seq,Peq] = equalizeMatricesToPrecision(S,shortPath(cInd),hammDistPrecision); % if any values in the corresponding matrices SAvg and shortPath differ by less than precision, they are set to equal
                % this step is necessary when we compare the z-scored to controls shortest path and the z-scored to controls sp times
            else
                Seq = S;
                Peq = shortPath(cInd);
            end
            Dc = hammingDistance(Seq, Peq, N); % hamming distance table (lines are subjects), columns are Hamming distance between individual nodes
        end
        DcM = sum(Dc,2); % hamming distance between matrices for each subject
        Dc_sort = Dc(:,sortInd);
        Dlc = sumSector(Dc_sort,lobeInd,'line'); % hamming distance inside the lobes
        DlLRc = sumSector(Dc_sort,lobeIndLR,'line'); % hamming distance inside the L and R lobes
        Dcc = sumSector(Dc,commInd,'line'); % hamming distance inside func comm

        r.D_theta(i) = mean(DcM,'omitnan'); % average (over subj) hamm distance for each theta
        r.DAll_theta{i} = DcM; % hamm dist for each subj in this group
        r.DErr_theta(i) = std(DcM,'omitnan') / sqrt(numel(DcM)); % stat err
        r.DStd_theta(i) = std(DcM,'omitnan'); % stddev of hamm dist

        r.D_node{i} = reshape(mean(Dc,1,'omitnan'),N,1); % avg over subj hamm dist per node
        r.DErr_node{i} = reshape(std(Dc,0,1,'omitnan'),N,1) ./ sqrt(numel(cInd));
        r.DStd_node{i} = reshape(std(Dc,0,1,'omitnan'),N,1);

        r.D_lobe{i} = reshape(mean(Dlc,1,'omitnan'),numel(lobeInd),1); % avg over subj hamm dist in lobe
        r.D_lobeLR{i} = reshape(mean(DlLRc,1,'omitnan'),numel(lobeIndLR),1); % in lobe LR
        r.D_comm{i} = reshape(mean(Dcc,1,'omitnan'),numel(commInd),1); % in func comm
    else
        Dc = [];
        DcM = []; % hamming distance between matrices for each subject
        Dlc = []; % hamming distance inside the lobes
        DlLRc = []; % hamming distance inside the L and R lobes
        Dcc = []; % hamming distance inside func comm
    end

    % histogram of the nodes that get disconnected for each theta (id by index i)
    nn = findNaNInSetOfMat(S,2); % find all rows that have a NaN in each matrix of the cInd set
    nn = [nn{:}];
    nodesIndHist = 1:(N+1);
    [r.I{i},~] = histcounts(nn(:), nodesIndHist, 'Normalization', 'probability');
    r.I{i} = reshape(r.I{i},N,1);
end

function r = CalcSpMatrixTTest(r,i,alphaTTest,alphaFDR,splitTTest,N,mtlIndL,mtlIndR,lobeInd,lobeIndLR,commInd,...
                               Dc,Dp,DcM,DpM,Dcc,Dcp,DlLRc,DlLRp,Dlc,Dlp,SPc_diff,SPp_diff,SPc_diff_edge,SPp_diff_edge,...
                               Sc,Sp,ScBc,ScBp,ScRc,ScRp,ScSc,ScSp,ScZS_mtlL,SpZS_mtlL,...
                               ScZ_mtlL_all,SpZ_mtlL_all,ScZ_mtlL_comm,SpZ_mtlL_comm,ScZ_mtlL_lobe,SpZ_mtlL_lobe,ScZ_mtlL_lobeLR,...
                               SpZ_mtlL_lobeLR,ScZS_mtlR,SpZS_mtlR,ScZ_mtlR_all,SpZ_mtlR_all,ScZ_mtlR_comm,SpZ_mtlR_comm,...
                               ScZ_mtlR_lobe,SpZ_mtlR_lobe,ScZ_mtlR_lobeLR,SpZ_mtlR_lobeLR,SlBc,SlBp,SlLRBc,SlLRBp,SlLRRc,...
                               SlLRRp,SlLRSc,SlLRSp,SlRc,SlRp,SlSc,SlSp,SnRc,SnRp,SnSc,SnSp,ct,hv,ScHV,SpHV,hvAbsent,cInd,pInd,tTestProp)

    Sc_stack = reshapeLines(Sc,[N,N]); % reshapes each line i of Sc(i,:) data table to become a matrix in Sc_stack(:,:,i) shaped [N,N]
    Sp_stack = reshapeLines(Sp,[N,N]); % reshapes each line i of Sc(i,:) data table to become a matrix in Sc_stack(:,:,i) shaped [N,N]

    r.SZ(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc,Sp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
    r.SZ_node(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_stack,Sp_stack,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,'TTestLines',true),[N,N]);

    if (N == 9) || (N >= 78) % Yeo Comm or std AAL
        ScZR_mtlL = matCell2Mat(  permute(Sc_stack(:,mtlIndL,:),[2,1,3]) );
        SpZR_mtlL = matCell2Mat(  permute(Sp_stack(:,mtlIndL,:),[2,1,3]) );
        ScZR_mtlR = matCell2Mat(  permute(Sc_stack(:,mtlIndR,:),[2,1,3]) );
        SpZR_mtlR = matCell2Mat(  permute(Sp_stack(:,mtlIndR,:),[2,1,3]) );
        Sc_mtlL_RS = cat(3,matCell2Mat(Sc_stack(mtlIndL,:,:)), ScZR_mtlL);
        Sp_mtlL_RS = cat(3,matCell2Mat(Sp_stack(mtlIndL,:,:)), SpZR_mtlL);
        Sc_mtlR_RS = cat(3,matCell2Mat(Sc_stack(mtlIndR,:,:)), ScZR_mtlR);
        Sp_mtlR_RS = cat(3,matCell2Mat(Sp_stack(mtlIndR,:,:)), SpZR_mtlR);

        r.SZS_mtlL(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlL,SpZS_mtlL,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndL),N]);
        r.SZS_mtlR(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlR,SpZS_mtlR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndR),N]);

        r.SZR_mtlL(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlL,SpZR_mtlL,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndL),N]);
        r.SZR_mtlR(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlR,SpZR_mtlR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndR),N]);

        r.SZRS_mtlL(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlL_RS,Sp_mtlL_RS,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'SplitNegPos',splitTTest,'MultiVar',true),[numel(mtlIndR),N]);
        r.SZRS_mtlR(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlR_RS,Sp_mtlR_RS,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'SplitNegPos',splitTTest,'MultiVar',true),[numel(mtlIndR),N]);

        r.SZ_mtlL_all(i) = ttest.ttest2Struct(ScZ_mtlL_all,SpZ_mtlL_all,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:});
        r.SZ_mtlR_all(i) = ttest.ttest2Struct(ScZ_mtlR_all,SpZ_mtlR_all,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:});

        r.SZ_mtlL_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobe,SpZ_mtlL_lobe,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndL),numel(lobeInd)]);
        r.SZ_mtlR_lobe(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobe,SpZ_mtlR_lobe,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndR),numel(lobeInd)]);
        r.SZ_mtlL_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobeLR,SpZ_mtlL_lobeLR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndL),numel(lobeIndLR)]);
        r.SZ_mtlR_lobeLR(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobeLR,SpZ_mtlR_lobeLR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndR),numel(lobeIndLR)]);
        r.SZ_mtlL_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_comm,SpZ_mtlL_comm,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndL),numel(commInd)]);
        r.SZ_mtlR_comm(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_comm,SpZ_mtlR_comm,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,tTestProp{:}),[numel(mtlIndR),numel(commInd)]);
    end

    if ~isempty(SPc_diff)
        r.SPdiff_edge(i) = ttest.reshapeTTest(ttest.ttest2Struct(SPc_diff,SPp_diff,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest),[N,N]);
        r.SPdiff_node(i) = ttest.ttest2Struct(SPc_diff_edge,SPp_diff_edge,'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
    end

    if (N == 9) || (N == 90) || (N == 306)
        % estimating cortical thickness influence
        if i == 1
            r.CTAll = ttest.ttest2Struct(ct.cData.CT,ct.pData.CT,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
            r.CT_node = ttest.ttest2Struct(matCell2Mat(ct.cData.CT_node),matCell2Mat(ct.pData.CT_node),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});

            r.HVAll = ttest.ttest2Struct(hv.cData.HV,hv.pData.HV,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
        end
        r.SAvg_CT_theta(i) = ttest.ttest2Struct(mean(Sc,2,'omitnan'),mean(Sp,2,'omitnan'),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        %r.SAvg_CT_node(i) = ttest.ttest2Struct(cat(3,SnRc,SnSc),cat(3,SnRp,SnSp),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',CT_node_c,'C1_y',CT_node_p);
        r.SAvgRS_CT_node(i) = ttest.ttest2Struct(cat(3,SnRc,SnSc),cat(3,SnRp,SnSp),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SAvgR_CT_node(i) = ttest.ttest2Struct(SnRc,SnRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SAvgS_CT_node(i) = ttest.ttest2Struct(SnSc,SnSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZ_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc,Sp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[N,N]);

        % estimating hippocampus volume influence
        r.SAvg_HV_theta(i) = ttest.ttest2Struct(mean(ScHV,2,'omitnan'),mean(SpHV,2,'omitnan'),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        ScHV_in = matCell2Mat(myMean(reshapeLines(ScHV,[N,N]),1,'omitnan'));
        ScHV_out = matCell2Mat(myMean(reshapeLines(ScHV,[N,N]),2,'omitnan'));
        SpHV_in = matCell2Mat(myMean(reshapeLines(SpHV,[N,N]),1,'omitnan'));
        SpHV_out = matCell2Mat(myMean(reshapeLines(SpHV,[N,N]),2,'omitnan'));
        r.SAvgRS_HV_node(i) = ttest.ttest2Struct(cat(3,ScHV_in,ScHV_out),cat(3,SpHV_in,SpHV_out),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SAvgR_HV_node(i) = ttest.ttest2Struct(ScHV_in,SpHV_in,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SAvgS_HV_node(i) = ttest.ttest2Struct(ScHV_out,SpHV_out,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZ_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc,Sp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'SplitNegPos',splitTTest,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[N,N]);
        
        r.SZS_mtlL_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlL,SpZS_mtlL,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndL),N]);
        r.SZS_mtlR_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlR,SpZS_mtlR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),N]);
        r.SZR_mtlL_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlL,SpZR_mtlL,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndL),N]);
        r.SZR_mtlR_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlR,SpZR_mtlR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),N]);
        r.SZRS_mtlL_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlL_RS,Sp_mtlL_RS,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),N]);
        r.SZRS_mtlR_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlR_RS,Sp_mtlR_RS,'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),N]);
        r.SZ_mtlL_lobe_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobe,SpZ_mtlL_lobe,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndL),numel(lobeInd)]);
        r.SZ_mtlR_lobe_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobe,SpZ_mtlR_lobe,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),numel(lobeInd)]);
        r.SZ_mtlL_lobeLR_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobeLR,SpZ_mtlL_lobeLR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndL),numel(lobeIndLR)]);
        r.SZ_mtlR_lobeLR_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobeLR,SpZ_mtlR_lobeLR,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),numel(lobeIndLR)]);
        r.SZ_mtlL_comm_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_comm,SpZ_mtlL_comm,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndL),numel(commInd)]);
        r.SZ_mtlR_comm_CT(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_comm,SpZ_mtlR_comm,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT),[numel(mtlIndR),numel(commInd)]);
        
        r.SZR_lobe_CT(i) = ttest.ttest2Struct(SlRc,SlRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZR_lobeLR_CT(i) = ttest.ttest2Struct(SlLRRc,SlLRRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZR_comm_CT(i) = ttest.ttest2Struct(ScRc,ScRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZS_lobe_CT(i) = ttest.ttest2Struct(SlSc,SlSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZS_lobeLR_CT(i) = ttest.ttest2Struct(SlLRSc,SlLRSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZS_comm_CT(i) = ttest.ttest2Struct(ScSc,ScSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZB_lobe_CT(i) = ttest.ttest2Struct(SlBc,SlBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZB_lobeLR_CT(i) = ttest.ttest2Struct(SlLRBc,SlLRBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);
        r.SZB_comm_CT(i) = ttest.ttest2Struct(ScBc,ScBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',ct.cData.CT,'C1_y',ct.pData.CT);

        [~,cIndHV] = setdiff(cInd,hvAbsent);
        [~,pIndHV] = setdiff(pInd,hvAbsent);
        r.SZS_mtlL_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlL(cIndHV,:),SpZS_mtlL(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndL),N]);
        r.SZS_mtlR_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZS_mtlR(cIndHV,:),SpZS_mtlR(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),N]);
        r.SZR_mtlL_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlL(cIndHV,:),SpZR_mtlL(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndL),N]);
        r.SZR_mtlR_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZR_mtlR(cIndHV,:),SpZR_mtlR(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),N]);
        r.SZRS_mtlL_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlL_RS(cIndHV,:,:),Sp_mtlL_RS(pIndHV,:,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),N]);
        r.SZRS_mtlR_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(Sc_mtlR_RS(cIndHV,:,:),Sp_mtlR_RS(pIndHV,:,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),N]);
        r.SZ_mtlL_lobe_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobe(cIndHV,:),SpZ_mtlL_lobe(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndL),numel(lobeInd)]);
        r.SZ_mtlR_lobe_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobe(cIndHV,:),SpZ_mtlR_lobe(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),numel(lobeInd)]);
        r.SZ_mtlL_lobeLR_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_lobeLR(cIndHV,:),SpZ_mtlL_lobeLR(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndL),numel(lobeIndLR)]);
        r.SZ_mtlR_lobeLR_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_lobeLR(cIndHV,:),SpZ_mtlR_lobeLR(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),numel(lobeIndLR)]);
        r.SZ_mtlL_comm_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlL_comm(cIndHV,:),SpZ_mtlL_comm(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndL),numel(commInd)]);
        r.SZ_mtlR_comm_HV(i) = ttest.reshapeTTest(ttest.ttest2Struct(ScZ_mtlR_comm(cIndHV,:),SpZ_mtlR_comm(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV),[numel(mtlIndR),numel(commInd)]);

        r.SZR_lobe_HV(i) = ttest.ttest2Struct(SlRc(cIndHV,:),SlRp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZR_lobeLR_HV(i) = ttest.ttest2Struct(SlLRRc(cIndHV,:),SlLRRp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZR_comm_HV(i) = ttest.ttest2Struct(ScRc(cIndHV,:),ScRp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZS_lobe_HV(i) = ttest.ttest2Struct(SlSc(cIndHV,:),SlSp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZS_lobeLR_HV(i) = ttest.ttest2Struct(SlLRSc(cIndHV,:),SlLRSp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZS_comm_HV(i) = ttest.ttest2Struct(ScSc(cIndHV,:),ScSp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZB_lobe_HV(i) = ttest.ttest2Struct(SlBc(cIndHV,:),SlBp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZB_lobeLR_HV(i) = ttest.ttest2Struct(SlLRBc(cIndHV,:),SlLRBp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
        r.SZB_comm_HV(i) = ttest.ttest2Struct(ScBc(cIndHV,:),ScBp(pIndHV,:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,'Model','1+G+C1','TestDomain','G.X-G.Y','C1_x',hv.cData.HV,'C1_y',hv.pData.HV);
    end

    r.SAvg_theta(i) = ttest.ttest2Struct(mean(Sc,2,'omitnan'),mean(Sp,2,'omitnan'),'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});

    r.SAvgR_node(i) = ttest.ttest2Struct(SnRc,SnRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SAvgS_node(i) = ttest.ttest2Struct(SnSc,SnSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SAvgRS_node(i) = ttest.ttest2Struct(cat(3,SnRc,SnSc),cat(3,SnRp,SnSp),'Alpha',alphaTTest,'AlphaFDR',alphaFDR/2,'MultiVar',true);

    r.SZR_lobe(i) = ttest.ttest2Struct(SlRc,SlRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZR_lobeLR(i) = ttest.ttest2Struct(SlLRRc,SlLRRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZR_comm(i) = ttest.ttest2Struct(ScRc,ScRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZS_lobe(i) = ttest.ttest2Struct(SlSc,SlSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZS_lobeLR(i) = ttest.ttest2Struct(SlLRSc,SlLRSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZS_comm(i) = ttest.ttest2Struct(ScSc,ScSp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZB_lobe(i) = ttest.ttest2Struct(SlBc,SlBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZB_lobeLR(i) = ttest.ttest2Struct(SlLRBc,SlLRBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    r.SZB_comm(i) = ttest.ttest2Struct(ScBc,ScBp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});

    if ~isempty(Dc)
        r.D_node(i) = ttest.ttest2Struct(Dc,Dp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
        r.D_theta(i) = ttest.ttest2Struct(DcM,DpM,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
        r.D_lobe(i) = ttest.ttest2Struct(Dlc,Dlp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
        r.D_lobeLR(i) = ttest.ttest2Struct(DlLRc,DlLRp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
        r.D_comm(i) = ttest.ttest2Struct(Dcc,Dcp,'Alpha',alphaTTest,'AlphaFDR',alphaFDR,tTestProp{:});
    end
end

function ct = getCortThickComm(ct, cm, ggamma, N)
    if isempty(ct)
        return;
    end
    fn = fieldnames(ct);
    for i = 1:numel(fn)
        l = fn{i};
        if strcmpi(l,'caseName')
            continue;
        end
        if isstruct(ct.(l)) % flip, raw, zToControls case
            ct.(l) = getCortThickComm(ct.(l), cm, ggamma, N); % then check each of these fields
        else
            if iscell(ct.(l))
                if (isnumeric(ct.(l){1}) && isvector(ct.(l){1})) && (numel(ct.(l){1}) == N)
                    ct.(l) = calcCommunityDataForNodes(ct.(l), cm, ggamma);
                end
            else
                if (isnumeric(ct.(l)) && isvector(ct.(l))) && (numel(ct.(l)) == N)
                    a = calcCommunityDataForNodes(ct.(l), cm, ggamma);
                    ct.(l) = a{1};
                end
            end
        end
    end
end

function q = ShortPathToShortPathMod(p, cm, ggamma)
    q = p;
    q.P = calcCommunityAvgShortestPath(p.P, cm, ggamma);
end

function r = getCommunityData(s, cm, ggamma)
    N = s(1).N;
    r = getCommunityData_internal(s, cm, ggamma, 'data', N);
    r = getCommunityData_internal(r, cm, ggamma, 'flipData', N);
    r = getCommunityData_internal(r, cm, ggamma, 'zControlData', N);
end

function r = getCommunityData_internal(s, cm, ggamma, dataField, N)
    r = s;
    for i = 1:numel(s)
        if isempty(s(i).(dataField))
            continue;
        end
        fn = fieldnames(s(i).(dataField));
        for j = 1:numel(fn)
            l = fn{j};
            if iscell(s(i).(dataField).(l)) && ~strContainsPattern(l,'_Z')%if iscell(s(i).(datafield).(l)) && ~contains(l,'_Z')
                if numel(size(s(i).(dataField).(l){1})) == 2 % vector or matrix
                    if all(size(s(i).(dataField).(l){1}) == [N,N])
                        [r(i).(dataField).(l),nComm] = calcCommunityAvgSpreadingTime(s(i).(dataField).(l), cm, ggamma);
                    end
                    if all(size(s(i).(dataField).(l){1}) == [N,1]) || all(size(s(i).(dataField).(l){1}) == [1,N])
                        [r(i).(dataField).(l),nComm] = calcCommunityDataForNodes(s(i).(dataField).(l), cm, ggamma);
                    end
                else
                    % 2-seed to 1-node activation times
                    [r(i).(dataField).(l),nComm] = calcCommunityAvgTwoSeedToNode(s(i).(dataField).(l), cm, ggamma);
                end
            end
        end
        r(i).N = nComm;
    end
    for i = 1:numel(s)
        if isempty(s(i).(dataField))
            continue;
        end
        fn = fieldnames(s(i).(dataField));
        for j = 1:numel(fn)
            l = fn{j};
            if strContainsPattern(l,'_Z')%if contains(l,'_Z')
                %nl = l(1:(end-2));
                nl = strrep(l,'_Z','');
                if isfield(r(i).(dataField), nl)
                    r(i).(dataField).(l) = ZScoreMatrix(r(i).(dataField).(nl));
                end
                if strContainsPattern(l,'Z_local')%if contains(l,'Z_local')
                    nl = strrep(l,'_Z_local','');
                    r(i).(dataField).(l) = ZScoreMatrix(r(i).(dataField).(nl),2);
                end
            end
        end
    end
end

function r = strContainsPattern(str,ptrn)
    if iscell(str)
        r = ~cellfun(@isempty,strfind(str,ptrn));
    else
        r = ~isempty(strfind(str,ptrn));
    end
end

function [value,paramList] = getParamValue(parName,paramList,delParam)
    if (nargin < 3) || isempty(delParam)
        delParam = false;
    end
    k = find(strcmpi(paramList,parName));
    if isempty(k)
        value = [];
        return;
    end
    if k == numel(paramList)
        error(['missing parameter value for ', parName]);
    end
    value = paramList{k+1};
    if delParam
        paramList(k:(k+1)) = [];
    end
end

function n = findNaNInSetOfMat(A,dim)
    if nargin < 2 || isempty(dim)
        dim = 1;
    end
    if iscell(A)
        n = cell(size(A));
        for i = 1:numel(A)
            n{i} = find(any(isnan(A{i}),dim)); %find(isnan(sp(j).SAvg{i}))';
            n{i} = reshape(n{i},1,numel(n{i}));
        end
    else
        n = find(any(isnan(A),dim));
        n = reshape(n,1,numel(n));
    end
end

function D = hammingDistance(S,P,N)
    D = zeros(numel(S),N);
    for i = 1:numel(S)
        D(i,:) = CalcHammingDist(S{i}, P{i}); % calculating hamming distance between spreading and shortest path matrices
    end
end

function r = processPhaseTrans(s, cInd, pInd, alphaTTest, alphaFDR, flipData)
    if flipData
        %disp('The density of active sites does not depend on the flipping because of its symmetry');
    end
    for i = 1:numel(s)
        r(i) = processPhaseTrans_single(s(i), cInd, pInd, alphaTTest, alphaFDR);
    end
end

function r = processPhaseTrans_single(s, cInd, pInd, alphaTTest, alphaFDR)
    r = s;
    r = rmfield(r, 'data');
    nC = numel(cInd);
    nP = numel(pInd);
    
    r.Theta = s.data.Theta{1};
    nTheta = numel(r.Theta);
    
%     thetaC = reshape([ s.data.Theta{cInd} ],nTheta,nC);
    controlRho = reshape([ s.data.rho{cInd} ],nTheta,nC);
%     [cRhoU,cRhoUInd,~]=uniqueInRows(controlRho);
    r.controlData = s.data;
    r.controlData = rmfield(r.controlData, 'Theta');
    r.controlData.ThetaTh = calcActivationThreshold([], r.Theta, s.data.rho(cInd));
    r.controlData.rho = mean(controlRho,2);
%     r.controlData.rhoAll = cRhoU;
%     r.controlData.thetaRhoAll = thetaC(cRhoUInd);
    r.controlData.rhoErr = std(reshape([s.data.rho{cInd}],nTheta,nC),0,2)./sqrt(nC);
    r.controlData.rhoStd = std(reshape([s.data.rho{cInd}],nTheta,nC),0,2);
    r.controlData.NVarRho = mean(reshape([s.data.NVarRho{cInd}],nTheta,nC),2);
    r.controlData.NVarRhoErr = std(reshape([s.data.NVarRho{cInd}],nTheta,nC),0,2)./sqrt(nC);
    r.controlData.NVarRhoStd = std(reshape([s.data.NVarRho{cInd}],nTheta,nC),0,2);
    r.controlData.nAct = mean(reshape([s.data.nAct{cInd}],nTheta,nC),2);
    r.controlData.nActErr = std(reshape([s.data.nAct{cInd}],nTheta,nC),0,2)./sqrt(nC);
    r.controlData.nActStd = std(reshape([s.data.nAct{cInd}],nTheta,nC),0,2);

    if numel(pInd) > 0
%         thetaP = reshape([ s.data.Theta{pInd} ],nTheta,nP);
        patientRho = reshape([ s.data.rho{pInd} ],nTheta,nP);
%         [pRhoU,pRhoUInd,~]=uniqueInRows(patientRho);
        r.patientData = s.data;
        r.patientData = rmfield(r.patientData, 'Theta');
        r.patientData.ThetaTh = calcActivationThreshold([], r.Theta, s.data.rho(pInd));
        r.patientData.rho = mean(patientRho,2);
%         r.patientData.rhoAll = pRhoU;
%         r.patientData.thetaRhoAll = thetaP(pRhoUInd);
        r.patientData.rhoErr = std(reshape([s.data.rho{pInd}],nTheta,nP),0,2)./sqrt(nP);
        r.patientData.rhoStd = std(reshape([s.data.rho{pInd}],nTheta,nP),0,2);
        r.patientData.NVarRho = mean(reshape([s.data.NVarRho{pInd}],nTheta,nP),2);
        r.patientData.NVarRhoErr = std(reshape([s.data.NVarRho{pInd}],nTheta,nP),0,2)./sqrt(nP);
        r.patientData.NVarRhoStd = std(reshape([s.data.NVarRho{pInd}],nTheta,nP),0,2);
        r.patientData.nAct = mean(reshape([s.data.nAct{pInd}],nTheta,nP),2);
        r.patientData.nActErr = std(reshape([s.data.nAct{pInd}],nTheta,nP),0,2)./sqrt(nP);
        r.patientData.nActStd = std(reshape([s.data.nAct{pInd}],nTheta,nP),0,2);
        
        r.ttest.ThetaTh = ttest.ttest2Struct(r.controlData.ThetaTh(:),r.patientData.ThetaTh(:),'Alpha',alphaTTest,'AlphaFDR',alphaFDR);
        %r.ttest.ThetaTh = ttest.ttest2Struct(r.controlData.ThetaTh,r.patientData.ThetaTh,'Alpha',alphaTTest,'Vartype','unequal');
    end
end

function r = sortFieldsContents(s, caseNameOrder)
    if isfield(s, 'caseName')
        c = s.caseName;
        f = fieldnames(s);
        [~,~,ic] = intersect(caseNameOrder, c, 'stable');
        for i = 1:numel(f)
            l = f{i};
            if isvector(s.(l))
                if numel(s.(l)) == numel(caseNameOrder)
                    r.(l) = s.(l)(ic);
                else
                    r.(l) = s.(l);
                end
            else
                k = find(size(s.(l))==numel(caseNameOrder));
                if isempty(k)
                    r.(l) = s.(l);
                else
                    if any(k==1)
                        r.(l) = s.(l)(ic,:);
                    end
                    if any(k==2)
                        r.(l) = s.(l)(:,ic);
                    end
                end
            end
        end
    else
        error('processSpreadingData:sortFieldsContents','caseName is not a field of data struct');
    end
end

function r = equalVectors(a,b)
    if numel(a) == numel(b)
        r = all(a(:) == b(:));
    else
        r = false;
    end
end

function r = hasDirectory(f)
    [a,~,~] = fileparts(f);
    r = ~isempty(a);
end

function cm = getCommStruct(aalComm, ggamma, N)
    l = getAALLabel(N);
    if isfield(aalComm,l)
        cm.ggamma = ggamma;
        cm.C{1} = aalComm.(l);
    else
        cm = [];
    end
end

function l = getAALLabel(N)
    l = ['AAL',num2str(N,'%02d')];
    if N == 78
        l = [l,'remap'];
    elseif N == 9
        l = [l,'comm'];
    end
end

function g = getCommGroups(cm,ggamma)
    k = find(cm.ggamma == ggamma, 1);
    if isempty(k)
        error('ggamma not found in cm');
    end
    g = getIndexGroups(cm.C{k});
end

function [indL,indR,labL,labR] = getMTLNodeIndex(N)
    global aal;
    al = getAALLabel(N);
    if N == 9 % Yeo communities
        indL = find(cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Subcortical')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Limbic')) );
        indR = find(cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Subcortical')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Limbic')) );
    else
        indL = find(cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Amygdala_L')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Hippocampus_L')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'ParaHippocampal_L')));
        indR = find(cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Amygdala_R')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'Hippocampus_R')) | ...
                    cellfun(@(x)~isempty(x),strfind(aal.labels.(al),'ParaHippocampal_R')));
    end
    labL = aal.labels.(al)(indL);
    labR = aal.labels.(al)(indR);
end

function [A,B] = equalizeMatricesToPrecision(A,B,precision)
    if iscell(A) || iscell(B)
        if ~(iscell(A) && iscell(B))
            error('A and B must be cell array of matrices')
        end
        if numel(A) ~= numel(B)
            error('A and B must be cell arrays with the same size')
        end
        for i = 1:numel(A)
            [A{i},B{i}] = equalizeMatricesToPrecision_internal(A{i},B{i},precision);
        end
    else
        [A,B] = equalizeMatricesToPrecision_internal(A,B,precision);
    end
end

function [A,B] = equalizeMatricesToPrecision_internal(A,B,precision)
    if precision == 0
        return;
    end
    k = find(abs(A-B) <= precision);
    B(k) = (A(k) + B(k)) ./ 2;
    A(k) = B(k);
end

function s = correctNumericPrecision_cell(s,precision)
% s -> struct containing fields of data
%      each field of s may be a numeric vector or a cell array of numeric vectors/matrices
%  this function forces anything less than 1e-8 (or precision) to zero for
%  any value stored in any field of s
    fn = fieldnames(s);
    for k = 1:numel(fn)
        l = fn{k};
        if iscell(s.(l))
            for i = 1:numel(s.(l))
                s.(l){i} = correctNumericPrecision(s.(l){i},precision);
            end
        else
            s.(l) = correctNumericPrecision(s.(l),precision);
        end
    end
end

function P = zScoreAndFlipShortestPath(P,cInd,S)
% z-score each subject in relation to subset given by indices cInd, P{cInd}
% flips those cases in which P differs from the spreading matrix S at theta=0
% S is already the z-scored to controls (cInd) flipped spreating time matrix for each case
    P = zScoreToSubset(P,cInd);
    H = hammingDistance(S,P,size(P{1},1)); % calculates matrix difference for each case between S{i} and P{i}
    flipInd = find(sum(H,2)~=0); % finds the cases that S and P differ from each other
    P = flipAALMatrix_rowsPerCols(P,[],flipInd); % flips the found cases
end

function n = getGroupName(gs)
    if ischar(gs)
        if strcmpi(gs,'nc')
            n = 'Controls';
            return;
        end
        n = gs;
        return;
    end
    n = [getGroupSideChar(gs),'TLE'];
end

function c = getGroupSideChar(sd)
    c = sort(strjoin(strrep(sd,'TLE',''),''));
end

function r = isNotEmptyField(s,fi)
    r = false;
    if isfield(s,fi)
        r = ~isempty(s.(fi));
    end
end

function ct = getCortThickStruct(ctFileName, cnOrder, N, controlGroup, cdb)
    if nargin == 0
        ct = [];
%         ct.isempty = true;
%         ct.raw = orderfields(struct('CT', [], 'CT_L', [], 'CT_R', [], 'CT_node', [], 'caseName', []));
%         ct.zToControls = orderfields(struct('CT', [], 'CT_L', [], 'CT_R', [], 'CT_node', [], 'caseName', []));
%         ct.flip = orderfields(struct('CT', [], 'CT_L', [], 'CT_R', [], 'CT_node', [], 'caseName', []));
        return;
    end
    if isempty(ctFileName)
        ct = [];
        return;
    end
    if ischar(ctFileName)
        try
            ct = load(ctFileName);
        catch
            ct = [];
            return;
        end
    else
        ct = ctFileName;
    end
    if N == 90
        ct = ct.N90;
    else
        ct = ct.N306;
    end
    
    if ~strcmp(controlGroup,'NC')
        [~,cInd] = getPatientControlInd(ct.raw.caseName,cdb,controlGroup);
        ct.zToControls.caseName = ct.raw.caseName;
        ct.zToControls.CT = zScoreToSubset(ct.raw.CT,cInd);
        ct.zToControls.CT_L = zScoreToSubset(ct.raw.CT_L,cInd);
        ct.zToControls.CT_R = zScoreToSubset(ct.raw.CT_R,cInd);
        ct.zToControls.CT_node = reshapeLines(zScoreToSubset(matCell2Mat(ct.raw.CT_node),cInd),[N,1],'cell');
    end
    
    [~,k] = setdiff(ct.raw.caseName,cnOrder);
    ct.raw.CT(k) = []; ct.raw.CT_L(k) = []; ct.raw.CT_R(k) = []; ct.raw.CT_node(k) = []; ct.raw.caseName(k) = [];
    [~,k] = setdiff(ct.zToControls.caseName,cnOrder);
    ct.zToControls.CT(k) = []; ct.zToControls.CT_L(k) = []; ct.zToControls.CT_R(k) = []; ct.zToControls.CT_node(k) = []; ct.zToControls.caseName(k) = [];
    [~,k] = setdiff(ct.flip.caseName,cnOrder);
    ct.flip.CT(k) = []; ct.flip.CT_L(k) = []; ct.flip.CT_R(k) = []; ct.flip.CT_node(k) = []; ct.flip.caseName(k) = [];

    ct.raw = sortFieldsContents(ct.raw, cnOrder);
    ct.zToControls = sortFieldsContents(ct.zToControls, cnOrder);
    ct.flip = sortFieldsContents(ct.flip, cnOrder);
end

function ctt = groupCortThick(ct,cInd,pInd)
    if isempty(ct)
        ctt = struct('raw', [], 'flip', [], 'zToControls', []);
        ctt.raw = struct('cData', [], 'pData', []);
        ctt.flip = struct('cData', [], 'pData', []);
        ctt.zToControls = struct('cData', [], 'pData', []);

        ctt.raw.cData.CT = [];        ctt.raw.cData.CT_node = [];
        ctt.raw.pData.CT = [];        ctt.raw.pData.CT_node = [];
        
        ctt.flip.cData.CT = [];        ctt.flip.cData.CT_node = [];
        ctt.flip.pData.CT = [];        ctt.flip.pData.CT_node = [];
        
        ctt.zToControls.cData.CT = [];        ctt.zToControls.cData.CT_node = [];
        ctt.zToControls.pData.CT = [];        ctt.zToControls.pData.CT_node = [];
        return;
    end
    ctt = ct;
    ctt.raw.cData.CT = ct.raw.CT(cInd);
    ctt.raw.cData.CT_node = ct.raw.CT_node(cInd);
    ctt.raw.pData.CT = ct.raw.CT(pInd);
    ctt.raw.pData.CT_node = ct.raw.CT_node(pInd);
    ctt.raw = rmfield(ctt.raw, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
    
    ctt.flip.cData.CT = ct.flip.CT(cInd);
    ctt.flip.cData.CT_node = ct.flip.CT_node(cInd);
    ctt.flip.pData.CT = ct.flip.CT(pInd);
    ctt.flip.pData.CT_node = ct.flip.CT_node(pInd);
    ctt.flip = rmfield(ctt.flip, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
    
    ctt.zToControls.cData.CT = ct.zToControls.CT(cInd);
    ctt.zToControls.cData.CT_node = ct.zToControls.CT_node(cInd);
    ctt.zToControls.pData.CT = ct.zToControls.CT(pInd);
    ctt.zToControls.pData.CT_node = ct.zToControls.CT_node(pInd);
    ctt.zToControls = rmfield(ctt.zToControls, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
end