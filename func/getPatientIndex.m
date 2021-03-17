function [ind,cases] = getPatientIndex(casesMetaData,field,value,op)
% phenotypes is a substruct of main functional network data struct
% containing fields: Age, Code, Duration, Engel, FC, FU, GTCS, Group, HipPath, Onset, SZMonth, Sex, Surgery
% field must be one (or a cell of) of the fields of phenotypes structure and value must be the value of the field corresponding
% to the patients we are looking for
% if value is a vector or cellarray (in the case of str values), then ind corresponds to
% the index that matches inclusively all the values for a given field (i.e. value1 or value2 or ...)
% if field is cellarray, then value must be a cellarray with the same size of field
% each cell of value will follow the above rules for each field
% op ( 'AND' or 'OR' ) is operated over different fields;
% values are always operated with OR if multiple values are supplied for a given field
%
% Ex 1: return all indices corresponding to males that are under group RTLE or LTLE:
% k = getPatientIndex(cdb.casesMetaData, {'Sex','Group'}, {{'Male'},{'LTLE','RTLE'}},'AND')
%
% Ex 2: return all RTLE with codes 0367_1, 0369_1, 0373_1, 0374_1
% k = getPatientIndex(cdb.casesMetaData, {'Group', 'Code'}, {'RTLE',{'0367_1', '0369_1', '0373_1', '0374_1'}},'AND')
    if nargin < 1 || isempty(casesMetaData)
        %load('D:\Dropbox\p\postdoc\data\TLE_blade_data_R1FN_Min_add11HS.mat'); % inputs variable casesMetaData
        dataDir = 'D:\Dropbox\p\postdoc\data';
        if isunix
            dataDir = '/host/scarus/local_raid/mauricio/data';
        end
        load(fullfile(dataDir,'TLE_NB_BB.mat')); % inputs variable casesMetaData
    end
    if nargin < 2 || isempty(field)
        field = 'Group';
    end
    if nargin < 3 || isempty(value)
        value = 'Control';
    end
    if nargin < 4 || isempty(op)
        op = 'OR';
    end
    if ~isfield(casesMetaData, field)
        error('getPatientIndex:field','Unexistent field: %s', field);
    end
    if strcmp(op,'OR')
        opFunc = @union;
    elseif strcmp(op, 'AND')
        opFunc = @intersect;
    else
        error('getPatientIndex:op','Unrecognized operation: %s', op);
    end
    if iscell(field)
        if ~iscell(value) || numel(value) ~= numel(field)
            error('getPatientIndex:value','value must be a cell array with the same size of field');
        end
        ind = getPatientIndex_field(casesMetaData,field{1},value{1});
        for i = 2:numel(field)
            if ~ischar(field{i})
                error('getPatientIndex:field','field must be a cell of char');
            end
            ind = opFunc(ind,getPatientIndex_field(casesMetaData,field{i},value{i}));
        end
    else
        if ~ischar(field)
            error('getPatientIndex:field','field must be a char or a cell of char');
        end
        ind = getPatientIndex_field(casesMetaData,field,value);
    end
    ind = reshape(ind,1,numel(ind));
    cases = casesMetaData.Code(ind)';
end

function ind = getPatientIndex_field(phenotypes,field,value)
% phenotypes is a substruct of main functional network data struct
% containing fields: sex, code, age, onset, duration, group, fc, gtcs, szmonth, surgery, engel, hs
% field must be one of the fields of phenotypes structure and value must be the value of the field corresponding
% to the patients we are looking for
% if value is a vector or cellarray (in the case of str values), then ind corresponds to
% the index that matches inclusively all the values (i.e. value1 or value2 or ...)
    if ~ischar(value)
        if iscell(value)
            ind = findIndOfField(phenotypes.(field), value{1});
        else
            ind = findIndOfField(phenotypes.(field), value(1));
        end
        for i = 2:numel(value)
            if iscell(value)
                ind = union(ind, findIndOfField(phenotypes.(field),value{i}));
            else
                ind = union(ind, findIndOfField(phenotypes.(field),value(i)));
            end
        end
    else
        ind = findIndOfField(phenotypes.(field), value);
    end
end

function k = findIndOfField(s,v)
    if ischar(v)
        k = find(strcmpi(s,v));
        return
    else
        k = find(s==v);
        return
    end
end
