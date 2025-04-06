#include <iostream>
using namespace std;

void podzbiory(int T[], int n, int k, int podzbior[], int j){
    if (k==0){
        cout<<"empty";
    }
    else {
        cout <<endl;
        for (int i = 0; i<k; i++) {
            cout << podzbior[i] << " ";
        }
    }

    for (int i=j;i<n;i++){
        podzbior[k]=T[i];
        podzbiory(T,n,k+1,podzbior,i+1);
    }
}
// bierzemy parametry T - tablica z liczbami, n-ile jest tych liczb, k-rozmiar podzbioru ktory juz mamy, pozbior-podzbior ktory obecnie mamy
// j - indeks na ktorym jestesmy
// najpierw sprawdzamy podzbior pusty (zawsze bedziemy zaczynac od k=0 a pozniej to modyfikujemy wiec bedzie raz)
// jak juz mamy podzbior wiekszy niz pusty to go wyswietlamy (tablica jest wieksza niz trzeba i nie wiadomo co na niej jest wiec wyswietlamy tylko
// tyle ile wiemy ze jest rozsadnie zapisane czyli do ktego indeksu)
// funkcje wywolamy od j=0 czyli od pierwszej liczby jaka byla podana i od niej zaczynami iteracje z tworzeniem podzbioroow
// bedziemy zwiekszac rozmiar o jeden wiec przy pierwszym wejsciu do tej petli zrobi sie zbior jednoelementowy (z jta liczba z tablicy), 
// potem zwiekszamy rozmiar o jeden i indeks o jeden i robimy jeszcze raz
// jak sie skoncza liczby w tablicy czyli i za duze to sie zrobi kolejna iteracja w forze a przez to element startowy to kolejny z tablicy itd 


int main(){
    int n;    
    cin >> n;
    int T[n];
    int podzbior[n];
    for (int i=0; i<n;i++){
        cin>>T[i];
    }
    podzbiory(T,n,0,podzbior,0);
    return 0;
}

// k to rozmiar rozwazanego podzbioru, j to numer indeksu ktory sprawdzamy