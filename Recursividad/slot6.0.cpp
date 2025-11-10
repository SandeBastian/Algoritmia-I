/*
Crear una función recursiva que permita recibir un número entero positivo
num y un digito d. Luego la función debe retorna el número modificado de
tal forma que no contenga al digito d.
Ejemplo:
La función recibe:
Numero: 4757
Digito: 7
La función retorna: 45
*/
#include <iostream>
using namespace std;

int numMod(int num, int d) {
    int r=0, newNum=0;
    int prod=1;
    if (num>0) {
        if (num%10!=d) {
            return num%10 + numMod(num/10, d)*10;
        }else {
            return numMod(num/10, d);
        }
    }
    return 0;
}

int main () {
    int a,b;
    cout<<"a: "; cin>>a;
    cout<<"b: "; cin>>b;
    cout<<"Numero Modificado: "<<numMod(a,b)<<endl;
    return 0;
}