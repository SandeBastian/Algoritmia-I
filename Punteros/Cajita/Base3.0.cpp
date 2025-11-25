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
    cout<<"Ingrese el codigo: "; cin>>cod;
    cout<<"Ingrese el Prom. final: "; cin>>pf;
    p = new Nodo;
    p->cod = cod;
    p->pf = pf;
    p->flecha = NULL;
}

void crea_lista(Nodo *&p) {
    int n;
    Nodo *q, *r;
    p=NULL;
    cout<<"Inngrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Datos #"<<i+1<<":"<<endl;
        if (p==NULL) {
            crea_nodo(p);
            r=p;
        }
        else {
            crea_nodo(q);
            r->flecha = q;
            r=q;
        }
    }

}

void recorre (Nodo *&p) {
    cout<<"Codigo\tP. Final"<<endl;
    while(p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        p=p->flecha;
    }
}

int main () {
    crea_lista(base);
    recorre(base);
    return 0;
}