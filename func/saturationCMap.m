function c = saturationCMap(color,N,startSaturation,finalSaturation)
    if (nargin < 3) || isempty(startSaturation)
        startSaturation = NaN;
    end
    if (nargin < 3) || isempty(finalSaturation)
        finalSaturation = 0.2;
    end
    color1 = rgb2hsv(color);
    if ~isnan(startSaturation)
        color1(2) = startSaturation;
    end
    color2 = rgb2hsv(color);
    color2(2) = finalSaturation;
    c = interp1([1;N],[hsv2rgb(color1);hsv2rgb(color2)],(1:N)');
end