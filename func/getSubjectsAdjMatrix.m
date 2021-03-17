function [c,p] = getSubjectsAdjMatrix(inputPattern, patientGroup, patientHipPath, nedaSelected)
    [cf,pf] = getSubjectsFiles(inputPattern, patientGroup, patientHipPath, nedaSelected);
    c = getMatrix(cf);
    p = getMatrix(pf);
end

function A = getMatrix(f)
    A = cell(1,numel(f));
    for i = 1:numel(f)
        A{i} = getMatrix_internal(f{i});
    end
end

function A = getMatrix_internal(f)
    a = load(f);
    if isfield(a, 'matrix')
        A = a.matrix;
    else
        A = a;
    end
end
