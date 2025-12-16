/*
Muestra el archivo REGISTRO.DAT utilizando el
archivo de indice INDICE.DAT
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

int main() {
    int i;
    ifstream ind, ent;
    reg r;
    ind.open("INDICE.DAT");
    if (!ind) {
        cout << "Error al abrir el archivo INDICE.DAT" << endl;
    }else{
        ent.open("REGISTRO1.DAT", ios::binary);
        if(!ent) {
            cout << "Error al abrir el archivo REGISTRO.DAT" << endl;
        }else{
            while(ind){
                if(ind.read((char*)&i, sizeof(int))){
                    ent.seekg(i*sizeof(reg));
                    ent.read((char*)&r, sizeof(reg));
                    cout << r.cod << "\t" << r.nomb << "\t" << r.pf << endl;
                }
            }
            ent.close();
        }
        ind.close();
    }

    return 0;
}