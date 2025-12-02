/*
Se tiene (ya existe ) el archivo de texto llamado ENCUESTA.txt, el cual contiene por cada linea de voto o no de un encuestado por uno o mas
candidatos a las elecciones presidenciales. Cada candidato esta representado por un numero de 3 cifras y luego una S que indica que el
encuestado si votaria por ese candidato y N representa que no votaria por ese candidato. A continuacion una parte del archivo.
Archivo.txt:
120 S
140 S
110 N
140 N
110 S
130 S
140 N
120 S
120 N
110 S
Se observa:
120 2 (S) y 1 (N)
140 1 (S) y 2 (N)
110 2 (S) y 1 (N)
130 1 (S) y 0 (N)
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct nodo {
    int cod;
    char voto;
    nodo *punt;
};

nodo *piv;

void creaNodo(nodo *&p, int cod, char voto) {
        if (p==NULL) {
            p=new nodo;
            p->cod=cod;
            p->voto=voto;
            p->punt=NULL;
        }else {
            creaNodo(p->punt, cod, voto);
        }
    }


void creaLista(nodo *&p) {
    int cod;
    char voto;
    ifstream ent;
    ent.open ( "PROMEDIOS.txt");
    if (!ent) {
        cout<<"Error al abrir el archivo."<<endl;
    } else {
        while (ent>>cod>>voto) {
            creaNodo(p, cod, voto);
        }
        ent.close();
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->voto;
        recorre(p->punt);
    }
}

int main () {
    piv=NULL;
    creaLista(piv);
    recorre(piv);
    return 0;
}