/*
Ordenamiento de una COLA (FIFO) de estudiantes que tengan datos del Código y
promedio final
Codigo  Promedio Final
111     13.5
222     08.7
333     14.5
*/

#include <iostream>
using namespace std;

struct nodo {
    int Cod;
    float Pf;
    nodo *punt;
};

nodo *head=NULL;
void crea_nodo (nodo *&p) {
    int cod;
    float pf;
    if (p==NULL) {
        cout<<"Ingresa Cod: "; cin>>cod;
        cout<<"Ingresa Pf: "; cin>>pf;
        p=new nodo;
        p->Cod=cod;
        p->Pf=pf;
        p->punt=NULL;
    }else {
        crea_nodo(p->punt);
    }
}

void crea_lista (nodo *&p) {
    int n;
    cout<<"Ingrese la cantidad de datos: "; cin>>n;
    for (int i=0; i<n; i++) {
        crea_nodo(p);
    }
}

void Ordena(nodo *p) {
    nodo *q1, *q2;
    int auxC;
    q1 = p;
    while(q1!=NULL){
        q2 = q1->punt;
        while(q2!=NULL){
            if(q1->Cod > q2->Cod){
                auxC = q1->Cod;
                q1->Cod = q2->Cod;
                q2->Cod = auxC;
            }
            q2 = q2->punt;
        }
        q1=q1->punt;
    }

}

int main () {

}
