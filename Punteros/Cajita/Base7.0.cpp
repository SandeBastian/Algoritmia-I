/*
Se tiene, ya existe el archivo de texto llamado PROMEDIOS:TXT, el cual contiene la siguiente informacion:
--PROMEDIOS.TXT--
Codigo      Promedio
111         12.3
333         11.4
555         10.8
777         14.5
999         11.4
Se pide almacenar los datos del archivo en una lista dinamica. Luego presentar la lista
ordenada con respecto al promedio
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Nodo {
    int Cod;
    float Pf;
    Nodo *punt;
};

Nodo *lista=NULL;

void crea_nodo (Nodo*&p, int cod, float pf) { //Aqui ya entran los datos de archivo
    if ( p == NULL ) {
        p=new Nodo;
        p->Cod = cod;
        p->Pf = pf;
        p->punt = NULL;
    }
    else {
        crea_nodo(p->punt, cod, pf);
    }
}

void crea_lista (Nodo*&p) {
    int cod;
    float pf;
    ifstream ent;
    ent.open ( "NOTAS.7.txt");
    if (!ent) {
        cout<<"Error al abrir el archivo."<<endl;
    } else {
        while (ent>>cod>>pf) {
            crea_nodo(p, cod, pf);
        }
        ent.close();
    }
}

void ordena(Nodo *p) {
    Nodo *q1, *q2;
    int auxC;
    float auxP;
    q1 = p;
    while(q1!=NULL){
        q2 = q1->punt;
        while(q2!=NULL){
            if(q1->Pf > q2->Pf){
                auxC = q1->Cod;
                q1->Cod = q2->Cod;
                q2->Cod = auxC;

                auxP = q1->Pf;
                q1->Pf = q2->Pf;
                q2->Pf = auxP;
            }
            q2 = q2->punt;
        }
        q1=q1->punt;
    }
}


void recorre (Nodo *p) {
    if (p!=NULL) {
        cout<<p->Cod<<"\t"<<p->Pf<<endl;
        recorre(p->punt);
    }
}

int main() {
    lista = NULL;
    crea_lista (lista);
    ordena(lista);
    recorre (lista);
    return 0;
}