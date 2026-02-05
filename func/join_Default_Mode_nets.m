function [comm_labels,comm_groups] = join_Default_Mode_nets(N)
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    lab = ['AAL',num2str(N)];
    
    comm_labels = aal.labels.AAL09comm;
    comm_groups = aal.comm.(lab);
    ind_DM1              = find(strcmpi(comm_labels,'Default_Mode_1'));
    ind_DM2              = find(strcmpi(comm_labels,'Default_Mode_2'));
    comm_groups(comm_groups==ind_DM2) = ind_DM1;
    for k = (ind_DM2+1):numel(comm_groups)
        comm_groups(comm_groups==k) = k-1;
    end
    comm_labels{ind_DM1} = strrep(comm_labels{ind_DM1},'_1','');
    comm_labels(ind_DM2) = [];
end