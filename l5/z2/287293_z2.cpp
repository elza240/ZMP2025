// Zadanie 2 (3p.). Zaimplementuj wariant merge sorta, który pomija początkowe dzielenie tablicy na pół 
// i zaczyna od razu ”od dołu”, tzn. na początku scala singletony tablicy, potem powstałe w ten sposób pary, 
// czwórki, etc. Program powinien oczekiwać ze standardowego wejścia wielkość tablicy n, a potem n liczb całkowitych 
// stanowiących zawartość tablicy, a na końcu wyświetlić posortowaną tablicę oddzielając kolejne liczby spacjami.

#include <iostream>
using namespace std;

void merge(int T[], int l, int m, int r){
    int nL=m-l+1;
    int nR=r-m;
    int L[nL];
    int R[nR];
    for (int i=0;i<nL;i++){
        L[i]=T[l+i];
    }
    for (int i=0;i<nR;i++){
        R[i]=T[m+1+i];
    }
    //tworzymy tablice zastepcze do ktorych wpisuejmy wartosci
    int i=0;
    int j=0;
    int k=l;
    while(i<nL&&j<nR){
        if(L[i]<=R[j]){
            T[k]=L[i];
            i++;
        }
        else{
            T[k]=R[j];
            j++;
        }
        k++;
    }

    while (i<nL){
        T[k]=L[i];
        i++;
        k++;
    }
    while (j<nR){
        T[k]=R[j];
        j++;
        k++;
    }
    //robimy zmienne pomocnicze, i dla lewej tablicy, j dla prawej, k jako odnosnik do T
    //jesli cos na lewej jest wieksze od tego na prawej to dajemy go pozniej 
    //iterujemy po tych indeksach na ktorych bylo cos mniejszego
    //jak sie skoncza indeksy to spisujemy tak jak jest

}//funkcja scala dwie posortowane tablice

void mergesort(int T[], int n){
    for (int k=1;k<=n;k=k*2){
        for (int l=0;l<n-1;l=l+k*2){
            int m=min(l+k*2,n-1);
            int r=min(l+k*2-1,n-1);
            merge(T,l,m,r);
        }
    }
}//sortujemy pojedyncze tablice
//mamy tablice T o elementach liczbie n, sortujemy tablice po dlugosci tablicy k, k się mnoży przez 2 bo tak z polecenia wynika
//iterujemy po tablicach zaczynajacych sie w l, srodek w m, prawy kraniec w r
//iterujemy po l, r i m jest juz sortowane, pozniej laczymy w tablice wieksza

int main (){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }
    mergesort(T,n);
    
    for (int i = 0; i < n; ++i)
        cout << T[i] << " ";
    return 0;
}
