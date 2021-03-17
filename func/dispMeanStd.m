function dispMeanStd(C,P,N)
    if iscell(C)
        cm = zeros(size(C));
        cs = zeros(size(C));
        if ~isempty(P)
            pm = zeros(size(P));
            ps = zeros(size(P));
        end
        for i = 1:numel(C)
            [cm(i),cs(i)] = meanStd(C{i},0,'omitnan');
            if ~isempty(P)
                [pm(i),ps(i)] = meanStd(P{i},0,'omitnan');
            end
            fprintf('  . N = %d => M +/- SD = %.5e +/- %.5e\n', N(i), cm(i), cs(i));
            if ~isempty(P)
                fprintf('  . N = %d => M +/- SD = %.5e +/- %.5e\n', N(i), pm(i), ps(i));
            end
        end
    else
        [cm,cs] = meanStd(C,0,'omitnan');
        [pm,ps] = meanStd(P,0,'omitnan');

        fprintf('  - N = %d\n', N);
        fprintf('    . Controls = %.5g +/- %.5g\n', cm, cs);
        fprintf('    . Patients = %.5g +/- %.5g\n', pm, ps);
    end
end
