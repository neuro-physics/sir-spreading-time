function [r,k] = containsCase(cn,c)
    m = cellfun(@(x)~isempty(x),strfind(cn,c));
    k = find(m);
    if isempty(k)
        r = false;
    else
        r = logical(m(k));
    end
end
