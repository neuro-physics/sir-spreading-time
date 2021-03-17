function s = get_txt_if(cond,txt_true,txt_false)
    if cond
        s = txt_true;
    else
        s = txt_false;
    end
end