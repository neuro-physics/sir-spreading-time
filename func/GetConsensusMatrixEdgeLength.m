function [G,P,km] = GetConsensusMatrixEdgeLength(input,dist,hemiid,nBins,kmShift)
%FCN_GROUP_AVERAGE      build group-average matrix
%
%   G = FCN_GROUP_AVERAGE(A,DIST,HEMIID) takes as input a WEIGHTED "stack" of
%   connectivity matrices, A, with dimensions [N x N x SUBJECT] where N is
%   number of nodes and SUBJECT is the number of matrices in the stack. The
%   matrices MUST be weighted, and ideally with continuous weights (e.g.
%   fractional anisotropy rather than streamline count). The second input
%   is DIST, which is a pairwise distance matrix (i.e. DIST(i,j) is the
%   Euclidean distance between nodes i and j). The final input is an [N x
%   1] vector, HEMIID, which labels nodes as in the left (1) or right (2)
%   hemisphere.
%
%   This function estimates the average edge length distribution and builds
%   a group-averaged connectivity matrix that approximates this
%   distribution with density equal to the mean density across subjects.
%
%   The algorithm works as follows:
%   1. Estimate the cumulative edge length distrbiution.
%   2. Divide the distribution into M length bins, one for each edge that
%      will be added to the group-average matrix.
%   3. Within each bin, select the most edge that is most consistently
%      expressed across subjects, breaking ties according to average edge
%      weight (which is why A must be weighted).
%   
%   The algorithm works separately on within/between hemisphere links.
%
%   Inputs:
%               input,      stack of connectivity matrices (either 3d array or cellarr of matrices) or directory pattern
%               DIST,   pairwise distance matrix
%               hemiid, vector containing the hemisphere of each node (1 == left; 2 == right)
%               nBins,  vector containing the number of bins for binning tract lengths for each hemisphere
%                       (if any nBins is Inf, then the number of bins for that hemisphere is automatically estimated)
%
%   Outputs:    G,      binary group-average matrix
%
    if ischar(input)
        input = loadFiles(input);
    end
    if iscell(input)
        N = size(input{1},1);
        A = reshape(cell2mat(input),[N,N,numel(input)]);
    else
        A = input;
    end
    if (nargin < 2) || (nargin < 3) || isempty(dist) || isempty(hemiid)
        %aal = load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
        [~,~,~,aal] = aalsurfview(zeros(90,1));
    end
    if (nargin < 2) || isempty(dist)
        if N == 78
            pLabel = 'AAL78remap';
        elseif N == 90
            pLabel = 'AAL90';
        elseif N == 294
            pLabel = 'AAL294';
        elseif N == 306
            pLabel = 'AAL306';
        else
            error('number of nodes did not match aal labels');
        end
        dist = calcNodesDistance_mex(ones(size(A,1),size(A,1)),aal.pos.(pLabel));
    end
    if (nargin < 3) || isempty(hemiid)
        hemiid = getHemisphereId(size(A,1),[],aal);
    else
        hemiid = hemiid(:)';
    end
    if (nargin < 4) || isempty(nBins)
        nBins = [ Inf, Inf ];
    else
        if isscalar(nBins)
            nBins = repmat(nBins,[1,2]);
        end
    end
    if (nargin < 5)
        kmShift = [];
    end

    [n,~,nsub] = size(A);
    if isempty(kmShift)
        kmShift = zeros(n,1);
    end
    C = sum(A~=0,3); % number of links between nodes
    P = C ./ nsub; % probability of having i,j connection
    km = round(mean(sum(A~=0,2),3));km(km<1)=1;km(km>n)=n; % mean connectivity per node
    W = sum(A,3)./C;
    Grp = zeros(n,n,2);
    for j = 1:2
        if j == 1
            d = +(hemiid' == 1)*(hemiid == 2); % +(hemiid == 1)*(hemiid' == 2);
            d = d | d';
        else
            d = +(hemiid' == 1)*(hemiid == 1) | +(hemiid' == 2)*(hemiid == 2); % +(hemiid == 1)*(hemiid' == 1) | +(hemiid == 2)*(hemiid' == 2);
            d = d | d';
        end
        D = nonzeros(bsxfun(@times,(A > 0),dist.*triu(d)));
        if isinf(nBins(j))
            M = round(length(D)/nsub);
        else
            M = nBins(j);
        end
        dist_hemi = dist.*d;
        [x,y] = ecdf(D);
        x = round(x.*M); % for N = 306, there are gaps in the values of x
                         % (i.e. some values of the 1:M sequence are not contained in x )
                         % thus, for some i values in the for loop below, the vector 'ind'
                         % returns empty from its statement and the mask would crash because min(yy) and max(yy) would be empty
        % debug histogram
        %[P,~] = histcounts(x, 0:M);
        %figure;
        %plot(1:M, P, '-');
        %if j == 1, figTitle='left'; else figTitle='right'; end
        %xlabel('x');ylabel('P');title([figTitle,' N=',num2str(numel(hemiid))]);
        %disp(sprintf('number of empty bins = %g', numel(find(P==0))));
        
        % x = x.*M;
        G = zeros(n);
        %debug_k = 0;
        for i = 1:M
            ind = (x >= (i - 1)) & (x < i);
            %if ~any(ind)
            %    debug_k = debug_k + 1;
            %    continue;
            %end
            yy = y(ind);
            if isempty(yy)
                % continue; % ignore connections
                % mask = ones(size(dist_hemi)); % consider every connection
                mask = d;
            else
                mask = dist_hemi >= min(yy) & dist_hemi <= max(yy);
            end
            [u,v] = find(triu(mask,1));
            indx = (v - 1)*n + u; % linear index related to matrix indices u and v
            c = C(indx);
            w = W(indx);
            zz = sum(c == max(c));
            if zz == 1
                [~,indmax] = max(c);
                G(indx(indmax)) = W(indx(indmax));%1;
            else
                aa = find(c == max(c));
                ww = w(aa);
                [~,indsort] = sort(ww,'descend');
                k = indx(aa(indsort(1)));
                G(k) = W(k);%1;
            end
        end
        %debug_k
        Grp(:,:,j) = G;
    end
    G = sum(Grp,3); G = G + G';
end

function hemiid = getHemisphereId(N,nodeLabels,aal)
% commFile is a mat-file containing a struct:
%   Ac         -> consensus matrix
%   C          -> communities for each node for each ggamma
%   aal_labels -> labels for each node
%   ggamma     -> each ggamma corresponds to a cell of C
    if (nargin < 2) || isempty(nodeLabels)
        if N == 78
            nodeLabels = aal.labels.AAL78remap;
        elseif N == 90
            nodeLabels = aal.labels.AAL90;
        elseif N == 294
            nodeLabels = aal.labels.AAL294;
        elseif N == 306
            nodeLabels = aal.labels.AAL306;
        else
            error('number of nodes did not match automatic sort');
        end
    end

    rInd = cellfun(@(x)~isempty(x),regexp(nodeLabels, '(_R$|_R_)', 'start'));
    %lInd = find(~rInd);
    %rInd = find(rInd);
    hemiid = ones(1,numel(nodeLabels));
    hemiid(rInd) = 2;
end

function A = loadFiles(input)
    [inputDir,~,~] = fileparts(input);
    if ~isempty(inputDir)
        inputDir = [ inputDir, filesep ];
    end
    f = dir(input);
    A = cell(1,numel(f));
    for i = 1:numel(f)
        a = load([inputDir,f(i).name]);
        if isfield(a, 'matrix')
            A{i} = a.matrix;
        else
            A{i} = a;
        end
    end
end
