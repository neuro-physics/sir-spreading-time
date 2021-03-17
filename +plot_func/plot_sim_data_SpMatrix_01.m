function plot_sim_data_SpMatrix_01(si_n90,si_n306,cGroup,p1Group,p2Group,groupLegend,saveOutputFigures,outputDir,imgFormat,isActThresh,isConsensus,oFileSuffix)

    if (nargin < 11) || isempty(isConsensus)
        isConsensus = false;
    end

    if (nargin < 12) || isempty(oFileSuffix)
        oFileSuffix = '';
    end

    % part of plot_sim_data.m

    fp = getDefaultFigureProperties();
    fp.pLines = {':'};
    fp.pPointSize = 3;

    if isActThresh
        si_n90 = resetTheta(si_n90, 0.03);
        si_n306 = resetTheta(si_n306, 0.03);
    end

    %% average Spreading Time vs. Theta
    x1 = { si_n90.(cGroup).SpMatrix.theta, si_n90.(p1Group).SpMatrix.theta, si_n90.(p2Group).SpMatrix.theta };
    y1 = { si_n90.(cGroup).SpMatrix.controlData.SAvg_theta, si_n90.(p1Group).SpMatrix.patientData.SAvg_theta, si_n90.(p2Group).SpMatrix.patientData.SAvg_theta };
    yErr1 = { si_n90.(cGroup).SpMatrix.controlData.SStd_theta, si_n90.(p1Group).SpMatrix.patientData.SStd_theta, si_n90.(p2Group).SpMatrix.patientData.SStd_theta };
    legVal = [ 'Controls; $N=90$', strrep(groupLegend(2:end),'_','-') ];
    ps1 = getPlotStruct(x1,y1,yErr1,'Threshold, $\theta$', 'Avg spreading time, $\langle S\rangle$', 'linear', 'linear', '', legVal, 1, '');
    ps2 = getPlotStruct(x1,y1,yErr1,'', '', 'linear', 'linear', '', legVal, 0, '');

    axPos = {[2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx],...
         [0.81 0.5567 0.1140625 0.36],...
         [0.5975 0.5 0.1140625 0.36],...
         [0.3925 0.35 0.1140625 0.36],...
         [0.1925 0.2933 0.1140625 0.36]};
    axProp = {{'XLim', [-0.002,0.052]},...
         {'XLim', [0.049979 0.05003], 'YLim', [2.678875 2.7450], 'XTick', 0.05},...
         {'XLim', [0.0299736 0.030036], 'YLim', [2.018223 2.05183], 'XTick', 0.03},...
         {'XLim', [0.0099683 0.0100389], 'YLim', [1.8622728 1.90246], 'XTick', 0.01},...
         {'XLim', [-2.18e-05 3.05e-05], 'YLim', [1.86 1.90], 'XTick', 0, 'XTickLabel', {'0'}}};
    if isActThresh
        axProp{1} = {'XLim',[0.02,0.04],'TickLabelInterpreter','latex','XTick',[0.02,0.03,0.04],'XTickLabel',{'','$\theta_0$',''}};
        axPos(2:end) = cellfun(@(x)x,cell(size(axPos(2:end))),'UniformOutput', false);
        axProp(2:end) = cellfun(@(x)x,cell(size(axProp(2:end))),'UniformOutput', false);
    end
    if isConsensus
        axPos(2:end) = {[0.8550 0.4900 0.1141 0.3600],[0.6500 0.2033 0.1141 0.3600],[0.4200 0.4067 0.1141 0.3600],[0.2075 0.3666 0.1141 0.3600]};
        axProp{1} = {'XLim',[-0.002,0.095]};
        axProp{2} = {'XLim',[0.089968140657283 0.0900479928008781],'YLim',[3.85041146143169 3.95203747769185],'XTick',0.09};
        axProp{3} = {'XLim',[0.0598940227918388 0.0601053961131198],'YLim',[2.85189454028687 2.91390293476105],'XTick',0.06};
        axProp{4} = {'XLim',[0.0299373345493285 0.0300469355307335],'YLim',[2.04132378214026 2.08056960142772],'XTick',0.03};
        axProp{5} = {'XLim',[-3.38366800103299e-05 4.83640560433891e-05],'YLim',[1.85118811553969 1.88357624429903],'XTick',0};
    end
    [fh1,axh] = plot5AxesFigure(ps1, ps2, [ 200, 200, fp.wFig/2, fp.hFig ], axPos, axProp, fp);

    x2 = { si_n306.(cGroup).SpMatrix.theta, si_n306.(p1Group).SpMatrix.theta, si_n306.(p2Group).SpMatrix.theta };
    y2 = { si_n306.(cGroup).SpMatrix.controlData.SAvg_theta, si_n306.(p1Group).SpMatrix.patientData.SAvg_theta, si_n306.(p2Group).SpMatrix.patientData.SAvg_theta };
    yErr2 = { si_n306.(cGroup).SpMatrix.controlData.SStd_theta, si_n306.(p1Group).SpMatrix.patientData.SStd_theta, si_n306.(p2Group).SpMatrix.patientData.SStd_theta };
    legVal = [ 'Controls; $N=306$', strrep(groupLegend(2:end),'_','-') ];
    ps1 = getPlotStruct(x2,y2,yErr2,'Threshold, $\theta$', 'Avg spreading time, $\langle S\rangle$', 'linear', 'linear', '', legVal, 1, '');
    ps2 = getPlotStruct(x2,y2,yErr2,'', '', 'linear', 'linear', '', legVal, 0, '');

    axPos = {[2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx],...
         [0.81 0.5567 0.1140625 0.36],...
         [0.5975 0.5 0.1140625 0.36],...
         [0.3925 0.35 0.1140625 0.36],...
         [0.1925 0.2933 0.1140625 0.36]};
    axProp = {{'XLim', [-0.002,0.052], 'YLim', [1.8679 4.3679]},...
         {'XLim', [0.049979 0.05003], 'YLim', [3.9893 4.0727], 'XTick', 0.05},...
         {'XLim', [0.0299736 0.030036], 'YLim', [2.6304 2.6929], 'XTick', 0.03},...
         {'XLim', [0.0099683 0.0100389], 'YLim', [2.0294 2.0617], 'XTick', 0.01},...
         {'XLim', [-2.18e-05 3.05e-05], 'YLim', [2.0040 2.0492], 'XTick', 0, 'XTickLabel', {'0'}}};
    if isActThresh
        axProp{1} = {'XLim',[0.02,0.04],'TickLabelInterpreter','latex','XTick',[0.02,0.03,0.04],'XTickLabel',{'','$\theta_0$',''}};
        axPos(2:end) = cellfun(@(x)x,cell(size(axPos(2:end))),'UniformOutput', false);
        axProp(2:end) = cellfun(@(x)x,cell(size(axProp(2:end))),'UniformOutput', false);
    end
    if isConsensus
        axPos(2:end) = { [0.8125 0.2267 0.1125 0.3600],[0.6375 0.5700 0.1141 0.3600],[0.4200 0.3967 0.1141 0.3600],[0.2050 0.2933 0.1141 0.3600] };
        axProp{2} = {'XLim',[0.0499703802944215 0.0500270370609504],'YLim',[3.9277684645383 4.04773673739176],'XTick',0.05};
        axProp{3} = {'XLim',[0.0419604209710744 0.0420440986570248],'YLim',[3.42947049375372 3.49342052349792],'XTick',0.042};
        axProp{4} = {'XLim',[0.0299781685821281 0.0300330820635331],'YLim',[2.63709740233988 2.66064489391235],'XTick',0.03};
        axProp{5} = {'XLim',[-1.89743672520701e-05 2.80943310950374e-05],'YLim',[2.09662050366845 2.11657390442197],'XTick',0};
    end
    [fh2,axh] = plot5AxesFigure(ps1, ps2, [ 600, 200, fp.wFig/2, fp.hFig ], axPos, axProp, fp);

    %% average Hamming distance (S,shortPath) Vs. theta

    x3 = { si_n90.(cGroup).SpMatrix.theta, si_n90.(p1Group).SpMatrix.theta, si_n90.(p2Group).SpMatrix.theta };
    y3 = { si_n90.(cGroup).SpMatrix.controlData.D_theta, si_n90.(p1Group).SpMatrix.patientData.D_theta, si_n90.(p2Group).SpMatrix.patientData.D_theta };
    yErr3 = { si_n90.(cGroup).SpMatrix.controlData.DStd_theta, si_n90.(p1Group).SpMatrix.patientData.DStd_theta, si_n90.(p2Group).SpMatrix.patientData.DStd_theta };
    legVal = [ 'Controls; $N=90$', strrep(groupLegend(2:end),'_','-') ];
    ps1 = getPlotStruct(x3,y3,yErr3,'Threshold, $\theta$', 'Avg Hamming dist., $\langle D(S,P)\rangle$', 'linear', 'linear', '', legVal, 1, '');
    ps2 = getPlotStruct(x3,y3,yErr3,'', '', 'linear', 'linear', '', legVal, 0, '');

    axPos = {[2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx],...
         [0.81 0.5567 0.1140625 0.36],...
         [0.5075 0.4333 0.1141 0.3600],...
         [0.2325 0.3067 0.1141 0.3600],[]};
    axProp = {{'XLim', [-0.002,0.052], 'YLim', [-512.1951 6.4878e+03]},...
         {'XLim', [0.049979 0.05003], 'YLim', [5.6617e+03 6.1799e+03], 'XTick', 0.05},...
         {'XLim', [0.0299736 0.030036], 'YLim', [1.0924e+03 1.4741e+03], 'XTick', 0.03},...
         {'XLim', [0.0099683 0.0100389], 'YLim', [-1.3723 11.9840], 'XTick', 0.01},{}};
    if isActThresh
        axProp{1} = {'XLim',[0.02,0.04],'TickLabelInterpreter','latex','XTick',[0.02,0.03,0.04],'XTickLabel',{'','$\theta_0$',''}};
        axPos(2:end) = cellfun(@(x)x,cell(size(axPos(2:end))),'UniformOutput', false);
        axProp(2:end) = cellfun(@(x)x,cell(size(axProp(2:end))),'UniformOutput', false);
    end
    if isConsensus
        axProp{1} = {'XLim',[-0.002,0.095]};
        axProp{2} = {'XLim',[0.0899176459150719 0.0900679558324272],'YLim',[7727.01434281795 7902.57122033794],'XTick',0.09};
        axProp{3} = {'XLim',[0.0598145620803203 0.0602012969718492],'YLim',[6385.28653579219 6762.83957961531],'XTick',0.06};
        axProp{4} = {'XLim',[0.0299099343039773 0.0301166104403409],'YLim',[1393.61491175887 1714.85227047392],'XTick',0.03};
    end
    [fh3,axh] = plot5AxesFigure(ps1, ps2, [ 200, 600, fp.wFig/2, fp.hFig ], axPos, axProp, fp);

    x4 = { si_n306.(cGroup).SpMatrix.theta, si_n306.(p1Group).SpMatrix.theta, si_n306.(p2Group).SpMatrix.theta };
    y4 = { si_n306.(cGroup).SpMatrix.controlData.D_theta, si_n306.(p1Group).SpMatrix.patientData.D_theta, si_n306.(p2Group).SpMatrix.patientData.D_theta };
    yErr4 = { si_n306.(cGroup).SpMatrix.controlData.DStd_theta, si_n306.(p1Group).SpMatrix.patientData.DStd_theta, si_n306.(p2Group).SpMatrix.patientData.DStd_theta };
    legVal = [ 'Controls; $N=306$', strrep(groupLegend(2:end),'_','-') ];
    ps1 = getPlotStruct(x4,y4,yErr4,'Threshold, $\theta$', 'Avg Hamming dist., $\langle D(S,P)\rangle$', 'linear', 'linear', '', legVal, 1, '');
    ps2 = getPlotStruct(x4,y4,yErr4,'', '', 'linear', 'linear', '', legVal, 0, '');

    axPos = {[2*fp.lMargin,fp.bMargin,2*fp.wAx,fp.hAx],...
         [0.8075 0.3834 0.1141 0.3600],...
         [0.4650 0.3900 0.1141 0.3600],...
         [0.2150 0.2767 0.1141 0.3600],[]};
    axProp = {{'XLim', [-0.002,0.052], 'YLim', [-3.2520e+03 9.6748e+04]},...
         {'XLim', [0.049979 0.05003], 'YLim', [9.1578e+04 9.2065e+04], 'XTick', 0.05},...
         {'XLim', [0.0299736 0.030036], 'YLim', [5.4380e+04 5.8104e+04], 'XTick', 0.03},...
         {'XLim', [0.0099683 0.0100389], 'YLim', [1.3034e+03 1.3924e+03], 'XTick', 0.01},{}};
    if isActThresh
        axProp{1} = {'XLim',[0.02,0.04],'TickLabelInterpreter','latex','XTick',[0.02,0.03,0.04],'XTickLabel',{'','$\theta_0$',''}};
        axPos(2:end) = cellfun(@(x)x,cell(size(axPos(2:end))),'UniformOutput', false);
        axProp(2:end) = cellfun(@(x)x,cell(size(axProp(2:end))),'UniformOutput', false);
    end
    if isConsensus
        axProp{2} = {'XLim',[0.049994279620703 0.0500056245934238],'YLim',[91914.9631846272 92593.9477654704],'XTick',0.05};
        axProp{3} = {'XLim',[0.0419366687112603 0.0420935643724173],'YLim',[85849.2294269284 88104.8312512393],'XTick',0.042};
        axProp{4} = {'XLim',[0.0299236909220041 0.030087995544938],'YLim',[47876.6271399299 50917.1453499901],'XTick',0.03};
    end
    [fh4,axh] = plot5AxesFigure(ps1, ps2, [ 600, 600, fp.wFig/2, fp.hFig ], axPos, axProp, fp);

    if saveOutputFigures
        saveFigure([fh1,fh2,fh3,fh4],...
            {fullfile(outputDir,['sptime_theta_N90',oFileSuffix]),...
            fullfile(outputDir,['sptime_theta_N306',oFileSuffix]),...
            fullfile(outputDir,['hammD_theta_N90',oFileSuffix]),...
            fullfile(outputDir,['hammD_theta_N306',oFileSuffix])}, imgFormat);
    end

end
