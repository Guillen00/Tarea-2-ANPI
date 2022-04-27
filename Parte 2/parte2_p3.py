from parte2_p2 import *
from sympy import *

def funcion_a():
    print("Funcion A")
    x       = ['x_1', 'x_2']
    f       = ['exp(x_1**2) - exp(sqrt(2)*x_1)', 'x_1 - x_2']
    x0      = [ 1.8 , 1.8 ]
    tol     = 10**-12
    iterMax = 100
    newton_raphson(x0, f, x, tol, iterMax)
    print("----------------------------------------------------")

def funcion_b():
    print("Funcion B")
    x       = ['x_1', 'x_2']
    f       = ['x_1 + exp(x_2) - cos(x_2)', '3*x_1 - x_2 - sin(x_2)']
    x0      = [ 0.3 , 0.5 ]
    tol     = 10**-12
    iterMax = 100
    newton_raphson(x0, f, x, tol, iterMax)
    print("----------------------------------------------------")

def funcion_c():
    print("Funcion C")
    x       = ['x_1', 'x_2']
    f       = ['x_1**2 - 2*x_1 - x_2 + 0.5', 'x_1**2 + 4*x_2**2-4']
    x0      = [ 3 , 2 ]
    tol     = 10**-12
    iterMax = 100
    newton_raphson(x0, f, x, tol, iterMax)
    print("----------------------------------------------------")

def funcion_d():
    print("Funcion D")
    x       = ['x_1', 'x_2']
    f       = ['x_1**2 + x_2**2 - 1', 'x_1**2 - x_2**2 + 0.5']
    x0      = [ 0.7 , 1.2]
    tol     = 10**-12
    iterMax = 100
    newton_raphson(x0, f, x, tol, iterMax)
    print("----------------------------------------------------")

def funcion_e():
    print("Funcion E")
    x       = ['x_1', 'x_2']
    f       = ['sin(x_1) + x_2*cos(x_1) ', 'x_1 - x_2']
    x0      = [ 1.2 , -1.5]
    tol     = 10**-12
    iterMax = 100
    newton_raphson(x0, f, x, tol, iterMax)
    print("----------------------------------------------------")

funcion_a()
funcion_b()
funcion_c()
funcion_d()
funcion_e()

      


