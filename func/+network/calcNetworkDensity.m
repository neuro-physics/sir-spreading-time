function r = calcNetworkDensity(A,resultType)
    if (nargin < 2) || isempty(resultType)
        resultType = 'single'; % 'single' -> all matrices in the cell array A{:} are considered as a single unit for the many samples of w
                               % 'individual' -> P(:,k) and w(:,k) are the weight distribution of A{k}
    end
    if ~iscell(A)
        A = {A};
    end
    if strcmpi(resultType,'single')
        A = reshape(cell2mat(A),numel(A{1})*numel(A),1);
        r = numel(find(A~=0))/numel(A);
    elseif strcmpi(resultType,'individual')
        nC = numel(A);
        r = zeros(nC,1);
        for i = 1:nC
            r(i) = numel(find(A{i}~=0))/numel(A{i});
        end
    else
        error('Unrecognized resultType');
    end
end
