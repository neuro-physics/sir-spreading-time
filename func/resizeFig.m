function fh = resizeFig(fh,s)
% s = [w,h]
    screenSize = get(0,'ScreenSize');
    mp = get(0,'MonitorPositions');
    hasSecMonitor = size(mp,1) == 2;
    if hasSecMonitor
        screenSize(3) = sum(mp(:,3));
    end
    nC = numel(fh.Children);
    p = fh.Position;
    oldUnits = cell(1,nC);
    pCB = cell(1,nC);
    for i = 1:nC
        if strcmpi(class(fh.Children(i)), 'matlab.graphics.illustration.ColorBar')
            pCB{i} = fh.Children(i).Position;
        end
        oldUnits{i} = fh.Children(i).Units;
        fh.Children(i).Units = 'pixels';
    end
    if hasSecMonitor
        fh.Position(3) = s(1);
        if (fh.OuterPosition(1) + fh.OuterPosition(3)) > screenSize(3)
            fh.OuterPosition(1) = screenSize(3) - fh.OuterPosition(3) - 100;
        end
        fh.Position(4) = s(2);
        if (fh.OuterPosition(2) + fh.OuterPosition(4)) > screenSize(4)
            fh.OuterPosition(2) = screenSize(4) - fh.OuterPosition(4) - 100;
        end
    else
        fh.Position(3) = s(1);
        if (fh.OuterPosition(1) + fh.OuterPosition(3)) > screenSize(3)
            fh.OuterPosition(1) = screenSize(3) - fh.OuterPosition(3) - 100;
        end
        fh.Position(4) = s(2);
        if (fh.OuterPosition(2) + fh.OuterPosition(4)) > screenSize(4)
            fh.OuterPosition(2) = screenSize(4) - fh.OuterPosition(4) - 100;
        end
    end
    didTheTrick = false;
    for i = 1:nC
        if strcmpi(class(fh.Children(i)), 'matlab.graphics.illustration.ColorBar') && ~didTheTrick
            fh.Children(i).Position = [(pCB{i}(1)*p(3)+1),(pCB{i}(2)*p(4)+1),pCB{i}(3)*p(3),pCB{i}(4)*p(4)];
            didTheTrick = true;
        else
            fh.Children(i).Units = oldUnits{i};
        end
    end
end
