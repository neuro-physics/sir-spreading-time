function B = selectLinesOrCols(A,sel,opt)
    if (nargin < 3) || isempty(opt)
        opt = 'line'; % 'cols'
    end
    if strcmpi(opt, 'line')
        opt = 1;
    elseif strcmpi(opt, 'cols')
        opt = 2;
    else
        error('Unknown option');
    end
    if iscell(A)
        B = cell(size(A));
        for i = 1:numel(A)
            B{i} = selectLinesOrCols_internal(A{i},sel,opt);
        end
    else
        B = selectLinesOrCols_internal(A,sel,opt);
    end
end

function B = selectLinesOrCols_internal(A,sel,opt)
    if opt == 1
        B = A(sel,:);
    else
        B = A(:,sel);
    end
end
