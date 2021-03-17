function [cInd,cCases] = getAgeAndSexMatchControls(nControls,pCases,caseNames,casesMetaData,nTrials,matchSex,matchAge)
    [~,pInd] = intersect(casesMetaData.Code, pCases);
    if (nControls < numel(pInd))
        nControls = numel(pInd);
    end
    pSex = reshape(cellfun(@(x)strcmp(x,'Male'),casesMetaData.Sex(pInd)),[numel(pInd),1]);
    pAge = reshape(casesMetaData.Age(pInd),[numel(pInd),1]);
    pVec = getFeatureVec(pSex,pAge,nControls,matchSex,matchAge);
    
    [~,allControlCases] = getPatientIndex(casesMetaData, {'Group','Use'}, {{'NC'},{1}}, 'AND');
    [~,allControlInd] = intersect(casesMetaData.Code, allControlCases);
    
    cAge = reshape(casesMetaData.Age(allControlInd),[numel(allControlInd),1]);
    cSex = reshape(cellfun(@(x)strcmp(x,'Male'),casesMetaData.Sex(allControlInd)),[numel(allControlInd),1]);
    
    nTotal = numel(allControlInd);
    
    d = Inf;
    k = 1:nControls;
    for i = 1:nTrials
        [d0,k0] = distanceCP(nTotal, nControls, cSex, cAge, pVec, matchSex, matchAge);
        if d0 <= d
            k = k0;
        end
    end
    ci = allControlInd(k);
    cc = casesMetaData.Code(ci);
    
    [~,cInd] = intersect(caseNames,cc);
    cCases = caseNames(cInd);
end

function v = zeroFill(u,n)
    v = u;
    n = n - numel(u);
    v((end+1):(end+n)) = 0;
end

function v = getFeatureVec(s,a,n,ms,ma)
    v = [];
    if ms
        v = zeroFill(s(:),n);
    end
    if ma
        v = [ v; zeroFill(a(:),n) ];
    end
end

function [d,k] = distanceCP(nTotal,nControls,cSex,cAge,pVec,matchSex,matchAge)
    k = randperm(nTotal, nControls);
    cVec = getFeatureVec(cSex(k),cAge(k),nControls,matchSex,matchAge);
    d = norm(pVec - cVec);
end
