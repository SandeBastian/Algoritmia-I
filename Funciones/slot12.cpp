/*
Funcion para determinar el mcd y mcm de dos numeros
*/
#include <iostream>
using namespace std;

int obtenerMCD(int x, int y) {
    int r;
    do {
        r = x%y;
        x=y;
        y=r;
    }while (r!=0);
    return x;
}

int main () {
    int a, b;
    cout<<"Ingrese a:";
    cin>>a;
    cout<<"Ingrese b:";
    cin>>b;
    int mcd=obtenerMCD(a,b);
    int mcm=(a*b)/mcd;
    cout<<"El MCD es: "<<mcd<<endl;
    cout<<"El MCM es: "<<mcm<<endl;
    return 0;
}