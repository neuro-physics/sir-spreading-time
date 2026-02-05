function A = filter_matrix(A,P,P_level,A_null_value,q_FDR)
    if (nargin<2) || isempty(P)
        P = zeros(size(A));
    end
    if (nargin<3) || isempty(P_level)
        P_level = 0.05;
    end
    if (nargin<4) || isempty(A_null_value)
        A_null_value = 0.0;
    end
    if (nargin<5) || isempty(q_FDR)
        q_FDR = NaN;
    end
    
    if ~isnan(q_FDR)
        P_level = FDR(P(:),q_FDR);
    end
    
    A(P>P_level) = A_null_value;
end