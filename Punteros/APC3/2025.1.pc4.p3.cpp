/*
Programa que genere una lista enlazada de enteros. El programa pide ingresr una lista (desordenada), se debe recorrer la lista e identificar
y eliminar todos los nodos que contengan valores duplicados, dejando solo la primera ocurrencia
lista ingresada: '4'->'1'->2->4->3->1->5
lista resultante: 4->1->2->3->5
4 y 1 con comillas fueron los primeros ingresados por eso estos se mantienen y la repeticiones despues se eliminan
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    int num;
    nodo *punt;
};

nodo *piv;

void creaNodo(nodo *&p) {
    int num;
    if (p==NULL) {
        cout<<"Ingresa num: "; cin>>num;
        p=new nodo;
        p->num=num;
        p->punt=NULL;
    }else {
        creaNodo(p->punt);
    }
}

void eliminar(nodo *&q2) {
    nodo *ant, *act;
    ant=NULL;
    act=piv;
    while (act!=q2) {
        ant=act;
        act=act->punt;
    }
    ant->punt=act->punt;
    delete act;
}

void busqueda(nodo *&p) {
    nodo *q1, *q2, *q3;
    q1=p;
    q2=NULL;
    while (q1!=NULL) {
        q2=q1->punt;
        while (q2!=NULL) {
            if (q1->num==q2->num) {
                q3=q2->punt;
                eliminar(q2);
                q2=q3;
            }
            else {
                q2=q2->punt;
            }
        }
        q1=q1->punt;
    }
}

void creaLista(nodo *&p) {
    piv=NULL;
    int n;
    cout<<"Ingrese la cantidad de numeros: ";
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Nodo ["<<i+1<<"]: "<<endl;
        creaNodo(p);
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->num<<" ";
        recorre(p->punt);
    }
}

int main () {
    creaLista(piv);
    recorre(piv);
    busqueda(piv);
    recorre(piv);
    return 0;
}