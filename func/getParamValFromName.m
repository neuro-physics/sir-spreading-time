function v = getParamValFromName(str, p, mStr)
    m = regexp(str, mStr, 'match');
    if isempty(m)
        v = [];
        return;
    end
    if numel(m) > 1
        warning('found more than 1 match for param %s in filename %s; using only first: %s', p, str, m{1});
    end
    m = m{1};
    m(strfind(m,p):numel(p)) = [];
    v = str2double(m);
end
