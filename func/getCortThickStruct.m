function ct = getCortThickStruct(ctFileName, cnOrder, N)
    ct = load(ctFileName);
    if N == 90
        ct = ct.N90;
    else
        ct = ct.N306;
    end
    [~,k] = setdiff(ct.raw.caseName,cnOrder);
    ct.raw.CT(k) = []; ct.raw.CT_L(k) = []; ct.raw.CT_R(k) = []; ct.raw.CT_node(k) = []; ct.raw.caseName(k) = [];
    [~,k] = setdiff(ct.zToControls.caseName,cnOrder);
    ct.zToControls.CT(k) = []; ct.zToControls.CT_L(k) = []; ct.zToControls.CT_R(k) = []; ct.zToControls.CT_node(k) = []; ct.zToControls.caseName(k) = [];
    [~,k] = setdiff(ct.flip.caseName,cnOrder);
    ct.flip.CT(k) = []; ct.flip.CT_L(k) = []; ct.flip.CT_R(k) = []; ct.flip.CT_node(k) = []; ct.flip.caseName(k) = [];

    ct.raw = sortFieldsContents(ct.raw, cnOrder);
    ct.zToControls = sortFieldsContents(ct.zToControls, cnOrder);
    ct.flip = sortFieldsContents(ct.flip, cnOrder);

    [pInd,cInd] = getPatientControlInd(cnOrder);
    ct = groupCortThick(ct,cInd,pInd);
end

function ctt = groupCortThick(ct,cInd,pInd)
    ctt = ct;
    ctt.raw.cData.CT = ct.raw.CT(cInd);
    ctt.raw.cData.CT_node = ct.raw.CT_node(cInd);
    ctt.raw.pData.CT = ct.raw.CT(pInd);
    ctt.raw.pData.CT_node = ct.raw.CT_node(pInd);
    ctt.raw = rmfield(ctt.raw, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
    
    ctt.flip.cData.CT = ct.flip.CT(cInd);
    ctt.flip.cData.CT_node = ct.flip.CT_node(cInd);
    ctt.flip.pData.CT = ct.flip.CT(pInd);
    ctt.flip.pData.CT_node = ct.flip.CT_node(pInd);
    ctt.flip = rmfield(ctt.flip, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
    
    ctt.zToControls.cData.CT = ct.zToControls.CT(cInd);
    ctt.zToControls.cData.CT_node = ct.zToControls.CT_node(cInd);
    ctt.zToControls.pData.CT = ct.zToControls.CT(pInd);
    ctt.zToControls.pData.CT_node = ct.zToControls.CT_node(pInd);
    ctt.zToControls = rmfield(ctt.zToControls, {'caseName','CT_L','CT_R','CT','CT_node'}); % I won't use CT_L or CT_R alone for now
end