function d = processSimDataGroups(inp,outputFileName,groupSide,useFieldName)
    if (nargin < 2) || isempty(outputFileName)
        outputFileName = '';
    end
    if (nargin < 3) || isempty(groupSide)
        groupSide = 'All';
    end
    if (nargin < 4) || isempty(useFieldName)
        useFieldName = 'UseForSpSim';
    end
    if ~iscell(groupSide)
        groupSide = { groupSide };
    end

    si = load(inp);
    
    groupNames = getGroupName_cell(groupSide);
    d = cell2struct(cell(size(groupNames)), groupNames, 2);

    for i = 1:numel(groupNames)
        g = groupNames{i};

        k = getGroupIndices(si.caseName,groupSide{i},useFieldName);

        d.(g) = getGroupData(si,k);
    end
    
    if ~isempty(outputFileName)
        save(outputFileName, '-struct', 'd', '-v7.3');
    end
end

function s = getGroupData(s,groupInd)
    N = numel(s.caseName);
    delInd = setdiff(1:N,groupInd);
    s.caseName(delInd) = [];
    f = fieldnames(s);
    f(strcmpi(f,'caseName')) = [];
    for i = 1:numel(f)
        dataField = f{i};
        g = fieldnames(s.(dataField));
        g = g(strcmpi(g,'data') | strcmpi(g,'flipData') | strcmpi(g,'zControlData')); % selecting only these fields from the fields of s.(dataField)
        h = fieldnames(s.(dataField)(1).data);
        for j = 1:numel(s.(dataField))
            for k = 1:numel(g)
                l = g{k};
                if ~isempty(s.(dataField)(j).(l))
                    for n = 1:numel(h)
                        m = h{n};
                        if ~isempty(s.(dataField)(j).(l).(m))
                            if iscell(s.(dataField)(j).(l).(m)) && (numel(s.(dataField)(j).(l).(m)) == N)
                                s.(dataField)(j).(l).(m)(delInd) = [];
                            end
                        end
                    end
                end
            end
        end
    end
end

function k = getGroupIndices(caseName,sd,useFieldName)
    if strcmpi(sd,'All')
        k = (1:numel(caseName))';
        return;
    end
    [kP,kC,~,~] = getCasesIndices(caseName,[],sd,'HS',1,useFieldName);
    if ischar(sd)
        if strcmpi(sd,'nc') || strcmpi(sd,'control') || strcmpi(sd,'controls') % controls are tagged NC
            k = kC;
        else
            k = kP;
        end
    else
        k = kP;
    end
end

function n = getGroupName_cell(gs)
    n = cell(size(gs));
    for i = 1:numel(gs)
        n{i} = getGroupName(gs{i});
    end
end

function n = getGroupName(gs)
    if ischar(gs)
        if strcmpi(gs,'nc')
            n = 'Controls';
            return;
        end
        n = gs;
        return;
    end
    n = [getGroupSideChar(gs),'TLE'];
end

function c = getGroupSideChar(sd)
    c = sort(strjoin(strrep(sd,'TLE',''),''));
end
