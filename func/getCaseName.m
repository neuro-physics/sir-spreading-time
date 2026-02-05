function [n,files] = getCaseName(inp, netSize)
    if nargin < 2
        netSize = [];
    end
    f = [];
    inpDir = [];
    if isstruct(inp)
        f = inp;
        inpDir = '';
    elseif iscell(inp)
        f = struct('name',inp);
        inpDir = '';
    elseif exist(inp, 'dir') == 7
        if inp(end) ~= filesep
            inp(end+1) = filesep;
        end
        inpDir = inp;
        inp = [inp,'*.mat'];
        f = dir(inp);
    elseif exist(inp, 'file') == 2
        files = inp;
        n = getCaseName_internal(inp, netSize);
        return;
    elseif ischar(inp)
        f = dir(inp);
        if isempty(f)
            f = struct('name',inp); % faking a file with name inp so that this function works
            inpDir = '';
        else
            [inpDir,~,~] = fileparts(inp);
            inpDir(end+1) = filesep;
        end
    else
        error('getCaseName:inp','unrecognized input type');
    end
    n = cell(1,numel(f));
    files = cell(1,numel(f));
    for i = 1:numel(f)
        fname = [inpDir,f(i).name];
        files{i} = fname;
        n{i} = getCaseName_internal(fname, netSize);
    end
end

function n = getCaseName_internal(inp, netSize)
    [~,fn,fn2] = fileparts(inp);
    fn = [fn,fn2];
    %m = regexp(fn, '[^\d]?0?\d{3,}((?:_3T)|_\d)?((?:_postop(\d|(?:sim))*)|(?:_\d{1,}))?[^\d]?', 'match');
    m = regexp(fn, '(?<!N)0?\d{3,}((?:_3T)|_\d)?((?:_postop(\d|(?:sim))*)|(?:_\d{1,}))?', 'match');

    if isempty(m)
        n = '999_9';
        return
    end
    n = m{1};
    if regexp(n(1),'[^\d]')
        n(1) = [];
    end
    if any(strcmpi(n(end),{'.','_','-'}))
        n(end) = [];
    end
    if ~isempty(netSize)
        if netSize(1)~='_'
            netSize = ['_',netSize];
        end
        n = [ n, netSize ];
    end
end

% function n = getCaseName(inp, netSize, pref)
%     if nargin < 2
%         netSize = [];
%     end
%     if nargin < 3 || isempty(pref)
%         pref = '1s_avg_';
%     end
%     [~,fn,~] = fileparts(inp);
%     if strcmpi(fn(1:numel(pref)), pref)
%         fn = fn((numel(pref)+1):end);
%     end
%     n = fn;
%     if ~isempty(netSize)
%         n = strrep(fn, 'lowres', netSize);
%         n = strrep(n, 'midres', netSize);
%     end
% end
