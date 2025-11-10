#include <iostream>
using namespace std;
int main () {
    char simbolo; //esta forma de declarar simbolo solo admite 1 cracter 'A' 'B' ....
    cout<<"Ingrese el simbolo:";
    cin>>simbolo;
    cout<<"El simbolo es :"<<simbolo<<endl; //Escribe Avena por ejemplo, solo admite A
    int simboloInt=simbolo;
    cout<<"El simboloInt es: "<<simboloInt<<endl;
    return 0;
}