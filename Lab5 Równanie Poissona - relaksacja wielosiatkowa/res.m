set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

 data = readtable('rel_w.dat');

 plot(data.Var1(1:81), data.Var2(1:81));
 hold on;
 plot(data.Var1(83:213), data.Var2(83:213));
  hold on;
 plot(data.Var1(217:371), data.Var2(217:371));
  hold on;
 plot(data.Var1(373:510), data.Var2(373:510));
  hold on;
 plot(data.Var1(511:516), data.Var2(511:516));
 

 legend({'$k = 16$', '$k = 8$','$k = 4$', '$k = 2$', '$k = 1$'},...
     'Location','best','Orientation','vertical','FontSize', 14, 'FontWeight', 'bold','Interpreter','latex');
 
 title('Relaksacja wielosiatkowa','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('nr iteracji','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('S','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
 
 figure;

 
matrix_g1 = readmatrix('rel_w_1.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
title('k=1','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

 figure;

 
matrix_g1 = readmatrix('rel_w_2.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
title('k=2','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

 figure;

 
matrix_g1 = readmatrix('rel_w_4.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
title('k=4','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
 
 figure;

 
matrix_g1 = readmatrix('rel_w_8.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
title('k=8','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

 figure;

 
matrix_g1 = readmatrix('rel_w_16.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
title('k=16','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
