clearvars
close all

% Point properties
num_of_points = 6;
row_of_points = 4;
P = rand(row_of_points, num_of_points);

% Create generic labels
P_labels = cell(num_of_points, 1);

for ii = 1:num_of_points
    P_labels{ii} = sprintf('Label %i', ii);
end
%%
% Figure properties
% figure('units', 'normalized', 'outerposition', [0 0.05 1 0.95]);
figure;
subplot(1,2,1);

% Axes interval
axes_interval = 2;
%%
% Spider plot
spider_plot(P, P_labels, axes_interval,...
    'Marker', 'o',...
    'LineStyle', '-',...
    'LineWidth', 2,...
    'MarkerSize', 5);

% Title properties
title('Sample Spider Plot',...
    'Fontweight', 'bold',...
    'FontSize', 12);

% Legend properties
legend('show', 'Location', 'southoutside');
