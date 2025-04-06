#include <iostream>
using namespace std;

void podzbiory(int T[], int n, int m, int k,int podzbior[], int j){
    if (m<=k){
    if (m==0){
        cout<<"empty";
    }
    else {
        cout <<endl;
        for (int i = 0; i<m; i++) {
            cout << podzbior[i] << " ";
        }
    }
    }
     for (int i=j;i<n;i++){
        podzbior[m]=T[i];
        podzbiory(T,n,m+1,k,podzbior,i+1);
    }

}
int main(){
    int n,k;    
    cin >> n>>k;
    int T[n];
    int podzbior[n];
    for (int i=0; i<n;i++){
        cin>>T[i];
    }
    podzbiory(T,n,0,k,podzbior,0);
    return 0;
}


// to co wczesniej bylo k to teraz jest m (czyli rozmiar pozbioru)
// dodany dodatkowy parametr k; wyswietlamy tylko jesli rozmiar pozdbioru mniejszy rowny k