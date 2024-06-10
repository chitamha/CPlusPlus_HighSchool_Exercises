#include <bits/stdc++.h>
#define fi first
#define se second
#define llll pair<ll, ll>
#define ll long long
#define maxn 1000006
using namespace std;

ll n, m, ans, t[maxn];

bool check(ll x){
    ll total=0;
    for (ll i=1; i<=n; i++) total+=x/t[i];
    return total>=m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n>> m;
    for (ll i=1; i<=n; i++) cin>> t[i];
    ll l=0, r=1e18+10;
    while (r>=l){
        ll mid=(l+r)>>1;
        if (check(mid)) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<< ans;
    return 0;
}
