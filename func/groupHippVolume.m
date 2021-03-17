function hvv = groupHippVolume(hv,cInd,pInd)
    if isempty(hv)
        hvv = struct('raw', [], 'flip', [], 'zToControls', []);
        hvv.raw = struct('cData', [], 'pData', []);
        hvv.flip = struct('cData', [], 'pData', []);
        hvv.zToControls = struct('cData', [], 'pData', []);

        hvv.raw.cData.HV = [];
        hvv.raw.pData.HV = [];

        hvv.flip.cData.HV = [];
        hvv.flip.pData.HV = [];

        hvv.zToControls.cData.HV = [];
        hvv.zToControls.pData.HV = [];
        return;
    end
    hvv = hv;
    hvv.excludedInd = hv.raw.excludedInd;
    cIndHV = setdiff(cInd,hv.raw.excludedInd);
    pIndHV = setdiff(pInd,hv.raw.excludedInd);
    hvv.raw.cData.HV = hv.raw.Vol(cIndHV);
    hvv.raw.pData.HV = hv.raw.Vol(pIndHV);
    hvv.raw = rmfield(hvv.raw, {'caseName','Vol','excludedInd'}); % I won't use CT_L or CT_R alone for now

    cIndHV = setdiff(cInd,hv.flip.excludedInd);
    pIndHV = setdiff(pInd,hv.flip.excludedInd);
    hvv.flip.cData.HV = hv.flip.Vol(cIndHV);
    hvv.flip.pData.HV = hv.flip.Vol(pIndHV);
    hvv.flip = rmfield(hvv.flip, {'caseName','Vol','excludedInd'}); % I won't use CT_L or CT_R alone for now
    
    cIndHV = setdiff(cInd,hv.zToControls.excludedInd);
    pIndHV = setdiff(pInd,hv.zToControls.excludedInd);
    hvv.zToControls.cData.HV = hv.zToControls.Vol(cIndHV);
    hvv.zToControls.pData.HV = hv.zToControls.Vol(pIndHV);
    hvv.zToControls = rmfield(hvv.zToControls, {'caseName','Vol','excludedInd'}); % I won't use CT_L or CT_R alone for now
end