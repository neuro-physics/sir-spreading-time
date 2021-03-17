function D = zScoreToSubset(D, ind)
% z-score the data in D according to the element-wise average of the subset of D given by ind
%      D -> either a cell of matrices or a 2d array in which observations (subjects) are rows
%
%      if D is cell, then converts it into a table of data in which each cell is a line in the table
%
%      if D is 2d array, then each subject (or observation) is considered to be a row in D
%
%      then calculate mean(D(ind,:),1) and std(D(ind,:)) and z-score all D according to these quantities
%
    isCell = iscell(D);
    if isCell
        sz = size(D{1});
        %D = matCell2Mat(ZScoreMatrix(M)); % calculate Z-score of each case and makes each case a line in the table of data D
        D = matCell2Mat(D); % converts each cell into a line in the table of data D (lines are subjects)
    end
    N = size(D,1);
    Cmean = mean(D(ind,:),1,'omitnan'); % average Z-score of controls
    Cstd = std(D(ind,:),[],1,'omitnan');
    Cstd(Cstd==0)=1; % avoids Inf and -Inf in the Z-scored matrices
    D = (D - repmat(Cmean,N,1)) ./ repmat(Cstd,N,1); % calculate Z-score relative to controls for all cases
    D(isnan(D)) = 0;
    if isCell
        D = reshapeLines(D,sz,'cell');
    end
end
