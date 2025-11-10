/*
Dada una lista de números enteros positivos determinar la suma de los
números perfectos mayores que el promedio y la suma de los números
no perfectos menores o iguales al promedio. Un número es perfecto si es
igual a la suma de todos sus divisores menores que el.
*/
// n=5, {6, 12, 13, 28, 19}  prom=15.6, sumP=28, sumNp=25
#include <iostream>
using namespace std;

bool isPerfecto (int x);

int main () {
    int n;
    cout<<"Cantidad de numero: ";
    cin>>n;
    int num[n];
    float prom=0;
    for (int i=0; i<n; i++) {
        cout<<"num["<<i+1<<"]: ";
        cin>>num[i];
        prom=prom+num[i];
    }
    prom=prom/n;

    int sumaPerfect=0;
    int sumaNoPerfect=0;
    for (int i=0; i<n; i++) {
        if (num[i]>prom) {
            if(isPerfecto (num[i])) {
                sumaPerfect=sumaPerfect+num[i];
            }
        }
        if (num[i]<=prom) {
            if(!isPerfecto (num[i])) {
                sumaNoPerfect=sumaNoPerfect+num[i];
            }
        }
    }
    cout<<"Promedio: "<<prom<<endl;
    cout<<"Suma Perfect: "<<sumaPerfect<<endl;
    cout<<"Suma No Perfect: "<<sumaNoPerfect<<endl;
    return 0;
}

bool isPerfecto (int x) {
    int sum=0;
    for (int j=1; j<x; j++) {
        if (x%j==0) {
            sum+=j;
        }
    }
    if (sum==x) {
        return true;
    }
    return false;
}