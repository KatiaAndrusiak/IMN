set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');

%  %euler, rk2, rk4
%  data = readtable('RK4.dat');
% % 
%  %figure;
%  plot(data.Var1(1:499), data.Var3(1:499), 'k', 'LineWidth', 7);
%  hold on;
%  plot(data.Var1(1:499), data.Var2(1:499), 'r', 'LineWidth', 5);
%  hold on;
%  plot(data.Var1(500:548), data.Var2(500:548), 'b', 'LineWidth', 3);
%  hold on;
%  plot(data.Var1(549:553), data.Var2(549:553), 'm', 'LineWidth',3);
% 
%  legend({'$y(t) = e^{\lambda t}$', '$\Delta t = 0.01$', '$\Delta t = 0.1$', '$\Delta t = 1.0$'},...
%      'Location','best','Orientation','vertical','FontSize', 20, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('Metoda jawna RK4','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
 


% %blad 
%  data = readtable('RK4.dat');
% 
%  plot(data.Var1(1:499), data.Var4(1:499), 'k', 'LineWidth', 3);
%  hold on;
%  plot(data.Var1(500:548), data.Var4(500:548), 'r', 'LineWidth', 3);
%  hold on;
%  plot(data.Var1(549:553), data.Var4(549:553), 'b', 'LineWidth',3);
%  set(gca, 'YScale', 'log');
%  legend({ '$\Delta t = 0.01$', '$\Delta t = 0.1$', '$\Delta t = 1.0$'},...
%      'Location','best','Orientation','vertical','FontSize', 20, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('RK4 - błąd globalny','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%   
%  xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('\delta (t)','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')



% % I(t) Q(t) 
%  data1 = readtable('RRZ_1.dat');
%  data2 = readtable('RRZ_2.dat');
%  data3 = readtable('RRZ_3.dat');
%  data4 = readtable('RRZ_4.dat');

%  %figure;
%  plot(data1.Var1, data1.Var3, 'k', 'LineWidth', 2);
%  hold on;
%  plot(data2.Var1, data2.Var3, 'r', 'LineWidth', 2);
%  hold on;
%  plot(data3.Var1, data3.Var3, 'b', 'LineWidth', 2);
%  hold on;
%  plot(data4.Var1, data4.Var3, 'm', 'LineWidth',2);
% 
%  legend({'$0.5\omega_{0}$', '$0.8\omega_{0}$', '$1.0\omega_{0}$', '$1.2\omega_{0}$'},...
%      'Location','best','Orientation','vertical','FontSize', 20, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('Metoda RK4 I(t)','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('I(t)','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
 
 
 
 
 
 
 

 
 

































