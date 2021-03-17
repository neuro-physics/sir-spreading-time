function [nColors,foundNaN] = getNumOfColors(spMat)
    if ~iscell(spMat)
        spMat = { spMat };
    end
    minC = Inf;
    maxC = 0;
    foundNaN = any(isnan(spMat{1}(:)));
    for i = 1:numel(spMat)
        m = minmax(spMat{i}(:)');
        if m(1) < minC
            minC = m(1);
        end
        if m(2) > maxC
            maxC = m(2);
        end
        foundNaN = foundNaN || any(isnan(spMat{i}(:)));
    end
    nColors = ceil(maxC) - floor(minC) + 1; % including 0 as a color
    if foundNaN
        nColors = nColors + 1; % including NaN as a color
    end
end
