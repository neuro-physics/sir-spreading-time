% COMPILE_NETWORKACTIVATIONTIME   Generate MEX-function
%  NetworkActivationTime_mex from NetworkActivationTime.
% 
% Script generated from project 'NetworkActivationTime.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'NetworkActivationTime'.
ARGS = cell(1,1);
ARGS{1} = cell(7,1);
ARGS{1}{1} = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0);
ARGS{1}{6} = coder.typeof('X',[1 Inf],[0 1]);
ARGS{1}{7} = coder.typeof(0,[Inf Inf],[1 1]);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg NetworkActivationTime -args ARGS{1} -o NetworkActivationTime_dej_mex
% else
    codegen -config cfg NetworkActivationTime -args ARGS{1}
% end
