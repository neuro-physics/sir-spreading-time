function d = parseSpreadingData(dirName, outFileName, isActThresh, flipRTLE, zScoreIndividuals, shortPathMatFile, zeroToNaNSpTimeDiag, splitWeightedData, controlGroup, patientTableFile, postopExpGroup, postopTeorGroup, fiberLengthDir)
    if (nargin < 1) || isempty(dirName)
        dirName = '.';
    end
    if (nargin < 2)
        outFileName = [];
    end
    if (nargin < 3) || isempty(isActThresh)
        isActThresh = false;
    end
    if (nargin < 4) || isempty(flipRTLE)
        flipRTLE = false;
    end
    if (nargin < 5) || isempty(zScoreIndividuals)
        zScoreIndividuals = false; % if true, each output data matrix (or vector) is z-scored according to its own mean/stddev before z-scoring to controls and/or flipping
    end
    if (nargin < 6)
        shortPathMatFile = ''; % if empty, tries to load 'shortPath.mat' from the input directory
    end
    if (nargin < 7) || isempty(zeroToNaNSpTimeDiag)
        zeroToNaNSpTimeDiag = false;
    end
    if (nargin < 8) || isempty(splitWeightedData)
        splitWeightedData = false;
    end
    if (nargin < 9) || isempty(controlGroup)
        controlGroup = 'NC';
    end
    if (nargin < 10) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    if (nargin < 11) || isempty(postopExpGroup)
        postopExpGroup = '';
    end
    if (nargin < 12) || isempty(postopTeorGroup)
        postopTeorGroup = '';
    end
    if (nargin < 13) || isempty(fiberLengthDir)
        fiberLengthDir = '';
    end

    cdbDataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        cdbDataDir = '/host/scarus/local_raid/mauricio/data';
    end
    cdb = load(fullfile(cdbDataDir,patientTableFile)); % inputs variable casesMetaData containing a table of patients that Neda gave me

    if dirName(end) ~= filesep
        dirName = [ dirName, filesep ];
    end
    
    [~,~,~,aal] = aalsurfview(zeros(90,1));

    dataDir = { 'pt_*', 'sp_*', 'netact_*', '2s_*' };
    caseName = unique(getCaseName(getFirstSubdir(dirName)));
    controlInd = getControlIndices(caseName,controlGroup,cdb);
    flipInd = [];
    if flipRTLE
        flipInd = getRTLEIndices(caseName);
    end
    
    shortPath = [];
    if isempty(shortPathMatFile)
        shortPathMatFile = fullfile(dirName,'shortPath.mat');
        if exist(shortPathMatFile, 'file') == 2
            shortPath = load(shortPathMatFile);
            shortPath = sortFieldsContents(shortPath, caseName);
        end
    end

    disp('Parsing phase transition files ...');
    subDir = getOnlyDir([dirName,dataDir{1}]);
    PhaseTrans = parsePhaseTrans(dirName, subDir, caseName);
    
    disp('Parsing spreading time matrices files ...');
    subDir = getOnlyDir([dirName,dataDir{2}]);
    SpMatrix = parseSpreadingTime(dirName, subDir, caseName, controlInd, flipInd, aal, zScoreIndividuals, shortPath, zeroToNaNSpTimeDiag);
    
    disp('Parsing weighted spreading time matrices files ...');
    subDir = getOnlyDir([dirName,dataDir{2}]);
    SpMatrixW = parseSpreadingTimeWeighted(dirName, subDir, caseName, controlInd, flipInd, aal, zScoreIndividuals, shortPath, zeroToNaNSpTimeDiag);
    
    disp('Parsing network activation files ...');
    subDir = getOnlyDir([dirName,dataDir{3}]);
    NetAct = parseNetworkActivation(dirName, subDir, caseName, controlInd, flipInd, aal, zScoreIndividuals);

    disp('Parsing two seeds spreading files ...');
    subDir = getOnlyDir([dirName,dataDir{4}]);
    TwoSeeds = parseTwoSeeds(dirName, subDir, caseName, controlInd, flipInd, aal, zScoreIndividuals);

    PhaseTrans = removeCaseNames(PhaseTrans);
    SpMatrix = clearDataArrays(removeCaseNames(SpMatrix), { 'SAvg_Z_local', 'SAvg_Z' });
    SpMatrixW = removeCaseNames(SpMatrixW);
    NetAct = clearDataArrays(removeCaseNames(NetAct), { 'T_Z' });
    TwoSeeds = removeCaseNames(TwoSeeds);

    if isActThresh
        PhaseTrans = resetTheta(PhaseTrans);
        SpMatrix = resetTheta(SpMatrix);
        SpMatrixW = resetTheta(SpMatrixW);
        NetAct = resetTheta(NetAct);
        TwoSeeds = resetTheta(TwoSeeds);
    end

    SpeedUp = [];
    SpeedUpW = [];
    if ~isempty(TwoSeeds)
        if ~isempty(SpMatrix)
            disp('Calculating Speed-ups ...');
            SpeedUp = calcSpeedUp(SpMatrix,TwoSeeds,caseName,controlInd,flipInd,aal,zScoreIndividuals,zeroToNaNSpTimeDiag);
        end
        if ~isempty(SpMatrixW)
            disp('Calculating Weighted Speed-ups ...');
            SpeedUpW = calcSpeedUpWeighted(SpMatrixW,TwoSeeds,caseName,controlInd,flipInd,aal,zScoreIndividuals,zeroToNaNSpTimeDiag);
        end
        TwoSeeds = clearCooperativeSeeds(clearDataArrays(TwoSeeds, { 'Tn', 'Tn_Z', 'Twn' }));
    end

    SpPostopImp = [];
    SpPostopImpW = [];
    if ~(isempty(postopExpGroup) || isempty(postopTeorGroup))
        if ~isempty(SpMatrix)
            disp('Calculating postop improvement ...');
            SpPostopImp = calcPostopImprovement(SpMatrix,cdb,postopExpGroup,postopTeorGroup,fiberLengthDir);
        end
        if ~isempty(SpMatrixW)
            disp('Calculating Weighted postop improvement ...');
            SpPostopImpW = calcPostopImprovement(SpMatrixW,cdb,postopExpGroup,postopTeorGroup,fiberLengthDir);
        end
    end

    if ~isempty(outFileName)
        outFileName = CheckAndGetFileName(outFileName);
        if splitWeightedData
            disp(['Saving ... ', outFileName]);
            save(outFileName, 'PhaseTrans', 'SpMatrix', 'NetAct', 'TwoSeeds', 'SpeedUp', 'SpPostopImp', 'caseName', '-v7.3');
            [dn,fn,fe] = fileparts(outFileName);
            outFileName = fullfile(dn,[fn,'_w',fe]);
            disp(['Saving ... ', outFileName]);
            save(outFileName, 'PhaseTrans', 'SpMatrixW', 'NetAct', 'TwoSeeds', 'SpeedUpW', 'SpPostopImpW', 'caseName', '-v7.3');
        else
            disp(['Saving ... ', outFileName]);
            save(outFileName, 'PhaseTrans', 'SpMatrix', 'SpMatrixW', 'NetAct', 'TwoSeeds', 'SpeedUp', 'SpeedUpW', 'caseName', '-v7.3');
        end
    end

    d.PhaseTrans = PhaseTrans;
    d.SpMatrix = SpMatrix;
    d.SpMatrixW = SpMatrixW;
    d.NetAct = NetAct;
    d.TwoSeeds = TwoSeeds;
    d.SpeedUp = SpeedUp;
    d.SpeedUpW = SpeedUpW;
    d.caseName = caseName;
end

function ts = clearCooperativeSeeds(ts)
    compInd = strcmpi({ts(:).seedMode}, 'competitive');
    ts = ts(compInd);
end

function s = clearDataArrays(s,fieldNames)
    if ~iscell(fieldNames)
        fieldNames = { fieldNames };
    end
    n = numel(s);
    for i = 1:n
        for j = 1:numel(fieldNames)
            if isfield(s(i),'data')
                if ~isempty(s(i).data) && isfield(s(i).data, fieldNames{j})
                    s(i).data.(fieldNames{j}) = [];
                    s(i).data = rmfield(s(i).data, fieldNames{j});
                end
            end
            if isfield(s(i),'flipData')
                if ~isempty(s(i).flipData) && isfield(s(i).flipData, fieldNames{j})
                    s(i).flipData.(fieldNames{j}) = [];
                    s(i).flipData = rmfield(s(i).flipData, fieldNames{j});
                end
            end
            if isfield(s(i),'zControlData')
                if ~isempty(s(i).zControlData) && isfield(s(i).zControlData, fieldNames{j})
                    s(i).zControlData.(fieldNames{j}) = [];
                    s(i).zControlData = rmfield(s(i).zControlData, fieldNames{j});
                end
            end
        end
    end
end

function r = zScoreToControlsAndFlip(s,caseName,controlInd,flipInd,aal,zScoreIndividuals)
    disp(' -> Z-scoring according to controls and flipping data...');
    N = numel(caseName);
    f = fieldnames(s);
    f(strcmpi(f,'caseName')) = [];
    kLeft = [];
    kRight = [];
    for i = 1:numel(f)
        l = f{i}; % for each field of the input data struct s
                  % we are only interested in those fields which contain cell arrays of the same size as caseName
        if iscell(s.(l)) && (numel(s.(l)) == N)
            if any(~cellfun(@isempty,s.(l))) % if there is any content in the cell array s.(l)
                fprintf('    ... %s\n',l);
                %sz = size(s.(l){1});
                %D = matCell2Mat(ZScoreMatrix(s.(l))); % calculate Z-score of each case and makes each case a line in the table of data D
                %Cmean = mean(D(controlInd,:),1,'omitnan'); % average Z-score of controls
                %Cstd = std(D(controlInd,:),[],1,'omitnan');
                %D = (D - repmat(Cmean,N,1)) ./ repmat(Cstd,N,1); % calculate Z-score relative to controls for all cases
                %D(isnan(D)) = 0;
                %[r.(l),kLeft,kRight] = flipAALMatrix_rowsPerCols(reshapeLines(D,sz,'cell'),aal,flipInd,kLeft,kRight);
                if zScoreIndividuals
                    dataTemp = ZScoreMatrix(s.(l));
                else
                    dataTemp = s.(l);
                end
                [r.(l),kLeft,kRight] = flipAALMatrix_rowsPerCols(zScoreToSubset(dataTemp, controlInd),aal,flipInd,kLeft,kRight);
            else
                r.(l) = s.(l); % otherwise, keep field l intact
            end
        else
            r.(l) = s.(l); % otherwise, keep field l intact
        end
    end
end

function r = zScoreToControls(s,caseName,controlInd,zScoreIndividuals)
    disp(' -> Z-scoring according to controls...');
    N = numel(caseName);
    f = fieldnames(s);
    f(strcmpi(f,'caseName')) = [];
    for i = 1:numel(f)
        l = f{i}; % for each field of the input data struct s
                  % we are only interested in those fields which contain cell arrays of the same size as caseName
        if iscell(s.(l)) && (numel(s.(l)) == N)
            if any(~cellfun(@isempty,s.(l))) % if there is any content in the cell array s.(l)
                fprintf('    ... %s\n',l);
                if zScoreIndividuals
                    dataTemp = ZScoreMatrix(s.(l));
                else
                    dataTemp = s.(l);
                end
                r.(l) = zScoreToSubset(dataTemp, controlInd);
            else
                r.(l) = s.(l); % otherwise, keep field l intact
            end
        else
            r.(l) = s.(l); % otherwise, keep field l intact
        end
    end
end

function k = getRTLEIndices(caseName)
    [~,cases] = getPatientIndex([],'Group','RTLE',[]);
    [~,k,~] = intersect(caseName,cases,'stable');
end

function k = getControlIndices(caseName,controlGroup,cdb)
    [~,cases] = getPatientIndex(cdb.casesMetaData,'Group',controlGroup,[]);
    [~,k,~] = intersect(caseName,cases,'stable');
end

function s = getFirstSubdir(d)
    if d(end) ~= filesep
        d(end+1) = filesep;
    end
    c = dir(d);
    for i = 1:numel(c)
        if c(i).isdir
            s = [d,c(i).name];
        end
    end
end

function d = removeCaseNames(d)
    for i = 1:numel(d)
        d(i).data = rmfield(d(i).data, 'caseName');
    end
end

function r = sortFieldsContents(s, caseNameOrder)
    if isfield(s, 'caseName')
        c = s.caseName;
        [~,~,ic] = intersect(caseNameOrder, c, 'stable');
        f = fieldnames(s);
        for i = 1:numel(f)
            l = f{i};
            if numel(s.(l)) == numel(caseNameOrder)
                r.(l) = s.(l)(ic);
            else
                r.(l) = s.(l);
            end
        end
    else
        error('parseSpreadingData:sortFieldsContents','caseName is not a field of data struct');
    end
end

function su = calcSpeedUpWeighted(s,ts,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals,zeroToNaNSpTimeDiag)
    compInd = strcmpi({ts(:).seedMode}, 'competitive');
    ts = ts(~compInd);
    theta_s = [s(:).theta];
    theta_ts = [ts(:).theta];

    [thetaSel,ks,kts] = intersect(theta_s, theta_ts, 'stable');
    s = s(ks);
    ts = ts(kts);

    su = ts;

    nT = numel(thetaSel);
    for i = 1:nT
        su(i).header = {{'Uglobal','Global speed-ups according to Misic 2015 for weighted sp time'};...
                        {'Ulocal','Local speed-ups based on 3D tensor (2seeds -> 1target) for weighted sp time'};...
                        {'Ulocalnet','Lobal speed-ups according to Misic 2015 for weighted sp time'}};
        su(i).theta = thetaSel(i);
        su(i).data = struct('Uglobal', [], 'Ulocal', [], 'Ulocalnet', []);%, 'Uglobal_Z', [], 'Ulocal_Z', [], 'Ulocalnet_Z', []);

        su(i).data.Uglobal = CalcSpeedUps(ts(i).data.Tw, s(i).data.SAvg, 'global',zeroToNaNSpTimeDiag);
        if isempty(ts(i).data.Twn) || (iscell(ts(i).data.Twn) && isempty(ts(i).data.Twn{1}))
            su(i).data.Ulocal = [];
        else
            su(i).data.Ulocal = CalcSpeedUps(ts(i).data.Twn, s(i).data.SAvg, 'local',zeroToNaNSpTimeDiag);
        end
        su(i).data.Ulocalnet = CalcSpeedUps(ts(i).data.Tw, s(i).data.SAvg, 'localnet',zeroToNaNSpTimeDiag);

        if ~isempty(flipInd)
            su(i).flipData = zScoreToControlsAndFlip(su(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
        su(i).zControlData = zScoreToControls(su(i).data, caseNameOrder, controlInd, zScoreIndividuals);
    end
    [~,ind] = sort([su(:).theta]);
    su = su(ind);
end

function su = calcSpeedUp(s,ts,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals,zeroToNaNSpTimeDiag)
    compInd = strcmpi({ts(:).seedMode}, 'competitive');
    ts = ts(~compInd);
    theta_s = [s(:).theta];
    theta_ts = [ts(:).theta];

    [thetaSel,ks,kts] = intersect(theta_s, theta_ts, 'stable');
    s = s(ks);
    ts = ts(kts);

    su = ts;

    nT = numel(thetaSel);
    for i = 1:nT
        su(i).header = {{'Uglobal','Global speed-ups according to Misic 2015'};...
                        {'Ulocal','Local speed-ups based on 3D tensor (2seeds -> 1target)'};...
                        {'Ulocalnet','Lobal speed-ups according to Misic 2015'}};
        su(i).theta = thetaSel(i);
        su(i).data = struct('Uglobal', [], 'Ulocal', [], 'Ulocalnet', []);%, 'Uglobal_Z', [], 'Ulocal_Z', [], 'Ulocalnet_Z', []);

        su(i).data.Uglobal = CalcSpeedUps(ts(i).data.T, s(i).data.SAvg, 'global',zeroToNaNSpTimeDiag);
        if isempty(ts(i).data.Tn) || (iscell(ts(i).data.Tn) && isempty(ts(i).data.Tn{1}))
            su(i).data.Ulocal = [];
        else
            su(i).data.Ulocal = CalcSpeedUps(ts(i).data.Tn, s(i).data.SAvg, 'local',zeroToNaNSpTimeDiag);
        end
        su(i).data.Ulocalnet = CalcSpeedUps(ts(i).data.T, s(i).data.SAvg, 'localnet',zeroToNaNSpTimeDiag);
%         su(i).data.Uglobal_Z = ZScoreMatrix(su(i).data.Uglobal);
%         su(i).data.Ulocal_Z = ZScoreMatrix(su(i).data.Ulocal);
%         su(i).data.Ulocalnet_Z = ZScoreMatrix(su(i).data.Ulocalnet);

        if ~isempty(flipInd)
            su(i).flipData = zScoreToControlsAndFlip(su(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
        su(i).zControlData = zScoreToControls(su(i).data, caseNameOrder, controlInd, zScoreIndividuals);
    end
    [~,ind] = sort([su(:).theta]);
    su = su(ind);
end

function d = parseTwoSeeds(dn,c,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals)
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'theta', [], 'seedMode', [], 'weightSamp', [], 'data', [], 'flipData', [], 'zControlData', []), size(c));
    for i = 1:numel(c)
        fd = [dn,c(i).name];
        if ~isdir(fd)
            continue;
        end
        fd = [fd,filesep];
        f = dir([fd,'*.mat']);
        if isempty(f)
            f = dir([fd,'*.dat']);
        end
        if isempty(f)
            error('parseSpreadingData:parseTwoSeeds','%s directory empty', fd);
        end
        [d(i).header, d(i).N, d(i).theta, d(i).seedMode, d(i).weightSamp, isMatFile] = getTSInfo(fd,f(1).name);
        if isMatFile
            d(i).data = loadTSMatFile(fd,f);
            % forcing the following variables to be empty to avoid "out of memory exception"... I would delete them anyways later
            % and they are good only to calculate speed-ups which I am not going to use...
            d(i).data.Tn = [];
            d(i).data.Twn = [];
        else
            error('parseSpreadingData:parseTwoSeeds','.dat file support is not implemented');
        end
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
        d(i).zControlData = zScoreToControls(d(i).data, caseNameOrder, controlInd, zScoreIndividuals);
        if ~isempty(flipInd)
            d(i).flipData = zScoreToControlsAndFlip(d(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
    end
    [~,ind] = sort([d(:).theta]);
    d = d(ind);
end

function d = loadTSMatFile(fd, f)
    d = struct('caseName', [], 'Cf',   [], 'Cp1',   [], 'Cp2',   [], 'H',   [], 'T',   [], 'Tn',   [], 'Tw',   [], 'Twn',   []);

    d.caseName = cell(1,numel(f));
    d.Cf = cell(1,numel(f));
    d.Cp1 = cell(1,numel(f));
    d.Cp2 = cell(1,numel(f));
    d.H = cell(1,numel(f));
    d.T = cell(1,numel(f));
    d.Tn = cell(1,numel(f));
    d.Tw = cell(1,numel(f));
    d.Twn = cell(1,numel(f));
%     d.Cf_Z = cell(1,numel(f));
%     d.Cp1_Z = cell(1,numel(f));
%     d.Cp2_Z = cell(1,numel(f));
%     d.H_Z = cell(1,numel(f));
%     d.T_Z = cell(1,numel(f));
%     d.Tn_Z = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.Cf{j} = fc.Cf;
        d.Cp1{j} = fc.Cp1;
        d.Cp2{j} = fc.Cp2;
        d.H{j} = fc.H;
        d.T{j} = fc.T;
        d.Tw{j} = fc.Tw;
        if numel(fc.H) == 90 % quick and dirt hack that solves "out of memory exception"... I won't be able to calculate the local speed-ups though...
            d.Tn{j} = fc.Tn;
            d.Twn{j} = fc.Twn;
        end
%         d.Cf_Z{j} = ZScoreMatrix(fc.Cf);
%         d.Cp1_Z{j} = ZScoreMatrix(fc.Cp1);
%         d.Cp2_Z{j} = ZScoreMatrix(fc.Cp2);
%         d.H_Z{j} = ZScoreMatrix(fc.H);
%         d.T_Z{j} = ZScoreMatrix(fc.T);
%         if numel(fc.H) == 90 % quick and dirt hack that solves "out of memory exception"... I won't be able to calculate the local speed-ups though...
%             d.Tn_Z{j} = ZScoreMatrix(fc.Tn,3);
%         end
    end
end

function [header,N,theta,seedMode,wSamp,isMat] = getTSInfo(fd,fn)
    [~,~,ext] = fileparts(fn);
    isMat = strcmpi(ext,'.mat');
    if isMat
        d = load([fd,fn]);
        N = d.N;
        header = d.header;
        
        if fd(end) == filesep
            fd = fd(1:end-1);
        end
        [~,dn,dn2] = fileparts(fd);
        dn = [dn,dn2];

        if isfield(d, 'theta')
            theta = d.theta;
        else
            theta = getParamValFromName(dn, 'theta', 'theta\d+\.*\d*');
        end
        if isfield(d, 'seedMode')
            seedMode = d.seedMode;
        else
            seedMode = getParamByFlag(dn, '_(coop|comp)', { 'coop', 'cooperative'; 'comp', 'competitive' } );
        end
        wSamp = getParamByFlag(dn, '_(b|(?!wr)w|wr)_*', { 'b', 'binary'; 'w', 'weighted'; 'wr', 'randweight' } );
    else
        error('parseSpreadingData:getTSInfo','.dat file support is not implemented');
    end
end

function d = parseNetworkActivation(dn,c,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals)
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'theta', [], 'data', [], 'flipData', [], 'zControlData', []), size(c));
    for i = 1:numel(c)
        fd = [dn,c(i).name];
        if ~isdir(fd)
            continue;
        end
        fd = [fd,filesep];
        f = dir([fd,'*.mat']);
        if isempty(f)
            f = dir([fd,'*.dat']);
        end
        if isempty(f)
            error('parseSpreadingData:parseNetworkActivation','%s directory empty', fd);
        end
        [d(i).header, d(i).N, d(i).theta, isMatFile] = getNAInfo(fd,f(1).name);
        if isMatFile
            d(i).data = loadNAMatFile(fd,f);
        else
            error('parseSpreadingData:parseNetworkActivation','.dat file support is not implemented');
        end
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
        d(i).zControlData = zScoreToControls(d(i).data, caseNameOrder, controlInd, zScoreIndividuals);
        if ~isempty(flipInd)
            d(i).flipData = zScoreToControlsAndFlip(d(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
    end
    [~,ind] = sort([d(:).theta]);
    d = d(ind);
end

function d = loadNAMatFile(fd, f)
    d = struct('caseName', [], 'seedInd', [], 'T', [], 'T_Z', []);
    d.caseName = cell(1,numel(f));
    d.seedInd = cell(1,numel(f));
    d.T = cell(1,numel(f));
    d.T_Z = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.seedInd{j} = fc.seedInd;
        d.T{j} = fc.T;
        d.T_Z{j} = ZScoreMatrix(fc.T);
    end
end

function [header,N,theta,isMat] = getNAInfo(fd,fn)
    [~,~,ext] = fileparts(fn);
    isMat = strcmpi(ext,'.mat');
    if isMat
        d = load([fd,fn]);
        N = d.N;
        header = d.header;
        if isfield(d, 'theta')
            theta = d.theta;
        else
            if fd(end) == filesep
                fd = fd(1:end-1);
            end
            [~,dn,dn2] = fileparts(fd);
            dn = [dn,dn2];
            theta = getParamValFromName(dn, 'theta', 'theta\d+\.*\d*');
        end
    else
        error('parseSpreadingData:getNAInfo','.dat file support is not implemented');
    end
end

function d = parseSpreadingTimeWeighted(dn,c,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals,shortPath,zeroToNaNSpTimeDiag)
    c = filterSpTimeDir(dn,c);
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'nSim', [], 'theta', [], 'data', [], 'flipData', [], 'zControlData', []), size(c));
    for i = 1:numel(c)
        fd = [dn,c(i).name];
        if ~isdir(fd)
            continue;
        end
        fd = [fd,filesep];
        f = dir([fd,'*.mat']);
        if isempty(f)
            f = dir([fd,'*.dat']);
        end
        if isempty(f)
            error('parseSpreadingData:parseSpreadingTime','%s directory empty', fd);
        end
        [d(i).header, d(i).N, d(i).nSim, d(i).theta, ~] = getSTInfo(fd,f(1).name);
        d(i).data = loadSTMatFileWeighted(fd,f);
        d(i).data.theta = d(i).theta;
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
        
        if zeroToNaNSpTimeDiag
            d(i).data.SAvg = cellfun(@mainDiagToNaN,d(i).data.SAvg,'UniformOutput',false);
        end

        d(i).data.SAvgR = cellfun(@(x)x',myMean(d(i).data.SAvg,1,'omitnan'),'UniformOutput',false);
        d(i).data.SAvgS = myMean(d(i).data.SAvg,2,'omitnan');

        % it does not make sense to calculate Hamming Distance because at theta=0 the Sp time weighted matrix is different than any short path matrix (either binary or weighted by distance)
%         if isempty(shortPath)
%             d(i).data.D_node = [];
%         else
%             d(i).data.D_node = hammingDistance(d(i).data.SAvg, shortPath.P); % hamming distance between individual nodes for each subject
%         end

%         d(i).data.SAvgR_Z = ZScoreMatrix(d(i).data.SAvgR);
%         d(i).data.SAvgS_Z = ZScoreMatrix(d(i).data.SAvgS);

        d(i).zControlData = zScoreToControls(d(i).data, caseNameOrder, controlInd, zScoreIndividuals);
        if ~isempty(flipInd)
            d(i).flipData = zScoreToControlsAndFlip(d(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
    end
    [~,ind] = sort([d(:).theta]);
    d = d(ind);
end

function d = loadSTMatFileWeighted(fd, f)
    d = struct('caseName', [], 'theta', [], 'SAvg', []);
    d.caseName = cell(1,numel(f));
    d.SAvg = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.SAvg{j} = fc.Tw;
    end
end

function d = parseSpreadingTime(dn,c,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals,shortPath,zeroToNaNSpTimeDiag)
    c = filterSpTimeDir(dn,c);
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'nSim', [], 'theta', [], 'data', [], 'flipData', [], 'zControlData', []), size(c));
    for i = 1:numel(c)
        fd = [dn,c(i).name];
        if ~isdir(fd)
            continue;
        end
        fd = [fd,filesep];
        f = dir([fd,'*.mat']);
        if isempty(f)
            f = dir([fd,'*.dat']);
        end
        if isempty(f)
            error('parseSpreadingData:parseSpreadingTime','%s directory empty', fd);
        end
        [d(i).header, d(i).N, d(i).nSim, d(i).theta, isMatFile] = getSTInfo(fd,f(1).name);
        if isMatFile
            d(i).data = loadSTMatFile(fd,f);
            d(i).data.theta = d(i).theta;
        else
            d(i).data = parseSpreadingTimeMatrixFiles(fd, '', '', [], [], false);
        end
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
        
        if zeroToNaNSpTimeDiag
            d(i).data.SAvg = cellfun(@mainDiagToNaN,d(i).data.SAvg,'UniformOutput',false);
        end

        d(i).data.SAvgR = cellfun(@(x)x',myMean(d(i).data.SAvg,1,'omitnan'),'UniformOutput',false);
        d(i).data.SAvgS = myMean(d(i).data.SAvg,2,'omitnan');

        if isempty(shortPath)
            d(i).data.D_node = [];
        else
            d(i).data.D_node = hammingDistance(d(i).data.SAvg, shortPath.P); % hamming distance between individual nodes for each subject
        end

%         d(i).data.SAvgR_Z = ZScoreMatrix(d(i).data.SAvgR);
%         d(i).data.SAvgS_Z = ZScoreMatrix(d(i).data.SAvgS);

        d(i).zControlData = zScoreToControls(d(i).data, caseNameOrder, controlInd, zScoreIndividuals);
        if ~isempty(flipInd)
            d(i).flipData = zScoreToControlsAndFlip(d(i).data,caseNameOrder,controlInd,flipInd,aal,zScoreIndividuals);
        end
    end
    [~,ind] = sort([d(:).theta]);
    d = d(ind);
end

function X = mainDiagToNaN(X)
    N = size(X,1);
    X(1:(N+1):end)=NaN;
end

function D = hammingDistance(S,P)
    D = cell(1,numel(S));
    for i = 1:numel(S)
        H = CalcHammingDist(S{i}, P{i});
        D{i} = reshape(H,numel(H),1); % calculating hamming distance between spreading and shortest path matrices
    end
end

function c = filterSpTimeDir(d,dn)
    k = [];
    for i = 1:numel(dn)
        r = dir([d,dn(i).name,filesep,'1s_avg*.mat']);
        if isempty(r)
            r = dir([d,dn(i).name,filesep,'1s_avg*.dat']);
            if isempty(r)
                k(end+1) = i;
            end
        end
    end
    c = dn;
    c(k) = [];
end

function d = loadSTMatFile(fd, f)
    d = struct('caseName', [], 'theta', [], 'SAvg',   [], 'SVar', [],...
                                            'SAvg_Z', [], 'SAvg_Z_local', []);
    d.caseName = cell(1,numel(f));
    d.SAvg = cell(1,numel(f));
    d.SAvg_Z = cell(1,numel(f));
    d.SAvg_Z_local = cell(1,numel(f));
    d.SVar = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.SAvg{j} = fc.T;
        d.SAvg_Z{j} = ZScoreMatrix(fc.T);
        d.SAvg_Z_local{j} = ZScoreMatrix(fc.T,2);
        d.SVar{j} = fc.V;
    end
end

function [header,N,nSim,theta,isMat] = getSTInfo(fd,fn)
    [~,~,ext] = fileparts(fn);
    isMat = strcmpi(ext,'.mat');
    if isMat
        d = load([fd,fn]);
        nSim = d.nSim;
        N = d.N;
        header = d.header;
        if isfield(d, 'theta')
            theta = d.theta;
        else
            if fd(end) == filesep
                fd = fd(1:end-1);
            end
            [~,dn,dn2] = fileparts(fd);
            dn = [dn,dn2];
            theta = getParamValFromName(dn, 'theta', 'theta\d+\.*\d*');
        end
    else
        if fd(end) == filesep
            fd = fd(1:end-1);
        end
        [rd,dn,dn2] = fileparts(fd);
        dn = [dn,dn2];
        [~,netDir,~] = fileparts(rd);
        nSim = getParamValFromName(dn, 'nSim', 'nSim\d+');
        theta = getParamValFromName(dn, 'theta', 'theta\d+\.*\d*');
        if ~isempty(strfind(netDir,'CoCoMac'))
            N = 242;
        else
            N = getParamValFromName(dn, 'N', 'N\d+');
        end
        header = 'spreading time from node to node, T, and variance of T, V, for many nSim simulations';
    end
end

function d = parsePhaseTrans(dn,c,caseNameOrder)
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('icType', [], 'weightSamp', [], 'nSim', [], 'N', [], 'data', [], 'flipData', [], 'zControlData', []), size(c));
    for i = 1:numel(c)
        fd = [dn,c(i).name];
        if ~isdir(fd)
            continue;
        end
        fd = [fd,filesep];
        f = dir([fd,'*.mat']);
        if isempty(f)
            f = dir([fd,'*.dat']);
        end
        if isempty(f)
            error('parseSpreadingData:parsePhaseTrans','%s directory empty', fd);
        end
        [d(i).icType, d(i).weightSamp, d(i).nSim, d(i).N, isMatFile] = getPTInfo(fd,f(1).name);
        if isMatFile
            d(i).data = loadPTMatFile(fd,f);
        else
            d(i).data = parsePhaseTransFiles([fd,'pt*.dat'], '', d(i).N, false);
            d(i).data = rmfield(d(i).data,'N');
        end
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
    end
end

function d = loadPTMatFile(fd, f)
    d = struct('caseName', [], 'Theta', [], 'nAct', [], 'rho', [], 'NVarRho', [], 'nActPerSeed', [], 'thetaPerSeed', []);
    d.caseName = cell(1,numel(f));
    d.Theta = cell(1,numel(f));
    d.nAct = cell(1,numel(f));
    d.rho = cell(1,numel(f));
    d.NVarRho = cell(1,numel(f));
    d.nActPerSeed = cell(1,numel(f));
    d.thetaPerSeed = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.Theta{j} = fc.Theta;
        d.nAct{j} = fc.nAct;
        d.rho{j} = fc.rho;
        d.NVarRho{j} = fc.NVarRho;
        d.nActPerSeed{j} = fc.nActSeed;
        d.thetaPerSeed{j} = fc.thetaSeed;
    end
end

function [icType,wSamp,nSim,N,isMat] = getPTInfo(fd,fn)
    [~,~,ext] = fileparts(fn);
    isMat = strcmpi(ext,'.mat');
    if isMat
        d = load([fd,fn]);
        icType = d.icType;
        nSim = d.nSim;
        N = d.N;
        if isfield(d, 'wSamp')
            wSamp = d.wSamp;
        else
            if fd(end) == filesep
                fd = fd(1:end-1);
            end
            [~,dn,dn2] = fileparts(fd);
            dn = [dn,dn2];
            wSamp = getParamByFlag(dn, '_(b|(?!wr)w|wr)_*', { 'b', 'binary'; 'w', 'weighted'; 'wr', 'randweight' } );
        end
    else
        if fd(end) == filesep
            fd = fd(1:end-1);
        end
        [rd,dn,dn2] = fileparts(fd);
        dn = [dn,dn2];
        [~,netDir,~] = fileparts(rd);
        nSim = getParamValFromName(dn, 'nSim', 'nSim\d+');
        if ~isempty(strfind(netDir,'CoCoMac'))
            N = 242;
        else
            N = getParamValFromName(netDir, 'N', 'N\d+');
        end
        icType = getParamByFlag(dn, '_((?!fm)f|fm|r)_', { 'f', 'fixed'; 'r', 'random'; 'fm', 'mostconn' } );
        wSamp = getParamByFlag(dn, '_(b|(?!wr)w|wr)_*', { 'b', 'binary'; 'w', 'weighted'; 'wr', 'randweight' } );
    end
end

function d = getOnlyDir(path)
    d = dir(path);
    k = [];
    for i = 1:numel(d)
        if ~d(i).isdir
            k(end+1) = i;
        end
    end
    d(k) = [];
end

function g = getDefaultPostopExpGroup(cdb)
    g = unique(cdb.casesMetaData.Group);
    g = g(cellfun(@(x)~isempty(x),regexp(g,'(_|^)POSTOP(_|$)','match')));
end

function g = getDefaultPostopTeorGroup(cdb)
    g = unique(cdb.casesMetaData.Group);
    g = g(cellfun(@(x)~isempty(x),regexp(g,'(_|^)POSTOPSIM(_|$)','match')));
end