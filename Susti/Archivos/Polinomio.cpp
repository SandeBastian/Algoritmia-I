/*Ejemplo 3:
Crear un programa que permita recibir los coeficientes de dos polinomios de grados
m y n respectivamente. Luego nos presenta los coeficientes del producto de dichos
polinomios.
Nota: Debe emplear listas dinamicas
Ejemplo:
P(x)= 3x^3-2x =3x^3+0x^2-2x+0
Q(x)= 2x^2+x+3
P(x)= 6x^5+3x^4+5x^3-2x^2-6x
*/
#include <iostream>
using namespace std;

struct nodo {
    float coef;
    int grado;
    nodo *punt;
};

nodo *piv1=NULL;
nodo *piv2=NULL;

nodo *prod=NULL;

void creaNodo (nodo *&p, int grado, float coef) {
    p=new nodo;
    p->grado=grado;
    p->coef=coef;
    p->punt=NULL;
}

void buscar (nodo *&p, nodo *&ant, nodo *&act, int grado, bool &yaExiste) {
    while (act!=NULL) {
        if (grado<act->grado) {
            ant=act;
            act=act->punt;
        }
        else {
            if (grado==act->grado) yaExiste=true;
            break;
        }
    }
}

void Insertar (nodo *&p, int grado, float coef) {
    nodo *act=p;
    nodo *ant=NULL;
    nodo *ins=NULL;

    bool yaExiste=false;

    buscar(p, ant, act, grado, yaExiste);

    if (!yaExiste) {
        creaNodo (ins, grado, coef);
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
        act->coef=act->coef+coef;
    }
}

void creaLista (nodo *&p) {
    int grado;
    float coef;
    do {
        cout<<"Ingrese el grado del polinomio: ";
        cin>>grado;
    }while (grado<0);

    while (!(grado<0)) {
        cout<<"Ingrese el coeficiente del grado ["<<grado<<"]: ";
        cin>>coef;
        if (coef!=0) {
            Insertar (p, grado, coef);
        }
        grado--;
    }
}

void Producto(nodo *&prod, nodo *piv1, nodo *piv2){
    int grado;
    float coef;
    nodo *q;

    while(piv1!=NULL){
        q=piv2;
        while(q!=NULL){
            grado=piv1->grado+q->grado;
            coef=(piv1->coef)*(q->coef);
            Insertar(prod,grado,coef);
            q=q->punt;
        }
        piv1=piv1->punt;
    }
}

void recorre (nodo *p) {
    bool primero=true;
    cout<<endl;
    while (p!=NULL) {
        if (primero) {
            cout<<p->coef<<"x^"<<p->grado;
            primero=false;
        }
        else {
            cout<<"+"<<p->coef<<"x^"<<p->grado;
        }
        p=p->punt;
    }
    cout<<endl;
}

int main () {
    cout<<"Polinomio P(x):"<<endl;
    creaLista (piv1);
    recorre (piv1);
    cout<<"Polinomio Q(x):"<<endl;
    creaLista (piv2);
    recorre (piv2);
    cout<<"Producto de polinomios: "<<endl;
    Producto(prod, piv1, piv2);
    recorre (prod);
    return 0;
}