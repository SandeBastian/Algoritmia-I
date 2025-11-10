#include <iostream>
using namespace std;
typedef char cadena[5];
int main () {
    cadena nombre;
    cout<<"Ingrese el nombre:"; //igual que con solo char sin alias, solo recibe 4 caracteres "sebas" prueba
    cin>>nombre;
    cout<<"El nombre es: "<<nombre<<endl;
    return 0;
}