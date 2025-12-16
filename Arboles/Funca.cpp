#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char usuario[5];
    char clave[7];
    char total[11];
    char archivo[] = "1111abcXYZ";

    // Entrada
    cout << "Usuario (4): ";
    cin >> usuario;

    cout << "Clave (6): ";
    cin >> clave;

    // 1) strcpy → copiar
    strcpy(total, usuario);

    // 2) strcat → concatenar
    strcat(total, clave);

    cout << "\nCadena concatenada: " << total << endl;

    // 3) strlen → longitud
    cout << "Longitud: " << strlen(total) << endl;

    // 4) strcmp → comparar
    if (strcmp(total, archivo) == 0) {
        cout << "Usuario y clave CORRECTOS\n";
    } else {
        cout << "Usuario o clave INCORRECTOS\n";
    }

    return 0;
}
