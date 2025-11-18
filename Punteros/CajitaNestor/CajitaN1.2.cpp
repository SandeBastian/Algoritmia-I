#include <iostream>
using namespace std;

struct Reg {
    int cod;
    float pt;
};

int main () {
    int *p;
    float *q;
    Reg *r1;
    p=new(int);
    q=new(float);
    r1=new(Reg);

    cout<<"\nMemorias 1: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    p++; q++; r1++;
    cout<<"\nMemorias ++: "<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"r1: "<<r1<<endl;

    return 0;
}