function fn = GetOutputFileName(inp, pre, suf, ext)
    if nargin < 2 || isempty(pre)
        pre = '';
    end
    if nargin < 3 || isempty(suf)
        suf = '';
    end
    if nargin < 4 || isempty(ext)
        ext = '.dat';
    end
    if ext(1) ~=  '.'
        ext = ['.',ext];
    end
    [~,n,~] = fileparts(inp);
    fn = [ pre, n, suf, ext ];
end
