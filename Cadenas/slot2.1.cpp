#include <iostream>
using namespace std;
int main () {
    char Letra;
    cout<<"Letra:"; cin>>Letra;
    //                 (Final-inicial) || (B-b)
    char LetraMayus=Letra+('A'-'a'); //Letra + 32
    cout<<"LetraMayus: "<<LetraMayus<<endl;
    return 0;
}