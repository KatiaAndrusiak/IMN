set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

 data1 = readtable('trapez1.dat');
 data2 = readtable('trapez2.dat');


 plot(data1.Var3, data1.Var4, 'b');
 hold on;
 plot(data2.Var3, data2.Var4, 'r');

 legend({'$TOL = 10^{-2}$', '$TOL = 10^{-5}$'},...
     'Location','best','Orientation','vertical','FontSize', 14, 'FontWeight', 'bold','Interpreter','latex');
 
 title('Metoda trapezów','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('v(x)','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

%  data1 = readtable('rk2_1.dat');
%  data2 = readtable('rk2_2.dat');
% 
% 
%  plot(data1.Var3, data1.Var4, 'b');
%  hold on;
%  plot(data2.Var3, data2.Var4, 'r');
% 
%  legend({'$TOL = 10^{-2}$', '$TOL = 10^{-5}$'},...
%      'Location','best','Orientation','vertical','FontSize', 14, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('Metoda RK2','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('x','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('v(x)','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')