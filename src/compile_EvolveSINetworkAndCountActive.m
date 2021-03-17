% COMPILE_EVOLVESINETWORKANDCOUNTACTIVE   Generate MEX-function
%  EvolveSINetworkAndCountActive_mex from EvolveSINetworkAndCountActive.
% 
% Script generated from project 'EvolveSINetworkAndCountActive.prj' on
%  09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'EvolveSINetworkAndCountActive'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS{1}{1} = struct;
ARGS{1}{1}.x = coder.typeof(0);
ARGS{1}{1}.neigh = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{1}.w = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{1}.par = struct;
ARGS{1}{1}.par.Iext = coder.typeof(0);
ARGS{1}{1}.par.Isyn = coder.typeof(0);
ARGS{1}{1}.par.kInp = coder.typeof(0);
ARGS{1}{1}.par.Theta = coder.typeof(0);
ARGS{1}{1}.par.W = coder.typeof(0);
ARGS{1}{1}.par.n = coder.typeof(0);
ARGS{1}{1}.par.nInp = coder.typeof(0);
ARGS{1}{1}.par.spTime = coder.typeof(0);
ARGS{1}{1}.par = coder.typeof(ARGS{1}{1}.par);
ARGS{1}{1} = coder.typeof(ARGS{1}{1},[1 Inf],[0 1]);
ARGS{1}{2} = coder.typeof(0);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg EvolveSINetworkAndCountActive -args ARGS{1} -o EvolveSINetworkAndCountActive_dej_mex
% else
    codegen -config cfg EvolveSINetworkAndCountActive -args ARGS{1}
% end
