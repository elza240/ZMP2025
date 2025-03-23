// Zadanie 1 (3p.). Napisz program, który obliczy NWD dowolnej skończonej liczby liczb
// naturalnych.
// Program powinien oczekiwać ze standardowego wejścia liczbę naturalną n, a następnie
// n liczb naturalnych, których NWD ma wyznaczyć. Na standardowym wyjściu spodziewamy się po prostu NWD tych liczb. Np. dla wejścia
// 4 42 45 39
// powinniśmy otrzymać wyjście 3

#include <iostream>
using namespace std;

//euklides() znajduje NWD lcizb a i b
int euklides(int a, int b){
    if (b==0){
        return a;
    }
    return euklides (b,a%b);
}

//nwd() przypisuje zmiennej nwd pierwszy element tablicy, pozniej znajduje nwd dla itego i i+1szego elementu; dziala bo nwd kazdych 3 liczb nie moze byc wieksze niz nwd 2 liczb
int nwd(int n, int tab[]){
    tab[n];
    int nwd=tab[0];
    for (int i=1;i<n;i++){
        nwd=euklides(nwd,tab[i]);
    }
    return nwd;
}

int main(){
    int n;
    cin >>n;
    int tab[n];
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    cout<<nwd(n, tab);
    return 0;
}