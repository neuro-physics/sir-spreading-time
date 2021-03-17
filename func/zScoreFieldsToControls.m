function r = zScoreFieldsToControls(P,C,nP,nC,f)
    if (nargin < 5) || isempty(f)
        f = fieldnames(P);
    end
    r = P;
    cInd = 1:nC;
    pInd = (nC+1):(nC+nP);
    for i = 1:numel(f)
        l = f{i};
        if iscell(P.(l)) && (numel(P.(l)) == nP) && isnumeric(P.(l){1})
            s = size(P.(l){1});
            Z = zScoreToSubset([matCell2Mat(C.(l));matCell2Mat(P.(l))],cInd);
            r.(l) = reshapeLines(Z(pInd,:),s,'cell');
        end
        if isnumeric(P.(l)) && (numel(P.(l)) == nP)
            s = size(P.(l));
            Z = zScoreToSubset([C.(l)(:);P.(l)(:)],cInd);
            r.(l) = reshape(Z(pInd),s);
        end
    end
end