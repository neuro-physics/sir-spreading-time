function [r,p] = corrcoef_perline(y1,y2)
% calls corrcoef for each line of y1 and y2
    n = size(y1,1);
    r = zeros(n,1);
    p = zeros(n,1);
    for i = 1:n
        [R,P] = corrcoef(y1(i,:),y2(i,:));
        r(i) = R(1,2);
        p(i) = P(1,2);
    end
end