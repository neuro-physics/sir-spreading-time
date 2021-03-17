function [B,cn] = generate_edge_bundling(inputMat,caseName,outFile,debundleFunction)
    if nargin < 2
        caseName = [];
    end
    if nargin < 3
        outFile = [];
    end
    if (nargin < 4) || isempty(debundleFunction)
        debundleFunction = @BoDebundle; % or @debundle
    end
    if isempty(outFile)
        if ischar(inputMat)
            [outFile,~,~] = fileparts(inputMat);
            if isempty(outFile)
                outFile = '.';
            end
            outFile = fullfile(outFile, 'debundle.mat');
        else
            outFile = fullfile('.','debundle.mat');
        end
    else
        [outDir,~,~] = fileparts(outFile);
        if isempty(outDir)
            if ischar(inputMat)
                [outDir,~,~] = fileparts(inputMat);
            else
                outDir = '.';
            end
            outFile = fullfile(outDir, outFile);
        end
    end
    if isunix
        if strcmp(get_hostname(),'neuropc')
            aal=load('./aux_files/aal_cortex_map_olf294_fix.mat');
        else
            aal=load('/host/scarus/local_raid/mauricio/data/AAL_data/aal_cortex_map_olf294_fix.mat');
        end
    else
        aal=load('D:\Dropbox\p\postdoc\data\AAL_data\aal_cortex_map_olf294_fix.mat');
    end

    matlabPath = path;
    if isunix
        if strcmp(get_hostname(),'neuropc')
            path(genpath('/media/storage/matlab_toolbox/tools_edgebundle'),matlabPath); % matlab path has to come later because of the conflict with minmax function in debundle
        else
            path(genpath('/host/scarus/local_raid/mauricio/matlab_toolbox/tools_edgebundle'),matlabPath); % matlab path has to come later because of the conflict with minmax function in debundle
        end
    else
        path(genpath('D:\matlab_toolbox\tools_edgebundle'),matlabPath); % matlab path has to come later because of the conflict with minmax function in debundle
    end

    [A,cn] = loadAALMatrix(inputMat,caseName);
    C = meanMatrix(A);
    N = size(C,1);
    l = getAALLabel(N);

    G = digraph(C);
    x = aal.pos.(l)(:,1);
    y = aal.pos.(l)(:,2);
    z = aal.pos.(l)(:,3);
    Name = cellfun(@num2str,num2cell(1:N)','UniformOutput',false); % cellstr(num2str((1:90)'))
    G.Nodes = table(Name,x,y,z,'RowNames',Name);
    B = debundleFunction(G);
    
    save(outFile, 'B', 'cn', 'C', '-v7.3');
    
    path(matlabPath);
end

function l = getAALLabel(N)
    l = ['AAL',num2str(N)];
    if N == 78
        l = [l,'remap'];
    end
end
