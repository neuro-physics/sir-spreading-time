function [fh,axh,cb,aal,aalParcelLab,sh,subh] = aalsurfview(values, titleTxt, colorArr, colorMode, colorLim, showSymbolLegend, fhp, axR0, alphaValues, mask, forceColorLim, showSymbols, surfstat_inflate_w)
    %load template surface
    %surf = SurfStatReadSurf('/host/weka/export02/data/min/TLEcheckCT/template.obj');
    %surf = SurfStatReadSurf('D:\Dropbox\p\postdoc\data\AAL_data\template_surf\cortex_template.obj');
    %load vertex-wise label
    %load('/data/noel/noel6/min/01_project/WMnetwork/scripts/AALlabel.mat')
    %load('D:\Dropbox\p\postdoc\data\AAL_data\template_surf\surf_labels.mat')

    if (nargin < 1) || isempty(values)
        error('aalsurfview:values','values must be set');
    end
    if (nargin < 2) || isempty(titleTxt)
        titleTxt = '';
    end
    if (nargin < 3) || isempty(colorArr)
        colorArr = jet(1+numel(unique(values))); % or 'continuous'
    end
    if (nargin < 4) || isempty(colorMode)
        colorMode = 'continuous'; % or 'discrete'
    end
    if (nargin < 5)
        colorLim = [];
    end
    if (nargin < 6) || isempty(showSymbolLegend)
        showSymbolLegend = 1;
    end
    if (nargin < 7)
        fhp = [];
    end
    if (nargin < 8)
        axR0 = [];
    end
    if (nargin < 9) || isempty(alphaValues)
        alphaValues = ones(size(values));
    end
    if (nargin < 10) || isempty(mask)
        mask = ones(size(values));
    end
    if (nargin < 11) || isempty(forceColorLim)
        forceColorLim = false;
    end
    if (nargin < 12) || isempty(showSymbols)
        showSymbols = true;
    end
    if (nargin < 13) || isempty(surfstat_inflate_w)
        surfstat_inflate_w = NaN;
    end
    dataDir = 'D:\Dropbox\p\postdoc\data\AAL_data';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data/AAL_data';
    end
    if ~(exist(dataDir,'dir') == 7)
        dataDir = fullfile('.','aux_files');
    end
    aal = load(fullfile(dataDir,'aal_cortex_map_olf294_fix.mat'));

    %load label and colortable
    N = numel(values);
    switch N
        case 90
            l = aal.map.AAL90;
            aalParcelLab = 'AAL90';
        case 306
            l = aal.map.AAL306;
            aalParcelLab = 'AAL306';
        case 78
            l = aal.map.AAL78remap;
            aalParcelLab = 'AAL78remap';
        case 294
            l = aal.map.AAL294;
            aalParcelLab = 'AAL294';
        case 9
            l = aal.map.AAL09comm;
            aalParcelLab = 'AAL09comm';
        otherwise
            error('aalsurfview:values','Do not recognize the matrix size.');
    end
    if (nargin == 1) && all(values==0)
        fh = []; axh = []; cb = [];
        return;
    end

%     hasMask = any(mask ~= 1);
%     if hasMask
%         nC = size(colorArr,1);
%         values = getColorIndex(values,nC);
%         colorArr_desat = rgb2hsv(colorArr);
%         colorArr_desat(ci,2) = colorArr_desat(ci,2) .* reshape(mask(kv),[],1);
%         colorArr_desat = hsv2rgb(colorArr_desat);
%         km = find(mask~=1);
%         values(km) = nC + km;
%         colorArr = [colorArr;colorArr_desat];

%         values = getColorIndex(values,size(colorArr,1));
%         [ci,kv] = unique(getColorIndex(values,size(colorArr,1))); % ci -> in the space of values; k -> in the space of values' indices
%         colorArr = [1,1,1;repmat([0,0,0],numel(ci),1)];
%         values = getColorIndex(values,numel(ci));
%         colorArr(ci,:) = repmat([0,0,0],numel(ci),1);
%         colorArr = rgb2hsv(colorArr);
%         colorArr(ci,2) = colorArr(ci,2) .* 0.2;%reshape(mask(kv),[],1);
%         colorArr = hsv2rgb(colorArr);
%     end
    
    s = zeros(size(l));
    a = ones(size(l));
    for i = 1:N
        ind = l==i;
        s(ind) = values(i);
        a(ind) = alphaValues(i);
    end
    if ~all(alphaValues == 1)
        a(l==0) = min(alphaValues);
    end
    
    % BoSurfStatViewData(data,surf,fp,titleTxt,cMap,fhp,axR0)
    if ~isempty(fhp)
        axh1 = fhp.Children;
        cMap1 = fhp.Colormap;
    end
%     [fh,axh,cb,sh] = BoSurfStatViewData(s, aal.surf, [], [titleTxt, ', $N=',num2str(N),'$'], [], fhp, axR0, a, colorMode);
    if ~isnan(surfstat_inflate_w) && (surfstat_inflate_w>0)
        try
            aal.surf = SurfStatInflate(aal.surf,surfstat_inflate_w);
        catch
            warning('aalsurfview:Inflate','Error inflating... maybe you dont have SurfStat');
        end
    end
    [fh,axh,cb,sh] = BoSurfStatViewData(s, aal.surf, [], titleTxt, [], fhp, axR0, a, colorMode);
    
    if isempty(fhp)
        colormap(fh,colorArr);
    else
        if all(size(colorArr)==size(cMap1)) && all(all(colorArr==cMap1))
            colormap(fh,colorArr);
        else
            for i = 1:numel(axh)
                colormap(axh(i),colorArr);
            end
            for i = 1:numel(axh1)
                colormap(axh1(i),cMap1);
            end
        end
    end
    for i = 1:numel(axh)
        mm = minmax(double(values(:)'));
        if (mm(1) == mm(2))
            mm = [0,1];
        end
        if ~isempty(colorLim)
            mm = colorLim;
        end
        cl = mm;
        if ~forceColorLim
            if all(cl>0)
                cl = [0,mm(2)];
            elseif all(mm<0)
                cl = [mm(1),0];
            else
                cl = mm;
            end
        end
        axh(i).CLim = cl;
    end
    
    if strcmpi(colorMode,'discrete')
        cb.Ticks = linspace(1,size(colorArr,1),5);
        cb.TickLabels = num2str(linspace(cl(1),cl(2),5)','%.2g');
    end

    subh = gobjects(1,0);
    if showSymbols && any(N == [9,90,306])
        if N == 90
            al = 'AAL90';
            [sn,indS] = setdiff(aal.labels.AAL90,aal.labels.AAL78remap);
        else
            al = 'AAL306';
            [sn,indS] = setdiff(aal.labels.AAL306,aal.labels.AAL294);
        end
        %if any(values(indS))
        kL = cellfun(@(x)~isempty(x),strfind(sn,'_L'));
        kR = cellfun(@(x)~isempty(x),strfind(sn,'_R'));
        rL = aal.pos.(al)(indS(kL),:);
        rR = aal.pos.(al)(indS(kR),:);
        rL(:,1)=0;
        rR(:,1)=0;
        rL(:,3)=rL(:,3)+20;
        rR(:,3)=rR(:,3)+20;
        rL(:,2)=rL(:,2)-5;
        rR(:,2)=rR(:,2)-5;
        rL(3:end,2)=rL(3:end,2)-5; % displacing all but amigdala and caudate
        rR(3:end,2)=rR(3:end,2)-5; %
        rL(4,2)=rL(4,2)-5; % displacing only pallidum
        rR(4,2)=rR(4,2)-5;
        rL(1,2)=rL(1,2)-5; % displacing only amigdala
        rR(1,2)=rR(1,2)-5;
        pSymbol = 'o^svd<';
        if N == 9
            indS = find(strcmpi(aal.labels.(getAALLabel(N)),'Subcortical'));
            ss = size(rL,1);
            vL = values(indS).*ones(ss,1);
            vR = values(indS).*ones(ss,1);
        else
            vL = values(indS(kL));
            vR = values(indS(kR));
        end
        hasVL = any(vL);
        hasVR = any(vR);
        if ~hasVL
            vL = zeros(size(vL));%repmat(colorLim(1),size(vL));
        end
        if ~hasVR
            vR = zeros(size(vR));%repmat(colorLim(1),size(vR));
        end
        [~,~,subh] = plot3DPosition(fh,axh(2),rL,vL,{'MarkerSize',6},colorArr,colorMode,colorLim,pSymbol,'unique');
        [~,~,subh2] = plot3DPosition(fh,axh(3),rR,vR,{'MarkerSize',6},colorArr,colorMode,colorLim,pSymbol,'unique');
        subh = [subh(:)',subh2(:)'];
        if showSymbolLegend && isempty(fhp)
            axh(end+1) = createLegend(fh,...
                strrep(strrep(sn(kL),'_L',''),'_',' '),...
                num2cell(pSymbol),...
                num2cell(repmat('n',1,numel(pSymbol))),...
                num2cell(repmat('k',1,numel(pSymbol))),...
                {'Position', [0.0142 0.0382 0.0259 0.2152], 'Box', 'off'},... % box args
                {'Interpreter', 'tex', 'Displacement', [0,0]},... % text args
                {'MarkerSize', 5, 'MarkerFaceColor', 'w'}); % line args
        end
        %end
    end
end

function y = getColorIndex(values, nColors, mm)
    if (nargin < 3) || isempty(mm)
        mm = minmax(values(:)');
    end
    dy = nColors-1;
    dx = mm(2) - mm(1);
    if dx == 0
        dx = 1;
    end
    a = dy / dx;
    b = -a*mm(1);
    y = round(a.*values+b)+1;
    y(y<1) = 1;
    y(y>nColors) = nColors;
end