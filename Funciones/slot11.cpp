/*
Crear una Funcion que determine si una matriz es simetrica
Una matriz cuadrada es simétrica si para td i,j, x[i][j] = x[j][i].
*/
#include <iostream>
using namespace std;
// la segunda dimension se le pone para que la funcion sepa hasta donde lee el primer bloque 100 es preventivo
bool esSimetrica (int x[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) { //Aqui solo recorre la parte (triangulo) inferior de la matriz
            if (x[i][j]!=x[j][i]) return false;
        }
    }
    return true;
}
int main () {
    int n;
    do {
        cout<<"Ingrese el orden de M (matriz cuadrada): "; //Tendra que ser <= 100 sino se rayara creo
        cin>>n;
        if (n<0) cout<<"Error. Valor no valido."<<endl;
    }while (n<0);

    int mat[100][100]; //Aqui debe coincidir con el tamaño del arreglo en el parametro de la funcion sino se lokea
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<"mat ["<<i<<"]["<<j<<"]: ";
            cin>>mat[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    if (esSimetrica(mat, n)) cout<<"\nLa matriz M "<<n<<"x"<<n<<" es simetrica."<<endl;
    else cout<<"\nLa matriz M "<<n<<"x"<<n<<" No es simetrica."<<endl;
    return 0;
}