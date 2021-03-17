function writeOutputFile(fileName, fheader, M, append)
    if nargin < 4 || isempty(append)
        append = false;
    end
    if append
        if ~isempty(fheader)
            dlmwrite(fileName, fheader, 'delimiter', '', '-append');
        end
    else
        disp(['Saving ... ', fileName ]);
        if ~isempty(fheader)
            dlmwrite(fileName, fheader, 'delimiter', '');
        end
    end
    if ~isempty(M)
        if numel(size(M)) == 3
            nn = size(M,3);
            for i = 1:nn
                dlmwrite(fileName, sprintf('# i = %d',i), 'delimiter', '');
                dlmwrite(fileName, M(:,:,i), 'delimiter', ' ', 'precision', '%.8f', '-append');
                dlmwrite(fileName, sprintf('\n'), 'delimiter', ' ', 'precision', '%.8f', '-append');
            end
        else
            dlmwrite(fileName, M, 'delimiter', ' ', 'precision', '%.8f', '-append');
        end
    end
end
