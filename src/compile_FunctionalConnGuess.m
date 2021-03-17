% COMPILE_FUNCTIONALCONNGUESS   Generate MEX-function FunctionalConnGuess_mex
%  from FunctionalConnGuess.
% 
% Script generated from project 'FunctionalConnGuess.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'FunctionalConnGuess'.
ARGS = cell(1,1);
ARGS{1} = cell(5,1);
ARGS{1}{1} = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg FunctionalConnGuess -args ARGS{1} -o FunctionalConnGuess_dej_mex
% else
    codegen -config cfg FunctionalConnGuess -args ARGS{1}
% end
