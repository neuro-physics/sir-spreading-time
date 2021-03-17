function S = CalcSpeedUps(T2, T, suType, zeroToNaNDiag)
% suType == 'global'
%     increase in network activation time: how faster is it to activate the network starting from (i,j) together compared to either i or j (i~=j)
% suType == 'local'
%     increase in node activation time: how faster is it to activate node k starting from (i,j) compared to either i or j (i~=k~=j)
% suType == 'localnet'
%     increase in node activation compared to network activation: how faster the signal goes from i to j compared to the time it takes for the network to activate using (i,j)
    if nargin < 3 || isempty(suType)
        suType = 'global';
    end
    if nargin < 3 || isempty(zeroToNaNDiag)
        zeroToNaNDiag = false;
    end
    if strcmp(suType, 'global')
        CalcSpeedUps_internal = @CalcSpeedUps_global;
    elseif strcmp(suType, 'localnet')
        CalcSpeedUps_internal = @CalcSpeedUps_local_netact;
    elseif strcmp(suType, 'local')
        CalcSpeedUps_internal = @CalcSpeedUps_local;
    else
        error('CalcSpeedUps:suType','Unknown speedup type');
    end
    if iscell(T2)
        if ~iscell(T)
            error('CalcSpeedUps:T','Parameter T should correspond to paremeter T2 (either cell or matrix)');
        end
        if numel(T) ~= numel(T2)
            error('CalcSpeedUps:T','Parameter T should correspond to paremeter T2 (either cell or matrix)');
        end
        S = cell(size(T2));
        for i = 1:numel(T2)
            S{i} = CalcSpeedUps_internal(T2{i},T{i},zeroToNaNDiag);
        end
    else
        S = CalcSpeedUps_internal(T2,T,zeroToNaNDiag);
    end
end

function S = CalcSpeedUps_global(T2,T,zeroToNaNDiag)
    N = size(T2,1);
    if numel(size(T2)) == 3
        T2 = max(T2,[],3); % calc network activation time starting from 2 seeds
    end
    if numel(T) ~= N
        T = max(T,[],2) + 1; % calc network activation time starting from 1 seed
    end
    if zeroToNaNDiag
        S = NaN(size(T2));
    else
        S = zeros(size(T2));
    end
    for i = 1:N
        for j = 1:N
            if (i == j)
                continue;
            end
            m = min(T(i),T(j));
            S(i,j) = (m - T2(i,j)) / m;
        end
    end
end

function S = CalcSpeedUps_local(T2,T,zeroToNaNDiag)
    N = size(T2,1);
    if zeroToNaNDiag
        S = NaN(N);
    else
        S = zeros(N);
    end
    for k = 1:N
        for i = 1:N
            for j = 1:N
                if (j == i)
                    continue;
                end
                if (k == i) || (k == j)
                    continue;
                end
                m = min([T(i,k),T(k,i),T(j,k),T(k,j)]);
                mm = min(T2(i,j,k),T2(j,i,k));
                S(i,k) = (m - mm) / m;
                S(k,i) = S(i,k);
            end
        end
    end
end

function S = CalcSpeedUps_local_netact(T2,T,zeroToNaNDiag)
    N = size(T2,1);
    if numel(size(T2)) == 3
        T2 = max(T2,[],3); % calc network activation time starting from 2 seeds
    end
    if zeroToNaNDiag
        S = NaN(size(T2));
    else
        S = zeros(size(T2));
    end
    for i = 1:N
        for j = 1:N
            if (i == j)
                continue;
            end
            m = min(T(i,j),T(j,i));
            S(i,j) = (m - T2(i,j)) / m;
        end
    end
end
