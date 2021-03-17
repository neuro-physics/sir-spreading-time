function G = reorgMatrixSectorLineGroup(M,secInd,numOfLines)
    m = max(cell2mat(cellfun(@(x)numel(x),secInd,'UniformOutput',false)));
    G = groupSector(M,cellfun(@(x)((x-1)*m+1):((x-1)*m+m),num2cell(1:(numel(secInd)*numOfLines)),'UniformOutput',false),'horiz');
end