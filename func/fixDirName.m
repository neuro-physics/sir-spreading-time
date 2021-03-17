function d = fixDirName(n)
    if isempty(n)
        d = ['.',filesep];
        return;
    end
    if (n(end) ~= filesep)
        n = [ n, filesep ];
    end
    if (n(1) ~= filesep) && isempty(strfind(n(1:min(3,numel(n))), ':\')) % if it is not an absolute path
        if (n(1) ~= '.')
            n = fullfile('.',n);
        end
    end
    d = n;
end
