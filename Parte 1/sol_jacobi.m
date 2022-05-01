% Metodo de Jacobi para resolver sistemas de ecuaciones:
%  A: matriz que se va a resolver.
%  b: Vector de resultados del sistema de ecuaciones.
%  x0: vector inicial de soluciones.
%  iterMax: numero de iteraciones máximas.
%  tol: valor mínimo aceptable para el error.
% Las salida son:
%  xk: vector final de soluciones.
%  k: numero de iteraciones.
%  error: valor del error obtenido.
function [xk,k,error]=sol_jacobi(A,b,x0,iterMax,tol)
  xk=x0;
  m=size(A,1);
  
  for k=1:iterMax
    
    for i=1:m
      %Se realiza la sumatoria desde j=1:m pero con j=!i
      sum=A(i,1:i-1)*xk(1:i-1)+A(i,i+1:m)*xk(i+1:m);
      xk(i)=(b(i)-sum)/A(i,i);      
    endfor
    
    error=norm(A*xk-b);
    
    if error<tol
      break
    end
    
  end
  
end