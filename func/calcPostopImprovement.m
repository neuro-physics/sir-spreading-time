function p = calcPostopImprovement(s,caseName,cdb,preopGroup,postopExpGroup,postopTeorGroup,fiberLengthDir)
% s -> SpMatrix or SpMatrixW struct generated by parseSpreadingData
% caseName -> sim_data struct caseName corresponding to the order of cases in SpMatrix(W) struct
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 3) || isempty(cdb)
        cdb = load(fullfile(dataDir,'FCD_table.mat')); % inputs variable casesMetaData containing a table of patients that Neda gave me
    end
    if (nargin < 4) || isempty(preopGroup)
        preopGroup = 'FCD_PREOP';
    end
    if (nargin < 5) || isempty(postopExpGroup)
        postopExpGroup = 'FCD_POSTOP';
    end
    if (nargin < 6) || isempty(postopTeorGroup)
        postopTeorGroup = 'FCD_POSTOPSIM';
    end
    if (nargin < 7) || isempty(fiberLengthDir)
        fiberLengthDir = fullfile(dataDir,'fcd','fiber_length');
    end
    
    % getting aal struct
    [~,~,~,aal] = aalsurfview(zeros(90,1));
    
    % setting the order of cases in cdb.casesMetaData struct to match variable caseName
    cdb.casesMetaData = sortFieldsContents(cdb.casesMetaData,caseName,'Code'); % this line will only work if numel(caseName) equals to numel of cdb.casesMetaData fields
    
    % getting group indices
    [cInd,preInd,postInd,postsimInd] = getCorrespGroupInd(caseName,cdb,preopGroup);
    
    % copying some values in casesMetaData table
    cdb.casesMetaData = copyStructFieldValue(cdb.casesMetaData,{'RemAALParcels','ParcelPercentRem','ParcelVolRem','ParcelTotalVol'},postsimInd,postInd);
    cdb.casesMetaData = copyStructFieldValue(cdb.casesMetaData,{'RemAALParcels','ParcelPercentRem','ParcelVolRem','ParcelTotalVol'},postsimInd,preInd);
    
    N = s(1).N;
    nC = numel(caseName);

    if ~isempty(fiberLengthDir)
        [LL,cnL] = loadAALMatrix(fullfile(fiberLengthDir,'*FL*midres*.mat')); % loads FL
        L = cell(1,nC);
        if ~isempty(LL)
            ci = ~cellfun(@isempty,regexp(cnL,'^3\d{2}_\d$'));
            pp = ~cellfun(@isempty,regexp(cnL,'(_|^)postop(\d|$)'));
            ps = ~cellfun(@isempty,regexp(cnL,'(_|^)postopsim(\d|$)'));
            pr = ~(pp | ps);
            [~, k, ~] = intersect(caseName,cnL(pp),'stable'); % indices of caseName that correspond to the postop in cnL
            L(k) = LL(pp);
            [~, k, ~] = intersect(caseName,cnL(ps),'stable'); % indices of caseName that correspond to the postopsim in cnL
            L(k) = LL(ps);
            [~, k, ~] = intersect(caseName,cnL(pr),'stable'); % indices of caseName that correspond to the preop in cnL
            L(k) = LL(pr);
            [~, k, ~] = intersect(caseName,cnL(ci),'stable'); % indices of caseName that correspond to the controls in cnL
            L(k) = LL(ci);
            %[~,k] = setdiff(caseName,cnL,'stable');
            %L(k) = repmat({eye(N)},size(k)); % controls
            LL=[];
        end
    end
    
    %fcd_caseName = getFCDCaseName(caseName,cdb);

    nT = numel(s);
    p = s;
    for i = 1:nT
        p(i).header = { 'Kt_std' , 'theoretical improvement coefficient (from computational surgery) of case c: Kteor_c = STD_c(Zteor_postsim)/STD_c(Z_pre) -- Z is the z-score to controls spreading time mat'; ...
                        'Ke_std' , 'experimental improvement coefficient (from a    ctual surgery) of case c: Kexp_c = STD_c(Zexp_post)/STD_c(Z_pre) -- Z is the z-score to controls spreading time mat'; ...
                        'Zdr_in_all', 'Z-score to controls of in sp times (to all nodes) as a function of the radial distance to the center of the lesion (going into the lesion) for each subject'; ...
                        'Zdl_in_all', 'Z-score to controls of in sp times (to all nodes) as a function of the mean fiber-length distance of any node to the lesion (going into the lesion) for each subject'; ...
                        'Zdr_out_all', 'Z-score to controls of out sp times (from all nodes) as a function of the radial distance to the center of the lesion (going out of the lesion) for each subject'; ...
                        'Zdl_out_all', 'Z-score to controls of out sp times (from all nodes) as a function of the mean fiber-length distance of any node to the lesion (going out of the lesion for each subject)'; ...
                        'Zdr_in_res', 'Z-score to controls of in sp times (to resected nodes) as a function of the radial distance to the center of the lesion (going into the lesion) for each subject'; ...
                        'Zdl_in_res', 'Z-score to controls of in sp times (to resected nodes) as a function of the mean fiber-length distance of any node to the lesion (going into the lesion) for each subject'; ...
                        'Zdr_out_res', 'Z-score to controls of out (from resected nodes) sp times as a function of the radial distance to the center of the lesion (going out of the lesion) for each subject'; ...
                        'Zdl_out_res', 'Z-score to controls of out (from resected nodes) sp times as a function of the mean fiber-length distance of any node to the lesion (going out of the lesion for each subject)'; ...
                        'dr_all', 'radial distance to the center of the lesion for each subject'; ...
                        'dl_all', 'mean fiber-length distance to any node of the lesion for each subject'};

        S = s(i).data.SAvg; % sp times z-scored to controls
        S_std = std(matCell2Mat(S),[],2,'omitnan'); % sp times z-scored to controls
        Z = s(i).zControlData.SAvg; % sp times z-scored to controls
        Z_std = std(matCell2Mat(Z),[],2,'omitnan');
        p(i).caseName = cdb.casesMetaData.Code;
        p(i).group = cdb.casesMetaData.Group;
        
        p(i).data = struct('Kt_std', [], 'Ke_std', [], 'Zdr_in_all', [], 'Zdl_in_all', [], 'Zdr_out_all', [], 'Zdl_out_all', [], 'dr_all', [], 'dl_all', []);
        p(i).data.Kt_std = ones(nC,1); % controls have improvement == 1 by definition because they did not go through surgery
        p(i).data.Ke_std = ones(nC,1); % I will try to get some simulated surgery controls to have a better null hypothesis
        p(i).data.Kt_std([preInd;postInd;postsimInd]) = repmat(S_std(postsimInd)./S_std(preInd),3,1);
        p(i).data.Ke_std([preInd;postInd;postsimInd]) = repmat(S_std(postInd)./S_std(preInd),3,1);
        [p(i).data.Zdr_in_res,p(i).data.dr_res] = calcRadialSpTime_all(aal,cdb,S,'in',caseName,true); % consider only to/from resected nodes
        p(i).data.Zdr_out_res = calcRadialSpTime_all(aal,cdb,S,'out',caseName,true); % consider only to/from resected nodes
        [p(i).data.Zdl_in_res,p(i).data.dl_res] = calcLengthSpTime_all(L,cdb,S,'in',caseName,true); % consider only to/from resected nodes
        p(i).data.Zdl_out_res = calcLengthSpTime_all(L,cdb,S,'out',caseName,true); % consider only to/from resected nodes
        [p(i).data.Zdr_in_all,p(i).data.dr_all] = calcRadialSpTime_all(aal,cdb,S,'in',caseName,false); % consider all nodes
        p(i).data.Zdr_out_all = calcRadialSpTime_all(aal,cdb,S,'out',caseName,false); % consider all nodes
        [p(i).data.Zdl_in_all,p(i).data.dl_all] = calcLengthSpTime_all(L,cdb,S,'in',caseName,false); % consider all nodes
        p(i).data.Zdl_out_all = calcLengthSpTime_all(L,cdb,S,'out',caseName,false); % consider all nodes
        
        p(i).flipData = [];
        
        p(i).zControlData = struct('Kt_std', [], 'Ke_std', [], 'Zdr_in_all', [], 'Zdl_in_all', [], 'Zdr_out_all', [], 'Zdl_out_all', [], 'dr_all', [], 'dl_all', []);
        p(i).zControlData.Kt_std = ones(nC,1); % controls have improvement == 1 by definition because they did not go through surgery
        p(i).zControlData.Ke_std = ones(nC,1); % I will try to get some simulated surgery controls to have a better null hypothesis
        p(i).zControlData.Kt_std([preInd;postInd;postsimInd]) = repmat(Z_std(postsimInd)./Z_std(preInd),3,1);
        p(i).zControlData.Ke_std([preInd;postInd;postsimInd]) = repmat(Z_std(postInd)./Z_std(preInd),3,1);
        [p(i).zControlData.Zdr_in_all,p(i).zControlData.dr_all] = calcRadialSpTime_all(aal,cdb,Z,'in',caseName,true); % consider only to/from resected nodes
        p(i).zControlData.Zdr_out_all = calcRadialSpTime_all(aal,cdb,Z,'out',caseName,true); % consider only to/from resected nodes
        [p(i).zControlData.Zdl_in_all,p(i).zControlData.dl_all] = calcLengthSpTime_all(L,cdb,Z,'in',caseName,true); % consider only to/from resected nodes
        p(i).zControlData.Zdl_out_all = calcLengthSpTime_all(L,cdb,Z,'out',caseName,true); % consider only to/from resected nodes
        [p(i).zControlData.Zdr_in_res,p(i).zControlData.dr_res] = calcRadialSpTime_all(aal,cdb,Z,'in',caseName,false); % consider all nodes
        p(i).zControlData.Zdr_out_res = calcRadialSpTime_all(aal,cdb,Z,'out',caseName,false); % consider all nodes
        [p(i).zControlData.Zdl_in_res,p(i).zControlData.dl_res] = calcLengthSpTime_all(L,cdb,Z,'in',caseName,false); % consider all nodes
        p(i).zControlData.Zdl_out_res = calcLengthSpTime_all(L,cdb,Z,'out',caseName,false); % consider all nodes
    end
end

function [SS,dd] = calcRadialSpTime_all(aal,cdb,S,inout,caseName,toResectedNodes)
    if ~iscell(S)
        S = S{1};
    end
    N = size(S{1},1);
    nC = numel(cdb.casesMetaData.Code);
    SS = cell(1,nC);
    dd = cell(1,nC);
    aalLabel = ['AAL',num2str(N)];
    for i = 1:nC
        %[k,k_cdb] = getCaseNameIndFromFCD(fcd_caseName{i},caseName,cdb);
        k = find(strcmpi(caseName,cdb.casesMetaData.Code{i}));
        w = cdb.casesMetaData.ParcelPercentRem{i}';
        r = aal.pos.(aalLabel)(cdb.casesMetaData.RemAALParcels{i},:);
        if toResectedNodes
            seedNodes = cdb.casesMetaData.RemAALParcels{i};
        else
            seedNodes = [];
        end
        [SS{i},dd{i}] = calcRadialSpTime(S{k},calcVolumeCenter(r,w),aal.pos.(aalLabel),inout,seedNodes);
    end
end

function [SS,dd] = calcLengthSpTime_all(L,cdb,S,inout,caseName,toResectedNodes)
    if ~iscell(S)
        S = S{1};
    end
    if ~iscell(L)
        L = L{1};
    end
    nC = numel(cdb.casesMetaData.Code);
    SS = cell(1,nC);
    dd = cell(1,nC);
    for i = 1:nC
        %[k,k_cdb] = getCaseNameIndFromFCD(fcd_caseName{i},caseName,cdb);
        k = find(strcmpi(caseName,cdb.casesMetaData.Code{i}));
        if toResectedNodes
            seedNodes = cdb.casesMetaData.RemAALParcels{i};
        else
            seedNodes = [];
        end
        [SS{i},dd{i}] = calcLengthSpTime(S{k},L{k},inout,seedNodes);
    end
end

function [cInd,preInd,postInd,postsimInd] = getCorrespGroupInd(caseName,cdb,preopGroup)
    [preInd,cInd] = getCasesIndices(caseName, cdb.casesMetaData, preopGroup, [], false, '');
    postInd = zeros(size(preInd));
    postsimInd = zeros(size(preInd));

    for i = 1:numel(preInd)
        cn = getCaseNumber(caseName{preInd(i)});
        postInd(i) = find(   cellfun(@(x,y)~isempty(x) && ~isempty(y),regexp(caseName,'(_|^)postop(\d|$)'),regexp(caseName,['^',cn,'_'],'match'))  );
        postsimInd(i) = find(   cellfun(@(x,y)~isempty(x) && ~isempty(y),regexp(caseName,'(_|^)postopsim(\d|$)'),regexp(caseName,['^',cn,'_'],'match'))  );
    end
end

function c = getCaseNumber(cn)
    if iscell(cn)
        c = cell(size(cn));
        for i = 1:numel(cn)
            c{i} = getCaseNumber(cn{i});
        end
    else
        c = regexp(cn,'^\d+(_|$)','match');
        if iscell(c)
            c = c{1};
        end
        if strcmp(c(end),'_')
            c(end) = [];
        end
    end
end

function fcd_caseName = getFCDCaseName(caseName,cdb)
    [pInd,~] = getPatientControlInd(caseName,cdb,'NC');
    fcd_caseName = [ caseName(pInd), appendStr(unique(getCaseNumber(caseName(pInd)),'stable'),'_con') ];
end

function [k,cdbInd] = getCaseNameIndFromFCD(fcd_cn,caseName,cdb)
% returns the index of caseName corresponding to case identified by fcd_cn
% if fcd_cn is not found in caseName
% it returns all the controls in caseName corresponding to the given fcd case
    k = find(strcmpi(caseName,fcd_cn));
    cdbInd = find(strcmpi(cdb.casesMetaData.Code,fcd_cn));
    if isempty(k)
        [~,k] = getPatientControlInd(caseName,cdb,'NC');
        cdbInd = find(strcmpi(cdb.casesMetaData.Group,['NC_',getCaseNumber(fcd_cn)]));
    end
end