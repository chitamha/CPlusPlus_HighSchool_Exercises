#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, k, s, cnt=0;
ll X[100];

void xuli(){
    ll sum=0;
    for (ll i=1; i<=k; i++) sum+=X[i];
    if (sum==s) cnt++;
}

void Ql(ll i){
    for (ll j=X[i-1]+1; j<=n-k+i; j++){
        X[i]=j;
        if (i==k) xuli();
        else Ql(i+1);
    }
}
int main(){
    n=1, k=1, s=1;
    while (n!=0 || k!=0 || s!=0){
        cin>> n>> k>> s;
        Ql(1);
        cout<< cnt<< endl;
        cnt=0;
        memset(X, 0, sizeof X);
    }
    return 0;
}
