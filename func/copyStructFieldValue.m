function s = copyStructFieldValue(s,fields,indFrom,indTo)
% copies values from the positions indFrom to positions indTo for all the specified fields in struct s
    if ~iscell(fields)
        fields = { fields };
    end
    if numel(indTo) ~= numel(indFrom)
        error('indTo and indFrom must have the same size')
    end
    indFrom = indFrom(:);
    indTo = indTo(:);
    mm = max([indFrom;indTo]);
    for i = 1:numel(fields)
        f = fields{i};
        if numel(s.(f)) < mm
            error('field %s does not contain some required indices',f)
        end
        s.(f)(indTo) = s.(f)(indFrom);
    end
end