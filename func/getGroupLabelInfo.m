function [g,gi,gTitle] = getGroupLabelInfo(g,sd,isConsensus)
    gi = getDigitFromStr(g);
    sdChar = getGroupSideChar(sd);
    if (gi == 1) && isConsensus
        gTitle = [sdChar,'TLE'];
    else
        if strcmp(sdChar,'LR')
            gTitle = 'TLE';
        else
            gTitle = [sdChar,'TLE'];
        end
    end
end

function c = getGroupSideChar(sd)
    c = sort(strjoin(strrep(sd,'TLE',''),''));
end
