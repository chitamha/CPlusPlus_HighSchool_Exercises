#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, ans, h[maxn];

bool check(ll x){
    ll total=0;
    for (ll i=1; i<=n; i++) total+=max(0ll, h[i]-x);
    return total>=m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (ll i=1; i<=n; i++) cin>> h[i];
    ll l=0, r=1e18+10;
    while (r>=l){
        ll mid=(l+r)>>1;
        if (check(mid)) {
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<< ans;
    return 0;
}
