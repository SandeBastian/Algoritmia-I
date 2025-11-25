#include <iostream>
using namespace std;

struct lego {
    int cod;
    float pt;
};

int main () {
    int *p;
    float *q;
    lego *r1;
    p=new(int);
    q=new(float);
    r1=new(lego);

    cout<<"\nMemorias 1: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    p++; q++; r1++;
    cout<<"\nMemorias ++: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    *p=5;
    *q=10.2;
    (*r1).cod=111;
    (*r1).pt=7.1;
    cout<<"\nValores 1: "<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"*q: "<<*q<<endl;
    cout<<"(*r1).cod: "<<(*r1).cod<<endl; //No practica
    cout<<"(*r1).pt: "<<(*r1).pt<<endl;  //No practica

    r1->cod=111;
    r1->pt=7.1;
    cout<<"\nValores De Estructura 1: "<<endl;
    cout<<"r1->cod: "<<r1->cod<<endl; //Practica
    cout<<"r1->pt: "<<r1->pt<<endl;  //Practica

    //Tambien puedes declarar luego mas punteros del tipo struct
    lego *r2=new(lego);
    r2->cod=222;
    r2->pt=7.2;
    cout<<"\nValores De Estructura 2: "<<endl;
    cout<<"r2->cod: "<<r2->cod<<endl;
    cout<<"r2->pt: "<<r2->pt<<endl;

    return 0;
}