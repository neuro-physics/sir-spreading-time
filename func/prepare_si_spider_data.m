function [r,rStd,axLabel2,dataLabels,axLabelStr,colNames,colLegend,r_T,r_FDR,r_Ef,r_CT,r_HV] = prepare_si_spider_data(s,dataLabel,dataInd,axLabel,sRow,shiftData,patientsControlsDiff,collapseControls,axLabelToFile,showEffectSizes,effectSzField,CohenThreshold,joinParaHipo,colLegend)%,joinDataFunc)
    if (nargin < 3) || isempty(dataInd)
        if isstruct(s) && isfield(s,'theta')
            dataInd = 1:numel(s.theta);
        end
    end
    if (nargin < 5)
        sRow = []; % selected row of control and patient data matrices
    end
    if (nargin < 6)
        shiftData = [];
    end
    if (nargin < 7) || isempty(patientsControlsDiff)
        patientsControlsDiff = false;
    end
    if (nargin < 8) || isempty(collapseControls)
        collapseControls = false;
    end
    if (nargin < 9) || isempty(axLabelToFile)
        axLabelToFile = false;
    end
    if (nargin < 10) || isempty(showEffectSizes)
        showEffectSizes = false; % false, or 1 for highlighting effect size>threshold; or 2 for plotting an effect size curve together with the data
    end
    if (nargin < 11) || isempty(effectSzField)
        effectSzField = 'hFDR';
    end
    if (nargin < 12) || isempty(CohenThreshold)
        CohenThreshold = 0.8;
    end
    if (nargin < 13) || isempty(joinParaHipo)
        joinParaHipo = false;
    end
    if (nargin < 14) || isempty(colLegend)
        colLegend = {};
    end
%     if (nargin < 15) || isempty(joinDataFunc)
%         joinDataFunc = @(x)mean(x,1,'omitnan');
%     end
    if patientsControlsDiff
        dataLabels = {'Patients - Controls'};
    else
        dataLabels = {'Controls', 'Patients'};
    end

    axLabelStr = 'T-test labels';
    if isNumericVector(dataInd) || isCellOfCells(s)
        if isNumericVector(dataInd)
            nC = numel(dataInd);
        else
            if isCellOfCells(s)
                nC = numel(s);
            else
                s = {s};
                nC = 1;
            end
        end
        r = cell(1,nC);
        rStd = cell(1,nC);
        r_T = cell(1,nC);
        r_FDR = cell(1,nC);
        r_Ef = cell(1,nC);
        r_CT = cell(1,nC);
        r_HV = cell(1,nC);
        axLabel2 = cell(1,nC);
        colNames = cell(1,nC);
        for i = 1:nC
            if isNumericVector(dataInd)
                [r{i},rStd{i},axLabel2{i},strTemp,colNames{i},colLegend,r_T{i},r_FDR{i},r_Ef{i},r_CT{i},r_HV{i}] = prepare_si_spider_data_internal(s,dataLabel,dataInd(i),axLabel,sRow,shiftData,patientsControlsDiff,collapseControls,axLabelToFile,showEffectSizes,effectSzField,CohenThreshold,joinParaHipo,colLegend);%,joinDataFunc);
                axLabelStr = strjoin({axLabelStr,'','','--','','',['theta = ',num2str(s.theta(dataInd(i)))],strTemp},'\n');
            else
                [r{i},rStd{i},axLabel2{i},strTemp,colNames{i},colLegend,r_T{i},r_FDR{i},r_Ef{i},r_CT{i},r_HV{i}] = prepare_si_spider_data_internal(s{i},'',[],axLabel,sRow,shiftData,patientsControlsDiff,collapseControls,axLabelToFile,showEffectSizes,effectSzField,CohenThreshold,joinParaHipo,colLegend);%,joinDataFunc);
                axLabelStr = strjoin({axLabelStr,'','','--','','',['panel ',num2str(i)],strTemp},'\n');
            end
        end
    else
        [r,rStd,axLabel2,strTemp,colNames,colLegend,r_T,r_FDR,r_Ef,r_CT,r_HV] = prepare_si_spider_data_internal(s,dataLabel,dataInd,axLabel,sRow,shiftData,patientsControlsDiff,collapseControls,axLabelToFile,showEffectSizes,effectSzField,CohenThreshold,joinParaHipo,colLegend);%,joinDataFunc);
        axLabelStr = strjoin({axLabelStr,strTemp},'\n');
    end
end

function [r,rStd,axLabel2,axLabelStr,colNames,colLegend,r_T,r_FDR,r_Ef,r_CT,r_HV] = prepare_si_spider_data_internal(s,dataLabel,dataInd,axLabel,sRow,shiftData,patientsControlsDiff,collapseControls,axLabelToFile,showEffectSizes,effectSzField,CohenThreshold,joinParaHipo,colLegend)%,joinDataFunc)
    rStd = [];
    r_CT = [];
    r_HV = [];
    r_T = [];
    r_FDR = [];
    r_Ef = [];
    axLabelStr = '';

    [mDataLabel,stdDataLabel,tDataLabel,tDataLabelCT,tDataLabelHV] = splitDataLabel(dataLabel);

    if joinParaHipo
        indJoin = find(contains(colLegend,'ParaHippocampal') | contains(colLegend,'ParHip'));
    else
        indJoin = [];
    end

    efSizeName = 'd';
    if strcmpi(effectSzField,'effsz')
        efSizeName = 'ef';
    end
    
%     if numel(sRow) > 1
%         error('Only one row can be selected!');
%     end
    if ~isempty(shiftData)
        if ~isscalar(shiftData)
            error('shiftData must be a scalar');
        end
    end
    sControlStd = [];
    if isstruct(s)
        if isempty(sRow)
            [sControl,newIndCol] = replaceLinesByFunc(s.controlData.(mDataLabel){dataInd}(:),indJoin,1);
            sPatient = replaceLinesByFunc(s.patientData.(mDataLabel){dataInd}(:),indJoin,1);
            sEfSz = replaceLinesByFunc(abs(s.ttest.(tDataLabel)(dataInd).(effectSzField)(:)),indJoin,1,@(x)max(x,[],1));
            if ~isempty(stdDataLabel)
                sControlStd = replaceLinesByFunc(s.controlData.(stdDataLabel){dataInd}(:),indJoin,1,@(x)sqrt(mean(x.^2,1,'omitnan')));
                sPatientStd = replaceLinesByFunc(s.patientData.(stdDataLabel){dataInd}(:),indJoin,1,@(x)sqrt(mean(x.^2,1,'omitnan')));
            end
            sTTestH = replaceLinesByFunc(s.ttest.(tDataLabel)(dataInd).h == 1,indJoin,1,@(x)any(x,1))';
            sTTestHFDR = replaceLinesByFunc(s.ttest.(tDataLabel)(dataInd).hFDR == 1,indJoin,1,@(x)any(x,1))';
            sEfSzTest = replaceLinesByFunc(abs(s.ttest.(tDataLabel)(dataInd).(effectSzField)) > CohenThreshold,indJoin,1,@(x)any(x,1))';
            sTTestCT = [];
            sTTestHV = [];
            if ~isempty(tDataLabelCT)
                sTTestCT = replaceLinesByFunc(s.ttest.(tDataLabelCT)(dataInd).hFDR == 1,indJoin,1,@(x)any(x,1))';
            end
            if ~isempty(tDataLabelHV)
                sTTestHV = replaceLinesByFunc(s.ttest.(tDataLabelHV)(dataInd).hFDR == 1,indJoin,1,@(x)any(x,1))';
            end
        else
            [sControl,newIndCol] = replaceLinesByFunc(s.controlData.(mDataLabel){dataInd}(sRow,:),indJoin,1);
            sControl = sControl';
            if collapseControls
                sControl = mean(sControl,2,'omitnan');
            end
            sPatient = replaceLinesByFunc(s.patientData.(mDataLabel){dataInd}(sRow,:),indJoin,1)';
            sEfSz = replaceLinesByFunc(abs(s.ttest.(tDataLabel)(dataInd).(effectSzField)(sRow,:)),indJoin,1,@(x)max(x,[],1))';
            if ~isempty(stdDataLabel)
                sControlStd = replaceLinesByFunc(s.controlData.(stdDataLabel){dataInd}(sRow,:),indJoin,1,@(x)sqrt(mean(x.^2,1,'omitnan')))';
                sPatientStd = replaceLinesByFunc(s.patientData.(stdDataLabel){dataInd}(sRow,:),indJoin,1,@(x)sqrt(mean(x.^2,1,'omitnan')))';
            end
            sTTestH = replaceLinesByFunc(s.ttest.(tDataLabel)(dataInd).h(sRow,:) == 1,indJoin,1,@(x)any(x,1))';
            sTTestHFDR = replaceLinesByFunc(s.ttest.(tDataLabel)(dataInd).hFDR(sRow,:) == 1,indJoin,1,@(x)any(x,1))';
            sEfSzTest = replaceLinesByFunc(abs(s.ttest.(tDataLabel)(dataInd).(effectSzField)(sRow,:)) > CohenThreshold,indJoin,1,@(x)any(x,1))';
            sTTestCT = [];
            sTTestHV = [];
            if ~isempty(tDataLabelCT)
                sTTestCT = replaceLinesByFunc(s.ttest.(tDataLabelCT)(dataInd).hFDR(sRow,:) == 1,indJoin,1,@(x)any(x,1))';
            end
            if ~isempty(tDataLabelHV)
                sTTestHV = replaceLinesByFunc(s.ttest.(tDataLabelHV)(dataInd).hFDR(sRow,:) == 1,indJoin,1,@(x)any(x,1))';
            end
        end
    elseif iscell(s)
        if isstruct(s{1})
            error('cell of struct is still not supported');
            % this data type would be useful to view multiple groups in the same spider plot... I will focus on the L + flipped R
            % so for now it is not interesting for me to implement it
            % to implement it, I need to make the "if" contents just above into a function that returns sControl, sPatient, sTTestH and sTTestHFDR
            % for each struct in the cell array s... this would be used below to construct r and rStd vectors, as well
            % as the axLabel with the corresponding * and + signs when either of the structs in the cell array meets the T-test hypothesis
            % the data labels of the main function above need to take into account the groups names, that should be taken from each
            % struct in the cell array s... these data labels can also be used in axLabel to identify which labels are significant for which groups
        end
        if isempty(sRow)
            [sControl, newIndCol] = replaceLinesByFunc(s{1}(:)',indJoin);
            sPatient = replaceLinesByFunc(s{2}(:)',indJoin);
        else
            [sControl, newIndCol] = replaceLinesByFunc(s{1}(sRow,:)',indJoin,1);
            sPatient = replaceLinesByFunc(s{2}(sRow,:)',indJoin,1);
        end
        sEfSz = [];
        sTTestH = [];
        sTTestHFDR = [];
        sEfSzTest = [];
        sTTestCT = [];
        sTTestHV = [];
    else
        error('unsupported data type');
    end
    
    if ~isempty(newIndCol)
        l1 = colLegend{indJoin(1)};
        ccl = colLegend;
        colLegend = cell(size(newIndCol));
        n = numel(newIndCol)-1;
        colLegend(1:n) = ccl(newIndCol(~isnan(newIndCol)));
        colLegend{isnan(newIndCol)} = l1;
    end

    if patientsControlsDiff
        colNames = { 'diff' };
        r = sPatient-sControl;
        if ~isempty(stdDataLabel)
            rStd = sPatientStd;
        end
        if isnumeric(showEffectSizes) && (showEffectSizes==2)
            colNames = [colNames,efSizeName];
            r = [r,sEfSz];
            if ~isempty(stdDataLabel)
                rStd = [rStd,NaN(size(sEfSz))];
            end
        end
        r_T = sTTestH;
        r_FDR = sTTestHFDR;
        r_Ef = sEfSzTest;
        if ~isempty(sTTestCT)
            r_CT = sTTestCT;
        end
        if ~isempty(sTTestHV)
            r_HV = sTTestHV;
        end
    else
        if collapseControls
            sControl = mean(sControl,2,'omitnan');
            if ~isempty(sControlStd)
                sControlStd = sqrt(mean(sControlStd.^2,2,'omitnan')); % sqrt of the mean variance
            end
        end
        nControls = size(sControl,2);
        nPatients = size(sPatient,2);
        colNames = [repmat({ 'Controls' },1,nControls),repmat({'Patients'},1,nPatients)];
        colLegend = [repmat({ 'Controls' },1,nControls),colLegend];
        r = [sControl,sPatient];
        if ~isempty(stdDataLabel)
            rStd = [sControlStd,sPatientStd];
        end
        r_T = [NaN(size(sControl)),sTTestH];
        r_FDR = [NaN(size(sControl)),sTTestHFDR];
        r_Ef = [NaN(size(sControl)),sEfSzTest];
        if ~isempty(sTTestCT)
            r_CT = [NaN(size(sControl)),sTTestCT];
        end
        if ~isempty(sTTestHV)
            r_HV = [NaN(size(sControl)),sTTestHV];
        end
        if isnumeric(showEffectSizes) && (showEffectSizes==2)
            nEffect = size(sEfSz,2);
            colNames = [colNames,repmat({efSizeName},1,nEffect)];
            r = [r,sEfSz];
            if ~isempty(stdDataLabel)
                rStd = [rStd,NaN(size(sEfSz))];
            end
        end
    end
    [~,axLabelTemp] = shrinkStrByCapLetters(axLabel,1,true);
    if size(sTTestHFDR,2) > 1
%         [sTTestHFDR,sTTestHFDRapp] = getNonEmptyCols(sTTestHFDR);
%         [sTTestH,sTTestHapp] = getNonEmptyCols(sTTestH);
%         axLabel(sTTestHFDR) = appendStr(axLabel(sTTestHFDR),appendStr(sTTestHFDRapp(sTTestHFDR),'','*'),'');
        [sTTestHFDR,sTTestHFDRapp] = getNonEmptyCols(sTTestHFDR,sTTestH,'*','+');
        axLabelTemp(sTTestHFDR) = appendStr(axLabelTemp(sTTestHFDR),appendStr(sTTestHFDRapp(sTTestHFDR),'','*'),'');
        if ~isempty(sTTestCT)
            [sTTestCT,strApp] = getNonEmptyCols(sTTestCT);
            axLabelTemp(sTTestCT) = appendStr(axLabelTemp(sTTestCT),appendStr(strApp(sTTestCT),')','(CT,'),'');
        end
        if ~isempty(sTTestHV)
            [sTTestHV,strApp] = getNonEmptyCols(sTTestHV);
            axLabelTemp(sTTestHV) = appendStr(axLabelTemp(sTTestHV),appendStr(strApp(sTTestHV),')','(HV,'),'');
        end
        if isnumeric(showEffectSizes) && (showEffectSizes==1)
            if ~isempty(sEfSzTest)
                [sEfSzTest,strApp] = getNonEmptyCols(sEfSzTest);
                axLabelTemp(sEfSzTest) = appendStr(axLabelTemp(sEfSzTest),appendStr(strApp(sEfSzTest),')','(d,'),'');
            end
        end
    else
        axLabelTemp(sTTestHFDR) = appendStr(axLabelTemp(sTTestHFDR),'','*');
        axLabelTemp((~sTTestHFDR) & sTTestH) = appendStr(axLabelTemp((~sTTestHFDR) & sTTestH),'','+');
        if ~isempty(sTTestCT)
            axLabelTemp(sTTestCT) = appendStr(axLabelTemp(sTTestCT),',CT','');
        end
        if ~isempty(sTTestHV)
            axLabelTemp(sTTestHV) = appendStr(axLabelTemp(sTTestHV),',HV','');
        end
        if isnumeric(showEffectSizes) && (showEffectSizes==1)
            if ~isempty(sEfSzTest)
                axLabelTemp(sEfSzTest) = appendStr(axLabelTemp(sEfSzTest),',d','');
            end
        end
    end

    if axLabelToFile
        [~,axLabel2] = shrinkStrByCapLetters(axLabel,1,true);
    else
        axLabel2 = axLabelTemp;
    end
%     if size(sTTestH,2) > 1
%         [sTTestH,sTTestHapp] = getNonEmptyCols(sTTestH);
%         axLabel(sTTestH) = appendStr(axLabel(sTTestH),'',appendStr(sTTestHapp(sTTestH),'','+'));
%     end
    if ~isempty(shiftData)
        r = circshift(r,shiftData,1);
        if ~isempty(stdDataLabel)
            rStd = circshift(rStd,shiftData,1);
        end
        axLabel2 = circshift(axLabel2,shiftData);
    end

    if axLabelToFile
        if ~isempty(shiftData)
            axLabelTemp = circshift(axLabelTemp,shiftData);
        end
        axLabelStr = strjoin(axLabelTemp,'\n');
    end
%     [~,axLabel] = shrinkStrByCapLetters(axLabel);
end

function r = isCellOfCells(s)
    r = iscell(s) && all(cellfun(@(x)iscell(x) && (numel(x)==2),s));
end

function r = isNumericVector(x)
    r = isnumeric(x) && isvector(x) && (numel(x) > 1);
end

function [ml,sl,tl,tlCT,tlHV] = splitDataLabel(dl)
    tlCT = [];
    tlHV = [];
    if iscell(dl)
        isStd = cellfun(@(x)~isempty(x),strfind(dl,'Std'));
        isTTest = cellfun(@(x)~isempty(x),regexp(dl,'^ttest_'));
        if ~any(isStd)
            isStd = cellfun(@(x)~isempty(x),strfind(dl,'Err'));
        end
        ml = dl{(~isStd) & (~isTTest)};
        if any(isStd)
            sl = dl{isStd};
        else
            sl = [];
        end
        if any(isTTest)
            ddl = regexprep(dl(isTTest),'^ttest_','');
            isCT = cellfun(@(x)~isempty(x),regexp(ddl,'_?CT_?'));
            isHV = cellfun(@(x)~isempty(x),regexp(ddl,'_?HV_?'));
            if any((~isCT) & (~isHV))
                tl = ddl{(~isCT) & (~isHV)};
            else
                tl = ml;
            end
            if any(isCT)
                tlCT = ddl{isCT};
            end
            if any(isHV)
                tlHV = ddl{isHV};
            end
        else
            tl = ml;
        end
    else
        ml = dl;
        sl = [];
        tl = ml;
    end
end