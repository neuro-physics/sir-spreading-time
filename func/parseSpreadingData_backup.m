function d = parseSpreadingData(dirName, outFileName, isActThresh)
    if (nargin < 1) || isempty(dirName)
        dirName = '.';
    end
    if (nargin < 2)
        outFileName = [];
    end
    if (nargin < 3) || isempty(isActThresh)
        isActThresh = false;
    end
    if dirName(end) ~= filesep
        dirName = [ dirName, filesep ];
    end
    
    dataDir = { 'pt_*', 'sp_*', 'netact_*', '2s_*' };
    caseName = unique(getCaseName(getFirstSubdir(dirName)));
    
    disp('Parsing phase transition files ...');
    subDir = getOnlyDir([dirName,dataDir{1}]);
    PhaseTrans = parsePhaseTrans(dirName, subDir, caseName);
    
    disp('Parsing spreading time matrices files ...');
    subDir = getOnlyDir([dirName,dataDir{2}]);
    SpMatrix = parseSpreadingTime(dirName, subDir, caseName);
    
    disp('Parsing network activation files ...');
    subDir = getOnlyDir([dirName,dataDir{3}]);
    NetAct = parseNetworkActivation(dirName, subDir, caseName);

    disp('Parsing two seeds spreading files ...');
    subDir = getOnlyDir([dirName,dataDir{4}]);
    TwoSeeds = parseTwoSeeds(dirName, subDir, caseName);
    
    PhaseTrans = removeCaseNames(PhaseTrans);
    SpMatrix = removeCaseNames(SpMatrix);
    NetAct = removeCaseNames(NetAct);
    TwoSeeds = removeCaseNames(TwoSeeds);
    
    if isActThresh
        PhaseTrans = resetTheta(PhaseTrans);
        SpMatrix = resetTheta(SpMatrix);
        NetAct = resetTheta(NetAct);
        TwoSeeds = resetTheta(TwoSeeds);
    end
    
    if ~isempty(outFileName)
        outFileName = CheckAndGetFileName(outFileName);
        disp(['Saving ... ', outFileName]);
        save(outFileName, 'PhaseTrans', 'SpMatrix', 'NetAct', 'TwoSeeds', 'caseName', '-v7.3');
    end

    d.PhaseTrans = PhaseTrans;
    d.SpMatrix = SpMatrix;
    d.NetAct = NetAct;
    d.TwoSeeds = TwoSeeds;
    d.caseName = caseName;
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
        f = fieldnames(s);
        for i = 1:numel(f)
            l = f{i};
            if numel(s.(l)) == numel(caseNameOrder)
                [~,~,ic] = intersect(caseNameOrder, c);
                r.(l) = s.(l)(ic);
            else
                r.(l) = s.(l);
            end
        end
    else
        error('parseSpreadingData:sortFieldsContents','caseName is not a field of data struct');
    end
end

function d = parseTwoSeeds(dn,c,caseNameOrder)
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'theta', [], 'seedMode', [], 'weightSamp', [], 'data', []), size(c));
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
        else
            error('parseSpreadingData:parseTwoSeeds','.dat file support is not implemented');
        end
        d(i).data = sortFieldsContents(d(i).data, caseNameOrder);
    end
end

function d = loadTSMatFile(fd, f)
    d = struct('caseName', [], 'Cf',   [], 'Cp1',   [], 'Cp2',   [], 'H',   [], 'T',   [], 'Tn',   [],...
                               'Cf_Z', [], 'Cp1_Z', [], 'Cp2_Z', [], 'H_Z', [], 'T_Z', [], 'Tn_Z', []);
    d.caseName = cell(1,numel(f));
    d.Cf = cell(1,numel(f));
    d.Cp1 = cell(1,numel(f));
    d.Cp2 = cell(1,numel(f));
    d.H = cell(1,numel(f));
    d.T = cell(1,numel(f));
    d.Tn = cell(1,numel(f));
    d.Cf_Z = cell(1,numel(f));
    d.Cp1_Z = cell(1,numel(f));
    d.Cp2_Z = cell(1,numel(f));
    d.H_Z = cell(1,numel(f));
    d.T_Z = cell(1,numel(f));
    d.Tn_Z = cell(1,numel(f));
    for j = 1:numel(f)
        fn = f(j).name;
        fc = load([fd,fn]);
        d.caseName{j} = fc.caseName;
        d.Cf{j} = fc.Cf;
        d.Cp1{j} = fc.Cp1;
        d.Cp2{j} = fc.Cp2;
        d.H{j} = fc.H;
        d.T{j} = fc.T;
        if numel(fc.H) == 90 % quick and dirt hack that solves "out of memory exception"... I won't be able to calculate the local speed-ups though...
            d.Tn{j} = fc.Tn;
        end
        d.Cf_Z{j} = ZScoreMatrix(fc.Cf);
        d.Cp1_Z{j} = ZScoreMatrix(fc.Cp1);
        d.Cp2_Z{j} = ZScoreMatrix(fc.Cp2);
        d.H_Z{j} = ZScoreMatrix(fc.H);
        d.T_Z{j} = ZScoreMatrix(fc.T);
        if numel(fc.H) == 90 % quick and dirt hack that solves "out of memory exception"... I won't be able to calculate the local speed-ups though...
            d.Tn_Z{j} = ZScoreMatrix(fc.Tn,3);
        end
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

function d = parseNetworkActivation(dn,c,caseNameOrder)
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'theta', [], 'data', []), size(c));
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
    end
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

function d = parseSpreadingTime(dn,c,caseNameOrder)
    c = filterSpTimeDir(dn,c);
    if isempty(c)
        d = [];
        return;
    end
    d = repmat(struct('header', [], 'N', [], 'nSim', [], 'theta', [], 'data', []), size(c));
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
    d = repmat(struct('icType', [], 'weightSamp', [], 'nSim', [], 'N', [], 'data', []), size(c));
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
