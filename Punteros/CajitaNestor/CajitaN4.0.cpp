#include <iostream>
using namespace std;

int main () {

    struct lego {
        int cod;
        lego *punt;
    };

    lego *lista;
    int x[5]={10,20,30,40,50};
    lego *q; //Crea estructura 'q' de tipo puntero
    lista=NULL; //Hace que el punto 'p' este vacio (no apunta nada)
    for (int i=0; i<5; i++) {
        if (lista==NULL) {
            //Empieza Nodo 1

            lista=new(lego);
            lista->cod = x[i];
            lista->punt = NULL;
        }
        else {
            //Continua Nodos y enlaza
            q=new(lego);
            q->cod = x[i];
            q->punt = NULL;
            //Enlaza p y q (tecnicamente pone p en q)
            q->punt = lista;
            lista=q;
            //Luego se pierde q pero p queda en el nodo q que a su vez es generado por
            //el anterior p->punt
        }
        cout<<"q: "<<q->cod<<endl;
    }
    int n=5;
    while (q!=NULL) {
        cout<<"Dato ("<<n--<<"): "<<q->cod<<endl;
        q=q->punt;
    }
    return 0;
}
