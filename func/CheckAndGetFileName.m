function fn = CheckAndGetFileName(n)
    if exist(n,'file') == 2
        [d,f,e] = fileparts(n);
        if ~isempty(d)
            d = [ d, filesep ];
        end
        i = 1;
        while true
            nn = [d,f,'_',num2str(i),e];
            if ~(exist(nn,'file') == 2)
                fn = nn;
                return
            end
            i = i + 1;
        end
    else
        fn = n;
    end
end
