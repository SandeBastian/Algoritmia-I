/*
Crea el archivo PEDIDOS.DAT

Codigo      Num. unidades
222         150
111         80
444         100
222         50
333         200
444         200
*/
#include <iostream>
#include <fstream>
using namespace std;

struct reg {
    int cod;
    int nota;
};

int main () {
    reg r;
    ofstream f;
    f.open ("PEDIDOS.DAT", ios::binary);
    if (!f) {
        cout<<"Error al crear PEDIDOS.DAT"<<endl;
    }
    else {
        int n;
        cout<<"Ingrese la cantidad de datos: ";
        cin>>n;
        for (int i=0; i<n; i++) {
            cout<<"Ingrese cod["<<i+1<<"]: "; cin>>r.cod;
            cout<<"Ingrese num["<<i+1<<"]: "; cin>>r.nota;
            f.write((char*)&r, sizeof(reg));
        }
        f.close();
    }
    cout<<"Proceso terminado"<<endl;
    return 0;
}