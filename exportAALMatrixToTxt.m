function exportAALMatrixToTxt(inpDirPtrn,outDir)
    [A,~,fn] = loadAALMatrix(inpDirPtrn);
    new_fn = regexprep(fn,'\.mat$','.txt');
    for i = 1:numel(A)
        f = fullfile(outDir,new_fn{i});
        fprintf('exporting ... %s\n',f);
        dlmwrite(f,A{i},' ');
    end
end