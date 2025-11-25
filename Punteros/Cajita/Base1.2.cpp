/*
Creacion y recorrido de una PILA (LIFO) de estudiantes que tengan datos
del Codigo y Promedio final
Codigo      Promedio Final
111         13.5
222         08.7
333         14.5
*/
#include <iostream>
using namespace std;

//Creas la estructura de los nodos
struct Nodo {
    int cod;
    float pt;
    Nodo *flecha;
};

//Declaras el nodo base
Nodo *Reg;

//Asignas valores al nodo y haces que apunten a NULL
void crea_nodo(Nodo *&p) {
    int codigo;
    float puntaje;
    cout<<"Codigo: "; cin>>codigo;
    cout<<"Puntaje: "; cin>>puntaje;
    p=new(Nodo);
    p->cod=codigo;
    p->pt=puntaje;
    p->flecha=NULL;
}

//Inicias la creacion de la lista, Creas un nodo auxiliar, haces que el nodo base apunte a NULL y comienzas a anidar
void crea_lista(Nodo *&x) {
    int n;
    Nodo *aux;
    x=NULL;
    cout<<"Ingrese la cantidad de Datos: "; cin>>n;
    for(int i=0;i<n;i++) {
        cout<<"Datos ["<<i+1<<"]:"<<endl;
        if (x==NULL) {
            crea_nodo(x);
        }else {
            crea_nodo(aux); //Creas el nuevo nodo
            aux->flecha=x;      //haces que apunte al nodo base o la lista (si es que ya hay varios nodos)
            x=aux;              //Haces que el nodo base o tal cual la lista apunte a td lo creado
        }
    }
}

void recorre( Nodo *&x) {
    cout<<"Codigo\tPuntaje"<<endl;
    while(x!=NULL) {
        cout<<x->cod<<"\t"<<x->pt<<endl;
        x=x->flecha;
    }

}

int main () {
    crea_lista(Reg);
    recorre(Reg);
    return 0;
}