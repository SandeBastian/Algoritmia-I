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

int main () {
    struct nodo {
        int cod;
        float pf;
        nodo *punt;
    };

    nodo *p, *q, *r;
    p=NULL;
    int n;
    cout<<"Ingrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        int codi;
        float pfi;
        cout<<"Datos ["<<i+1<<"]: "<<endl;
        cout<<"Ingrese el codigo: "; cin>>codi;
        cout<<"Ingrese el pfi: "; cin>>pfi;
        if (p==NULL) {
            p=new(nodo);
            p->cod=codi;
            p->pf=pfi;
            p->punt=NULL;
            r=p;
        }
        else {
            q=new(nodo);
            q->cod=codi;
            q->pf=pfi;
            q->punt=NULL;
            r->punt=q;
            r=q;
        }
    }
    cout<<"Codigos\tP. Final"<<endl;
    while (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        p=p->punt;
    }
    return 0;
}