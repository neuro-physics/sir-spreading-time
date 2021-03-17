function d = calcNetworkProperties(inp,outputFileName,nPermRichClub,nBinsWeightDist,caseNameInp,labels,flipRTLE,cdb)
    if (nargin < 2) || isempty(outputFileName)
        outputFileName = '';
    end
    if (nargin < 3) || isempty(nPermRichClub)
        nPermRichClub = 100;
    end
    if (nargin < 4) || isempty(nBinsWeightDist)
        nBinsWeightDist = 50;
    end
    if (nargin < 5) || isempty(caseNameInp)
        caseNameInp = [];
    end
    if (nargin < 6) || isempty(labels)
        labels = {};
    end
    if (nargin < 7) || isempty(flipRTLE)
        flipRTLE = false;
    end
    if (nargin < 8) || isempty(cdb)
        if flipRTLE
            dataDir = 'D:\Dropbox\p\postdoc\data';
            if isunix
                dataDir = '/host/scarus/local_raid/mauricio/data';
            end
            cdb = load(fullfile(dataDir,'TLE_NB_BB.mat')); % inputs variable casesMetaData containing a table of patients that Neda gave me
        end
    end

    if ischar(inp)
        [A,caseName,~] = loadAALMatrix(inp);
    else
        if ~iscell(inp)
            error('inp must be a directory containing mat files or a cell of adjacency matrices')
        end
        if isempty(caseNameInp)
            error('if inp is a cell of matrices, you must provide a cell of case numbers as the 5th argument')
        end
        A = inp;
        caseName = caseNameInp;
    end

    if iscell(A)
        N = size(A{1},1);
    else
        N = size(A,1);
    end
    d.A = A;
    d.caseName = caseName;
    d.density = network.calcNetworkDensity(A,'individual');
    d.shortestPathBin = network.calcShortestPath_adj(A,true);
    d.shortestPathWei = network.calcShortestPath_adj(A,false);
    [d.Pw,d.wEdges] = network.calcWeightDistribution(A,nBinsWeightDist,'individual');
    [d.Pw_mean,d.wEdges_mean] = network.calcWeightDistribution(A,nBinsWeightDist,'single');
    d.clusterCoeffBin = network.calcClusteringCoeff(A,true);
    d.clusterCoeffWei = network.calcClusteringCoeff(A,false);
    [~, d.inDegree] = network.calcNodeDegree(A,'in', 'degree','binary');
    [~,d.outDegree] = network.calcNodeDegree(A,'out','degree','binary');
    [~, d.inDegreeWei] = network.calcNodeDegree(A,'in', 'degree','weighted');
    [~,d.outDegreeWei] = network.calcNodeDegree(A,'out','degree','weighted');
    d.betweenCenBin = network.calcBetweennessCentrality(A,true);
    d.betweenCenWei = network.calcBetweennessCentrality(A,false);
    [d.Pk_in_mean,d.kEdges_in_mean] = network.calcNodeDegree(A,'in','distribution');
    [d.Pk_out_mean,d.kEdges_out_mean] = network.calcNodeDegree(A,'in','distribution');
    
    %d.richClub = network.getRichClubNodes(A,nPermRichClub);
    d.richClub = struct('header',[],'C',[],'rcIndNorm',[],'rcCurve',[],'numMatrixPerm',[],'rcNodes',[],'rcNodes2',[],'feederNodes',[],'localNodes',[]);
    d.richClub.header = { 'rich club is calculated for C, and normalized over numMatrixPerm permutations of C that preserve degree and connectedness';...
                          'C -> consensus matrix of all A [ only for this group; calculated by func.GetConsensusAdjMatrix(A) ]';...
                          'rcNodes  -> nodes of C that have degree equal to the level of maximum rcIndNorm';...
                          'rcNodes2 -> nodes of C that have degree equal to the level of the second maximum of rcIndNorm';...
                          'feederNodes -> nodes that have at least one edge coming or going to a rcNode or rcNode2';...
                          'localNodes  -> nodes that have no edges coming or going to a rcNode or a rcNode2'};
	d.richClub.C = GetConsensusAdjMatrix(A);
    [d.richClub.rcNodes,d.richClub.rcNodes2,d.richClub.rcIndNorm,d.richClub.rcCurve,d.richClub.feederNodes,d.richClub.localNodes] = network.getRichClubNodes(d.richClub.C,nPermRichClub);
    
    if ~isempty(labels)
        d.nodeLabel = labels;
    end

    d.Pw = reshapeLines(d.Pw', [nBinsWeightDist,1], 'cell');
    d.wEdges = reshapeLines(d.wEdges', [nBinsWeightDist,1], 'cell');
    d.clusterCoeffWei = reshapeLines(d.clusterCoeffWei', [N,1], 'cell');
    d.clusterCoeffBin = reshapeLines(d.clusterCoeffBin', [N,1], 'cell');
    d.inDegree = reshapeLines(d.inDegree', [N,1], 'cell');
    d.outDegree = reshapeLines(d.outDegree', [N,1], 'cell');
    d.inDegreeWei = reshapeLines(d.inDegreeWei', [N,1], 'cell');
    d.outDegreeWei = reshapeLines(d.outDegreeWei', [N,1], 'cell');
    d.betweenCenBin = reshapeLines(d.betweenCenBin', [N,1], 'cell');
    d.betweenCenWei = reshapeLines(d.betweenCenWei', [N,1], 'cell');

    if flipRTLE
        [~,rInd] = intersect(caseName,cdb.casesMetaData.Code(strcmpi(cdb.casesMetaData.Group,'RTLE')),'stable'); % indices of the selected cases in the order of caseName for RTLEs
        d = flip_struct(d,rInd,N);
    end

    if ~isempty(outputFileName)
        save(outputFileName,'-struct','d','-v7.3');
    end
end