/*
LEE REGISTRO.DAT
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

    ifstream ente;
    ente.open("REGISTRO1.DAT", ios::binary);

    if (!ente) {
        cout<<"Error, no se pudo encontrar el Archivo"<<endl;
    }else {
        while (ente.read((char*)&r,sizeof(reg))) {
            cout<<r.cod<<"\t"<<r.nomb<<"\t"<<r.pf<<endl;
        }
        ente.close();
    }
    return 0;
}