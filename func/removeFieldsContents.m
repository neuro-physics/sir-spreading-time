function s = removeFieldsContents(s, remCaseNames)
    if isfield(s, 'caseName')
        c = s.caseName;
        nC = numel(c);
        f = fieldnames(s);
        [~,~,ic] = intersect(remCaseNames, c, 'stable');
        for i = 1:numel(f)
            l = f{i};
            if isvector(s.(l))
                if numel(s.(l)) == nC
                    s.(l)(ic) = [];
                end
            else
                k = find(size(s.(l))==nC);
                if ~isempty(k)
                    if any(k==1)
                        s.(l)(ic,:) = [];
                    end
                    if any(k==2)
                        s.(l)(:,ic) = [];
                    end
                end
            end
        end
    else
        error('processSpreadingData:sortFieldsContents','caseName is not a field of data struct');
    end
end