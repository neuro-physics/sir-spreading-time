function m = meandiff0(x,dim)
    x(x==0)=NaN;
    m = mean(x,dim,'omitnan');
end