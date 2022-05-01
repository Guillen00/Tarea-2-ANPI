#include <iostream>
#include "armadillo"
#include <math.h>
#include <chrono>



using namespace std::chrono;
using namespace arma;

int rows = 45;
int col = 30;

// Funcion para llenar la matriz
mat fillMatrix() {
    mat A(rows, col);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < col; ++j) {
            A(i, j) = pow(i+1, 2) + pow(j+1, 2);
        }
    }
    return A;
}

// Función Auxiliar para calcular el factorial de un número 
int factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

// Función para conseguir 
mat sumMatrix(mat x_prev, mat A) {
    mat result(rows, rows);
    int p = 6;
    mat temp = A * x_prev;
    for (int q = 1; q <= p; q++) {
        long double num = (pow(-1, q - 1) * factorial(p));
        long double den = (factorial(q) * factorial(p - q));
        long double frac = num / den;
        result +=  frac * powmat(temp, q-1);
    }
    return result;
}

int main() {
    mat A = fillMatrix();


    // Cálculo de la constante alpha según el método de Newton-Schultz
    long double alpha = 1 / pow(norm(A, 2), 2);
    

    // Valores iniciales de la matriz
    mat x_0 = alpha  *  A.t();


    // Matriz I30 utilizada constantemente
    mat I(col, col);
    I = powmat(I, 0);

    // Valor de la tolerancia 
    long double tol = pow(10, -5);

    //auto start = high_resolution_clock::now();

    // Configura la primera iteración
    mat x_prev = x_0;
    mat x_current = x_0 * sumMatrix(x_0, A);

    // Error
    long double error = norm(x_current*A - I, "fro");
    
    // Bandera para definir si la matriz convergió o no
    bool flag = true;
    
    
    // Calculo de la pseudoinversa
    while (error > tol and flag) {

        
        x_prev = x_current;
        x_current = x_prev * sumMatrix(x_prev, A);
        long double error_prev = error;
        error = norm(x_current * A - I, "fro");
        if (error_prev == error) {
            flag = false;
        }
        
    }

    x_current.print("Matriz pseudoinversa de A:");

    /*
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
    */
   
    return 0;
}