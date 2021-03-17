function [g,k,lobeLimLR,lobeLabelsLR,lobeIndLR,lobeInd] = groupAALNodes(N_aalLabels_commInd,groupType,aal)
    N = 0;
    if (nargin < 1) || isempty(N_aalLabels_commInd)
        N = 90;
    end
    if (nargin < 2) || isempty(groupType)
        groupType = 'lobe'; % 'lobe' or 'func' or 'funclr'
        % if 'lobe', aalLabels must be the aal labels to sort
        % if 'func', aalLabels must be the vector of functional community indices
        % if first argument is not provided, aal data struct is loaded
    end
    if (nargin < 3) || isempty(aal)
        if ~(strcmpi(groupType,'lobe') && iscell(N_aalLabels_commInd))
            [~,~,~,aal] = aalsurfview(zeros(90,1));
        else
            aal = [];
        end
    end
    if isvector(N_aalLabels_commInd) && isnumeric(N_aalLabels_commInd) && (numel(N_aalLabels_commInd) == 1)
        N = N_aalLabels_commInd;
    end
    if isvector(N_aalLabels_commInd) && isnumeric(N_aalLabels_commInd) && (numel(N_aalLabels_commInd) > 1)
        warning('forcing groupType == func');
        groupType = 'func';
    end
    if strcmpi(groupType,'lobe')
        if iscell(N_aalLabels_commInd)
            arg = N_aalLabels_commInd;
        else
            arg = aal.labels.(getAALLabel(N));
        end
        [g,k,lobeLimLR,lobeLabelsLR,lobeIndLR,lobeInd] = groupAALNodes_lobe(arg);
    elseif strcmpi(groupType,'func') || strcmpi(groupType,'funclr')
        if iscell(N_aalLabels_commInd)
            N = numel(N_aalLabels_commInd);
            if isempty(aal)
                [~,~,~,aal] = aalsurfview(zeros(90,1));
            end
        end
        if N == 0
            arg = N_aalLabels_commInd;
        else
            arg = aal.comm.(getAALLabel(N));
        end
        [g,k,lobeLimLR,lobeLabelsLR,lobeIndLR,lobeInd] = groupAALNodes_func(arg,aal,strcmpi(groupType((end-1):end),'lr'));
    else
        error('unrecognized groupType, must be lobe or func or funclr')
    end
end

function [g,k,lobeLimLR,lobeLabelsLR,lobeIndLR,lobeInd] = groupAALNodes_func(cInd,aal,isLR)
    if isempty(aal)
        [~,~,~,aal] = aalsurfview(zeros(90,1));
    end
    N = numel(cInd);
    lab = getAALLabel(N);
    
    u = unique(cInd);
    if isLR
        sl = [];
        sr = [];
        lll = [];
        llr = [];
        [~,lInd,rInd] = sortAALNodes('lr',[],[],aal.labels.(lab));
        for i = 1:numel(u)
            kInd = reshape(cInd == u(i),size(lInd));
            l = find(lInd & kInd);
            sl((numel(sl)+1):(numel(l)+numel(sl))) = l;
            r = find(rInd & kInd);
            sr((numel(sr)+1):(numel(r)+numel(sr))) = r;
            lll(end+1) = numel(sl);
            llr(end+1) = numel(sr);
        end
        k = [sl(:);sr(:)];
        lobeLimLR = [ lll(:); (llr(:)+numel(sl)) ];
    else
        [cIndSort,k] = sort(cInd);
        lobeLimLR = zeros(numel(u),1);
        for i = 1:numel(u)
            lobeLimLR(i) = find(cIndSort == u(i),1,'last');
        end
    end
    g = aal.labels.(lab)(k);
    lobeLabelsLR = aal.labels.AAL09comm;

    lobeIndLR = cell(size(lobeLimLR));
    lobeLim2 = [ 0; lobeLimLR(:) ];
    for i = 1:(numel(lobeLim2)-1)
        lobeIndLR{i} = (lobeLim2(i)+1):lobeLim2(i+1);
    end
    
    if isLR
        lobeInd = cell(1,numel(lobeLimLR)/2);
        for i = 1:numel(lobeInd)
            j = numel(lobeInd)+i;
            lobeInd{i} = [ lobeIndLR{i}, lobeIndLR{j} ];
        end
    else
        lobeInd = lobeIndLR;
    end
end

function [g,k,lobeLimLR,lobeLabelsLR,lobeIndLR,lobeInd] = groupAALNodes_lobe(aalLabels)
    keywords = { {'Frontal_Inf_Orb','Frontal_Med_Orb','Frontal_Mid_Orb','Frontal_Sup_Orb','Frontal_Inf_Oper','Frontal_Inf_Tri','Frontal_Sup_Medial','Frontal_Mid','Frontal_Sup','Precentral','Rolandic_Oper','Supp_Motor_Area','Paracentral_Lobule','Olfactory','Rectus'},...
                 {'Parietal_Inf','Parietal_Sup','Postcentral','SupraMarginal','Angular','Precuneus'},...
                 {'Temporal_Pole','Insula','Cingulum_Ant','Cingulum_Mid','Cingulum_Post','Hippocampus','ParaHippocampal'},...
                 {'Amygdala','Caudate','Putamen','Pallidum','Thalamus'},...
                 {'Occipital_Inf','Occipital_Mid','Occipital_Sup','Calcarine','Cuneus','Lingual','Fusiform'},...
                 {'Temporal_Inf','Temporal_Mid','Temporal_Sup','Heschl'} };
    lobeLabelsLR = { 'Frontal_L', 'Parietal_L', 'Limbic_L', 'Subcortical_L', 'Occipital_L', 'Temporal_L', ...
                     'Frontal_R', 'Parietal_R', 'Limbic_R', 'Subcortical_R', 'Occipital_R', 'Temporal_R' };
    [~,lInd,rInd] = sortAALNodes('lr',[],[],aalLabels);
%     lLab = aalLabels(lInd);
%     rLab = aalLabels(rInd);
%     sl = zeros(size(lInd));
%     sr = zeros(size(rInd));
    labFree = true(size(aalLabels));
    sl = [];
    sr = [];
    lll = [];
    llr = [];
    m = numel(keywords); % m -> number of lobes; n -> number of search patterns
    for i = 1:m % for each lobe
        n = numel(keywords{i});
        for j = 1:n
            kInd = reshape(cellfun(@(x)~isempty(x),strfind(aalLabels, keywords{i}{j})) & labFree,size(lInd)); % finding indices of aalLabels that match keyword j of lobe i and are not assigned
            l = find(lInd & kInd);
            sl((numel(sl)+1):(numel(l)+numel(sl))) = l;
            r = find(rInd & kInd);
            sr((numel(sr)+1):(numel(r)+numel(sr))) = r;
            labFree([l(:);r(:)]) = false;
        end
        lll(end+1) = numel(sl);
        llr(end+1) = numel(sr);
    end
    k = [ sl(:); sr(:) ];
    g = aalLabels(k);
    lobeLimLR = [ lll(:); (llr(:)+numel(sl)) ];
    lobeIndLR = cell(size(lobeLimLR));
    lobeInd = cell(1,numel(lobeLimLR)/2);
    lobeLim2 = [ 0; lobeLimLR(:) ];
    for i = 1:(numel(lobeLim2)-1)
        lobeIndLR{i} = (lobeLim2(i)+1):lobeLim2(i+1);
    end
    for i = 1:numel(lobeInd)
        j = numel(lobeInd)+i;
        lobeInd{i} = [ lobeIndLR{i}, lobeIndLR{j} ];
    end
    if isempty(k)
        k = 1:numel(aalLabels);
        g = aalLabels;
        lobeLimLR = k;
        lobeIndLR = k;
    end
end
