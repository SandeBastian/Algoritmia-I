/*
Ordenar el archivo "REGISTRO.DAT" en forma creciente respecto al
promedio final. Hacerlo sin modificar el orden en el archivo
“REGISTRO.DAT”.

antes de ordenar en forma creciente
REGISTRO.DAT                            INDICE.DAT

Codigo  Nombre              Prom final
222     ALVA TORRES INES    14.7          0
111     CAMPOS RUIZ JUAN    13.5          1
333     BARRIOS ALVA LUIS   08.7          2

despues de ordenar en forma creciente
REGISTRO.DAT INDICE.DAT
Codigo  Nombre              Prom final
333     BARRIOS ALVA LUIS   08.7        2
111     CAMPOS RUIZ JUAN    13.5        1
222     ALVA TORRES INES    14.7        0
*/
#include <iostream>
#include <fstream>
using namespace std;

typedef char cadena[51];

struct reg {
    int cod;
    cadena nomb;
    float pf;
};

int main () {
    ifstream ente;

    int n;

    int n1, n2;

    reg r1, r2;

    ente.open("REGISTRO1.DAT", ios::binary);
    if (!ente) {
        cout<<"Error al encontrar el archivo REGISTRO.DAT"<<endl;
    }
    else {
        ente.seekg(0,ente.end);
        n = ente.tellg()/sizeof(reg);
        ente.seekg(0,ente.beg);

        fstream indi;

        indi.open("INDICE.DAT", ios::out|ios::binary);

        if (!indi) {
            cout<<"Error al crear el archivo Ind"<<endl;
        }
        else {
            for (int i=0; i<n; i++) {
                indi.write((char*)&i, sizeof(i));
            }
            indi.close();
        }

        indi.open("INDICE.DAT", ios::in|ios::out|ios::binary);
        if (!indi) {
            cout<<"Error al encontrar el archivo Ind"<<endl;
        }
        else {
            for (int i=0; i<n-1; i++) {
                for (int j=i+1; j<n; j++ ) {
                    //Ubica Indice en funcion a "i" en Indice.Dat
                    indi.seekg(i*sizeof(int)); //Ubicate en i*byte(int)
                    indi.read((char*)&n1, sizeof(i)); //Copia los primeros i*byte(int) en n1

                    //Ubica Indice en funcion a "j" en Indice.Dat
                    indi.seekg(j*sizeof(int)); //Ubicate en j*byte(int)
                    indi.read((char*)&n2, sizeof(i)); //Copia los primeros j*byte(int) en n2

                    //Ubica Reg #n1 ahora si en funcion a Indice.Dat
                    ente.seekg(n1*sizeof(reg)); //Ubicate en n1*byte(reg)
                    ente.read((char*)&r1, sizeof(reg)); //Copia los primeros r1*byte(reg) en r1

                    //Ubica Reg #n2 ahora si en funcion a Indice.Dat
                    ente.seekg(n2*sizeof(reg)); //Ubicate en n2*byte(reg)
                    ente.read((char*)&r2, sizeof(reg)); //Copia los primeros r2*byte(reg) en r2

                    //Una vez ubicado en los reg que quiero comparar
                    if (r1.pf>r2.pf) { //Si pf[n1] es mayor que pf[n2] -> intercambio

                        //En Indice.dat ubicate en i*byte(int) y copia Indice[n2]
                        indi.seekg(i*sizeof(int));
                        indi.write((char*)&n2, sizeof(int));

                        //En Indice.dat ubicate en j*byte(int) y copia Indice[n1]
                        indi.seekg(j*sizeof(int));
                        indi.write((char*)&n1, sizeof(int));

                        // Indice[i]=n1*byte   Indice[j]=n2*byte
                        // aux=Indice[i];
                        // Indice[i]=Indice[j];
                        // Indice[j]=aux;
                    }
                }
            }
            indi.close();
            ente.close();
        }
    }
    cout<<"Proceso terminado "<<endl;
    return 0;
}