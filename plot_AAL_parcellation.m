function fh = plot_AAL_parcellation(N,outputFileName,figFmt,nullColor,showSymbols)
    if (nargin < 2) || isempty(outputFileName)
        outputFileName = '';
    end
    if (nargin < 3) || isempty(figFmt)
        figFmt = 'tiff';
    end
    if (nargin < 4) || isempty(nullColor)
        nullColor = zeros(1,3);
    end
    if (nargin < 5) || isempty(showSymbols)
        showSymbols = true;
    end
%     c = [0,0,0;c(reshape(repmat(1:((N/2)-1),2,1),N-2,1),:)];
%     v = reshape(repmat(1:(N/2),2,1),N,1);
    addpath func
    [~,~,~,aal]=aalsurfview(zeros(N,1));
    c = [nullColor;brewerCMap((N/2),2,1)];
    if N == 90
        [~,lInd,rInd] = sortAALNodes('lr',[],[],aal.labels.(['AAL',num2str(N)]));
        lInd = find(lInd);
        rInd = find(rInd);
    else
        [~,lInd,~] = sortAALNodes('lr',[],[],aal.labels.(['AAL',num2str(N)]));
        lInd = find(lInd);
        rInd = getContraLateralLabel(aal.surf.coord, ['AAL',num2str(N)], lInd, aal);
    end
    v = zeros(N,1);
    v(lInd) = 1:numel(lInd);
    v(rInd) = 1:numel(rInd);
    fh = aalsurfview(v,'',c,[],[],showSymbols,[],[],[],[],[],showSymbols);
%     disp('warning: hemispheres are not symmetric because the parts of each AAL node are node ordered in the same order for both hemispheres');
    if (nargin >= 2) && ~isempty(outputFileName)
        saveFigure(fh, outputFileName, figFmt, false, [], 600);
    end
end