function s = stddevSector(A,secInd,secDirection)
    secInd = cellfun(@(x)reshape(x,1,numel(x)),reshape(secInd,1,numel(secInd)),'UniformOutput',false);
    if iscell(A)
        s = cell(size(A));
        for i = 1:numel(A)
            s{i} = stddevSector_internal(A{i},secInd,secDirection);
        end
    else
        s = stddevSector_internal(A,secInd,secDirection);
    end
end

function s = stddevSector_internal(A,secInd,secDirection)
% given a matrix A and a set of indices secInd
% averages rows (if secDirection == 'horiz') or cols (if secDirection == 'vert') of A according to the subdivisions
% of cols (if secDirection == 'horiz') or rows (if secDirection == 'vert') indices in secInd, respectively
% block averages inside blocks of the matrix defined by the index groups secInd
% line averages the sectors of each line
    if (nargin < 3) || isempty(secDirection)
        secDirection = 'vert'; % 'vert'; 'horiz'; 'block'; or 'line'
    end
    if isvector(A)
        sdFunc = @(X,k) std(X(k),'omitnan');
        secInd = completeSecInd(secInd,[1,numel(A)],2);
%         s = zeros(numel(secInd),1);
    else
        if strcmpi(secDirection,'horiz')
            sdFunc = @(X,k) std(reshape(X(:,k),[],1),'omitnan');
            secInd = completeSecInd(secInd,size(A),2);
%             s = zeros(1,numel(secInd));
        elseif strcmpi(secDirection,'vert')
            sdFunc = @(X,k) std(reshape(X(k,:),[],1),'omitnan');
            secInd = completeSecInd(secInd,size(A),1);
%             s = zeros(numel(secInd),1);
        elseif strcmpi(secDirection,'block')
            sdFunc = @(X,k) std(reshape(X(k,k),[],1),'omitnan');
            secInd = completeSecInd(secInd,size(A),1);
%             s = zeros(size(secInd));
        elseif strcmpi(secDirection,'line')
            sdFunc = @(X,k) std(X(k),'omitnan');
            secInd = completeSecInd(secInd,[1,numel(A(1,:))],2);
            s = zeros(size(A,1),numel(secInd));
            for i = 1:size(A,1)
                s(i,:) = sdsec_internal(A(i,:),secInd,sdFunc);
            end
            return;
        else
            error('unrecognized secDirection value');
        end
    end
    s = sdsec_internal(A,secInd,sdFunc);
    if strcmpi(secDirection,'horiz')
        s = reshape(s,1,numel(s));
    else
        s = reshape(s,numel(s),1);
    end
end

function s = sdsec_internal(A,secInd,sdFunc)
    s = zeros(1,numel(secInd));
    for i = 1:numel(s)
        s(i) = sdFunc(A,secInd{i});
    end
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
