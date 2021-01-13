% set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');
% 
% subplot(2,1,1)
% matrix_g1 = readmatrix('vx.dat');
% mapa = pcolor(matrix_g1');
% set(mapa, 'EdgeColor', 'none');
% colormap turbo
% colorbar
% caxis([-5 45])
% title('Vx','FontSize', 20);
% xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
% ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
% 
% subplot(2,1,2)
% matrix_g1 = readmatrix('vy.dat');
% mapa = pcolor(matrix_g1');
% set(mapa, 'EdgeColor', 'none');
% colormap turbo
% colorbar
% caxis([-20 20])
% title('Vy','FontSize', 20);
% xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
% ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


data = readtable('c_xsr_2.dat');

subplot(3,2,6);
plot(data.Var1, data.Var2, 'b');
hold on;
plot(data.Var1, data.Var3, 'r');
legend({'$c(t)$', '$x_s(t)$'},...
     'Location','best','Orientation','vertical','FontSize', 10, 'FontWeight', 'bold','Interpreter','latex');
 xlabel('t','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(3,2,1);
matrix_g1 = readmatrix('map2.dat','Range','1:401');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo

 subplot(3,2,2);
matrix_g1 = readmatrix('map2.dat','Range','405:805');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
subplot(3,2,3);
matrix_g1 = readmatrix('map.dat','Range','809:1209');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo

subplot(3,2,4);
matrix_g1 = readmatrix('map2.dat','Range','1213:1613');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo

subplot(3,2,5);
matrix_g1 = readmatrix('map2.dat','Range','1617:2017');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
 
sgtitle('D = 0.1','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');