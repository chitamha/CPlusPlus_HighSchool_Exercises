#include <iostream>
#include <math.h>
using namespace std;
int n=10000000;
int prime[10000001];

void nt(){
    for (int i=0; i<=n; i++){
        prime[i]=1;
    }
    prime[0]=prime[1]=0;
    for (int i=2; i<=sqrt(n); i++){
        if (prime[i]==1){
            for (int j=i*i; j<=n; j+=i){
                prime[j]=0;
            }
        }
    }
}

int main(){
    nt();
    for (int i=0; i<=1000; i++){
        if (prime[i]==1){
            cout<< i<< " ";
        }
    }
}
