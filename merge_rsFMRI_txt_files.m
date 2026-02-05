function merge_rsFMRI_txt_files(input_dir,output_dir,save_as_mat,flip_rtle,only_selected)
    dataDir = 'D:/Dropbox/p/postdoc/data';
    casesMetaData = load(fullfile(dataDir,'TLE_NB_BB.mat'));
    casesMetaData = casesMetaData.casesMetaData;
    flipSide = 'R';
    if (nargin < 1) || isempty(input_dir)
        input_dir = 'D:/Dropbox/p/postdoc/data/rsfmri/cases';
    end
    if (nargin < 2) || isempty(output_dir)
        output_dir = '';
    end
    if (nargin < 3) || isempty(save_as_mat)
        save_as_mat = true;
    end
    if (nargin < 4) || isempty(flip_rtle)
        flip_rtle = false;
    end
    if (nargin < 5) || isempty(only_selected)
        only_selected = false;
    end
    
    if isempty(output_dir)
        output_dir = input_dir;
    end
    
    if exist(output_dir,'dir') ~= 7
        mkdir(output_dir);
    end
    
    subjList = dir(input_dir);
    subjList([subjList(:).isdir]==0) = []; % removing non-directory names
    subjList(cellfun(@isempty,regexp({subjList(:).name},'0*\d{3}_\d{1}'))) = []; % removing dir that do not match pattern

    rows_flip = [];
    cols_flip = [];
    
    cases_to_process = casesMetaData.Code(casesMetaData.UseForSpSim==1);
    
    for i = 1:numel(subjList)
        
        output_fn = fullfile(output_dir,['rsFMRI_',subjList(i).name]);
        if flip_rtle
            output_fn = [output_fn,'_flipR'];
        end
        if save_as_mat
            output_fn = [output_fn,'.mat'];
        else
            output_fn = [output_fn,'.txt'];
        end
        
        cases_meta_data_idx = find(strcmpi(casesMetaData.Code,subjList(i).name),1,'first');
        
        if only_selected
            if ~any(contains(cases_to_process,subjList(i).name))
                fprintf('processing only selected ... skipping %s\n',subjList(i).name);
                continue;
            end
        end
        
        %if exist(output_fn,'file')==2
        %    fprintf('skipping %s\n',subjList(i).name);
        %    continue
        %end
        
        disp(['Processing ... ', subjList(i).name]);
        ROI_timeseries = getTxtData(fullfile(subjList(i).folder,subjList(i).name));
        patient_group = casesMetaData.Group(cases_meta_data_idx);
        if iscell(patient_group) && ~isempty(patient_group)
            patient_group = patient_group{1};
        end
        if isempty(patient_group)
            patient_group = 'unk';
        end
        %if ~strcmpi(patient_group,'RTLE')
        %    fprintf('skipping %s\n',subjList(i).name);
        %    continue
        %end
        if flip_rtle && strcmpi(patient_group,[flipSide,'TLE'])
            [ROI_timeseries,rows_flip,cols_flip] = flipAALMatrix_rowsPerCols(ROI_timeseries,[],[],rows_flip,cols_flip,true);
        end
        if isempty(ROI_timeseries)
            disp('  ... empty directory');
        else
            
            if save_as_mat
                readme    = 'rows = time, cols = ROI';
                save(output_fn,'ROI_timeseries','readme')
            else
                fID = fopen(output_fn,'w');
                header_txt = '# rows -> time\n';
                header_txt = [header_txt ,'# cols -> ROIs\n'];
                header_txt = [header_txt ,'#',num2str(1:306), '\n'];
                fprintf(fID,header_txt);
                fclose(fID);
                dlmwrite(output_fn,ROI_timeseries,'-append','delimiter',' ','precision',8);
            end
        end
    end
end

function s = getTxtData(d)
% searches all subdir of d until it finds a directory with many files ROI_AAL_%d.txt
% puts each txt file in a column in s matrix, corresponding to the number in the file name
    txtDir = getTxtDir(d);
    if isempty(txtDir)
        s = [];
        return;
    end
    txtFiles = dir(fullfile(txtDir,'*.txt'));
    txtFiles(cellfun(@(x)strcmpi(x,'.')||strcmpi(x,'..'),{txtFiles(:).name})) = [];
    nLines = numel(importdata(fullfile(txtFiles(1).folder,txtFiles(1).name)));
    N = numel(txtFiles);
    s = zeros(nLines,N);
    for i = 1:N
        col = importdata(fullfile(txtFiles(i).folder,txtFiles(i).name));
        k = regexp(txtFiles(i).name,'\d+','match');
        k = str2double(k{1});
        s(:,k) = col(:);
    end
end

function d = getTxtDir(r)
    temp = dir(fullfile(r,'*.txt'));
    d = '';
    if isempty(temp)
        sd = dir(r);
        for i = 1:numel(sd)
            if sd(i).isdir && ~strcmp(sd(i).name,'.') && ~strcmp(sd(i).name,'..')
                d = getTxtDir(fullfile(sd(i).folder,sd(i).name));
            end
        end
    else
        d = r;
    end
end