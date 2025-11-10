/*
A partir de laa funcion mayor (que calcula el mayor valor de 2 numeros reales),
¿se podrá calcular el mayor valor de 5 numeros reales?
*/
#include <iostream>
using namespace std;

int obtenerMayor(int a, int b) {
    return a>b? a:b;
}
int obtenerMayor(int a, int b, int c, int d, int e) {
    return obtenerMayor(obtenerMayor(obtenerMayor(a,b), obtenerMayor(c, d)),e);
}

int main() {
    int a, b, c, d, e;
    cout<<"a:"; cin>>a;
    cout<<"b:"; cin>>b;
    cout<<"c:"; cin>>c;
    cout<<"d:"; cin>>d;
    cout<<"e:"; cin>>e;
    cout<<"El mayor valor de a, b, c, d y e: "<<obtenerMayor(a,b,c,d,e);
    return 0;
}