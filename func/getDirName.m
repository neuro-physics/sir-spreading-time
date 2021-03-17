function d = getDirName(p)
    if p(end) == filesep
        p(end) = [];
    end
    if exist(p, 'dir') == 7
        [~,d1,d2]=fileparts(p);
        d = [d1,d2];
        return
    end
    [ d, ~, ~ ] = fileparts(p);
    if ~isempty(d)
        [ ~, d1, d2 ] = fileparts(d);
        d = [ d1, d2 ];
    end
end
