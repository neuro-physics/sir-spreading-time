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


function [n,nCell] = shrinkStrByCapLetters(nn,nLet,keepSeparator,separator)
    if (nargin < 2) || isempty(nLet)
        nLet = 3;
    end
    if (nargin < 3) || isempty(keepSeparator)
        keepSeparator = false;
    end
    if (nargin < 4) || isempty(separator)
        separator = '';
    end
    if ischar(nn)
        nn = { nn };
    end
    n = '';
    nCell = cell(size(nn));
    nLet = nLet - 1;
    for i = 1:numel(nn)
        m = splitAndShrink_internal(nn{i},nLet,keepSeparator,separator);
        nCell{i} = m;
        n = [ n, '-', m ];
    end
    n(1)=[];
end

function s = splitAndShrink_internal(nn,nLet,keepSeparator,separator)
    if isempty(separator)
        sep = {'_','-'};
        sepJoin = '_';
    else
        sep = separator;
        sepJoin = separator;
    end
    if keepSeparator
        ss = strsplit(nn,sep);
        for i = 1:numel(ss)
            ss{i} = shrinkStrByCapLetters_internal(ss{i},nLet);
        end
        s = strjoin(ss,sepJoin);
    else
        s = shrinkStrByCapLetters_internal(nn,nLet);
    end
end

function n = shrinkStrByCapLetters_internal(nn,nLet)
    queryStr = '';
    if nLet > 0
        queryStr = ['[a-z]{0,',num2str(nLet),'}|'];
    end
    queryStr = ['[A-Z0-9]{1}(',queryStr,'\d*)'];
    n = strjoin(regexp(nn,queryStr,'match'),'');
end
