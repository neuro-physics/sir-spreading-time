function C = ClusterConnectedElements(T)
    % creating consensus community
    N = numel(T(:,1));
    C = zeros(1,N);
    assigned = false(1,N);
    k = 1;
    for i = 1:N
        if ~assigned(i)
            %continue;
        %end
            c = GrowClusterBFS(T,i); % generates a cluster of all the elements connected to i
        %if all(~assigned(c)) % if this elements are still not assigned to a community
            C(c) = k; % assign these elements to community k
            assigned(c) = true; % set this cluster as already assigned to a community
            k = k + 1; % increments the community index
        end
    end
end
% function C = GetConsensusCommunity(T)
%     % creating consensus community
%     N = numel(T(:,1));
%     C = zeros(1,N);
%     assigned = false(1,N);
%     k = 1;
%     for i = 1:N
%         C(T(i,~assigned)>0) = k;
%         assigned(T(i,:)>0) = true;
%         k = k + 1;
%         if all(assigned)
%             break;
%         end
%     end
%     C = C + 1;
% end
