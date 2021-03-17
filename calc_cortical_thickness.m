function [s,ss,patientTableFile] = calc_cortical_thickness(saveOutput,inputDir,outputDir,patientTableFile)
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 1) || isempty(saveOutput)
        saveOutput = true; % 0 -> does not save; 1 -> saves all cases output
    end
    if (nargin < 2) || isempty(inputDir)
        inputDir = fullfile(dataDir,'thickness_hipvol','thickness_txt');
    end
    if (nargin < 3) || isempty(outputDir)
        outputDir = dataDir;
    end
    if (nargin < 4) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    addpath func

    [~,~,~,aal] = aalsurfview(zeros(90,1));

    cdb = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData containing a table of patients that Neda gave me

    c = dir(fullfile(inputDir,'*'));
    c(~[c(:).isdir]) = [];
    c(strcmpi({c(:).name},'.') | strcmpi({c(:).name},'..')) = [];
    s.header = { 'CT', 'average cortical thickness for each subject';...
                 'CT_L', 'average cortical thickness for L hem for each subject';...
                 'CT_R', 'average cortical thickness for L hem for each subject';...
                 'CT_node', 'average cortical thickness for each AAL node for each subject'};
	s.N90 = struct('raw', [], 'flip', [], 'zToControls', []);
    s.N306 = struct('raw', [], 'flip', [], 'zToControls', []);
    s.N90.raw = struct('caseName', [], 'CT', [], 'CT_L', [], 'CT_R', [], 'CT_node', []);
    s.N306.raw = struct('caseName', [], 'CT', [], 'CT_L', [], 'CT_R', [], 'CT_node', []);

    for i = 1:numel(c)
        disp(['Processing ... ',c(i).name])
        if ~c(i).isdir
            continue;
        end
        [CT_L_surf,CT_R_surf] = getCaseCTFileContent(fullfile(c(i).folder,c(i).name));
        if any([ isempty(CT_L_surf), isempty(CT_R_surf) ])
            continue;
        end

        [CT,CT_L,CT_R,CT_node] = processCaseCT(CT_L_surf,CT_R_surf,aal.map.AAL90,90);
        s.N90.raw.caseName{i} = c(i).name;
        s.N90.raw.CT(i) = CT;
        s.N90.raw.CT_L(i) = CT_L;
        s.N90.raw.CT_R(i) = CT_R;
        s.N90.raw.CT_node{i} = CT_node;

        [CT,CT_L,CT_R,CT_node] = processCaseCT(CT_L_surf,CT_R_surf,aal.map.AAL306,306);
        s.N306.raw.caseName{i} = c(i).name;
        s.N306.raw.CT(i) = CT;
        s.N306.raw.CT_L(i) = CT_L;
        s.N306.raw.CT_R(i) = CT_R;
        s.N306.raw.CT_node{i} = CT_node;
    end
    ie = find(cellfun(@isempty,s.N90.raw.caseName));
    s.N90.raw.caseName(ie) = [];
    s.N90.raw.CT(ie) = [];
    s.N90.raw.CT_L(ie) = [];
    s.N90.raw.CT_R(ie) = [];
    s.N90.raw.CT_node(ie) = [];
    s.N306.raw.caseName(ie) = [];
    s.N306.raw.CT(ie) = [];
    s.N306.raw.CT_L(ie) = [];
    s.N306.raw.CT_R(ie) = [];
    s.N306.raw.CT_node(ie) = [];
    s.N90.raw.CT = s.N90.raw.CT(:);
    s.N90.raw.CT_L = s.N90.raw.CT_L(:);
    s.N90.raw.CT_R = s.N90.raw.CT_R(:);
    s.N306.raw.CT = s.N306.raw.CT(:);
    s.N306.raw.CT_L = s.N306.raw.CT_L(:);
    s.N306.raw.CT_R = s.N306.raw.CT_R(:);

    s.N90.zToControls = s.N90.raw;
    s.N306.zToControls = s.N306.raw;

    [~,cInd] = getPatientControlInd(s.N90.raw.caseName,cdb);
    
    if isempty(cInd)
        warning('no controls were found in the cortical thickness input directory')
    end

    s.N90.zToControls.CT = zScoreToSubset(s.N90.zToControls.CT,cInd);
    s.N90.zToControls.CT_L = zScoreToSubset(s.N90.zToControls.CT_L,cInd);
    s.N90.zToControls.CT_R = zScoreToSubset(s.N90.zToControls.CT_R,cInd);
    s.N90.zToControls.CT_node = reshapeLines(zScoreToSubset(matCell2Mat(s.N90.zToControls.CT_node),cInd),[90,1],'cell');
    s.N306.zToControls.CT = zScoreToSubset(s.N306.zToControls.CT,cInd);
    s.N306.zToControls.CT_L = zScoreToSubset(s.N306.zToControls.CT_L,cInd);
    s.N306.zToControls.CT_R = zScoreToSubset(s.N306.zToControls.CT_R,cInd);
    s.N306.zToControls.CT_node = reshapeLines(zScoreToSubset(matCell2Mat(s.N306.zToControls.CT_node),cInd),[306,1],'cell');
    
    ss = s; % keeping only the selected cases for spreading time simulations
    [~,k] = setdiff(s.N90.raw.caseName,cdb.casesMetaData.Code(cdb.casesMetaData.UseForSpSim==1));
    ss.N90.raw.caseName(k) = [];
    ss.N90.raw.CT(k) = [];
    ss.N90.raw.CT_L(k) = [];
    ss.N90.raw.CT_R(k) = [];
    ss.N90.raw.CT_node(k) = [];
    ss.N90.zToControls.caseName(k) = [];
    ss.N90.zToControls.CT(k) = [];
    ss.N90.zToControls.CT_L(k) = [];
    ss.N90.zToControls.CT_R(k) = [];
    ss.N90.zToControls.CT_node(k) = [];
    ss.N306.raw.caseName(k) = [];
    ss.N306.raw.CT(k) = [];
    ss.N306.raw.CT_L(k) = [];
    ss.N306.raw.CT_R(k) = [];
    ss.N306.raw.CT_node(k) = [];
    ss.N306.zToControls.caseName(k) = [];
    ss.N306.zToControls.CT(k) = [];
    ss.N306.zToControls.CT_L(k) = [];
    ss.N306.zToControls.CT_R(k) = [];
    ss.N306.zToControls.CT_node(k) = [];

    [~,~,cdbToCn] = intersect(ss.N90.raw.caseName,cdb.casesMetaData.Code,'stable');
    k = find(strcmpi(cdb.casesMetaData.Group(cdbToCn),'RTLE')); % getting the RTLE indices to flip
    ss.N90.flip = ss.N90.zToControls;
    ss.N306.flip = ss.N306.zToControls;
    ctRTLE_L = ss.N90.flip.CT_L(k);
    ss.N90.flip.CT_L(k) = ss.N90.flip.CT_R(k);
    ss.N90.flip.CT_R(k) = ctRTLE_L;
    ss.N90.flip.CT_node = flipAALMatrix_rowsPerCols(ss.N90.flip.CT_node, aal, k);
    ctRTLE_L = ss.N306.flip.CT_L(k);
    ss.N306.flip.CT_L(k) = ss.N306.flip.CT_R(k);
    ss.N306.flip.CT_R(k) = ctRTLE_L;
    ss.N306.flip.CT_node = flipAALMatrix_rowsPerCols(ss.N306.flip.CT_node, aal, k);

    if saveOutput
        disp('Saving complete cortical_thickness.mat ...');
        save(fullfile(outputDir,'cortical_thickness.mat'),'-struct','s','-v7.3');
        disp('Saving selected cases cortical_thickness_sel.mat ...');
        save(fullfile(outputDir,'cortical_thickness_sel.mat'),'-struct','ss','-v7.3');
        cdb.ctdata = ss;
        disp(['Replacing patient table file ... ',fullfile(dataDir,patientTableFile)]);
        save(fullfile(dataDir,patientTableFile),'-struct','cdb','-v7.3');
        disp(['Replacing patient table file ... ',fullfile(outputDir,patientTableFile)]);
        save(fullfile(outputDir,patientTableFile),'-struct','cdb','-v7.3');
        patientTableFile = fullfile(outputDir,patientTableFile);
    end
end

function [CT_L,CT_R] = getCaseCTFileContent(caseDir)
    f = dir(fullfile(caseDir,'*.txt'));
    if isempty(f)
        CT_L=[];
        CT_R=[];
        return;
    end
    isLeft = cellfun(@(x)~isempty(x),strfind({f(:).name},'left'));
    kL = find(isLeft); % left file index
    kR = find(~isLeft); % right file index
    CT_L = getFileContent(fullfile(f(kL).folder,f(kL).name),'%f');
    CT_R = getFileContent(fullfile(f(kR).folder,f(kR).name),'%f');
end

function [CT,CT_L,CT_R,CT_node] = processCaseCT(CT_L_s,CT_R_s,aalmap,N)
    n = numel(CT_L_s);
    CT = [CT_L_s;CT_R_s];
    CT(aalmap==0) = NaN;
    CT_L = nanmean(CT(1:n));
    CT_R = nanmean(CT((n+1):end));
    CT_node = calcAvgCTNode(CT,aalmap,N);
    CT = nanmean(CT);
end

function CTn = calcAvgCTNode(CT,map,N)
    %A = numel(find(map~=0));
    u = unique(map);
    if u(1) == 0
        u(1) = [];
    end
    CTn = NaN(N,1);
    for i = 1:numel(u)
        %kk = find(map == u(i));
        CTn(u(i)) = nanmean(CT(map == u(i)));
    end
end

function c = getFileContent(fn,fmt)
    fid = fopen(fn,'r');
    c = textscan(fid,fmt);
    fclose(fid);
    c = cell2mat(c);
end