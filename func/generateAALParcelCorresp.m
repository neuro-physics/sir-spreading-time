function [k90,x90,k306,x306] = generateAALParcelCorresp(xScale_x90,dx)
    if (nargin < 1) || isempty(xScale_x90)
        xScale_x90 = 1;
    end
    if (nargin < 2) || isempty(dx)
        dx = 0.8; % interval size to the right and to the left of each N=90 x coordinate in which the N=306 x are going to be fit
    end
    if dx < 0
        dx = abs(dx);
    end
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    [~,k90] = groupAALNodes(90,'lobe',aal);
    [l306,k306] = groupAALNodes(306,'lobe',aal);
    
    x90 = reshape(linspace(1,90,90).*xScale_x90,90,1);
    x306 = zeros(306,1);
    [~,~,n306] = unique(regexprep(l306,'[-_]\d+$',''),'stable');
    for i = 1:90
        k = find(n306 == i);
        if (numel(k) == 1)
            x306(k) = x90(i);
        else
            x306(k) = linearTransf(1:numel(k),[1,numel(k)],[(x90(i)-dx),(x90(i)+dx)]);
        end
    end
end
