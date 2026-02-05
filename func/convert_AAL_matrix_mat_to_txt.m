function convert_AAL_matrix_mat_to_txt(input_dir,input_filename_ptrn,output_dir,flip_matrices)
    dataDir = 'D:/Dropbox/p/postdoc/data';
    casesMetaData = load(fullfile(dataDir,'TLE_NB_BB.mat'));
    casesMetaData = casesMetaData.casesMetaData;
    flipSide = 'R';
    if isunix
        dataDir = '/host/scarus/local_raid/mauricio/data';
    end
    if (nargin < 2) || isempty(input_filename_ptrn)
        input_filename_ptrn = '';
    end
    if (nargin < 3) || isempty(output_dir)
        output_dir = input_dir;
    end
    if (nargin < 4) || isempty(flip_matrices)
        flip_matrices = false;
    end
    
%%
    %input_dir  = 'AALmatrix_N306/selected_FL';
    %output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/fiber_length';
    
    %input_dir  = 'AALmatrix_N306/selected_FN';
    %output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality/tle_matrix/fiber_number';
    
    %input_dir  = 'fcd/fiber_length';
    %output_dir = 'D:/Dropbox/p/pesquisa/epilepsy_criticality/fcd_matrix/fiber_length';
    
    if exist(output_dir,'dir')~=7
        fprintf('creating directory ::: %s ...\n',output_dir);
        mkdir(output_dir);
    end

    [A,cn,fn]=loadAALMatrix(fullfile(input_dir,input_filename_ptrn));
    if flip_matrices
        disp('Flipping matrices for ...');
        %[~,flipCases]   = getPatientIndex(casesMetaData, 'Group', {[flipSide,'TLE']});
        flipCases        = casesMetaData.Code(casesMetaData.UseForSpSim & strcmpi(casesMetaData.Group,[flipSide,'TLE']));
        [~,ind_flip]     = intersect(cn,flipCases);
        group_flip       = cellfun(@(x)casesMetaData.Group(strcmpi(casesMetaData.Code,x)),cn(ind_flip));
        fprintf('%s',strjoin(cellfun(@(x,y)sprintf('%s - %s\n',x,y),cn(ind_flip),group_flip,'UniformOutput',false)));
        A = flipAALMatrix_rowsPerCols(A,[],ind_flip);
    end
    
    for k = 1:numel(A)
        fn_new = fullfile(output_dir,regexprep(fn{k},'\.mat$','.txt','ignorecase'));
        fprintf(' * (%.4g%%) converting %s \n',100*k/numel(A),fn{k});
        fprintf('        ... to %s ...\n',fn_new);
        
        dlmwrite(fn_new,A{k},' ');
    end

end