function A = import_edge_debundle_json(fileName)
    A = jsondecode(fileread(fileName));
    A.nodes = fieldToDouble(A.nodes,'label');
    [~,k] = sort([A.nodes(:).label]);
    A.nodes = A.nodes(k);
    A.edges = edgesToCell(A.edges,numel(A.nodes));
end

function c = edgesToCell(e,N)
    e = fieldToDouble(e,{'source','target'});
    [~,k] = sort([e(:).source]);
    e = e(k);
    c = cell(N);
    for i = 1:numel(e)
        c{e(i).source,e(i).target} = struct('x',reshape([e(i).coords(:).x],[],1),'y',reshape([e(i).coords(:).y],[],1));
    end
end

function s = fieldToDouble(s,f)
    if ~iscell(f)
        f = {f};
    end
    for i = 1:numel(s)
        for j = 1:numel(f)
            s(i).(f{j}) = str2double(s(i).(f{j}));
        end
    end
end