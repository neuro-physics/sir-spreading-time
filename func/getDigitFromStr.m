function k = getDigitFromStr(str)
    m = regexp(str,'\d+','match');
    k = str2double(m{1});
end
