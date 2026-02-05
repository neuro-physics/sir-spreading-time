function [fh,cMap,cbh]=plot_stacked_adj_matrices(N,nMat,axDisp,dAlpha,sortNodesBy,axScale,caseName,cmapFunc,nullColor,cLim,showCBar,A)
    dataDir = 'D:\Dropbox\p\postdoc\data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 1) || isempty(N)
        N = 90;
    end
    if (nargin < 2) || isempty(nMat)
        nMat = 5;
    end
    if (nargin < 3) || isempty(axDisp)
        axDisp = 0.01;
    end
    if (nargin < 4) || isempty(dAlpha)
        dAlpha = 0.2;
    end
    if (nargin < 5) || isempty(sortNodesBy)
        sortNodesBy = 'lobe'; % 'lobe' or 'func'
    end
    if (nargin < 6) || isempty(axScale)
        axScale = 0.5;
    end
    if (nargin < 7) || isempty(caseName)
        caseName = '';
    end
    if (nargin < 8) || isempty(cmapFunc)
        cmapFunc = @hot;
    end
    if (nargin < 9) || isempty(nullColor)
        nullColor = 0.9.*ones(1,3);
    end
    if (nargin < 10) || isempty(cLim)
        cLim = [];
    end
    if (nargin < 11) || isempty(showCBar)
        showCBar = true;
    end
    if (nargin < 12) || isempty(A)
        A = {}; % if given, this is a cell-array of adjacency matrices (ignores caseName)
    end
    %aal = load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
    [~,~,~,aal] = aalsurfview(zeros(90,1));
    
    if isempty(A)
        matDir         = ['AALmatrix_N',num2str(N)];
        [A,cn]         = loadAALMatrix(fullfile(dataDir,matDir,'selected','TLE_*FA*.mat'));
        isPatient      = ~cellfun(@isempty,regexp(cn, '^0\d{3}_\d{1}'));
        if isempty(caseName)
            A = A(~isPatient);
            A = A(randperm(numel(A),nMat));
        else
            if ~iscell(caseName)
                caseName = { caseName };
            end
            [~,~,k] = intersect(caseName,cn,'stable');
            k = repeatToComplete(k,nMat);
            A = A(k);
        end
    end
    
    [~,sc,lobeLim] = groupAALNodes(N,sortNodesBy,aal);
    hp             = createCommPattern(90,lobeLim);
    
    if isa(cmapFunc,'function_handle')
        cMap = cmapFunc(numel(A{1}));
        cMap(1,:) = nullColor;
    else
        cMap = cmapFunc;
    end
    if isempty(cLim)
        cLim = minmax(A{1}(:)');
    end

    fh = figure;
    r = fh.Position(3) / fh.Position(4);
    
    taxh = axes;
    axis(taxh,'square');
    taxh.Position = [taxh.Position(1:2),axScale.*taxh.Position(3:4)];
    drawnow
    axPos = taxh.Position;
    delete(taxh);
    
    axh = gobjects(1,nMat);
    axM = gobjects(1,nMat);
    k = -1;
    for i = 1:nMat
        axh(i) = axes('Position',axPos);
%                           plotMatrix(fh,axh   ,A          ,matrixView,elemHighlight,patternHighlight,cMap,                axProp,imgProp,elHighlightProp,...
%                                      ptrnHighlightProp);
        alpha = 1 - (i-1) * dAlpha;
        
        [~,~,ih,~,axM(i),cbh1] = plotMatrix(fh,axh(i),A{i}(sc,sc),    'full',           [],              hp,cMap, {'ShowColorBar',showCBar},     [],             [],...
                                       {'Type','contour','Alpha',0.4,'LineStyle','-','LineWidth',0.5,'Color',0.01.*ones(1,3)},...
                                       {'ColorLim', cLim});

        if alpha <= 0
            k = i;
            break;
        end
        ih.AlphaData = alpha;
%         axM(i) = createPatternHighlight(fh,axh(i),hp,0.6,[0,0,0;1,1,1]);
        axh(i).XTick  = [];
        axh(i).YTick  = [];
        axh(i).XColor = [0,0,0,alpha];
        axh(i).YColor = [0,0,0,alpha];
        axh(i).Layer  = 'top';
        axh(i).Position(1) = axh(i).Position(1) + axDisp*(i>1);
        axh(i).Position(2) = axh(i).Position(2) + axDisp*r*(i>1);
%         axM(i).Position = axh(i).Position;
        axPos = axh(i).Position;
        drawnow
        showCBar = false; % show only colorbar for 1st axis
        if i == 1
            cbh = cbh1;
        end
    end
    if (k>0)
        axh(k:end) = [];
%         axM(k:end) = [];
    end
    for i = numel(axh):-1:1
        if isa(axh(i),'matlab.graphics.GraphicsPlaceholder')
            continue;
        end
        axes(axh(i));
        axes(axM(i));
    end
    p = axh(1).Position;
    cbh.Location = 'westoutside';
    axh(1).Position = p;
end

function a = createPatternHighlight(fh,axh,p,alpha,cMap)
    a = copyobj(axh,fh);
    cla(a);
    imagesc(a, p, 'AlphaData', alpha.*p);
%     h.AlphaData = 0.2.*p;
    colormap(a,cMap);
    axis(a, 'square');
    axis(a, 'off');
end
