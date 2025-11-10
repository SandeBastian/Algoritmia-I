/*
Sucesicion de Fibonacci
*/
#include <iostream>
using namespace std;

double fib (int n) {
    if (n>2) return fib(n-1)+fib(n-2);
    return 1;
}

int main () {
    int n;
    cout<<"Ingrese el n: ";
    cin>>n;
    cout<<"Fibonacci Sotelo #"<<n<<": "<<fib(n)<<endl;
    return 0;
}