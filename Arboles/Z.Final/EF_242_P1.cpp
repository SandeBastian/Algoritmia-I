#include <iostream>
using namespace std;
struct nod {
    int x;
    nod *l;
    nod *r;
};
nod *crearnodo(int x) {
    nod *u = new nod;
    u->x = x;
    u->l = u->r = NULL;
    return u;
}
void insert(nod *&u, int x) {
    if (u == NULL) {
        u = crearnodo(x);
        return;
    }
    if (x < u->x) insert(u->l, x);
    else insert(u->r, x);
}
void crearlista(nod *u, nod *&root, nod *&lu) {
    if (u == NULL) return;
    crearlista(u->l, root, lu);
    if (root == NULL) root = lu = crearnodo(u->x);
    else lu = lu->r = crearnodo(u->x);
    crearlista(u->r, root, lu);
}
void mostrarlista(nod *root) {
    nod *u = root;
    while (u) {
        cout << u->x << " ";
        u = u->r;
    }
}
int main() {
    int n;
    cout << "Ingrese cantidad de numeros: ";
    cin >> n;
    nod *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Ingrese numero: ";
        cin >> x;
        insert(root, x);
    }
    nod *lroot = NULL, *lu;
    crearlista(root, lroot, lu);
    mostrarlista(lroot);
    return 0;
}