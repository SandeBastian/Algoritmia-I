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
    ent.open ( "PROMEDIOS.txt");
    if (!ent) {
        cout<<"Error al abrir el archivo."<<endl;
    } else {
        while (ent>>cod>>pf) {
            crea_nodo(p, cod, pf);
        }
        ent.close();
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
    recorre (lista);
    return 0;
}