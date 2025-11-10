/*
Crear un programa que permite leer un numero entero de m cifras (m>5) y luego lo modifique eliminando
sus digitos de posicion par (leyendo el numero de derecha a izquierda).
Ejemplo:
Numero: 476592
Numero mod: 752
*/
//NO PUDISTE HACERLO CON ARREGLOS DE MANERA RAPIDA Y EFECTIVA PORQUE NO ES EFECTIVA HACERLO CON ARREGLOS
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Ingrese un número: ";
    cin >> num;

    int digitos[20];  // capacidad máxima (segura)
    int cont = 0;

    while (num > 0) {
        digitos[cont] = num % 10;  // obtiene el último dígito
        num /= 10;                 // elimina el último dígito
        cont++;
    }

    // mostrar los dígitos en orden correcto
    cout << "Cifras apiladas: ";
    for (int i = cont - 1; i >= 0; i--) {
        cout << digitos[i] << " ";
    }

    return 0;
}
