#include <iostream>
#include <time.h>
using namespace std;
int main() {
    int m, n, p;
    //srand(time(NULL));
    do {
        cout<<"Ingrese el numero de jugadores:";
        cin>>m;
        if (m<0) cout<<"Error, numero de jugadores invalido."<<endl;
    }while (m<0);
    do {
        cout<<"Ingrese el numero de rondas:";
        cin>>n;
        if (n<0) cout<<"Error, numero de rondas invalido."<<endl;
    }while (n<0);
    do {
        cout<<"Ingrese el numero de juegos:";
        cin>>p;
        if (p<0) cout<<"Error, numero de juegos invalido."<<endl;
    }while (p<0);
    float puntaje[m][n][p];
    float suma[m]={0};
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<p;k++) {
                puntaje[i][j][k]=0+rand()%21;
            }
        }
    }
    /*
    for (int i=0; i<m; i++) {
        cout<<"\nJugador "<<i+1<<": "<<endl;
        for (int j=0; j<n; j++) {
            for (int k=0; k<p; k++) {
                cout<<puntaje[i][j][k]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    */

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<p;k++) {
                suma[i]=suma[i]+puntaje[i][j][k];
            }
        }
    }

    float prom=0;
    for (int i=0; i<m; i++) {
        prom=prom+suma[i];
    }
    prom=prom/float(m);
    for (int i=0;i<m;i++) {
        cout<<"\nJugador #"<<i+1<<":"<<endl;
        for (int j=0;j<n;j++) {
            for (int k=0;k<p;k++) {
                cout<<puntaje[i][j][k]<<"\t";
            }
            cout<<endl;
        }
        if (!(suma[i]<prom-10||suma[i]>prom+10)) {
            cout<<"\nJugador #"<<i+1<<":"<<endl;
            cout<<"Puntaje Total: "<<suma[i]<<endl;
            cout<<"Promedio: "<<prom<<endl;
            cout<<endl;
        }
    }
    int k;
    cout<<"Solicite el puntaje total de algun jugador: "<<endl;
    do {
        cout<<"Jugador #: ";
        cin>>k;
    }while (k<0||k>m);
    cout<<"Puntaje del jugador "<<k<<": "<<suma[k-1]<<endl;
    return 0;
}