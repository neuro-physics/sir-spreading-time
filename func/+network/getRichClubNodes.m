function [nMax,nMax2,rcInd,rcA,fd,lc] = getRichClubNodes(A,nPerm,isBinMat)
% calculates rich club indices R for nodes of A and nPerm permutations of A
% returns those nodes which have R = RC(A)/<RC(A_rand)> greater than 1
% nMax -> indices of the nodes which have maximum RC index
% nMax2 -> indices of the nodes which have degree equal to the level of second maximum of RC index
% rcInd -> RC index (normalized)
% rcA -> individual RC coefficient (not normalized)
    if (nargin < 2) || isempty(nPerm)
        nPerm = 100;
    end
    if (nargin < 3) || isempty(isBinMat)
        if iscell(A)
            isBinMat = isBinary(A{1});
        else
            isBinMat = isBinary(A);
        end
    end
    if iscell(A)
        nMax = cell(size(A));
        nMax2 = cell(size(A));
        rcInd = cell(size(A));
        rcA = cell(size(A));
        fd = cell(size(A));
        lc = cell(size(A));
        for i = 1:numel(A)
            if isBinMat
                AA = cast(A{i}>0,'like',A{i});
            else
                AA = A{i};
            end
            [nMax{i},nMax2{i},rcInd{i},rcA{i},fd{i},lc{i}] = getRichClubNodes_internal(AA,nPerm,isBinMat);
        end
    else
        if isBinMat
            AA = cast(A>0,'like',A);
        else
            AA = A;
        end
        [nMax,nMax2,rcInd,rcA,fd,lc] = getRichClubNodes_internal(AA,nPerm,isBinMat);
    end
end

function [nMax,nMax2,rcInd,rcA,fd,lc] = getRichClubNodes_internal(A,nPerm,isBinMat)
    rcA = calcRichClub(A,isBinMat);
    nK = numel(rcA);
    rcARand_avg = zeros(1,nK);
    for i = 1:nPerm
        B = randmio_und_connected(A,1);
        rcB = calcRichClub(B,isBinMat);
        nK = min(numel(rcB),nK);
        rcARand_avg(1:nK) = rcARand_avg(1:nK) + rcB(1:nK);
    end
    rcARand_avg((nK+1):end) = [];
    rcA((nK+1):end) = [];
    rcARand_avg = rcARand_avg ./ nPerm;
    rcInd = rcA ./ rcARand_avg;
%     kSel = find(rcInd > 1);
%     n = find(ismember(k,kSel));
    k = sum(A~=0);
    [nMax,kMax] = getNodesForMaxRC(k,rcInd);
    rc2 = rcInd;
    rc2(kMax) = [];
    nMax2 = getNodesForMaxRC(k,rc2);
    A(1:(size(A,1)+1):end)=0;
    [fd,lc] = network.getFeedersAndLocals(A,[nMax,nMax2]);
end

function [n,kMax] = getNodesForMaxRC(k,rc)
    [~,kMax] = max(rc);
    n = find(ismember(k,kMax));
    while isempty(n)
        [~,kInd] = min(k - kMax);
        kk = k(kInd);
        n = find(ismember(k,kk));
    end
end

function r = calcRichClub(A,isBinMat)
    if isBinMat
        r = rich_club_bu(A);
    else
        r = rich_club_wu(A);
    end
end

function r = isBinary(A)
    r = full(all(all((A == 0) | (A == 1))));
end
