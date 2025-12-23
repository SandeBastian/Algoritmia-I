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

Por ejemplo si el texto es “LA PILA AAA”
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
using namespace std;

struct nodo {
    char letra;
    int frec;
    nodo *izq;
    nodo *der;
};

typedef char cadena[101];

int buscar (nodo *raiz[], int c, int n ) {
    for (int i=0; i<n; i++) {
        if (raiz[i]->letra == c) return i;
    }
    return -1;
}

void insertarOrdenado (nodo *raiz [], nodo *nuevo, int &n) {
     //pos inicial i=n-1
    int i;
    for (i=n-1; i>=0; i--) {
        if (raiz[i]->frec > nuevo->frec) {
            raiz[i+1] = raiz[i];
        }
        else {
            break;
        }
    }
    raiz[i+1]=nuevo;
    n++;
}

void presentaCodigos (nodo *r, string cod) {
    if (r==NULL) return ;

    if (r->letra != '\0') {
        cout<<r->letra<<": "<<cod<<endl;
        return;
    }
    presentaCodigos(r->izq, cod + '0');
    presentaCodigos(r->der, cod + '1');
}

int main () {
    string texto;
    cout << "Ingrese texto en MAYUSCULAS: ";
    getline(cin, texto);

    nodo *raiz[100];
    int n = 0;

    for ( char c: texto ) {
        if (c==' ') continue;

        int pos = buscar (raiz, c, n);

        if (pos==-1) {
            nodo *nuevo = new nodo;
            nuevo->letra = c;
            nuevo->frec = 1;
            nuevo->izq = NULL;
            nuevo->der = NULL;

            insertarOrdenado (raiz, nuevo, n);
        }
        else {
            raiz[pos]->frec++;

            //Reorden hacia la derecha
            nodo *temp=raiz[pos];
            int i=pos;

            for (i=pos; i<n; i++) {
                if (raiz[i+1]->frec < temp->frec) {
                    raiz[i]=raiz[i+1];
                }
                else {
                    break;
                }
            }
            raiz[i]=temp;
        }
    }

    while (n>1) {
        nodo *izq = raiz[0];
        nodo *der = raiz [1];

        if (izq->letra == '\0' && der->letra != '\0') {
            nodo *aux = izq;
            izq = der;
            der = aux;
        }
        nodo *padre = new nodo;
        padre->letra='\0';
        padre->frec=izq->frec+der->frec;
        padre->izq=izq;
        padre->der=der;

        for (int i=2; i<n; i++) {
            raiz [i-2]=raiz[i];
        }
        n=n-2;
        insertarOrdenado(raiz, padre, n);
    }
    cout<<"Codigos del arbol: "<<endl;
    presentaCodigos(raiz[0], "");
    return 0;
}