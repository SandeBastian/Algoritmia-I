/*
PILAS PILAS PILAS PILAS PILAS:
Crea una pila usando la siguiente lista de codigos empieza almacenando
desde el primer elemento x[5]={10,20,30,40,50}
-SIN FUNCIONES
-SOLO BUCLES
*/

#include <iostream>
using namespace std;

int x[5]={10,20,30,40,50}; //Esta aqui afuera del main porque void crea_lista accede a esto

struct lego {
    int cod;
    lego *punt;
};

void crea_nodo(lego *&p, int cod) {
    p=new(lego);
    p->cod = cod;
    p->punt = NULL;
}

lego *lista;

void crea_lista(lego *&p) {

    lego *q; //Crea estructura 'q' de tipo puntero
    p=NULL; //Hace que el punto 'p' este vacio (no apunta nada)
    for (int i=0; i<5; i++) {
        if (p==NULL) {
            //Empieza Nodo 1
            crea_nodo(p, x[i]);
        }
        else {
            //Continua Nodos y enlaza
            crea_nodo(q, x[i]);
            //Enlaza p y q (tecnicamente pone p en q)
            q->punt = p;
            p=q;
            //Luego se pierde q pero p queda en el nodo q que a su vez es generado por
            //el anterior p->punt
        }
        cout<<"q: "<<q->cod<<endl;
    }
}

void recorre(lego *p) {
    int n=5;
    while (p!=NULL) {
        cout<<"Dato ("<<n--<<"): "<<p->cod<<endl;
        p=p->punt;
    }
}

int main () {

    crea_lista(lista);

    recorre(lista);
    return 0;
}