#include <iostream>
using namespace std;

int x[] = {10, 20, 30};

// Nodo
struct Nodo {
    int Cod;
    Nodo* punt;
};

// Variable puntero para la lista
Nodo* lista = NULL;

// Funcion que crea un Nodo
void Crea_Nodo(Nodo*& p, int Cod) {
    if (p == NULL) {
        p = new Nodo;
        p->Cod = Cod;
        p->punt = NULL;
    } else {
        Crea_Nodo(p->punt, Cod);
    }
}


// Funcion que crea la lista
void Crea_lista(Nodo*& p) {
    int n = 3;
    for (int i = 0; i < n; i++) {
        Crea_Nodo(p, x[i]);
    }
}

// Funcion que recorre la lista (recursiva)
void Recorre(Nodo* p) {
    if (p != NULL) {
        cout << p->Cod << "\t" << endl;
        Recorre(p->punt); // Llamada recursiva al siguiente nodo
    }
}

int main() {
    // Inicializar la lista como NULL
    lista = NULL;

    // Llamando a Crea_lista
    Crea_lista(lista);

    // Llamando a Recorre
    Recorre(lista);

    return 0;
}
