/*
Diseñe un programa que solicite un usuario y una clave y llame a un subprograma valida() que recibe
el usuario y la clave y verifica en un archivo de texto “CLAVE.TXT” si son correctos. Si el usuario y
la clave son correctos, el programa debe llamar a una función notas() que solicita el código (entero
de 3 cifras, asuma que todos los códigos son diferentes) y la nota (entero: 0–20) de “N” estudiantes
(1<N < 10). Con los datos de los estudiantes construya un árbol binario y muéstrelos en consola
ordenados por código (recorrido “in-order”). Luego guarde en un archivo físico
“DESAPROBADOS.DAT” aquellos alumnos que han sido desaprobados (nota menor a 10).
Tome en cuenta que cada línea del archivo de texto CLAVE.TXT contiene 2 datos concatenados
(Exactamente 10 caracteres sin espacios): usuario (cadena de 4 caracteres) y clave (cadena de 6
caracteres), como se muestra en el ejemplo:
Entrada
111 8
444 15
888 16
333 9
777 11
666 8
555 7
222 12

Salida:
111 8
222 12
333 9
444 15
555 7
666 8
777 11
888 16

desaprob:
111 8
333 9
555 7
666 8
*/
//creacion y modificacion ofstream ||| solo lectura ifstream
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef char cadena [11];

struct nodo {
    int cod;
    int nota;
    nodo *pI;
    nodo *pD;
};

struct reg {
    int cod;
    int nota;
};

nodo *piv=NULL;

bool valida (cadena final) {
    cadena clave; //cadena clave;
    ifstream f;
    f.open("CLAVE1.TXT");
    if (!f) {
        cout<<"Error al encontrar CLAVE1.TXT"<< endl;
    }
    else {
        while (f>>clave) {
            if (strcmp(final, clave)==0) {
                return true;
            }
        }
        f.close();
    }
    return false;
}


void creaNodo (nodo *&p, int cod, int nota) {
    if (p==NULL) {
        p=new nodo;
        p->cod = cod;
        p->nota = nota;
        p->pI = NULL;
        p->pD = NULL;
    }else {
        if (cod>p->cod) creaNodo(p->pD,cod,nota);
        else creaNodo(p->pI,cod,nota);
    }
}

void notas (nodo *&p) {
    int n;
    int cod;
    int nota;
    cout<<"Ingrese la cantidad de estudiantes (1<n<10): ";
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout<<"Ingrese el codigo["<<i+1<<"]: ";
        cin>>cod;
        cout<<"Ingrese la nota["<<i+1<<"]: ";
        cin>>nota;
        creaNodo(p, cod, nota);
    }
}

void recorreRID (nodo *p, ofstream &f) {
    if (p!=NULL) {
        reg r;
        recorreRID(p->pI, f);
        cout<<p->cod<<"\t"<<p->nota<<endl;
        if (p->nota<10) {
            r.cod=p->cod;
            r.nota=p->nota;
            f.write((char*)&r, sizeof(reg));
        }
        recorreRID(p->pD, f);
    }
}


int main () {
    cadena user;
    cadena pass;
    cadena final;
    cout<<"Ingrese el usuario [4 digitos]: ";
    cin>>user;
    cout<<"Ingrese la contrasenia [6 gigitos]: ";
    cin>>pass;

    strcpy(final,user);

    strcat(final, pass);
    int n;
    if (valida(final)) {
        notas (piv);
        ofstream bin;
        bin.open("DESAPROBADOS1.DAT", ios::binary);
        if (!bin) {
            cout<<"Error al encontrar DESAPROBADOS.DAT"<<endl;
        }else {
            cout<<"Arbol Ordenado:"<<endl;
            cout<<"Cod\tNota"<<endl;
            recorreRID(piv, bin);
            bin.close();
        }
    }else {
        cout<<"Usuario y Contraseñas incorretas"<<endl;
    }
    return 0;
}