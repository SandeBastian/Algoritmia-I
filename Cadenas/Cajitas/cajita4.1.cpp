#include <iostream>
using namespace std;
int main () {
    char oracion[100];
    int i=0;
    cout<<"Ingrese el oracion:";
    gets(oracion); //parece que tiene problemas porque no controla las longitudes
    cout<<"El oracion es: "<<oracion<<endl; //ingresa oracion con espacios GETS soporta
    while (oracion[i]!='\0') i++;
    cout<<"Tiene "<<i<<" caracteres"<<endl;
    return 0;
}