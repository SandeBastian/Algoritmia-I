/*
Se tiene (ya existe) el archivo fisico
PEDIDOS.DAT
Codigo Numero unidades
222 150
111 80
444 100
222 50
333 200
444 200
Mediante un arbol binario, presentar los pedidos ordenado en forma creciente
respecto al codigo y totalizados, esto es:
Codigo Numero de unidades
111 80
222 200
333 200
444 300
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    //Dato del nodo
    int cod;
    int num;

    //Punteros
    nodo *pI;
    nodo *pD;
};

struct reg {
    int cod;
    int num;
};

nodo *piv=NULL;

void creaNodo (nodo *&p, int cod, int num) {
    if (p==NULL) {
        p=new nodo;
        p->cod=cod;
        p->num=num;

        p->pI=NULL;
        p->pD=NULL;
    }
    else {
        if (cod==p->cod) {
            p->num=p->num+num;
        }else {
            if (cod>p->cod) {
                creaNodo(p->pD,cod, num);
            }
            else {
                creaNodo(p->pI,cod, num);
            }
        }
    }
}

//IN orden
void recorridoIRD (nodo *p) {
    if (p!=NULL) {
        recorridoIRD(p->pI);
        cout<<p->cod<<"\t"<<p->num<<endl;
        recorridoIRD(p->pD);
    }
}

void creaLista (nodo *&p) {
    reg r; //Estructura temporal donde se guarda Cod y Num

    ifstream f;
    f.open("PEDIDOS.DAT");
    if (!f) {
        cout<<"Error al encontrar el archivo"<<endl;
    }
    else {
        while (f.read((char*)&r,sizeof(r))) {
            creaNodo(p,r.cod,r.num);
        }
        f.close();
    }
}

int main () {
    creaLista(piv);
    recorridoIRD(piv);
    return 0;
}