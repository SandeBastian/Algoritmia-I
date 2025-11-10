/*
La siguiente funcion recibe un valor entero positivo y luego presenta sus divisores
*/
#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

void mostrarDivisores(int x) {
    for (int i = 1; i <=x; i++)
        if (x % i == 0) cout<<i<<" ";
}

int main () {
    int n;
    do {
        cout<<"Ingrese el numero (n>0): ";
        cin>>n;
        if (n<=0) cout<<"Error. Numero invalido."<<endl;
    }while (n<=0);
    cout<<"\nLos divisores de n (SIN FUNCION) son: "<<endl;
    for (int i=1; i<=n; i++) {
        if (n%i==0) {
            cout<<i<<" ";
        }
    }
    cout<<"\nLos divisores de n (CON FUNCION) son: "<<endl;
    mostrarDivisores(n);
    return 0;
}