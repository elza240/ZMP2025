#include <iostream>
using namespace std;

//funkcja dziala tak samo jak w a tlko zamiast sprawdzac cala tebele to zatrzymuje sie jak juz znajdzie x
void czy_zawiera(int x, int n, int tab[]){
    tab[n];
    bool czy_zawiera=false;
    
    string indeksy;
    for (int i=0;i<n;i++){
        if(tab[i]==x){
            czy_zawiera=true;
            indeksy=indeksy+to_string(i)+" ";
            if(tab[i+1]!=x){
                break;
            }
        }
        else{continue;}
       
    }
    if (czy_zawiera==true){
        cout<< "tak "<<indeksy;
    }
}

//funkcja wykorzystuje binary search, a-zakres dolny c-zakres gorny, b-wartosc srodkowa, dopoki jest gdzie szukac czyli zakres dolny jest nie
//wiekszy niz zakres gorny (tablica ma przynjamneij jedenelemtn) sprawdzamy element srodkowy, jesli pod tym indeksem jst wartosc szukana to
//koniec jesli nie to zawezamy obszar poszukiwania do gornej lub dolnej polowy zakresu, jesli nie znalezlismy to znaczy ze nie ma
int czy_zawiera2(int x, int tab[], int a, int c){
    int b;
    while (a<=c){
        b=a+(c-a)/2;
        if (tab[b]==x){
            cout << "tak " << b;
            return 0;
        }
        else if (tab[b]<x){
            a=b+1;
        }
        else{
            c=b-1;
        }
    }
    cout<<"nie";
    return 1;
}



int main(){
    int x,n;
    cin>>x>>n;
    int tab[n];
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    czy_zawiera2(x,tab,0,7);
    return 0;
}