function [A,cn,fn] = loadAALMatrix(inp, caseName, selectCaseName, return_all_file_data)

   if nargin < 2
        caseName = [];
    end
    if nargin < 3
        selectCaseName = [];
    end
    if (nargin < 4) || isempty(return_all_file_data)
        return_all_file_data = false;
    end

    if isempty(caseName)
        cases = selectCaseName;
    elseif isempty(selectCaseName)
        cases = caseName;
    else
        cases = selectCaseName;
    end


    [A,cn,fn] = loadAALMatrix_clean(inp, cases, return_all_file_data);
end


function [A,cn,fn] = loadAALMatrix_clean(inp, cases, return_all_file_data)

%     if (nargin < 2) || isempty(cases)
%         cases = [];
%     end

    [files, baseDir] = resolveInput(inp);

    cnAll = getCaseName(files);
    fnAll = {files.name};

    % Decide loading and ordering
    if isempty(cases)
        loadIdx = 1:numel(files);
        cn = cnAll;
        fn = fnAll;
    else
        [tf,loc] = ismember(cases, cnAll);

        if any(~tf)
            warning('loadAALMatrix:MissingCases', ...
                'Cases not found and skipped: %s', strjoin(cases(~tf),', '));
        end

        % Keep only cases that were found
        loc   = loc(tf);
        cases = cases(tf);


        loadIdx = loc;        % indices into files
        cn = cases;           % EXACT requested order
        fn = fnAll(loadIdx);  % aligned filenames
    end

    % Load data
    A = cell(1,numel(loadIdx));
    for i = 1:numel(loadIdx)
        A{i} = load_internal(fullfile(baseDir,files(loadIdx(i)).name),return_all_file_data);
    end

    % Scalar unwrap
    if numel(A) == 1
        A  = A{1};
        cn = cn{1};
        fn = fn{1};
    end
end




% function [A,cn,fn] = loadAALMatrix(inp,caseName,selectCaseName)
% %LOADAALMATRIX_REFACTORED Behavior-preserving refactor of loadAALMatrix
% 
%     if nargin < 2 || isempty(caseName)
%         caseName = [];
%     end
%     if nargin < 3 || isempty(selectCaseName)
%         selectCaseName = [];
%     end
% 
%     % Resolve input into files + base directory
%     [files, baseDir] = resolveInput(inp);
% 
%     if isempty(files)
%         A = [];
%         cn = [];
%         fn = [];
%         return
%     end
% 
%     % Metadata
%     cnAll = getCaseName(files);
%     fnAll = {files.name};
% 
%     % Stage 1: filter by caseName
%     if isempty(caseName)
%         idx = 1:numel(files);
%         cn = cnAll;
%         fn = fnAll;
%     else
%         [cn,~,idx] = intersect(caseName, cnAll);
%         fn = fnAll(idx);
%     end
% 
%     % Load all selected files (always as cell internally)
%     A = cell(1,numel(idx));
%     for i = 1:numel(idx)
%         A{i} = load_internal(fullfile(baseDir,files(idx(i)).name));
%     end
% 
%     % Stage 2: select/reorder by selectCaseName
%     if ~isempty(selectCaseName)
%         [~,k] = intersect(cn,selectCaseName,'stable');
%         A  = A(k);
%         cn = cn(k);
%         fn = fn(k);
%     end
% 
%     % Unwrap scalars to preserve original behavior
%     if numel(A) == 1
%         A  = A{1};
%         cn = cn{1};
%         fn = fn{1};
%     end
% end


function [files, baseDir] = resolveInput(inp)
%RESOLVEINPUT Normalize input into dir-struct + base directory

    if isstruct(inp)
        files = inp;
        baseDir = '';
    elseif exist(inp,'dir') == 7
        baseDir = inp;
        files = dir(fullfile(baseDir,'*.mat'));
    elseif exist(inp,'file') == 2
        files = dir(inp);
        baseDir = fileparts(inp);
    elseif ischar(inp)
        files = dir(inp);
        baseDir = fileparts(inp);
    else
        error('loadAALMatrix:inp','Unrecognized input type');
    end
end

function A = load_internal(fname,return_all_file_data)
    A = load(fname);
    if ~return_all_file_data && isfield(A,'matrix')
        A = A.matrix;
    end
end
