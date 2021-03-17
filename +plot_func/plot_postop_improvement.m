function [fh,axh] = plot_postop_improvement(ppInfo,ppData,distField,SField,patientGroup,averageFuncPar,xLabel,yLabel)

    if (nargin < 3) || isempty(distField)
        distField = 'dr_all';
    end
    if (nargin < 4) || isempty(SField)
        SField = 'Zdr_in_all';
    end
    if (nargin < 5) || isempty(patientGroup)
        patientGroup = 'FCD_PREOP';
    end
    if (nargin < 6) || isempty(averageFuncPar)
        averageFuncPar = { 'xbinslin', 10 };
    end
    if (nargin < 7) || isempty(xLabel)
        xLabel = 'Distance';
    end
    if (nargin < 8) || isempty(yLabel)
        yLabel = 'Sp Time';
    end

    cases = ppInfo.caseName(strcmpi(ppInfo.group,patientGroup));
    nC = numel(cases);

    xx = cell(1,2*nC);
    yy = cell(1,2*nC);
    xxStd = cell(1,2*nC);
    yyStd = cell(1,2*nC);
    legVal = cell(size(xx));

    i = 1;
    k = 0;
    pInd_all = [];
    cInd_all = [];
    for i = 1:2:(2*nC)
        k = k + 1;
        cn = getCaseNumber(cases{k});
        cInd = find(strcmpi(ppInfo.group,['NC_',cn]));
        pInd = find(strcmpi(ppInfo.caseName,cases{k}));
        pInd_all((numel(pInd_all)+1):(numel(pInd_all)+numel(pInd))) = pInd;
        cInd_all((numel(cInd_all)+1):(numel(cInd_all)+numel(cInd))) = cInd;
        legVal{i} = cases{k};
        legVal{i+1} = ['NC_',cn];
        [xx{i},yy{i},xxStd{i},yyStd{i}] = averageFunctionData(ppData.(distField)(pInd), ppData.(SField)(pInd), averageFuncPar{:});
        [xx{i+1},yy{i+1},xxStd{i+1},yyStd{i+1}] = averageFunctionData(ppData.(distField)(cInd), ppData.(SField)(cInd), averageFuncPar{:});
    end
    
    %xP_avg = union_cell(xx(1:2:(2*nC)));
    %yP_avg = mean(matCell2Mat(yy(1:2:(2*nC))),1,'omitnan');
    
    [xP_avg,yP_avg,xP_std,yP_std] = averageFunctionData(ppData.(distField)(pInd_all), ppData.(SField)(pInd_all), averageFuncPar{:});
    [xC_avg,yC_avg,xC_std,yC_std] = averageFunctionData(ppData.(distField)(cInd_all), ppData.(SField)(cInd_all), averageFuncPar{:});
    
    [fitDataP,fitDataC,fitp,fitc,xLim] = fitData(xx(1:2:(2*nC)),yy(1:2:(2*nC)),xx(2:2:(2*nC)),yy(2:2:(2*nC)));
    
    xx = [xx,xP_avg,xC_avg,fitDataP.x,fitDataC.x];
    yy = [yy,yP_avg,yC_avg,fitDataP.y,fitDataC.y];
    xxStd = [xxStd,xP_std,xC_std,zeros(size(fitDataP.x)),zeros(size(fitDataC.x))];
    yyStd = [yyStd,yP_std,yC_std,zeros(size(fitDataP.x)),zeros(size(fitDataC.x))];
    legVal = [legVal,'Avg P','Avg C',sprintf('Fit P (%.2g)',fitp.p1),sprintf('Fit C (%.2g)',fitc.p1)];
    
    ps = getPlotStruct(xx,yy,yyStd,xLabel,strrep(yLabel,'_','\_'),'linear','linear','',legVal,[repmat([1,0],1,nC),[1,1,1,1]],'Spreading time Vs. Distance');

    fp = getDefaultFigureProperties();
    colorSet = zeros(2*nC,3);
    colorSet(1:2:end,:) = getNRows(fp.pColors,nC);
    colorSet = [ colorSet; 1,0,0; 1,0,0; 0,0,1; 0,0,1; ];
    lineSet = [repeatToComplete(fp.pLines,2*nC),'-','-','--','--'];
    symbolSet = [duplicateElements(repeatToComplete(fp.pSymbols,nC)),'nnnn'];
    widthSet = [0.5.*ones(1,2*nC),2,2,2,2];
    [fh,axh] = plotPlotStruct([], ps, lineSet, widthSet, symbolSet, colorSet, ...
            {'MarkerSize', 4, 'MarkerFaceColor', 'w'},... % plot properties
            {'ShowErrorBar', 'on', 'LineWidth', 1, 'Color', 'auto', 'Fill', 'on', 'LineStyle', 'none'},... % error properties
            {'FontSize', 8, 'Box', 'on', 'Layer', 'top', 'XLim', xLim},... % axis properties
            {'Location', 'eastoutside', 'FontSize', 8, 'Box', 'off', 'Interpreter', 'none'},... % legend properties
            {'FontSize', 11, 'YDisplacement', [0,0,0]},... % label properties
            {'FontWeight','normal','FontSize',11,'Interpreter','tex'}); % title properties
end

function [datap,datac,fitp,fitc,xLim] = fitData(xp,yp,xc,yc)
    xc = reshape(matCell2Mat(xc),[],1);
    yc = reshape(matCell2Mat(yc),[],1);
    [xc,ind] = sort(xc);
    yc = yc(ind);
    k = isnan(yc) | isnan(xc);
    xc(k) = [];
    yc(k) = [];

    xp = reshape(matCell2Mat(xp),[],1);
    yp = reshape(matCell2Mat(yp),[],1);
    [xp,ind] = sort(xp);
    yp = yp(ind);
    k = isnan(yp) | isnan(xp);
    xp(k) = [];
    yp(k) = [];

    fitc = fit(xc(:),yc(:),'poly1');
    fitp = fit(xp(:),yp(:),'poly1');
    
    xLim = minmax([xc(:)',xp(:)']);
    xLimFit = xLim;
    xLimFit(1) = xLim(1)-0.2*diff(xLim);
    xLimFit(2) = xLim(2)+0.2*diff(xLim);
    xLim(1) = xLim(1)-0.05*diff(xLim);
    xLim(2) = xLim(2)+0.05*diff(xLim);

    datap.x = xLimFit;
    datap.y = fitp(xLimFit);
    datac.x = xLimFit;
    datac.y = fitc(xLimFit);
end

function R = getNRows(M,N)
    if size(M,1) < N
        nn = floor(N/size(M,1));
        R = repmat(M,nn,1);
        n = ceil((N/size(M,1) - nn) * size(M,1));
        R = [R;M(1:n,:)];
    else
        R = M(1:N,:);
    end
end

function c = getCaseNumber(cn)
    if iscell(cn)
        c = cell(size(cn));
        for i = 1:numel(cn)
            c{i} = getCaseNumber(cn{i});
        end
    else
        c = regexp(cn,'^\d+(_|$)','match');
        if iscell(c)
            c = c{1};
        end
        if strcmp(c(end),'_')
            c(end) = [];
        end
    end
end