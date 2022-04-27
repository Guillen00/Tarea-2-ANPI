from sympy import sympify
from sympy import Symbol
from sympy import diff
from sympy import solve
import sympy
import math
from numpy import linalg as LA
import numpy as np
import matplotlib.pyplot as plt

def newton_raphson(x0, f, x, tol, iterMax):

    """
    Este método contiene la implementación del algoritmo Newton Raphson
    para la solución de sistemas de ecuaciones con múltiples variables.
    
    Sintaxis: newton_raphson(fun, x0, tol, iterMax)
    
    Parámetros Iniciales: 
                f = lista con las funciones a evaluar.
                x0 = vector con los valores iniciales de las variables.
                tol = un número positivo que representa a la tolerancia para el criterio ||f(xk)|| < tol
                iterMax = cantidad de iteraciones máximas
                
    Parámetros de Salida: 
                xk = vector con los valores de la aproximación.
                k = número de iteraciones realizados
                error = ||f(x)||
                
    """
    
    variables = [sympy.symbols(v) for v in x]
    cantidad_vars = len(x)

    if (tol <= 0):
        
        print ("El valor de la tolerancia no es valido")
        return False
    
    else:

        k = 1
        error = tol + 1
        e = []
        vectorF = []
        vectorIteracionesK = []

        while (error > tol and k < iterMax):
            i = 0
            
            while (i < cantidad_vars):
                funcion = sympify(f[i])

                j=0
                fk = funcion.subs(variables[j], x0[j]).evalf()

                while (j < cantidad_vars):
                    fk = fk.subs(variables[j], x0[j]).evalf()
                    j += 1
                    
                vectorF.append(fk)
                i += 1
                
            i = 0

            # Calculando el error.
            vectorArray = np.array(vectorF, dtype=np.float64)
            error = LA.norm(vectorArray)

            e.append(error)
            J = []

            # Calculando el jacobiano
            while (i < cantidad_vars):

                # Se pasa "f" a una matriz de sympy
                funciones = sympy.Matrix(f)

                # Se pasa "variables" a una matriz de sympy
                argumentos = sympy.Matrix(variables)
                Jk = funciones.jacobian(argumentos)

                j=0
                Je = Jk.subs(variables[j], x0[j]).evalf()

                
                while (j < cantidad_vars):
                    Je = Je.subs(variables[j], x0[j]).evalf()
                    j +=1
                    
                J.append(Je)
                i += 1
                
            # Calculando y para los proximos valores iniciales.    
            Jf = sympy.Matrix(J[0])**-1
            vF = sympy.Matrix(vectorF)
            y = Jf * vF

            # Actualizacion de variables.
            xk = sympy.Matrix(x0)
            x0 = xk - y
            vectorIteracionesK.append(k)
            k += 1
            
            # Reinicio de variables.
            vectorF = []
            i = 0
            
        print ("Soluciones: ", x0)
        print ("Error: ", error)
        print ("Iteraciones: ", k)
        plt.plot(vectorIteracionesK, e)
        plt.show()
        return (x0, error, k)


#tol = 10**-15;
#x = ['x', 'y', 'z'];
#f = ['cos(y)-cos(x)' , 'z^x - 1/y' , 'exp(x)-z^2'];
#f = ['x^2 + y^2 + z^2 - 1' , '2*x^2 + y^2 - 4*z' , '3*x^2 - 4*y + z^2'];

#x0 = [0.5, 0.5, 0.5];
#iterMax = 100;
#newton_raphson(x0, f, x, tol, iterMax)            


