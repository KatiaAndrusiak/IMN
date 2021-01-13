set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

subplot(2,3,1)
matrix_g1 = readmatrix('T.dat','Range','1:41');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap cool
colorbar
title('it=100','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,2)
matrix_g1 = readmatrix('T.dat','Range','42:82');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=200','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,3,3)
matrix_g1 = readmatrix('T.dat','Range','83:123');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=500','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,4)
matrix_g1 = readmatrix('T.dat','Range','124:164');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=1000','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,5)
matrix_g1 = readmatrix('T.dat','Range','165:205');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=2000','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
sgtitle('T(x,y)','FontSize', 16, 'Color', 'k', 'FontWeight', 'bold');

figure;
subplot(2,3,1)
matrix_g1 = readmatrix('nT.dat','Range','1:39');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap cool
colorbar
title('it=100','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,2)
matrix_g1 = readmatrix('nT.dat','Range','41:79');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=200','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,3,3)
matrix_g1 = readmatrix('nT.dat','Range','81:119');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=500','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,4)
matrix_g1 = readmatrix('nT.dat','Range','121:159');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=1000','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,3,5)
matrix_g1 = readmatrix('nT.dat','Range','161:199');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap jet
colorbar
title('it=2000','FontSize', 14);
xlabel('x','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 12, 'Color', 'k', 'FontWeight', 'bold')
sgtitle('\nabla^2T(x,y)','FontSize', 16, 'Color', 'k', 'FontWeight', 'bold');
