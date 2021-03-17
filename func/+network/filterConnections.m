function [F,Fdens,success] = filterConnections(A,dens,maxIter,precision)
% remove weakest connections from A such that density of F matches (or is close to) dens
% F is a connected graph (has no isolated islands of nodes)
% Fdens is the achieved density such that F is connected
% success flag indicates if Fdens == dens or if bisection
% A is a weighted adjacency matrix to be filtered
% 0 < dens < 1 is the desired density of F
    if (nargin < 3) || isempty(maxIter)
        maxIter = 5000;
    end
    if (nargin < 4) || isempty(precision)
        precision = getRelativePrecision_internal(dens,1e-2);
    end
    [F,Fdens] = network.filterWeakestElements(A,dens);
    if network.isGraphConnected(F)
        success = isEqualToPrecision(Fdens,dens,1e-8);
        return;
    end
    d = dens;
    d1 = 0;
    d2 = network.netDensity(A);
    dVal = d2;
    i = 0;
    while true
        i = i + 1;

        d = (d1 + d2) / 2;
        [F,Fdens] = network.filterWeakestElements(A,d);

        if network.isGraphConnected(F)
            dVal = d;

            if isEqualToPrecision(d1/2,d2/2,precision) % if the graph is connected and we reached the desired precision
                success = true; % we stop
                return;
            end

            if (i >= maxIter) % if the graph is connected and we reached the maximum number of iterations
                success = false; % we stop
                return;
            end

            % if neither the maxIter or the precision have been reached, we continue
            d2 = d; % d was too large, so I decrease the interval to [d1;d]
        else
            if (i >= maxIter) % if the graph is disconnected and we reached the maximum number of iterations
                success = false; % we break the loop and return the last connected graph achieved
                break;
            end
            d1 = d; % d was too small, so I decrease the interval to [d;d2]
        end

    end
    [F,Fdens] = network.filterWeakestElements(A,dVal); % calculating graph of the last valid density in which F is connected
end

function r = isEqualToPrecision(a,b,p)
    r = abs(a-b) <= p;
end

function p = getRelativePrecision_internal(r,precision)
% returns the precision relative to number r
% if r = 1e-2 and precision = 1e-2, then p = 1e-4
    p = precision * 10^floor(log10(r));
end
