#include <iostream>
using namespace std;
int main () {
    char cadena[100];
    cout<<"Cadena:";
    cin.getline(cadena,100);
    int i=0;
    int cont=0;
    while (cadena[i]!='\0') {
        switch(cadena[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': cont++;
            default: break;
        }
        i++;
    }
    cout<<"LA cadena tiene "<<cont<<" vocales"<<endl;
    return 0;
}