#include <iostream>
using namespace std;

struct lego {
    int cod;
    lego *punt;
};

int x[]={10,20,30,40,50};

lego *tank;

void crea_nodo ( lego *&p, int codPs) {
    p=new lego;
    p->cod=codPs;
    p->punt=NULL;
}

void crea_lista(lego *&p) {
    lego *q, *r;
    p=NULL;
    for (int i=0; i<5; i++) {
        if (p==NULL) {
            crea_nodo(p,x[i]);
            r=p;
        }else {
            crea_nodo(q,x[i]);
            r->punt=q;
            r=q;
        }
    }
}

void recorrer(lego *&p) {
    cout<<"Codigos: "<<endl;
    while (p!=NULL) {
        cout<<p->cod<<endl;
        p=p->punt;
    }
}

int main () {
    crea_lista(tank);
    recorrer(tank);
    return 0;
}