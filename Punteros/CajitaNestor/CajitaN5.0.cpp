#include <iostream>
using namespace std;

struct lego {
    int cod;
    lego *punt;
};

int main () {
    lego *lista;
    int x[5]={10,20,30,40,50};
    lego *q, *r;
    lista=NULL; //Hace que el punto 'p' este vacio (no apunta nada)

    for (int i=0; i<5; i++) {
        if (lista==NULL) {
            //Empieza Nodo 1

            lista=new(lego);
            lista->cod = x[i];
            lista->punt = NULL;
            r=lista;
        }
        else {
            //Continua Nodos y enlaza
            q=new(lego);
            q->cod = x[i];
            q->punt = NULL;
            r->punt = q;
            r=q;
        }
        cout<<"q: "<<q->cod<<endl;
    }
    int n=5;
    while (lista!=NULL) {
        cout<<"Dato ("<<n--<<"): "<<lista->cod<<endl;
        lista=lista->punt;
    }
    return 0;
}