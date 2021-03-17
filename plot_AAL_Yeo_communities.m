function fh=plot_AAL_Yeo_communities(N,outputDir,figFormat)
    if (nargin < 1) || isempty(N)
        N = 306;
    end
    if (nargin < 2) || isempty(outputDir)
        outputDir = '';
    end
    if (nargin < 3) || isempty(figFormat)
        figFormat = 'png';
    end
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    lab = ['AAL',num2str(N)];
    plotf=@(i)aalsurfview(aal.comm.(lab)==i,strrep(aal.labels.AAL09comm{i},'_',' '),[1,1,1;0,0,0]);
    nComm = numel(aal.labels.AAL09comm);
    fh = gobjects(1,nComm);
    fn = cell(1,nComm);
    for k = 1:nComm
        fh(k) = plotf(k);
        fn{k} = fullfile(outputDir,['comm_',num2str(k),'_',shrinkStrByCapLetters(aal.labels.AAL09comm{k},1),'_N',num2str(N)]);
    end
    if ~isempty(outputDir)
        if exist(outputDir,'dir') ~= 7
            mkdir(outputDir);
        end
        saveFigure(fh,fn,figFormat);
    end
end