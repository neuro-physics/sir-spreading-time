function s = groupSector(A,secInd,secDirection)
    secInd = cellfun(@(x)reshape(x,1,numel(x)),reshape(secInd,1,numel(secInd)),'UniformOutput',false);
    if iscell(A)
        s = cell(numel(A),1);
        for i = 1:numel(A)
            s{i} = groupSector_internal(A{i},secInd,secDirection);
        end
    else
        s = groupSector_internal(A,secInd,secDirection);
    end
end

function s = groupSector_internal(A,secInd,secDirection)
% given a matrix A and a set of indices secInd
% groups rows (if secDirection == 'horiz') or cols (if secDirection == 'vert') of A according to the subdivisions
% of cols (if secDirection == 'horiz') or rows (if secDirection == 'vert') indices in secInd, respectively
% block groups inside blocks of the matrix defined by the index groups secInd
% line groups the sectors of each line
    if (nargin < 3) || isempty(secDirection)
        secDirection = 'vert'; % 'vert'; 'horiz'; 'block'; or 'line'
    end
    if isvector(A)
        getElemFunc = @(X,k) X(k);
        secInd = completeSecInd(secInd,[1,numel(A)],2);
%         s = zeros(numel(secInd),1);
    else
        if strcmpi(secDirection,'horiz')
            getElemFunc = @(X,k) X(:,k);
            secInd = completeSecInd(secInd,size(A),2);
%             s = zeros(1,numel(secInd));
        elseif strcmpi(secDirection,'vert')
            getElemFunc = @(X,k) X(k,:);
            secInd = completeSecInd(secInd,size(A),1);
%             s = zeros(numel(secInd),1);
        elseif strcmpi(secDirection,'block')
            getElemFunc = @(X,k) X(k,k);
            secInd = completeSecInd(secInd,size(A),1);
%             s = zeros(size(secInd));
        elseif strcmpi(secDirection,'line')
            getElemFunc = @(X,k) X(k);
            secInd = completeSecInd(secInd,[1,numel(A(1,:))],2);
            s = cell(size(A,1),1);
            for i = 1:size(A,1)
                s{i} = gsec_internal(A(i,:),secInd,getElemFunc);
            end
            s = cell2mat(s);
            return;
        else
            error('unrecognized secDirection value');
        end
    end
    s = gsec_internal(A,secInd,getElemFunc);
%     if strcmpi(secDirection,'horiz')
%         s = reshape(s,1,numel(s));
%     else
%         s = reshape(s,numel(s),1);
%     end
end

function s = gsec_internal(A,secInd,getElemFunc)
    s = cell(1,numel(secInd));
    for i = 1:numel(secInd)
        s{i} = getElemFunc(A,secInd{i});
    end
    M = max(cell2mat(cellfun(@(x)numel(x),s,'UniformOutput',false)));
    s = cell2mat(cellfun(@(x)[x(:);NaN(M-numel(x),1)],s,'UniformOutput',false));
end

function k = completeSecInd(s,sA,dim)
% dim == 1 -> s has to correspond to the number of rows in A
% dim == 2 -> s has to correspond to the number of cols in A
    ss = cell2mat(s);
    if numel(ss) > sA(dim)
        error('not enough rows/cols to segment; try setting secDirection to the opposite value you set and run again');
    end
    ss = sort(reshape(ss,1,numel(ss)),'ascend');
    a = 1:sA(dim);
    r = setdiff(a,ss);
    if isempty(r)
        k = s;
    else
        k = sortCellOfVectors([ s, getContinuousIndGroups(r) ]);
    end
end
