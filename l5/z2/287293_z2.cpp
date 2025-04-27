// Zadanie 2 (3p.). Zaimplementuj wariant merge sorta, który pomija początkowe dzielenie tablicy na pół 
// i zaczyna od razu ”od dołu”, tzn. na początku scala singletony tablicy, potem powstałe w ten sposób pary, 
// czwórki, etc. Program powinien oczekiwać ze standardowego wejścia wielkość tablicy n, a potem n liczb całkowitych 
// stanowiących zawartość tablicy, a na końcu wyświetlić posortowaną tablicę oddzielając kolejne liczby spacjami.

#include <iostream>
using namespace std;


void merge(int tab[],int l,int s, int p){
    int dl_l=s-l+1;
    int dl_p=p-s;

    int* L=new int[dl_l];
    int* P=new int[dl_p];

    for (int i=0;i<dl_l;i++){
        L[i]=tab[l+i];
    }
    for (int j=0;j<dl_p;j++){
        P[j]=tab[s+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while (i<dl_l && j<dl_p){
        if (L[i]<=P[j]){
            tab[k++]=L[i++];
        }
        else{
            tab[k++]=P[j++];
        }
    }

    while (i<dl_l){
        tab[k++]=L[i++];
    }

    while (j<dl_p){
        tab[k++]=P[j++];
    }

    delete[] L;
    delete[] P;
}

void mergesort(int tab[], int l, int p){
    if (l>=p) return;
    int s=l+(p-l)/2;
    mergesort(tab,l,s);
    mergesort(tab,s+1,p);
    merge(tab,l,s,p);

}

int main (){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }
    mergesort(T,0,n-1);
    
    for (int i = 0; i < n; ++i)
        cout << T[i] << " ";
    return 0;
}