function p = getRelativePrecision(r,precision)
% returns the precision relative to number r
% if r = 1e-2 and precision = 1e-2, then p = 1e-4
    p = precision * 10^floor(log10(r));
end
