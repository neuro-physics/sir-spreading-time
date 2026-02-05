function export_rsFMRI_UFSC()
%%
    input_dir  = 'D:/Dropbox/p/postdoc/data/rsfmri/cases';
    output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/flip_rsfMRI_timeseries';
    merge_rsFMRI_txt_files(input_dir,output_dir,false,true,true)
%%
    input_dir  = 'D:/Dropbox/p/postdoc/data/rsfmri/cases';
    output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/rsfMRI_timeseries';
    merge_rsFMRI_txt_files(input_dir,output_dir,false,false,true)
end