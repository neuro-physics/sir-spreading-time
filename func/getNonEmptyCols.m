function [r,c] = getNonEmptyCols(M,H,mChar,hChar)
% if nargin == 1, r(i) = 1 if any(M(i,:)); c{i} -> char list of indices of non-empty columns for M(i,:)
% if nargin > 1, r(i) = 1 if any(M(i,:)) or any(H(i,:)); and c{i} -> char list of non-empty col indices of M(i,:) (id by mChar) and H(i,:) (id by hChar)
    if nargin == 1
        r = any(M,2);
        if nargout == 2
            [m,n] = size(M);
            Mstr = num2str(M.*repmat(1:n,m,1));
            %c = regexprep(regexprep(mat2cell(Mstr,ones(1,m),size(Mstr,2)),'\s+',','),'(0,|,0|0)',''); % col index
            c = regexprep(regexprep(regexprep(mat2cell(Mstr,ones(1,m),size(Mstr,2)),'\s+',','),'(^0|(?<=[^0]+)0,|,0)',''),'^,',''); % col index
        else
            c = [];
        end
    else
        r = any(M,2) | any(H,2);
        if nargout == 2
            %[m,n] = size(M);
            %Mstr = num2str(M.*repmat(1:n,m,1));
            %c = regexprep(regexprep(mat2cell(Mstr,ones(1,m),size(Mstr,2)),'\s+',','),'(0,|,0|0)',''); % col index
            %c = regexprep(regexprep(mat2cell(Mstr,ones(1,m),size(Mstr,2)),'\s+',','),'(^0|(?<=[^0]+)0,|,0)',''); % col index
            [nRow,~] = size(M);
            c = cell(nRow,1);
            for i = 1:nRow
                ind1 = find(M(i,:));
                ind2 = find((~M(i,:)) & H(i,:));
                c{i} = '';
                if ~isempty(ind1)
                    c{i} = [regexprep(num2str(ind1(:)'),'\s+',[mChar,',']),mChar];
                end
                if ~isempty(ind2)
                    if ~isempty(c{i})
                        c{i} = [c{i},','];
                    end
                    c{i} = [c{i},regexprep(num2str(ind2(:)'),'\s+',[hChar,',']),hChar];
                end
            end
        else
            c = [];
        end
    end
end