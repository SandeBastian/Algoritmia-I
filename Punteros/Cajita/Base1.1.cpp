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

void crea_lista (lego *&punt) {
    lego *puntx;
    punt = NULL;
    int n;
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

void recorre(lego *&punt) {
    cout<<"Codigo\tPunt Final"<<endl;
    while (punt != NULL) {
        cout<<punt->cod<<"\t"<<punt->pf<<endl;
        punt=punt->apunt;
    }
}

//Este codigo busca que solo entre Reg punt dentro de cada funcion

int main () {
    lego *punt;

    crea_lista(punt);

    recorre(punt);

    return 0;
}