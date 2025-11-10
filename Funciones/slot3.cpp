/*
Funcion que intercambia 2 valores
LLAMADA POR COPIA
LLAMADA POR REFERENCIA
*/
#include <iostream>
using namespace std;
void llamar_crear_Variable(int &x, int &y) {
    cout<<"Ingrese el Valor de n:";
    cin>>x;
    cout<<"Ingrese el Valor de m:";
    cin>>y;
}
void intercambio1(int x, int y) {
    int aux=x;
    x=y;
    y=aux;
}
void intercambio2(int &x, int &y) {
    int aux=x;
    x=y;
    y=aux;
}
int main () {
    int n, m;
    cout<<"Ingrese n:";
    cin>>n;
    cout<<"Ingrese m:";
    cin>>m;
    cout<<"Los Valores Son: "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"m: "<<m<<endl;

    llamar_crear_Variable(n, m);
    cout<<"Los Valores Ahora Son: "<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"m: "<<m<<endl;

    cout<<"Antes del intercambio:" <<endl;
    cout<<"n:"<<n<<endl;
    cout<<"m:"<<m<<endl;

    intercambio1(n,m);
    cout<<"Intercambio 1 sin llamdo de memoria:" <<endl;
    cout<<"n:"<<n<<endl;
    cout<<"m:"<<m<<endl;

    intercambio2(n,m);
    cout<<"Intercambio 2 con llamdo de memoria:" <<endl;
    cout<<"n:"<<n<<endl;
    cout<<"m:"<<m<<endl;
    cout<<"\nAnalisis:"<<endl;
    cout<<"Esto sucede porque el primer intercambio (Intercambio por valor) genero una variable copia e intercambio estas copias"<<endl;
    cout<<"sin embargo lo que tu quieres hacer es intercambiar los valores originales entonces entonces se hace uso de otra cosa"<<endl;
    cout<<"(intercambio por referencia) que hace un llamado de las variables originales mediante su memoria (llamado a la memoria)"<<endl;
}