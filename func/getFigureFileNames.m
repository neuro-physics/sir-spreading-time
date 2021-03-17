function figNames = getFigureFileNames(outDir, baseName, figInd)
    figNames = cellfun(@(x)fullfile(outDir,[baseName,num2str(x)]),num2cell(figInd),'UniformOutput',false);
end
