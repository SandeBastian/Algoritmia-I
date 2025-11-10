/*
Para un grupo de n empleados, se desea almacenar por cada uno:
Código (entero de 3 digitos), sexo (F o M) y sueldo (real positivo). Luego
presentar la información ordenada en forma decreciente respecto al sueldo
*/
#include <iostream>
using namespace std;
struct REgente {
    int cod;
    char sex;
    float sueldo;
};

void IngresasDatos(int n, REgente empl[]) {
    char sexo;
    for (int i=0; i<n; i++) {
        cout<<"Codigo de Empleado ["<<i+1<<"]: ";
        cin>>empl[i].cod;
        cout<<"Sexo de Empleado ["<<i+1<<"]: ";
        cin>>sexo;
        empl[i].sex=toupper(sexo);
        cout<<"Sueldo de Empleado ["<<i+1<<"]: ";
        cin>>empl[i].sueldo;
    }
}

void ordenarDatos(int n, REgente empl[]) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (empl[i].sueldo<empl[j].sueldo) {
                REgente temp = empl[i];
                empl[i] = empl[j];
                empl[j] = temp;
            }
        }
    }
}

void presentarDatos(int n, REgente empl[]) {
    cout<<"\nCodigo\tSexo\tSueldo"<<endl;
    for (int i=0; i<n; i++) {
        cout<<empl[i].cod<<"\t"<<empl[i].sex<<"\t"<<empl[i].sueldo<<endl;
    }
}

int main () {
    int n;
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;
    REgente empl[n] ;
    IngresasDatos(n, empl);
    ordenarDatos(n, empl);
    presentarDatos(n, empl);
    return 0;
}