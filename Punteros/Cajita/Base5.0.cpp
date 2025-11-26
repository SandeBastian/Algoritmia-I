/*
Se tiene, (ya existe) el siguiente archivo de texto
PEDIDOS.txt
cod unid
100 20
120 30
100 50
120 100
130 50
Crear un programa que muestre un reporte de los productos totalizados
cod unid
100 70
120 130
130 50
*/

#include <iostream>
#include <fstream>
using namespace std;

// Nodo
struct Nodo {
    int Cod;
    int Unid;
    Nodo* punt;
};

// Variable puntero para la lista
Nodo* lista = NULL;

// Funcion que crea un Nodo
void Crea_Nodo(Nodo*& p, int cod, int unid) {
    if (p == NULL) {
        p = new Nodo;
        p->Cod = cod;
        p->Unid = unid;
        p->punt = NULL;
    } else {
        if(cod == p->Cod) {
            p->Unid = p->Unid + unid;
        }else{
            Crea_Nodo(p->punt, cod, unid);
        }
    }
}

// Funcion que crea la lista
void Crea_lista(Nodo*& p) {
    int n = 3;
    int cod;
    int unid;
    ifstream ent;
    ent.open("PEDIDOS.txt");
    if (!ent) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }else{
        while(ent >> cod >> unid) {
            Crea_Nodo(p, cod, unid);
        }
        ent.close();
    }
}

// Funcion que recorre la lista (recursiva)
void Recorre(Nodo* p) {
    if (p != NULL) {
        cout << p->Cod << "\t"<< p->Unid << endl;
        Recorre(p->punt); // Llamada recursiva al siguiente nodo
    }
}

int main() {

    // Llamando a Crea_lista
    Crea_lista(lista);

    // Llamando a Recorre
    Recorre(lista);

    return 0;
}