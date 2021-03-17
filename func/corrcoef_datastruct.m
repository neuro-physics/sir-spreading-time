function [r_c_sp,p_c_sp,r_c,p_c,r_p_sp,p_p_sp,r_p,p_p,theta,scatterPlot] = corrcoef_datastruct(SpMat,B,SpMatDataField,SFieldName,BFieldName,useInverseSpTimes,zScoreData,caseName,BVarName)
% dataField = 'data', 'flipData', 'zControlData'
% useInverseSpTimes = true or false
    if (nargin < 9) || isempty(BVarName)
        BVarName = '';
    end
    B = sortFieldsContents(B,caseName);
    [pInd,cInd] = getPatientControlInd(caseName);
    
    isMatrixData = ~isvector(SpMat(1).(SpMatDataField).(SFieldName){1});
    
    if isMatrixData
        N = size(SpMat(1).(SpMatDataField).(SFieldName){1},1);
    else
        N = numel(SpMat(1).(SpMatDataField).(SFieldName){1});
    end

    if zScoreData
        B.(BFieldName) = zScoreToSubset(B.(BFieldName),cInd);
    end
    netQuantity_c = matCell2Mat(B.(BFieldName)(cInd));
    netQuantity_p = matCell2Mat(B.(BFieldName)(pInd));
    if isMatrixData
        netQuantity_c(:,1:(N+1):end) = []; % removing self connecting paths
        netQuantity_p(:,1:(N+1):end) = []; % removing self connecting paths
    end

    theta = [SpMat(:).theta];
    r_c_sp = zeros(numel(cInd),numel(theta));
    r_p_sp = zeros(numel(pInd),numel(theta));
    p_c_sp = zeros(numel(cInd),numel(theta));
    p_p_sp = zeros(numel(pInd),numel(theta));

    r_c = zeros(1,numel(theta));
    r_p = zeros(1,numel(theta));
    p_c = zeros(1,numel(theta));
    p_p = zeros(1,numel(theta));
    
    scatterPlot = struct('SpMatDataField',SFieldName,'VarName',BVarName,'sptime_control',[],'var_control',[],'sptime_patient',[],'var_patient',[]);
    scatterPlot = repmat(scatterPlot,1,numel(theta));
    
    if isfield(B,'ignore_zero_for_mean') && B.ignore_zero_for_mean
        mean_B_func = @(xx) meandiff0(xx,2);
    else
        mean_B_func = @(xx) mean(xx,2,'omitnan');
    end

    for t = 1:numel(theta)
        if useInverseSpTimes
            SpMat(t).(SpMatDataField).(SFieldName) = cellfun(@(x)1./x,SpMat(t).(SpMatDataField).(SFieldName),'UniformOutput',false);
        end
        if zScoreData && ~any(strcmpi(SpMatDataField,{'flipData','zControlData'})) % data is already z-scored if it is one of these data fields
            SpMat(t).(SpMatDataField).(SFieldName) = zScoreToSubset(SpMat(t).(SpMatDataField).(SFieldName),cInd);
        end
        sptime_c = matCell2Mat(SpMat(t).(SpMatDataField).(SFieldName)(cInd));
        sptime_c(isnan(sptime_c)) = 0;

        sptime_p = matCell2Mat(SpMat(t).(SpMatDataField).(SFieldName)(pInd));
        sptime_p(isnan(sptime_p)) = 0;

        if isMatrixData
            sptime_c(:,1:(N+1):end) = []; % removing self spreading times
            sptime_p(:,1:(N+1):end) = []; % removing self spreading times
        end

%         ss_c(ss_c==0) = 1e-8;
%         ss_p(ss_p==0) = 1e-8;

        scatterPlot(t).sptime_control = sptime_c;
        scatterPlot(t).sptime_patient = sptime_p;
        scatterPlot(t).var_control = netQuantity_c;
        scatterPlot(t).var_patient = netQuantity_p;

        [R,P] = corrcoef(mean_B_func(netQuantity_c), mean(sptime_c,2,'omitnan'));
        r_c(t) = R(1,2);
        p_c(t) = P(1,2);
        [R,P] = corrcoef(mean_B_func(netQuantity_p), mean(sptime_p,2,'omitnan'));
        r_p(t) = R(1,2);
        p_p(t) = P(1,2);

        [r_c_sp(:,t),p_c_sp(:,t)] = corrcoef_perline(netQuantity_c,sptime_c);
        [r_p_sp(:,t),p_p_sp(:,t)] = corrcoef_perline(netQuantity_p,sptime_p);
    end
end