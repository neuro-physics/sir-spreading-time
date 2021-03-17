function d = resetTheta(d, theta)
    if ~isstruct(d)
        return;
    end
    if (nargin < 2) || isempty(theta)
        theta = Inf;
    end
    n = numel(d);
    for i = 1:n
        fn = fieldnames(d(i))';
        ind = find(strcmpi(fn,'theta'));
        if ~isempty(ind)
            for j = 1:numel(ind)
                k = ind(j);
                if isscalar(d(i).(fn{k}))
                    d(i).(fn{k}) = theta; % changing theta value
                end
            end
            fn(ind) = [];
        end
        for j = 1:numel(fn)
            d(i).(fn{j}) = resetTheta(d(i).(fn{j}), theta);
        end
    end
end
