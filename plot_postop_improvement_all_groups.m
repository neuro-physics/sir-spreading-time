clearvars
close all

addpath func

load('D:\Dropbox\p\postdoc\data\sirs\fcd_selected\N306\postop_imp.mat') % loads variable p

thetaInd = 4;
figOutDir = 'D:\Dropbox\p\postdoc\data\sirs\fcd_selected\figs\postop_imp';
saveOutputFig = true;

pp = p(thetaInd);

sp_target = 'all'; % plots data corresponding to spreading from/to all nodes
% sp_target = 'res'; % plots data corresponding only to spreading from/to resected nodes



%%

patientGroup = 'FCD_PREOP';
fh = gobjects(1,8);
fn = cell(1,8);
fh(1) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{1} = 'Sin_r';
fh(2) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{2} = 'Sin_l';
fh(3) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{3} = 'Sout_r';
fh(4) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{4} = 'Sout_l';
fh(5) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{5} = 'Zin_r';
fh(6) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{6} = 'Zin_l';
fh(7) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{7} = 'Zout_r';
fh(8) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{8} = 'Zout_l';
fn = appendStr(fn,['_',patientGroup,'_',sp_target]);
fn = cellfun(@(x)fullfile(figOutDir,patientGroup,x),fn,'UniformOutput',false);
if saveOutputFig
    mkdir(fullfile(figOutDir,patientGroup))
    saveFigure(fh,fn,'png');
end

%%

patientGroup = 'FCD_POSTOP';
fh = gobjects(1,8);
fn = cell(1,8);
fh(1) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{1} = 'Sin_r';
fh(2) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{2} = 'Sin_l';
fh(3) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{3} = 'Sout_r';
fh(4) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{4} = 'Sout_l';
fh(5) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{5} = 'Zin_r';
fh(6) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{6} = 'Zin_l';
fh(7) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{7} = 'Zout_r';
fh(8) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{8} = 'Zout_l';
fn = appendStr(fn,['_',patientGroup,'_',sp_target]);
fn = cellfun(@(x)fullfile(figOutDir,patientGroup,x),fn,'UniformOutput',false);
if saveOutputFig
    mkdir(fullfile(figOutDir,patientGroup))
    saveFigure(fh,fn,'png');
end

%%

patientGroup = 'FCD_POSTOPSIM';
fh = gobjects(1,8);
fn = cell(1,8);
fh(1) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{1} = 'Sin_r';
fh(2) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{2} = 'Sin_l';
fh(3) = plot_func.plot_postop_improvement(pp,pp.data,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{3} = 'Sout_r';
fh(4) = plot_func.plot_postop_improvement(pp,pp.data,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Raw Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{4} = 'Sout_l';
fh(5) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_in_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{5} = 'Zin_r';
fh(6) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_in_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score In Sp Times - ', patientGroup,' (',sp_target,')']);
fn{6} = 'Zin_l';
fh(7) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dr_all',['Zdr_out_',sp_target],patientGroup,{'xbinslin',10},'Radial distance (MNI)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{7} = 'Zout_r';
fh(8) = plot_func.plot_postop_improvement(pp,pp.zControlData,'dl_all',['Zdl_out_',sp_target],patientGroup,{'xbinslin',10},'Fiber distance (mm)',['Z-Score Out Sp Times - ', patientGroup,' (',sp_target,')']);
fn{8} = 'Zout_l';
fn = appendStr(fn,['_',patientGroup,'_',sp_target]);
fn = cellfun(@(x)fullfile(figOutDir,patientGroup,x),fn,'UniformOutput',false);
if saveOutputFig
    mkdir(fullfile(figOutDir,patientGroup))
    saveFigure(fh,fn,'png');
end