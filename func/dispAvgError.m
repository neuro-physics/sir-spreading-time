function [sA,sB,sM] = dispAvgError(CA,CB,CM,N,dataTitle)
    sA = getMeanErr(CA,CM,N);
    sB = getMeanErr(CB,CM,N);
    sM = getMeanErr(CM,CM,N);

    disp(sprintf('* %s',dataTitle));
    disp(sprintf('  - matrix A (no edge length sampling) (mean +/- sderr) = %.5g +/- %.5g', sA.mean, sA.err));
    disp(sprintf('  - matrix B    (edge length sampling) (mean +/- sderr) = %.5g +/- %.5g', sB.mean, sB.err));
    disp(sprintf('  - all matrices                       (mean +/- sderr) = %.5g +/- %.5g', sM.mean, sM.err));

    disp(sprintf('* %s mean absolute error', dataTitle));
    disp(sprintf('  - matrix A (no edge length sampling) (mean +/- sderr) = %.5g +/- %.5g', sA.absErr, sA.absErrErr));
    disp(sprintf('  - matrix B    (edge length sampling) (mean +/- sderr) = %.5g +/- %.5g', sB.absErr, sB.absErrErr));
end

function s = getMeanErr(C,M,N)
    s.mean = mean(C);
    s.err = std(C) / sqrt(N);
    s.absErr = mean(abs(C-M));
    s.absErrErr = std(abs(C-M))/sqrt(N);
end
