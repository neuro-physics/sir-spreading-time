function [r,codes] = IsPatient(fileNames)
    r = false(size(fileNames));
    codes = regexp(fileNames, '\d{3,4}_\d{1}', 'match', 'once');
    for i = 1:numel(codes)
        if codes{i}(1) == '0'
            r(i) = true;
        end
    end
end
%a=
