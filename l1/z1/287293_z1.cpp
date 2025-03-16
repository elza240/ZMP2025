#include <iostream>
using namespace std;

int funkcja(int n){
    int licznik=1;
    cout<<n;
    if (n!=0){
        while (n!=1){
        if (n%2==0){
            n=n/2;
            cout <<" "<<n;
            licznik++;
            }
        else{
            n=3*n+1;
            cout <<" "<<n ;
            licznik++;
            }
        }
    }
    cout<<", " ;
    cout<<licznik;
    return 0;
    //nie bo dla n=0 2|0 wiec bedzie 0/2=0 i bedzie ciag 0;    
}

int main(){
    int n;
    cin>>n;
    funkcja(n);
    return 0;
}