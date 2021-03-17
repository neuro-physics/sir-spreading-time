function [n,nCell] = shrinkStrByCapLetters(nn,nLet,keepSeparator,separator)
    if (nargin < 2) || isempty(nLet)
        nLet = 3;
    end
    if (nargin < 3) || isempty(keepSeparator)
        keepSeparator = false;
    end
    if (nargin < 4) || isempty(separator)
        separator = '';
    end
    if ischar(nn)
        nn = { nn };
    end
    n = '';
    nCell = cell(size(nn));
    nLet = nLet - 1;
    for i = 1:numel(nn)
        m = splitAndShrink_internal(nn{i},nLet,keepSeparator,separator);
        nCell{i} = m;
        n = [ n, '-', m ];
    end
    n(1)=[];
end

function s = splitAndShrink_internal(nn,nLet,keepSeparator,separator)
    if isempty(separator)
        sep = {'_','-'};
        sepJoin = '_';
    else
        sep = separator;
        sepJoin = separator;
    end
    if keepSeparator
        ss = strsplit(nn,sep);
        for i = 1:numel(ss)
            ss{i} = shrinkStrByCapLetters_internal(ss{i},nLet);
        end
        s = strjoin(ss,sepJoin);
    else
        s = shrinkStrByCapLetters_internal(nn,nLet);
    end
end

function n = shrinkStrByCapLetters_internal(nn,nLet)
    queryStr = '';
    if nLet > 0
        queryStr = ['[a-z]{0,',num2str(nLet),'}|'];
    end
    queryStr = ['[A-Z0-9]{1}(',queryStr,'\d*)'];
    n = strjoin(regexp(nn,queryStr,'match'),'');
end
