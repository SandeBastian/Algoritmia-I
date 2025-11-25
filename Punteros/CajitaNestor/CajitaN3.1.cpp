/*
Nodos ENLAZANDO ESTRUCTURA
*/
#include <iostream>
using namespace std;

struct lego {
    int cod;
    float pt;
    lego *punt;
};

int main () {
    lego *p, *q;
    p=new(lego);
    q=new(lego);
    lego *r;
    r=new (lego);

    //Creas p
    p->cod=111;
    p->pt=7.1;
    p->punt=NULL;

    //Creas q
    q->cod=222;
    q->pt=7.2;
    q->punt=NULL;

    //CREAS r
    r->cod=333;
    r->pt=7.3;
    r->punt=NULL;

    p->punt=q; //enlaza p y q
    q->punt=r; //enlaza q y r

    //Estructura 1
    cout<<p->cod<<"\t"<<p->pt<<endl;
    //Estructura enlazada 2
    p=p->punt;
    cout<<p->cod<<"\t"<<p->pt<<endl;
    //Estructura enlazada 3
    p=p->punt;
    cout<<p->cod<<"\t"<<p->pt<<endl;
    return 0;
}