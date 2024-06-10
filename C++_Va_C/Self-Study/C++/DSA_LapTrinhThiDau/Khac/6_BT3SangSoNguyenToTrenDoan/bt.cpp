#include <bits/stdc++.h>
using namespace std;

void sangso(int l, int r){
    int NT[r-l+1];
    for (int i=0; i<=r-l+1; i++){
        NT[i]=1;
    }
    for (int i=2; i<=sqrt(r); i++){
        for (int j=max((l+i-1)/i*i, i*i); j<=r; j+=i){
            NT[j-l]=0;
        }
    }
    for (int i=max(l, 2); i<=r; i++){
        if (NT[i-l]){
            cout<< i<< " ";
        }
    }
}
/*
int fibo[10001];
void sangso(){
    for (int i=0; i<=10000; i++){
        fibo[i]=1;
    }
    fibo[0]=fibo[1]=0;
    for (int i=2; i<=sqrt(10000); ++i){
        if (fibo[i]){
            for (int j=i*i; j<=10000; j+=i){
                fibo[j]=0;
            }
        }
    }
}
*/
int main(){
    int l, r;
    cin>> l>> r;
    sangso(l, r);
    cout<< endl;
    /*
    int n;
    cin>> n;
    sangso();
    for (int i=2; i<=n; i++){
        if (fibo[i])
            cout<< i<< " ";
    }
    */
    return 0;
}
