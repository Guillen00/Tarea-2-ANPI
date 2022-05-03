% Calculo de aceleraciones del metodo de Jacobi de manera secuencial y paralela.
% Salidas: Sp: vector con las aceleraciones
function Sp = parte1_p4()
  
  %Tiempo metodo secuancial
  tic(); parte1_p2(); Ts = toc();
  
  % Tiempo metodo en paralelo
  pMax = 8; %Procesadores maximos del computador
  Tp = [];
  for i=1:pMax-1
    tic(); parte1_p3(i); Tp(i)= toc();
    Sp(i) = Ts/Tp(i); %Aceleracion para cada numero de procesadores
    printf('Para %i procesadores, la aceleraci�n es %d \n',i,Sp(i));
  endfor

  stem([1:pMax-1],Sp)
  title("Aceleraci�n del m�todo de Jacobi")
  ylabel('Aceleraci�n')
  xlabel('N�mero de procesadores')
  
endfunction