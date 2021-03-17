function saveSubcorticalData(fileName,data,append)
    appendcmd = {'-v7.3'};
    if (nargin < 6) || isempty(append)
        append = true;
    end
    if append && (exist(fileName,'file')==2)
        appendcmd = {'-append'};
    end
    s = getVarName(data);
    save(fileName,'-struct',s,appendcmd{:});
end

function s = getVarName(v)
    s = inputname(1);
end