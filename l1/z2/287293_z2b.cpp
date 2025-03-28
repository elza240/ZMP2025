#include <iostream>
using namespace std;


int euklides(int liczba1, int liczba2){
    if (liczba1==liczba2) {
        return liczba1;
    }
    else {
        if (liczba1>liczba2){
            liczba1=liczba1-liczba2;
            return euklides(liczba1,liczba2);
        }
        else {
            liczba2=liczba2-liczba1;
            return euklides(liczba1,liczba2);
        }
    }
}

int euler(int k){
    int licznik=0;
    for (int i=1;i<=k;i++){
        if  (euklides(k,i)==1){
            licznik++;
        }
        else{
            continue;
        }
    }
    return licznik;
}

int F(int n){
    int suma=0;
    for(int i=1;i<=n;i++){
        if (n%i==0){
            suma=suma+euler(i);
        }
        else{
            continue;
        }
    }
    return suma;
}

int main(){
    int n;
    cin>>n;
    cout<<F(n);
    return 0;
}