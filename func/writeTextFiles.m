function writeTextFiles(fn,txt,printTxt)
    if iscell(fn)
        for i = 1:numel(fn)
            writeTextFiles_internal(fn{i},txt{i},printTxt);
        end
    else
        writeTextFiles_internal(fn,txt,printTxt);
    end
end

function writeTextFiles_internal(fn,txt,printTxt)
    if printTxt
        disp('--#--');
        disp(fn);
        disp('');
        disp(sprintf(txt));
        disp('');
        disp('');
    else
        fid = fopen(fn, 'a');
        fprintf(fid, replaceLatexBackslash(txt));
        fclose(fid);
    end
end