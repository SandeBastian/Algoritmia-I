#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef char cadena[51];

struct nodo {
    cadena nombre;
    nodo *punt;
};


void recorre(nodo *p) {
    while (p != NULL) {
        cout<<p->nombre<<endl;
        p=p->punt;
    }
}

void insertar(nodo *&p, cadena nom) {
    nodo *piv=new nodo;
    strcpy(piv->nombre, nom);
    piv->punt=NULL;

    if (p==NULL)
        p=piv;
    else {
        nodo *q = p;
        while (q->punt != NULL)
            q=q->punt;
        q->punt=piv;
    }
}


void ordenar(nodo *p) {
    if (p!=NULL) {
        bool cambio;
        nodo *pAux;
        cadena aux;

        do {
            cambio = false;
            pAux = p;
            while (pAux->punt != NULL) {
                if (strcmp(pAux->nombre, pAux->punt->nombre) > 0) {
                    strcpy(aux, pAux->nombre);
                    strcpy(pAux->nombre, pAux->punt->nombre);
                    strcpy(pAux->punt->nombre, aux);
                    cambio = true;
                }
                pAux=pAux->punt;
            }
        } while (cambio);
    }
}


int main() {
    ifstream f("PLAYAS.TXT");
    if (!f) {
        cout<<"Error al abrir PLAYAS.TXT"<< endl;
        return 0;
    }

    nodo *lista=NULL;
    cadena playa;

    while (f>>playa) {
        insertar(lista, playa);
    }
    f.close();

    ordenar(lista);

    cout << "Playas ordenadas:" << endl;
    recorre(lista);

    return 0;
}
