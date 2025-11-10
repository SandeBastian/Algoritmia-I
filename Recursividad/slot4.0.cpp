/*
Multiplica dos numero con una funcion recursiva
*/
#include <iostream>
using namespace std;

int multiplica (int a, int b) {
    int mult=0;
    if (b>0) mult= a+multiplica(a, b-1);
    return mult;
}

int main () {
    int a, b;
    cout<<"Ingrese a: ";
    cin>>a;
    cout<<"Ingrese b: ";
    cin>>b;
    cout<<"Divisores de "<<multiplica(a,b);
    return 0;
}