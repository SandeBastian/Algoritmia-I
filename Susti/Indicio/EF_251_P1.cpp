#include <fstream>
#include <iostream>
using namespace std;
struct reg {
    int cod;
    string cont;
};
struct nod {
    int cod;
    int nota;
    nod *l;
    nod *r;
};
nod *crearnodo(int cod, int nota) {
    nod *u = new nod;
    u->cod = cod;
    u->nota = nota;
    u->l = u->r = NULL;
    return u;
}
void insert(nod *&root, int cod, int nota) {
    if (root == NULL) {
        root = crearnodo(cod, nota);
        return;
    }
    if (cod < root->cod) insert(root->l, cod, nota);
    else insert(root->r, cod, nota);
}
bool valid(reg data[200], int n, int cod, string cont) {
    for (int i = 0; i < n; i++)
        if (data[i].cod == cod) return cont == data[i].cont;
    return false;
}
void mostrarenorden(nod *root) {
    if (root == NULL) return;
    mostrarenorden(root->l);
    cout << root->cod << ": " << root->nota << endl;
    mostrarenorden(root->r);
}
int main() {
    ifstream f("Claves.txt");
    char a[200];
    reg data[200];
    int n = 0;
    nod *root = NULL;
    while (f >> a) {
        int cod = 0;
        for (int i = 0; i < 4; i++) cod = 10 * cod + (a[i] - '0');
        string cont = "";
        for (int i = 4; i < 10; i++) cont += a[i];
        data[n].cod = cod;
        data[n].cont = cont;
        n++;
    }
    f.close();
    ofstream F("Desaprobados.txt");
    int nnotas;
    cout << "Ingrese cantidad de notas a registrar: ";
    cin >> nnotas;
    for (int i = 0; i < nnotas; i++) {
        int cod;
        string cont;
        cout << "Ingrese codigo: ";
        cin >> cod;
        cout << "Ingrese contrasena: ";
        cin >> cont;
        if (valid(data, n, cod, cont)) {
            int nota;
            cout << "Ingrese nota a registrar: ";
            cin >> nota;
            if (nota < 10) F << cod << " " << nota << endl;
            insert(root, cod, nota);
        } else cout << "Constrasena o usuario no valido." << endl;
    }
    mostrarenorden(root);
    return 0;
}