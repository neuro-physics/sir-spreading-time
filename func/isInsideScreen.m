function [r,screenIndex,screenSize] = isInsideScreen(pos)
    ss = get(0,'ScreenSize');
    mp = get(0,'MonitorPositions');

    screenSize = ss;
    screenIndex = 0;
    r = isAreaInsideMainScreen(pos,ss);
    if r
        screenIndex = 1;
        return;
    else
        r = isAreaInsideSecondScreen(pos,mp);
        if r
            screenIndex = 2;
            screenSize = mp(2,:);
            screenSize(3) = abs(screenSize(1)) + abs(screenSize(3));
            screenSize(4) = abs(screenSize(2)) + abs(screenSize(4));
            return;
        end
    end

    xx = [0,pos(3),0,pos(3)];
    yy = [0,0,pos(4),pos(4)];
    for i = 1:numel(xx)
        rP = isPositionInsideMainScreen(pos(1:2)+[xx(i),yy(i)],ss);
        if rP
            screenIndex = 1;
            return;
        else
            if isPositionInsideSecondScreen(pos(1:2)+[xx(i),yy(i)],mp)
                screenSize = mp(2,:);
                screenSize(3) = abs(screenSize(1)) + abs(screenSize(3));
                screenSize(4) = abs(screenSize(2)) + abs(screenSize(4));
                screenIndex = 2;
                return;
            end
        end
    end
end

function r = isPositionInsideMainScreen(p,ss)
    r = (p(1) >= (ss(1)-1)) && (p(1) <= ss(3)) && (p(2) >= (ss(2)-1)) && (p(2) <= ss(4));
end

function r = isAreaInsideMainScreen(p,ss)
    r = (p(1) >= (ss(1)-1)) && ((p(1)+p(3)) <= ss(3)) && (p(2) >= (ss(2)-1)) && ((p(2)+p(4)) <= ss(4));
end

function r = isPositionInsideSecondScreen(p,mp)
    if size(mp,1) == 2
        mp2 = mp(2,:);
        mp2(3) = abs(mp2(1)) + abs(mp2(3));
        mp2(4) = abs(mp2(2)) + abs(mp2(4));
        r = isPositionInsideMainScreen(p,mp2);
    else
        r = false;
    end
end

function r = isAreaInsideSecondScreen(p,mp)
    if size(mp,1) == 2
        mp2 = mp(2,:);
        mp2(3) = abs(mp2(1)) + abs(mp2(3));
        mp2(4) = abs(mp2(2)) + abs(mp2(4));
        r = isAreaInsideMainScreen(p,mp2);
    else
        r = false;
    end
end
