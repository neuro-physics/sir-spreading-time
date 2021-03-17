function r = isRTLECase(caseName,casesMetaData)
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 2) || isempty(casesMetaData)
        casesMetaData = load(fullfile(dataDir,'TLE_NB_BB.mat'));
        casesMetaData = casesMetaData.casesMetaData;
    end
    rtle_cases = casesMetaData.Code( strcmpi(casesMetaData.Group,'RTLE') & (casesMetaData.UseForSpSim==1));
    [~,rtle_ind] = intersect(caseName,rtle_cases,'stable');
    r = false(size(caseName));
    r(rtle_ind)=true;
end