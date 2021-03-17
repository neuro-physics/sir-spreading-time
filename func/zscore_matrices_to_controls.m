function [Z,cn] = zscore_matrices_to_controls(inputMat,outDir)
    if (nargin < 2)
        [outDir,~,~] = fileparts(inputMat);
    end
    [A,cn,fn] = loadAALMatrix(inputMat);
   
    [~,cInd] = getPatientControlInd(cn);
    [M,~,~,S] = meanMatrix(A(cInd));
    S(S==0)=1;
    Z = shiftAndStretchGlobal(ZScoreMatrixElem(A,M,S,true),A(cInd),true);

    if exist(outDir,'dir') ~= 7
        mkdir(outDir);
    end
    for i = 1:numel(Z)
        fname = fullfile(outDir,appendToFileName(fn{i},'_Z'));
        matrix = Z{i};
        save(fname, 'matrix', '-v7.3');
    end
end

function n = appendToFileName(fn,suf)
    [a,b,c] = fileparts(fn);
    n = [a,b,suf,c];
end

function Zn = shiftAndStretchIndividual(Z)
    if ~iscell(Z)
        Z = { Z };
    end
    Zn = cell(size(Z));
    for i = 1:numel(Z)
        [a,b] = getLinTransfParam(minmax(Z{i}(:)'),[0,1]);
        Zn{i} = a + b.*Z{i};
    end
end

function Zn = shiftAndStretchGlobal(Z,A,keepNonzeroOnly)
    if ~iscell(Z)
        Z = { Z };
    end
    if (nargin < 2)
        A = [];
    end
    if (nargin < 2) || isempty(keepNonzeroOnly)
        keepNonzeroOnly = true;
    end
    ZZ = cell2mat(Z);
    [a,b] = getLinTransfParam(minmax(ZZ(:)'),[0,1]);
    Zn = cell(size(Z));
    for i = 1:numel(Z)
        Zn{i} = a + b.*Z{i};
        if keepNonzeroOnly && ~isempty(A)
            Zn{i}(A{i}==0)=0;
        end
    end
end

function [a,b] = getLinTransfParam(x,y)
    %x = minmax(A(:)');
    %y = [0,1];
    b = diff(y)/diff(x);
    a = y(1) - b*x(1);
end
