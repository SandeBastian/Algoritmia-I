#include <iostream>
using namespace std;
int main () {
    char oracion[100];
    int i=0;
    cout<<"Ingrese el oracion:";
    cin>>oracion;
    cout<<"El oracion es: "<<oracion<<endl; //ingresa oracion con espacios
    while (oracion[i]!='\0') i++;
    cout<<"Tiene "<<i<<" caracteres"<<endl;
    return 0;
}