function l = getTTestLabel(tbc,lab)
    if strcmpi(tbc,'none')
        l=[];
        return;
    end
    if ~(strcmpi(tbc,'CT') || strcmpi(tbc,'HV'))
        error('Unrecognized tTestBiasControl argument');
    end
    avgTxt = regexp(lab,'Avg(RS|R|S)?','match');
    if isempty(avgTxt)
        l = ['ttest_',lab,'_',tbc];
    else
        avgTxt = avgTxt{1};
        l = ['ttest_',strrep(lab,avgTxt,[avgTxt,'_',tbc])];
    end
end