% Funcion para solucionar cada componente de la solucion
% de manera paralela
% Entradas:
  % A: matriz tridiagonal de coeficientes
  % b: vector de constantes
  % xk: vector solucion para la iteracion k
  % i: numero de la solucion
% Salidas: xi_km1: vector solucion para la iteracion k+1
function xi_km1 = calcular_xi(A,b,xk,i)
  m = size(A,1);
  sumatoria = 0;
  for j=1:m %Sumatoria que es parte de xi_km1
    if j != i
      sumatoria += A(i,j)*xk(j);  
    endif
  endfor
  xi_km1 = (1/A(i,i))*(b(i)- sumatoria); %Calculo final de xi_km1
endfunction



