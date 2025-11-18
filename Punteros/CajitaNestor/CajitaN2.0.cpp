/*
Enlazando Variables puntero por memoria
*/
#include <iostream>
using namespace std;
int main () {
    int *p1;
    int *p2;

    p1=new(int);
    p2=new(int);

    *p1=10;
    *p2=20;
    cout<<"\n*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    //Caso 1: p1 apunta a p2
    p1=p2;
    cout<<"\n*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    //Ahora sus valores dependen uno del otro
    *p1=30;
    cout<<"\n*p1=30 (Se alteran ambos): "<<endl;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    *p2=40;
    cout<<"\n*p2=40 (Se alteran ambos): "<<endl;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    return 0;
}