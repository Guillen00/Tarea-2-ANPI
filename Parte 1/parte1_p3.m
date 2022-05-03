% Implementacion metodo de Jacobi en paralelo

function x = parte1_p3(nproc)
  p = q = [1:0.1:25];
  m = 242;
  A = tridiagonal(p,q,m);
  b = ones(m,1); 
  x0 = zeros(m,1);
  tol = 10e-5; 
  iterMax = 1000;
  x = jacobi_paralelo(A,b,x0,nproc,tol,iterMax);
endfunction


% Implementacion metodo de Jacobi en paralelo
% Entradas: 
  % A: matriz tridiagonal de coeficientes
  % b: vector de constantes
  % x0: vector inicial
  % tol: tolerancia maxima de error del resultado
  % iterMax: cantidad maxima de iteraciones
% Salidas: x: vector solucion del sistema
function xk = jacobi_paralelo(A,b,x0,nproc,tol,iterMax)
  m = size(A,1);
  xk = x0;
  val_i = 1:m; %Vector de valores de i para los que se va a evaluar la funcion
  
  pkg load parallel
  for k=1:iterMax
    f = @(i) calcular_xi(A,b,xk,i); %Funcion que se va a evaluar para cada i
    xkm1 = pararrayfun(nproc,f,val_i)'; %Ejecuciones en paralelo
    error = norm(A*xk-b); %Error para la iteracion
    if error < tol
      break
    endif
    xk = xkm1;
  endfor
endfunction


