#include <iostream>
using namespace std;
string codigo[26];
struct nod {
    char c;
    int frec;
    nod *l;
    nod *r;
};
nod *crearnodo(char c, int frec) {
    nod *u = new nod;
    u->c = c;
    u->frec = frec;
    u->l = u->r = NULL;
    return u;
}
nod *unir(nod *u, nod *v) {
    nod *p = crearnodo('?', u->frec + v->frec);
    p->l = u;
    p->r = v;
    return p;
}
void contarfrecuencias(nod *hojas[26], int &n, char a[200]) {
    for (char c = 'A'; c <= 'Z'; c++) {
        int frec = 0;
        for (int i = 0; a[i] != '\0'; i++)
            if (c == a[i]) frec++;
        if (frec != 0) hojas[n] = crearnodo(c, frec), n++;
    }
}
void ordenar(nod *hojas[26], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (hojas[j]->frec > hojas[j + 1]->frec) {
                nod *aux = hojas[j];
                hojas[j] = hojas[j + 1];
                hojas[j + 1] = aux;
            }
}
void crearcodigo(nod *root, string s) {
    if (root->l == NULL && root->r == NULL) {
        codigo[root->c - 'A'] = s;
        return;
    }
    crearcodigo(root->l, s + '1');
    crearcodigo(root->r, s + '0');
}
int main() {
    char a[200];
    cout << "Ingrese cadena: ";
    cin.getline(a, 200);
    nod *hojas[26];
    int n = 0;
    contarfrecuencias(hojas, n, a);
    ordenar(hojas, n);
    if (n == 1) codigo[hojas[0]->c - 'A'] = "1";
    if (n >= 2) {
        while (n >= 2) {
            nod *u = unir(hojas[0], hojas[1]); // unido
            hojas[1] = u;
            for (int i = 0; i < n - 1; i++) hojas[i] = hojas[i + 1];
            n--;
            ordenar(hojas, n);
        }
        nod *root = hojas[0];
        crearcodigo(root, "");
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        int id = c - 'A';
        if (codigo[id] != "") cout << c << ": " << codigo[id] << endl;
    }
    return 0;
}
