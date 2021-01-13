set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

%  data1 = readtable('lok1.dat');
%  data2 = readtable('lok2.dat');
%  data3 = readtable('lok3.dat');
%  data4 = readtable('lok4.dat');
% 
%  plot(data1.Var1, data1.Var2);
%  hold on;
%  plot(data2.Var1, data2.Var2);
%   hold on;
%  plot(data3.Var1, data3.Var2);
%   hold on;
%  plot(data4.Var1, data4.Var2);
%  
% 
%  legend({'$\omega = 1.0$', '$\omega = 1.4$','$\omega = 1.8$', '$\omega = 1.9$'},...
%      'Location','best','Orientation','vertical','FontSize', 14, 'FontWeight', 'bold','Interpreter','latex');
%  set(gca, 'XScale', 'log');
%  title('Relaksacja lokalna','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('nr iteracji','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('S','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


%  data1 = readtable('glob1.dat');
%  data2 = readtable('glob2.dat');
% 
% 
%  plot(data1.Var1, data1.Var2);
%  hold on;
%  plot(data2.Var1, data2.Var2);
% 
%  
% 
%  legend({'$\omega = 0.6$', '$\omega = 1.0$'},...
%      'Location','best','Orientation','vertical','FontSize', 14, 'FontWeight', 'bold','Interpreter','latex');
%  set(gca, 'XScale', 'log');
%  title('Relaksacja globalna','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('nr iteracji','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('S','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')




figure;
matrix_g1 = readmatrix('glob1_matrix.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap
colorbar
title('Relaksacja globalna, \omega = 0.6','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

figure;
matrix_g2 = readmatrix('glob2_matrix.dat');
mapa2 = pcolor(matrix_g2');
set(mapa2, 'EdgeColor', 'none');
colormap
colorbar
title('Relaksacja globalna, \omega = 1.0','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

