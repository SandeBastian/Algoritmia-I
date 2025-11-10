/*
Escriba un algoritmo que reciba dos listas de números enteros de n y m
elementos respectivamente y determine la suma del mayor número
perfecto de cada lista. Utilice una función para determinar el mayor
número perfecto de un arreglo. Si no hubiera número perfecto la función
debe devolver cero
*/
#include <iostream>
using namespace std;
bool isPerfect(int x) {
    int suma=0;
    if (x==1) return false;
    for (int i=1; i<x; i++) {
        if (x%i==0) {
            suma+=i;
        }
    }
    return suma==x;   //esto es mas elegante
}
int mayorPerfecto(int x[],int n) {
    int mayor=0;
    for (int i=0; i<n; i++) {
        if (isPerfect(x[i])&&x[i]>mayor) {
            mayor=x[i];
        }
    }
    return mayor;
}
int main() {
    int m;
    do {
        cout<<"Cantidad de numeros: ";
        cin>>m;
        if (m<=0) cout<<"Error. Valor no valido."<<endl;
    }while (m<=0);
    int a[m];
    for (int i=0; i<m; i++) {
        cout<<"a["<<i+1<<"]: ";
        cin>>a[i];
    }
    int n;
    do {
        cout<<"Cantidad de numeros: ";
        cin>>n;
        if (n<=0) cout<<"Error. Valor no valido."<<endl;
    }while (n<=0);
    int b[n];
    for (int i=0; i<n; i++) {
        cout<<"b["<<i+1<<"]: ";
        cin>>b[i];
    }
    cout<<"La suma de los mayores perfectos de a y b es: "<<mayorPerfecto(a,m)+mayorPerfecto(b,n)<<endl;
    return 0;
}