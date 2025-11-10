#include <iostream>
using namespace std;
int main () {
    char nombre[101]; //prueba con numeros bajos para que veas que '\0' ocupa 1 espacio al final
    cout<<"Ingrese el nombre:";//ingresa "sebas" tiene 5 caracteres solo recibe 4 porque el ultimo es el salto o final de linea
    cin>>nombre;
    cout<<"El nombre es: "<<nombre<<endl;
    return 0;
}