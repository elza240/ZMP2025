#include <iostream>
using namespace std;

void szyfr(int p[],int q[]){
    for (int i=0;i<8;i++){
        cout<<(p[i]^q[i])<<" ";
    }
}

int main(){
    int p[8], q[8];
    for (int i=0;i<8;i++){
        cin>>p[i];
    }
    for (int i=0;i<8;i++){
        cin>>q[i];
    }
    szyfr(p,q);
    return 0;
}