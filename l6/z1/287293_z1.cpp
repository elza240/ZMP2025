#include <iostream>
using namespace std;

int main(){

    int n; //liczba zmiennych
    cin>>n;

    int *liczby=new int [n];
    for (int i=0;i<n;i++){
        cin>>liczby[i];
    } // uzupelniamy tablice liczbami

    for (int j=0;j<n-1;j++){
        for (int k=0;k<n-j-1;k++){
            if (liczby[k]>liczby[k+1]){
                swap(liczby[k],liczby[k+1]);
            }
        }
    } //sortowanie babelkowe - przechodzimy przez caly zakres tablicy i sprawdzamy czy kazde dwie sasiednie liczby sa w dobrej kolejnosci
    // jesli nie to zamieniamy je. tak z kazda liczba 
    
    for (int m=0;m<n;m++){
        cout << endl << liczby[m];
    }

    delete []liczby;
    return 0;
}