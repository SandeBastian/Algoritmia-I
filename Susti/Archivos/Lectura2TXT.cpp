/*
Se tiene los siguiente archivos de texto
    DATOS.TXT
codigo nombre
111 PEREZ-RUIZ
222 ALVA-CASTRO
333 CAMPOS-TORRES

    CURSOS.TXT
codigo curso nota
111 FI-205 10
222 FB-101 13
333 FB-111 6
111 FI-205 11

Se pide presentar un reporte que muestre los usuarios y los
cursos que llevan, un ejemplo de salida sera el siguiente:
111 PEREZ-RUIZ
Lista de cursos:
FI-205 10
FI-205 11
222 ALVA-CASTRO
Lista de cursos:
FB-101 13
333 CAMPOS-TORRES
Lista de cursos:
FB-111 6
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef char cadena[51];
int main () {
    ifstream reg1;
    reg1.open("DATOS1.0.txt");
    ifstream reg2;


    int cod1;
    cadena nomb;

    if (!reg1) {
        cout<<"Error al encontrar el archivo"<<endl;
    }else {
        while (reg1>>cod1>>nomb) {
            cout<<"\n"<<cod1<<"\t"<<nomb<<endl;
            cout<<"Lista de cursos: "<<endl;

            //ifstream reg2;
            reg2.open("CURSOS1.0.txt");

            int cod2, nota;
            cadena curso;
            if (!reg2) {
                cout<<"Error al encontrar el archivo"<<endl;
            }else {
                while (reg2>>cod2>>curso>>nota) {
                    if (cod1==cod2) {
                        cout<<curso<<"\t"<<nota<<endl;
                    }
                }
                reg2.close();
            }
        }
        reg1.close();
    }
    return 0;
}