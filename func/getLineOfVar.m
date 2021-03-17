function A = getLineOfVar(varargin)
% the component i of all input variables makes the i-th line of matrix A
% 
    n = numel(varargin{1});
    A = zeros(n,numel(varargin));
    for i = 1:n
        A(i,:) = getAllElemWithInd(varargin,i);
    end
end

function v = getAllElemWithInd(c,k)
    v = zeros(1,numel(c));
    for i = 1:numel(c)
        v(i) = c{i}(k);
    end
end