/*
Tarea 36: Función recursiva para
multiplicar dos números naturales
*/
#include <iostream>
using namespace std;

long multiplicacion (int x, int y) {
    long m=0;
    if (y>0) m=x+multiplicacion(x, y-1);
    return m;
}
int main() {
    int a, b;
    cout<<"Ingrese el #1: ";
    cin>>a;
    cout<<"Ingrese el #2: ";
    cin>>b;
    cout<<"La multiplicacion es: "<<multiplicacion(a,b);
    return 0;
}