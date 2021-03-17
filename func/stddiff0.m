function s = stddiff0(x,dim)
    x(x==0)=NaN;
    s = std(x,[],dim,'omitnan');
end