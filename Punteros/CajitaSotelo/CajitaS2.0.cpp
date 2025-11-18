#include <iostream>
using namespace std;
int main () {
    int x[5]={1,2,3,4,5};
    int *p;
    p=&x[0];

    while (p!=NULL) {
        cout<<*p<<endl;
        if (*p==5) {
            p=NULL;
        }else {
            p++; //Avanza al a siguiente direccion de MEMORIA que en arreglo seria el siguiente elemento x[i+1];
        }
    }
}