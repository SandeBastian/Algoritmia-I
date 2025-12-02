/*
Desarrolle un programa que lea un archivo de texto "Vuelos txt
codigo(ente de 4 dig) destino(Hasta 25 caracte) asientos tot (ent) asientos disp( ent) precio base (real))
Asuma que los Datos estan separados por 1 o mas espacios en blanco
1. Cargar los registros del archhivo en una lista enlazada. PAra cada vuelo ademas calcule el porcentaje de ocupacion
2. Ordene la lista de mayor a menor porcentaje de ocupacion y si  hay empate por precio base descendente. Muestre la lista ordenada
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct nodo {
    int cod;
    char dest;
    int asienT;
    int asienD;
    float precio;
    float porc;
    nodo *punt;
};

nodo *piv;

void creaNodo(nodo *p, int cod, char dest, char asienT, char asienD, float precio) {
    if (p==NULL) {
        float porc;
        porc=(asienT-asienD)/(asienT)*100;
        p=new nodo;
        p->cod = cod;
        p->dest = dest;
        p->asienT = asienT;
        p->asienD = asienD;
        p->precio = precio;
        p->porc = porc;
        p->punt = NULL;
    }else {
        creaNodo(p->punt, cod, dest, asienT, asienD, precio);
    }
}

void creaLista(nodo *&p) {
    int cod;
    char dest;
    int asienT;
    int asienD;
    float precio;
    ifstream ent;
    ent.open ( "VUELOS.txt");
    if (!ent) {
        cout<<"Error al abrir el archivo."<<endl;
    } else {
        while (ent>>cod>>dest>>asienT>>asienD>>precio) {
            creaNodo(p, cod, dest, asienT, asienD, precio);
        }
        ent.close();
    }
}


void intercambia (nodo *&q1, nodo *&q2) {
    int auxCod=q1->cod;
    q1->cod=q2->cod;
    q2->cod=auxCod;

    char auxDest=q1->dest;
    q1->dest=q2->dest;
    q2->dest=auxDest;

    int auxAsienT=q1->asienT;
    q1->asienT=q2->asienT;
    q2->asienT=auxAsienT;

    int auxAsienD=q1->asienD;
    q1->asienD=q2->asienD;
    q2->asienD=auxAsienD;

    float auxPrecio=q1->precio;
    q1->precio=q2->precio;
    q2->precio=auxPrecio;

    float auxPorc=q1->porc;
    q1->porc=q2->porc;
    q2->porc=auxPorc;
}

void ordena(nodo *&p) {
    nodo *q1, *q2;
    int auxC;
    float auxP;
    q1 = p;
    while(q1!=NULL){
        q2 = q1->punt;
        while(q2!=NULL){
            if(q1->porc < q2->porc){
                intercambia (q1, q2);
            }
            if (q1->porc==q2->porc) {
                if (q1->precio < q2->precio) {
                    intercambia (q1, q2);
                }
            }
            q2 = q2->punt;
        }
        q1=q1->punt;
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->dest<<"\t"<<p->asienT<<"\t"<<p->asienD<<"\t"<<p->precio<<endl;
        recorre(p->punt);
    }
}

int main () {
    piv=NULL;
    creaLista(piv);
    ordena(piv);
    recorre(piv);
    return 0;
}