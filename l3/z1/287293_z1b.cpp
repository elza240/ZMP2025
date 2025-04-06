#include <iostream>
using namespace std;

unsigned long long fib(unsigned long long n, unsigned long long k, unsigned long long  f0, unsigned long long f1, unsigned long long fn){
    if (k<=n){
        fn=f0+f1;
        f0=f1;
        f1=fn;
        k++;
        return fib(n,k,f0,f1,fn);
    }
    else{
        return fn;
    }
}

int main(){
    long long n;
    cin >> n;
    cout<<fib(n,2,1,1,0);
    return 0;
}