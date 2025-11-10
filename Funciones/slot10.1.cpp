#include <iostream>
using namespace std;

void arrminmaxprom (int a[], int n, int &max, int &min, float &prom) {
    min=a[0]; max=a[0]; prom=0;
    for (int i=0; i<n; i++) {
        if (a[i]>max) max=a[i];
        if (a[i]<min) min=a[i];
        prom+=a[i];
    }
    prom=prom/n;
}

int main() {
    int n, max=0, min=0;
    float prom=3.99;
    do {
        cout<<"Ingrese la cantida de numeros: ";
        cin>>n;
        if (n<=0) cout<<"Error. Valor no valido."<<endl;
    }while (n<=0);

    int a[n]={0};
    for (int i=0; i<n; i++ ) {
        cout<<"a["<<i+1<<"]:";
        cin>>a[i];
    }
    cout<<"\nAntes de la Funcion: "<<endl;
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
    cout<<"Prom: "<<prom<<endl;
    arrminmaxprom(a, n, max, min, prom);
    cout<<"\nDespues del Arreglo: "<<endl;
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
    cout<<"Prom: "<<prom<<endl;
    return 0;
}