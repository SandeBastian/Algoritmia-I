/*Ejemplo 2
Se tiene (ya existe) el archivo binario
		PEDIDOS.DAT
Codigo	Numero unidades
222		150
111		 80
444		100
222		 50
333		200
444		200

Mediante un arbol binario, presentar los pedidos ordenado en forma creciente
respecto al codigo y totalizados, esto es:
Codigo	Numero de unidades
111		 80
222		200
333		200
444		300

 Se debe guardar esta salida al archivo de texto
        PEDIDOS_RESUMEN.TXT
*/

#include <iostream>
#include <fstream>

using namespace std;
//Reg
struct Nodo{
    //Campos de datos
    int Cod;
    int Uni;
    //Campos punteros
    Nodo *pI;
    Nodo *pD;
};

//Reg
struct Reg{
    //Campos de datos
    int Cod;
    int Uni;
};


//Funcion Crea_Nodo
void Crea_Nodo(Nodo *&p, int Cod, int Uni){
    if(p==NULL){
        p=new(Nodo);
        p->Cod=Cod;
        p->Uni=Uni;
        p->pI=NULL;
        p->pD=NULL;
    }
    else{
        if(Cod>p->Cod){
            Crea_Nodo(p->pD, Cod, Uni);
        }
        else{
            if(Cod==p->Cod){
                p->Uni=p->Uni+Uni;
            }
            else{
                Crea_Nodo(p->pI, Cod, Uni);
            }
        }
    }
}

//Funcion que Recorre en orden creciente respecto al codigo
void Recorre_IRD(Nodo *&p, ostream &out){ // salida genérica
    if(p!=NULL){
        Recorre_IRD(p->pI, out);
        out<<p->Cod<<"\t"<<p->Uni<<endl;
        Recorre_IRD(p->pD, out);
    }
}

//Funcion que crea el arbol
void Crea_arbol(Nodo *&p){
    ifstream ent;
    Reg r;
    p=NULL;
    //Aperturando el archivo de texto
    ent.open("PEDIDOS.DAT");
    if(!ent){
        cout<<"Error de Apertura del archivo...";
    }
    else{
        while(!ent.eof()){
            if(ent.read((char*)&r, sizeof(r))){
                Crea_Nodo(p, r.Cod, r.Uni);
            }
        }
        ent.close();
    }
}

//Funcion principal
int main(){
    Nodo *Raiz;
    //llamando a crea arbol
    Crea_arbol(Raiz);
    //Recorrido en orden

    ofstream sal("PEDIDOS_RESUMEN.TXT");       // archivo resultado
    if (!sal) {
        cerr << "No se pudo crear PEDIDOS_RESUMEN.TXT\n";
        return 1;
    }else{
        //salida en archivo
        cout<<"salida en archivo"<<endl;
        Recorre_IRD(Raiz, sal);
        sal.close();
    }

    cout<<"Presentacion"<<endl;
    Recorre_IRD(Raiz, cout);
    return 0;
}

