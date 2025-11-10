/*
Escriba un algoritmo que lea los elementos de una matriz de n x m de
numeros enteros y mediante una funcion calcule el MODO de la matriz.
Asuma que el MODO de una matriz es el maximo valor absoluto de la
sumas de las filas de la matriz. Utilizar una funcion que devuelva el valor
absoluto de un numero.

*/
#include <iostream>

int devAbs( int x) {
    if (x<0) return -x;
    return x;
}

int devModo(int x[][100], int m, int n) {
    int mayor=0;
    for (int i=0;i<m;i++) {
        int suma=0;
        for (int j=0;j<n;j++) {
            suma+=x[i][j];
        }
        if (devAbs(suma)>mayor) mayor=devAbs(suma);
    }
    return mayor;
}

using namespace std;
int main() {
    int n;
    do {
        cout<<"Ingrese n: ";
        cin>>n;
        if (n<=0) cout<<"Error. Valor no valido."<<endl;
    }while(n<=0);
    int m;
    do {
        cout<<"Ingrese m: ";
        cin>>m;
        if (m<=0) cout<<"Error. Valor no valido."<<endl;
    }while (m<=0);
    int a[n][100];

    for (int i=0; i<n; i++ ) {
        for (int j=0;j<m;j++) {
            cout<<"Ingrese a["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout<<"El MODO es: "<<devModo(a, n, m)<<endl;
    return 0;
}