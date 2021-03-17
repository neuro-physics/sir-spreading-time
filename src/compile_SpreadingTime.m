% COMPILE_SPREADINGTIME   Generate MEX-function SpreadingTime_mex from
%  SpreadingTime.
% 
% Script generated from project 'SpreadingTime.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'SpreadingTime'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg SpreadingTime -args ARGS{1} -o SpreadingTime_dej_mex
% else
    codegen -config cfg SpreadingTime -args ARGS{1}
% end
