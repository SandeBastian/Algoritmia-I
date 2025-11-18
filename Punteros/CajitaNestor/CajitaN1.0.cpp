#include <iostream>
using namespace std;

struct Reg {
    int cod;
    float pt;
};

int main () {

    int *p; //Variable puntero para enteros
    float *q; //Variable puntero para reales
    Reg *r1; //Variable puntero para estructuras
    p=new(int);
    q=new(float);
    r1=new(Reg);

    cout<<"\nDirecciones de memmoria: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    p++; q++; r1++;
    cout<<"\nDirecciones de memoria ++: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    //Dando valores a los datos simples
    *p=5;
    *q=10.2;
    cout<<"\nValores de los datos simples: "<<endl;
    cout<<"*p: "<<*p<<endl;
    cout<<"*q: "<<*q<<endl;

    //Dando valores a datos compuestos (de manera NO PRACTICA)
    (*r1).cod=111;
    (*r1).pt=7.1;
    cout<<"\nImpresion de datos compuestos I: "<<endl;
    cout<<"(*r1).cod: "<<(*r1).cod<<endl;
    cout<<"(*r1).pt: "<<(*r1).pt<<endl;

    //Dando valores para datos compuestos (de manera PRACTICA)
    r1->cod=222;
    r1->pt=7.2;
    cout<<"\nImpresion de datos compuestos II: "<<endl;
    cout<<"r1->cod: "<<r1->cod<<endl;
    cout<<"r1->pt: "<<r1->pt<<endl;

    //Declara otro puntero tipo structura?????
    Reg *r2=new(Reg);
    r2->cod=333;
    r2->pt=7.3;
    cout<<"\nDe ahora en adelante asi: "<<endl;
    cout<<"r2->cod: "<<r2->cod<<endl;
    cout<<"r2->pt: "<<r2->pt<<endl;
    return 0;


}