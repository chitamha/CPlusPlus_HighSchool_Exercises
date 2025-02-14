#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, p, k, ans=0;
map<ll, ll> mp;

ll Mod(ll x){
    return ((((x*x)%p)*((x*x)%p)%p)-(k*x)%p+p)%p;
}

int main(){
    freopen("cpairs.inp", "r", stdin);
    freopen("cpairs.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> p>> k;
    for (ll i=1; i<=n; i++){
        ll x; cin>> x;
        mp[Mod(x)]++;
        ans+=mp[Mod(x)]-1;
    }
    cout<< ans;
    return 0;
}
