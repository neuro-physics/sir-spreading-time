function rtle_ind = getRTLEIndices(caseName,casesMetaData)
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 2) || isempty(casesMetaData)
        casesMetaData = load(fullfile(dataDir,'TLE_NB_BB.mat'));
        casesMetaData = casesMetaData.casesMetaData;
    end
    rtle_ind = find(isRTLECase(caseName,casesMetaData));
end