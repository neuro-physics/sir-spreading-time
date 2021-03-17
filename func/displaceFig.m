function fh = displaceFig(fh,s)
% s = [w,h]
    p = fh.Position;
    screenSize = get(0,'ScreenSize');
    mp = get(0,'MonitorPositions');
    hasSecMonitor = size(mp,1) == 2;
    if hasSecMonitor
        screenSize(3) = sum(mp(:,3));

        fh.Position(1) = s(1);
        if (fh.OuterPosition(1) + fh.OuterPosition(3)) > screenSize(3)
            fh.OuterPosition(1) = screenSize(3) - fh.OuterPosition(3) - 100;
        end
        fh.Position(2) = s(2);
        if (fh.OuterPosition(2) + fh.OuterPosition(4)) > screenSize(4)
            fh.OuterPosition(2) = screenSize(4) - fh.OuterPosition(4) - 100;
        end
    else
        fh.Position(1) = s(1);
        if (fh.OuterPosition(1) + fh.OuterPosition(3)) > screenSize(3)
            fh.OuterPosition(1) = screenSize(3) - fh.OuterPosition(3) - 100;
        end
        fh.Position(2) = s(2);
        if (fh.OuterPosition(2) + fh.OuterPosition(4)) > screenSize(4)
            fh.OuterPosition(2) = screenSize(4) - fh.OuterPosition(4) - 100;
        end
    end
end
