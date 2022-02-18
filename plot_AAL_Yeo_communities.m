function fh=plot_AAL_Yeo_communities(N,outputDir,figFormat,color_vec,show_all_together)
    if (nargin < 1) || isempty(N)
        N = 306;
    end
    if (nargin < 2) || isempty(outputDir)
        outputDir = '';
    end
    if (nargin < 3) || isempty(figFormat)
        figFormat = 'png';
    end
    if (nargin < 4) || isempty(color_vec)
        color_vec = zeros(1,3); % black
    end
    if (nargin < 5) || isempty(show_all_together)
        show_all_together = false;
    end
    addpath func
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    lab = ['AAL',num2str(N)];
    nComm = numel(aal.labels.AAL09comm);
    if show_all_together
        if (size(color_vec,1) < nComm)
            color_vec = brewerCMap(nComm+1,2,1);
            color_vec = color_vec(2:end,:);
        else
            color_vec = color_vec(1:nComm,:);
        end
        fh = aalsurfview(aal.comm.(lab),'Communities',[1,1,1;color_vec]);
        fn = fullfile(outputDir,'communities');
    else
        plotf=@(i)aalsurfview(aal.comm.(lab)==i,strrep(aal.labels.AAL09comm{i},'_',' '),[1,1,1;color_vec]);
        fh = gobjects(1,nComm);
        fn = cell(1,nComm);
        for k = 1:nComm
            fh(k) = plotf(k);
            fn{k} = fullfile(outputDir,['comm_',num2str(k),'_',shrinkStrByCapLetters(aal.labels.AAL09comm{k},1),'_N',num2str(N)]);
        end
    end
    if ~isempty(outputDir)
        if exist(outputDir,'dir') ~= 7
            mkdir(outputDir);
        end
        saveFigure(fh,fn,figFormat,false);
    end
end