%% output data config

imgFormat = 'png';

saveOutputFigures = true;
% saveOutputFigures = false;

% N = 90; % size of the parcellation of the main results
% sortNodesBy = 'lobe'; % 'lobe' or 'func' or 'funclr'

N = 306; % size of the parcellation of the main results
sortNodesBy = 'func';

% plotData = 'flip'; % 'raw', 'flip', 'zScoreToControls'
% groupLabels = { 'LRTLE' }; % list of group labels that are going to be plotted

plotData = 'zScoreToControls'; % 'raw', 'flip', 'zScoreToControls'
groupLabels = { 'RTLE', 'LTLE' }; % list of group labels that are going to be plotted

% plotData = 'raw'; % 'raw' -> plot data without preprocessing; 'flip' -> plot data with RTLE flipped and grouped with LTLE; 'zScoreToControls' -> plot data that has been z-scored to controls (no flipping)

addpath('func');

nodeLabels = {'Hippocampus_R','Hippocampus_L','Thalamus_R','Thalamus_L','Amygdala_R','Amygdala_L','ParaHippocampal_R','ParaHippocampal_L'};

displayData = { 'raw' }; % 'raw' -> full matrices; and/or 'comm' -> community data

%% input data config

% useFDR = 2; % false, true, or 2; if useFDR == 2, show t-test figures
useFDR = 1; % false, true, or 2; if useFDR == 2, show t-test figures

% useBinarySpTime = true;
useBinarySpTime = false;

splitTTest = true;
% splitTTest = false;

zScoreIndividually = true;
% zScoreIndividually = false;

% ttestOnAvg = true;
ttestOnAvg = false;

odirSuffix = '';
if useFDR, odirSuffix = '_fdr'; end