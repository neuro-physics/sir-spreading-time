function RunNetworkActivationTime(inputFile, useBinaryMatrix, Theta, tTotal, nSeeds, isCompetitive, seedType, seedInd, outDirName, outFileType)
% inputFile        -> .mat file containing "matrix" variable with the FA DTI adjacency of a given subject
% useBinaryMatrix  -> replaces all weights by 1 if true
% Theta            -> value of the threshold of the nodes
% tTotal           -> max amount of time steps to run the dynamics
% nSeeds           -> number of seeds to be used
% isCompetitive    -> if true, each seed generates a competing cascade
% seedType         -> 'random': randomly select seeds
%                     'fixed': select fixed seedInd for every trial + a quantity of (nSeeds-numel(seedInd)) seeds in 1:size(A,1);
%                     'mostconn': selects the nSeeds most connected nodes as seeds
% seedInd          -> double(1:nSim,1:nSeeds) index of 'fixed' seeds
%                     if there is less rows than nSim, the remaining rows are a periodic repetition of seedInd(:,:)
%                     if there is less columns than nSeeds, the remaining cols are going to be filled up with random seeds
% outDirName       -> name of the output directory
% outFileType      -> leave it as 'mat'
    if nargin < 10 || isempty(outFileType)
        outFileType = 'mat';
    end
    addpath(['.',filesep,'src']);
    addpath(['.',filesep,'func']);

    disp(['Loading ... ', inputFile ]);
    tmp = load(inputFile);

    if isfield(tmp, 'matrix')
        A = tmp.matrix();
    else
        A = tmp;
    end
    if useBinaryMatrix
        A(A~=0)=1;
    end

    N = size(A,1);
    
    Theta = getTheta(Theta, inputFile, size(A,1));

    disp('Running ... ');
    
    [~,hName] = system('hostname');
    disp(['My HostName is ... ', hName]);

%     if ~isempty(strfind(hName, 'dejerine')) || ~isempty(strfind(hName, 'oberon'))
%         T = NetworkActivationTime_dej_mex(A, Theta, tTotal, nSeeds, isCompetitive, seedType, seedInd);
%     else
        [T,Tw] = NetworkActivationTime_mex(A, Theta, tTotal, nSeeds, isCompetitive, seedType, seedInd);
%     end

    if ~isempty(outDirName)
        outDirName = fixDirName(outDirName);
        if (exist(outDirName, 'dir') ~= 7)
            disp(['Creating directory ... ', outDirName ]);
            mkdir(outDirName);
        end
    end

    outFileName = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'nact_','',outFileType)]);
    if strcmpi(outFileType, 'mat')
        caseName = getCaseName(inputFile);
        header = {'network activation time, T, for given seed combinations, seedInd';...
                  'network activation time in inverse weight units, Tw'};
        theta = Theta;
        disp(['Saving ... ', outFileName]);
        save(outFileName, 'caseName', 'header', 'seedInd', 'T', 'Tw', 'N', 'theta', '-v7.3');
    else
        writeOutputFile(outFileName,  '# network activation time for the given seed combinations', '');
        writeOutputFile(outFileName, ['#',sprintf('s%d  ',1:size(seedInd,2)),'T'], '', true);
        writeOutputFile(outFileName, '', [ seedInd, T ], true);
    end
end
