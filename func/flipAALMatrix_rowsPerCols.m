function [B,i,j] = flipAALMatrix_rowsPerCols(A,aal,indToFlip,i,j,verbose)
% if A is a cell array, only flip matrices or vectors indexed by indices in indToFlip vector
% otherwise, or if indToFlip is empty, flips every matrix/vector in A
    if (nargin < 2) || isempty(aal)
        %aal=load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
        [~,~,~,aal] = aalsurfview(zeros(90,1));
    end
    if (nargin < 3)
        indToFlip = [];
    end
    if (nargin < 4)
        i = [];
    end
    if (nargin < 5)
        j = [];
    end
    if (nargin < 6)
        verbose = [];
    end
    

    [l,d] = getAALLabel(A);
    B = A;
    if isempty(l)
%         disp('    - nothing done');
        return;
    end
    if ~(iscell(A) || isnumeric(A))
%         disp('    - nothing done');
        return;
    end
    if isempty(i) || isempty(j)
        i = find(cellfun(@(x)~isempty(x),regexp(aal.labels.(l),'_L(_*\d*$|$)'))); % ind of nodes
        j = getContraLateralLabel(aal.surf.coord,l,i,aal); % ind of contra lateral nodes
    end
    B = flip_internal(A,d,aal,i,j,indToFlip,verbose);
end

function B = flip_internal(A,dim,aal,i,j,indToFlip,verbose)
    if iscell(A)
        if isempty(indToFlip)
            B = cell(size(A));
            indToFlip = 1:numel(A);
        else
            B = A;
        end
        for n = 1:numel(indToFlip)
            k = indToFlip(n);
            B{k} = flip_internal(A{k},dim,aal,i,j);
        end
        return;
    end

%     fprintf('  * size(A) == [%d,%d]\n',size(A,1),size(A,2));
    if isvector(A)
        if verbose
            disp('    - flipping vector');
        end
        B = flipVector(A,i,j);
    else
        B = zeros(size(A));
        if dim == 0 % square matrix
            if verbose
                disp('    - flipping square matrix');
            end
            for k = 1:numel(i)
                B(:,i(k)) = flipVector(A(:,j(k)),i,j);
                B(:,j(k)) = flipVector(A(:,i(k)),i,j);
            end
        else
            if dim == 1
                if verbose
                    fprintf('    - flipping over lines; dim == %d\n',dim);
                end
                % flipping over lines
                B(i,:) = A(j,:);
                B(j,:) = A(i,:);
            elseif dim == 2
                if verbose
                    fprintf('    - flipping over columns; dim == %d\n',dim);
                end
                % flipping over cols
                B(:,i) = A(:,j);
                B(:,j) = A(:,i);
            else
                error('unknown dimension for flipping');
            end
        end
    end
end

function u = flipVector(a,i,j)
    u = a;
    u(i) = a(j);
    u(j) = a(i);
end

function [N,dimN] = getN(A)
    % dimN == 0 -> A is a sqr matrix
    % dimN == 1 -> A is a row vector, or is the dim == 1 that has to be flipped
    % dimN == 2 -> A is a col vector, or is the dim == 2 that has to be flipped
    if isnumeric(A)
        if isvector(A)
            n = [90,306];
            if any(numel(A) == n)
                N = numel(A);
                [~,dimN] = max(size(A));
            else
                N = [];
                dimN = [];
            end
        else
            % check if it is a square matrix, if it is, return number of rows of it
            % if it is not, checks if the number of rows or cols matches either [90,306]
            % if it is not either [90,306], then returns null
            if ismatrix(A) && all(size(A) == size(A,1))
                N = size(A,1);
                dimN = 0;
            else
                n = [90,306];
                if any(size(A,1) == n)
                    N = size(A,1);
                    dimN = 1;
                else
                    if any(size(A,2) == n)
                        N = size(A,2);
                        dimN = 2;
                    else
                        N = [];
                        dimN = [];
                    end
                end
            end
        end
    else
        if iscell(A)
            NN = [];
            dd = [];
            for i = 1:numel(A)
                [n,d] = getN(A{i});
                NN((1 + numel(NN)):(numel(NN) + numel(n))) = n;
                dd((1 + numel(dd)):(numel(dd) + numel(d))) = d;
            end
            if isempty(NN)
                N = [];
                dimN = [];
            else
                if all(NN == NN(1)) && all(dd == dd(1))
                    N = NN(1);
                    dimN = dd(1);
                else
                    N = [];
                    dimN = [];
                end
            end
        else
            N = [];
            dimN = [];
        end
    end
end

function [l,dim] = getAALLabel(A)
    [N,dim] = getN(A);
    if isempty(N)
        l = [];
        return;
    end
    l = ['AAL',num2str(N)];
    if N == 78
        l = [l,'remap'];
    elseif N == 9
        l = ['AAL0',num2str(N),'comm'];
    end
end
