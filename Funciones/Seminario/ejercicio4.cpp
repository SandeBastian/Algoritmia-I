/*
Funcion para determinar el mcd y mcm de dos numeros
*/
#include <iostream>
using namespace std;

int obtenerMCD(int x, int y) {
   int r;
    do {
        r=x%y;
        x=y;
        y=r;
    }while (r!=0);
    return x;
}
int mcdMultiple(int x[], int n) {
    int mcd=0;
    for (int i=0; i<n; i++) {
        if (i==0) mcd=x[i];
        else mcd=obtenerMCD(mcd, x[i]);
    }
    return mcd;
}

int main () {
    int n;
    cout<<"n: ";
    cin>>n;
    int num[n];
    for (int i=0; i<n; i++) {
        cout<<"num["<<i+1<<"]: ";
        cin>>num[i];
    }
    cout<<"El MCD es: "<<mcdMultiple(num, n)<<endl;
    return 0;
}