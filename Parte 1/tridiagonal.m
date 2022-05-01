% Construye una matriz tridiagonal partir de los parametros de entrada dados:
%  p: vector correspondiente a la diagonal inferior con tamaño m-1.
%  q: vector correspondiente a la diagonal superior con tamaño m-1.
%  m: dimension de la matriz cuadrada
% La salida es:
%  A: matriz mxm diagonalmente dominante.
function A=tridiagonal(p,q,m)
    A=zeros(m);
    A(1,1)=2*q(1); A(1,2)=q(1); % Se definen los valores de la primera fila
    A(m,m)=2*p(m-1); A(m,m-1)=p(m-1); %Valores de la ultima fila
    for i=2:m-1             % Filas restantes
        A(i,i)=2*(p(i-1)+q(i));
        A(i,i-1)=p(i-1);
        A(i,i+1)=q(i);
    end
  end