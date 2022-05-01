% Se declaran las variables para construir la
% matriz tridiagonal
p=[1:0.1:25];
q=[1:0.1:25];
m=242;
% Esta es la matriz A que se va a resolver
A=tridiagonal(p,q,m);
% Vector de resultados del sistema de ecuaciones
b=ones(m,1);
% Vector inicial de soluciones
x0=zeros(m,1);
%variables para las iteraciones
tol=10e-5;
iterMax=1000;
%Se llama a la función con los valores antes 
%definidos para obtener el resultados
[xk,k,error]=sol_jacobi(A,b,x0,iterMax,tol);