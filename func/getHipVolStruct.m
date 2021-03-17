function hv = getHipVolStruct(cdb, cnOrder, keepVol)
    if (nargin < 3) || isempty(keepVol)
        keepVol = 'ipsi'; % 'ipsi' or 'contra'
    end
    hvt = struct('caseName',[],'Group',[],'HipVol',[],'HipVol_flip',[],'HipVol_Z',[],'excludedInd',[]);
    selCases = cdb.casesMetaData.UseForSpSim==1;
    hvt.caseName = cdb.casesMetaData.Code(selCases);
    hvt.HipVol = cdb.casesMetaData.HipVol(selCases,:);
    hvt.Group = cdb.casesMetaData.Group(selCases);
    [~,k] = setdiff(hvt.caseName,cnOrder);
    hvt.caseName(k) = []; % removing cases that are not in the main data
    hvt.HipVol(k,:) = [];
    hvt.Group(k) = [];
    hvt = sortFieldsContents(hvt, cnOrder); % sorting fields according to main data file
    hvt.excludedInd = find( any(isnan( hvt.HipVol ),2) ); % searching the cases which have no hippocampus volume data
    hvt.caseName = reshape(hvt.caseName,1,[]);
    %hvt.caseName(hvt.excludedInd) = []; hvt.HipVol(hvt.excludedInd,:) = []; hvt.Group(hvt.excludedInd) = [];
    [~,cInd] = getPatientControlInd(hvt.caseName);
    hvt.HipVol_Z = zScoreToSubset(hvt.HipVol, cInd);
    
    if strcmpi(keepVol,'ipsi')
        i1 = 1;
        i2 = 2;
    elseif strcmpi(keepVol,'contra')
        i1 = 2;
        i2 = 1;
    else
        error('getHipVolStruct:keepVol','must be either ipsi or contra');
    end
    k = strcmpi(hvt.Group,'RTLE'); % getting the RTLE indices to keep only the ipsi-lateral Hippocampus
    hvt.HipVol_flip = hvt.HipVol_Z;
    %hvRTLE_L = hvt.HipVol_flip(k,1); % saving the L hip vol in a new variable
    hvt.HipVol(k,i1) = hvt.HipVol(k,i2);
    hvt.HipVol_flip(k,i1) = hvt.HipVol_flip(k,i2); % saving the R hip vol onto the old L hip vol for RTLE
    hvt.HipVol_Z(k,i1) = hvt.HipVol_Z(k,i2);
    hvt.HipVol(:,i2) = [];
    hvt.HipVol_flip(:,i2) = [];
    hvt.HipVol_Z(:,i2) = [];
    %hvt.HipVol_flip(k,2) = hvRTLE_L; % setting the new R Hip Vol of RTLE to the old L hip vol of RTLE
    hv = struct('raw',[],'flip',[],'zToControls',[]);
    hv.raw = hvt;
    hv.flip = hvt;
    hv.zToControls = hvt;
    hv.raw = rmfield(hv.raw, {'Group', 'HipVol_flip', 'HipVol_Z'});
    hv.flip.HipVol = hv.flip.HipVol_flip;
    hv.flip = rmfield(hv.flip, {'Group', 'HipVol_flip', 'HipVol_Z'});
    hv.zToControls.HipVol = hv.zToControls.HipVol_Z;
    hv.zToControls = rmfield(hv.zToControls, {'Group', 'HipVol_flip', 'HipVol_Z'});

    [pInd,cInd] = getPatientControlInd(cnOrder);
    hv = groupHipVol(hv,cInd,pInd);
end

function hvv = groupHipVol(hv,cInd,pInd)
    hvv = hv;
    hvv.excludedInd = hv.raw.excludedInd;
    cIndHV = setdiff(cInd,hv.raw.excludedInd);
    pIndHV = setdiff(pInd,hv.raw.excludedInd);
    hvv.raw.cData.HV = hv.raw.HipVol(cIndHV);
    hvv.raw.pData.HV = hv.raw.HipVol(pIndHV);
    hvv.raw = rmfield(hvv.raw, {'caseName','HipVol','excludedInd'}); % I won't use CT_L or CT_R alone for now

    cIndHV = setdiff(cInd,hv.flip.excludedInd);
    pIndHV = setdiff(pInd,hv.flip.excludedInd);
    hvv.flip.cData.HV = hv.flip.HipVol(cIndHV);
    hvv.flip.pData.HV = hv.flip.HipVol(pIndHV);
    hvv.flip = rmfield(hvv.flip, {'caseName','HipVol','excludedInd'}); % I won't use CT_L or CT_R alone for now
    
    cIndHV = setdiff(cInd,hv.zToControls.excludedInd);
    pIndHV = setdiff(pInd,hv.zToControls.excludedInd);
    hvv.zToControls.cData.HV = hv.zToControls.HipVol(cIndHV);
    hvv.zToControls.pData.HV = hv.zToControls.HipVol(pIndHV);
    hvv.zToControls = rmfield(hvv.zToControls, {'caseName','HipVol','excludedInd'}); % I won't use CT_L or CT_R alone for now
end