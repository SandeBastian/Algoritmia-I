/*
Creacion y recorrido de una PILA (LIFO) de estudiantes que tengan datos
del Codigo y Promedio final
Codigo      Promedio Final
111         13.5
222         08.7
333         14.5
*/
#include <iostream>
using namespace std;

struct lego {
    int cod;
    float pf;
    lego *apunt;
};

void crea_nodo( lego *&punt) {
    int cd;
    float pt;
    cout<<"Ingresa un codigo: "; cin>>cd;
    cout<<"Ingresa puntaje final: "; cin>>pt;
    punt=new(lego);
    punt->cod = cd;
    punt->pf = pt;
    punt->apunt=NULL;
}

void crea_lista (lego *&punt, int &n) {
    lego *puntx;
    punt = NULL;
    cout<<"Ingrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Datos ["<<i+1<<"]: "<<endl;
        if (punt == NULL) {
            crea_nodo(punt);
        }else {
            crea_nodo(puntx);
            puntx->apunt=punt;
            punt=puntx;
        }
    }
}

void recorre(lego *&punt, int n) {
    cout<<"Datos: "<<endl;
    while (punt != NULL) {
        cout<<"Datos ("<<n--<<"):"<<"\t"<<punt->cod<<"\t"<<punt->pf<<endl;
        punt=punt->apunt;
    }
}

int main () {
    lego *punt;
    int n;
    crea_lista(punt, n);

    recorre(punt, n);
    return 0;
}