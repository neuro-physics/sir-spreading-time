function RunTwoSeedsSpreading(inputFile, useBinaryMatrix, Theta, tTotal, isCompetitive, outDirName, outFileType, saveTwoToOneSpTimeMatrix)
% inputFile        -> .mat file containing "matrix" variable with the FA DTI adjacency of a given subject
% useBinaryMatrix  -> replaces all weights by 1 if true
% Theta            -> value of the threshold of the nodes
% tTotal           -> max amount of time steps to run the dynamics
% isCompetitive    -> if true, each seed generates a competing cascade
% outDirName       -> name of the output directory
% outFileType      -> leave it as 'mat'
% saveTwoToOneSpTimeMatrix -> if true, saves Tn and Twn matrices, which are 3d arrays meaning the sp time from 2 seeds to every other seed in the network
%                             set to false to save memory in disk
    if nargin < 7 || isempty(outFileType)
        outFileType = 'mat';
    end
    if (nargin < 8) || isempty(saveTwoToOneSpTimeMatrix)
        saveTwoToOneSpTimeMatrix = false;
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
    
    Theta = getTheta(Theta, inputFile, size(A,1));

    disp('Running ... ');
    
    [~,hName] = system('hostname');
    disp(['My HostName is ... ', hName]);

%     if ~isempty(strfind(hName, 'dejerine')) || ~isempty(strfind(hName, 'oberon'))
%         [Cp1,Cp2,H,Cf,T,Tn] = TwoSeedsSpreading_dej_mex(A, Theta, tTotal, isCompetitive);
%     else
        [Cp1,Cp2,H,Cf,T,Tn,Tw,Twn] = TwoSeedsSpreading_mex(A, Theta, tTotal, isCompetitive);
%     end

    if ~isempty(outDirName)
        outDirName = fixDirName(outDirName);
        if (exist(outDirName, 'dir') ~= 7)
            disp(['Creating directory ... ', outDirName ]);
            mkdir(outDirName);
        end
    end

    if ~saveTwoToOneSpTimeMatrix
        Tn = [];
        Twn = [];
    end

    outFileName = CheckAndGetFileName([outDirName,GetOutputFileName(inputFile,'2s_','',outFileType)]);
    if strcmpi(outFileType, 'mat')
        caseName = getCaseName(inputFile);
        N = size(A,1);
        header = { { 'Cp1', 'avalanche size of state 1 (eq Cp2'') for each pair of seeds' };...
                   { 'Cp2', 'avalanche size of state 2 (eq Cp1'') for each pair of seeds' };...
                   { 'H', 'average entropy of each node' };...
                   { 'Cf', 'average conformity of each node' };...
                   { 'T', 'network activation time for each pair of seeds' };...
                   { 'Tn', 'node activation time for each pair of seeds' };...
                   { 'Tw', 'node activation time (inverse weight units) for each pair of seeds' };...
                   { 'Twn', 'node activation time (inverse weight units) for each pair of seeds' } };
        disp(['Saving ... ', outFileName]);
        save(outFileName, 'caseName', 'N', 'header', 'isCompetitive', 'Cp1', 'Cp2', 'H', 'Cf', 'T', 'Tn', 'Tw', 'Twn', '-v7.3');
    else
        outFileHeader = '# avalanche size of state 1 (eq Cp2'') for each pair of seeds';
        writeOutputFile(outFileName, outFileHeader, Cp1);
        
        writeOutputFile(outFileName, ' ', '', true);writeOutputFile(outFileName, ' ', '', true);
        outFileHeader = '# avalanche size of state 2 (eq Cp1'') for each pair of seeds';
        writeOutputFile(outFileName, outFileHeader, Cp2, true);
        
        writeOutputFile(outFileName, ' ', '', true);writeOutputFile(outFileName, ' ', '', true);
        outFileHeader = '# average entropy of each node';
        writeOutputFile(outFileName, outFileHeader, H, true);
        
        writeOutputFile(outFileName, ' ', '', true);writeOutputFile(outFileName, ' ', '', true);
        outFileHeader = '# average conformity of each node';
        writeOutputFile(outFileName, outFileHeader, Cf, true);
        
        writeOutputFile(outFileName, ' ', '', true);writeOutputFile(outFileName, ' ', '', true);
        outFileHeader = '# network activation time for each pair of seeds';
        writeOutputFile(outFileName, outFileHeader, T, true);
   
        if saveTwoToOneSpTimeMatrix
            writeOutputFile(outFileName, ' ', '', true);writeOutputFile(outFileName, ' ', '', true);
            outFileHeader = '# node activation time for each pair of seeds';
            writeOutputFile(outFileName, outFileHeader, Tn, true);
        end
    end
end
