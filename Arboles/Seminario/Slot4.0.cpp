/*
Se tiene el siguiente archivo de texto:
LISTADO.TXT

Especialidad nombre sueldo
CIVIL PEREZ-RUIZ 1800
CIVIL ALVA-TORRES 1700
MECANICO CAMPOS-ALVA 1800
CONTADOR CORREA-RUIZ 1600
MECANICO RUIZ-PEREZ 2000
CIVIL BARRERA-CAMPOS 1900

Se debe crear lista(s) enlazadas usando los datos del archiva.
Luego, se pide por cada Especialidad mostrar
los datos de los empleados siguiendo el siguiente formato.

CIVIL
PEREZ-RUIZ 1800
ALVA-TORRES 1700
BARRERA-CAMPOS 1900
MECANICO
CAMPOS-ALVA 1800
RUIZ-PEREZ 2000
CONTADOR
CORREA-RUIZ 1600
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef char cadena[101];

struct nodo1 {
    cadena nomb;
    int sueldo;
    nodo1 *punt;
};

struct nodo2 {
    cadena esp;
    nodo1 *punt1;
    nodo2 *punt2;
};

nodo2 *piv=NULL;;

void creaNodo1 (nodo1 *&p, cadena nomb, int sueldo ) {
    if (p==NULL) {
        p=new nodo1;
        strcpy(p->nomb, nomb);
        p->sueldo=sueldo;
        p->punt=NULL;
    }
    else {
        creaNodo1(p->punt, nomb, sueldo);
    }
}

void creaNodo2 (nodo2 *&p, cadena esp, cadena nomb, int sueldo) {
    if (p==NULL) {
        p=new nodo2;
        strcpy(p->esp,esp);
        p->punt1=NULL;
        p->punt2=NULL;
        creaNodo1(p->punt1, nomb, sueldo);
    }else {
        if (strcmp(p->esp,esp)==0) {
            creaNodo1(p->punt1, nomb, sueldo);
        }else {
            creaNodo2(p->punt2, esp, nomb, sueldo);
        }
    }
}

void recorre1 (nodo1 *&p) {
    if (p!=NULL) {
        cout<<p->nomb<<"\t"<<p->sueldo<<endl;
        recorre1(p->punt);
    }
}

void recorre2 (nodo2 *&p) {
    if (p!=NULL) {
        cout<<"\n"<<p->esp<<endl;
        recorre1(p->punt1);
        recorre2(p->punt2);
    }
}

void creaLista (nodo2 *&p) {
    ifstream reg ("LISTADO1.0.txt");
    cadena esp, nomb;
    int sueldo;

    if (!reg) {
        cout<<"No se pudo encontrar el archivo"<<endl;
    }
    else {
        while (reg>>esp>>nomb>>sueldo) {
            creaNodo2(p, esp, nomb, sueldo);
        }
        reg.close();
    }
}

int main () {
    creaLista(piv);
    recorre2(piv);
    return 0;
}