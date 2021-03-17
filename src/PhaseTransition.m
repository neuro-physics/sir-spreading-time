function [ nAct, nAct2, stimIndex, nActVec ] = PhaseTransition(A, ThetaRange, nSim, tTotal, x0, icType, useWeightSampling)
% A -> adjacency matrix
% ThetaRange -> 1,nTheta vector containing the threshold values for the elements
% nSim -> number of simulations for each theta in ThetaRange
% tTotal -> max number of time steps used to try to activate entire network
% x0 -> 1,N vector containing the initial condition for each of the N nodes
% icType -> 'fixed': the same node is stimulated for every theta and sim
%           'mostconn': the same node (most connected) is stimulated for every theta and sim
%           'random': randomly choose one seed node
%           'allnodes': runs one simulation for each node
% useWeightSampling -> if true, a new weight sampling is generated for each simulation of each theta
%
% returns
% nAct -> number of activated sites for each theta in ThetaRange
% nAct2 -> variance of nAct
    coder.extrinsic('rng');
    coder.extrinsic('FitMatrixWeights');
    
    rng('shuffle', 'twister');
    
    isFixed = false;
    mostConn = false;
    isAllNodes = false;
    if strcmpi(icType, 'fixed')
        isFixed = true;
        mostConn = false;
        isAllNodes = false;
    end
    if  strcmpi(icType, 'mostconn')
        isFixed = true;
        mostConn = true;
        isAllNodes = false;
    end
    if  strcmpi(icType, 'allnodes')
        isFixed = true;
        mostConn = false;
        isAllNodes = true;
    end
    if strcmpi(icType, 'random')
        isFixed = false;
    end
    nodes = GetNodes(A, ThetaRange(1), x0, 1, false);
    N = numel(nodes);
    nAct = zeros(size(ThetaRange));
    nAct2 = zeros(size(ThetaRange));
    nTheta = numel(ThetaRange);
    
    if isFixed
        if isAllNodes
            stimIndex = repmat(1:N, nTheta, 1);
            nSim = N;
        else
            if mostConn
                [ ~, ind ] = max(sum(A~=0));
                stInd = ind;
            else
                stInd = randi(numel(x0), 1);
            end
            stimIndex = repmat(stInd, nTheta, nSim);
        end
    else
        stimIndex = randi(numel(x0), nTheta, nSim);
    end
    nActVec = zeros(nTheta,nSim);
    
    mu = 0;
    sigma = 0;
    if useWeightSampling
        [mu, sigma] = FitMatrixWeights(A, 100, false);
    end

    for i = 1:nTheta
        nActSum = 0.0;
        nAct2Sum = 0.0;
        for k = 1:nSim
            x0i = x0;
            x0i(stimIndex(i,k)) = 1;
            if useWeightSampling
                Asurr = zeros(size(A)); % avoids "Subscripting into an mxArray is not supported" error https://www.mathworks.com/matlabcentral/answers/122167-subscripting-into-an-mxarray-is-not-supported
                Asurr = GetSurrogateRandomMatrix(A, mu, sigma, false);
                nodes = GetNodes(Asurr, ThetaRange(i), x0i, 1, false);
            else
                nodes = ResetNodes(nodes, ThetaRange(i), x0i);
            end
            nActTemp = EvolveSINetworkAndCountActive(nodes, tTotal);
            nActVec(i,k) = nActTemp;
            nActSum = nActSum + nActTemp;
            nAct2Sum = nAct2Sum + nActTemp .* nActTemp;
        end
        nAct(i) = nActSum ./ nSim;
        nAct2(i) = nAct2Sum ./ nSim - nAct(i) .* nAct(i);
%         if rho2(i) < 0.0
%             rho2(i) = 0.0;
%         end
    end
end

% function nn = EvolveSINetworkAndCountActive(nodes, tTotal)
%     N = numel(nodes);
%     for t = 1:tTotal
%         for i = 1:N
%             nodes(i).par.Isyn = UpdateInput(i, nodes);
%         end
%         isNetActive = nodes(1).x > 0;
%         for i = 1:N
%             nodes(i).x = SIElementIter(nodes(i).x, nodes(i).par);
%             isNetActive = isNetActive && (nodes(i).x > 0);
%         end
%         if isNetActive
%             break;
%         end
%     end
%     nn = 0;
%     for i = 1:N
%         if nodes(i).x > 0
%             nn = nn + 1;
%         end
%     end
% end
