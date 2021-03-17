% COMPILE_EVOLVESINETWORK   Generate MEX-function EvolveSINetwork_mex from
%  EvolveSINetwork.
% 
% Script generated from project 'EvolveSINetwork.prj' on 09-Nov-2016.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;

%% Define argument types for entry-point 'EvolveSINetwork'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
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
ARGS{1}{3} = struct;
ARGS{1}{3}.N = coder.typeof(0);
ARGS{1}{3}.nSeeds = coder.typeof(0);
ARGS{1}{3}.isCompetitive = coder.typeof(false);
ARGS{1}{3}.seeds = coder.typeof(0,[Inf Inf],[1 1]);
ARGS{1}{3}.nSim = coder.typeof(0);
ARGS{1}{3}.seedType = coder.typeof('X',[1 Inf],[0 1]);
ARGS{1}{3}.seedTrial = coder.typeof(0);
ARGS{1}{3}.x0 = coder.typeof(0,[1 Inf],[0 1]);
ARGS{1}{3} = coder.typeof(ARGS{1}{3});
ARGS{1}{4} = coder.typeof(0);

%% Invoke MATLAB Coder.
% if forDejerine
%     codegen -config cfg EvolveSINetwork -args ARGS{1} -o EvolveSINetwork_dej_mex
% else
    codegen -config cfg EvolveSINetwork -args ARGS{1}
% end
