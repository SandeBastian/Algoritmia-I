#include <iostream>
using namespace std;

void evalua (int n, int &cnt) {
    while (n!=0) {
        n=n/10;
        cnt++;
    }
}

void almacena(int n, int arr[], int cnt) {

}

int main () {
    int a;
    int b;
    do {
        cout<<"Ingrese el valor de n:";
        cin>>a;
        if (a<100000) cout<<"Error. valor no valido"<<endl;
    }while (a<100000);
    int cnt1=0;
    evalua (a, cnt1);
    int arr1[cnt1];

    almacena (a, arr1, cnt1);

    do {
        cout<<"Ingrese el valor de m:";
        cin>>b;
        if (a<1000) cout<<"Error. valor no valido"<<endl;
    }while (a<1000);
    int cnt2=0;
    evalua (b, cnt2);
    int arr2[cnt2];
    almacena (b, arr2, cnt2);

    return 0;
}