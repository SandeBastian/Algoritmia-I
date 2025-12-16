/*
Crea un arbol binario con valores enteros aleatorios
13, 16, 10, 11, 09, 14, 18, 15
Recorre:
PreOrden
EnOrden
PosOrden
*/
#include <iostream>
using namespace std;

struct nodo {
    //Dato del nodo
    int num;

    //Punteros
    nodo *pI;
    nodo *pD;
};

nodo *piv=NULL;

void creaNodo (nodo *&p, int cod) {
    if (p==NULL) {
        p=new nodo;
        p->num=cod;
        p->pI=NULL;
        p->pD=NULL;
    }
    else {
        if (cod>p->num) {
            creaNodo(p->pD,cod);
        }
        else {
            creaNodo(p->pI,cod);
        }
    }
}

//PRE orden
void recorridoRID (nodo *p) {
    if (p!=NULL) {
        cout<<p->num<<endl;
        recorridoRID(p->pI);
        recorridoRID(p->pD);
    }
}

//IN orden
void recorridoIRD (nodo *p) {
    if (p!=NULL) {
        recorridoIRD(p->pI);
        cout<<p->num<<endl;
        recorridoIRD(p->pD);
    }
}

//POS orden
void recorridoIDR (nodo *p) {
    if (p!=NULL) {
        recorridoIDR(p->pI);
        recorridoIDR(p->pD);
        cout<<p->num<<endl;
    }
}

void creaLista (nodo *&p) {
    int n;
    int num;
    cout<<"Ingrese la cantidad de numero: "; cin>>n;
    for (int i=0;i<n;i++) {
        cout<<"Ingrese el numero["<<i+1<<"]: "; cin>>num;
        creaNodo(p,num);
    }
}

int main () {
    creaLista(piv);
    cout<<"Reccorido Pre-Orden: "<<endl;
    recorridoRID(piv);
    cout<<"Recorido En-Orden: "<<endl;
    recorridoIRD(piv);
    cout<<"Recorido Pos-ORD: "<<endl;
    recorridoIDR(piv);
    return 0;
}