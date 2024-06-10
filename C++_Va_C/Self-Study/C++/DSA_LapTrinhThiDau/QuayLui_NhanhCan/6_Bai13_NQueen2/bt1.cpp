#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, ans=-1e9;
ll A[100][100];
ll X[100];
ll cot[100], cheo1[100], cheo2[100];

void Ql(ll i){
    for (ll j=1; j<=n; j++){
        if (cot[j]==0 && cheo1[i-j+8]==0 && cheo2[i+j-1]==0){
            X[i]=j;
            cot[j]=1; cheo1[i-j+8]=1; cheo2[i+j-1]=1;
            if (i==n){
                ll sum=0;
                for (ll k=1; k<=n; k++){
                    sum+=A[k][X[k]];
                }
                ans=max(ans, sum);
            }
            else Ql(i+1);
            cot[j]=0; cheo1[i-j+8]=0; cheo2[i+j-1]=0;
        }
    }
}

int main(){
    cin>> t;
    while (t--){
        n=8;
        for (ll i=1; i<=n; i++){
            for (ll j=1; j<=n; j++){
                cin>> A[i][j];
            }
        }
        Ql(1);
        cout<< ans<< endl;
        ans=0;
        memset(A, 0, sizeof A);
        memset(X, 0, sizeof X);
        memset(cot, 0, sizeof cot);
        memset(cheo1, 0, sizeof cheo1);
        memset(cheo2, 0, sizeof cheo2);
    }
    return 0;
}
