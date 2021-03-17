function [A,cn,fn] = loadAALMatrix(inp,caseName,selectCaseName)
    if (nargin < 2) || isempty(caseName)
        caseName = [];
    end
    if (nargin < 3) || isempty(selectCaseName)
        selectCaseName = [];
    end
    
    if isstruct(inp)
        f = inp;
        inpDir = '';
    elseif exist(inp, 'dir') == 7
        inpDir = inp;
        inp = fullfile(inpDir,'*.mat');
        f = dir(inp);
    elseif exist(inp, 'file') == 2
        f = dir(inp);
        [inpDir,~,~]=fileparts(inp);
    elseif ischar(inp) % inp is a pattern string
        f = dir(inp);
        [inpDir,~,~]=fileparts(inp);
    else
        error('loadAALMatrix:inp','unrecognized input type');
    end
    cn = getCaseName(f);
    fn = {f(:).name};
    n = numel(f);
    if n == 1
        if ~isempty(caseName)
            hasCase = strcmp(caseName, cn{1});
            if any(hasCase)
                A = load_internal(fullfile(inpDir,f(1).name));
                cn = cn{1};
                fn = fn{1};
            else
                A = [];
                cn = [];
                fn = [];
            end
        else
            A = load_internal(fullfile(inpDir,f(1).name));
            cn = cn{1};
            fn = fn{1};
        end
    else
        if ~isempty(caseName)
            [cn,~,ind]=intersect(caseName,cn);
            n = numel(ind);
            fn = fn(ind);
        else
            ind = 1:n;
        end
        A = cell(1,n);
        for i = 1:n
            j = ind(i);
            A{i} = load_internal(fullfile(inpDir,f(j).name));
        end
    end
    
    if ~isempty(selectCaseName)
        [~,k] = intersect(cn,selectCaseName,'stable');
        A = A(k);
        cn = cn(k);
        fn = fn(k);
    end
end

function A = load_internal(fname)
    A = load(fname);
    if isfield(A,'matrix')
        A = A.matrix;
    end
end
