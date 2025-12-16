#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct nodoInt {
    int dato;
    nodoInt *sig;
};

void pushEnt(nodoInt *&p, int x) {
    nodoInt *nuevo = new nodoInt;
    nuevo->dato = x;
    nuevo->sig = p;
    p = nuevo;
}

int popEnt(nodoInt *&p) {
    int x = p->dato;
    nodoInt *aux = p;
    p = p->sig;
    delete aux;
    return x;
}

struct nodoStr {
    char dato[200];
    nodoStr *sig;
};

void pushA(nodoStr *&p, const char *s) {
    nodoStr *nuevo = new nodoStr;
    strcpy(nuevo->dato, s);
    nuevo->sig = p;
    p = nuevo;
}

void popB(nodoStr *&p, char *s) {
    strcpy(s, p->dato);
    nodoStr *aux = p;
    p=p->sig;
    delete aux;
}

void decodifica(char *cad, char *resultado) {
    nodoInt *pNum = NULL;
    nodoStr *pStr = NULL;

    char actual[200] = "";
    int num = 0;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] >= '0' && cad[i] <= '9') {
            num = num * 10 + (cad[i] - '0');
        }
        else if(cad[i] == '[') {
            pushEnt(pNum, num);
            pushA(pStr, actual);
            num = 0;
            actual[0] = '\0';
        }
        else if(cad[i] == ']') {
            int rep = popEnt(pNum);
            char previo[200];
            popB(pStr, previo);

            char temp[200] = "";
            for (int k = 0; k < rep; k++)
                strcat(temp, actual);

            strcpy(actual, previo);
            strcat(actual, temp);
        }
        else {
            int p = strlen(actual);
            actual[p] = cad[i];
            actual[p + 1] = '\0';
        }
    }
    strcpy(resultado, actual);
}

int main() {
    ifstream f("IMPUT.TXT");
    if (!f) {
        cout<<"Error al encontrar el archivo"<<endl;
        return 0;
    }

    char linea[200];
    char salida[200];

    while(f>>linea) {
        decodifica(linea, salida);
        cout<<salida<<endl;
    }
    f.close();
    return 0;
}
