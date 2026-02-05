function fh=plot_AAL_Yeo_communities(N,outputDir,figFormat,color_vec,show_all_together,join_DM_net)
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
    if (nargin < 6) || isempty(join_DM_net)
        join_DM_net = false;
    end
    
    addpath func
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    lab = ['AAL',num2str(N)];
    
    comm_labels = aal.labels.AAL09comm;
    comm_groups = aal.comm.(lab);
    if join_DM_net
        [comm_labels,comm_groups] = join_Default_Mode_nets(N);
    end
    
    nComm = numel(comm_labels);
    if show_all_together
        if (size(color_vec,1) < nComm)
            color_vec = brewerCMap(nComm+1,2,1);
            color_vec = color_vec(2:end,:);
        else
            color_vec = color_vec(1:nComm,:);
        end
        [fh,~,cb] = aalsurfview(comm_groups,'Communities',[1,1,1;color_vec]);
        fn = fullfile(outputDir,'communities');
        comm_labels = ['_',strsplit(shrinkStrByCapLetters(comm_labels,1),'-')];
        comm_labels{1}='';
        cb.Ticks = 0:9;
        cb.TickLabels = comm_labels;
    else
        plotf=@(i)aalsurfview(comm_groups==i,strrep(comm_labels{i},'_',' '),[1,1,1;color_vec]);
        fh = gobjects(1,nComm);
        fn = cell(1,nComm);
        for k = 1:nComm
            fh(k) = plotf(k);
            sgtitle(fh(k),strrep(comm_labels{k},'_',' '));
            fn{k} = fullfile(outputDir,['comm_',num2str(k),'_',shrinkStrByCapLetters(comm_labels{k},1),'_N',num2str(N)]);
        end
    end
    if ~isempty(outputDir)
        if exist(outputDir,'dir') ~= 7
            mkdir(outputDir);
        end
        saveFigure(fh,fn,figFormat,false);
    end
end