function t = thetaValToTxt(theta)
    t = num2str(theta);
    if isinf(theta)
        t = '\theta_0';
    end
end
