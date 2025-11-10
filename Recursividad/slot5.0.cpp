/*
Crear una funcion recursiva que permita calcular la combinatoria de m
numeros en n grupos
(m, n) = m!/(m-n)!n!, m>=n
(m, 0) = 1
(m, m) = 1
*/
#include <iostream>
using namespace std;

int combinar(int a,int b) {
    if (a==b||b==0) return 1;
    return combinar (a-1, b) + combinar (a-1, b-1);
}

int main() {
    int a, b;
    cout<<"a: "; cin>>a;
    cout<<"b: "; cin>>b;
    cout<<"Combinatoria de m en n: "<<combinar(a,b);
    return 0;
}