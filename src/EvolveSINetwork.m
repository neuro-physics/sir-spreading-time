function [xData,par,netActTime,spTime] = EvolveSINetwork(nodes, tTotal, par, returnTimeEvol)
    if nargin < 4 || isempty(returnTimeEvol)
        returnTimeEvol = 0;
    end
    if par.isCompetitive
        [xData,par,netActTime,spTime] = EvolveSINetwork_internal(nodes, tTotal, par, @UpdateInputNSeed, @SINElementIter, returnTimeEvol);
    else
        [xData,par,netActTime,spTime] = EvolveSINetwork_internal(nodes, tTotal, par, @UpdateInput1Seed, @SIElementIter, returnTimeEvol);
    end
end

function [xData,par,netActTime,spTime] = EvolveSINetwork_internal(nodes, tTotal, par, UpdateInput, ElementIter, returnTimeEvol)
    if returnTimeEvol
        [xData,par,netActTime,spTime] = EvolveSINetwork_main(nodes, tTotal, par, UpdateInput, ElementIter, @getTimeIndex_same, returnTimeEvol);
    else
        [xData,par,netActTime,spTime] = EvolveSINetwork_main(nodes, tTotal, par, UpdateInput, ElementIter, @getTimeIndex_one, returnTimeEvol);
    end
end

function t = getTimeIndex_same(tt)
    t = tt;
end

function t = getTimeIndex_one(tt)
    t = 1;
end

function [xData,par,netActTime,spTime] = EvolveSINetwork_main(nodes, tTotal, par, UpdateInput, ElementIter, TimeInd, returnTimeEvol)
    N = numel(nodes);
    if par.seedTrial > size(par.seeds,1)
        par.seedTrial = 1;
    end
    for i = 1:size(par.seeds,2)
        nodes(par.seeds(par.seedTrial,i)).x = par.x0(i);
    end
    par.seedTrial = par.seedTrial + 1; % increasing seedTrial for next simulation run (if any)
    if returnTimeEvol
        xData = zeros(tTotal + 1, N);
        spTime = zeros(tTotal + 1, N);
    else
        xData = zeros(1, N);
        spTime = zeros(1, N);
    end
    for i = 1:N
        xData(1,i) = nodes(i).x;
        spTime(1,i) = nodes(i).par.spTime;
    end
    tTotal = tTotal + 1;
    t = 1;
    for t = 2:tTotal
        for i = 1:N
            [nodes(i).par.Isyn,nodes(i).par.kInp] = UpdateInput(i, nodes);
        end
        %isFullyActive = nodes(1).x > 0;
        isFullyActive = true;
        for i = 1:N
            [nodes(i).x,nodes(i).par.spTime] = ElementIter(i,nodes);%ElementIter(nodes(i).x, nodes(i).par);
            xData(TimeInd(t),i) = nodes(i).x;
            spTime(TimeInd(t),i) = nodes(i).par.spTime;
            isFullyActive = isFullyActive && (nodes(i).x > 0);
        end
        if isFullyActive
            break;
        end
    end
    %netActTime = t - 1;
    netActTime = t;
    if returnTimeEvol
        %xData = xData(1:(t-1),:);
        xData = xData(1:t,:);
        spTime = spTime(1:t,:);
    end
end
