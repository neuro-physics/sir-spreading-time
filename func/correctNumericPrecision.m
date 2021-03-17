function x = correctNumericPrecision(x,precision)
    x(abs(x) <= precision) = 0;
end
