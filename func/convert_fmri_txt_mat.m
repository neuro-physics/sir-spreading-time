function convert_fmri_txt_mat(dirname_ptrn)
    [files, baseDir] = resolveInput(dirname_ptrn);
    for k = 1:numel(files)
        fn     = files(k).name;
        fn_new = fullfile(baseDir,regexprep(fn,'\.txt$','.mat','ignorecase'));
        fprintf(' * saving ... %s\n',fn_new);
        timeseries_rsfmri = load_txt_file(fullfile(baseDir,fn));
        save(fn_new,'timeseries_rsfmri');
    end
end

function [files, baseDir] = resolveInput(inp)
%RESOLVEINPUT Normalize input into dir-struct + base directory

    if isstruct(inp)
        files = inp;
        baseDir = '';
    elseif exist(inp,'dir') == 7
        baseDir = inp;
        files = dir(fullfile(baseDir,'*.txt'));
    elseif exist(inp,'file') == 2
        files = dir(inp);
        baseDir = fileparts(inp);
    elseif ischar(inp)
        files = dir(inp);
        baseDir = fileparts(inp);
    else
        error('convert_fmri_txt_mat:inp','Unrecognized input type');
    end
end