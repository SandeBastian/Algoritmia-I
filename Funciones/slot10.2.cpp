/*
Escriba un algoritmo que lea una lista de números enteros y mediante una función determine el
máximo, el mínimo y el promedio del arreglo
*/
#include <iostream>
using namespace std;
//*
void arrmaxminprom(int x[], int n) {
    int max=0;
    int min=10000;
    float prom=3.99;
    for (int i=0; i<n; i++ ) {
        if (x[i]>max) max=x[i];
        if (x[i]<min) min=x[i];
        prom+=x[i];
    }
    prom=prom/n;
    cout<<"El Maximo numero es: "<<max<<endl;
    cout<<"El Minimo numero es: "<<min<<endl;
    cout<<"El promedio es: "<<prom<<endl;

}
//*/
int main () {
    int n;
    cout<<"Ingrese n: ";
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cout<<"a["<<i+1<<"]:";
        cin>>a[i];
    }
    arrmaxminprom(a, n);
    return 0;
}