function [ F, R, P ] = FindBestFunctionalMatch_parallel(As, Af, Theta, nSeedsRange, nSim, tTotal, comparisonMethod)
% This function maximizes (minimizes) the correlation (hamming distance) between functional connectivity estimates F_k and Af (the actual functional connectivity matrix)
% k is the amount of seeds used to seed the spreading model... it has to be greater than 2
%
% Input:
% As -> structural connectivity matrix
% Af -> functional connectivity matrix
% Theta -> threshold of the spreading model (0 is mostly fine, but keep it smaller than the smallest FA weight in As)
% nSeedsRange -> vector with the range of number of seeds to search for the best match between F and Af
% nSim -> number of trials for each number of seed (at least 100 trials for each number of seeds; the higher the better)
% tTotal -> maximum spreading time (usually, the signal activates the whole network in less than 20 time steps...)
% comparisonMethod -> 'corr': maximizes correlation between trials F_k and Af for each number of seeds k
%                     'hamming': minimizes hamming distance between trials F_k and Af for each number of seeds k
%
% Output:
% F -> best functional connectivity estimate in the number of seeds input range according to minimization or maximization of the comparison method (either Hamming distance or correlation, respectively)
% R -> correlation coefficient or hamming distance between estimates F_k and Af for each number k of seeds in the vector nSeedsRange
% P -> p-values or normalized hamming distance between estimates F_k and Af for each number k of seeds in the vector nSeedsRange
    if any(nSeedsRange(:)<2)
        error('the model has to have at least 2 seeds; nSeedsRange cannot have values smaller than 2');
    end
    if (Theta < 0) || ~isscalar(Theta)
        error('Theta has to be a scalar >= 0')
    end
    if strcmpi(comparisonMethod, 'corr')
%         [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @GreaterThan, @CalcCorrCoeff);
        [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @gt, @CalcCorrCoeff);
    elseif strcmpi(comparisonMethod, 'hamming')
%         [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @LessThan, @CalcHammingDist);
        [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, @lt, @CalcHammingDist);
    else
        error('FindBestFunctionalMatch:comparisonMethod', 'Unrecognized comparisonMethod');
    end
end

function [ F, R, P ] = FindBestFunctionalMatch_internal(As, Af, Theta, nSeedsRange, nSim, tTotal, bestMatchCondition, comparisonMethod)
    F = zeros(size(As));
    R = zeros(size(nSeedsRange));
    P = zeros(size(nSeedsRange));
    numOfTestSeeds = numel(nSeedsRange);
    Ftemp = mycell(numOfTestSeeds);
    parfor i = 1:numOfTestSeeds
        Ftemp{i} = FunctionalConnGuess(As, Theta, nSeedsRange(i), nSim, tTotal);
        [R(i),P(i)] = comparisonMethod(Ftemp{i}(:), Af(:));
    end
    if bestMatchCondition(1,2) % condition is seeking for a < b
        CExt = Inf;
    else % condition is seeking for a > b
        CExt = -Inf;
    end
    for i = 1:numOfTestSeeds
        if bestMatchCondition(R(i),CExt)
            CExt = R(i);
            F = Ftemp{i};
        end
    end
end

function c = mycell(n)
    c = cell(1,n);
    for i = 1:n
        c{i} = i;
    end
end

function [r,p] = CalcCorrCoeff(A,B)
    coder.extrinsic('corr');
    [r,p] = corr(A(:),B(:));
end

% function r = GreaterThan(a,b)
%     r = a > b;
% end
% 
% function r = LessThan(a,b)
%     r = a < b;
% end
