
#include <iostream>
using namespace std;


int main () {
    string s="anitalavalatina";
    int i=0;
    int j=s.size()-1;
    bool palindroma=true;
    while (i<j) {
        if (s[i]!=s[j]) palindroma=false;
        i++;
        j--;
    }
    if (palindroma) cout<<"Es palindroma"<<endl;
    else cout<<"No palindroma"<<endl;
    return 0;
 }