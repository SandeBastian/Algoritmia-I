#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct nodo {
    char letra;
    int frec;
    nodo *izq;
    nodo *der;
    nodo *punt;
};

nodo *piv = NULL;

void creaNodo(nodo *&ins, char letra, int freq, nodo *izq, nodo *der) {
    ins = new nodo;
    ins->letra = letra;
    ins->frec = freq;
    ins->izq = izq;
    ins->der = der;
    ins->punt = NULL; // FIX: faltaba inicializar
}

void intercambia(nodo *q1, nodo *q2) {
    char auxL = q1->letra;
    q1->letra = q2->letra;
    q2->letra = auxL;

    int auxC = q1->frec;
    q1->frec = q2->frec;
    q2->frec = auxC;
}

void ordena(nodo *p) {
    nodo *q1 = p, *q2;
    while (q1 != NULL) {
        q2 = q1->punt;
        while (q2 != NULL) {
            if (q1->frec > q2->frec) {
                intercambia(q1, q2);
            }
            q2 = q2->punt;
        }
        q1 = q1->punt;
    }
}

void buscar(nodo *&p, nodo *&ant, nodo *&act, char letra, bool &yaExiste) {
    while (act != NULL) {
        if (letra != act->letra) {
            ant = act;
            act = act->punt;
        } else {
            yaExiste = true;
            return;
        }
    }
}

void insertarOrdenado(nodo *&p, nodo *nuevo) {
    if (p == NULL ||
        nuevo->frec < p->frec ||
        (nuevo->frec == p->frec &&
         nuevo->letra != '\0' && p->letra == '\0')) {

        nuevo->punt = p;
        p = nuevo;
        return;
         }

    nodo *act = p;
    while (act->punt != NULL &&
          (act->punt->frec < nuevo->frec ||
          (act->punt->frec == nuevo->frec &&
           !(nuevo->letra != '\0' && act->punt->letra == '\0')))) {

        act = act->punt;
           }

    nuevo->punt = act->punt;
    act->punt = nuevo;
}


void creaArbol(nodo *&p) {
    while (p != NULL && p->punt != NULL) {

        nodo *izq = p;
        nodo *der = p->punt;

        nodo *resto = der->punt; // FIX: avanzar la lista

        nodo *padre;
        creaNodo(padre, '\0', izq->frec + der->frec, izq, der);

        izq->punt = NULL;
        der->punt = NULL;

        p = resto;               // FIX: quitar los dos nodos usados
        insertarOrdenado(p, padre);
    }
}

void recorreArbol(nodo *r, string codigo) {
    if (r == NULL) return;

    if (r->letra != '\0') {
        cout << r->letra << " : " << codigo << endl;
        return;
    }

    recorreArbol(r->izq, codigo + "0");
    recorreArbol(r->der, codigo + "1");
}

void recorre(nodo *p) {
    while (p != NULL) {
        cout << p->letra << "[" << p->frec << "]\t";
        p = p->punt;
    }
    cout << endl;
}

int main() {
    string cadena;
    cout << "Ingrese la cadena en mayusculas: ";
    getline(cin, cadena);

    for (char letra : cadena) {
        if (letra == ' ') continue;

        nodo *ant = NULL;
        nodo *act = piv;
        nodo *ins = NULL;
        bool yaExiste = false;

        buscar(piv, ant, act, letra, yaExiste);

        if (!yaExiste) {
            creaNodo(ins, letra, 1, NULL, NULL);
            if (ant == NULL) {          // FIX: inserción correcta al inicio
                ins->punt = piv;
                piv = ins;
            } else {
                ant->punt = ins;
                ins->punt = act;
            }
        } else {
            act->frec++;
        }
    }

    ordena(piv);
    recorre(piv);

    creaArbol(piv);

    cout << "Los codigos:" << endl;
    recorreArbol(piv, "");

    return 0;
}
