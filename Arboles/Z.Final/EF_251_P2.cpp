#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;
int raiz(int x) {
    int i = 1;
    while (i * i < x) i++;
    if (i * i == x) return i;
    else return 0;
}
int main() {
    srand(time(NULL));
    int n;
    cout << "Ingrese orden de la matriz: ";
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) a[i][j] = 10 + rand() % 90, cout << a[i][j] << " ";
        cout << endl;
    }
    int sumaexternos = 0, sumainternos = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (n / 2 < i + j && i + j < n / 2 + n - 1 && -(n / 2) < j - i && j - i < n / 2 &&
                a[i][j] % 2 == 1)
                sumainternos += a[i][j] * a[i][j];
            if (n / 2 > i + j || i + j > n / 2 + n - 1 || -(n / 2) > j - i || j - i > n / 2)
                sumaexternos += raiz(a[i][j]);
        }
    cout << "La suma de raices de los externos es: " << sumaexternos << endl;
    cout << "La suma de cuadrados de los internos es: " << sumainternos << endl;
    return 0;
}