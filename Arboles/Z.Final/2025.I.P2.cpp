/*
Presente un programa en C++, que, genere aleatoriamente una matriz cuadrada de orden n>=5 (n
debe ser impar) de números enteros de 2 cifras. Dentro de la matriz se forma un rombo con los
elementos de las diagonales que unen los puntos medios de la primera fila y la primera columna, la
primera fila y la última columna, la última fila y la primea columna, la última fila y la última columna.
Este rombo divide la matriz en dos zonas: la interna y la externa al rombo.
a) Hallar y mostrar la suma de los elementos de la zona externa que tengan raíz cuadrada exacta,
si no existen elementos con esta cualidad mostrar 0.
b) Hallar y mostrar la suma de los cuadrados de los elementos impares de la interna.
Ejemplo: Si n=7.
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main () {
    //srand (time(NULL));
    int n;
    do {
        cout<<"Ingrese el orden de la matriz (n>=5 y n impar): ";
        cin>>n;
        if (n<5||n%2==0) cout<<"Orden invalido"<<endl;
    }while (n<5||n%2==0);

    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 10 + rand()%90;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}