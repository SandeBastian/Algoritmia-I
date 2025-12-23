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

 56    79    10   "32"   21    45    33
 90    24   "30"   10   "16"   37    99
 40   "70"   14    94    24   "80"   44
"82"   24    32    92    28    23   "11"
 50   "81"   13    41    45   "48"   88
 89    31   "42"   21   "51"   97    45
 26    32    50   "12"   65    64    59

La suma de las raices elementos externos con raiz cuadrada exacta = 8.
La suma de los cuadrados de los elemtnos internos impares = 4845

*/
#include <iostream>
#include <ctime>
using namespace std;

bool esCuadrado (int n) {
    int raiz=0;
    while (raiz*raiz<n) raiz++;
    return raiz*raiz==n;
}

int raiz (int n) {
    int raiz=0;
    while (raiz*raiz<n) raiz++;
    return raiz;
}

bool esCuadradoRolly (int n) {
    int raiz=0;
    while (raiz*raiz<n) raiz++;
    return raiz*raiz==n;
}

int valAbs (int n){
    if (n<0) return -n;
    return n;
}

int main () {
    srand(time(NULL));

    int n;
    do {
        cout<<"Ingrese el orden de la matriz (n>=5 y n impar): ";
        cin>>n;
        if (n<5 || n%2==0) cout<<"Orden invalido"<<endl;
    } while (n<5 || n%2==0);

    int mat[n][n];

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            mat[i][j] = 10 + rand()%90;

    cout<<"\nMatriz:\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }

    int c = n/2;
    int sumaExt = 0;
    int sumaInt = 0;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
           int dif=valAbs(i-c)+valAbs(j-c);
            //Externa
            if (dif>c) {
                cout<<mat[i][j]<<endl;
                if (esCuadrado(mat[i][j])) {
                    sumaExt += raiz(mat[i][j]);
                }
            }
            //Interna
            if (dif<c) {
                if (mat[i][j]%2!=0) {
                    sumaInt += mat[i][j]*mat[i][j];
                }
            }
        }
    }

    cout<<"\nSuma de elementos externos con raiz cuadrada exacta = "<<sumaExt<<endl;
    cout<<"Suma de los cuadrados de los elementos internos impares = "<<sumaInt<<endl;

    return 0;
}
