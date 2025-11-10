/*
Sucesicion de Fibonacci
*/
#include <iostream>
using namespace std;

double fib (int n) {
    if(n==1||n==2) return 1;
    return fib(n-1)+fib(n-2);
}

int main () {
    int n;
    cout<<"Ingrese el n: ";
    cin>>n;
    cout<<"Fibonacci Mine #"<<n<<": "<<fib(n)<<endl;
    return 0;
}