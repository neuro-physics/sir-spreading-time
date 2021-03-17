function r = parseSpreadingTimeMatrixFiles(inputDir, outputFileName, inputAdjMatPathPtrn, ggamma, nTrials, saveMatFile)
    if nargin < 2 || isempty(outputFileName)
        tempDir = inputDir;
        if tempDir(end)~=filesep
            tempDir(end+1) = filesep;
        end
        outputFileName = [tempDir,getDirName(inputDir),'.mat'];
    end
    if nargin < 3 || isempty(inputAdjMatPathPtrn)
        calcCommunity = false;
    end
    if nargin < 4 || isempty(ggamma)
        ggamma = 2;
    end
    if nargin < 5 || isempty(nTrials)
        nTrials = 10;
    end
    if nargin < 6 || isempty(saveMatFile)
        saveMatFile = 'new';
    end
    
    if ~isempty(inputDir) && (inputDir(end) ~= filesep)
        inputDir = [ inputDir, filesep ];
    end
    spFiles = dir([inputDir,'1s_avg_*.dat']);
    varFiles = dir([inputDir,'1s_var_*.dat']);
    varFileList = { varFiles(:).name };
    
    % getting the value of theta
    temp = regexp(inputDir, 'theta\d+\.*\d*', 'match');
    theta = str2double(temp{1}(6:end));

    if calcCommunity
        Ac = GetConsensusAdjMatrix(inputAdjMatPathPtrn);
        C = GenerateCommunity(Ac, ggamma, nTrials);
        N = numel(Ac(:,1));
    end

    caseName = cell(1,numel(spFiles));
    SAvg = cell(1,numel(spFiles));
    SVar = cell(1,numel(spFiles));
    if calcCommunity
        r = struct('caseName', [], 'SAvg',[],'SVar',[],'Ac',[],'C',[]);
    else
        r = struct('caseName', [], 'SAvg',[],'SVar',[]);
    end
    for i = 1:numel(spFiles)
        cn = getCaseName(spFiles(i).name);
        if isempty(cn)
            k = 1;
            warning('case name not found, assuming first var file');
        else
            k = find(cellfun(@(x)~isempty(x),strfind(varFileList, cn)));
        end
        if numel(k) ~= 1
            error('parseSpreadingTimeMatrixFiles:inputDir', 'could not find (or found many) variance file for avg file %s', spFiles(i).name);
        end
        
        %netSizeStr = [ 'N', num2str(netSize) ];
        caseName{i} = cn;%getCaseName(spFiles(i).name, netSizeStr, '1s_avg_');

        d = importdata([inputDir,spFiles(i).name], ' ', 1);
        SAvg{i} = d.data;
        
        d = importdata([inputDir,varFiles(k).name], ' ', 1);
        SVar{i} = d.data;
    end
    r.caseName = caseName;
    r.SAvg = SAvg;
    r.SVar = SVar;
    r.theta = theta;
    if (calcCommunity)
        r.C = C;
        r.Ac = Ac;
        r.N = N;
    end
    if saveMatFile
        if strcmp(saveMatFile,'new')
            outputFileName = CheckAndGetFileName(outputFileName);
            disp(['Creating new file ... ', outputFileName]);
        elseif strcmp(saveMatFile,'replace')
            disp(['Replacing file ... ', outputFileName]);
        else
            outputFileName = CheckAndGetFileName(outputFileName);
            disp(['Creating new file ... ', outputFileName]);
        end
        if calcCommunity
            save(outputFileName, 'caseName', 'SAvg', 'SVar', 'C', 'Ac', 'N', 'theta', '-v7.3');
        else
            save(outputFileName, 'caseName', 'SAvg', 'SVar', 'theta', '-v7.3');
        end
    end
end
