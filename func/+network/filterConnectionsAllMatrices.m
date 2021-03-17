function [F,Fdens,success] = filterConnectionsAllMatrices(A,dens)
    if iscell(A)
        Fdens = zeros(numel(A),1);
        success = false(numel(A),1);
        F = cell(size(A));
        for i = 1:numel(A)
            [F{i},Fdens(i),success(i)] = network.filterConnections(A{i},dens);
        end
    else
        [F,Fdens,success] = network.filterConnections(A,dens);
    end
end
