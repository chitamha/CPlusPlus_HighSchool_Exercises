#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, S, ans=-1e9;
ll W[1005];
ll V[1005];
ll X[1005];

void xuli(){
    ll tw=0, tv=0;
    for (ll i=1; i<=n; i++){
        if (X[i]){
            tw+=W[i];
            tv+=V[i];
        }
    }
    if (tw>S) return;
    else ans=max(ans, tv);
}

void QL(ll i){
    for (ll j=0; j<=1; j++){
        X[i]=j;
        if (i==n) xuli();
        else QL(i+1);
    }
}


int main(){
    cin>> n>> S;
    for (ll i=1; i<=n; i++) cin>> W[i];
    for (ll i=1; i<=n; i++) cin>> V[i];
    QL(1);
    cout<< ans;
    return 0;
}
