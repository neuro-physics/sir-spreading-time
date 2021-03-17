function d = calcNetworkPropertiesGroups(inp,outputFileName,groupSide,useFieldName,nPermRichClub,nBinsWeightDist,labels,flipRTLE,zScoreToControls,patientTableFile,patientHipPath)
    if (nargin < 2) || isempty(outputFileName)
        outputFileName = '';
    end
    if (nargin < 3) || isempty(groupSide)
        groupSide = 'All';
    end
    if (nargin < 4) || isempty(useFieldName)
        useFieldName = 'UseForSpSim';
    end
    if (nargin < 5) || isempty(nPermRichClub)
        nPermRichClub = [];
    end
    if (nargin < 6) || isempty(nBinsWeightDist)
        nBinsWeightDist = [];
    end
    if (nargin < 7) || isempty(labels)
        labels = [];
    end
    if (nargin < 8) || isempty(flipRTLE)
        if ischar(groupSide) && strcmpi(groupSide,'All')
            flipRTLE = false;
        else
            flipRTLE = false(1,numel(groupSide));
        end
    end
    if (nargin < 9) || isempty(zScoreToControls)
        if ischar(groupSide) && strcmpi(groupSide,'All')
            zScoreToControls = false;
        else
            zScoreToControls = false(1,numel(groupSide));
        end
    end
    if (nargin < 10) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    if (nargin < 11)
        patientHipPath = 'HS';
    end

    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    cdb = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData containing a table of patients that Neda gave me

    if ~iscell(groupSide)
        groupSide = { groupSide };
    end
    flipRTLE = logical(repeatToComplete(flipRTLE,numel(groupSide)));
    zScoreToControls = logical(repeatToComplete(zScoreToControls,numel(groupSide)));

    [A,caseName] = loadAALMatrix(inp);

    groupNames = getGroupName_cell(groupSide);
    d = cell2struct(cell(size(groupNames)), groupNames, 2);
    if numel(flipRTLE) ~= numel(groupNames)
        flipRTLE = repeatToComplete(flipRTLE,numel(groupNames));
    end

    for i = 1:numel(groupNames)
        g = groupNames{i};

        k = getGroupIndices(caseName,groupSide{i},useFieldName,cdb,patientHipPath);

        d.(g) = network.calcNetworkProperties(A(k),'',nPermRichClub,nBinsWeightDist,caseName(k),[],flipRTLE(i),cdb);
    end
    if any(zScoreToControls)
        for i = 1:numel(groupNames)
            g = groupNames{i};
            if zScoreToControls(i)
                d.(g) = zScoreFieldsToControls(d.(g),d.Controls,numel(d.(g).A),numel(d.Controls.A),{'density','shortestPathBin','shortestPathWei','clusterCoeffBin','clusterCoeffWei','inDegree','outDegree','inDegreeWei','outDegreeWei','betweenCenBin','betweenCenWei'});
            end
        end
    end

    d.nodeLabel = labels;
    d.flipRTLE = groupNames(flipRTLE);

    d.richClub = struct('header',[],'C',[],'rcIndNorm',[],'rcCurve',[],'numMatrixPerm',[],'rcNodes',[],'rcNodes2',[],'feederNodes',[],'localNodes',[]);
    d.richClub.header = { 'rich club is calculated for C, and normalized over numMatrixPerm permutations of C that preserve degree and connectedness';...
                          'C -> consensus matrix of all A [ of all groups together; calculated by func.GetConsensusAdjMatrix(A) ]';...
                          'rcNodes  -> nodes of C that have degree equal to the level of maximum rcIndNorm';...
                          'rcNodes2 -> nodes of C that have degree equal to the level of the second maximum of rcIndNorm';...
                          'feederNodes -> nodes that have at least one edge coming or going to a rcNode or rcNode2';...
                          'localNodes  -> nodes that have no edges coming or going to a rcNode or a rcNode2'};
	d.richClub.C = GetConsensusAdjMatrix(A);
    [d.richClub.rcNodes,d.richClub.rcNodes2,d.richClub.rcIndNorm,d.richClub.rcCurve,d.richClub.feederNodes,d.richClub.localNodes] = network.getRichClubNodes(d.richClub.C,nPermRichClub);

    if ~isempty(outputFileName)
        save(outputFileName, '-struct', 'd', '-v7.3');
    end
end

function k = getGroupIndices(caseName,sd,useFieldName,cdb,patientHipPath)
    if strcmpi(sd,'All')
        k = (1:numel(caseName))';
        return;
    end
    [kP,kC,~,~] = getCasesIndices(caseName,cdb.casesMetaData,sd,patientHipPath,1,useFieldName);
    if ischar(sd)
        if strcmpi(sd,'nc') || strcmpi(sd,'control') || strcmpi(sd,'controls') % controls are tagged NC
            k = kC;
        else
            k = kP;
        end
    else
        k = kP;
    end
end

function n = getGroupName_cell(gs)
    n = cell(size(gs));
    for i = 1:numel(gs)
        n{i} = getGroupName(gs{i});
    end
end

function n = getGroupName(gs)
    if ischar(gs)
        if strcmpi(gs,'nc')
            n = 'Controls';
            return;
        end
        n = gs;
        return;
    end
    n = [getGroupSideChar(gs),'TLE'];
end

function c = getGroupSideChar(sd)
    c = sort(strjoin(strrep(sd,'TLE',''),''));
end
