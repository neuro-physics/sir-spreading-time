function r = isCellOfEmpty(c)
    r = all(reshape(cellfun(@isempty,c),[],1));
end