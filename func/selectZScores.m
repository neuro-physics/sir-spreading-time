function s = selectZScores(z, nSigma, f, keepFormat, keepZ)
% given a matrix of z scores, z, returns all the elements of z such that z > nSigma
% if z is a cell of matrices, each cell corresponds to a different case
% f is a function handle that must compare two values f(a,b)
%    if not specified, f = @(a,b) a >= b
%    a is the z-score
%    b is nSigma
% keepFormat: if true, keep the output selected z scores with matrix shape, instead of vector of pairs
% keepZ: if false, only returns the number of times each element of z matrices has passed the f test
%        if true, returns the average z-score of a given pair taken over all the cases that satisfy f
    if ~iscell(z)
        z = {z};
    end
    if (nargin < 3) || isempty(f)
        f = @(a,b) a >= b;
    end
    if (nargin < 4) || isempty(keepFormat)
        keepFormat = false;
    end
    if (nargin < 5) || isempty(keepZ)
        keepZ = false;
    end
    nCases = numel(z);
    N = size(z{1},1);
    [x,y] = meshgrid(1:N,1:N);
    pairs = [y(:),x(:)]; % matlab iterates firt over rows, then over cols: reshape(1:9,[3,3]) == [1 4 7;2 5 8;3 6 9]
    %pairs = pairs(pairs(:,2)>pairs(:,1),:);
    nPairs = size(pairs,1);
    zSel = zeros(nCases,nPairs);
    for i = 1:nCases
        for j = 1:nPairs
            zz = z{i}(pairs(j,1),pairs(j,2));
            if f(zz,nSigma)
                if keepZ
                    zSel(i,j) = zz;
                else
                    zSel(i,j) = zSel(i,j) + 1; % element j corresponds to ind2sub([N,N],j): j = 1:N is first col; j = (N+1):(2*N) is second col; etc
                end
            end
        end
    end
    s.pairs = pairs;
    s.z = zSel;
    if keepFormat
        if nCases == 1
            s.z = reshape(zSel(1,:), size(z{1}));
        else
            s.z = cell(1,nCases);
            for i = 1:nCases
                s.z{i} = reshape(zSel(i,:), size(z{i}));
            end
        end
    end
end
