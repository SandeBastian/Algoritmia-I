/*
Sucesicion de Fibonacci
*/
#include <iostream>
using namespace std;

double fib (int n) {
    switch (n) {
        case 1:
        case 2: return 1;
        default: return fib(n-1) + fib(n-2);
    }
}

int main () {
    int n;
    cout<<"Ingrese el n: ";
    cin>>n;
    cout<<"Fibonacci Switch #"<<n<<": "<<fib(n)<<endl;
    return 0;
}