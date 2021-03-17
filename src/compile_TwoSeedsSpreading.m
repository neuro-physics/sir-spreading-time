% COMPILE_TWOSEEDSSPREADING   Generate MEX-function TwoSeedsSpreading_mex from
%  TwoSeedsSpreading.
% 
% Script generated from project 'TwoSeedsSpreading.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'TwoSeedsSpreading'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);

%% Invoke MATLAB Coder.

% if forDejerine
%     codegen -config cfg TwoSeedsSpreading -args ARGS{1} -o TwoSeedsSpreading_dej_mex
% else
    codegen -config cfg TwoSeedsSpreading -args ARGS{1}
% end
