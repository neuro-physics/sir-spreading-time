function [T_con,T_pat] = selectCasesFromPatientStruct(s,controlCodeOrder,patientCodeOrder,asTable)
    if (nargin < 4) || isempty(asTable)
        asTable = '';
    end
    if isempty(asTable)
        asTableFlag = false;
    else
        asTableFlag = strcmpi(asTable,'astable');
    end
    ind = getPatientIndex(s, 'UseForSpSim', {1}, 'AND');
    T = struct2table(s);
    T = T(ind,:);
    T_con = T(strcmpi(T.Group,'NC'),:);
    T_pat = T(~strcmpi(T.Group,'NC'),:);
    [~,k] = setdiff(T_con.Code,controlCodeOrder);
    if ~isempty(k)
        T_pat(k,:) = [];
    end
    [~,k] = setdiff(T_pat.Code,patientCodeOrder);
    if ~isempty(k)
        T_pat(k,:) = [];
    end
    T_con = sortFieldsContents(table2struct(T_con,'ToScalar',true),controlCodeOrder,'Code');
    T_pat = sortFieldsContents(table2struct(T_pat,'ToScalar',true),patientCodeOrder,'Code');
    if asTableFlag
        T_con = struct2table(T_con);
        T_pat = struct2table(T_pat);
    end
end