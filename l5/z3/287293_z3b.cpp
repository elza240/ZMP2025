// Zadanie 3 (4p.). Napisz program, który znajdzie max{T[j] −T[i] : 0 i j <n} w czasie 
// (a) (1p.) O(n2), 
// (b) (3p.) O(nlogn) (polegający na ”dziel i zwyciężaj”)3, 
// gdzie T to tablica intów o rozmiarze n. Program powinien oczekiwać ze standardowego wejścia rozmiaru tablicy n, 
// następnie n liczb całkowitych stanowiących zawartość tablicy, a oddać na standardowym wyjściu znalezioną wartość.

#include <iostream>
using namespace std;

int maksimum(int T[],int l, int p, int &min, int &max){
    if (l==p){
        min=T[l];
        max=T[l];
        return 0;
    }
    //jesli poczatek i koniec tablicy sa w tym samym miejscu to roznica jest 0; definiujemy tez min i max zeby nie umarlo

    int s=(l+p)/2; //robimy nowy poczatek tablicy ktory bedzie na srodku

    int minP,maxP,minL,maxL; //zmienne pomocnicze

    int roznicaL=maksimum(T,l,s,minL,maxL);
    int roznicaP=maksimum(T,s+1,p,minP,maxP);
    //rekurencyjnie dzielimy tablice do pojedynczych i szukamy tak roznicy w kazdej polowie
    //maxL-minL nie jest potrzebne bo doprowadzamy do pojedynczych elementow wiec i tak jest maxP-minL
    
    int roznica=maxP-minL;
    //roznica miedzy polowami tablicy

    if (minL<minP){
        min=minL;
    }
    else{
        min=minP;
    }

    if (maxL>maxP){
        max=maxL;
    }
    else{
        max=maxP;
    }
    //znajdujemy najwieksza wartosc i najmniejsza zeby byly jakeis warunki poczatkowe

   int maksimum = roznicaL;
    if (roznicaP > maksimum) {
        maksimum = roznicaP;
    }
    if (roznica > maksimum) {
        maksimum = roznica;
    }
    //wybieramy maksimum: albo roznica jest najwieksza w lewej polowie, albo jesli w prawej jest wieksza to tam jest najwieksza, ablo jestli miedzy polowami jest najwiekza to tam

    return maksimum;
}


int main(){
    int n;
    cin >>n;
    int T[n];
    for (int i=0;i<n;i++){
        cin >> T[i];
    }
    int min, max;
    cout <<maksimum(T,0,n-1,min,max);
    return 0;
}