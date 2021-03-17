function RunSpreadingTimeSingleMatrix(inputFile, useBinaryMatrix, Theta, nSim, tTotal, outDirName, outFileType)
% inputFile        -> .mat file containing "matrix" variable with the FA DTI adjacency of a given subject
% useBinaryMatrix  -> replaces all weights by 1 if true
% Theta            -> value of the threshold of the nodes
% nSim             -> number of trials for each theta
% tTotal           -> max amount of time steps to run the dynamics
% outDirName       -> name of the output directory
% outFileType      -> leave it as 'mat'
    if nargin < 7 || isempty(outFileType)
        outFileType = 'mat';
    end
    addpath(['.',filesep,'src']);
    addpath(['.',filesep,'func']);

    disp(['Loading ... ', inputFile ]);
    tmp = load(inputFile);
    
    if isfield(tmp, 'matrix')
        A = tmp.matrix;
    else
        A = tmp;
    end
    if useBinaryMatrix
        A(A~=0)=1;
    end
    
    Theta = getTheta(Theta, inputFile, size(A,1));
    
    disp('Running ... ');
    
    [~,hName] = system('hostname');
    disp(['My HostName is ... ', hName]);

%     if ~isempty(strfind(hName, 'dejerine')) || ~isempty(strfind(hName, 'oberon'))
%         [T, V] = SpreadingTime_dej_mex(A, Theta, nSim, tTotal);
%     else
        [T, V, Tw] = SpreadingTime_mex(A, Theta, nSim, tTotal);
%     end

    if ~isempty(outDirName)
        outDirName = fixDirName(outDirName);
        if (exist(outDirName, 'dir') ~= 7)
            disp(['Creating directory ... ', outDirName ]);
            mkdir(outDirName);
        end
    end

    outFileName = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'1s_avg_','',outFileType)]);
    if strcmpi(outFileType, 'mat')
        caseName = getCaseName(inputFile);
        N = size(A,1);
        theta = Theta;
        header = {'spreading time from node to node, T, and variance of T, V, for many nSim simulations';...
                  'spreading time (in inverse weight units) from node to node, Tw'};
        disp(['Saving ... ', outFileName]);
        save(outFileName, 'caseName', 'N', 'header', 'T', 'V', 'Tw', 'nSim', 'theta', '-v7.3');
    else
        writeOutputFile(outFileName, ...
            '# 1 seed average spreading time matrix', T);
        writeOutputFile(CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'1s_var_')]), ...
            '# 1 seed variance spreading time matrix', V);
    end
end
