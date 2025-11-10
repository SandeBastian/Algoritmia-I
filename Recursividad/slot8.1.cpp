/*
Crear una funcion recursiva que permita estima la producción de un
producto para los siguientes años, sabiendo que se cumple que:
Año : 2010 2011 2012 2013 ... n
Prod. 450 350 480 (P2010+P2011+P2012)/3 ... (Pn-1+Pn-2+Pn-3)/3
P2010 P2011 P2012 P2013 ... Pn
*/
#include <iostream>
using namespace std;

int produccion(int anio) {
    switch(anio) {
        case 2010: return 450;
        case 2011: return 350;
        case 2012: return 480;
        default: return (produccion(anio-1)+produccion(anio-2)+produccion(anio-3))/3;
    }
}

int main () {
    int a;
    cout<<"Anio: "; cin>>a;
    cout<<"Produccion: "<<produccion(a);
    return 0;
}