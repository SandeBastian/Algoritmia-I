/*
Busqueda, Eliminacion e Insercion
en una lista ordenada respecto al codigo.
Lista ->[111|11.5| ]->[333|8.5| ]->[555|12]->NULL
Operaciones:
Buscar (con respecto al Cod): 222, 333
Eliminar(con respecto al Cod): 333, 444
Insertar(con respecto al Cod): 222, 333
*/
#include <algorithm>
#include <iostream>
using namespace std;

struct nodo{
    int cod;
    float pf;
    nodo *punt;
};

nodo *piv;

void creaNodo (nodo *&p, int cod, float pf);

void creaLista (nodo *&p);

void evaluaNodo (nodo *&p);

void buscar (nodo *&p, nodo *&ant, nodo *&act, int cod, bool &flag);

void eliminar(nodo *&p, int cod);

void recorre (nodo *&p);


int main () {
    creaLista(piv);
    recorre(piv);
    int codEl;
    cout<<"\nIngrese el Codigo que desea eliminar: "; cin>>codEl;
    eliminar(piv, codEl);
    recorre(piv);
    return 0;
}

void creaNodo (nodo *&p, int cod, float pf) {
    p=new nodo;
    p->cod=cod;
    p->pf=pf;
    p->punt=NULL;
}

void creaLista(nodo *&p) {
    int n;
    p=NULL;
    cout<<"Ingrese la cantidad de numeros: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Alumno ["<<i+1<<"]: "<<endl;
        evaluaNodo(p);
    }
}

void buscar (nodo *&p, nodo *&ant, nodo *&act, int cod, bool &yaEsta) {
    while (act!=NULL) {
        if (cod>act->cod) {
            ant=act;
            act=act->punt;
        }
        else {
            if (cod==act->cod) yaEsta=true;
            break;
        }
    }
}

void evaluaNodo(nodo *&p) {
    int cod;
    cout<<"Ingresa el codigo: "; cin>>cod;

    float pf;
    cout<<"Ingrese el prom. final: "; cin>>pf;

    nodo *ant, *act, *ins;
    ant=NULL;
    act=p;
    ins=NULL;

    bool yaEsta;

    buscar (p, ant, act, cod, yaEsta);

    if (!yaEsta) {

        creaNodo(ins, cod, pf);

        if (p==act) { //si se inserta al inicio participa pivote y no entra el ant
            p=ins;
            ins->punt=act;
        }
        else {   //si esta en medio participa ant act y ya no participa el pivote
            ant->punt=ins;
            ins->punt=act;
        }
    }
    else {
        cout<<"El numero ya esta en la lista"<<endl;
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        recorre(p->punt);
    }
}

void eliminar(nodo *&p, int cod){
    nodo *ant, *act;
    ant=NULL;
    act=p;
    bool yaEsta;
    //llamando a la funcion Buscar
    buscar(p, ant, act, cod, yaEsta);
    if(yaEsta){
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