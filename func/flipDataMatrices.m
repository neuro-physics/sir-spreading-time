function d = flipDataMatrices(s, aal)
    if (nargin < 2) || isempty(aal)
        [~,~,~,aal] = aalsurfview(zeros(90,1));
    end
    d = s;
    fn = fieldnames(s);
    for i = 1:numel(fn)
%         fprintf('Flipping %s ...\n', fn{i});
        d.(fn{i}) = flipAALMatrix_rowsPerCols(s.(fn{i}), aal);
    end
end
