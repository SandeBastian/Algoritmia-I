//Determinar si es palindromo
#include <iostream>
using namespace std;

bool esPalindromo(string s, int inicio, int final) {
    if (inicio>=final) return true;
    if (s[inicio]==s[final]) {
        return esPalindromo(s,inicio+1,final-1);
    }
    return false;
}

int main () {
    string s="anitalavalatina";
    if (esPalindromo(s,0,s.size()-1) ) cout<<"Es Palindromo"<<endl;
    else cout<<"Not es Palindromo"<<endl;
    cout<<"El tamanio era: "<<s.size()<<endl;
    cout<<"s[0]: "<<s[0]<<endl;
    cout<<"s[s.size()-1]: "<<s[s.size()-1]<<endl;
    return 0;
}