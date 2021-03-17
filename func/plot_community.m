function ax = plot_community(commLab,ccolor,fh,axpos,axratio)
    if (nargin < 2) || isempty(ccolor)
        ccolor = [0,0,0];
    end
    if (nargin < 3) || isempty(fh)
        fh = [];
    end
    if (nargin < 4) || isempty(axpos)
        axpos = [0.1,0.1];
    end
    if (nargin < 5) || isempty(axratio)
        axratio = 0.5;
    end
    N = 306;
    [~,~,~,aal]=aalsurfview(zeros(90,1));
    lab = ['AAL',num2str(N)];
    [cnall,cn] = shrinkStrByCapLetters(aal.labels.AAL09comm,1);
    k = find(strcmpi(commLab,cn));
    if isempty(k)
        error('plot_community:commLab','unknown community abbreviation; valid communities: %s',strrep(cnall,'-',', '));
    end
    [fhtemp,axtemp] = aalsurfview(aal.comm.(lab)==k,'',[1,1,1;ccolor]);
    if any(k == [4,6]) % Dorsal Attention OR Fronto Parietal
        axtemp = axtemp(1);
    elseif k == 9 % Subcortical
        axtemp = axtemp(2);
    else
        axtemp = axtemp([1,2]);
    end
    if ~isempty(fh)
        wh = axtemp(1).Position(3:4);
        whn = axratio.*wh;
        axtemp(1).Position = [(axpos(1)-whn(1)),axpos(2),whn];
        drawnow
        if numel(axtemp)>1
            axtemp(1).Position = [(axpos(1)-2.*whn(1)),axpos(2),whn];
            axtemp(2).Position = [(axpos(1)-whn(1)),axpos(2),whn];
            drawnow
        end
        if k == 9 % Subcortical
            c = getLinesChildren(axtemp(1));
            ms = c(1).MarkerSize;
            msn = axratio*ms;
            if msn < 0.8
                msn = 0.8;
            end
            set(c,'MarkerSize',msn);
            drawnow
        end
        ax = gobjects(1,numel(axtemp));
        ax(1) = copyobj(axtemp(1),fh);
        ax(1).Colormap = axtemp(1).Colormap;
        ax(1).CLim = axtemp(1).CLim;
        ax(1).Position = [(axpos(1)-whn(1)),axpos(2),whn];
        drawnow
        if numel(ax)>1
            ax(2) = copyobj(axtemp(2),fh);
            ax(2).Colormap = axtemp(2).Colormap;
            ax(2).CLim = axtemp(2).CLim;
            ax(1).Position = [(axpos(1)-2.*whn(1)),axpos(2),whn];
            ax(2).Position = [(axpos(1)-whn(1)),axpos(2),whn];
            drawnow
        end
        close(fhtemp);
    end
end

function c = getLinesChildren(h)
    c = allchild(h);
    ind = arrayfun(@(x)isa(x,'matlab.graphics.chart.primitive.Line'),c);
    c = c(ind);
end