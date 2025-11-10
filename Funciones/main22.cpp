/*
*Escribir un algoritmo que reciba un número entero positivo n y mediante
una función recursiva determine el valor del termino n-ésimo de la serie de
Fibonacci.
*/
#include <iostream>
using namespace std;

long long fib(int x) {
    if (x==0||x==1) return 1;
    return (fib(x-1)+fib(x-2));
}

int main () {
    long long n;
    cout<<"Ingrese la posicion del termino de Fibonacci: ";
    cin>>n;
    cout<<"El numero de Fibonacci de la posicion "<<n<<" es: "<<fib(n-1);
    return 0;
}