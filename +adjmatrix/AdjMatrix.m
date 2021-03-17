classdef (Abstract = true) AdjMatrix < handle
    % base class for every adjacency matrix
    properties (Access = protected)
        Params;
        Matrix;
    end
    
    methods
        function this = AdjMatrix(params, matrix)
            % params {AdjMatrixParams}: parameters of the required adjacency
            % matrix {sparse matrix}: sparse matrix representing this adj matrix
            if nargin < 1 || isempty(params)
                params = AdjMatrixParams();
            end
            if nargin < 2
                matrix = [];
            else
                if (~issparse(matrix))
                    matrix = sparse(matrix);
                end
            end
            this.Params = params;
            this.Matrix = matrix;
        end

        function mat = Get(this)
            mat = this.Matrix;
        end
    end
    
    methods (Abstract)
        this = Load(this);
    end
end
