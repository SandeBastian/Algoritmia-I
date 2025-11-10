/*
Dada una lista de números enteros positivos determinar la suma de los
números perfectos mayores que el promedio y la suma de los números
no perfectos menores o iguales al promedio. Un número es perfecto si es
igual a la suma de todos sus divisores menores que el.
*/
#include <iostream>
using namespace std;
int main () {
    int n;
    cout<<"Cantidad de numero: ";
    cin>>n;
    int num[n];
    int prom=0;
    for (int i=0; i<n; i++) {
        cout<<"num["<<i+1<<"]: ";
        cin>>num[i];
        prom=prom+num[i];
    }
    prom=prom/n;

    int sumaPerfect=0;
    int sumaNoPerfect=0;
    for (int i=0; i<n; i++) {
        bool isperfect=false;
        int sum=0;
        for (int j=1; j<num[i]; j++) {
            if (num[i]%j==0) {
                sum+=j;
            }
        }
        if (sum==num[i]) {
            isperfect=true;
        }
        if (isperfect&&num[i]>prom) {
            cout<<"NumP["<<i+1<<"]: "<<num[i]<<endl;
            sumaPerfect=sumaPerfect+num[i];
        }
        if (!isperfect&&num[i]<=prom) {
            cout<<"numNP["<<i+1<<"]: "<<num[i]<<endl;
            sumaNoPerfect=sumaNoPerfect+num[i];
        }
    }
    cout<<"Promedio: "<<prom<<endl;
    cout<<"Suma Perfect: "<<sumaPerfect<<endl;
    cout<<"Suma No Perfect: "<<sumaNoPerfect<<endl;
    return 0;
}