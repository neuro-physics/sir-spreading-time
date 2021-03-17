function r = flip_struct(s,flipInd,N)
    r=s;
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    f = fieldnames(s);
    f((~cellfun(@(x)iscell(s.(x)),f)) & cellfun(@(x)all(size(s.(x))~=[N,N]),f) ) = []; % removing non-cell fields
    f(strcmpi(f,'richClub')) = [];
    kLeft = [];
    kRight = [];
    for i = 1:numel(f)
        l = f{i}; % for each field of the input data struct s
        if iscell(s.(l)) && any(size(s.(l){1}) == [N,N])
            if any(~cellfun(@isempty,s.(l))) % if there is any content in the cell array s.(l)
                [r.(l),kLeft,kRight] = flipAALMatrix_rowsPerCols(s.(l),aal,flipInd,kLeft,kRight);
            else
                r.(l) = s.(l); % otherwise, keep field l intact
            end
        else
            if any(size(s.(l)) == [N,N])
                [r.(l),kLeft,kRight] = flipAALMatrix_rowsPerCols(s.(l),aal,flipInd,kLeft,kRight);
            else
                r.(l) = s.(l); % otherwise, keep field l intact
            end
        end
    end
end