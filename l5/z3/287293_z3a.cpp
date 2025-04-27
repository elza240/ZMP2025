// Zadanie 3 (4p.). Napisz program, który znajdzie max{T[j] −T[i] : 0 i j <n} w czasie 
// (a) (1p.) O(n2), 
// (b) (3p.) O(nlogn) (polegający na ”dziel i zwyciężaj”)3, 
// gdzie T to tablica intów o rozmiarze n. Program powinien oczekiwać ze standardowego wejścia rozmiaru tablicy n, 
// następnie n liczb całkowitych stanowiących zawartość tablicy, a oddać na standardowym wyjściu znalezioną wartość.

#include <iostream>
using namespace std;

int maksimum(int n, int T[]){
    int max=T[1]-T[0];
    for (int i=0; i<n;i++){
        for (int j=i+1;j<n;j++){
            if (T[j]-T[i]>max){
                max=T[j]-T[i];
            }
        }
    }
    return max;
}

int main (){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }
    cout <<maksimum(n,T);
    return 0;
}