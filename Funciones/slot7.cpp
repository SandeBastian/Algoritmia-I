/*
Escriba un algoritmo que lea n números enteros positivos en un arreglo y
luego mediante una función determine el valor máximo del arreglo
*/
#include <iostream>
using namespace std;

int mayor(int x[], int n) {
    int max=0;
    for (int i=0; i<n; i++ ) {
        if (x[i]>max) max=x[i];
    }
    return max;
}

int main () {
    int n;
    do {
        cout<<"Ingrese la cantidad de numeros: ";
        cin>>n;
    }while(n<=0);
    int a[n];
    for (int i=0; i<n; i++ ) {
        do {
            cout<<"a["<<i+1<<"]: ";
            cin>>a[i];
        }while (a[i]<=0);
    }
    cout<<"El mayor es: "<<mayor(a,n)<<endl;
    return 0;
}