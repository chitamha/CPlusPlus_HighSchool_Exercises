#include <bits/stdc++.h>
#define maxn 1e9+7
using namespace std;

int n;

int main(){
    cin>> n;
    int F[n+1];
    F[0]=1;
    for (int i=1; i<=n; i++){
        F[i]=0;
        for (int j=1; j<=min(6, i); j++){
            F[i]+=F[i-j];
        }
    }
    cout<< F[n];
    return 0;
}
