function [fh, axh, colorMatrix] = plotEdges(fh,axh,r,A,colorArr,colorMode,posArgs,edgeArgs,widthMode,brainShade,brainColor,onlyAddEdgesToAxes,lightPos,Gdb,contourLevel,contourArgs)
    A(1:(size(A,1)+1):end) = 0; % removing main diagonal elements
    if isempty(fh)
        fh = figure;
    end
    if (nargin < 2) || isempty(axh)
        axh = axes;
    end
    if (nargin < 5) || isempty(colorArr)
        AA=A(A~=0);
        colorArr = autumn(numel(unique(AA(:))));
    end
    if (nargin < 6) || isempty(colorMode)
        colorMode = 'continuous'; % or 'discrete'
    end
    if (nargin < 7) || isempty(posArgs)
        posArgs = {};
    end
    if (nargin < 8) || isempty(edgeArgs)
        edgeArgs = {};
    end
    if (nargin < 9) || isempty(widthMode)
        widthMode = 'proportional'; % or 'constant'
    end
    if (nargin < 10) || isempty(brainShade)
        brainShade = 0.3;
    end
    if (nargin < 11) || isempty(brainColor)
        brainColor = [0.95,0.95,0.95];
    end
    if (nargin < 12) || isempty(onlyAddEdgesToAxes)
        onlyAddEdgesToAxes = false;
    end
    if (nargin < 13) || isempty(lightPos)
        lightPos = [];
    end
    if (nargin < 14) || isempty(Gdb)
        Gdb = [];
    end
    if (nargin < 15) || isempty(contourLevel)
        contourLevel = [];
    end
    if (nargin < 16) || isempty(contourArgs)
        contourArgs = {};
    end
    if ~onlyAddEdgesToAxes
        if brainShade
            [fh,axh] = plotBrainSurf(fh,axh,brainColor,brainShade,lightPos,[],contourLevel,contourArgs);
        end
        if isempty(Gdb)
            [fh,axh] = plot3DPosition(fh,axh,r,ones(size(A,1),1),posArgs,colorArr,colorMode,[],'o','value');
        else
            n = struct2table(Gdb.nodes);
            r = [n.x,n.y];
            [fh,axh] = plot3DPosition(fh,axh,r,ones(size(A,1),1),posArgs,colorArr,colorMode,[],'o','value');
        end
    end
    [fh,axh,colorMatrix] = plotEdges_internal(fh,axh,r,A,colorArr,colorMode,edgeArgs,widthMode,Gdb);
end

function [fh,axh,colorMatrix] = plotEdges_internal(fh,axh,r,A,colorArr,colorMode,edgeArgs,widthMode,Gdb)
    if strcmpi(colorMode, 'discrete')
        getColor = @(ii,xx)getPColor_discrete(ii,colorArr);
    elseif strcmpi(colorMode, 'continuous')
        %mm = minmax(values(:)');
        AA = A(A~=0);
        mmColor = minmax(AA(:)');
        getColor = @(ii,xx)getPColor_continuous(xx,colorArr,mmColor);
    else
        error('plotParcelPosition:colorMode','unrecognized colorMode parameter');
    end
    
    [mmLineWidth,edgeArgs] = getParamValue('LineWidthLim',edgeArgs,true);
    if isempty(mmLineWidth)
        mmLineWidth = [ 2, 11 ];
    end
    [lineWidth,edgeArgs] = getParamValue('LineWidth',edgeArgs,true);
    if isempty(lineWidth)
        lineWidth = mmLineWidth(1);
    end
    [edgeAlpha,edgeArgs] = getParamValue('EdgeAlpha',edgeArgs,true);
    if isempty(edgeAlpha)
        edgeAlpha = 1;
    end
    if strcmpi(widthMode, 'constant')
        getLineWidth = @(xx)lineWidth;
    elseif strcmpi(widthMode, 'proportional')
        AA = A(A~=0);
        mmData = minmax(AA(:)');
        getLineWidth = @(xx)getLineWidth_continuous(xx,mmData,mmLineWidth);
    else
        error('plotParcelPosition:colorMode','unrecognized colorMode parameter');
    end
    if isempty(Gdb)
        colorMatrix = zeros(size(A,1),size(A,2),3);
        hold(axh,'on');
        N = size(A,1);
        for i = 1:N
            for j = 1:N
                if A(i,j) ~= 0
                    eColor = getColor(i+(j-1)*N, A(i,j));
                    colorMatrix(i,j,:) = reshape(eColor,1,1,numel(eColor));
                    pArgs = [ edgeArgs, 'Color', [eColor,edgeAlpha], 'LineWidth', getLineWidth(A(i,j)) ];
                    xyz = [ r(i,1), r(j,1); r(i,2), r(j,2); r(i,3), r(j,3) ];
                    line(xyz(1,:),xyz(2,:),xyz(3,:),pArgs{:});
                end
            end
        end
    else
        [i_list,j_list] = find(tril(A,-1));
        colorMatrix = zeros(size(A,1),size(A,2),3);
        hold(axh,'on');
        N = size(A,1);
        for k = 1:numel(i_list)
            i = i_list(k);
            j = j_list(k);
            if A(i,j) ~= 0%if ~isempty(Gdb.edges{i,j})
                eColor = getColor(i+(j-1)*N, A(i,j));
                colorMatrix(i,j,:) = reshape(eColor,1,1,numel(eColor));
                pArgs = [ edgeArgs, 'Color', [eColor,edgeAlpha], 'LineWidth', getLineWidth(A(i,j)) ];
                line(Gdb.edges{i,j}.x,Gdb.edges{i,j}.y,pArgs{:});
            end
        end
    end
    hold(axh,'off');
end

function w = getLineWidth_continuous(xx, mmDomain, mmImage)
    if (mmDomain(1) < 0) && (mmDomain(2) < 0)
        if (mmDomain(2) > mmDomain(1))
            temp = mmDomain(1);
            mmDomain(1) = mmDomain(2);
            mmDomain(2) = temp;
        end
    end
    dw = mmImage(2) - mmImage(1);
    dx = mmDomain(2) - mmDomain(1);
    if dx == 0
        dx = 1;
    end
    a = dw / dx;
    b = mmImage(1)-a*mmDomain(1);
    w = a.*xx+b;
end

function s = getPColor_discrete(ii, colorSet)
    s = colorSet(int32(mod(int32(ii)-1,int32(round(numel(colorSet)/3))))+1,:);
end

function s = getPColor_continuous(xx, colorSet, mm)
    dy = size(colorSet,1)-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    k = round(a.*xx+b)+1;
    if k < 1
        k = 1;
    end
    if k > size(colorSet,1)
        k = size(colorSet,1);
    end
    s = colorSet(k,:);
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
