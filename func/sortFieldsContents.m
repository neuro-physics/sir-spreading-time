function r = sortFieldsContents(s, caseNameOrder, caseNameField)
    if (nargin < 3) || isempty(caseNameField)
        caseNameField = 'caseName';
    end
    if isfield(s, caseNameField)
        c = s.(caseNameField);
        f = fieldnames(s);
        [~,~,ic] = intersect(caseNameOrder, c, 'stable');
        for i = 1:numel(f)
            l = f{i};
            if isvector(s.(l))
                if numel(s.(l)) == numel(caseNameOrder)
                    r.(l) = s.(l)(ic);
                else
                    r.(l) = s.(l);
                end
            else
                k = find(size(s.(l))==numel(caseNameOrder));
                if isempty(k)
                    r.(l) = s.(l);
                else
                    if any(k==1)
                        r.(l) = s.(l)(ic,:);
                    end
                    if any(k==2)
                        r.(l) = s.(l)(:,ic);
                    end
                end
            end
        end
    else
        error('processSpreadingData:sortFieldsContents','%s is not a field of data struct',caseNameField);
    end
end