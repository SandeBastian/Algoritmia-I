/*
Creacion y recorrido de una lista de forma recursiva de estudiantes que tengan datos del
codigo y promedio final
Codigo      Promedio final
111         13.5
222         08.7
333         14.5
*/

#include <iostream>
using namespace std;

struct Nodo {
    int cod;
    float pf;
    Nodo *flecha;
};

Nodo *base;

void crea_nodo (Nodo *&p) {
    int cod;
    float pf;
    if (p==NULL) {
        cout<<"Ingrese el codigo: "; cin>>cod;
        cout<<"Ingrese el Prom. final: "; cin>>pf;
        p = new Nodo;
        p->cod = cod;
        p->pf = pf;
        p->flecha = NULL;
    }
    else {
        crea_nodo(p->flecha);
    }
}

void crea_lista(Nodo *&p) {
    int n;
    p=NULL;
    cout<<"Inngrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Datos #"<<i+1<<":"<<endl;
        crea_nodo(p);
    }
}

void recorre (Nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        recorre(p->flecha);
    }
}

int main () {
    crea_lista(base);
    recorre(base);
    return 0;
}