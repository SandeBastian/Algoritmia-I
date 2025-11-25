#include <iostream>
using namespace std;

struct lego {
    int cod;
    lego *punt;
};

int x[5]={10,20,30,40,50};

lego *lista;

void crea_nodo (lego *&p, int codPs) {
    p = new (lego);
    p->cod=codPs;
    p->punt=NULL;
}

void crea_lista (lego *&p) {
    int n=5;
    p=NULL;
    lego *q, *r;
    for (int i=0;i<n;i++) {
        if (p==NULL) {
            crea_nodo(p, x[i]);
            r=p;
        }
        else {
            crea_nodo(q, x[i]);
            r->punt=q;
            r=q;
        }
    }
}

void recorre (lego *&p) {
    cout<<"Codigos: "<<endl;
    while(p!=NULL) {
        cout<<p->cod<<endl;
        p=p->punt;
    }
}

int main () {
    crea_lista(lista);
    recorre(lista);
    return 0;
}