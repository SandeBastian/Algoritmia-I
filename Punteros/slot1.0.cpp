/*
Crea un codigo que reciba numero de 3 cifras (<=999) y los ordene de menor a mayor
conforme se vayan ingresando los numeros. Presentar. Luego solitar 1 nuevo numero
de 3 cifras (<=999) y presentar la nueva lista luego de la insercion
*/
#include <iostream>
using namespace std;

struct nodo {
    int Cod;
    nodo *punt;
};

nodo *piv;

void creaNodo (nodo *&p, int cod) {
    p = new nodo;
    p->Cod=cod;
    p->punt=NULL;
}

void buscarCod (nodo *&p, nodo *&act, nodo *&ant, int cod, bool &yaExiste) {
    while (act!=NULL) {
        if (cod>act->Cod) {
            ant=act;
            act=act->punt;
        }else {
            if (cod==act->Cod) yaExiste=true;
            break;
        }
    }
}

void evaluaCod(nodo *&p) {
    int cod;
    nodo *act=p;
    nodo *ant=NULL;
    nodo *ins=NULL;

    cout<<"Ingrese Cod: "; cin>>cod;

    bool yaExiste=false;

    buscarCod (p, act, ant, cod, yaExiste);
    if (!yaExiste) {
        creaNodo(ins, cod);
        if (act==p) {
            p=ins;
            ins->punt=act;
        }
        else {
            ant->punt=ins;
            ins->punt=act;
        }
    }else {
        cout<<"El codigo ya esta en la lista"<<endl;
    }
}

void creaLista (nodo *&p) {
    int n;
    p=NULL;
    cout<<"Ingresa la cantidad de numeros: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Alumnos ["<<i+1<<"]: "<<endl;
        evaluaCod(p);
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->Cod<<endl;
        recorre(p->punt);
    }
}

int main () {
    creaLista(piv);
    recorre(piv);
}