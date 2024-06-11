#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, ans=0, X[15];
vector<ll> A;

void xuli(){
    ll sol=0;
    for (ll i=1; i<=n-1; i++){
        if (X[i]==1) sol=(sol+A[i]+A[i+1])%m;
        else if (X[i]==2) sol=(sol+A[i]-A[i+1])%m;
        else sol=(sol+(A[i]%m)*(A[i+1]%m));
    }
    ans+=sol%m==0;
}

void Try(ll i){
    //1: +; 2: -; 3: *
    for (ll j=1; j<=3; j++){
        X[i]=j;
        if (i==n-1) xuli();
        else Try(i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin>> t;
    while (t--){
        cin>> n>> m;
        A.resize(n+1); ans=0;
        for (ll i=1; i<=n; i++) cin>> A[i];
        Try(1);
        cout<< ans<< "\n";
        A.clear();
    }
    return 0;
}
