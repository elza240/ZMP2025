#include <iostream>
using namespace std;

void swap(unsigned long long a,unsigned long long b){
    a=a^b;
    b=a^b;
    a=a^b;
}

unsigned long long fib(int n){
    unsigned long long f0=1;
    unsigned long long f1=1;
    unsigned long long fn;
        for (int i=2;i<=n;i++){
            fn=f0+f1;
            f0=f1;
            f1=fn;
        }
    return fn;
    
}

int main(){
    int n;
    cin>>n;
    int fn=fib(n);
    cout<<fn;
    return 0;
}