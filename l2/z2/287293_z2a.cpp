#include <iostream>
using namespace std;

void czy_zawiera(int x, int n, int tab[]){
    tab[n];
    bool czy_zawiera=false;
    string indeksy;
    for (int i=0;i<n;i++){
        if(tab[i]==x){
            czy_zawiera=true;
            indeksy=indeksy+to_string(i)+" ";
        }
        else{continue;}
    }
    if (czy_zawiera==true){
        cout<< "tak "<<indeksy;
    }
}

int main(){
    int x,n;
    cin>>x>>n;
    int tab[n];
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    czy_zawiera(x,n,tab);
    return 0;
}