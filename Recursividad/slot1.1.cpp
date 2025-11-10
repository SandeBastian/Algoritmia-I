//Factorial de un numero pero sin Funcion recursiva para que compares la rapidez
#include <iostream>
using namespace std;
int main () {
     int n;
     int f=1;
     cout<<"n: "; cin>>n;
     for (int i=1; i<=n; i++) {
         f=f*i;
     }
    cout<<"El factorial de n es: "<<f<<endl;
    return 0;
 }