function T = getTheta(theta, inputFile, N)
    if ischar(theta)
        if strcmpi(theta, 'actThresh')
            cName = getCaseName(inputFile);
            [inputDir,~,~] = fileparts(inputFile);
            nTxt = ['N', num2str(N) ];
            atFile = load([inputDir, filesep, nTxt, '_thetaActivation.mat']);
            T = atFile.thetaAct(strcmp(atFile.caseName,cName));
        else
            T = str2double(theta);
            if isnan(T)
                error('getTheta:theta','theta value not supported');
            end
        end
    else
        T = theta;
    end
end
