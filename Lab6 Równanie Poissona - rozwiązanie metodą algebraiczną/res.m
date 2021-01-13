function c = redblue(m)
%REDBLUE    Shades of red and blue color map
%   REDBLUE(M), is an M-by-3 matrix that defines a colormap.
%   The colors begin with bright blue, range through shades of
%   blue to white, and then through shades of red to bright red.
%   REDBLUE, by itself, is the same length as the current figure's
%   colormap. If no figure exists, MATLAB creates one.
%
%   For example, to reset the colormap of the current figure:
%
%             colormap(redblue)
%
%   See also HSV, GRAY, HOT, BONE, COPPER, PINK, FLAG, 
%   COLORMAP, RGBPLOT.
%   Adam Auton, 9th October 2009
if nargin < 1, m = size(get(gcf,'colormap'),1); end
if (mod(m,2) == 0)
    % From [0 0 1] to [1 1 1], then [1 1 1] to [1 0 0];
    m1 = m*0.5;
    r = (0:m1-1)'/max(m1-1,1);
    g = r;
    r = [r; ones(m1,1)];
    g = [g; flipud(g)];
    b = flipud(r);
else
    % From [0 0 1] to [1 1 1] to [1 0 0];
    m1 = floor(m*0.5);
    r = (0:m1-1)'/max(m1,1);
    g = r;
    r = [r; ones(m1+1,1)];
    g = [g; 1; flipud(g)];
    b = flipud(r);
end
c = [r g b]; 

set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');
subplot(1,3,1);
matrix_g1 = readmatrix('V_50.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
title('nx=ny=50','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

subplot(1,3,2);
matrix_g1 = readmatrix('V_100.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
title('nx=ny=100','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

subplot(1,3,3);
matrix_g1 = readmatrix('V_200.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
caxis([-0.6 0.6])
title('nx=ny=200','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


sgtitle('Mapy potencjału, \epsilon1=\epsilon2=1.0','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');

figure;
subplot(1,3,1);
matrix_g1 = readmatrix('V_eps1.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
caxis([-0.8 0.8])
title('eps1 = eps2 =1.0','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

subplot(1,3,2);
matrix_g1 = readmatrix('V_eps2.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
caxis([-0.8 0.8])
title('eps1=1.0 eps2=2.0','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

subplot(1,3,3);
matrix_g1 = readmatrix('V_eps3.dat');
mapa = pcolor(matrix_g1);
set(mapa, 'EdgeColor', 'none');
colormap(c)
colorbar
caxis([-0.8 0.8])
title('eps1=1.0 eps2=10.0','FontSize', 20);
xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')


sgtitle('Mapy potencjału, nx=ny=100','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');