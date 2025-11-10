#include <iostream>
using namespace std;
int main() {
    int n, max=0, min=0;
    float prom=0;

    do {
        cout<<"Ingrese la cantida de numeros: ";
        cin>>n;
        if (n<=0) cout<<"Error. Valor no valido."<<endl;
    }while (n<=0);

    int a[n]={0};
    for (int i=0; i<n; i++ ) {
        cout<<"a["<<i+1<<"]:";
        cin>>a[i];
    }

    max=a[0];
    min=a[0];
    for (int i=0; i<n; i++) {
        if (max<a[i]) max=a[i];
        if (min>a[i]) min=a[i];
        prom+=a[i];
    }

    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
    cout<<"Prom: "<<prom/n<<endl;
    return 0;
}