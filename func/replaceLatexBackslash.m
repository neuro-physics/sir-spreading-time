function r = replaceLatexBackslash(s)
    m = regexp(s,'\$[^\$]+\$','match');
    n = strrep(m,'\','\\');
    r = s;
    for i = 1:numel(m)
        r = strrep(r,m{i},n{i});
    end
end
