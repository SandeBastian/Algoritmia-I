/*
CREAR REGISTRO1.DAT
                REGISTRO.DAT
Codigo  Nombre              Prom. final   Ind
222     ALVA TORRES INES    14.7          0
111     CAMPOS RUIZ JUAN    13.5          1
333     BARRIOS ALVA LUIS   08.7          2
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
    reg r;

    int n;

    ofstream ente;
    ente.open("REGISTRO1.DAT", ios::binary);

    if (!ente) {
        cout<<"Error, no se pudo crear el Archivo"<<endl;
    }else {
        cout<<"Ingrese el numero de Personas: "; cin>>n;
        for (int i=0; i<n; i++) {
            cout<<"Ingrese el codigo: "; cin>>r.cod;
            cout<<"Ingrese el nombre: ";
            cin.ignore();
            cin.getline(r.nomb, 51);
            cout<<"Ingrese el Prom. Final: ";
            cin>>r.pf;

            ente.write((char*)&r, sizeof(r));
        }
        cout<<"Archivo creado con exito"<<endl;
        ente.close();
    }
    return 0;
}