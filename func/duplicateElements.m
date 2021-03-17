function y = duplicateElements(x)
    y = zeros(2*numel(x),1);
    y(1:2:end) = x;
    y(2:2:end) = x;
    sx = size(x);
    if any( sx == 1 )
        s = ones(1,numel(sx));
        s(sx==max(sx)) = numel(y);
        y = reshape(y,s);
    end
end