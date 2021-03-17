function cbh = setColorBarTitle(cbh,cbTitle)
    if ~isempty(strfind(cbTitle,'$'))
        txtInterpreter = 'latex';
    else
        txtInterpreter = 'tex';
    end
    for i = 1:numel(cbh)
        if ~isempty(fieldnames(cbh(i)))
            h = get(cbh(i),'Title');
            set(h,'String',cbTitle,'Interpreter',txtInterpreter);
        end
    end
end
