#include <iostream>
using namespace std;

struct nodo {
    int cod;
    nodo *punt;
};

nodo *piv=NULL;

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<endl;
        recorre(p->punt);
    }
}

void buscarCod (nodo *&p,nodo *&act,nodo *&ant, int cod, bool &yaExiste) {
    while (act!=NULL) {
        if (cod>act->cod) {
            ant=act;
            act=act->punt;
        }
        else {
            if (cod==act->cod) yaExiste=true;
            break;
        }
    }
}

void creaNodo (nodo *&p, int cod) {
    p=new nodo;
    p->cod=cod;
    p->punt=NULL;
}

void evaluaCod (nodo *&p) {
    int cod;
    nodo *act=p;
    nodo *ant=NULL;
    nodo *ins=NULL;

    cout<<"Ingrese el codigo: "; cin>>cod;

    bool yaExiste=false;

    buscarCod( *&p, *&act, *&ant, cod, yaExiste);

    if (!yaExiste) {
        creaNodo (ins, cod);
        if (act==p) {
            p=ins;
            ins->punt=act;
        }
        else {
            ant->punt=ins;
            ins->punt=act;
        }
    }else {
        cout<<"El codigo ya existe"<<endl;
    }
}

void creaLista (nodo *&p) {
    int n;
    cout<<"Ingrese la cantidad de Datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Ingrese Datos ["<<i+1<<"]: "<<endl;
        evaluaCod(p);
    }
}

int main () {
    creaLista(piv);
    recorre(piv);
    return 0;
}