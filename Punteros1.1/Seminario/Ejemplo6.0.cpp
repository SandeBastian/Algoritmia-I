/*
Ordenar el archivo "REGISTRO.DAT" en forma creciente respecto al
promedio final. Hacerlo sin modificar el orden en el archivo
“REGISTRO.DAT”.

antes de ordenar en forma creciente
REGISTRO.DAT                            INDICE.DAT

Codigo  Nombre              Prom final
222     ALVA TORRES INES    14.7          0
111     CAMPOS RUIZ JUAN    13.5          1
333     BARRIOS ALVA LUIS   08.7          2

despues de ordenar en forma creciente
REGISTRO.DAT INDICE.DAT
Codigo  Nombre              Prom final
333     BARRIOS ALVA LUIS   08.7        2
111     CAMPOS RUIZ JUAN    13.5        1
222     ALVA TORRES INES    14.7        0
*/
#include <iostream>
#include <fstream>
using namespace std;

typedef char cadena[51];

struct reg {
    int cod;
    cadena nomb;
    float pf;
};

int main () {
    ifstream ente;

    ente.open("REGISTROS:DAT", ios::binary);
    if (!ente) {
        cout<<"Error al encontrar el archivo"<<endl;
    }
    else {

        ente.close();
    }
    return 0;
}