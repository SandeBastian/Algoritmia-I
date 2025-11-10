/*
Crear una función recursiva que permita determinar cuántos mensajes diferentes
se pueden generar en una señal que dura n segundos. Sabiendo que las señales solo
pueden ser:
Un punto: dura 1 segundo
Una raya: dura 2 segundos
Veamos:
n (segundos) Seniaales # de mensajes        Fn
1 .                         1               F1
2 ..; -                     2               F2
3 ...; .-; -.               3               F3=F2+F1
4 ..-; .-.; -..; --; ....   5               F4=F3+F2
F1=1
F2=2
Fn = Fn-1 + Fn-2, n>=2
*/
#include <iostream>
using namespace std;

int mensajes(int n) {
    if (n==1) return 1;
    if (n==2) return 2;
    return mensajes(n-1)+mensajes(n-2);
}

int main () {
    int n;
    cout<<"# Segundos: "; cin>>n;
    cout<<"La cantidad de mensajes es: "<<mensajes(n)<<endl;
}