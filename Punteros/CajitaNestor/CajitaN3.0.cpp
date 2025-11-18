/*
Nodos ENLAZANDO ESTRUCTURA
*/
#include <iostream>
using namespace std;

struct Reg {
    int cod;
    float pt;
    Reg *punt;
};

int main () {
    Reg *p, *q;
    p=new(Reg);
    q=new(Reg);

    //Creas p
    p->cod=111;
    p->pt=7.1;
    p->punt=NULL;

    //Creas q
    q->cod=222;
    q->pt=7.2;
    q->punt=NULL;

    p->punt=q; //enlaza p y q

    cout<<p->cod<<"\t"<<p->pt<<endl;

    p=p->punt;
    cout<<p->cod<<"\t"<<p->pt<<endl;
    return 0;
}