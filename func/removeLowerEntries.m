function [A,iRem,jRem] = removeLowerEntries(A)
    [rows,cols] = find(A);
    iRem = [];
    jRem = [];
    for k = 1:numel(rows)
        i = rows(k);
        j = cols(k);
        if (i > j) && (A(j,i) ~= 0)
            A(i,j) = 0;
            iRem(end+1) = i;
            jRem(end+1) = j;
        end
    end
end
