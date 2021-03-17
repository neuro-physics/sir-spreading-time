function obj = stretchAndDisplaceObj(obj,posDisplacement)
    for i = 1:numel(obj)
        obj(i).Position = obj(i).Position + posDisplacement;
    end
end
