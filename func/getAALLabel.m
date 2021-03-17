function l = getAALLabel(N)
    l = ['AAL',num2str(N,'%02d')];
    if N == 78
        l = [l,'remap'];
    elseif N == 9
        l = [l,'comm'];
    else
        if all(N ~= [90,294,306])
        error('unknown AAL label for variable aal');
        end
    end
end