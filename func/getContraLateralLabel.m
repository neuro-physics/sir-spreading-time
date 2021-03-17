function n = getContraLateralLabel(c,m,i,aal)
% c -> aal.surf.coord
% m -> aal.map.PARCELLATION_MAP (AAL78remap, AAL90, AAL294, AAL306)
%      OR
%      string containing PARCELLATION_MAP label (AAL78remap, AAL90, AAL294, AAL306)
% i -> numeric label of the parcel to look for the contralateral part
    if (nargin < 4)
        aal = [];
    end
    if ischar(m) && isempty(aal)
        error('If m is map label, aal struct must be provided');
    end
    mapLabel = [];
    if ischar(m)
        mapLabel = m;
        m = aal.map.(mapLabel);
    end

    if isvector(i)
        n = zeros(size(i));
        for k = 1:numel(i)
            n(k) = getContraLateralLabel_internal(c,m,i(k),aal,mapLabel);
        end
    else
        n = getContraLateralLabel_internal(c,m,i,aal,mapLabel);
    end
end

function n = getContraLateralLabel_internal(c,m,i,aal,mapLabel)
    r = c(:,m==i); % get coordinates of label i
    r(1,:) = -r(1,:); % invert x (R by L) coordinate
    if isempty(r) % subcortical node
        if isempty(aal)
            error('aal struct must be provided');
        end
        if ~ischar(mapLabel) || isempty(mapLabel)
            error('aal map label must be provided as m');
        end
        if aal.labels.(mapLabel){i}(end) == 'L'
            n = find(strcmp(aal.labels.(mapLabel),regexprep(aal.labels.(mapLabel){i},'_L$','_R')));
        else
            n = find(strcmp(aal.labels.(mapLabel),regexprep(aal.labels.(mapLabel){i},'_R$','_L')));
        end
    else % cortical surface node
        [~,~,k] = intersect(r',c','rows'); % gets the indices of the coordinates that correspond to the flipped coordinates of i
        labels = m(k);
        labels=labels(labels~=0);
        n = mode(labels); % gets the label that is repeated more often
    end
end
