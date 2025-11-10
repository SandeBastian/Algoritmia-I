/*
Evaluar y Comparar en 2 funciones 4 numeros para ordenarlos de forma decreciente
*/
#include <iostream>
using namespace std;
void evaluar(int &x, int &y);
void intercambia(int &x, int &y);
//el orden importa al parecer, primero debes hacer el "Intercambia" y luego el "evaluar" porque al revez
//la funcion evaluar busca la funcion "intercambia" y no la enucentra porque aun no ha sido creada a menos
//se cree una firma creo. Y si con la firma el orden no importa pero esa observacion es importante
void evaluar (int &x, int &y) {
    if (x>y) intercambia(x, y);
}
void intercambia(int &x, int&y) {
    int aux=x;
    x=y;
    y=aux;
}
int main () {
    int a, b, c, d;
    cout<<"a: "; cin>>a;
    cout<<"b: "; cin>>b;
    cout<<"c: "; cin>>c;
    cout<<"d: "; cin>>d;
    evaluar(a,b);
    evaluar(c,d);
    evaluar(a,c);
    evaluar(b,d);
    evaluar(b,c);
    cout<<"Variables ordenadas: "<<endl;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}