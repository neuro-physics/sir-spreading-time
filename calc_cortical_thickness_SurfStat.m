function [LTLE,RTLE,LRTLE] = calc_cortical_thickness_SurfStat(saveOutput,patientTableFile)
    if (nargin < 1) || isempty(saveOutput)
        saveOutput = false; % 0 -> does not save; 1 -> saves all cases output
    end
    if (nargin < 2) || isempty(patientTableFile)
        patientTableFile = 'TLE_NB_BB.mat';
    end
    addpath func

    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end

    [~,~,~,aal] = aalsurfview(zeros(90,1));
    outDir = fullfile(dataDir,'thickness_hipvol','thickness_txt');

    cdb = load(fullfile(dataDir,patientTableFile)); % inputs variable casesMetaData containing a table of patients that Neda gave me

    c = dir(fullfile(outDir,'*_*'));
    cn = { c(:).name };
    [cn,k,kk] = intersect(cn,cdb.casesMetaData.Code(cdb.casesMetaData.UseForSpSim==1)','stable');
    c = c(k);
    groups = cdb.casesMetaData.Group(cdb.casesMetaData.UseForSpSim==1);
    groups = groups(kk);
    [cn,k] = sort(cn);
    cn = cn(:);
    c = c(k);
    groups = groups(k);
    groups_flip = strrep(strrep(groups,'LTLE','TLE'),'RTLE','TLE');
    [~,controlInd] = getPatientControlInd(cn);

    nC = numel(c);
    nV = numel(aal.map.AAL90);
    CT = zeros(nC,nV);
    for i = 1:nC
        CT(i,:) = getCaseCTFileContent(fullfile(c(i).folder,c(i).name));
    end

    LTLE = createCTStruct(CT,cn,controlInd,groups,groups_flip,aal,'LTLE');
    RTLE = createCTStruct(CT,cn,controlInd,groups,groups_flip,aal,'RTLE');
    LRTLE = createCTStruct(CT,cn,controlInd,groups,groups_flip,aal,'TLE');

    if saveOutput
        disp('Saving selected cases cortical_thickness_sel.mat ...');
        save(fullfile(outDir,'cortical_thickness_sel_surfstat.mat'),'LTLE','RTLE','LRTLE','-v7.3');
    end
end

function ss = createCTStruct(CT,cn,controlInd,groups,groups_flip,aal,groupName)
    ss = struct('N90',[],'N306',[]);
    ss.N90 = struct('raw',[],'flip',[],'zToControls',[]);
    ss.N306 = struct('raw',[],'flip',[],'zToControls',[]);

    ss.N90.raw = processCortThick(CT,cn,groups,aal,90,groupName);
    ss.N90.zToControls = processCortThick(zScoreToSubset(CT,controlInd),cn,groups,aal,90,groupName);
    ss.N90.flip = processCortThick(flipCT(zScoreToSubset(CT,controlInd)),cn,groups_flip,aal,90,groupName);

    ss.N306.raw = processCortThick(CT,cn,groups,aal,306,groupName);
    ss.N306.zToControls = processCortThick(zScoreToSubset(CT,controlInd),cn,groups,aal,306,groupName);
    ss.N306.flip = processCortThick(flipCT(zScoreToSubset(CT,controlInd)),cn,groups_flip,aal,306,groupName);

    ss.N90.raw.caseName = cn;
    ss.N90.flip.caseName = cn;
    ss.N90.zToControls.caseName = cn;
    ss.N306.raw.caseName = cn;
    ss.N306.flip.caseName = cn;
    ss.N306.zToControls.caseName = cn;
end

function s = processCortThick(CT,cn,groups,aal,N,groupName)
    % load(fullfile(dataDir,'cortical_thickness_sel_raw.mat'))
    G = termSurfStat(groups);
    M = 1 + G;
    s = SurfStatLinMod(CT,M,aal.surf);
    s = SurfStatT(s,G.NC-G.(groupName));
end

function CT = getCaseCTFileContent(caseDir)
    f = dir(fullfile(caseDir,'TLE*.txt'));
    if isempty(f)
        CT=[];
        return;
    end
    isLeft = cellfun(@(x)~isempty(x),strfind({f(:).name},'left'));
    kL = find(isLeft); % left file index
    kR = find(~isLeft); % right file index
    CT_L = getFileContent(fullfile(f(kL).folder,f(kL).name),'%f');
    CT_R = getFileContent(fullfile(f(kR).folder,f(kR).name),'%f');
    CT = [ CT_L(:)', CT_R(:)' ];
end

function CT = flipCT(CT)
    n = floor(size(CT,2) / 2);
    CT = CT(:,[(n+1):end,1:n]); % fliping L-R vertices
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