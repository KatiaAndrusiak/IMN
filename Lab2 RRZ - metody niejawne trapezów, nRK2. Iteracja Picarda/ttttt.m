set(0,'DefaultAxesFontSize',15,'DefaultAxesFontName','Arial Cyr');
% data = readtable('picarda.dat');
% 
% 
% plot(data.Var1, data.Var2, 'b', 'LineWidth', 5);
%  hold on;
%  plot(data.Var1, data.Var3, 'r', 'LineWidth', 5);
% 
%  legend({'$u(t)$', '$z(t)$'},...
%      'Location','best','Orientation','vertical','FontSize', 16, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('Metoda Picarda','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')

% data = readtable('newtona.dat');
% 
% 
% plot(data.Var1, data.Var2, 'b', 'LineWidth', 5);
%  hold on;
%  plot(data.Var1, data.Var3, 'r', 'LineWidth', 5);
% 
%  legend({'$u(t)$', '$z(t)$'},...
%      'Location','best','Orientation','vertical','FontSize', 16, 'FontWeight', 'bold','Interpreter','latex');
%  
%  title('Iteracja Newtona','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
%  xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
%  ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')
 
 data = readtable('rk2.dat');


 plot(data.Var1, data.Var2, 'b', 'LineWidth', 5);
 hold on;
 plot(data.Var1, data.Var3, 'r', 'LineWidth', 5);

 legend({'$u(t)$', '$z(t)$'},...
     'Location','best','Orientation','vertical','FontSize', 16, 'FontWeight', 'bold','Interpreter','latex');
 
 title('RK2','FontSize', 20, 'Color', 'k', 'FontWeight', 'bold');
 xlabel('t','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold') 
 ylabel('y','FontSize', 15, 'Color', 'k', 'FontWeight', 'bold')