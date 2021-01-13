subplot(2,2,1);
matrix_g1 = readmatrix('u1.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap 
colorbar
 xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
 title('\beta = 0.0, \alpha = 0.0 ','FontSize', 14);
 
subplot(2,2,2);
matrix_g1 = readmatrix('u2.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap 
colorbar
 xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
 title('\beta = 0.1, \alpha = 0.0 ','FontSize', 14);
 
subplot(2,2,3);
matrix_g1 = readmatrix('u3.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap 
colorbar
 xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
 title('\beta = 1.0, \alpha = 0.0 ','FontSize', 14);
 
subplot(2,2,4);
matrix_g1 = readmatrix('u4.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap 
colorbar
 xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
 title('\beta = 1.0, \alpha = 1.0 ','FontSize', 14);
 
 sgtitle('u(x,t)','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
% data1 = readtable('E1.dat');
% data2 = readtable('E2.dat');
% data3 = readtable('E3.dat');
% 
% subplot(1,2,1);
% plot(data1.Var1, data1.Var2);
% hold on;
% plot(data2.Var1, data2.Var2);
% hold on;
% plot(data3.Var1, data3.Var2);
% legend({'$\beta = 0.0$', '$\beta = 0.1$', '$\beta = 1.0$'},...
%      'Location','best','Orientation','vertical','FontSize', 10, 'FontWeight', 'bold','Interpreter','latex');
%  xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('E','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
%  title('E(t), \alpha = 0.0 ','FontSize', 16);
%  
%  data4 = readtable('E4.dat');
%  
%  subplot(1,2,2);
%  plot(data4.Var1, data4.Var2);
%  legend({'$\beta = 1.0$'},...
%      'Location','best','Orientation','vertical','FontSize', 10, 'FontWeight', 'bold','Interpreter','latex');
%  xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('E','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
%  title('E(t), \alpha = 1.0 ','FontSize', 16);
%  