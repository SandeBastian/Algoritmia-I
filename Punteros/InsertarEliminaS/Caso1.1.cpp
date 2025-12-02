/*
Ejemplo:
Creacion de lista, Busqueda, insercion ordenada,y eliminacion de 1 dato
*/
//CREAR LISTA ORDENADA
#include <iostream>
using namespace std;

int m[]={999, 444, 777, 111, 555, 888, 333, 222, 666};

struct nodo {
    int Cod;
    nodo *punt;
};

nodo *piv=NULL;


void buscar(nodo *p, nodo *&ant, nodo *&act, int cod, bool &yaEsta){
    bool termina=false; //Indica que todavia no ha terminado la busqueda
    ant=NULL;
    act=p;
    while(act!=NULL && !termina){ //aqui se mueve el ant y act para ubicar el nuevo nodo (ins)
        if(cod>act->Cod){
            ant=act;
            act=act->punt;
        }
        else{
            termina=true;
            if(cod==act->Cod){
                yaEsta=true;
            }
        }
    }
}

void insertarNodo (nodo *&p, int cod) {
    nodo *ant, *act;
    bool yaEsta = false;
    buscar (p, ant, act, cod, yaEsta);
    if (!yaEsta) {
        nodo *ins;
        ins=new nodo;
        ins->Cod=cod;
        ins->punt=NULL;

        if (p==act) {
            p=ins;
            ins->punt=act;
        }
        else {
            ant->punt=ins;
            ins->punt=act;
        }
    }else {
        cout<<"Eso codigo ya esta en la lista."<<endl;
    }
}

void crea_lista (nodo *&p) {
    int n=9;
    for (int i=0; i<n; i++) {
        insertarNodo(p, m[i]);
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->Cod<<endl;
        recorre(p->punt);
    }
}

int main () {
    crea_lista(piv);
    recorre(piv);
    return 0;
}