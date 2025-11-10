/*
Programa que presenta 4 numeros reales ordenados en forma decreciente
*/
#include <iostream>
using namespace std;

void intercambio(int &x, int &y) {
    int aux=x;
    x=y;
    y=aux;
}

int main () {
    int a, b ,c ,d;
    cout<<"Ingrese a: "; cin>>a;
    cout<<"Ingrese b: "; cin>>b;
    cout<<"Ingrese c: "; cin>>c;
    cout<<"Ingrese d: "; cin>>d;

    if (a<b) intercambio(a,b);
    if (c<d) intercambio(c,d);
    if (a<c) intercambio(a,c);
    if (b<d) intercambio(b,d);
    if (b<c) intercambio(b,c);
    cout<<"Variables ordenadas: "<<endl;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}