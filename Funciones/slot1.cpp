/*
La siguiente funcion recibe 2 valores enteros y entrega el mayor de ellos
*/

//prototipo/firma de funcion para que el compilador busque la funcion y no bote error incluso cuando la funcion esta al final
int mayor(int x, int y);
int elMayor(int x, int y);

#include <iostream>
using namespace std;
int main () {
    int n;
    int m;
    do {
        cout<<"Ingrese el valor de n:";
        cin>>n;
        if (n<0) cout<<"Error. Valor invalido."<<endl;
    }while (n<0);

    do {
        cout<<"Ingrese el valor de m:";
        cin>>m;
        if (m<0) cout<<"Error. Valor invalido."<<endl;
    }while (m<0);

    cout<<"El mayor es: "<<mayor(n, m)<<endl;
    cout<<"El mayor es: "<<elMayor(n, m)<<endl;
    return 0;
}
int mayor(int x, int y) {
    int mayor;
    if (x > y) return x;
    else return y;
}
int elMayor(int x, int y) {
    return x > y ? x : y;
}