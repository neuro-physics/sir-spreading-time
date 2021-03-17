classdef (Sealed) AdjMatrixBarabAlbGraph < adjmatrix.AdjMatrixFromNetX
    methods
        function this = AdjMatrixBarabAlbGraph(params, loadOnInit, delAfterLoad)
            % creates a complete graph (mean-field network)
            %
            % params {AdjMatrixParams}: params of the adjacency matrix
            % loadOnInit {boolean}: loads the text file containing the adj matrix on initialization (constructor)
            % delAfterLoad {boolean}: delete adj matrix file after loading the matrix

            this = this@adjmatrix.AdjMatrixFromNetX('barabasi_albert_graph', params, loadOnInit, delAfterLoad);
        end
    end
    methods (Access = protected)
        function cmd = GetNetXGraphCmdLine(this)
            cmd = [ 'G=nx.' this.Method '(' num2str(this.Params.N) ',' num2str(this.Params.m) ')' ];
        end
        
        function cmd = GetNetXAdjMatCmdLine(this)
            cmd = 'nx.adj_matrix(G).todense()';
        end
    end
end
