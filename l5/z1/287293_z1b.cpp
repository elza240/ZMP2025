//Zadanie 1 (3p.). Napisz program, który znajdzie liczbę inwersji w podanej tablicy intów o zadanym rozmiarze w czasie:
// (a) (1p.) O(n2), 
// (b) (2p.) O(nlogn)2. 
// Na potrzeby testów załóżmy, że na standardowym wejściu przychodzi rozmiar tablicy n oraz n liczb całkowitych stanowiących zawartość tablicy, 
// a na standardowym wyjściu chcemy otrzymać liczbę inwersji.

#include <iostream>
using namespace std;

int merge(int tab[],int l,int s, int p){
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
    int inwersje=0;

    while (i<dl_l && j<dl_p){
        if (L[i]<=P[j]){
            tab[k++]=L[i++];
        }
        else{
            tab[k++]=P[j++];
            inwersje=inwersje+dl_l-i;
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
    return inwersje;
}


int mergesort(int tab[], int l, int p){
    int inwersje=0;
    if (l>=p){
        return 0;
    }
    int s=l+(p-l)/2;
        inwersje=inwersje+mergesort(tab,l,s);
        inwersje=inwersje+mergesort(tab,s+1,p);
        inwersje=inwersje+merge(tab,l,s,p);    
    return inwersje;
}

int main (){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }

    cout<<mergesort(T,0,n-1);
    return 0;
}