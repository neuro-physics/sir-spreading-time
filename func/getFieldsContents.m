function c = getFieldsContents(s,f,ind,field,selfield,condition)
    if (nargin < 3) || isempty(ind)
        ind = [];
    end
    if (nargin < 4) || isempty(field)
        field = [];
    end
    if (nargin < 5) || isempty(selfield)
        selfield = [];
    end
    if (nargin < 6) || isempty(condition)
        condition = '';
    end
    if ~iscell(selfield)
        selfield = {selfield};
    end
    if iscell(f)
        c = cell(size(f));
        for i = 1:numel(f)
            c{i} = s.(f{i});
            if ~isempty(ind)
                c{i} = c{i}(ind);
            end
            if isstruct(c{i})
                a = [];
                for j = 1:numel(c{i})
                    if isempty(condition)
                        b = c{i}(j).(field);
                    else
                        for k = 1:numel(selfield)
                            condition = replace(condition,['$',selfield{k},'$'],['c{i}(j).',selfield{k},'']);
                        end
                        b = c{i}(j).(field)(eval(condition));
                    end
                    a((numel(a)+1):(numel(a)+numel(b))) = b;
                end
                c{i} = a;
            end
        end
    else
        c = s.(f);
    end
end