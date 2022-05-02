#include <iostream>
#include "armadillo"
#include <math.h>

using namespace std;
using namespace arma;

int rows = 17;
int col = 3;

int factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

mat sumMatrix(mat x_prev, mat A) {
    mat result(rows, rows);
    int p = 6;
    mat temp = A * x_prev;
    for (int q = 1; q <= p; q++) {
        long double num = (pow(-1, q - 1) * factorial(p));
        long double den = (factorial(q) * factorial(p - q));
        long double frac = num / den;
        result += frac * powmat(temp, q - 1);
    }
    return result;
}

Mat<double> pseudoinversa() {
    mat A;

    A   << 1 << 0.4160 << pow(0.4160, 2) << endr
        << 1 << 0.4030 << pow(0.4030, 2) << endr
        << 1 << 0.3900 << pow(0.3900, 2) << endr
        << 1 << 0.3770 << pow(0.3770, 2) << endr
        << 1 << 0.3630 << pow(0.3630, 2) << endr
        << 1 << 0.3490 << pow(0.3490, 2) << endr
        << 1 << 0.3340 << pow(0.3340, 2) << endr
        << 1 << 0.3190 << pow(0.3190, 2) << endr
        << 1 << 0.3020 << pow(0.3020, 2) << endr
        << 1 << 0.2670 << pow(0.2670, 2) << endr
        << 1 << 0.2470 << pow(0.2470, 2) << endr
        << 1 << 0.2250 << pow(0.2250, 2) << endr
        << 1 << 0.2020 << pow(0.2020, 2) << endr
        << 1 << 0.1750 << pow(0.1750, 2) << endr
        << 1 << 0.1430 << pow(0.1430, 2) << endr
        << 1 << 0.1010 << pow(0.1010, 2) << endr
        << 1 << 0.0000 << pow(0.0000, 2) << endr;



    // Cálculo de la constante alpha según el método de Newton-Schultz
    long double alpha = 1 / pow(norm(A, 2), 2);


    // Valores iniciales de la matriz
    mat x_0 = alpha * A.t();


    // Matriz I30 utilizada constantemente
    mat I(col, col);
    I = powmat(I, 0);


    // Valor de la tolerancia 
    long double tol = pow(10, -5);

    // Configura la primera iteración
    mat x_prev = x_0;
    mat x_current = x_0 * sumMatrix(x_0, A);

    // Error
    long double error = norm(x_current * A - I, "fro");

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

    return x_current;
}


int main() {
    mat b;

    b   << 0.85 << endr
        << 0.80 << endr
        << 0.75 << endr
        << 0.70 << endr
        << 0.65 << endr
        << 0.60 << endr
        << 0.55 << endr
        << 0.50 << endr
        << 0.45 << endr
        << 0.35 << endr
        << 0.30 << endr
        << 0.25 << endr
        << 0.20 << endr
        << 0.15 << endr
        << 0.10 << endr
        << 0.05 << endr
        << 0.00 << endr;

    mat A = pseudoinversa();
    mat C;
    C = A * b;
    
    C.print("Parametros de funcion");

    cout << "Gravedad: " << 2 * C.rows(2, 2) << endl;;

    return 0;
}
