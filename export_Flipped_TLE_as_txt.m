function export_Flipped_TLE_as_txt
%%
    clearvars
    close all

    [~,~,~,aal]=aalsurfview(zeros(90,1));
    
    S=struct('ROI_idx',[],'AAL_label',[],'RSN_label',[],'RSN_short_label',[],'Position_X',[],'Position_Y',[],'Position_Z',[]);
    [~,rsn_short_label] = shrinkStrByCapLetters(aal.labels.AAL09comm(aal.comm.AAL306)',1,false);
    S.ROI_idx           = (1:numel(aal.labels.AAL306))';
    S.AAL_label         = aal.labels.AAL306';
    S.RSN_label         = aal.labels.AAL09comm(aal.comm.AAL306)';
    S.RSN_short_label   = rsn_short_label;
    S.Position_X        = aal.pos.AAL306(:,1);
    S.Position_Y        = aal.pos.AAL306(:,1);
    S.Position_Z        = aal.pos.AAL306(:,1);
    
    writetable(struct2table(S),'AAL_ROI_template.xlsx');
%%
    convert_AAL_matrix_mat_to_txt('D:/Dropbox\p/postdoc/data/AALmatrix_N306/selected','TLE*.mat',...
                                  'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/flip_frac_anisotropy',true);
    convert_AAL_matrix_mat_to_txt('D:/Dropbox\p/postdoc/data/AALmatrix_N306/selected_FL','TLE*.mat',...
                                  'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/flip_fiber_length',true);
    convert_AAL_matrix_mat_to_txt('D:/Dropbox\p/postdoc/data/AALmatrix_N306/selected_FN','TLE*.mat',...
                                  'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/flip_fiber_number',true);
%%
    merge_rsFMRI_txt_files(input_dir,output_dir)
end