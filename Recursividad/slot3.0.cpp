/*
Imprimir divisores de un numero con una funcion recursiva
*/
#include <iostream>
using namespace std;

void divisores (int n, int d) {
   if (d<=n) {
       if (n%d==0) cout<<d<<" ";
       return divisores(n, d+1);
   }
}

int main () {
    int n;
    cout<<"Ingrese el n: ";
    cin>>n;
    cout<<"Divisores de "<<n<<" : "; divisores(n,1);
    return 0;
}