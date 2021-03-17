% COMPILE_PHASETRANSITION   Generate MEX-function PhaseTransition_mex from
%  PhaseTransition.
% 
% Script generated from project 'PhaseTransition.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'PhaseTransition'.
ARGS = cell(1,1);
ARGS{1} = cell(7,1);
ARGS{1}{1} = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{6} = coder.typeof('X',[1 Inf],[0 1]);
ARGS{1}{7} = coder.typeof(false);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg PhaseTransition -args ARGS{1} -o PhaseTransition_dej_mex
% else
    codegen -config cfg PhaseTransition -args ARGS{1}
% end
