clearvars
close all

% adding nifti functions
addpath D:\matlab_toolbox\NIfTI_20140122

[A_midres,caseName_midres] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected\TLE_*_FA_AAL_midres.mat');
[A_lowres,caseName_lowres] = loadAALMatrix('D:\Dropbox\p\postdoc\data\AALmatrix_N90\selected\TLE_*_FA_AAL_lowres.mat');

nii_file_dir = 'D:\Dropbox\p\postdoc\data\AAL_data\parcellation';

output_dir_midres = 'D:\Dropbox\p\postdoc\data\AALmatrix_N306\selected_dist';
output_dir_lowres = 'D:\Dropbox\p\postdoc\data\AALmatrix_N90\selected_dist';

out_fname_suffix_midres = '_dist_AAL_midres.mat';
out_fname_suffix_lowres = '_dist_AAL_lowres.mat';

nii_files = dir(nii_file_dir);
all_cases = getCaseName({nii_files(:).name});

%%
for i = 1:numel(nii_files)
    if nii_files(i).isdir
        continue;
    end
    
    this_case = all_cases{i};
    
    is_midres = contains(nii_files(i).name,'midres');

    % case index to match with the FA matrix in A
    if is_midres
        k = find(strcmpi(this_case,caseName_midres));
    else
        k = find(strcmpi(this_case,caseName_lowres));
    end
    
    if ~isempty(k)
        disp(sprintf(' Processing ... %s',nii_files(i).name));
        
        % loading nii file
        input_file = fullfile(nii_files(i).folder,nii_files(i).name);
        try
            f = load_nii(input_file);
        catch ME
            if strcmp(ME.identifier,'nifti:loadNifti')
                disp('   ***  loadNifti shear error  ***');
                %new_input_file = strrep(input_file,'.nii','_reslice.nii');
                %reslice_nii(input_file, new_input_file);
                %f = load_nii(new_input_file);
                f = load_untouch_nii(input_file);
            else
                rethrow(ME);
            end
        end
        
        % calculating distance between every parcel
        matrix = squareform(pdist(calcNiiParcelPosition(f.img)));
        
        if is_midres
            matrix(A_midres{k}==0)=NaN;
        else
            matrix(A_lowres{k}==0)=NaN;
        end
        
        if is_midres
            output_dir = output_dir_midres;
            out_fname_suffix = out_fname_suffix_midres;
        else
            output_dir = output_dir_lowres;
            out_fname_suffix = out_fname_suffix_lowres;
        end
        out_fname = fullfile(output_dir,['TLE_' this_case out_fname_suffix]);
        disp(sprintf(' ... saving ::: %s',out_fname));
        save(out_fname,'matrix','-v7.3');
    end
end