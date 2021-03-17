function [fh,axh] = plotNetworkHighlight(fh,axh,A,rcInd,rA,netArgs,rcArgs)
% plots the network given by adj matrix A
% such that its nodes specified in rc vector are highlighted
    if isempty(fh)
        fh = figure;
    end
    if isempty(axh)
        axh = axes;
    end
    if (nargin < 6) || isempty(netArgs)
        netArgs = {};
    end
    if (nargin < 7) || isempty(rcArgs)
        rcArgs = {};
    end
    N = size(A,1);
    A(1:(N+1):end) = 0;
    Arc = A;
    A(rcInd,:) = 0; A(:,rcInd) = 0;
    netInd = setdiff(1:N,rcInd);
    Arc(netInd,:) = 0; Arc(:,netInd) = 0;
    
    [edgeColorNet,mfColorNet,mColorNet,mSizeNet,lineWidthNet,netArgs] = getMainParams(netArgs,[0,0,1],3,2);
    [edgeColorRC,mfColorRC,mColorRC,mSizeRC,lineWidthRC,rcArgs] = getMainParams(rcArgs,[1,0,0],3,2);
    
    plotEdges(fh,axh,rA,A, edgeColorNet,'continuous',{'Color',mColorNet,'MarkerFaceColor',mfColorNet,'MarkerSize',mSizeNet,'HideNodeList',rcInd}, ['LineWidth',lineWidthNet,netArgs],'constant');
    plotEdges(fh,axh,rA,Arc,edgeColorRC,'continuous',{'Color', mColorRC,'MarkerFaceColor', mfColorRC,'MarkerSize', mSizeRC,'HideNodeList',netInd},['LineWidth', lineWidthRC, rcArgs],'constant',false);
    daspect(axh,[1,1,1]);
    axis(axh,'off');
end

function [ec,mfc,mc,ms,lw,args] = getMainParams(args,ecDefaultValue,msDefaultValue,lwDefaultValue)
    [ec,args] = getParamValue('EdgeColor',args,true);
    if isempty(ec)
        ec = ecDefaultValue;
    end
    [mfc,args] = getParamValue('MarkerFaceColor',args,true);
    if isempty(mfc)
        mfc = ec;
    end
    [mc,args] = getParamValue('MarkerColor',args,true);
    if isempty(mc)
        mc = ec;
    end
    [ms,args] = getParamValue('MarkerSize',args,true);
    if isempty(ms)
        ms = msDefaultValue;
    end
    [lw,args] = getParamValue('LineWidth',args,true);
    if isempty(lw)
        lw = lwDefaultValue;
    end
    [lw,args] = getParamValue('LineWidth',args,true);
    if isempty(lw)
        lw = lwDefaultValue;
    end
end

function [v,c] = getParamValue(par,c,del)
    if (nargin < 3) || isempty(del)
        del = false;
    end
    k = find(strcmpi(c,par));
    if isempty(k)
        v = [];
        return;
    end
    if k == numel(c)
        error(['missing parameter value for ', par]);
    end
    v = c{k+1};
    if del
        c(k:(k+1)) = [];
    end
end
