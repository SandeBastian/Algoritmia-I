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
    lego *mira;
};

lego *base;

void crea_nodo(lego *&x) {
    int codigo;
    float promf;
    cout<<"Ingrese el codigo: "; cin>>codigo;
    cout<<"Ingrese el promedio final: "; cin>>promf;
    x=new lego;
    x->cod=codigo;
    x->pf=promf;
    x->mira=NULL;
}

void crea_lista(lego *&x) {
    int n;
    lego *aux;
    x=NULL;
    cout<<"Ingrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Datos ["<<i+1<<"]: "<<endl;
        if (x==NULL) {
            crea_nodo(x);
        }else {
            crea_nodo(aux);
            aux->mira=x;
            x=aux;
        }

    }
}

void recorre (lego *&x) {
    cout<<"Codigo\tP. Final"<<endl;
    while(x!=NULL) {
        cout<<x->cod<<"\t"<<x->pf<<endl;
        x=x->mira;
    }
}

int main () {
    crea_lista(base);
    recorre(base);
    return 0;
}