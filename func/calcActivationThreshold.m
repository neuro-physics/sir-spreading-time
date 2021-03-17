function Th = calcActivationThreshold(pt, Theta, rho)
    if nargin < 2
        Theta = [];
    end
    if nargin < 3
        rho = [];
    end
    if ~isempty(pt)
        Theta = pt.Theta;
        rho = pt.rho;
    end
    if iscell(Theta)
        Theta = Theta{1};
    end
    nCases = numel(rho);
    Th = zeros(1, nCases);
    for i = 1:nCases
        mRho = max(rho{i});
        k = find(rho{i}~=mRho,1,'first') - 1;
        if k < 1
            Th(i) = NaN;
        else
            Th(i) = Theta(k);
        end
    end
end
