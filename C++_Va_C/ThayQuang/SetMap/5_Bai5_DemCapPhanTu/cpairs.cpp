#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, p, k, ans=0;
vector<pair<ll, ll>> AA2;

ll Find(ll id, ll sum){
    ll l=0, r=id-1, mid=0;
    while (l<=r){
        mid=(l+r)/2;
        ll tmp=(AA2[mid].fi+AA2[id].fi)*(AA2[mid].se+AA2[id].se);
        if (tmp==sum) return 1;
        if (tmp>sum) r=mid-1;
        else l=mid+1;
    }
    return 0;
}

int main(){
    freopen("cpairs.inp", "r", stdin);
    freopen("cpairs.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> p>> k;
    for (ll i=1; i<=n; i++){
        ll x; cin>> x;
        AA2.push_back({x%p, (x*x)%p});
    }
    sort(AA2.begin(), AA2.end());
    for (ll i=1; i<n; i++){
        for (ll j=0; j<=4; j++){
            ans+=Find(i, j*p+k);
        }
    }
    cout<< ans;
    return 0;
}
