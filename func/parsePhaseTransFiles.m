function r = parsePhaseTransFiles(inputPattern, outputDir, netSize, saveMatFile)
    if nargin < 2 || isempty(outputDir)
        outputDir = '.';
    end
    if nargin < 3 || isempty(netSize)
        netSize = 90; % lowres
    end
    if nargin < 4 || isempty(saveMatFile)
        saveMatFile = true;
    end
    
    N = netSize;

    [inputDir,~,fExt] = fileparts(inputPattern);
    if ~isempty(inputDir)
        inputDir = [ inputDir, filesep ];
    end
    isMatFile = strcmpi(fExt,'.mat');
    files = dir(inputPattern);
    caseName = cell(1,numel(files));
    Theta = cell(1,numel(files));
    nAct = cell(1,numel(files));
    rho = cell(1,numel(files));
    NVarRho = cell(1,numel(files));
    nC = numel(files);
    if isMatFile
        r = load(fullfile(inputDir,files(1).name));
        r.caseName = cell(1,nC);
        r.Theta = cell(1,nC);
        r.nAct = cell(1,nC);
        r.rho = cell(1,nC);
        r.NVarRho = cell(1,nC);
        if isfield(r, 'nActSeed')
            r.nActSeed = cell(1,nC);
        end
    else
        r = struct('caseName','','Theta',[],'nAct',[],'rho',[],'NVarRho',[],'N',N);
    end
    for i = 1:numel(files)
        if isMatFile
            d = load(fullfile(inputDir,files(i).name));
            r.caseName{i} = d.caseName;
            r.Theta{i} = d.Theta;
            r.nAct{i} = d.nAct;
            r.rho{i} = d.rho;
            r.NVarRho{i} = d.NVarRho;
            if isfield(d, 'nActSeed')
                r.nActSeed{i} = d.nActSeed;
            end
        else
            caseName{i} = getCaseName(files(i).name);%getCaseName(files(i).name, netSizeStr, 'pt_');
            d = importdata([inputDir,files(i).name], ' ', 1);
            hTxt = strsplit(d.textdata{1}(3:end));
            hTxt(strcmp('',hTxt)) = [];

            k = strcmp('theta', hTxt);
            Theta{i} = d.data(:,k)';

            k = strcmp('nAct', hTxt);
            nAct{i} = d.data(:,k)';

            k = strcmp('rho', hTxt);
            rho{i} = d.data(:,k)';

            k = strcmp('N*Var(rho)', hTxt);
            NVarRho{i} = d.data(:,k)';
        end
    end
    if ~isMatFile
        r.caseName = caseName;
        r.Theta = Theta;
        r.nAct = nAct;
        r.rho = rho;
        r.NVarRho = NVarRho;
    end
    if saveMatFile
        outFileName = getDirName(inputPattern);
        if isempty(outFileName)
            outFileName = 'pt.mat';
        else
            outFileName = [ outFileName, '.mat' ];
        end
        if outputDir(end) == filesep
            outputDir = outputDir(1:end-1);
        end
        outFileName = [ outputDir, filesep, CheckAndGetFileName(outFileName) ];
        if isMatFile
            save(outFileName, '-struct', 'r', '-v7.3');
        else
            save(outFileName, 'caseName', 'Theta', 'nAct', 'rho', 'NVarRho', 'N', '-v7.3');
        end
    end
end

% function n = getCaseName(inp, netSize)
%     [~,fn,~] = fileparts(inp);
%     if strcmpi(fn(1:3), 'pt_')
%         fn = fn(4:end);
%     end
%     n = strrep(fn, 'lowres', netSize);
% end

% function d = getDirName(p)
%     [ d, ~, ~ ] = fileparts(p);
%     if ~isempty(d)
%         [ ~, d1, d2 ] = fileparts(d);
%         d = [ d1, d2 ];
%     end
% end
