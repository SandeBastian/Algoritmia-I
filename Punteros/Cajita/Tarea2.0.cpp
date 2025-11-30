/*
Se tiene, ya existe el archivo de texto llamado PROMEDIOS.TXT, el cual contiene
la siguiente información:
NOTAS.TXT
Codigo Promedio Seccion
111 12.3 A
333 11.4 B
555 10.8 A
777 11.4 C
999 12.3 B
Se pide almacenar los datos del archivo en una lista dinámica. Luego presentar la
lista ordenada en base al promedio (decreciente), en caso existan promedios
iguales, ordenarla en base a la sección (creciente).
Despues de ordenar...
111 12.3 A
999 12.3 B
333 11.4 B
777 11.4 C
555 10.8 A
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {
    int Cod;
    float Pf;
    char Sec;
    nodo *punt;
};

nodo *piv=NULL;

void crea_nodo (nodo *&p, int cod, float pf, char sec) {
    if (p==NULL) {
        p=new nodo;
        p->Cod=cod;
        p->Pf=pf;
        p->Sec=sec;
        p->punt=NULL;
    }else {
        crea_nodo(p->punt, cod, pf, sec);
    }
}

void intercambia (nodo *&q1, nodo *&q2) {
    int auxCod=q1->Cod;
    q1->Cod=q2->Cod;
    q2->Cod=auxCod;


    float auxPf=q1->Pf;
    q1->Pf=q2->Pf;
    q2->Pf=auxPf;

    char auxSec=q1->Sec;
    q1->Sec=q2->Sec;
    q2->Sec=auxSec;
}

void crea_lista (nodo *&p) {
    int cod;
    float pf;
    char sec;
    ifstream Regente;
    Regente.open("NOTAS.8.TXT");
    if (!Regente) {
        cout<<"Error al abrir el archivo, tal vez no existe."<<endl;
    }else {
        while (Regente) {
            if (Regente>>cod>>pf>>sec) {
                crea_nodo(p, cod, pf, sec);
            }
        }
    }
}

void ordena (nodo *&p) {
    nodo *q1, *q2;
    q1=p;
    while (q1!=NULL) {
        q2=q1->punt;
        while (q2!=NULL) {
            if (q1->Pf<q2->Pf) {
                intercambia(q1, q2);
            }
            if (q1->Pf==q2->Pf) {
                if (q1->Sec>q2->Sec) {
                   intercambia(q1, q2);
                }
            }
            q2=q2->punt;
        }
        q1=q1->punt;
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->Cod<<"\t"<<p->Pf<<"\t"<<p->Sec<<endl;
        recorre(p->punt);
    }
}

int main () {

    crea_lista(piv); //Crea la lista e imprime
    cout<<"Antes: "<<endl;
    recorre(piv);

    ordena(piv); //ordena la lista de nodos

    cout<<"\nDespues: "<<endl; //Imprime la lista despues de ordenar
    recorre(piv);
    return 0;
}