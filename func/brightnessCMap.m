function c = brightnessCMap(color,N,startBrightness,finalBrightness)
    if (nargin < 3) || isempty(startBrightness)
        startBrightness = NaN;
    end
    if (nargin < 3) || isempty(finalBrightness)
        finalBrightness = 0.2;
    end
    color1 = rgb2hsv(color);
    if ~isnan(startBrightness)
        color1(3) = startBrightness;
    end
    color2 = rgb2hsv(color);
    color2(3) = finalBrightness;
    c = interp1([1;N],[hsv2rgb(color1);hsv2rgb(color2)],(1:N)');
end