/*
Una técnica para comprimir textos es la siguiente:
a) Contar frecuencias: Se cuenta la frecuencia de cada símbolo en el conjunto de datos.
b) Crear nodos: Se crea un nodo para cada símbolo con su frecuencia.
c) Ordenar nodos: Se ordenan los nodos por frecuencia de menor a mayor.
d) Combinar nodos: Se combinan los dos nodos con menor frecuencia en un nuevo nodo con frecuencia
    igual a la suma de las frecuencias de los nodos combinados. Siempre va a la izquierda el nodo
    que tiene la cadena de longitud 1
e) Asignar códigos: Se asigna un código binario a cada nodo:
    • Se le asigna un 0 al nodo izquierdo y un 1 al nodo derecho.
    • Los códigos binarios de cada símbolo se construyen recorriendo el árbol desde la raíz hasta el
    nodo del símbolo. Los nodos símbolos son las hojas finales
    del árbol binario.

Por ejemplo si el texto es “LA PILAAAA”
Paso 1: Contar frecuencias
    L: 2 A: 5 P: 1 I: 1
Paso 2: Crear nodos
    L (2) A(5) P(1) I(1)
Paso 3: Ordenar nodos
    P (1) I (1) L (2) A (5)
Paso 4: Combinar nodos (construir árbol binario)
    - P (1) + I (1) = PI (2)
    - L (2) + PI (2) = LPI (4)
    - A (5) + LPI (4) = ALPI (9)
Paso 5: Asignar códigos
    - A: 0
    - L: 10
    - P: 110
    - I: 111
Crear un programa que permita recibir una línea de texto (en mayúscula) y los nos presente los códigos asignados a cada símbolo diferente.
*/
#include <iostream>
#include <cstring>
using namespace std;

struct nodo {
    char letra;
    int frec;
    nodo *izq;
    nodo *der;
    nodo *punt;
};

nodo *piv=NULL;

void creaNodo (nodo *&ins, char letra, int freq, nodo *izq, nodo *der ) {
    ins = new nodo;
    ins->letra = letra;
    ins->frec = freq;
    ins->izq = izq;
    ins->der = der;
}

void intercambia(nodo *q1, nodo *q2) {
    char auxL=q1->letra;
    q1->letra = q2->letra;
    q2->letra = auxL;

    int auxC = q1->frec;
    q1->frec = q2->frec;
    q2->frec = auxC;
}

void ordena(nodo *p) {
    nodo *q1, *q2;
    q1 = p;
    while(q1!=NULL){
        q2 = q1->punt;
        while(q2!=NULL){
            if(q1->frec > q2->frec){
                intercambia(q1,q2);
            }
            q2 = q2->punt;
        }
        q1=q1->punt;
    }
}


void buscar (nodo *&p, nodo *&ant, nodo *&act, char letra, bool &yaExiste) {
    while (act!=NULL) {
        if(letra!=act->letra){
            ant=act;
            act=act->punt;
        }
        else {
            yaExiste=true;
            break;
        }
    }
}

void buscar (nodo *&p, nodo *&ant, nodo *&act, nodo *&padre) {
    while (act!=NULL) {
        if (padre->frec >act->frec) {
            ant=act;
            act=act->punt;
        }
    }
}

void insertarOrdenado(nodo *&p, nodo *nuevo) {
    if (p == NULL || nuevo->frec < p->frec) {
        nuevo->punt = p;
        p = nuevo;
        return;
    }

    nodo *act = p;
    while (act->punt != NULL && act->punt->frec <= nuevo->frec) {
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
    if (r==NULL) return;

    if (r->letra != '\0') {
        cout << r->letra << " : " << codigo << endl;
        return;
    }

    recorreArbol(r->izq, codigo + "0");
    recorreArbol(r->der, codigo + "1");
}

void recorre (nodo *p) {
    if (p!=NULL) {
        cout<<p->letra<<"["<<p->frec<<"]"<<"\t";
        recorre(p->punt);
    }
}

int main () {
    string cadena;
    cout<<"Ingrese la cadena en mayusculas:";
    getline (cin, cadena);
    //cout<<"La cadena es: "<<cadena<<endl;

    for ( char letra : cadena ) {
        nodo *ant=NULL;
        nodo *act=piv;
        nodo *ins=NULL;

        if (letra == ' ') continue;

        bool yaExiste=false;
        buscar (piv,ant, act, letra, yaExiste );

        if (!yaExiste) {
            creaNodo (ins, letra, 1, NULL, NULL);
            if (act==piv) {
                piv=ins;
                ins->punt=act;
            }
            else {
                ant->punt=ins;
                ins->punt=act;
            }
        }
        else {
            act->frec++;
        }
    }
    ordena (piv);
    recorre(piv);

    creaArbol(piv);
    cout<<"Los codigos: "<<endl;
    recorreArbol(piv, "");
    return 0;
}