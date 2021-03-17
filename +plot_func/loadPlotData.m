function [outputDir,outputMainDir,outputMainDirN,si,siFileName] = loadPlotData(dataDir,odirSuffix,N,useBinarySpTime,splitTTest,zScoreIndividually,ttestOnAvg,siFileNameSuffix)
    if (nargin < 8) || isempty(siFileNameSuffix)
        siFileNameSuffix = '';
    end

    Nstr = sprintf('N%d',N);
    outputMainDir = fullfile(dataDir,'figs');
    outputMainDirN = fullfile(outputMainDir, Nstr);
    if ttestOnAvg
        if useBinarySpTime
            if splitTTest
                % split t-test, binary sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_spTT_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_spTT.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_spTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_spTT.mat');
                end
            else
                % no t-test splitting, binary sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01.mat');
                end
            end
        else
            if splitTTest
                % split t-test, weighted sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT_w',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_z_spTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_spTT_w.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_spTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_spTT_w.mat');
                end
            else
                 % split t-test, weighted sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_w',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_w.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_w.mat');
                end
            end
        end
    else
        if useBinarySpTime
            if splitTTest
                % split t-test, binary sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT_sampTT',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_spTT_sampTT_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_sampTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_sampTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_spTT_sampTT.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_spTT_sampTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_sampTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_sampTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_spTT_sampTT.mat');
                end
            else
                % no t-test splitting, binary sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_sampTT_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_sampTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_sampTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_sampTT.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_binSpTime_sampTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_sampTT.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_sampTT.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_sampTT.mat');
                end
            end
        else
            if splitTTest
                % split t-test, weighted sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_spTT_w',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_spTT_sampTT_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_sampTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_spTT_sampTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_spTT_sampTT_w.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_spTT_sampTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_sampTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_spTT_sampTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_spTT_sampTT_w.mat');
                end
            else
                % split t-test, weighted sp time, t-test on the averages
                %outputDir = fullfile(outputMainDirN,['full_alpha0.01_w',odirSuffix,filesep]);
                if zScoreIndividually
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_sampTT_z');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_sampTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_z_alpha0.01_sampTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_z_alpha0.01_sampTT_w.mat');
                else
                    outputDir = fullfile(outputMainDirN,'figs_weiSpTime_sampTT');
%                     if ~checkHash(fullfile(dataDir,Nstr,'sim_data_alpha0.01_sampTT_w.mat'),si.HashValue)
                        siFileName = fullfile(dataDir,Nstr,'sim_data_alpha0.01_sampTT_w.mat');
%                     end
                    %si_n306 = load(fullfile(dataDir,'N306','sim_data_alpha0.01_sampTT_w.mat');
                end
            end
        end
    end
%     if isempty(si)
%         si = si;
%     end
    if ~isempty(siFileNameSuffix)
        [dd,ff,ee] = fileparts(siFileName);
        siFileName = fullfile(dd,[ff,siFileNameSuffix,ee]);
    end
    si = load(siFileName);
    si = rmfield(si,'HashValue');
    outputDir = [outputDir,odirSuffix,siFileNameSuffix,filesep];
end

function r = checkHash(fn,h)
    mf = matfile(fn);
    r = strcmp(h,mf.HashValue);
end