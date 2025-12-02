/*
Crea una lista de notas de manera que se asegura que ingresan ordenadas. Luego se ingresa
una nota dentro de la lista de manera que no se altere el orden
*/
#include <iostream>
using namespace std;

struct nodo {
    float pf;
    nodo *punt;
};

void creaNodo(nodo *&p) {
    if (p==NULL) {
        float prom; //Entonces si pones int no hace conversion
        cout<<"Prom: "; cin>>prom;
        p=new nodo;
        p->pf=prom;
        p->punt=NULL;
    }
    else {
        creaNodo(p->punt);
    }
}

void recorre (nodo *&p) {
    if (p!=NULL) {
        cout<<p->pf<<endl;
        recorre(p->punt);
    }
}


int main () {
    int n;
    cout<<"Ingresa la cantidad de elementos: ";
    cin>>n;
    //float m[n];
    //for (int i=0; i<n; i++) {
    //cout<<"m["<<i+1<<"]: "; cin>>m[i];
    nodo *piv=NULL;
    for (int i=0; i<n; i++) {
        cout<<"Alumno ["<<i+1<<"]: "<<endl;
        creaNodo(piv);
    }
    recorre(piv);
    float newNum;
    cout<<"Ingrese el dato que desea insertar: "; cin>>newNum;
    //Realizar busqueda
    nodo *ant, *act, *ins;
    ant=NULL;
    act=piv;
    while (act!=NULL && newNum>act->pf) {
        ant=act;
        act=act->punt;
    }
    //Creamos el nuevo nodo con el nuevo codigo
    ins=new nodo;
    ins->pf=newNum;
    ins->punt=NULL;

    //procedemos a insertar el nuevo nodo
    if (act==piv) {
        piv=ins; //Caso en que act nunca se mueve y el nuevo nodo se inserta al inicio
        ins->punt=act;  //Se puede notar que no interviene puntero ant
    }
    else {
        ant->punt=ins;
        ins->punt=act;
    }
    recorre(piv);

    //Elmiminacion de 1 elemento
    float codEl;
    cout<<"Ingrese el codigo que desea eliminar: "; cin>>codEl;
    ant=NULL;
    act=piv;
    bool yaEsta=false;
    while (act!=NULL) {
        if (codEl!=act->pf) {
            ant=act;
            act=act->punt;
        }
        else {
            yaEsta=true;
            break;
        }
    }
    if (yaEsta) {
        if (piv==act) {
            piv=piv->punt;
            delete act;
        }
        else {
            ant->punt=act->punt;
            delete act;
        }
    }
    else {
        cout<<"Ese promedio no existe"<<endl;
    }
    return 0;
}