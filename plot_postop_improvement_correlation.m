addpath('func');

dataDir = 'D:\Dropbox\p\postdoc\data';
if isunix
    dataDir = '/host/scarus/local_raid/mauricio/data';
end
%%
% cdb = load(fullfile(dataDir,'TLE_NB_BB.mat'));
cdb = load(fullfile(dataDir,'FCD_table.mat'));

[~,~,~,aal]=aalsurfview(zeros(90,1));

%%
thetaInd = 4;
alphaTTest = 0.05;
alphaFDR = 0.01;
dataField = 'zControlData'; % 'zControlData' or 'data'

si = load(fullfile(dataDir,'sirs','fcd_selected','N306','si_data_w.mat'));
po = load('D:\Dropbox\p\postdoc\data\sirs\fcd_selected\N306\postop_imp.mat'); % loads variable p

cn_si = si.caseName(:);
cn_po = po.p(thetaInd).caseName;
N = si.SpMatrixW(thetaInd).N;
si = si.SpMatrixW(thetaInd).(dataField);

po = po.p(thetaInd).(dataField);
po = rmfield(po,{'Kt_std', 'Ke_std'});
po = transposeFields(po);
po.Code = cn_po;
po = getStructRows(po,'Code',cn_si,false); % this line guarantees that po is sorted according to cn_si
cn_po = po.Code;
po = rmfield(po,'Code');

cc = getStructRows(cdb.casesMetaData,'Code',cn_si,false); % this line guarantees that cc is sorted according to cn_si

%%

[pInd,cInd] = getCasesIndices(cn_si, cdb.casesMetaData, 'FCD_PREOP', [], [], 'UseForSpSim'); % unified pInd and cInd for all the three structs: si, po and cc

y_p = mean(matCell2Mat(si.SAvg(pInd)),2,'omitnan');
y_c = mean(matCell2Mat(si.SAvg(cInd)),2,'omitnan');
t_sp = ttest.ttest2Struct(y_p,y_c,'Alpha',alphaTTest,'AlphaFDR',alphaFDR);

x_p = { cc.LesionTotalVolume(pInd), cc.LesionGMVolume(pInd), cc.LesionWMTransmantleVolume(pInd) };
x_c = zeros(size(y_c));

xLabel = { 'Lesion total volume (mm^3)', 'Lesion GM volume (mm^3)', 'Lesion WM volume (mm^3)' };

%%

fh = plotScatterCorr([],[],x_p,y_p,x_c,y_c,xLabel,'Z-Score Sp times');

saveFigure(fh,fullfile(dataDir,'sirs','fcd_selected','figs','postop_imp','sp_time_lesion_vol_corr'),'png');