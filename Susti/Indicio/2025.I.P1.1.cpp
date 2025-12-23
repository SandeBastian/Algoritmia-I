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
*/
//creacion y modificacion ofstream ||| solo lectura ifstream
#include <iostream>
#include <fstream>
using namespace std;

struct reg {
    int cod;
    int nota;
};

int main () {
    reg r;
    ifstream f;
    f.open ("DESAPROBADOS1.DAT", ios::binary);
    if (!f) {
        cout<<"Error al leer desprobados1.DAT"<<endl;
    }
    else {
        while (f.read((char*)&r,sizeof(reg))) {
            cout<<r.cod<<"\t"<<r.nota<<endl;
        }
        f.close();
    }
    cout<<"Proceso terminado"<<endl;
    return 0;
}