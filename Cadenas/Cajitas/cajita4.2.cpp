#include <iostream>
using namespace std;
int main () {
    char oracion[100];
    int i=0;
    cout<<"Ingrese el oracion:";
    cin.getline(oracion, 20); //si controla longitudes, cambia su tamaño por uno pequeño para que veas '\0'
    cout<<"El oracion es: "<<oracion<<endl; //ingresa la oracion como quieras
    while (oracion[i]!='\0') i++;
    cout<<"Tiene "<<i<<" caracteres"<<endl;
    return 0;
}