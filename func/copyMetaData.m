function s = copyMetaData(a,b,matchField)
% copies fields of a to b and returns the full data set
% it does not copy cases in which a.(matchField) == b.(matchField)
% the default matchField == 'Code'

    if (nargin < 3) || isempty(matchField)
        matchField = 'Code';
    end
    
    if ~isfield(a, matchField) || ~isfield(b, matchField)
        error('copyMetaData:matchField', '%s must be a field in both a and b', matchField);
    end

    sa = size(a.(matchField));
    sb = size(b.(matchField));
    bIsCol = max(sb(1),sb(2)) == sb(1);
    
    a = reshapeFields(a,sort(sa,'descend'));
    b = reshapeFields(b,sort(sb,'descend'));

    [~,iad] = setdiff(a.(matchField),b.(matchField));
    fna = fieldnames(a);
    fnb = fieldnames(b);
    fi = intersect(fna, fnb);
    fd = setdiff(fnb,fna);
    s = copyFields(a,b,fi,iad);
    s = fillDefault(s,fd, numel(iad));
    [~,iai,isi] = intersect(a.(matchField), s.(matchField));
    s = updateFields(s,isi,a,iai,fi);
    
    if ~bIsCol
        s = reshapeFields(s, sort(size(s.(matchField)),'ascend'));
    end
end

function r = updateFields(s,is,a,ia,fu)
% updates fields fu in s indexed by is, copying data from a indexed by ia
    r = s;
    for i = 1:numel(fu)
        f = fu{i};
        for j = 1:numel(is)
            n = is(j);
            m = ia(j);
            if needsUpdate(r.(f)(n))
                r.(f)(n) = updateValue(a.(f)(m));
            end
        end
    end
end

function r = updateValue(b)
    r = b;
    if iscell(b)
        if isempty(b{1})
            r{1} = '?';
        else
            r{1} = capitalizeWords(b{1});
        end
    else
        r = b;
    end
end

function r = needsUpdate(a)
    if iscell(a)
        a = a{1};
    end
    if ischar(a)
        r = strcmp(a,'?') || isempty(a) || strcmp(a, 'NA') || strcmp(a, '-666');
    else
        r = isnan(a);
    end
end

function r = fillDefault(s,fd,nEntries)
    r = s;
    for i = 1:numel(fd)
        f = fd{i};
        if iscell(r.(f)(1))
            defaultEntry = {'NA'};
        else
            defaultEntry = -666;
        end
        r.(f) = [ s.(f); repmat(defaultEntry, [nEntries,1]) ];
    end
end

function r = copyFields(a,b,fi,ia)
% copy entries indexed ia from fields fi of a to b
% keep b fields which are not in fi
    r = b;
    if isempty(ia)
        return;
    end
    for i = 1:numel(fi)
        f = fi{i};
        r.(f) = [ b.(f); a.(f)(ia) ];
    end
    
end

function r = reshapeFields(s,sp)
    fn = fieldnames(s);
    r = s;
    for i = 1:numel(fn)
        f = fn{i};
        r.(f) = reshape(r.(f), sp);
    end
end

function strout = capitalizeWords(str,forceLower)
    if (nargin < 2) || isempty(forceLower)
        forceLower = false;
    end
    if forceLower
        strout = lower(str);
    else
        strout = str;
    end
    idx = regexp([' ' str],'(?<=\s+)\S','start')-1;
    strout(idx) = upper(str(idx));
end
