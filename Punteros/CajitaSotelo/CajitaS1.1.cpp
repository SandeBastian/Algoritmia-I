#include <iostream>
using namespace std;
int main() {
    int x=1, y=2;
    int *p;

    // 'p' apunta donde sea
    cout<<"\nCaso 1 (solo crea puntero): "<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    //cout<<"*p: "<<*p<<endl;

    cout<<"\nMemoria 1: "<<endl;
    cout<<"x: "<<&x<<endl;
    cout<<"y: "<<&y<<endl;


    p=&x; // 'p' apunta a la memoria de 'x' (sus memorias ahora son las mismas)
    y=*p; // 'y' toma el valor de 'p' pero solo su valor.
    cout<<"\nCaso 2 (Asigna una memoria a *p): "<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"*p: "<<*p<<endl;


    *p=*p+3; // Incrementa en 3 a los que tenia apuntado p? cambia x e p?
    cout<<"\nCaso 3 (Cambia *p y x???): "<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"*p: "<<*p<<endl;

    x=x+3; // Incrementa en 3 a x, cambiara *p???
    cout<<"\nCaso 3.00 (Cambia *p y x???): "<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"*p: "<<*p<<endl;

    p=NULL;
    cout<<"\nCaso 4 (Final *p ahora apunta a NADA): "<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"*p: "<<*p<<endl;

    return 0;
}