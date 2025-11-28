/*Ejemplo 10:
Ordenamiento de una cola
 */
#include <iostream>
#include<fstream>
using namespace std;

int x[5]={20,30,10,50,40};
//Nodo
struct Nodo{
    int Cod;
    Nodo *punt;
};

//Variable Pila
Nodo *Cola;

//Funcion que crea un Nodo
void Crea_Nodo(Nodo *&p, int Cod){
    p=new(Nodo);
    p->Cod=Cod;
    p->punt=NULL;
}

//Funcion que crea la Cola
void Crea_Cola(Nodo *&p){
    int Cod,i,n=5;
    Nodo *q,*r;
    p=NULL; //Cola vacia
    for(i=0; i<n; i++){
        Cod= x[i];
        //creando la Cola
        if(p==NULL){
            //llamando Crea_Nodo
            Crea_Nodo(p,Cod);
            r=p;
        }
        else{
            //llamando a Crea_Nodo
            Crea_Nodo(q,Cod);
            //Enlazar r y q
            r->punt=q;
            r=q;
        }
    }
}

//Funcion que recorre la Cola
void Recorre(Nodo *p){
    while(p!=NULL){
        cout<<p->Cod<<"\t"<<endl;
        p=p->punt;
    }
}

void Ordena(Nodo *p) {
    Nodo *q1, *q2;
    int auxC;
    q1 = p;
    while(q1!=NULL){
        q2 = q1->punt;
        while(q2!=NULL){
            if(q1->Cod > q2->Cod){
                auxC = q1->Cod;
                q1->Cod = q2->Cod;
                q2->Cod = auxC;
            }
            q2 = q2->punt;
        }
        q1=q1->punt;
    }

}


int main(){
    //llamando a Crea_Cola
    Crea_Cola(Cola);
    cout<<"Antes de ordenar"<<endl;
    //Llamando a Recorre
    Recorre(Cola);

    cout<<"Despues de ordenar"<<endl;
    Ordena(Cola);
    Recorre(Cola);
    return 0;
}
