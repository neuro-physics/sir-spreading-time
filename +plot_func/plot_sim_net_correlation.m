close all
clearvars -except np si

addpath('func');

if exist('si','var') ~= 1
    si = load('D:\Dropbox\p\postdoc\data\sirs\selected\N90\si_group_data.mat');
end
if exist('np','var') ~= 1
    np = load('D:\Dropbox\p\postdoc\data\sirs\selected\N90\net_prop.mat');
end

group = 'Controls';

np.(group) = sortFieldsContents(np.(group),si.(group).caseName);

si_dataField = 'SpMatrix';
np_dataField = 'controlData';
