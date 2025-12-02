/*
Se tiene ya existe el archivo de texto llamado PROMEDIOS.TXT, el cual contiene
los siguientes datos:
PROMEDIOS.TXT
Codigo Promedio final
111 10.5
333 15.0
555 10.5
777 12.0
999 14.5
Se pide almacenar los datos de este archivo en una lista dinámica ordenados en
forma decreciente respecto al promedio. Luego presentar la lista.
Tenga en cuenta que los promedios pueden ser repetidos
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
    int cod;
    float pf;
    nodo *punt;
};

nodo *piv;

void creaNodo (nodo *&p, int cod);

void creaLista (nodo *&p);

void evaluaNodo (nodo *&p, int cod, float pf);

void buscar (nodo *&p, nodo *&ant, nodo *&act, float pf);

void recorre (nodo *&p);


int main () {
    creaLista(piv);
    recorre(piv);
    return 0;
}

void creaNodo (nodo *&p, int cod, float pf) {
    p=new nodo;
    p->cod=cod;
    p->pf=pf;
    p->punt=NULL;
}

void creaLista(nodo *&p) {
    int cod;
    float pf;

    int n;
    p=NULL;
    ifstream ent;
    ent.open ( "PROMEDIOS1.txt");
    if (!ent) {
        cout<<"Error al abrir el archivo."<<endl;
    } else {
        while (ent>>cod>>pf) {
            evaluaNodo(p, cod, pf);
        }
        ent.close();
    }
}

void buscar (nodo *&p, nodo *&ant, nodo *&act, float pf) {
    while (act!=NULL) {
        if (pf<act->pf) {
            ant=act;
            act=act->punt;
        }
        else {
            break;
        }
    }
}

void evaluaNodo(nodo *&p, int cod, float pf) {

    nodo *ant, *act, *ins;
    ant=NULL;
    act=p;
    ins=NULL;

    buscar (p, ant, act, pf);
    creaNodo(ins, cod, pf);
    if (p==act) { //si se inserta al inicio participa pivote y no entra el ant
        p=ins;
        ins->punt=act;
    }
    else {   //si esta en medio participa ant act y ya no participa el pivote
        ant->punt=ins;
        ins->punt=act;
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        recorre(p->punt);
    }
}

