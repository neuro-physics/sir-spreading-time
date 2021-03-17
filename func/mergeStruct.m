function s = mergeStruct(fieldsToMerge,varargin)
    s = varargin{1};
    if isempty(fieldsToMerge)
        fn = fieldnames(s);
    else
        fn = fieldsToMerge;
    end
    fr = setdiff(reshape(fieldnames(s),1,[]),fn);
    for i = 1:numel(fr)
        s = rmfield(s,fr{i});
    end
    for i = 2:numel(varargin)
        for j = 1:numel(fn)
            l = fn{j};
            s.(l)((numel(s.(l))+1):(numel(s.(l))+numel(varargin{i}.(l)))) = varargin{i}.(l);
        end
    end
end