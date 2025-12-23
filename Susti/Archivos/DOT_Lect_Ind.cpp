/*
Leer el archivo binario INDICE.DAT y muestra
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int r;
    ifstream ent;

    //Aperturando el arhivo de datos REGISTRO.DAT para lectura
    ent.open("INDICE.DAT");
    if(!ent){
        cout<<"Error de apertura para lectura del archivo REGISTRO.DAT...";
    }
    else{
        while(!ent.eof()){
            if(ent.read((char*)&r, sizeof(int))){
                cout<<r<<endl;
            }
        }
        ent.close();
    }


    return 0;
}