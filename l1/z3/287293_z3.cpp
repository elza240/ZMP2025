#include <iostream>
using namespace std;

int funkcja(int n){
    int zera=0;
    for (int i=1;i<=n;i++){
        if (i%5==0){
            int j=i;
            while (j%5==0){
                j=j/5;
                zera++;
            }
        }
        else{
            continue;
        }
    }
    return zera;
}

int main() {
    int n;
    cin>>n;
    cout<<funkcja(n);
    return 0;
}