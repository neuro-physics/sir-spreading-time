function [fh,ax,cb,cLimEffSz] = plot_effsz_pat_con(tt_in,tt_ou,color_lim,showSymbols)
    if (nargin < 3) || isempty(color_lim)
        cLimEffSz_max = max(tt_in.Cohen_Mahal(:));
        cLimEffSz_min = min(tt_in.Cohen_Mahal(:));
        color_lim = getCLim0(cLimEffSz_max,cLimEffSz_min);
    end
    if (nargin < 4) || isempty(showSymbols)
        showSymbols = true;
    end
    % plotting Cohen effect size of patients vs controls
    cLimEffSz = color_lim;

    d = tt_in.Cohen_Mahal;
    d(~(tt_in.h & tt_in.hFDR)) = 0;
    d(abs(d)<0.8) = 0;
    c = insertColorForVal(0,d,[1,1,1],flipud(greenYellowPinkCMap(numel(d))),greenYellowPinkCMap(numel(d)),[],cLimEffSz,numel(d));
    [fh1,ax1,cb1] = aalsurfview(d,'Effect size (Cohen''s d)',c,'continuous',[],[],[],[],[],[],[],showSymbols);
    cb1.TickLabels{1} = 'slower in TLE';

    d = tt_ou.Cohen_Mahal;
    d(~(tt_ou.h & tt_ou.hFDR)) = 0;
    d(abs(d)<0.8) = 0;
    c = insertColorForVal(0,d,[1,1,1],flipud(greenYellowPinkCMap(numel(d))),greenYellowPinkCMap(numel(d)),[],cLimEffSz,numel(d));
    [fh2,ax2,cb2] = aalsurfview(d,'Effect size (Cohen''s d)',c,'continuous',[],[],[],[],[],[],[],showSymbols);
    cb2.Limits = cb1.Limits;
    cb2.TickLabels{1} = 'slower in TLE';

    fh = [fh1,fh2];
    ax = [ax1,ax2];
    cb = [cb1,cb2];

end