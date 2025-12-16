/*
Busqueda, Eliminacion e Insercion
en una lista ordenada respecto al codigo.
Lista ->[111|11.5| ]->[333|8.5| ]->[555|12]->NULL
Operaciones:
Buscar (con respecto al Cod): 222, 333
Eliminar(con respecto al Cod): 333, 444
Insertar(con respecto al Cod): 222, 333
*/
#include <iostream>
using namespace std;

struct nodo {
    int cod;
    float pf;
    nodo *punt;
};

nodo *piv=NULL;

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->cod<<"\t"<<p->pf<<endl;
        recorre(p->punt);
    }
}

void creaNodo (nodo *&p, int cod, float pf) {
    p=new nodo;
    p->cod=cod;
    p->pf=pf;
    p->punt=NULL;
}

void buscarCod(nodo *&p, nodo *&ant, nodo *&act, int cod, bool &yaExiste) {
    while (act!=NULL) {
        if (cod>act->cod) {
            ant=act;
            act=act->punt;
        }
        else {
            if (cod==act->cod) yaExiste=true;
            break;
        }
    }
}

void evaluarNodo(nodo *&p) {
    nodo *act=p;
    nodo *ant=NULL;
    nodo *ins=NULL;
    int cod;
    float pf;
    cout<<"Ingresa Cod: "; cin>>cod;
    cout<<"Ingresa pf: "; cin>>pf;
    bool yaExiste=false;
    buscarCod(p, ant, act, cod, yaExiste);
    if (!yaExiste) {
        creaNodo(ins, cod, pf);
        if (act==p) {
            p=ins;
            ins->punt=act;
        }
        else {
            ant->punt=ins;
            ins->punt=act;
        }
    }
    else {
        cout<<"Ese alumno ya esta registrado"<<endl;
    }
}

void creaLista (nodo *&p) {
    int n;
    cout<<"Ingrese la cantidad de alumnos: "; cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Alumno ["<<i+1<<"]: "<<endl;
        evaluarNodo(p);
    }
}

void eliminar (nodo *&p, int cod) {
    nodo *act=p;
    nodo *ant=NULL;
    bool yaExiste=false;

    buscarCod(p, ant, act, cod, yaExiste);
    if (yaExiste) {
        if (p==act) {
            p=p->punt;
            delete act;
        }
        else {
            ant->punt=act->punt;
            delete act;
        }
    }
    else {
        cout<<"El Alumno no existe"<<endl;
    }
}

int main () {
    creaLista(piv);
    recorre(piv);
    int codEl;
    cout<<"Ingrese el Codigo del alumno que deseas eliminar: "; cin>>codEl;
    eliminar (piv, codEl);
    recorre(piv);
    return 0;
}

