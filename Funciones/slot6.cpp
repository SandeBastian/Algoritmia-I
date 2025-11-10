/*Dada una lista de números enteros positivos determinar la suma de los
números perfectos mayores que el promedio y la suma de los números
no perfectos menores o iguales al promedio. Un número es perfecto si es
igual a la suma de todos sus divisores menores que el.
*/
bool isPerfect(int x) {
    int suma=0;
    if (x==1) return false;
    for (int i=1; i<x; i++) {
        if (x%i==0) {
            suma+=i;
        }
    }
    if (suma==x) return true;
    else return false;
    //return suma==x;   //esto es mas elegante
}
#include <iostream>
using namespace std;
int main () {
    int n;
    cout<<"Ingrese la cantidad de numeros: ";
    cin>>n;
    int a[n];
    float prom=0;
    for (int i=0; i<n; i++) {
        cout<<"a["<<i+1<<"]: "; cin>>a[i];
        prom=prom+a[i];
    }
    prom=prom/n;

    int sumaPerfect=0;
    int sumaNoPerfect=0;

    for (int i=0; i<n; i++) {
        if (isPerfect(a[i])&&a[i]>prom) {
            sumaPerfect+=a[i];
        }
        if (!isPerfect(a[i])&&a[i]<=prom) {
            sumaNoPerfect+=a[i];
        }
    }
    cout<<"El promedio es: "<<prom<<endl;
    cout<<"Suma de numeros perfectos mayores al promedio: "<<sumaPerfect<<endl;
    cout<<"Suma de numero no perefecto menores o iguales al promedio: "<<sumaNoPerfect<<endl;
    return 0;
}