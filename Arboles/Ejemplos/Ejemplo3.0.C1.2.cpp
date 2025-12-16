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
    int num;
};

int main () {
    reg r;
    ifstream f;
    f.open ("PEDIDOS.DAT", ios::binary);
    if (!f) {
        cout<<"Error al leer PEDIDOS.DAT"<<endl;
    }
    else {
        while (f.read((char*)&r,sizeof(reg))) {
            cout<<r.cod<<"\t"<<r.num<<endl;
        }
        f.close();
    }
    cout<<"Proceso terminado"<<endl;
    return 0;
}