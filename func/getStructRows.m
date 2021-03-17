function T = getStructRows(T,matchField,selVal,keepOrder)
    if keepOrder
        % keep order of original struct
        [~,k] = intersect(T.(matchField),selVal,'stable');
    else
        % keep order of selVal set
        [~,~,k] = intersect(selVal,T.(matchField),'stable');
    end
    T = struct2table(T);
    T = mytable2struct(T(k,:));
end