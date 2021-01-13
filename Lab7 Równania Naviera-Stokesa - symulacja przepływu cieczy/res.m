set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

matrix_g1 = readmatrix('rel_psi_1000.dat');
subplot(2,2,1)
contour( matrix_g1' ,400)
colorbar 
caxis([-55 -50])
title('\psi(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



matrix_g1 = readmatrix('rel_zeta_1000.dat');
subplot(2,2,2)
contour( matrix_g1' ,200)
colorbar 
caxis([-200 300])
title('\zeta(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,2,3)
matrix_g1 = readmatrix('rel_u_1000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-2 16])
title('u(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


subplot(2,2,4)
matrix_g1 = readmatrix('rel_v_1000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-6 1])
title('v(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

sgtitle('Q = -1000','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');


figure;
matrix_g1 = readmatrix('rel_psi_4000.dat');
subplot(2,2,1)
contour( matrix_g1' ,400)
colorbar 
caxis([-218 -202])
title('\psi(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


matrix_g1 = readmatrix('rel_zeta_4000.dat');
subplot(2,2,2)
contour( matrix_g1' ,200)
colorbar 
caxis([-600 1100])
title('\zeta(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,2,3)
matrix_g1 = readmatrix('rel_u_4000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-10 70])
title('u(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,2,4)
matrix_g1 = readmatrix('rel_v_4000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-14 4])
title('v(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



sgtitle('Q = -4000','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');


figure;
matrix_g1 = readmatrix('rel_psi_p4000.dat');
subplot(2,2,1)
contour( matrix_g1' ,500)
colorbar 
caxis([202 220])
title('\psi(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

matrix_g1 = readmatrix('rel_zeta_p4000.dat');
subplot(2,2,2)
contour( matrix_g1' ,200)
colorbar 
caxis([-500 1300])
title('\zeta(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,2,3)
matrix_g1 = readmatrix('rel_u_p4000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-70 10])
title('u(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



subplot(2,2,4)
matrix_g1 = readmatrix('rel_v_p4000.dat');
mapa = pcolor(matrix_g1');
set(mapa, 'EdgeColor', 'none');
colormap turbo
colorbar
caxis([-4 15])
title('v(x,y)','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



sgtitle('Q = 4000','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
