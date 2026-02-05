function T = export_TLE_table_to_UFSC()
%%
    clearvars
    close all
    
    dataDir    = 'D:/Dropbox/p/postdoc/data';
    output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality';
    
    d = load(fullfile(dataDir,'TLE_NB_BB.mat'));
    T = struct2table(d.casesMetaData);
    
    dnp = load(fullfile(dataDir,'TLE_Neuropsyche_Data.mat'));
    Tnp = struct2table(rmfield(dnp.TLE_NPT,'evaluationdate'));

    T.IsPatient         = cellfun(@(x)int32(~isempty(regexpi(x,'^0\d+_\d{1}'))),T.Code);
    T(~T.UseForSpSim,:) = [];
    T.UseForSpSim       = [];
    T.Use               = [];
    T.Source            = [];
    T                   = [T(:,1:2),T(:,end),T(:,3:(end-1))];

    [~,k1,k2]            = intersect(d.ctdata.N306.raw.caseName,T.Code);
    T.CortThickAvg       = zeros(size(T,1),1);
    T.CortThickAvg(k2)   = d.ctdata.N306.raw.CT(k1);
    T.CortThickAvg_L(k2) = d.ctdata.N306.raw.CT_L(k1);
    T.CortThickAvg_R(k2) = d.ctdata.N306.raw.CT_R(k1);
    
    
    %T.HipVol_L           = T.HipVol(:,1);
    %T.HipVol_R           = T.HipVol(:,2);
    T.HipVol             = [];
    hv                       = getHipVolStruct([], T.Code, 'ipsi', false);
    [~,k1,k2]                = intersect(hv.caseName,T.Code);
    T.HipVol_ipsi            = zeros(size(T,1),1);
    T.HipVol_ipsi_ZScore     = zeros(size(T,1),1);
    T.HipVol_ipsi(k2)        = hv.HipVol(k1);
    T.HipVol_ipsi_ZScore(k2) = hv.HipVol_Z(k1);
    
    hv                         = getHipVolStruct([], T.Code, 'contra', false);
    [~,k1,k2]                  = intersect(hv.caseName,T.Code);
    T.HipVol_contra            = zeros(size(T,1),1);
    T.HipVol_contra_ZScore     = zeros(size(T,1),1);
    T.HipVol_contra(k2)        = hv.HipVol(k1);
    T.HipVol_contra_ZScore(k2) = hv.HipVol_Z(k1);
    

    [~,k1,k2]            = intersect(Tnp.MRIcode,T.Code);
    T.VerbalIQ            = -666.*ones(size(T,1),1);
    T.DigitSpanagecorSS   = -666.*ones(size(T,1),1);
    T.Forward             = -666.*ones(size(T,1),1);
    T.Backward            = -666.*ones(size(T,1),1);
    T.Blockdesign         = -666.*ones(size(T,1),1);
    T.MemoryScores        = -666.*ones(size(T,1),1);
    T.MemoScoresT5_T1     = -666.*ones(size(T,1),1);
    T.MemoScoresT7_T5     = -666.*ones(size(T,1),1);
    T.MemoNonverbal       = -666.*ones(size(T,1),1);
    T.MemoNonverbalT5_T1  = -666.*ones(size(T,1),1);
    T.MemoNonverbalT7_T5  = -666.*ones(size(T,1),1);
    T.VerbalFluency       = -666.*ones(size(T,1),1);
    T.MotorDom            = -666.*ones(size(T,1),1);
    T.MotorDom_non        = -666.*ones(size(T,1),1);
    T.MotorBalanced       = -666.*ones(size(T,1),1);
    T.MotorBalanced_non   = -666.*ones(size(T,1),1);
    T.MotorSpeed          = -666.*ones(size(T,1),1);
    T.MotorSpeed_non      = -666.*ones(size(T,1),1);
    T.handedness          = -666.*ones(size(T,1),1);
    T.VerbalIQ(k2)             = Tnp.VIQ(k1);
    T.DigitSpanagecorSS(k2)    = Tnp.DigitSpanagecorSS(k1);
    T.Forward(k2)              = Tnp.Forward(k1);
    T.Backward(k2)             = Tnp.Backward(k1);
    T.Blockdesign(k2)          = Tnp.Blockdesign(k1);
    T.MemoryScores(k2)         = Tnp.Memoryscores(k1);
    T.MemoScoresT5_T1(k2)      = Tnp.T5_T1(k1);
    T.MemoScoresT7_T5(k2)      = Tnp.T7_T5(k1);
    T.MemoNonverbal(k2)        = Tnp.nonverbalmemo(k1);
    T.MemoNonverbalT5_T1(k2)   = Tnp.T5_T1_nonverbal(k1);
    T.MemoNonverbalT7_T5(k2)   = Tnp.T7_T5_nonverbal(k1);
    T.VerbalFluency(k2)        = Tnp.Fluency(k1);
    T.MotorDom(k2)             = Tnp.MotorDom(k1);
    T.MotorDom_non(k2)         = Tnp.MotorDom_non(k1);
    T.MotorBalanced(k2)        = Tnp.MotorBalanced(k1);
    T.MotorBalanced_non(k2)    = Tnp.MotorBalanced_non(k1);
    T.MotorSpeed(k2)           = Tnp.MotorSpeed(k1);
    T.MotorSpeed_non(k2)       = Tnp.MotorSpeed_non(k1);
    T.handedness(k2)           = Tnp.handedness(k1);

%%
    S = table2struct(T);
    save(fullfile(output_dir,'TLE_patients_UFSC.mat'),'S')
    
    writetable(T,fullfile(output_dir,'TLE_patients_UFSC.xlsx'));
end

function r=iif(cond,a,b)
    if cond
        r = a;
    else
        r = b;
    end
end