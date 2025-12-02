/*
Busqueda, Eliminacion e Insercion
en una lista ordenada respecto al codigo.
Lista ->[111|11.5| ]->[333|8.5| ]->[555|12]->NULL
Operaciones:
Buscar (con respecto al Cod): 222, 333
Eliminar(con respecto al Cod): 333, 444
Insertar(con respecto al Cod): 222, 333
*/
#include<iostream>
using namespace std;

int codigos[] = {111, 888, 222, 444, 333, 555, 777};
//int codigos[] = {111,   777};

//Nodo
struct Nodo{
    int Cod;
    Nodo *punt;
};

//Funcion que crea el nodo
void Crea_Nodo(Nodo *&p, int Cod){
    p=new(Nodo);
    p->Cod=Cod;
    p->punt=NULL;
}

//Funcion Buscar
//Asume que la lista está ordenada
void Buscar(Nodo *p, Nodo *&ant, Nodo *&act, int Cod, bool &Enlista){
    bool termina=false; //Indica que todavia no ha terminado la busqueda
    Enlista=false; //Indica no esta en la lista
    ant=NULL;
    act=p;
    while(act!=NULL && !termina){
        if(Cod>act->Cod){
            ant=act;
            act=act->punt;
        }
        else{
            termina=true;
            if(Cod==act->Cod){
                Enlista=true;
            }
        }
    }
}

//Funcion Eliminar
void Eliminar(Nodo *&p, int Cod){
    Nodo *ant, *act;
    bool Enlista;
    //llamando a la funcion Buscar
    Buscar(p, ant, act, Cod, Enlista);
    if(Enlista){
        if(p==act){
            p=p->punt;
            delete act;
        }
        else{
            ant->punt=act->punt;
            delete act;
        }
    }
    else{
        cout<<"Codigo no existe..."<<endl;
    }
}

//Funcion Insertar
void Insertar(Nodo *&p, int Cod){
    Nodo *ant, *act, *ins;
    bool Enlista;
    //llamando a la funcion Buscar
    Buscar(p, ant, act, Cod, Enlista);
    if(!Enlista){
        //llamando a Crea Nodo
        Crea_Nodo(ins, Cod);
        //insertar al inicio
        if(p==act){
            p=ins;
            ins->punt=act;
        }
        //si no esta al inicio
        else{
            ant->punt=ins;
            ins->punt=act;
        }
    }
    else{
        cout<<"El Cod ya existe..."<<endl;
    }
}

void Crea_lista(Nodo *&p){
    int Cod, i, n=7;
    p=NULL;//Lista vacia

    for(i=0; i<n;i++){
        Cod = codigos[i];
        Insertar(p, Cod);
    }
}

//Funcion Recorre
void Recorre(Nodo *p){
    while(p!=NULL){
        cout<<p->Cod<<endl;
        p=p->punt;
    }
}


int main(){
    int Cod;

    Nodo *Lista;
    cout<<"Muestra la lista..."<<endl;
    Crea_lista(Lista);
    Recorre(Lista);
    //"Ingresa Cod a eliminar..."
    Cod = 444;
    //Llamando a eliminar
    Eliminar(Lista, Cod);
    cout<<"Muestra la lista..."<<endl;
    Recorre(Lista);

    return 0;
}