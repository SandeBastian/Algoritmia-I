/*
Asignando valor puntero a puntero sin apuntar a memorias
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

    //Caso 2: Se le asigna el valor de p2 a p1
    *p1=*p2;
    cout<<"\n*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;


    //como solo alteraron su valor, su valores en adelante no dependen uno del otro
    *p1=6;
    *p2=7;
    cout<<"\nSe alteran de manera independiente: "<<endl;
    cout<<"*p: "<<*p1<<endl;
    cout<<"*q: "<<*p2<<endl;

    return 0;
}