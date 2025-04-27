//Zadanie 1 (3p.). Napisz program, który znajdzie liczbę inwersji w podanej tablicy intów o zadanym rozmiarze w czasie:
// (a) (1p.) O(n2), 
// (b) (2p.) O(nlogn)2. 
// Na potrzeby testów załóżmy, że na standardowym wejściu przychodzi rozmiar tablicy n oraz n liczb całkowitych stanowiących zawartość tablicy, 
// a na standardowym wyjściu chcemy otrzymać liczbę inwersji.

#include <iostream>
using namespace std;

int inwersje(int n, int T[]){
    int  licznik=0;
    for (int i=0;i<n;i++){
        for (int j=1+i; j<n;j++){
            if (i<j&& (T[i]>T[j])){
                licznik++;
            }
        }
    }
    return licznik;
}

int main (){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }
    cout <<inwersje(n,T);
    return 0;
}