function n = getParamByFlag(fn, flagPtrn, flagNames)
    m = regexp(fn,flagPtrn,'match');
    if isempty(m)
        n = '';
        return;
    end
    if numel(m) > 1
        warning('found more than 1 match for flags %s in filename %s; using only first: %d', flagPtrn, fn, m{1});
    end
    m = m{1}(m{1}~='_');
    k = find(strcmp(m,flagNames(:,1)));
    n = flagNames{k,2};
end
