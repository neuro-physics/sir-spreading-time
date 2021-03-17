function r = calcCommunities(inputAdjMatPathPtrn, ggamma, nTrials, aal_labels, saveMatFile, outputFileName, caseName)
    if (nargin < 4)
        aal_labels = [];
    end
    if (nargin < 5) || isempty(saveMatFile)
        saveMatFile = false;
    end
    if (nargin < 6) || isempty(outputFileName)
        outputFileName = 'comm.mat';
    end
    if (nargin < 7)
        caseName = [];
    end
    Ac = GetConsensusAdjMatrix(inputAdjMatPathPtrn, [], caseName);
    C = cell(size(ggamma));
    for i = 1:numel(ggamma)
        C{i} = GenerateCommunity(Ac, ggamma(i), nTrials);
    end
    r.Ac = Ac;
    r.C = C;
    r.ggamma = ggamma;
    r.aal_labels = aal_labels;
    if saveMatFile
        save(outputFileName, 'Ac', 'C', 'ggamma', 'aal_labels', '-v7.3');
    end
end
