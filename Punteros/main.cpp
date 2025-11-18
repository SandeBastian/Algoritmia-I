#include <iostream>
using namespace std;
int main () {
    int *p1;
    int *p2;

    p1=new(int);
    p2=new(int);

    *p1=10;
    *p2=20;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    //Caso 1: p1 apunta a p2
    p1=p2;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    *p1=30;
    cout<<"*p1=30 (Se alteran ambos): "<<endl;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;

    *p2=40;
    cout<<"*p2=40 (Se alteran ambos): "<<endl;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;


    *p1=*p2;
    cout<<"*p1: "<<*p1<<endl;
    cout<<"*p2: "<<*p2<<endl;


    *p1=6;
    *p2=7;
    cout<<"\n*p: "<<*p1<<endl;
    cout<<"*q: "<<*p2<<endl;

    return 0;
}