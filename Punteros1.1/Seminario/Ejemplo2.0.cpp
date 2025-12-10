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

struct nodo {
    int cod;
    float pf;
    nodo *punt;
};

nodo *piv=NULL;

void ordenaNodo (nodo *&p, nodo *&act, nodo *&ant,  int cod, float pf) {
    while (act!=NULL) {
        if (cod<act->pf) {
            ant=act;
            act=act->punt;
        }
        else {
            break;
        }
    }
}

void creaNodo (nodo *&ins, int cod, float pf) {
    ins = new nodo;
    ins->cod=cod;
    ins->pf=pf;
    ins->punt=NULL;
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        recorre(p->punt);
    }
}

void evaluaNodo(nodo *&p, int cod, float pf) {
    nodo *act=p;
    nodo *ant=NULL;
    nodo *ins=NULL;
    ordenaNodo(p, act, ant,  cod, pf);
    creaNodo(ins, cod, pf);
    if (act==p) {
        p=ins;
        ins->punt=act;
    }
    else {
        ant->punt=ins;
        ins->punt=act;
    }
}

void creaLista (nodo *&p) {
    int cod;
    float pf;
    ifstream Reg;
    Reg.open("PROMEDIOS1.TXT");
    if (!Reg) {
        cout<<"Error al encontrar el archivo"<<endl;
    }else {
        while (Reg>>cod>>pf) {
            evaluaNodo(p, cod, pf);
        }
        Reg.close();
    }
}

int main () {
    creaLista(piv);
    recorre(piv);
    return 0;
}