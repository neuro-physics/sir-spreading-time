function [r_c,p_c,r_p,p_p] = corrcoef_datastruct_cli(SpMat_con,SpMat_pat,SFieldName,B_con,B_pat,BFieldName,useInverseSpTimes,zScoreData,theta,funcForClin,ignoreOutliersSpMat,ignoreOutliersB)
% transform clinical data according to funcForClin
    if (nargin < 10) || isempty(funcForClin)
        funcForClin = @(x)x;
    end
    if (nargin < 11) || isempty(ignoreOutliersSpMat)
        ignoreOutliersSpMat = false;
    end
    if (nargin < 12) || isempty(ignoreOutliersB)
        ignoreOutliersB = false;
    end
    if zScoreData
        [cc_c,cc_p] = zScoreToControls(funcForClin(B_con.(BFieldName)),funcForClin(B_pat.(BFieldName)));
    else
        cc_c = funcForClin(B_con.(BFieldName));
        cc_p = funcForClin(B_pat.(BFieldName));
    end
    cc_c = reshape(cc_c,[],1);
    cc_p = reshape(cc_p,[],1);
    if ignoreOutliersB
        [~,ind_cc_c] = getOutliers(cc_c);
        [~,ind_cc_p] = getOutliers(cc_p);
    else
        ind_cc_c = false(size(cc_c));
        ind_cc_p = false(size(cc_p));
    end

    r_c = zeros(1,numel(theta));
    r_p = zeros(1,numel(theta));
    p_c = zeros(1,numel(theta));
    p_p = zeros(1,numel(theta));
    
    for t = 1:numel(theta)
        if useInverseSpTimes
            if iscell(SpMat_con.(SFieldName))
                ss_c = 1./SpMat_con.(SFieldName){t};
                ss_p = 1./SpMat_pat.(SFieldName){t};
            else
                ss_c = 1./SpMat_con.(SFieldName);
                ss_p = 1./SpMat_pat.(SFieldName);
            end
        else
            if iscell(SpMat_con.(SFieldName))
                ss_c = SpMat_con.(SFieldName){t};
                ss_p = SpMat_pat.(SFieldName){t};
            else
                ss_c = SpMat_con.(SFieldName);
                ss_p = SpMat_pat.(SFieldName);
            end
        end
        if zScoreData
            [ss_c,ss_p] = zScoreToControls(ss_c,ss_p);
        end

        ss_c = reshape(ss_c,[],1);
        ss_c(isnan(ss_c)) = 0;

        ss_p = reshape(ss_p,[],1);
        ss_p(isnan(ss_p)) = 0;

        cc_c_filter = cc_c;
        cc_p_filter = cc_p;
        if ignoreOutliersSpMat
            [~,ind_ss_c] = getOutliers(ss_c);
            [~,ind_ss_p] = getOutliers(ss_p);
            ss_c(ind_ss_c | ind_cc_c) = [];
            ss_p(ind_ss_p | ind_cc_p) = [];
            cc_c_filter(ind_ss_c | ind_cc_c) = [];
            cc_p_filter(ind_ss_p | ind_ss_p) = [];
        end
        [R,P] = corrcoef(cc_c_filter, ss_c,'Rows','pairwise'); % omit rows that contain NaN in any of the two entries
        r_c(t) = R(1,2);
        p_c(t) = P(1,2);
        [R,P] = corrcoef(cc_p_filter, ss_p,'Rows','pairwise');
        r_p(t) = R(1,2);
        p_p(t) = P(1,2);
    end
end