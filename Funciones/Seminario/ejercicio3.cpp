/*
Crear una funcion que reciba un vector de 8 elementos enteros (cada elemento menor que 512) y luego
devuelva dicho vector modificado de la siguiente manera como se muestra en el ejemplo.
*/
#include <iostream>
using namespace std;

void transformar(int v[], int n) {
    int m[n][n]={0};
    for (int i=0; i<n; i++) {
        for (int k=n-1; k>=0; k--) {
            m[i][k]=v[i]%2;
            v[i]=v[i]/2;
        }
    }
    cout<<"\nMatriz Original:"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << m[i][j] << " ";
        }
        cout<<endl;
    }
    int mT[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mT[j][i]=m[i][j];
        }
    }
    cout<<"\nMatriz Transpuesta: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << mT[i][j] << " ";
        }
        cout<<endl;
    }
    int vMod[n];
    for (int i=0; i<n; i++) {
        int pot=1;
        int suma=0;
        for (int j=n-1; j>=0; j--) {
            suma=suma+mT[i][j]*pot;
            pot=pot*2;
        }
        vMod[i]=suma;
    }
    cout<<"\nVmod:"<<endl;
    for (int i=0; i<n; i++) {
        cout<<vMod[i]<<" ";
    }
}

int main() {
    int v[]={166, 7, 12, 155, 189, 15, 132, 145};
    transformar (v, 8);
    return 0;
}