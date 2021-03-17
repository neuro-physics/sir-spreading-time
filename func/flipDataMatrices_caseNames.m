function d = flipDataMatrices_caseNames(caseNames, flipCaseNames, s, aal, rootPath)
    if (nargin < 5) || isempty(rootPath)
        rootPath = 's';
    end
    d = s;
    fn = fieldnames(s);
    for i = 1:numel(fn)
        if strcmpi(fn{i},'data')
            d.(fn{i}) = flipDataMatrices_struct(caseNames, flipCaseNames, s.(fn{i}), aal);
        else
            if isstruct(s.(fn{i}))
                m = numel(s.(fn{i}));
                for j = 1:m
                    d.(fn{i})(j) = flipDataMatrices_caseNames(caseNames, flipCaseNames, s.(fn{i})(j), aal, [ rootPath, '.', fn{i}, '(',num2str(j),')' ]);
                end
            elseif iscell(s.(fn{i}))
                [~,kFlip,~] = intersect(caseNames,flipCaseNames);
                d.(fn{i}) = flipDataMatrices_cell(s.(fn{i}), caseNames, kFlip, aal);
            end
        end
    end
end

function d = flipDataMatrices_struct(cn, flipCN, s, aal)
    d = s;
    [~,kFlip,~] = intersect(cn,flipCN);
    fn = fieldnames(s);
    for i = 1:numel(fn)
        l = fn{i};
        if ~iscell(s.(l))
            continue;
        end
         d.(l) = flipDataMatrices_cell(s.(l), cn, kFlip, aal);
    end
end

function f = flipDataMatrices_cell(c,cn,kFlip,aal)
    f=c;
    if numel(c)~=numel(cn)
        return;
    end
    n = numel(kFlip);
    for j = 1:n
        k = kFlip(j);
        f{k} = flipAALMatrix_rowsPerCols(c{k}, aal);
    end
end

% function B = flipMatrix_internal(A,aal,rootPath)
%     B = A;
%     if isvector(A)
%         N = numel(A);
%     else
%         N = size(A,1);
%     end
%     if (N~=78) && (N~=90)
%         %disp(sprintf('%s - Cannot flip vector of size N=%d or matrix of size [N,N] == [%d,%d]',rootPath,N,N,N));
%         return;
%     end
%     l = ['AAL',num2str(N)];
%     if N == 78
%         l = [l,'remap'];
%     end
%     n = unique(regexprep(regexprep(aal.labels.(l), '_L$', ''),'_R$', ''));
%     for i = 1:numel(n)
%         k = [ find(strcmp(aal.labels.(l),[n{i},'_L'])), find(strcmp(aal.labels.(l),[n{i},'_R'])) ];
%         if isvector(A)
%             B(k(1)) = A(k(2));
%             B(k(2)) = A(k(1));
%         else
%             B(k(1),:) = A(k(2),:);
%             B(k(2),:) = A(k(1),:);
%             B(:,k(1)) = A(:,k(2));
%             B(:,k(2)) = A(:,k(1));
%         end
%     end
% end
