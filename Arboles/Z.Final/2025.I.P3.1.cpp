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
#include <string>
using namespace std;

struct Nodo {
    char simbolo;      // '\0' si es nodo interno
    int freq;
    Nodo* izq;
    Nodo* der;
};

//-----------------------------------
// Insertar nodo ordenado por frecuencia
//-----------------------------------
void insertarOrdenado(Nodo* a[], int& n, Nodo* nuevo) {
    int i = n - 1;
    while (i >= 0 && a[i]->freq > nuevo->freq) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = nuevo;
    n++;
}

//-----------------------------------
// Buscar símbolo existente
//-----------------------------------
int buscar(Nodo* a[], int n, char c) {
    for (int i = 0; i < n; i++)
        if (a[i]->simbolo == c)
            return i;
    return -1;
}

//-----------------------------------
// Generar códigos Huffman
//-----------------------------------
void generarCodigos(Nodo* r, string codigo) {
    if (!r) return;

    if (r->simbolo != '\0') {
        cout << r->simbolo << " : " << codigo << endl;
        return;
    }

    generarCodigos(r->izq, codigo + "0");
    generarCodigos(r->der, codigo + "1");
}

//-----------------------------------
// MAIN
//-----------------------------------
int main() {
    string texto;
    cout << "Ingrese texto en MAYUSCULAS: ";
    getline(cin, texto);

    Nodo* nodos[256];
    int n = 0;

    // Contar y mantener ordenado mientras se itera
    for (char c : texto) {
        if (c == ' ') continue;

        int pos = buscar(nodos, n, c);
        if (pos != -1) {
            nodos[pos]->freq++;

            // Reordenar hacia la derecha si es necesario
            Nodo* temp = nodos[pos];
            int i = pos;
            while (i + 1 < n && nodos[i + 1]->freq < temp->freq) {
                nodos[i] = nodos[i + 1];
                i++;
            }
            nodos[i] = temp;
        } else {
            Nodo* nuevo = new Nodo{c, 1, nullptr, nullptr};
            insertarOrdenado(nodos, n, nuevo);
        }
    }

    // Construcción del árbol de Huffman
    while (n > 1) {
        Nodo* izq = nodos[0];
        Nodo* der = nodos[1];

        // Regla: símbolo simple a la izquierda
        if (izq->simbolo == '\0' && der->simbolo != '\0') {
            Nodo* aux = izq;
            izq = der;
            der = aux;
        }

        Nodo* padre = new Nodo{'\0', izq->freq + der->freq, izq, der};

        // Eliminar los dos primeros
        for (int i = 2; i < n; i++)
            nodos[i - 2] = nodos[i];
        n -= 2;

        insertarOrdenado(nodos, n, padre);
    }

    cout << "\nCODIGOS:\n";
    generarCodigos(nodos[0], "");

    return 0;
}
