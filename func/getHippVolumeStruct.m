function hv = getHippVolumeStruct(cdb, cnOrder, volumeField, controlGroup, keepVol)
    if ~isfield(cdb.casesMetaData,volumeField)
        hv = [];
        return;
    end
    if (nargin < 5) || isempty(keepVol)
        keepVol = 'ipsi'; % 'ipsi' or 'contra'
    end
    hvt = struct('caseName',[],'Group',[],'Vol',[],'Vol_flip',[],'Vol_Z',[],'excludedInd',[]);
    selCases = cdb.casesMetaData.UseForSpSim==1;
    hvt.caseName = cdb.casesMetaData.Code(selCases);
    hvt.Vol = cdb.casesMetaData.(volumeField)(selCases,:);
    hvt.Vol(hvt.Vol==-666) = 0;
    hvt.Group = cdb.casesMetaData.Group(selCases);
    [~,k] = setdiff(hvt.caseName,cnOrder);
    hvt.caseName(k) = []; % removing cases that are not in the main data
    hvt.Vol(k,:) = [];
    hvt.Group(k) = [];
    hvt = sortFieldsContents(hvt, cnOrder); % sorting fields according to main data file
    hvt.excludedInd = find( any(isnan( hvt.Vol ),2) ); % searching the cases which have no hippocampus volume data
    hvt.caseName = reshape(hvt.caseName,1,[]);
    %hvt.caseName(hvt.excludedInd) = []; hvt.Vol(hvt.excludedInd,:) = []; hvt.Group(hvt.excludedInd) = [];
    [~,cInd] = getPatientControlInd(hvt.caseName,cdb,controlGroup);
    hvt.Vol_Z = zScoreToSubset(hvt.Vol, cInd);
    hvt.Vol_flip = hvt.Vol_Z;
    if size(hvt.Vol,2) == 2 % flipping RTLE hippocampus volumes
        if strcmpi(keepVol,'ipsi')
            i1 = 1;
            i2 = 2;
        elseif strcmpi(keepVol,'contra')
            i1 = 2;
            i2 = 1;
        else
            error('getHippVolumeStruct:keepVol','must be either ipsi or contra');
        end
        k = strcmpi(hvt.Group,'RTLE'); % getting the RTLE indices to keep only the ipsi-lateral Hippocampus
        hvt.Vol(k,i1) = hvt.Vol(k,i2);
        hvt.Vol_flip(k,i1) = hvt.Vol_flip(k,i2); % saving the R hip vol onto the old L hip vol for RTLE
        hvt.Vol_Z(k,i1) = hvt.Vol_Z(k,i2);
        hvt.Vol(:,i2) = [];
        hvt.Vol_flip(:,i2) = [];
        hvt.Vol_Z(:,i2) = [];
    end

    hv = struct('raw',[],'flip',[],'zToControls',[]);
    hv.raw = hvt;
    hv.flip = hvt;
    hv.zToControls = hvt;
    hv.raw = rmfield(hv.raw, {'Group', 'Vol_flip', 'Vol_Z'});
    hv.flip.Vol = hv.flip.Vol_flip;
    hv.flip = rmfield(hv.flip, {'Group', 'Vol_flip', 'Vol_Z'});
    hv.zToControls.Vol = hv.zToControls.Vol_Z;
    hv.zToControls = rmfield(hv.zToControls, {'Group', 'Vol_flip', 'Vol_Z'});
end