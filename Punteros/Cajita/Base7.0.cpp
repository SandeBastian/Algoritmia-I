/*
Se tiene, ya existe el archivo de texto llamado PROMEDIOS.TXT, el cual contiene
la siguiente informacion:
PROMEDIOS.TXT
Codigo Promedio
111 12.3
333 11.4
555 10.8
777 14.5
999 11.4
Se pide almacenar los datos del archivo en una lista dinamica. Luego presentar la
lista
*/

    #include <iostream>
    #include <fstream>
    using namespace std;

// Nodo
struct Nodo {
    int Cod;
    float pf;
    Nodo* punt;
};

// Variable puntero para la lista
Nodo* lista = NULL;

// Funcion que crea un Nodo
void Crea_Nodo(Nodo*& p, int Cod, float pf) {
    if (p == NULL) {
        p = new Nodo;
        p->Cod = Cod;
        p->pf = pf;
        p->punt = NULL;
    } else {
        Crea_Nodo(p->punt, Cod, pf);
    }
}

// Funcion que crea la lista
void Crea_lista(Nodo*& p) {
    int n = 3;
    int cod;
    float pf;
    ifstream ent;
    ent.open("PROMEDIOS.TXT");
    if (!ent) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }else{
        while(ent >> cod >> pf) {
            Crea_Nodo(p, cod, pf);
        }
        ent.close();
    }


}

// Funcion que recorre la lista (recursiva)
void Recorre(Nodo* p) {
    if (p != NULL) {
        cout << p->Cod << "\t"<< p->pf << endl;
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
