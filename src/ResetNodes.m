function n = ResetNodes(nodes, Theta, x0)
    n = nodes;
    for i = 1:numel(nodes)
        n(i).par.Theta = Theta;
        n(i).x = x0(i);
    end
end
