/*
Crear una función recursiva que permita recibir un arreglo de elementos
reales y la cantidad de estos almacenados. Luego la función nos retorne el
menor elemento de arreglo.
Ejemplo:
La función recibe:
arreglo: 1, 3, 4, -2
# de elemento: 4
La función retorna: -2
*/
#include <iostream>
using namespace std;

int menor(int a[], int n) {
    if (n==1) {
        return a[0];
    }else {
        if (a[n-2]>a[n-1]) {
            a[n-2] = a[n-1];
            return a[n-1];
        }
    }
}

int main () {
    int a[4]={1, 3, 4, -2};
    cout<<"Menor del areglo: "<<menor(a,4)<<endl;
    return 0;
}