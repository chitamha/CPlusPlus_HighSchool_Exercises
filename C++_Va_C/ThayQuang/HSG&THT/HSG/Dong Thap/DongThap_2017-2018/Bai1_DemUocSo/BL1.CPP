#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, Dem[25];

void xuli(ll x){
    for (ll i=2; i<=sqrt(x); i++){
        while (x%i==0){
            Dem[i]++;
            x/=i;
        }
    }
    if (x>1) Dem[x]++;
}

int main(){
    //freopen("UOCSO.INP", "r", stdin);
    //freopen("UOCSO.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>> t;
    while (t--){
    memset(Dem, 0, sizeof Dem);
    cin>> n;
    //if (n==1) return cout<< 1, 0;
    for (ll i=2; i<=n; i++) xuli(i);
    ll ans=1;
    for (ll i=1; i<=25; i++){
        if (Dem[i]!=0) ans*=(Dem[i]+1);
    }
    cout<< ans;
    cout<< endl;
    }
    return 0;
}
