function RunPhaseTransitionSingleMatrix(inputFile, useBinaryMatrix, Theta0, Theta1, nTheta, nSim, tTotal, x0, icType, useWeightSampling, outDirName, outFileType)
% inputFile        -> .mat file containing "matrix" variable with the FA DTI adjacency of a given subject
% useBinaryMatrix  -> replaces all weights by 1 if true
% Theta0           -> initial value of the threshold
% Theta1           -> final value of the threshold
% nTheta           -> amount of theta to simulate between theta0 and theta1
% nSim             -> number of trials for each theta
% tTotal           -> max amount of time steps to run the dynamics
% x0               -> initial state of the nodes of the network
% icType           -> 'fixed': the same node is stimulated for every theta and sim
%                     'mostconn': the same node (most connected) is stimulated for every theta and sim
%                     'random': randomly choose one seed node
%                     'allnodes': runs one simulation for each node
% useWeightSampling -> if true, a new weight sampling is generated for each simulation of each theta (leave it as FALSE to use original subject FA weights)
% outDirName       -> name of the output directory
% outFileType      -> leave it as 'mat'
    if nargin < 12 || isempty(outFileType)
        outFileType = 'mat';
    end
    addpath(['.',filesep,'src']);
    addpath(['.',filesep,'func']);

    disp(['Loading ... ', inputFile ]);
    tmp = load(inputFile);

    A = tmp.matrix();
    if useBinaryMatrix
        A(A~=0)=1;
    end
    N = numel(A(:,1));
    Theta = linspace(Theta0,Theta1,nTheta);
    
    if useWeightSampling
        useWeightSampling = true;
    else
        useWeightSampling = false;
    end
    
    disp('Running ... ');

    [~,hName] = system('hostname');
    disp(['My HostName is ... ', hName]);
    
%     if ~isempty(strfind(hName, 'dejerine')) || ~isempty(strfind(hName, 'oberon'))
%         [nAct, NVarRho, seedInd, nActSeed] = PhaseTransition_dej_mex(A, Theta, nSim, tTotal, repmat(x0,1,N), icType, useWeightSampling);
%     else
        [nAct, NVarRho, seedInd, nActSeed] = PhaseTransition_mex(A, Theta, nSim, tTotal, repmat(x0,1,N), icType, useWeightSampling);
%     end
    rho = nAct ./ N;

    if ~isempty(outDirName)
        outDirName = fixDirName(outDirName);
        if (exist(outDirName, 'dir') ~= 7)
            disp(['Creating directory ... ', outDirName ]);
            mkdir(outDirName);
        end
    end

    outFileName = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'pt_','',outFileType)]);
    if strcmpi(outFileType,'mat')
        caseName = getCaseName(inputFile);
        Theta = Theta(:);
        nAct = nAct(:);
        rho = rho(:);
        NVarRho = NVarRho(:);
        thetaSeed = repmat(Theta,1,size(seedInd,2));
        disp(['Saving ... ', outFileName]);
        save(outFileName, 'caseName', 'Theta', 'nAct', 'rho', 'NVarRho', 'N', 'nSim', 'icType', 'seedInd', 'nActSeed', 'thetaSeed', '-v7.3');
    else
        writeOutputFile(outFileName, ...
            '# theta nAct rho N*Var(rho)', [ Theta(:), nAct(:), rho(:), NVarRho(:) ]);
        outFileName2 = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'pt_','_nActSeed',outFileType)]);
        thetaVal = repmat(Theta(:),1,size(seedInd,2));
        writeOutputFile(outFileName2, ...
            '# Theta seedInd nActSeed', [ thetaVal(:), seedInd(:), nActSeed(:) ]);
    end
    %outFileName = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'pt_')]);
    %disp(['Saving ... ', outFileName ]);
    %dlmwrite(outFileName, '# theta nAct rho N*Var(rho)', 'delimiter', '');
    %dlmwrite(outFileName, [ Theta(:), nAct(:), rho(:), nAct2(:) ], 'delimiter', ' ', 'precision', '%.8f', '-append');
end
